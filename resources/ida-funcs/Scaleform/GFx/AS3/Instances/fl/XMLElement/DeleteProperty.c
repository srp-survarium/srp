Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Instances::fl::XMLElement::DeleteProperty(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::SoundObject *prop_name)
{
  unsigned int v4; // edi
  Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2,Scaleform::ArrayDefaultPolicy> *p_Attrs; // ebx
  Scaleform::GFx::AS3::Instances::fl::XML *v6; // esi
  Scaleform::GFx::AS3::Instances::fl::XML *v7; // ecx
  unsigned int v8; // eax
  Scaleform::GFx::AS3::CheckResult *v9; // eax
  Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2,Scaleform::ArrayDefaultPolicy> *p_Children; // ebx
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // esi
  Scaleform::GFx::AS3::Instances::fl::XML *v12; // ecx
  unsigned int RefCount; // eax

  v4 = 0;
  if ( ((int)prop_name->Scaleform::RefCountBase<Scaleform::GFx::AS3::SoundObject,323>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,323>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable
      & 8) == 0 )
  {
    if ( !this->Children.Data.Size )
      goto LABEL_27;
    p_Children = &this->Children;
    while ( 1 )
    {
      pObject = p_Children->Data.Data[v4].pObject;
      if ( !Scaleform::GFx::AS3::Instances::fl::XML::Matches(pObject, prop_name) )
      {
        ++v4;
        goto LABEL_26;
      }
      v12 = pObject->Parent.pObject;
      if ( !v12 )
        goto LABEL_24;
      if ( ((unsigned __int8)v12 & 1) == 0 )
        break;
      pObject->Parent.pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)v12 - 1);
      pObject->Parent.pObject = 0;
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
        (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> > *)&this->Children,
        v4);
LABEL_26:
      if ( v4 >= this->Children.Data.Size )
        goto LABEL_27;
    }
    RefCount = v12->RefCount;
    if ( (RefCount & 0x3FFFFF) != 0 )
    {
      v12->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v12);
    }
    pObject->Parent.pObject = 0;
LABEL_24:
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
      (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> > *)&this->Children,
      v4);
    goto LABEL_26;
  }
  if ( this->Attrs.Data.Size )
  {
    p_Attrs = &this->Attrs;
    while ( 1 )
    {
      v6 = p_Attrs->Data.Data[v4].pObject;
      if ( !Scaleform::GFx::AS3::Instances::fl::XML::Matches(v6, prop_name) )
      {
        ++v4;
        goto LABEL_13;
      }
      v7 = v6->Parent.pObject;
      if ( !v7 )
        goto LABEL_11;
      if ( ((unsigned __int8)v7 & 1) == 0 )
        break;
      v6->Parent.pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)v7 - 1);
      v6->Parent.pObject = 0;
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
        &this->Attrs,
        v4);
LABEL_13:
      if ( v4 >= this->Attrs.Data.Size )
      {
        v9 = result;
        result->Result = 1;
        return v9;
      }
    }
    v8 = v7->RefCount;
    if ( (v8 & 0x3FFFFF) != 0 )
    {
      v7->RefCount = v8 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v7);
    }
    v6->Parent.pObject = 0;
LABEL_11:
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
      &this->Attrs,
      v4);
    goto LABEL_13;
  }
LABEL_27:
  v9 = result;
  result->Result = 1;
  return v9;
}
