void __thiscall Scaleform::GFx::FontCompactor::AddKerningPair(
        Scaleform::GFx::FontCompactor *this,
        unsigned int char1,
        unsigned __int16 char2,
        int adjustment)
{
  __int16 v4; // bp
  Scaleform::HashSet<unsigned short,Scaleform::FixedSizeHash<unsigned short>,Scaleform::FixedSizeHash<unsigned short>,Scaleform::AllocatorGH<unsigned short,2>,Scaleform::HashsetCachedEntry<unsigned short,Scaleform::FixedSizeHash<unsigned short> > > *p_GlyphCodes; // esi
  int v7; // eax
  unsigned __int16 v8; // bx
  int v9; // eax
  Scaleform::ArrayPagedPOD<Scaleform::GFx::FontCompactor::KerningPairType,6,64,261> *p_KerningTable; // esi
  unsigned int v11; // edi
  int v12; // ebx
  Scaleform::GFx::FontCompactor::KerningPairType *v13; // edi
  int v14; // eax
  int kp; // [esp+Ch] [ebp-8h]

  v4 = char1;
  p_GlyphCodes = &this->GlyphCodes;
  char1 = (unsigned __int16)char1;
  v7 = Scaleform::HashSetBase<unsigned short,Scaleform::FixedSizeHash<unsigned short>,Scaleform::FixedSizeHash<unsigned short>,Scaleform::AllocatorGH<unsigned short,2>,Scaleform::HashsetCachedEntry<unsigned short,Scaleform::FixedSizeHash<unsigned short>>>::findIndex<unsigned short>(
         &this->GlyphCodes,
         (const unsigned __int16 *)&char1);
  if ( v7 >= 0
    && (Scaleform::HashSetBase<unsigned short,Scaleform::FixedSizeHash<unsigned short>,Scaleform::FixedSizeHash<unsigned short>,Scaleform::AllocatorGH<unsigned short,2>,Scaleform::HashsetCachedEntry<unsigned short,Scaleform::FixedSizeHash<unsigned short> > >::TableType *)((char *)p_GlyphCodes->pTable + 12 * v7) != (Scaleform::HashSetBase<unsigned short,Scaleform::FixedSizeHash<unsigned short>,Scaleform::FixedSizeHash<unsigned short>,Scaleform::AllocatorGH<unsigned short,2>,Scaleform::HashsetCachedEntry<unsigned short,Scaleform::FixedSizeHash<unsigned short> > >::TableType *)-16 )
  {
    v8 = char2;
    char1 = char2;
    v9 = Scaleform::HashSetBase<unsigned short,Scaleform::FixedSizeHash<unsigned short>,Scaleform::FixedSizeHash<unsigned short>,Scaleform::AllocatorGH<unsigned short,2>,Scaleform::HashsetCachedEntry<unsigned short,Scaleform::FixedSizeHash<unsigned short>>>::findIndex<unsigned short>(
           p_GlyphCodes,
           (const unsigned __int16 *)&char1);
    if ( v9 >= 0
      && (Scaleform::HashSetBase<unsigned short,Scaleform::FixedSizeHash<unsigned short>,Scaleform::FixedSizeHash<unsigned short>,Scaleform::AllocatorGH<unsigned short,2>,Scaleform::HashsetCachedEntry<unsigned short,Scaleform::FixedSizeHash<unsigned short> > >::TableType *)((char *)p_GlyphCodes->pTable + 12 * v9) != (Scaleform::HashSetBase<unsigned short,Scaleform::FixedSizeHash<unsigned short>,Scaleform::FixedSizeHash<unsigned short>,Scaleform::AllocatorGH<unsigned short,2>,Scaleform::HashsetCachedEntry<unsigned short,Scaleform::FixedSizeHash<unsigned short> > >::TableType *)-16 )
    {
      p_KerningTable = &this->KerningTable;
      v11 = this->KerningTable.Size >> 6;
      HIWORD(kp) = v8;
      v12 = adjustment;
      LOWORD(kp) = v4;
      if ( v11 >= p_KerningTable->NumPages )
        Scaleform::ArrayPagedBase<Scaleform::GFx::FontCompactor::ContourType,6,64,Scaleform::AllocatorPagedGH_POD<Scaleform::GFx::FontCompactor::ContourType,261>>::allocatePage(
          p_KerningTable,
          v11);
      v13 = p_KerningTable->Pages[v11];
      v14 = p_KerningTable->Size & 0x3F;
      *(_DWORD *)&v13[v14].Char1 = kp;
      v13[v14].Adjustment = v12;
      ++p_KerningTable->Size;
    }
  }
}
