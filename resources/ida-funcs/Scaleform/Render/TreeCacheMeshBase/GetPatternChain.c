char __thiscall Scaleform::Render::TreeCacheMeshBase::GetPatternChain(
        Scaleform::Render::TreeCacheMeshBase *this,
        Scaleform::Render::BundleEntryRange *range,
        unsigned int __formal)
{
  Scaleform::Render::CacheEffectChain *p_Effects; // ecx
  Scaleform::Render::Bundle *pObject; // eax
  unsigned int Depth; // ecx
  Scaleform::Render::CacheEffectChain v8; // ecx

  if ( (this->Flags & 3) == 1 )
  {
    range->pLast = &this->SorterShapeNode;
    range->pFirst = &this->SorterShapeNode;
    range->Length = 1;
    p_Effects = &this->Effects;
    this->SorterShapeNode.Removed = 0;
    if ( this->Effects.pEffect
      || ((unsigned int)&Scaleform::Render::D3D1x::pBinary_D3D1xFL1x_FBox2FullShadowHighlight[1376] & this->UpdateFlags) != 0 )
    {
      if ( ((unsigned int)&Scaleform::Render::D3D1x::pBinary_D3D1xFL1x_FBox2FullShadowHighlight[1376] & this->UpdateFlags) != 0 )
      {
        Scaleform::Render::CacheEffectChain::UpdateEffects(
          p_Effects,
          this,
          (unsigned int)&Scaleform::Render::D3D1x::pBinary_D3D1xFL1x_FBox2FullShadowHighlight[1376] & this->UpdateFlags);
        Scaleform::Render::TreeCacheNode::updateEffectChain(this, range);
        Depth = this->Depth;
        this->UpdateFlags &= 0xFF81FFFF;
        Scaleform::Render::BundleEntryRange::StripChainsByDepth(range, Depth);
        return 1;
      }
      else
      {
        v8.pEffect = p_Effects->pEffect;
        if ( v8.pEffect )
          ((void (__thiscall *)(Scaleform::Render::CacheEffectChain, Scaleform::Render::BundleEntryRange *))v8.pEffect->GetRange)(
            v8,
            range);
        Scaleform::Render::BundleEntryRange::StripChainsByDepth(range, this->Depth);
        return 1;
      }
    }
    else
    {
      pObject = this->SorterShapeNode.pBundle.pObject;
      if ( pObject )
        pObject->NeedUpdate = 1;
      this->SorterShapeNode.pChain = 0;
      this->SorterShapeNode.ChainHeight = 0;
      return 1;
    }
  }
  else
  {
    range->pLast = 0;
    range->pFirst = 0;
    range->Length = 0;
    return 0;
  }
}
