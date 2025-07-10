bool __thiscall Scaleform::GFx::AS3::VectorBase<unsigned long>::CompareValuePtr::operator()(
        Scaleform::GFx::AS3::VectorBase<unsigned long>::CompareValuePtr *this,
        Scaleform::GFx::AS3::Value::V1U *a,
        Scaleform::GFx::AS3::Value::V1U *b)
{
  Scaleform::GFx::AS3::VM *Vm; // eax
  Scaleform::GFx::AS3::Value *Func; // ecx
  Scaleform::GFx::AS3::Value::V1U v5; // esi
  bool v6; // bl
  Scaleform::GFx::AS3::Value v8; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value v9; // [esp+18h] [ebp-10h] BYREF

  v9.Bonus.pWeakProxy = 0;
  v8.Bonus.pWeakProxy = 0;
  v9.Flags = 3;
  v8.Flags = 3;
  Vm = this->Vm;
  Func = (Scaleform::GFx::AS3::Value *)this->Func;
  v5 = *b;
  v8.value.VS._1 = *a;
  v9.value.VS._1 = v5;
  v6 = Scaleform::GFx::AS3::Impl::CompareFunct(Vm, Func, &v8, &v9) < 0;
  if ( (v8.Flags & 0x1F) > 9 )
  {
    if ( (v8.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v8);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v8);
  }
  if ( (v9.Flags & 0x1F) > 9 )
  {
    if ( (v9.Flags & 0x200) != 0 )
    {
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v9);
      return v6;
    }
    Scaleform::GFx::AS3::Value::ReleaseInternal(&v9);
  }
  return v6;
}
