void __thiscall Scaleform::Render::CacheEffectChain::updateBundleChain(
        Scaleform::Render::CacheEffectChain *this,
        Scaleform::Render::CacheEffect *effect,
        Scaleform::Render::BundleEntryRange *chain,
        Scaleform::Render::BundleEntryRange *maskChain)
{
  Scaleform::Render::CacheEffect *pNext; // eax

  pNext = effect->pNext;
  if ( pNext )
    Scaleform::Render::CacheEffectChain::updateBundleChain(this, pNext, chain, maskChain);
  effect->ChainNext(effect, chain, maskChain);
}
