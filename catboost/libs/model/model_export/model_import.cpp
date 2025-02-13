#include "coreml_helpers.h"
#include "json_model_helpers.h"

#include <catboost/libs/model/model_import_interface.h>
#include <catboost/libs/options/json_helper.h>

#include <library/json/json_reader.h>

#include <contrib/libs/coreml/TreeEnsemble.pb.h>
#include <contrib/libs/coreml/Model.pb.h>

#include <util/generic/buffer.h>
#include <util/stream/buffer.h>
#include <util/stream/file.h>
#include <util/system/fs.h>

namespace NCB {
    class TJsonModelLoader : public IModelLoader {
    public:
        TFullModel ReadModel(IInputStream* modelStream) const override {
            TFullModel model;
            NJson::TJsonValue jsonModel = NJson::ReadJsonTree(modelStream);
            CB_ENSURE(jsonModel.IsDefined(), "Json model deserialization failed");
            ConvertJsonToCatboostModel(jsonModel, &model);
            CheckModel(&model);
            return model;
        }
    };

    TModelLoaderFactory::TRegistrator<TJsonModelLoader> JsonModelLoaderRegistrator(EModelType::Json);

    class TCoreMLModelLoader : public IModelLoader {
    public:
        TFullModel ReadModel(IInputStream* modelStream) const override {
            TFullModel model;
            CoreML::Specification::Model coreMLModel;
            CB_ENSURE(coreMLModel.ParseFromString(modelStream->ReadAll()), "coreml model deserialization failed");
            NCB::NCoreML::ConvertCoreMLToCatboostModel(coreMLModel, &model);
            CheckModel(&model);
            return model;
        }
    };

    TModelLoaderFactory::TRegistrator<TCoreMLModelLoader> CoreMLModelLoaderRegistrator(EModelType::AppleCoreML);
}
