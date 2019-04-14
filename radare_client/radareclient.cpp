#include "radareclient.h"

#include <QString>
#include <QDebug>

#include <r_asm.h>
#include <r_core.h>
#include <sdb.h>

#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>

namespace amika {
namespace radare_client {

class RadareClient::Impl
{
public:
    Impl();
    ~Impl();
    bool OpenFile(const QString &filename);
private:
    void cmdj(const char *str)
    {
        r_core_task_sync_begin(mCore);
        char *res = r_core_cmd_str(mCore, str);
        r_core_task_sync_end(mCore);
        QByteArray json(res);
        QJsonDocument doc = QJsonDocument::fromJson(json);
        qDebug() << res;
        qDebug() << doc;
        r_mem_free(res);
    }

private:
    RCore* mCore;
};


RadareClient::Impl::Impl()
{
    r_cons_new();  // initialize console
    mCore = r_core_new();
}

RadareClient::Impl::~Impl()
{
    r_core_free(this->mCore);
    r_cons_free();
}

bool RadareClient::Impl::OpenFile(const QString &filename)
{
    RCoreFile *file = r_core_file_open(mCore, filename.toUtf8().constData(), 0, 0);
    if (!file) {
        qWarning() << QString( "cant open file %1").arg(filename);
        return false;
    }

    qDebug() << "open is correct";
    r_core_file_close(mCore, file);
    return true;
}


RadareClient::RadareClient():
    mImpl(new Impl())
{


}

RadareClient::~RadareClient()
{

}

bool RadareClient::OpenFile(const QString &filename)
{
    return mImpl->OpenFile(filename);
}

}
}
