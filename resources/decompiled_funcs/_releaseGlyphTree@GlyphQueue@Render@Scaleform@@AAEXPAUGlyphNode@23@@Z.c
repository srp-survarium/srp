void __thiscall Scaleform::Render::GlyphQueue::releaseGlyphTree(
        Scaleform::Render::GlyphQueue *this,
        Scaleform::Render::GlyphNode *glyph)
{
  Scaleform::Render::GlyphNode *v2; // esi

  v2 = glyph;
  if ( glyph )
  {
    Scaleform::Render::GlyphQueue::releaseGlyphTree(this, glyph->pNext);
    Scaleform::Render::GlyphQueue::releaseGlyphTree(this, v2->pNex2);
    if ( v2->Param.pFont )
    {
      glyph = v2;
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::GlyphParamHash,79>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF>>::RemoveAlt<Scaleform::Render::GlyphParamHash>(
        &this->GlyphHTable.mHash,
        (const Scaleform::Render::GlyphParamHash *)&glyph);
    }
    v2->Param.pFont = 0;
    v2->Param.pFont = (Scaleform::Render::FontCacheHandle *)this->Glyphs.FirstEmptySlot;
    this->Glyphs.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,79> >::NodeType *)v2;
  }
}
