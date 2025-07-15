void __thiscall Scaleform::GFx::AS3::XMLSupportImpl::~XMLSupportImpl(Scaleform::GFx::AS3::XMLSupportImpl *this)
{
  Scaleform::GFx::AS3::ClassTraits::fl::XMLList *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::XML *v4; // ecx
  unsigned int v5; // eax

  this->__vftable = (Scaleform::GFx::AS3::XMLSupportImpl_vtbl *)&Scaleform::GFx::AS3::XMLSupportImpl::`vftable';
  pObject = this->TraitsXMLList.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->TraitsXMLList.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::XMLList *)((char *)pObject - 1);
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  v4 = this->TraitsXML.pObject;
  if ( v4 )
  {
    if ( ((unsigned __int8)v4 & 1) != 0 )
    {
      this->TraitsXML.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::XML *)((char *)v4 - 1);
      this->__vftable = (Scaleform::GFx::AS3::XMLSupportImpl_vtbl *)&Scaleform::GFx::AS3::XMLSupport::`vftable';
      Scaleform::GFx::AS3::GASRefCountBase::~GASRefCountBase(this);
      return;
    }
    v5 = v4->RefCount;
    if ( (v5 & 0x3FFFFF) != 0 )
    {
      v4->RefCount = v5 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v4);
    }
  }
  this->__vftable = (Scaleform::GFx::AS3::XMLSupportImpl_vtbl *)&Scaleform::GFx::AS3::XMLSupport::`vftable';
  Scaleform::GFx::AS3::GASRefCountBase::~GASRefCountBase(this);
}
