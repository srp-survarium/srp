void __thiscall Scaleform::Render::TreeCacheMeshBase::UpdateBundlePattern(
        Scaleform::Render::TreeCacheMeshBase *this,
        unsigned int __formal)
{
  Scaleform::Render::BundleEntryRange chain; // [esp+0h] [ebp-Ch] BYREF

  if ( this->pMask )
  {
    if ( this->Effects.pEffect )
    {
      chain.pLast = &this->SorterShapeNode;
      chain.pFirst = &this->SorterShapeNode;
      chain.Length = 1;
      Scaleform::Render::TreeCacheNode::updateEffectChain(this, &chain);
    }
  }
}
