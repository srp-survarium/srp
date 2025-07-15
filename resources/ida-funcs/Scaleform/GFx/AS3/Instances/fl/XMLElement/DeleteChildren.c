void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLElement::DeleteChildren(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::Instances::fl::XML *child)
{
  unsigned int Size; // ebp
  unsigned int v4; // edi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *Data; // eax
  Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2,Scaleform::ArrayDefaultPolicy> *v6; // ebx
  Scaleform::GFx::AS3::Instances::fl::XML *v7; // esi
  Scaleform::GFx::AS3::Instances::fl::XML *v8; // ecx
  unsigned int v9; // eax
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // esi
  Scaleform::GFx::AS3::Instances::fl::XML *v11; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> **p_Children; // esi

  Size = this->Children.Data.Size;
  v4 = 0;
  if ( !child )
  {
    if ( Size )
    {
      do
      {
        pObject = this->Children.Data.Data[v4].pObject;
        if ( pObject )
        {
          v11 = pObject->Parent.pObject;
          if ( v11 )
          {
            if ( ((unsigned __int8)v11 & 1) != 0 )
            {
              pObject->Parent.pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)v11 - 1);
            }
            else
            {
              RefCount = v11->RefCount;
              if ( (RefCount & 0x3FFFFF) != 0 )
              {
                v11->RefCount = RefCount - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v11);
              }
            }
            pObject->Parent.pObject = 0;
          }
        }
        ++v4;
      }
      while ( v4 < Size );
    }
    p_Children = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> **)&this->Children;
    if ( this->Children.Data.Size )
    {
      Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
        *p_Children,
        this->Children.Data.Size);
      if ( (this->Children.Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
      {
        if ( *p_Children )
        {
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, *p_Children);
          *p_Children = 0;
        }
        this->Children.Data.Policy.Capacity = 0;
        this->Children.Data.Size = 0;
        return;
      }
    }
    else if ( !this->Children.Data.Policy.Capacity )
    {
      Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Children,
        &this->Children,
        0);
    }
    this->Children.Data.Size = 0;
    return;
  }
  if ( !Size )
    return;
  Data = this->Children.Data.Data;
  v6 = &this->Children;
  while ( 1 )
  {
    v7 = Data->pObject;
    if ( Data->pObject == child )
      break;
    ++v4;
    ++Data;
    if ( v4 >= Size )
      return;
  }
  if ( v7 )
  {
    v8 = v7->Parent.pObject;
    if ( v8 )
    {
      if ( ((unsigned __int8)v8 & 1) != 0 )
      {
        v7->Parent.pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)v8 - 1);
        v7->Parent.pObject = 0;
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
          (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> > *)v6,
          v4);
        return;
      }
      v9 = v8->RefCount;
      if ( (v9 & 0x3FFFFF) != 0 )
      {
        v8->RefCount = v9 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v8);
      }
      v7->Parent.pObject = 0;
    }
  }
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
    (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> > *)v6,
    v4);
}
