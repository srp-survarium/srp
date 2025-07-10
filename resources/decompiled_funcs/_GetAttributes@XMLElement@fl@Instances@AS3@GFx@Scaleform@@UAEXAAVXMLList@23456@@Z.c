void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLElement::GetAttributes(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::Instances::fl::XMLList *list)
{
  int v2; // ebp
  Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2,Scaleform::ArrayDefaultPolicy> *p_List; // edi
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *pObject; // ebx
  unsigned int v5; // eax
  unsigned int v6; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *Data; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v8; // esi
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v10; // [esp+4h] [ebp-8h]
  unsigned int size; // [esp+8h] [ebp-4h]

  v2 = 0;
  v10 = this;
  size = this->Attrs.Data.Size;
  if ( size )
  {
    p_List = &list->List;
    while ( 1 )
    {
      pObject = this->Attrs.Data.Data[v2].pObject;
      if ( pObject )
        pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
      v5 = list->List.Data.Size;
      v6 = v5 + 1;
      if ( v5 + 1 >= v5 )
      {
        if ( v6 >= list->List.Data.Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)p_List,
            p_List,
            v6 + (v6 >> 2));
      }
      else
      {
        Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *)&p_List->Data.Data[v5 + 1],
          0xFFFFFFFF);
        if ( v6 < list->List.Data.Policy.Capacity >> 1 )
          Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)p_List,
            p_List,
            v6);
      }
      Data = p_List->Data.Data;
      list->List.Data.Size = v6;
      v8 = &Data[v6 - 1];
      if ( v8 )
      {
        v8->pObject = pObject;
        if ( !pObject )
          goto LABEL_18;
        pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
      }
      if ( pObject && ((unsigned __int8)pObject & 1) == 0 )
      {
        RefCount = pObject->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
LABEL_18:
      if ( ++v2 >= size )
        return;
      this = v10;
    }
  }
}
