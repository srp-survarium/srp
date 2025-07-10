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
  Scaleform::Render::BundleEntryRange chain; // [esp+4h] [ebp-Ch] BYREF

  if ( this->IsPatternChainValid(this) )
  {
    chain.pFirst = 0;
    chain.pLast = 0;
    chain.Length = 0x80000000;
    Scaleform::Render::TreeCacheContainer::BuildChildPattern(this, &chain, flags);
    Length = chain.Length;
    pLast = chain.pLast;
    pFirst = chain.pFirst;
    if ( this->Effects.pEffect && chain.pFirst )
      Scaleform::Render::TreeCacheNode::updateEffectChain(this, &chain);
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
            if ( pParent->IsPatternChainValid(pParent)
              && ((unsigned int)&vostok::memory::s_CRT_arena[39128632] & this->pParent->UpdateFlags) == 0 )
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
            Scaleform::Render::TreeCacheRoot::AddToDepthUpdate(
              pRoot,
              v9,
              (unsigned int)&vostok::memory::s_CRT_arena[5574200]);
        }
      }
    }
    this->CachedChildPattern.pFirst = pFirst;
    this->CachedChildPattern.pLast = pLast;
    this->CachedChildPattern.Length = Length;
  }
}
