#include "MyForm.h"

using namespace Forms;
int main() {
	srand(time(NULL));
	Application::Run(gcnew MyForm());
	return 0;
}