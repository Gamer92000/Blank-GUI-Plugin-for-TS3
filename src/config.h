#pragma once
#include <QtWidgets/QDialog>
#pragma comment (lib, "Qt5Widgets")
#pragma comment (lib, "Qt5Core")
#include <QtCore/QSettings>
#include <memory>

namespace Ui {
	class Config;
}

class config : public QDialog
{
	Q_OBJECT
public:
	config(const QString& configLocation, QWidget* parent = nullptr);
	~config();
	config(const config& other) = delete;
	config& operator=(const config& other) = delete;

	void setConfigOption(const QString& option, const QVariant& value);
	QVariant getConfigOption(const QString& option) const;

protected:
	void showEvent(QShowEvent* e) override;
	void changeEvent(QEvent* e) override;

private:
	std::unique_ptr<Ui::Config> m_ui;
	std::unique_ptr<QSettings> m_settings;

	
	void loadSettings();
private slots:
	void saveSettings();
};
