#include "iattool.h"

IATTool::IATTool(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

IATTool::~IATTool()
{

}

void IATTool::on_pushButtonGen_clicked()
{
	QString text = ui.plainTextEditIn->toPlainText();
	outText.clear();

	QString newDllStr = ui.lineEditNewDll->text();

	QStringList textLines = text.split("\n", QString::SkipEmptyParts);
	QStringList args;

	int i = 0;
	for (i = 0; i < textLines.size(); i++)
	{
		args = textLines[i].split(QRegExp("\\s+"), QString::SkipEmptyParts);
		if (args.size() >= 4)
		{
			outText += QString("#pragma comment(linker, \"/export:%1=%2.%1,@%3\")\n").arg(args[3]).arg(newDllStr).arg(args[0]);
		}
	}

	ui.plainTextEditOut->setPlainText(outText);
}
