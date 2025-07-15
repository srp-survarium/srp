void __thiscall Scaleform::GFx::XML::DOMString::~DOMString(Scaleform::GFx::XML::DOMString *this)
{
  Scaleform::GFx::XML::DOMStringNode *pNode; // esi
  Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *> > > *p_StringSet; // ecx
  Scaleform::GFx::XML::DOMStringNode *key; // [esp+4h] [ebp-4h] BYREF

  pNode = this->pNode;
  if ( this->pNode->RefCount-- == 1 )
  {
    p_StringSet = &pNode->pManager->StringSet;
    key = pNode;
    Scaleform::HashSetBase<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::XML::DOMStringNode *,326>,Scaleform::HashsetEntry<Scaleform::GFx::XML::DOMStringNode *,Scaleform::GFx::XML::DOMStringNodeHashFunc<Scaleform::GFx::XML::DOMStringNode *>>>::RemoveAlt<Scaleform::GFx::XML::DOMStringNode *>(
      p_StringSet,
      &key);
    Scaleform::GFx::XML::DOMStringManager::FreeStringNode(pNode->pManager, pNode);
  }
}
