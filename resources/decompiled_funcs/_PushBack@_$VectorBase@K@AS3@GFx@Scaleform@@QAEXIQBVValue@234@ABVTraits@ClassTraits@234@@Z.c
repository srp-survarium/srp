void __thiscall Scaleform::GFx::AS3::VectorBase<unsigned long>::PushBack(
        Scaleform::GFx::AS3::VectorBase<unsigned long> *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        const Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  Scaleform::GFx::AS3::Value::V1U v5; // ebp
  const Scaleform::MemoryHeap *pHeap; // eax
  Scaleform::ArrayDH<unsigned long,2,Scaleform::ArrayDefaultPolicy> *p_ValueA; // edi
  unsigned int v8; // esi
  Scaleform::GFx::AS3::Value::V1U *v9; // eax
  Scaleform::GFx::AS3::CheckResult result; // [esp+7h] [ebp-19h] BYREF
  Scaleform::GFx::AS3::Value *v; // [esp+8h] [ebp-18h]
  unsigned int i; // [esp+Ch] [ebp-14h]
  Scaleform::GFx::AS3::Value r; // [esp+10h] [ebp-10h] BYREF

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &result)->Result )
  {
    i = 0;
    if ( argc )
    {
      v = argv;
      while ( 1 )
      {
        r.Flags = 0;
        r.Bonus.pWeakProxy = 0;
        if ( !Scaleform::GFx::AS3::ArrayBase::CheckCoerce(this, (Scaleform::GFx::AS3::CheckResult *)&argv, tr, v, &r)->Result )
          break;
        v5 = r.value.VS._1;
        pHeap = this->ValueA.Data.pHeap;
        p_ValueA = &this->ValueA;
        v8 = this->ValueA.Data.Size + 1;
        if ( v8 >= this->ValueA.Data.Size )
        {
          if ( v8 >= this->ValueA.Data.Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)p_ValueA,
              pHeap,
              v8 + (v8 >> 2));
        }
        else if ( v8 < this->ValueA.Data.Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)p_ValueA,
            pHeap,
            this->ValueA.Data.Size + 1);
        }
        v9 = (Scaleform::GFx::AS3::Value::V1U *)&p_ValueA->Data.Data[v8 - 1];
        this->ValueA.Data.Size = v8;
        if ( v9 )
          *v9 = v5;
        if ( (r.Flags & 0x1F) > 9 )
        {
          if ( (r.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
        }
        ++v;
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
