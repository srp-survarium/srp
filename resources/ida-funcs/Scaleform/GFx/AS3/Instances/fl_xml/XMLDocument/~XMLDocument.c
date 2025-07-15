void __thiscall Scaleform::GFx::AS3::Instances::fl_xml::XMLDocument::~XMLDocument(
        Scaleform::GFx::AS3::Instances::fl_xml::XMLDocument *this)
{
  Scaleform::GFx::AS3::Instances::fl::Object *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Instances::fl::Object *v4; // ecx
  unsigned int v5; // eax
  Scaleform::GFx::AS3::Instances::fl::Object *v6; // ecx
  unsigned int v7; // eax

  pObject = this->xmlDecl.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->xmlDecl.pObject = (Scaleform::GFx::AS3::Instances::fl::Object *)((char *)pObject - 1);
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  v4 = this->idMap.pObject;
  if ( v4 )
  {
    if ( ((unsigned __int8)v4 & 1) != 0 )
    {
      this->idMap.pObject = (Scaleform::GFx::AS3::Instances::fl::Object *)((char *)v4 - 1);
    }
    else
    {
      v5 = v4->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & v5) != 0 )
      {
        v4->RefCount = v5 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v4);
      }
    }
  }
  v6 = this->docTypeDecl.pObject;
  if ( v6 )
  {
    if ( ((unsigned __int8)v6 & 1) != 0 )
    {
      this->docTypeDecl.pObject = (Scaleform::GFx::AS3::Instances::fl::Object *)((char *)v6 - 1);
      Scaleform::GFx::AS3::Instances::fl_xml::XMLNode::~XMLNode(this);
      return;
    }
    v7 = v6->RefCount;
    if ( ((unsigned int)&byte_3FFFFF & v7) != 0 )
    {
      v6->RefCount = v7 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v6);
    }
  }
  Scaleform::GFx::AS3::Instances::fl_xml::XMLNode::~XMLNode(this);
}
