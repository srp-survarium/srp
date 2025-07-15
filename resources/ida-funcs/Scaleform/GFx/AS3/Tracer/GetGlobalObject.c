Scaleform::GFx::AS3::Value *__thiscall Scaleform::GFx::AS3::Tracer::GetGlobalObject(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::AS3::TR::State *st)
{
  const Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *pSavedScope; // eax
  Scaleform::GFx::AS3::Value *Data; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // edi

  pSavedScope = this->CF->pSavedScope;
  if ( pSavedScope->Data.Size )
    Data = pSavedScope->Data.Data;
  else
    Data = st->Registers.Data.Data;
  Flags = Data->Flags;
  pWeakProxy = Data->Bonus.pWeakProxy;
  result->value.VNumber = Data->value.VNumber;
  result->Flags = Flags;
  result->Bonus.pWeakProxy = pWeakProxy;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
    {
      ++pWeakProxy->RefCount;
      return result;
    }
    Scaleform::GFx::AS3::Value::AddRefInternal(Data);
  }
  return result;
}
