bool __thiscall Scaleform::GFx::AS3::VectorBase<long>::CompareValuePtr::Equal(
        Scaleform::GFx::AS3::VectorBase<long>::CompareValuePtr *this,
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
  v9.Flags = 2;
  v8.Flags = 2;
  Vm = this->Vm;
  Func = (Scaleform::GFx::AS3::Value *)this->Func;
  v5 = *b;
  v8.value.VS._1 = *a;
  v9.value.VS._1 = v5;
  v6 = Scaleform::GFx::AS3::Impl::CompareFunct(Vm, Func, &v8, &v9) == 0;
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


bool __thiscall Scaleform::GFx::AS3::VectorBase<unsigned long>::CompareValuePtr::Equal(
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
  v6 = Scaleform::GFx::AS3::Impl::CompareFunct(Vm, Func, &v8, &v9) == 0;
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


bool __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::CompareValuePtr::Equal(
        Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> >::CompareValuePtr *this,
        const Scaleform::Ptr<Scaleform::GFx::ASStringNode> *a,
        const Scaleform::Ptr<Scaleform::GFx::ASStringNode> *b)
{
  Scaleform::GFx::AS3::VM *Vm; // ebx
  Scaleform::GFx::ASStringNode *pObject; // edi
  Scaleform::GFx::AS3::Value *v6; // eax
  Scaleform::GFx::AS3::Value *v7; // eax
  bool v8; // bl
  Scaleform::GFx::AS3::Value *v10; // [esp-4h] [ebp-30h]
  Scaleform::GFx::AS3::Value v11; // [esp+Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value v12; // [esp+1Ch] [ebp-10h] BYREF

  Vm = this->Vm;
  pObject = a->pObject;
  Scaleform::GFx::AS3::Value::Value(&v12, b->pObject);
  v10 = v6;
  Scaleform::GFx::AS3::Value::Value(&v11, pObject);
  v8 = Scaleform::GFx::AS3::Impl::CompareFunct(Vm, (Scaleform::GFx::AS3::Value *)this->Func, v7, v10) == 0;
  if ( (v11.Flags & 0x1F) > 9 )
  {
    if ( (v11.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v11);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v11);
  }
  if ( (v12.Flags & 0x1F) > 9 )
  {
    if ( (v12.Flags & 0x200) != 0 )
    {
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v12);
      return v8;
    }
    Scaleform::GFx::AS3::Value::ReleaseInternal(&v12);
  }
  return v8;
}
