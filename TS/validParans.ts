const isValid = function (s: string) {
	const stack: string[] = [];
	const charMappings = {
		")": "(",
		"}": "{",
		"]": "[",
	};

	for (let i = 0; i < s.length; i++) {
		const char = s[i];

		if (char === "(" || char === "{" || char === "[") {
			stack.push(char);
		} else if (char === ")" || char === "}" || char === "]") {
			if (stack.length === 0 || stack[stack.length - 1] !== charMappings[char])
				return false;
			stack.pop();
		}
	}
	return stack.length === 0;
};
const exp = "{{()([])}}";
isValid(exp) ? console.log("Valid") : console.log("Invalid");
