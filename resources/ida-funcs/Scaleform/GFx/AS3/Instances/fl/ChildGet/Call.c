bool __thiscall Scaleform::GFx::AS3::Instances::fl::ChildGet::Call(
        Scaleform::GFx::AS3::Instances::fl::ChildGet *this,
        unsigned int ind)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *Data; // edx
  Scaleform::GFx::AS3::Instances::fl::XMLList *List; // esi
  unsigned int Size; // ecx
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *p_List; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v6; // edi
  unsigned int v7; // edx
  Scaleform::GFx::AS3::ClassTraits::Traits *pObject; // ecx
  bool result; // al

  Data = this->Element->Children.Data.Data;
  List = this->List;
  Size = List->List.Data.Size;
  p_List = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&List->List;
  v6 = &Data[ind];
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    p_List,
    p_List,
    Size + 1);
  v7 = p_List->Size;
  if ( &p_List->Data[v7] == (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *)4 )
    return 1;
  pObject = (Scaleform::GFx::AS3::ClassTraits::Traits *)v6->pObject;
  p_List->Data[v7 - 1].pObject = (Scaleform::GFx::AS3::ClassTraits::Traits *)v6->pObject;
  result = 1;
  if ( pObject )
    pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
  return result;
}
