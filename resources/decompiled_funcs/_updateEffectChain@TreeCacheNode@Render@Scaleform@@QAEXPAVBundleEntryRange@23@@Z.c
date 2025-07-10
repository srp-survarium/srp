void __thiscall Scaleform::Render::TreeCacheNode::updateEffectChain(
        Scaleform::Render::TreeCacheNode *this,
        Scaleform::Render::BundleEntryRange *contentChain)
{
  Scaleform::Render::TreeCacheNode *pMask; // ecx
  Scaleform::Render::CacheEffect *pEffect; // eax
  Scaleform::Render::CacheEffect *v5; // eax
  Scaleform::Render::BundleEntryRange maskPattern; // [esp+8h] [ebp-Ch] BYREF

  pMask = this->pMask;
  if ( pMask )
  {
    memset(&maskPattern, 0, sizeof(maskPattern));
    pMask->GetPatternChain(pMask, &maskPattern, 0);
    pEffect = this->Effects.pEffect;
    if ( pEffect )
      Scaleform::Render::CacheEffectChain::updateBundleChain(&this->Effects, pEffect, contentChain, &maskPattern);
  }
  else
  {
    v5 = this->Effects.pEffect;
    if ( v5 )
      Scaleform::Render::CacheEffectChain::updateBundleChain(&this->Effects, v5, contentChain, 0);
  }
}
