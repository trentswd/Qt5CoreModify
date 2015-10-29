#include "qt5core.h"
#include <QtWidgets/QMessageBox>
#include <QCoreApplication>
#include <Windows.h>


Qt5Core::Qt5Core()
{

}

Qt5Core::~Qt5Core()
{

}

//extern "C" void QT5CORE_EXPORT qt_startup_hook()
//{
//	QMessageBox::information(NULL, "dll redirect", "congratulations. it is successful!");
//}

typedef int  (*execFunc)();

int QCoreApplication::exec()
{
	HINSTANCE handle;
	execFunc func;
	int retaddr;
	//__asm{
	//	pop retaddr
	//}

	handle = LoadLibraryA("Qt5CoreImpl.dll");
	if (!handle){
		QMessageBox::information(NULL, "dll redirect", "Failed to load Qt5CoreImpl.dll!");
		ExitProcess(0);
	}

	func = (execFunc)GetProcAddress(handle, "?exec@QCoreApplication@@SAHXZ");
	if (!func){
		QMessageBox::information(NULL, "dll redirect", "Failed to load GetProcessDefaultLayout!");
		ExitProcess(0);
	}

	QMessageBox::information(NULL, "dll redirect", "congratulations. it is successful!");

	//__asm{
	//	call far dword ptr function
	//		push retaddr
	//		retn
	//}

	return func();
}