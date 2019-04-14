#ifndef RADARECLIENT_H
#define RADARECLIENT_H

#include <QString>
#include <memory>
#include "radare_client_global.h"

namespace amika {
namespace radare_client {

class RADARE_CLIENTSHARED_EXPORT RadareClient
{
public:
    RadareClient();
    ~RadareClient();

    bool OpenFile(const QString &filename);
private:
    class Impl;
    std::unique_ptr<Impl> mImpl;
};


}
}

#endif // RADARECLIENT_H
