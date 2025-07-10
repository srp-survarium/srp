void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::Apppend(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::GFx::AS3::Instances::fl::XML *v)
{
  Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2,Scaleform::ArrayDefaultPolicy> *p_List; // esi
  unsigned int RefCount; // eax

  if ( v )
    v->RefCount = (v->RefCount + 1) & 0x8FBFFFFF;
  p_List = &this->List;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&this->List,
    &this->List,
    this->List.Data.Size + 1);
  if ( &p_List->Data.Data[p_List->Data.Size] != (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)4 )
  {
    p_List->Data.Data[p_List->Data.Size - 1].pObject = v;
    if ( !v )
      return;
    v->RefCount = (v->RefCount + 1) & 0x8FBFFFFF;
  }
  if ( v && ((unsigned __int8)v & 1) == 0 )
  {
    RefCount = v->RefCount;
    if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
    {
      v->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v);
    }
  }
}
