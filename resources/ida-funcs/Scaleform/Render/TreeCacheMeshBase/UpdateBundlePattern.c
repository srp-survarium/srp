void __thiscall Scaleform::Render::TreeCacheMeshBase::UpdateBundlePattern(
        Scaleform::Render::TreeCacheMeshBase *this,
        unsigned int __formal)
{
  Scaleform::Render::BundleEntryRange contentChain; // [esp+0h] [ebp-Ch] BYREF

  if ( this->pMask )
  {
    if ( this->Effects.pEffect )
    {
      contentChain.pLast = &this->SorterShapeNode;
      contentChain.pFirst = &this->SorterShapeNode;
      contentChain.Length = 1;
      Scaleform::Render::TreeCacheNode::updateEffectChain(this, &contentChain);
    }
  }
}
