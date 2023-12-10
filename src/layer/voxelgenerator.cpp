#include "voxelgenerator.h"

DEFINE_LAYER_CREATOR(VoxelGenerator)
int VoxelGenerator::load_param(const ParamDict& pd)
{
    // details about the relations with param file
    // https://github.com/Tencent/ncnn/wiki/param-and-model-file-structure
    //
    channels = pd.get(0, 0);// parse 0=<int value> entry, default value 0
    eps = pd.get(1, 0.001f);// parse 1=<float value> entry, default value 0.001f



    // you could alter the behavior based on loaded parameter
    // if (eps == 0.001f)
    // {
    //     one_blob_only = false;
    //     support_inplace = false;
    // }

    return 0;// return zero if success
}



// new routine for loading weights
int VoxelGenerator::load_model(const ModelBin& mb)
{
    // details about the relations with model file
    // https://github.com/Tencent/ncnn/wiki/param-and-model-file-structure
    //
    // read weights with length of channels * sizeof(float)
    // the second argument explains as follows
    // 0 judge the value type automatically, you may get float or float16 or uint8 etc
    //   depends on the model storage and the supporting target hardware
    // 1 read float values anyway
    // 2 read float16 values anyway
    // 3 read uint8 values anyway
    gamma_data = mb.load(channels, 1);
    if (gamma_data.empty())
        return -100;// return non-zero on error, -100 indicates out-of-memory

    // you could alter the behavior based on loaded weight
    // if (gamma_data[0] == 0.f)
    // {
    //     one_blob_only = false;
    //     support_inplace = false;
    // }

    return 0;// return zero if success
}
```


// new routine for setting forward behavior
VoxelGenerator::VoxelGenerator()
{
    // one input and one output
    // typical one_blob_only type: Convolution, Pooling, ReLU, Softmax ...
    // typical non-one_blob_only type: Eltwise, Split, Concat, Slice ...
    one_blob_only = true;

    // do not change the blob size, modify data in-place
    // typical support_inplace type: ReLU, Sigmoid ...
    // typical non-support_inplace type: Convolution, Pooling ...
    support_inplace = true;
}
