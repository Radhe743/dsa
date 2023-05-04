const generateParenthesis = (n: number): string[] => {
	const result: string[] = [];

	const backtrack = (curr: string, open: number, close: number) => {
		if (curr.length === 2 * n) {
			result.push(curr);
			return;
		}

		if (open < n) backtrack(curr + "(", open + 1, close);
		if (close < open) backtrack(curr + ")", open, close + 1);
	};

	backtrack("", 0, 0);

	return result;
};

const generateParenthesisIter = (n: number): string[] => {
	const result: string[] = [];
	const stack: { str: string; open: number; close: number }[] = [
		{ str: "", open: 0, close: 0 },
	];

	while (stack.length > 0) {
		const { str, close, open } = stack.pop() as {
			str: string;
			open: number;
			close: number;
		};

		if (str.length === 2 * n) {
			result.push(str);
			continue;
		}

		if (open < n) stack.push({ str: str + "(", open: open + 1, close });

		if (close < open) stack.push({ str: str + ")", open, close: close + 1 });
	}

	return result;
};
const parans = generateParenthesis(4);
console.log(parans);
