Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *__thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::ShallowCopy(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *result)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *v2; // edi
  Scaleform::GFx::AS3::Instances::fl::XMLList *v3; // esi
  int v4; // ebx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *Data; // eax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *p_List; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v7; // ebp
  unsigned int Size; // eax
  unsigned int v9; // edi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *v10; // ecx
  Scaleform::GFx::AS3::ClassTraits::Traits *pObject; // eax
  unsigned int csize; // [esp+10h] [ebp-4h]

  v2 = result;
  v3 = this;
  Scaleform::GFx::AS3::Instances::fl::XMLList::MakeInstance(this, result);
  v4 = 0;
  csize = v3->List.Data.Size;
  if ( !csize )
    return result;
  while ( 1 )
  {
    Data = v3->List.Data.Data;
    p_List = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&v2->pV->List;
    v7 = &Data[v4];
    Size = v2->pV->List.Data.Size;
    v9 = Size + 1;
    if ( Size + 1 >= Size )
    {
      if ( v9 >= p_List->Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          p_List,
          p_List,
          v9 + (v9 >> 2));
    }
    else
    {
      Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *)&p_List->Data[Size + 1],
        0xFFFFFFFF);
      if ( v9 < p_List->Policy.Capacity >> 1 )
        Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          p_List,
          p_List,
          v9);
    }
    v10 = &p_List->Data[v9 - 1];
    p_List->Size = v9;
    if ( v10 )
    {
      pObject = (Scaleform::GFx::AS3::ClassTraits::Traits *)v7->pObject;
      v10->pObject = (Scaleform::GFx::AS3::ClassTraits::Traits *)v7->pObject;
      if ( pObject )
        pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
    }
    if ( ++v4 >= csize )
      break;
    v2 = result;
    v3 = this;
  }
  return result;
}
