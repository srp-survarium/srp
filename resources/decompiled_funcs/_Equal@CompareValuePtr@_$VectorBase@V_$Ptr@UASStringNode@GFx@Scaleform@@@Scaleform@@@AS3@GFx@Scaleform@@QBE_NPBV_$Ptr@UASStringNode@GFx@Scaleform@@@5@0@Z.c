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
