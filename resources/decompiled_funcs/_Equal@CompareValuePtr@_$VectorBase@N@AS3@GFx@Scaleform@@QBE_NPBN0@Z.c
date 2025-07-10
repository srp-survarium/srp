bool __thiscall Scaleform::GFx::AS3::VectorBase<double>::CompareValuePtr::Equal(
        Scaleform::GFx::AS3::VectorBase<double>::CompareValuePtr *this,
        long double *a,
        long double *b)
{
  Scaleform::GFx::AS3::VM *Vm; // eax
  Scaleform::GFx::AS3::Value *Func; // ecx
  bool v5; // bl
  Scaleform::GFx::AS3::Value v7; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value v8; // [esp+18h] [ebp-10h] BYREF

  v8.value.VNumber = *b;
  v8.Flags = 4;
  v7.Flags = 4;
  v8.Bonus.pWeakProxy = 0;
  v7.Bonus.pWeakProxy = 0;
  Vm = this->Vm;
  Func = (Scaleform::GFx::AS3::Value *)this->Func;
  v7.value.VNumber = *a;
  v5 = Scaleform::GFx::AS3::Impl::CompareFunct(Vm, Func, &v7, &v8) == 0;
  if ( (v7.Flags & 0x1F) > 9 )
  {
    if ( (v7.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v7);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v7);
  }
  if ( (v8.Flags & 0x1F) > 9 )
  {
    if ( (v8.Flags & 0x200) != 0 )
    {
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v8);
      return v5;
    }
    Scaleform::GFx::AS3::Value::ReleaseInternal(&v8);
  }
  return v5;
}
