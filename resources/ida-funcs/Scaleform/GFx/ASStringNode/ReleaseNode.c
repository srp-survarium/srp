void __thiscall Scaleform::GFx::ASStringNode::ReleaseNode(Scaleform::GFx::ASStringNode *this)
{
  Scaleform::GFx::ASStringNode *pLower; // ecx
  Scaleform::HashSetUncachedLH<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,324> *p_StringSet; // ecx
  Scaleform::GFx::ASStringNode *key; // [esp+4h] [ebp-4h] BYREF

  pLower = this->pLower;
  if ( pLower != this )
  {
    if ( pLower )
    {
      if ( pLower->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pLower);
    }
  }
  p_StringSet = &this->pManager->StringSet;
  key = this;
  Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>>>::RemoveAlt<Scaleform::GFx::ASStringNode *>(
    p_StringSet,
    &key);
  Scaleform::GFx::ASStringManager::FreeStringNode(this->pManager, this);
}
