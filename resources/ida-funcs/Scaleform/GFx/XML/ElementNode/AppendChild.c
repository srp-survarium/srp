void __thiscall Scaleform::GFx::XML::ElementNode::AppendChild(
        Scaleform::GFx::XML::ElementNode *this,
        Scaleform::GFx::XML::Node *xmlNode)
{
  Scaleform::GFx::XML::Node *LastChild; // eax
  Scaleform::GFx::XML::Node *v4; // ecx
  Scaleform::GFx::XML::Node *v5; // edi
  Scaleform::RefCountNTSImpl *pObject; // ecx
  Scaleform::Ptr<Scaleform::GFx::XML::Node> *p_NextSibling; // edi

  LastChild = this->LastChild;
  if ( LastChild )
  {
    xmlNode->PrevSibling = LastChild;
    v5 = this->LastChild;
    ++xmlNode->RefCount;
    pObject = v5->NextSibling.pObject;
    p_NextSibling = &v5->NextSibling;
    if ( pObject )
      Scaleform::RefCountNTSImpl::Release(pObject);
    p_NextSibling->pObject = xmlNode;
    this->LastChild = xmlNode;
    xmlNode->Parent = this;
  }
  else
  {
    if ( xmlNode )
      ++xmlNode->RefCount;
    v4 = this->FirstChild.pObject;
    if ( v4 )
      Scaleform::RefCountNTSImpl::Release(v4);
    this->FirstChild.pObject = xmlNode;
    this->LastChild = xmlNode;
    xmlNode->Parent = this;
  }
}
