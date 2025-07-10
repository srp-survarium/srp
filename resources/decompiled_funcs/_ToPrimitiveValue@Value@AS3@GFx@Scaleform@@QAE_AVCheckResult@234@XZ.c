Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Value::ToPrimitiveValue(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::CheckResult *result)
{
  bool v2; // bl
  Scaleform::GFx::AS3::Value::Extra v4; // ecx
  Scaleform::GFx::AS3::Value::V1U v5; // edx
  unsigned int Flags; // eax
  unsigned int v7; // ebp
  Scaleform::GFx::AS3::Value::V2U v8; // edi
  void *pWeakProxy; // eax
  Scaleform::GFx::AS3::CheckResult v12; // [esp+Fh] [ebp-11h] BYREF
  Scaleform::GFx::AS3::Value v; // [esp+10h] [ebp-10h] BYREF

  v2 = 0;
  if ( (_S10_0 & 1) == 0 )
  {
    _S10_0 |= 1u;
    ::v.Flags = 0;
    ::v.Bonus.pWeakProxy = 0;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  v = ::v;
  if ( (::v.Flags & 0x1F) > 9 )
  {
    if ( (::v.Flags & 0x200) != 0 )
      ++::v.Bonus.pWeakProxy->RefCount;
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&::v);
  }
  if ( Scaleform::GFx::AS3::Value::Convert2PrimitiveValueUnsafe(this, &v12, &v, hintNone)->Result )
  {
    v4.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v.Bonus;
    v5 = v.value.VS._1;
    Flags = v.Flags;
    v7 = this->Flags;
    v.Bonus.pWeakProxy = this->Bonus.pWeakProxy;
    v8.VObj = (Scaleform::GFx::AS3::Object *)v.value.VS._2;
    v.value.VNumber = this->value.VNumber;
    this->value.VS._2 = v8;
    v.Flags = v7;
    this->Flags = Flags;
    this->Bonus = v4;
    this->value.VS._1 = v5;
    v2 = 1;
  }
  else
  {
    LOWORD(v7) = v.Flags;
  }
  result->Result = v2;
  if ( (v7 & 0x1F) > 9 )
  {
    if ( (v7 & 0x200) != 0 )
    {
      pWeakProxy = v.Bonus.pWeakProxy;
      if ( v.Bonus.pWeakProxy->RefCount-- == 1 )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
        return result;
      }
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
    }
  }
  return result;
}
