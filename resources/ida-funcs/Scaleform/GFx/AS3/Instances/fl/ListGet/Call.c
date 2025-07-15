void __thiscall Scaleform::GFx::AS3::Instances::fl::ListGet::Call(
        Scaleform::GFx::AS3::Instances::fl::ListGet *this,
        unsigned int li,
        unsigned int ii)
{
  Scaleform::GFx::AS3::ClassTraits::Traits *v3; // ebx
  Scaleform::GFx::AS3::Instances::fl::XMLList *NewList; // esi
  unsigned int Size; // ecx
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *p_List; // esi
  unsigned int RefCount; // eax

  v3 = (Scaleform::GFx::AS3::ClassTraits::Traits *)*((_DWORD *)&this->List->List.Data.Data[li].pObject[1].pUserDataHolder->pMovieView
                                                   + ii);
  if ( v3 )
    v3->RefCount = (v3->RefCount + 1) & 0x8FBFFFFF;
  NewList = this->NewList;
  Size = NewList->List.Data.Size;
  p_List = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&NewList->List;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    p_List,
    p_List,
    Size + 1);
  if ( &p_List->Data[p_List->Size] != (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *)4 )
  {
    p_List->Data[p_List->Size - 1].pObject = v3;
    if ( !v3 )
      return;
    v3->RefCount = (v3->RefCount + 1) & 0x8FBFFFFF;
  }
  if ( v3 && ((unsigned __int8)v3 & 1) == 0 )
  {
    RefCount = v3->RefCount;
    if ( (RefCount & 0x3FFFFF) != 0 )
    {
      v3->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v3);
    }
  }
}
