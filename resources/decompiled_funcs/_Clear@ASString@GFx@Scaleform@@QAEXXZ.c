void __thiscall Scaleform::GFx::ASString::Clear(Scaleform::GFx::ASString *this)
{
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // esi
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // edi
  Scaleform::GFx::ASStringNode *pLower; // ecx
  Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *> > > *p_StringSet; // ecx
  Scaleform::GFx::ASStringNode *key; // [esp+Ch] [ebp-4h] BYREF

  pManager = this->pNode->pManager;
  ++pManager->EmptyStringNode.RefCount;
  pNode = this->pNode;
  p_EmptyStringNode = &pManager->EmptyStringNode;
  if ( this->pNode->RefCount-- == 1 )
  {
    pLower = pNode->pLower;
    if ( pLower != pNode && pLower )
      Scaleform::GFx::ASStringNode::Release(pLower);
    p_StringSet = &pNode->pManager->StringSet;
    key = pNode;
    Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>>>::RemoveAlt<Scaleform::GFx::ASStringNode *>(
      p_StringSet,
      &key);
    Scaleform::GFx::ASStringManager::FreeStringNode(pNode->pManager, pNode);
  }
  this->pNode = p_EmptyStringNode;
}
