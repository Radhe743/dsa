namespace Table {
	const makeTable = (data: any[][]): string => {
		// Get Widths of all columns;
		const columnWidths = data.reduce<number[]>((widths, row) => {
			row.forEach((cell: any[], colIdx: number) => {
				const cellWidth = cell.toString().length;
				widths[colIdx] = Math.max(widths[colIdx] || 0, cellWidth);
			});

			return widths;
		}, []);

		let table = "";

		table += "|";
		columnWidths.forEach((width, col) => {
			table += `${"-".repeat(width)} | `;
		});
		table += "\n";

		// Header

		table += "|";
		data[0].forEach((header, colIdx) => {
			table += `${(header.toString() as string).padEnd(
				columnWidths[colIdx]
			)} | `;
		});

		table += "\n";

		// Separator

		table += "|";
		columnWidths.forEach((width, col) => {
			table += `${"-".repeat(width)} | `;
		});
		table += "\n";

		// Rest Data

		for (let rowIdx = 1; rowIdx < data.length; rowIdx++) {
			table += "|";
			data[rowIdx].forEach((col, colIdx) => {
				table += `${(col.toString() as string).padEnd(
					columnWidths[colIdx]
				)} | `;
			});
			table += "\n";
		}

		table += "|";
		columnWidths.forEach((width, col) => {
			table += `${"-".repeat(width)} | `;
		});
		table += "\n";

		return table;
	};

	const data = [
		["Name", "Age", "City"],
		["John Doe", 28, "New York"],
		["Jane Smith", 35, "San Francisco"],
		["Bob Johnson", 42, "Chicago"],
	];

	const table = makeTable(data);
	console.log(table);
}
