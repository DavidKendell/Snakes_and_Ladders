#include <iostream>

template <typename T, int MAX_SIZE>
class Stack {
	int bottom = -1;
	int top = MAX_SIZE;
	int arr[MAX_SIZE]{};
public:
	void pushbottom() {
		++bottom;
		if (bottom == top) {
			std::cout << "Stack overflow\n";
			--bottom;
		}
		else {
			std::cout << "Enter value.";
			std::cin >> arr[bottom];
		}
	}
	void pushtop() {
		--top;
		if (bottom == top) {
			std::cout << "Stack overflow\n";
			++top;
		}
		else {
			std::cout << "Enter value.";
			std::cin >> arr[top];
		}
	}
	void pop_bottom() {
		if (bottom-- <= -1) {
			std::cout << "Stack underflow\n";
			++bottom;
		}
	}
	void pop_top() {
		if (top++ >= MAX_SIZE) {
			std::cout << "Stack underflow\n";
			--top;
		}
	}
	void display() {
		std::cout << "Bottom up: ";
		for (int i = 0; i <= bottom; ++i) {
			std::cout << arr[i] << ' ';
		}
		std::cout << std::endl;
		std::cout << "Top up: ";
		for (int i = top; i < MAX_SIZE; ++i) {
			std::cout << arr[i] << ' ';
		}
		std::cout << '\n';
	}
};
//int main() {
//	Stack<int, 9> userValues;
//	int ch;
//	do
//	{
//		std::cout
//			<< "1 PUSH TOP\n"
//			<< "2 PUSH BOTTOM\n"
//			<< "3 POP TOP\n"
//			<< "4 POP BOTTOM\n"
//			<< "5 DISPLAY\n"
//			<< "6 EXIT\n"
//			<< "Enter choice = \n";
//		std::cin >> ch;
//		switch (ch)
//		{
//		case 1: {
//			
//			userValues.pushtop();
//			break;
//		}
//
//		case 2: {
//			
//			userValues.pushbottom();
//			break;
//		}
//		case 3: userValues.pop_top(); break;
//		case 4: userValues.pop_bottom(); break;
//		case 5: userValues.display(); break;
//		case 6: break;
//		default: std::cout << "Invalid choice! FOOL!\n"; break;
//		}
//		if (std::cin.fail()) {
//			std::cin.clear();
//			std::cin.ignore(10000, '\n');
//		}
//	} while (ch != 6);
//}
//template <typename T>



void pain() {
	int triangleHeight;
	char triangleChar;
	std::cin >> triangleHeight;
	std::cin >> triangleChar;
	for (int i = 1; i <= triangleHeight; ++i) {
		for (int j = 1; j <= i; ++j) {
			std::cout << triangleChar << ' ';
		}
		std::cout << std::endl;
	}
	
}