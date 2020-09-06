#include "config.h"
#include "../.vsgen/ui_config.h"

config::config(const QString& configLocation, QWidget* parent /* = nullptr */) : QDialog(parent),
m_ui(std::make_unique<Ui::Config>()),
m_settings(std::make_unique<QSettings>(configLocation + "/Plugin.ini", QSettings::IniFormat, this))
{
	m_ui->setupUi(this);

	setWindowTitle("Plugin :: Settings");

	connect(m_ui->buttonBox, SIGNAL(accepted()), this, SLOT(saveSettings()));
	connect(m_ui->buttonBox, SIGNAL(rejected()), this, SLOT(close()));

	//connect(m_ui->pokeEnable, &QCheckBox::toggled, this, [&](bool checked) {
	//	m_ui->poke1->setEnabled(checked);
	//	});
	adjustSize();
	setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
	setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

config::~config() {
	m_settings->sync();
}

void config::setConfigOption(const QString& option, const QVariant& value) {
	m_settings->setValue(option, value);
}

QVariant config::getConfigOption(const QString& option) const {
	return m_settings->value(option);
}

void config::showEvent(QShowEvent* /* e */) {
	adjustSize();
	loadSettings();
}

void config::changeEvent(QEvent* e) {
	if (e->type() == QEvent::StyleChange && isVisible()) {
		m_ui->verticalLayoutWidget->adjustSize();
		adjustSize();
	}
}

void config::saveSettings() {
	//setConfigOption("botToken", m_ui->BotTokenInput->text());
	close();
}

void config::loadSettings() {
	//m_ui->BotTokenInput->setText(getConfigOption("botToken").toString());

	// Manually set enabled state of elements, as the event doesn't fire if the state is the same as it was already (ie. unchecked).
	//m_ui->poke1->setEnabled(m_ui->pokeEnable->isChecked());
}