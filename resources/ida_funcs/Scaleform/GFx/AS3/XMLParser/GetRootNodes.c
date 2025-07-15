void __thiscall Scaleform::GFx::AS3::XMLParser::GetRootNodes(
        Scaleform::GFx::AS3::XMLParser *this,
        Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2,Scaleform::ArrayDefaultPolicy> *nodes)
{
  unsigned int v2; // ebp
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v3; // ebx
  unsigned int Size; // eax
  unsigned int v5; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v6; // ecx
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // eax
  Scaleform::GFx::AS3::XMLParser *i; // [esp+4h] [ebp-4h]

  v2 = 0;
  for ( i = this; v2 < i->RootElements.Data.Size; ++v2 )
  {
    v3 = &this->RootElements.Data.Data[v2];
    Size = nodes->Data.Size;
    v5 = Size + 1;
    if ( Size + 1 >= Size )
    {
      if ( v5 >= nodes->Data.Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)nodes,
          nodes,
          v5 + (v5 >> 2));
    }
    else
    {
      Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *)&nodes->Data.Data[Size + 1],
        0xFFFFFFFF);
      if ( v5 < nodes->Data.Policy.Capacity >> 1 )
        Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)nodes,
          nodes,
          v5);
    }
    v6 = &nodes->Data.Data[v5 - 1];
    nodes->Data.Size = v5;
    if ( v6 )
    {
      pObject = v3->pObject;
      v6->pObject = v3->pObject;
      if ( pObject )
        pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
    }
    this = i;
  }
}
