void __thiscall Scaleform::GFx::ASString::operator=(Scaleform::GFx::ASString *this, char *pstr)
{
  Scaleform::GFx::ASStringNode *StringNode; // edi
  Scaleform::GFx::ASStringNode *pNode; // esi
  Scaleform::GFx::ASStringNode *pLower; // ecx
  Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *> > > *p_StringSet; // ecx

  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(this->pNode->pManager, pstr, strlen(pstr));
  ++StringNode->RefCount;
  pNode = this->pNode;
  if ( this->pNode->RefCount-- == 1 )
  {
    pLower = pNode->pLower;
    if ( pLower != pNode && pLower )
      Scaleform::GFx::ASStringNode::Release(pLower);
    p_StringSet = &pNode->pManager->StringSet;
    pstr = (char *)pNode;
    Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>>>::RemoveAlt<Scaleform::GFx::ASStringNode *>(
      p_StringSet,
      (Scaleform::GFx::ASStringNode *const *)&pstr);
    Scaleform::GFx::ASStringManager::FreeStringNode(pNode->pManager, pNode);
  }
  this->pNode = StringNode;
}
