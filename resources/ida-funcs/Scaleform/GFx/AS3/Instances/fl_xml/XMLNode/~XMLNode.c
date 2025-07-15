void __thiscall Scaleform::GFx::AS3::Instances::fl_xml::XMLNode::~XMLNode(
        Scaleform::GFx::AS3::Instances::fl_xml::XMLNode *this)
{
  Scaleform::GFx::AS3::Instances::fl_xml::XMLNode *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Instances::fl_xml::XMLNode *v4; // ecx
  unsigned int v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v7; // zf
  Scaleform::GFx::ASStringNode *v8; // ecx
  Scaleform::GFx::AS3::Instances::fl_xml::XMLNode *v9; // ecx
  unsigned int v10; // eax
  Scaleform::GFx::AS3::Instances::fl_xml::XMLNode *v11; // ecx
  unsigned int v12; // eax
  Scaleform::GFx::AS3::Instances::fl_xml::XMLNode *v13; // ecx
  unsigned int v14; // eax

  pObject = this->previousSibling.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->previousSibling.pObject = (Scaleform::GFx::AS3::Instances::fl_xml::XMLNode *)((char *)pObject - 1);
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
  v4 = this->parentNode.pObject;
  if ( v4 )
  {
    if ( ((unsigned __int8)v4 & 1) != 0 )
    {
      this->parentNode.pObject = (Scaleform::GFx::AS3::Instances::fl_xml::XMLNode *)((char *)v4 - 1);
    }
    else
    {
      v5 = v4->RefCount;
      if ( (v5 & 0x3FFFFF) != 0 )
      {
        v4->RefCount = v5 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v4);
      }
    }
  }
  pNode = this->nodeValue.pNode;
  v7 = pNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v8 = this->nodeName.pNode;
  v7 = v8->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  v9 = this->nextSibling.pObject;
  if ( v9 )
  {
    if ( ((unsigned __int8)v9 & 1) != 0 )
    {
      this->nextSibling.pObject = (Scaleform::GFx::AS3::Instances::fl_xml::XMLNode *)((char *)v9 - 1);
    }
    else
    {
      v10 = v9->RefCount;
      if ( (v10 & 0x3FFFFF) != 0 )
      {
        v9->RefCount = v10 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v9);
      }
    }
  }
  v11 = this->lastChild.pObject;
  if ( v11 )
  {
    if ( ((unsigned __int8)v11 & 1) != 0 )
    {
      this->lastChild.pObject = (Scaleform::GFx::AS3::Instances::fl_xml::XMLNode *)((char *)v11 - 1);
    }
    else
    {
      v12 = v11->RefCount;
      if ( (v12 & 0x3FFFFF) != 0 )
      {
        v11->RefCount = v12 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v11);
      }
    }
  }
  v13 = this->firstChild.pObject;
  if ( v13 )
  {
    if ( ((unsigned __int8)v13 & 1) != 0 )
    {
      this->firstChild.pObject = (Scaleform::GFx::AS3::Instances::fl_xml::XMLNode *)((char *)v13 - 1);
      Scaleform::GFx::AS3::Instance::~Instance(this);
      return;
    }
    v14 = v13->RefCount;
    if ( (v14 & 0x3FFFFF) != 0 )
    {
      v13->RefCount = v14 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v13);
    }
  }
  Scaleform::GFx::AS3::Instance::~Instance(this);
}
