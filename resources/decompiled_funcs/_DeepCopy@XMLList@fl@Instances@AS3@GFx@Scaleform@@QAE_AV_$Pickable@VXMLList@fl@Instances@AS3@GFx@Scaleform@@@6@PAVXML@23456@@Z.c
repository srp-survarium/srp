Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *__thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::DeepCopy(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *result,
        Scaleform::GFx::AS3::Instances::fl::XML *parent)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *v3; // edi
  Scaleform::GFx::AS3::Instances::fl::XMLList *v4; // esi
  int v5; // ebp
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // ecx
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v7; // eax
  Scaleform::GFx::AS3::Instances::fl::XMLList *pV; // esi
  unsigned int v9; // edi
  Scaleform::GFx::AS3::ClassTraits::Traits *v10; // ebx
  unsigned int v11; // eax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *p_List; // esi
  unsigned int v13; // edi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *Data; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *v15; // edi
  unsigned int RefCount; // eax
  unsigned int size; // [esp+10h] [ebp-8h]
  int v20; // [esp+14h] [ebp-4h] BYREF

  v3 = result;
  v4 = this;
  Scaleform::GFx::AS3::Instances::fl::XMLList::MakeInstance(this, result);
  v5 = 0;
  size = v4->List.Data.Size;
  if ( size )
  {
    while ( 1 )
    {
      pObject = v4->List.Data.Data[v5].pObject;
      v7 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)pObject->DeepCopy(
                                                          pObject,
                                                          (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *)&v20,
                                                          parent);
      pV = v3->pV;
      v9 = v3->pV->List.Data.Size;
      v10 = (Scaleform::GFx::AS3::ClassTraits::Traits *)*v7;
      v11 = v9;
      p_List = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&pV->List;
      v13 = v9 + 1;
      if ( v13 >= v11 )
      {
        if ( v13 >= p_List->Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            p_List,
            p_List,
            v13 + (v13 >> 2));
      }
      else
      {
        Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *)&p_List->Data[v13],
          v11 - v13);
        if ( v13 < p_List->Policy.Capacity >> 1 )
          Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            p_List,
            p_List,
            v13);
      }
      Data = p_List->Data;
      p_List->Size = v13;
      v15 = &Data[v13 - 1];
      if ( v15 )
      {
        v15->pObject = v10;
        if ( !v10 )
          goto LABEL_16;
        v10->RefCount = (v10->RefCount + 1) & 0x8FBFFFFF;
      }
      if ( v10 && ((unsigned __int8)v10 & 1) == 0 )
      {
        RefCount = v10->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
        {
          v10->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v10);
        }
      }
LABEL_16:
      if ( ++v5 >= size )
        return result;
      v4 = this;
      v3 = result;
    }
  }
  return result;
}
