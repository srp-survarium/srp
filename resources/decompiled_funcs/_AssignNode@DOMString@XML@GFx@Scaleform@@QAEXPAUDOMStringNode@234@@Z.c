void __thiscall Scaleform::GFx::XML::DOMString::AssignNode(
        Scaleform::GFx::XML::DOMString *this,
        Scaleform::GFx::XML::DOMStringNode *pnode)
{
  Scaleform::GFx::XML::DOMStringNode *v2; // ebx
  Scaleform::GFx::XML::DOMStringNode *v4; // esi
  Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *> > > *p_StringSet; // ecx

  v2 = pnode;
  ++pnode->RefCount;
  v4 = this->pNode;
  if ( this->pNode->RefCount-- == 1 )
  {
    p_StringSet = &v4->pManager->StringSet;
    pnode = v4;
    Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>>>::RemoveAlt<Scaleform::GFx::XML::DOMStringNode *>(
      p_StringSet,
      &pnode);
    Scaleform::GFx::XML::DOMStringManager::FreeStringNode(v4->pManager, v4);
  }
  this->pNode = v2;
}
