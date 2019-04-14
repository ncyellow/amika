#pragma once
#include <QString>
#include <memory>

namespace amika {
namespace radare {



class Radare
{
public:
    Radare();
    ~Radare();

    bool OpenFile(const QString &filename);
private:
    class Impl;
    std::unique_ptr<Impl> mImpl;
};

}
}

