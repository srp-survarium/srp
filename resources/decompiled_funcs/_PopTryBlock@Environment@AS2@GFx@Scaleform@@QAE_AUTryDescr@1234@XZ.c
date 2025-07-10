Scaleform::GFx::AS2::Environment::TryDescr *__thiscall Scaleform::GFx::AS2::Environment::PopTryBlock(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::AS2::Environment::TryDescr *result)
{
  unsigned int Size; // eax
  Scaleform::GFx::AS2::Environment::TryDescr *v3; // edx
  unsigned int TryBeginPC; // edi
  unsigned int TopStackIndex; // edx

  Size = this->TryBlocks.Data.Size;
  v3 = &this->TryBlocks.Data.Data[Size - 1];
  result->pTryBlock = v3->pTryBlock;
  TryBeginPC = v3->TryBeginPC;
  TopStackIndex = v3->TopStackIndex;
  result->TryBeginPC = TryBeginPC;
  result->TopStackIndex = TopStackIndex;
  Scaleform::ArrayData<Scaleform::GFx::AS2::Environment::TryDescr,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Environment::TryDescr,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->TryBlocks.Data,
    Size - 1);
  return result;
}
