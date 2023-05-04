class ListNode {
	val: number;
	next: ListNode | null;
	constructor(val: number) {
		this.val = val;

		this.next = null;
	}
}
namespace mergeK {
	const l1 = new ListNode(1);
	l1.next = new ListNode(4);
	l1.next.next = new ListNode(5);

	const l2 = new ListNode(1);
	l2.next = new ListNode(3);
	l2.next.next = new ListNode(4);

	const l3 = new ListNode(2);
	l3.next = new ListNode(6);

	// Merge the linked lists
	const mergedList = mergeKLists([l1, l2, l3]);
	printList(mergedList);
	function mergeTwoLists(
		l1: ListNode | null,
		l2: ListNode | null
	): ListNode | null {
		if (!l1) return l2;

		if (!l2) return l1;

		if (l1.val < l2.val) {
			l1.next = mergeTwoLists(l1.next, l2);
			return l1;
		} else {
			l2.next = mergeTwoLists(l1, l2.next);
			return l2;
		}
	}

	function mergeKLists(lists: ListNode[]): ListNode | null {
		if (lists.length === 0) return null;

		let n = lists.length;

		while (n > 1) {
			let k = Math.floor((n + 1) / 2);
			for (let i = 0; i < Math.floor(n / 2); i++) {
				lists[i] = mergeTwoLists(lists[i], lists[i + k]) as ListNode;
			}
			n = k;
		}
		return lists[0];
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
}
