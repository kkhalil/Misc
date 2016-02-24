public class LList {
	private LNode head;
	private LNode tail;
	
	public LList() {
		head = null;
		tail = null;
	}
	
	public void push(int n) {
		LNode tmp = new LNode(null, n, head);
		head = tmp;
	}

	public void enqueue(int n) {
		LNode tmp = new LNode(tail, n, null);
		if (tail != null) {
			tail.setNext(tmp);
		}
		else {
			head = tmp;
		}
		tail = tmp;
	}

	public int dequeue() {
		int val = tail.getVal();
		tail = tail.getPrev();
		if (tail != null) {
			tail.setNext(null);
		}
		else {
			head = tail;
		}
		return val;
	}

	public int pop() {
		int val = head.getVal();
		head = head.getNext();
		return val;
	}

	public void delete(LNode n) {
		n.getPrev().setNext(n.getNext());
		n.getNext().setPrev(n.getPrev());
	}

	public void delete(int n) {
		LNode tmp = head;
		while (tmp != null) {
			if (tmp.getVal() == n) {
				tmp.getPrev().setNext(tmp.getNext());
				tmp.getNext().setPrev(tmp.getPrev());
				break;
			}
			tmp = tmp.getNext();
		}
	}

	public void deleteAt(int n) {
		LNode tmp = head;
		int c = 0;
		while (tmp != null) {
			System.out.println(c + " " + tmp.getVal());
			if (c == n) {
				tmp.getPrev().setNext(tmp.getNext());
				tmp.getNext().setPrev(tmp.getPrev());
				break;
			}
			c++;
			tmp = tmp.getNext();
		}
	}
	
	public String toString() {
		String ans = "{";
		LNode tmp = head;
		while (tmp != null) {
			ans += tmp;
			tmp = tmp.getNext();
		}
		
		return ans + "}";
	}
}