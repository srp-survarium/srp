Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *__thiscall Scaleform::GFx::AS3::CallFrame::GetGlobalObject(
        Scaleform::GFx::AS3::CallFrame *this)
{
  const Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *pSavedScope; // eax
  Scaleform::GFx::AS3::Value *pRF; // ecx

  pSavedScope = this->pSavedScope;
  if ( pSavedScope->Data.Size )
    return (Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *)pSavedScope->Data.Data->value.VS._1.VInt;
  pRF = this->pRegisterFile->pRF;
  if ( (pRF->Flags & 0x1F) - 12 > 3 )
    return 0;
  else
    return (Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *)pRF->value.VS._1.VInt;
}
