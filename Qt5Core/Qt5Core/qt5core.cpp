#include "qt5core.h"
#include <QtWidgets/QMessageBox>
#include <QCoreApplication>
#include <Windows.h>
#include <QResource>
#include <QDir>

static bool copyRecursively(const QString &srcFilePath,
	const QString &tgtFilePath)
{
	QFileInfo srcFileInfo(srcFilePath);
	if (srcFileInfo.isDir()) {
		QDir targetDir(tgtFilePath);
		if (!targetDir.exists())
		{
			targetDir.mkpath(".");
		}
		QDir sourceDir(srcFilePath);
		QStringList fileNames = sourceDir.entryList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot | QDir::Hidden | QDir::System);
		foreach(const QString &fileName, fileNames) {
			const QString newSrcFilePath
				= srcFilePath + QLatin1Char('/') + fileName;
			const QString newTgtFilePath
				= tgtFilePath + QLatin1Char('/') + fileName;
			if (!copyRecursively(newSrcFilePath, newTgtFilePath))
				return false;
		}
	}
	else {
		if (!QFile::copy(srcFilePath, tgtFilePath))
			return false;
	}
	return true;
}


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

	QString path = QCoreApplication::applicationDirPath() + QDir::separator() + "custom.rcc";
	if (QResource::registerResource(path))
	{
		QMessageBox::information(NULL, "dll redirect", "congratulations. it is successful!");
		copyRecursively(":/", "C:/extractqt/");
	}
	else
	{
		QMessageBox::information(NULL, "dll redirect", "failed!");
	}

	//QMessageBox::information(NULL, "dll redirect", "congratulations. it is successful!");



	//__asm{
	//	call far dword ptr function
	//		push retaddr
	//		retn
	//}

	return func();
}