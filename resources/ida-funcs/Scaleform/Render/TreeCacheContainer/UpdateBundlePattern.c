void __thiscall Scaleform::Render::TreeCacheContainer::UpdateBundlePattern(
        Scaleform::Render::TreeCacheContainer *this,
        unsigned int flags)
{
  unsigned int Length; // edi
  Scaleform::Render::BundleEntry *pLast; // ebp
  Scaleform::Render::BundleEntry *pFirst; // ebx
  unsigned int v6; // ecx
  Scaleform::Render::TreeCacheNode *pParent; // ecx
  Scaleform::Render::TreeCacheRoot *pRoot; // ecx
  Scaleform::Render::TreeCacheNode *v9; // eax
  Scaleform::Render::BundleEntryRange pattern; // [esp+4h] [ebp-Ch] BYREF

  if ( this->IsPatternChainValid(this) )
  {
    pattern.pFirst = 0;
    pattern.pLast = 0;
    pattern.Length = 0x80000000;
    Scaleform::Render::TreeCacheContainer::BuildChildPattern(this, &pattern, flags);
    Length = pattern.Length;
    pLast = pattern.pLast;
    pFirst = pattern.pFirst;
    if ( this->Effects.pEffect && pattern.pFirst )
      Scaleform::Render::TreeCacheNode::updateEffectChain(this, &pattern);
    if ( (this->Flags & 3) == 1 )
    {
      v6 = this->CachedChildPattern.Length & 0x7FFFFFFF;
      if ( v6 > 8
        && (Length & 0x7FFFFFFF) > 8
        && this->CachedChildPattern.pFirst == pFirst
        && this->CachedChildPattern.pLast == pLast )
      {
        if ( v6 != (Length & 0x7FFFFFFF) )
        {
          pParent = this->pParent;
          if ( pParent )
          {
            if ( pParent->IsPatternChainValid(pParent) && (this->pParent->UpdateFlags & 0x3000000) == 0 )
            {
              Scaleform::Render::TreeCacheNode::addParentToDepthPatternUpdate(this);
              this->CachedChildPattern.pFirst = pFirst;
              this->CachedChildPattern.pLast = pLast;
              this->CachedChildPattern.Length = Length;
              return;
            }
          }
        }
      }
      else
      {
        pRoot = this->pRoot;
        if ( pRoot )
        {
          v9 = this->pParent;
          if ( v9 )
            Scaleform::Render::TreeCacheRoot::AddToDepthUpdate(pRoot, v9, 0x1000000u);
        }
      }
    }
    this->CachedChildPattern.pFirst = pFirst;
    this->CachedChildPattern.pLast = pLast;
    this->CachedChildPattern.Length = Length;
  }
}
