#include "layer.h"

using namespace ncnn;



// a new layer type called MyLayer
class VoxelGenerator : public Layer
{


public:
    VoxelGenerator();// new code
    virtual int load_param(const ParamDict& pd);// new code
    virtual int load_model(const ModelBin& mb);// new code

private:
    int channels;
    float eps;
    Mat gamma_data;

};
