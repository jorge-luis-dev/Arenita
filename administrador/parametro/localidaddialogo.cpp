#include "localidaddialogo.h"
#include "ui_localidaddialogo.h"

LocalidadDialogo::LocalidadDialogo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LocalidadDialogo)
{
    ui->setupUi(this);

}

LocalidadDialogo::~LocalidadDialogo()
{
    delete ui;
}
void LocalidadDialogo::sendMessage()
{
    emit messageSent(this->mensaje);
}
void LocalidadDialogo::setMensaje(const Mensaje &mensaje)
{
    this->mensaje = mensaje;
    qDebug() << "Localidad Dialogo: "+mensaje.getUsuario()+"  |  "+mensaje.getTipo()
                            +"  |  "+mensaje.getServidor();
}

void LocalidadDialogo::on_pushAceptar_clicked()
{
    Conectar *co =  new Conectar(mensaje.getServidor());

    QSqlDatabase *db = co->conecta(mensaje.getUsuario(),mensaje.getClave());
    QSqlTableModel *model = new QSqlTableModel;

    model->setTable("adm_localidades");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    /*
    model->select();

    int rowCount = model->rowCount();
    qDebug() << "Número de registros" << rowCount;

    QSqlRecord record = model->record();
    record.setValue(1,QVariant(tr("Colombia")));
    record.setValue(2,QVariant("Activo"));

    model->insertRecord(1,record);
    model->submitAll();
    */
    QSqlRecord myRecord;

    myRecord.append(QSqlField("localidad", QVariant::Int));
    myRecord.append(QSqlField("estado", QVariant::Int));

    myRecord.setValue("localidad",ui->txtLocalidad->text());

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
