void __thiscall Scaleform::GFx::XML::ElementNode::InsertBefore(
        Scaleform::GFx::XML::ElementNode *this,
        Scaleform::GFx::XML::Node *child,
        Scaleform::GFx::XML::Node *insert)
{
  Scaleform::GFx::XML::Node *PrevSibling; // ebx
  Scaleform::GFx::XML::Node *pObject; // ecx
  Scaleform::RefCountNTSImpl *v6; // ecx
  Scaleform::GFx::XML::Node *v7; // ecx

  PrevSibling = insert->PrevSibling;
  insert->PrevSibling = child;
  child->PrevSibling = PrevSibling;
  ++insert->RefCount;
  pObject = child->NextSibling.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  child->NextSibling.pObject = insert;
  if ( PrevSibling )
  {
    ++child->RefCount;
    v6 = PrevSibling->NextSibling.pObject;
    if ( v6 )
      Scaleform::RefCountNTSImpl::Release(v6);
    PrevSibling->NextSibling.pObject = child;
  }
  if ( insert == this->FirstChild.pObject )
  {
    ++child->RefCount;
    v7 = this->FirstChild.pObject;
    if ( v7 )
      Scaleform::RefCountNTSImpl::Release(v7);
    this->FirstChild.pObject = child;
  }
  child->Parent = this;
}
