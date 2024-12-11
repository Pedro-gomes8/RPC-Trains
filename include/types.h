
#include <string>

struct TrainData
{
    int id;
    int trainLoc;
    int EOA;
};
struct MessageTrain
{
    int code;
    struct TrainData data;
};

struct ServerResponse
{
    int ack;
    struct TrainData traindata;
};
