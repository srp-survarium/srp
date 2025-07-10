void __thiscall Scaleform::GFx::XML::ElementNode::RemoveChild(
        Scaleform::GFx::XML::ElementNode *this,
        Scaleform::GFx::XML::Node *xmlNode)
{
  Scaleform::GFx::XML::Node *pObject; // eax
  Scaleform::GFx::XML::Node *v4; // ecx
  Scaleform::GFx::XML::Node *v5; // eax
  Scaleform::GFx::XML::Node *PrevSibling; // edi
  Scaleform::GFx::XML::Node *v7; // eax
  Scaleform::RefCountNTSImpl *v8; // ecx
  Scaleform::GFx::XML::Node *v9; // ecx

  if ( xmlNode )
    ++xmlNode->RefCount;
  if ( xmlNode == this->FirstChild.pObject )
  {
    pObject = xmlNode->NextSibling.pObject;
    if ( pObject )
      ++pObject->RefCount;
    v4 = this->FirstChild.pObject;
    if ( v4 )
      Scaleform::RefCountNTSImpl::Release(v4);
    this->FirstChild.pObject = xmlNode->NextSibling.pObject;
  }
  if ( xmlNode == this->LastChild )
    this->LastChild = xmlNode->PrevSibling;
  v5 = xmlNode->NextSibling.pObject;
  if ( v5 )
    v5->PrevSibling = xmlNode->PrevSibling;
  PrevSibling = xmlNode->PrevSibling;
  if ( PrevSibling )
  {
    v7 = xmlNode->NextSibling.pObject;
    if ( v7 )
      ++v7->RefCount;
    v8 = PrevSibling->NextSibling.pObject;
    if ( v8 )
      Scaleform::RefCountNTSImpl::Release(v8);
    PrevSibling->NextSibling.pObject = xmlNode->NextSibling.pObject;
  }
  xmlNode->Parent = 0;
  v9 = xmlNode->NextSibling.pObject;
  if ( v9 )
    Scaleform::RefCountNTSImpl::Release(v9);
  xmlNode->NextSibling.pObject = 0;
  xmlNode->PrevSibling = 0;
  Scaleform::RefCountNTSImpl::Release(xmlNode);
}
