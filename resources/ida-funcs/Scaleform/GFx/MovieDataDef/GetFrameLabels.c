Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy> *__thiscall Scaleform::GFx::MovieDataDef::GetFrameLabels(
        Scaleform::GFx::MovieDataDef *this,
        unsigned int frameNumber,
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *destArr)
{
  return Scaleform::GFx::MovieDataDef::LoadTaskData::GetFrameLabels(this->pData.pObject, frameNumber, destArr);
}
