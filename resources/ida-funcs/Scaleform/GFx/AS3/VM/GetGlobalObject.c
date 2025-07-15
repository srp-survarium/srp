Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *__thiscall Scaleform::GFx::AS3::VM::GetGlobalObject(
        Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::CallFrame *v1; // eax
  const Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *pSavedScope; // ecx
  Scaleform::GFx::AS3::Value *pRF; // ecx

  if ( !this->CallStack.Size )
    return 0;
  v1 = &this->CallStack.Pages[(this->CallStack.Size - 1) >> 6][(this->CallStack.Size - 1) & 0x3F];
  pSavedScope = v1->pSavedScope;
  if ( pSavedScope->Data.Size )
    return (Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *)pSavedScope->Data.Data->value.VS._1.VInt;
  pRF = v1->pRegisterFile->pRF;
  if ( (pRF->Flags & 0x1F) - 12 <= 3 )
    return (Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *)pRF->value.VS._1.VInt;
  else
    return 0;
}
