void __thiscall Scaleform::GFx::ASString::Append(Scaleform::GFx::ASString *this, Scaleform::GFx::ASStringNode *str)
{
  Scaleform::GFx::ASStringNode *StringNode; // ebx
  Scaleform::GFx::ASStringNode *pNode; // esi
  Scaleform::GFx::ASStringNode *pLower; // ecx
  Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *> > > *p_StringSet; // ecx

  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 this->pNode->pManager,
                 (char *)this->pNode->pData,
                 this->pNode->Size,
                 *(char **)str->pData,
                 *((Scaleform::GFx::ASStringNode **)str->pData + 5));
  ++StringNode->RefCount;
  pNode = this->pNode;
  if ( this->pNode->RefCount-- == 1 )
  {
    pLower = pNode->pLower;
    if ( pLower != pNode && pLower )
      Scaleform::GFx::ASStringNode::Release(pLower);
    p_StringSet = &pNode->pManager->StringSet;
    str = pNode;
    Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>>>::RemoveAlt<Scaleform::GFx::ASStringNode *>(
      p_StringSet,
      &str);
    Scaleform::GFx::ASStringManager::FreeStringNode(pNode->pManager, pNode);
  }
  this->pNode = StringNode;
}


void __thiscall Scaleform::GFx::ASString::Append(
        Scaleform::GFx::ASString *this,
        char *str,
        Scaleform::GFx::ASStringNode *len)
{
  Scaleform::GFx::ASStringNode *StringNode; // ebx
  Scaleform::GFx::ASStringNode *pNode; // esi
  Scaleform::GFx::ASStringNode *pLower; // ecx
  Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *> > > *p_StringSet; // ecx

  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 this->pNode->pManager,
                 (char *)this->pNode->pData,
                 this->pNode->Size,
                 str,
                 len);
  ++StringNode->RefCount;
  pNode = this->pNode;
  if ( this->pNode->RefCount-- == 1 )
  {
    pLower = pNode->pLower;
    if ( pLower != pNode && pLower )
      Scaleform::GFx::ASStringNode::Release(pLower);
    p_StringSet = &pNode->pManager->StringSet;
    len = pNode;
    Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>>>::RemoveAlt<Scaleform::GFx::ASStringNode *>(
      p_StringSet,
      &len);
    Scaleform::GFx::ASStringManager::FreeStringNode(pNode->pManager, pNode);
  }
  this->pNode = StringNode;
}
