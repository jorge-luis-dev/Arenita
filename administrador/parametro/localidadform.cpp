#include "localidadform.h"
#include "ui_localidadform.h"

LocalidadForm::LocalidadForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LocalidadForm)
{
    ui->setupUi(this);
}

LocalidadForm::~LocalidadForm()
{
    delete ui;
}

void LocalidadForm::on_pushAceptar_clicked()
{
    Conectar *co =  new Conectar(mensaje.getServidor());

    QSqlDatabase *db = co->conecta(mensaje.getUsuario(),mensaje.getClave());
    QSqlTableModel *model = new QSqlTableModel;

    model->setTable("adm_localidades");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    QSqlRecord myRecord;

    myRecord.append(QSqlField("localidad", QVariant::Int));
    myRecord.append(QSqlField("estado", QVariant::Int));
    myRecord.append(QSqlField("observacion", QVariant::Int));

    myRecord.setValue("localidad",ui->txtLocalidad->text());
    myRecord.setValue("observacion",ui->textObservacion->toPlainText());

    if(ui->checkEstado->isChecked())
        myRecord.setValue("estado","Activo");
    else
        myRecord.setValue("estado","Inactivo");

    model->insertRecord(-1,myRecord);
    model->submitAll();

    qDebug() << model->lastError().text();

    db->close();
    co->desconecta();
}

void LocalidadForm::sendMessage()
{
    emit messageSent(this->mensaje);
}
void LocalidadForm::setMensaje(const Mensaje &mensaje)
{
    this->mensaje = mensaje;
    qDebug() << "Localidad Dialogo: "+mensaje.getUsuario()+"  |  "+mensaje.getTipo()
                            +"  |  "+mensaje.getServidor();
}
