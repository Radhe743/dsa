function generateTable(data) {
	// Determine the maximum width for each column
	const columnWidths = data.reduce((widths, row) => {
		row.forEach((cell, columnIndex) => {
			const cellLength = cell.toString().length;
			widths[columnIndex] = Math.max(widths[columnIndex] || 0, cellLength);
		});
		return widths;
	}, []);

	// Construct the table structure
	let table = "";

	// Generate the table header
	table += "|";
	data[0].forEach((cell, columnIndex) => {
		table += ` ${cell.toString().padEnd(columnWidths[columnIndex])} |`;
	});
	table += "\n";

	// Generate the separator line
	table += "|";
	columnWidths.forEach((width) => {
		table += ` ${"-".repeat(width)} |`;
	});
	table += "\n";

	// Generate the table rows
	for (let rowIndex = 1; rowIndex < data.length; rowIndex++) {
		table += "|";
		data[rowIndex].forEach((cell, columnIndex) => {
			table += ` ${cell.toString().padEnd(columnWidths[columnIndex])} |`;
		});
		table += "\n";
	}

	return table;
}

// Example usage:
const data = [
	["Name", "Age", "City"],
	["John Doe", 28, "New York"],
	["Jane Smith", 35, "San Francisco"],
	["Bob Johnson", 42, "Chicago"],
];

const table = generateTable(data);
console.log(table);
// document.body.innerText = table;
