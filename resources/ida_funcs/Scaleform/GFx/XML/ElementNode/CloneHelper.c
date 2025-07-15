void __thiscall Scaleform::GFx::XML::ElementNode::CloneHelper(
        Scaleform::GFx::XML::ElementNode *this,
        Scaleform::GFx::XML::ElementNode *clone,
        BOOL deep)
{
  Scaleform::GFx::XML::DOMStringNode *LastAttribute; // ecx
  Scaleform::GFx::XML::Attribute *i; // esi
  Scaleform::GFx::XML::ObjectManager *pObject; // ebx
  Scaleform::GFx::XML::DOMStringNode *v7; // ecx
  Scaleform::GFx::XML::Attribute *Attribute; // eax
  Scaleform::GFx::XML::Node *j; // ebx
  Scaleform::GFx::XML::Node *v10; // esi
  Scaleform::GFx::XML::Node *LastChild; // eax
  Scaleform::GFx::XML::Node *v12; // ecx
  Scaleform::GFx::XML::Node *v13; // ebp
  Scaleform::RefCountNTSImpl *v14; // ecx
  Scaleform::Ptr<Scaleform::GFx::XML::Node> *p_NextSibling; // ebp
  Scaleform::GFx::XML::DOMString v16; // [esp-8h] [ebp-18h] BYREF
  Scaleform::GFx::XML::DOMString v17; // [esp-4h] [ebp-14h] BYREF

  Scaleform::GFx::XML::DOMString::AssignNode(&clone->Prefix, this->Prefix.pNode);
  for ( i = this->FirstAttribute; i; i = i->Next )
  {
    pObject = this->MemoryManager.pObject;
    v17.pNode = LastAttribute;
    Scaleform::GFx::XML::DOMString::DOMString(&v17, &i->Value);
    v16.pNode = v7;
    Scaleform::GFx::XML::DOMString::DOMString(&v16, &i->Name);
    Attribute = Scaleform::GFx::XML::ObjectManager::CreateAttribute(pObject, v16, v17);
    if ( clone->FirstAttribute )
    {
      LastAttribute = (Scaleform::GFx::XML::DOMStringNode *)clone->LastAttribute;
      LastAttribute->HashFlags = (unsigned int)Attribute;
    }
    else
    {
      clone->FirstAttribute = Attribute;
    }
    clone->LastAttribute = Attribute;
  }
  if ( deep )
  {
    for ( j = this->FirstChild.pObject; j; j = j->NextSibling.pObject )
    {
      v10 = j->Clone(j, deep);
      LastChild = clone->LastChild;
      if ( LastChild )
      {
        v10->PrevSibling = LastChild;
        v13 = clone->LastChild;
        ++v10->RefCount;
        v14 = v13->NextSibling.pObject;
        p_NextSibling = &v13->NextSibling;
        if ( v14 )
          Scaleform::RefCountNTSImpl::Release(v14);
        p_NextSibling->pObject = v10;
      }
      else
      {
        if ( v10 )
          ++v10->RefCount;
        v12 = clone->FirstChild.pObject;
        if ( v12 )
          Scaleform::RefCountNTSImpl::Release(v12);
        clone->FirstChild.pObject = v10;
      }
      clone->LastChild = v10;
      v10->Parent = clone;
      Scaleform::RefCountNTSImpl::Release(v10);
    }
  }
}
