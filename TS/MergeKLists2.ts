namespace merger {
	class ListNode {
		val: number;
		next: ListNode | null;
		constructor(val: number) {
			this.val = val;

			this.next = null;
		}
	}

	function printList(list: ListNode | null) {
		let currentNode: ListNode | null = list;
		let result = "";
		while (currentNode !== null) {
			result += currentNode.val + " ";
			currentNode = currentNode.next;
		}

		console.log(result.trim());
	}

	function merge(l1: ListNode | null, l2: ListNode | null): ListNode | null {
		if (!l1) return l2;

		if (!l2) return l1;

		if (l1.val < l2.val) {
			l1.next = merge(l1.next, l2);
			return l1;
		} else {
			l2.next = merge(l1, l2.next);
			return l2;
		}
	}

	function mergeKListHelperFn(
		lists: ListNode[],
		start: number,
		end: number
	): ListNode | null {
		if (start === end) return lists[start];

		const mid = Math.floor(start + (start + end) / 2);
		const left = mergeKListHelperFn(lists, start, mid);
		const right = mergeKListHelperFn(lists, mid + 1, end);
		return merge(left, right);
	}

	function mergeKLists(lists: ListNode[]): ListNode | null {
		if (lists.length === 0) return null;

		return mergeKListHelperFn(lists, 0, lists.length - 1);
	}

	const l1 = new ListNode(1);
	l1.next = new ListNode(4);
	l1.next.next = new ListNode(5);

	const l2 = new ListNode(1);
	l2.next = new ListNode(3);
	l2.next.next = new ListNode(4);

	const l3 = new ListNode(2);
	l3.next = new ListNode(6);

	const merged = mergeKLists([l1, l2, l3]);
	printList(merged);
}
