bool __thiscall Scaleform::Render::TreeCacheContainer::GetPatternChain(
        Scaleform::Render::TreeCacheContainer *this,
        Scaleform::Render::BundleEntryRange *range,
        unsigned int flags)
{
  unsigned int v5; // ebx
  Scaleform::Render::CacheEffect *pEffect; // ecx
  Scaleform::Render::BundleEntryRange *p_CachedChildPattern; // edi

  if ( (this->Flags & 3) != 1 )
  {
    range->pLast = 0;
    range->pFirst = 0;
    range->Length = 0;
    return 0;
  }
  v5 = (unsigned int)sub_7E0000 & this->UpdateFlags;
  if ( this->CachedChildPattern.Length == 0x80000000 )
  {
    p_CachedChildPattern = &this->CachedChildPattern;
    Scaleform::Render::TreeCacheContainer::BuildChildPattern(this, &this->CachedChildPattern, flags);
    goto LABEL_12;
  }
  if ( v5 )
  {
    p_CachedChildPattern = &this->CachedChildPattern;
    Scaleform::Render::BundleEntryRange::StripChainsByDepth(&this->CachedChildPattern, this->Depth);
LABEL_12:
    *range = *p_CachedChildPattern;
    if ( v5 )
    {
      Scaleform::Render::CacheEffectChain::UpdateEffects(&this->Effects, this, v5);
      this->UpdateFlags &= 0xFF81FFFF;
    }
    if ( p_CachedChildPattern->pFirst )
      Scaleform::Render::TreeCacheNode::updateEffectChain(this, range);
    return (range->Length & 0x7FFFFFFF) != 0;
  }
  if ( this->CachedChildPattern.pFirst )
  {
    pEffect = this->Effects.pEffect;
    if ( pEffect )
      pEffect->GetRange(pEffect, range);
    else
      *range = this->CachedChildPattern;
    Scaleform::Render::BundleEntryRange::StripChainsByDepth(range, this->Depth);
  }
  return (range->Length & 0x7FFFFFFF) != 0;
}
