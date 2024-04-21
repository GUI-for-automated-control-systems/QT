#ifndef RPCBRIDGE_H
#define RPCBRIDGE_H

#include <QObject>
#include "rep_rpcbridge_source.h"

class RPCBridgePrivate;
class RPCBridge : public RPCBridgeSampleSource
{
    Q_OBJECT;
    Q_DECLARE_PRIVATE(RPCBridge);
public:
    RPCBridge(QObject* parrent = nullptr);
    ~RPCBridge();

    void changeServerState(int state)
    {
        setServerState(state);
    }

private slots:
    void onCollectionDataChanged(bool collect);

private:
    RPCBridgePrivate* d_ptr = nullptr;
};

#endif // RPCBRIDGE_H

