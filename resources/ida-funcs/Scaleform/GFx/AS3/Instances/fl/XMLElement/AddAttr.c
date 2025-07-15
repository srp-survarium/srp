void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::Instances::fl::Namespace *ns,
        const Scaleform::GFx::ASString *n,
        const Scaleform::GFx::ASString *v)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // edi
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *v6; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v7; // eax
  Scaleform::GFx::AS3::ClassTraits::Traits *v8; // ebx
  unsigned int Size; // edx
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *p_Attrs; // esi
  unsigned int RefCount; // eax

  pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->pTraits.pObject;
  v6 = (Scaleform::GFx::AS3::Instances::fl::XMLAttr *)pObject->pVM->MHeap->Alloc(pObject->pVM->MHeap, 48u, 0);
  if ( v6 )
  {
    Scaleform::GFx::AS3::Instances::fl::XMLAttr::XMLAttr(v6, pObject, ns, n, v, this);
    v8 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v7;
  }
  else
  {
    v8 = 0;
  }
  Size = this->Attrs.Data.Size;
  p_Attrs = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Attrs;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    p_Attrs,
    p_Attrs,
    Size + 1);
  if ( &p_Attrs->Data[p_Attrs->Size] != (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *)4 )
  {
    p_Attrs->Data[p_Attrs->Size - 1].pObject = v8;
    if ( !v8 )
      return;
    v8->RefCount = (v8->RefCount + 1) & 0x8FBFFFFF;
  }
  if ( v8 && ((unsigned __int8)v8 & 1) == 0 )
  {
    RefCount = v8->RefCount;
    if ( (RefCount & 0x3FFFFF) != 0 )
    {
      v8->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v8);
    }
  }
}
