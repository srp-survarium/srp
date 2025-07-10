char __thiscall Scaleform::GFx::MovieDataDef::GetLabeledFrame(
        Scaleform::GFx::MovieDataDef *this,
        char *label,
        unsigned int *frameNumber,
        bool translateNumbers)
{
  return Scaleform::GFx::MovieDataDef::LoadTaskData::GetLabeledFrame(
           this->pData.pObject,
           label,
           frameNumber,
           translateNumbers);
}
