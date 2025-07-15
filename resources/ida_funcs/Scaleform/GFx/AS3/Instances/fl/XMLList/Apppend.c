void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::Apppend(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::GFx::AS3::Instances::fl::XMLList *v)
{
  unsigned int v2; // ebx
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *p_List; // edi
  unsigned int v4; // eax
  unsigned int v5; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v6; // ebp
  _DWORD *p_pObject; // ecx
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // eax
  unsigned int size; // [esp+4h] [ebp-4h]

  v2 = 0;
  size = v->List.Data.Size;
  if ( size )
  {
    p_List = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&this->List;
    do
    {
      v4 = p_List->Size;
      v5 = v4 + 1;
      v6 = &v->List.Data.Data[v2];
      if ( v4 + 1 >= v4 )
      {
        if ( v5 >= p_List->Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            p_List,
            p_List,
            v5 + (v5 >> 2));
      }
      else
      {
        Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *)&p_List->Data[v4 + 1],
          0xFFFFFFFF);
        if ( v5 < p_List->Policy.Capacity >> 1 )
          Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            p_List,
            p_List,
            v5);
      }
      p_pObject = &p_List->Data[v5 - 1].pObject;
      p_List->Size = v5;
      if ( p_pObject )
      {
        pObject = v6->pObject;
        *p_pObject = v6->pObject;
        if ( pObject )
          pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
      }
      ++v2;
    }
    while ( v2 < size );
  }
}


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
