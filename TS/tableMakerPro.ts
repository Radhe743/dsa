namespace TableMaker {
	const normalizeData = (data: any[][]) => {
		const maxCols = Math.max(...data.map((row) => row.length));

		data.forEach((row) => {
			if (maxCols > row.length) {
				const missingCols = maxCols - row.length;
				for (let _ = 0; _ < missingCols; _++) row.push("NULL");
			}
		});
		return data;
	};

	const separator = (widths: number[]): string => {
		let sep = "";
		sep += "|";
		widths.forEach((width) => {
			sep += `${"-".repeat(width)} |`;
		});
		sep += "\n";
		return sep;
	};

	const makeTable = (data: any[][]): string => {
		data = normalizeData(data);
		const colWidths = data.reduce<number[]>((widths, col) => {
			col.forEach((cell, cellIdx) => {
				const cellWidth = cell.toString().length;
				widths[cellIdx] = Math.max(widths[cellIdx] || 0, cellWidth);
			});

			return widths;
		}, []);

		let table = "";

		// Header

		table += separator(colWidths);

		table += "|";
		data[0].forEach((header, colIdx) => {
			const headerText = header.toString() as string;
			const paddedHeader = headerText
				.padStart(
					Math.floor(
						colWidths[colIdx] / headerText.length / 2 + headerText.length
					)
				)
				.padEnd(colWidths[colIdx], " ");
			table += `${paddedHeader} |`;
		});
		table += "\n";

		// Separator

		table += separator(colWidths);

		for (let rowIdx = 1; rowIdx < data.length; rowIdx++) {
			table += "|";

			data[rowIdx].forEach((row, colIdx) => {
				table += `${row.toString().padEnd(colWidths[colIdx])} |`;
			});
			table += "\n";
		}

		table += separator(colWidths);
		return table;
	};

	const data = [
		["Name", "Age", "City", "Position", "Experience"],
		["John Doe", 25, "New York", "Developer"],
		["Jane Smith", 30, "San Francisco", "Manager"],
		["Bob Johnson", 35, "Chicago"],
		["Alice Williams", 28, "Los Angeles"],
		["Michael Brown", 32, "Seattle"],
		["Emily Davis", 27, "Boston"],
		["David Wilson", 31, "Houston"],
		["Sarah Taylor", 29, "Miami"],
		["Daniel Anderson", 33, "Denver"],
		["Olivia Martinez", 26, "Phoenix"],
	];

	const table = makeTable(data);
	console.log(table);
}
