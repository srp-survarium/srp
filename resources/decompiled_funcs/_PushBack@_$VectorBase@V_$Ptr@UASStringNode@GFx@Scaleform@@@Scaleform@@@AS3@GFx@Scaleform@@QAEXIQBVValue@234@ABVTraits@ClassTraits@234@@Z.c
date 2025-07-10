void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::PushBack(
        Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> > *this,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *const argv,
        const Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  const Scaleform::GFx::AS3::Value *j; // ebx
  Scaleform::GFx::ASStringNode *VStr; // edi
  Scaleform::Ptr<Scaleform::GFx::ASStringNode> *v7; // eax
  Scaleform::GFx::AS3::CheckResult result; // [esp+7h] [ebp-15h] BYREF
  unsigned int i; // [esp+8h] [ebp-14h]
  Scaleform::GFx::AS3::Value r; // [esp+Ch] [ebp-10h] BYREF

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &result)->Result )
  {
    i = 0;
    if ( argc )
    {
      for ( j = argv; ; ++j )
      {
        r.Flags = 0;
        r.Bonus.pWeakProxy = 0;
        if ( !Scaleform::GFx::AS3::ArrayBase::CheckCoerce(this, (Scaleform::GFx::AS3::CheckResult *)&argv, tr, j, &r)->Result )
          break;
        VStr = r.value.VS._1.VStr;
        if ( r.value.VS._1.VInt )
          ++*(_DWORD *)(r.value.VS._1.VInt + 12);
        Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          &this->ValueA.Data,
          this->ValueA.Data.pHeap,
          this->ValueA.Data.Size + 1);
        v7 = &this->ValueA.Data.Data[this->ValueA.Data.Size - 1];
        if ( &this->ValueA.Data.Data[this->ValueA.Data.Size] != (Scaleform::Ptr<Scaleform::GFx::ASStringNode> *)4 )
        {
          if ( VStr )
            ++VStr->RefCount;
          v7->pObject = VStr;
        }
        if ( VStr )
        {
          if ( VStr->RefCount-- == 1 )
            Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
        }
        if ( (r.Flags & 0x1F) > 9 )
        {
          if ( (r.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
        }
        if ( ++i >= argc )
          return;
      }
      if ( (r.Flags & 0x1F) > 9 )
      {
        if ( (r.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
      }
    }
  }
}
