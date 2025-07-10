void __thiscall Scaleform::GFx::FontCompactor::AssignGlyphCode(
        Scaleform::GFx::FontCompactor *this,
        unsigned int glyphIndex,
        unsigned __int16 glyphCode)
{
  unsigned __int16 v3; // di
  Scaleform::HashSet<unsigned short,Scaleform::FixedSizeHash<unsigned short>,Scaleform::FixedSizeHash<unsigned short>,Scaleform::AllocatorGH<unsigned short,2>,Scaleform::HashsetCachedEntry<unsigned short,Scaleform::FixedSizeHash<unsigned short> > > *p_GlyphCodes; // esi
  int v5; // eax

  if ( glyphIndex < this->GlyphInfoTable.Size )
  {
    v3 = glyphCode;
    p_GlyphCodes = &this->GlyphCodes;
    this->GlyphInfoTable.Pages[glyphIndex >> 6][glyphIndex & 0x3F].GlyphCode = glyphCode;
    glyphIndex = v3;
    v5 = Scaleform::HashSetBase<unsigned short,Scaleform::FixedSizeHash<unsigned short>,Scaleform::FixedSizeHash<unsigned short>,Scaleform::AllocatorGH<unsigned short,2>,Scaleform::HashsetCachedEntry<unsigned short,Scaleform::FixedSizeHash<unsigned short>>>::findIndex<unsigned short>(
           &this->GlyphCodes,
           (const unsigned __int16 *)&glyphIndex);
    if ( v5 < 0
      || (Scaleform::HashSetBase<unsigned short,Scaleform::FixedSizeHash<unsigned short>,Scaleform::FixedSizeHash<unsigned short>,Scaleform::AllocatorGH<unsigned short,2>,Scaleform::HashsetCachedEntry<unsigned short,Scaleform::FixedSizeHash<unsigned short> > >::TableType *)((char *)p_GlyphCodes->pTable + 12 * v5) == (Scaleform::HashSetBase<unsigned short,Scaleform::FixedSizeHash<unsigned short>,Scaleform::FixedSizeHash<unsigned short>,Scaleform::AllocatorGH<unsigned short,2>,Scaleform::HashsetCachedEntry<unsigned short,Scaleform::FixedSizeHash<unsigned short> > >::TableType *)-16 )
    {
      glyphIndex = v3;
      Scaleform::HashSet<unsigned short,Scaleform::FixedSizeHash<unsigned short>,Scaleform::FixedSizeHash<unsigned short>,Scaleform::AllocatorGH<unsigned short,2>,Scaleform::HashsetCachedEntry<unsigned short,Scaleform::FixedSizeHash<unsigned short>>>::Add<unsigned short>(
        p_GlyphCodes,
        (const unsigned __int16 *)&glyphIndex);
    }
  }
}
