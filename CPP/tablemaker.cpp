#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

std::vector<std::vector<std::string>> normalizeData(std::vector<std::vector<std::string>> &data)
{

  size_t maxCols = 0;
  for (auto const &row : data)
    maxCols = std::max(maxCols, row.size());

  for (auto &row : data)
  {
    if (maxCols > row.size())
    {
      size_t missingCols = maxCols - row.size();

      for (int i = 0; i < missingCols; i++)
        row.push_back("NULL");
    }
  }
  return data;
}

std::string separator(std::vector<size_t> &cellWidths)
{
  std::string sep = "|";
  for (auto const &width : cellWidths)
  {
    sep += std::string(width, '-') + " |";
  }
  sep += "\n";
  return sep;
}

std::string makeTable(std::vector<std::vector<std::string>> &data)
{
  data = normalizeData(data);

  std::vector<size_t> colWidths(data[0].size(), 0);

  for (auto const &row : data)
  {
    for (size_t cellIdx = 0; cellIdx < row.size(); cellIdx++)
    {
      size_t cellWidth = row[cellIdx].length();
      colWidths[cellIdx] = std::max(colWidths[cellIdx], cellWidth);
    }
  }

  std::string table;

  table += separator(colWidths);

  // Header
  table += "|";

  for (size_t colIdx = 0; colIdx < data[0].size(); colIdx++)
  {
    const std::string &header = data[0][colIdx];
    std::string paddingHeader = header;
    size_t headerWidth = header.length();
    size_t colWidth = colWidths[colIdx];
    if (headerWidth < colWidth)
    {
      size_t padding = (colWidth - headerWidth) / 2;
      paddingHeader = std::string(padding, ' ') + header + std::string(colWidth - padding - headerWidth, ' ');
    }
    table += paddingHeader + " |";
  }

  table += "\n";

  table += separator(colWidths);

  // Data

  for (size_t rowIdx = 1; rowIdx < data.size(); rowIdx++)
  {
    table += "|";
    for (size_t colIdx = 0; colIdx < data[rowIdx].size(); colIdx++)
    {
      const std::string &cell = data[rowIdx][colIdx];
      size_t colWidth = colWidths[colIdx];
      table += cell + std::string(colWidth - cell.length(), ' ') + " |";
    }
    table += "\n";
  }

  table += separator(colWidths);

  return table;
}

std::vector<std::vector<std::string>> parseCSV(const std::string &filename, char delim = ',')
{

  std::fstream file;
  file.open(filename, std::ios::in);
  std::vector<std::vector<std::string>>
      data;

  if (!file.is_open())
  {
    std::cout << "Error Opening file: " << filename << std::endl;
    return data;
  }

  std::string line;

  while (std::getline(file, line))
  {
    std::vector<std::string> row;
    std::stringstream ss(line);

    std::string cell;

    while (std::getline(ss, cell, delim))
    {
      row.push_back(cell);
    }
    data.push_back(row);
  }
  file.close();

  return data;
}

int main(int argc, char const *argv[])
{

  std::vector<std::vector<std::string>> data = parseCSV("./CPP/data.csv");

  auto table = makeTable(data);
  std::cout << table;

  return 0;
}
