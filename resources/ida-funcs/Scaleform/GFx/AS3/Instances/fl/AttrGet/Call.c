char __thiscall Scaleform::GFx::AS3::Instances::fl::AttrGet::Call(
        Scaleform::GFx::AS3::Instances::fl::AttrGet *this,
        unsigned int ind)
{
  Scaleform::GFx::AS3::ClassTraits::Traits *pObject; // ebx
  Scaleform::GFx::AS3::Instances::fl::XMLList *List; // esi
  unsigned int Size; // eax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *p_List; // esi
  unsigned int RefCount; // eax

  pObject = (Scaleform::GFx::AS3::ClassTraits::Traits *)this->Element->Attrs.Data.Data[ind].pObject;
  if ( pObject )
    pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
  List = this->List;
  Size = List->List.Data.Size;
  p_List = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&List->List;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    p_List,
    p_List,
    Size + 1);
  if ( &p_List->Data[p_List->Size] != (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *)4 )
  {
    p_List->Data[p_List->Size - 1].pObject = pObject;
    if ( !pObject )
      return 1;
    pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
  }
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) == 0 )
    {
      RefCount = pObject->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  return 1;
}
