void __thiscall Scaleform::GFx::AS3::Abc::ConstPool::Clear(Scaleform::GFx::AS3::Abc::ConstPool *this)
{
  Scaleform::ArrayLH_POD<long,339,Scaleform::ArrayDefaultPolicy> *p_ConstInt; // esi
  Scaleform::ArrayLH_POD<unsigned long,339,Scaleform::ArrayDefaultPolicy> *p_ConstUInt; // esi
  Scaleform::ArrayLH_POD<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,339,Scaleform::ArrayDefaultPolicy> *p_const_ns_set; // esi
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Abc::Multiname,339,Scaleform::ArrayDefaultPolicy> *p_const_multiname; // esi

  p_ConstInt = &this->ConstInt;
  if ( this->ConstInt.Data.Size )
  {
    if ( (this->ConstInt.Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
    {
      if ( p_ConstInt->Data.Data )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_ConstInt->Data.Data);
        p_ConstInt->Data.Data = 0;
      }
      p_ConstInt->Data.Policy.Capacity = 0;
    }
  }
  else if ( !this->ConstInt.Data.Policy.Capacity )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,339>,Scaleform::ArrayDefaultPolicy> *)&this->ConstInt,
      &this->ConstInt,
      0);
  }
  p_ConstInt->Data.Size = 0;
  p_ConstUInt = &this->ConstUInt;
  if ( this->ConstUInt.Data.Size )
  {
    if ( (this->ConstUInt.Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
    {
      if ( p_ConstUInt->Data.Data )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_ConstUInt->Data.Data);
        p_ConstUInt->Data.Data = 0;
      }
      this->ConstUInt.Data.Policy.Capacity = 0;
    }
  }
  else if ( !this->ConstUInt.Data.Policy.Capacity )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,339>,Scaleform::ArrayDefaultPolicy> *)&this->ConstUInt,
      &this->ConstUInt,
      0);
  }
  this->ConstUInt.Data.Size = 0;
  Scaleform::ArrayData<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->ConstStr.Data,
    0);
  Scaleform::ArrayData<Scaleform::GFx::AS3::Abc::NamespaceInfo,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::NamespaceInfo,339>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->ConstNamespace.Data,
    0);
  p_const_ns_set = &this->const_ns_set;
  if ( this->const_ns_set.Data.Size )
  {
    if ( (this->const_ns_set.Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
    {
      if ( p_const_ns_set->Data.Data )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_const_ns_set->Data.Data);
        p_const_ns_set->Data.Data = 0;
      }
      this->const_ns_set.Data.Policy.Capacity = 0;
    }
  }
  else if ( !this->const_ns_set.Data.Policy.Capacity )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->const_ns_set.Data,
      &this->const_ns_set,
      0);
  }
  this->const_ns_set.Data.Size = 0;
  p_const_multiname = &this->const_multiname;
  if ( !this->const_multiname.Data.Size )
  {
    if ( !this->const_multiname.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::Multiname,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::Multiname,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &this->const_multiname.Data,
        &this->const_multiname,
        0);
    goto LABEL_29;
  }
  if ( (this->const_multiname.Data.Policy.Capacity & 0xFFFFFFFE) == 0 )
  {
LABEL_29:
    this->const_multiname.Data.Size = 0;
    return;
  }
  if ( p_const_multiname->Data.Data )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_const_multiname->Data.Data);
    p_const_multiname->Data.Data = 0;
  }
  this->const_multiname.Data.Policy.Capacity = 0;
  this->const_multiname.Data.Size = 0;
}
