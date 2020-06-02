#include "SubnetDialog.h"
#include "ui_SubnetDialog.h"

using namespace core;

SubnetDialog::SubnetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SubnetDialog),
    subnet{ 1 , {} }
{
    ui->setupUi(this);
}

SubnetDialog::~SubnetDialog()
{
    delete ui;
}

void SubnetDialog::InjectData(Subnetv4 subnet)
{
    this->subnet = subnet;
    SetData();
}

void SubnetDialog::SetData()
{
    ui->subnetName->setText(subnet.SubName());

    QIcon icon;
    QPixmap pixmap(":/resources/img/switch.png");
    icon.addPixmap(pixmap);
    ui->graphImage->setIconSize(QSize(120,120));
    ui->graphImage->setIcon(icon);

    ui->hostCount->setText(QString::fromStdString(subnet.HostNumber().str()));
    ui->hostCapacity->setText(QString::fromStdString(subnet.hostsCapacity().str()));
    ui->progressBar->setRange(0, subnet.hostsCapacity().convert_to<unsigned long long>());
    ui->progressBar->setValue(subnet.HostNumber().convert_to<unsigned long long>());

    ui->subnetAddressBinary->setText(subnet.Ip().asStringBin());
    ui->subnetAddressDecimal->setText(subnet.Ip().asStringDec());
    ui->subnetMaskBinary->setText(subnet.Mask().asStringBin());
    ui->subnetMaskDecimal->setText(subnet.Mask().asStringDec());

    ui->firstAddressBinary->setText(subnet.getMinHost()->asStringBin());
    ui->firstAddressDecimal->setText(subnet.getMinHost()->asStringDec());
    ui->lastAddressBinary->setText(subnet.getMaxHost()->asStringBin());
    ui->lastAddressDecimal->setText(subnet.getMaxHost()->asStringDec());

    ui->broadcastAddressBinary->setText(subnet.getBroadcast()->asStringBin());
    ui->broadcastAddressDecimal->setText(subnet.getBroadcast()->asStringDec());

}

void SubnetDialog::on_subnetName_textEdited(const QString &arg1)
{
    subnet.SubName() = arg1;
}
