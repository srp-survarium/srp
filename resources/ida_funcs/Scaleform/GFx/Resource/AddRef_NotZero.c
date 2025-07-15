char __thiscall Scaleform::GFx::Resource::AddRef_NotZero(Scaleform::GFx::Resource *this)
{
  volatile int Value; // esi
  Scaleform::AtomicInt<long> *p_RefCount; // edi

  Value = this->RefCount.Value;
  p_RefCount = &this->RefCount;
  if ( !Value )
    return 0;
  while ( InterlockedCompareExchange(&p_RefCount->Value, Value + 1, Value) != Value )
  {
    Value = p_RefCount->Value;
    if ( !p_RefCount->Value )
      return 0;
  }
  return 1;
}
