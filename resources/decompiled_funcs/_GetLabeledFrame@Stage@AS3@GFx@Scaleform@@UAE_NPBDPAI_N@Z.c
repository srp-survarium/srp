bool __thiscall Scaleform::GFx::AS3::Stage::GetLabeledFrame(
        Scaleform::GFx::AS3::Stage *this,
        const char *plabel,
        unsigned int *frameNumber,
        BOOL translateNumbers)
{
  Scaleform::GFx::DisplayObjContainer *pObject; // ecx

  pObject = this->pRoot.pObject;
  return pObject && pObject->GetLabeledFrame(pObject, plabel, frameNumber, translateNumbers);
}
