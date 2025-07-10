void __thiscall Scaleform::Render::TextMeshProvider::addVectorGlyph(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::TmpTextStorage *storage,
        unsigned int color,
        Scaleform::Render::FontCacheHandle *font,
        unsigned __int16 glyphIndex,
        unsigned __int16 flags,
        float fontSize,
        float x,
        float y)
{
  Scaleform::Render::GlyphCache *pCache; // ecx
  unsigned int Size; // eax
  Scaleform::Render::PrimitiveFill *Fill; // eax
  Scaleform::GFx::Resource *pFont; // ecx
  Scaleform::Render::Font *v13; // eax
  unsigned int v14; // esi
  unsigned int v15; // esi
  Scaleform::Render::TmpTextMeshEntry e; // [esp+Ch] [ebp-24h] BYREF

  pCache = this->pCache;
  e.LayerType = 8;
  Size = storage->Entries.Size;
  e.TextureId = 0;
  e.EntryIdx = Size;
  e.mColor = color;
  Fill = Scaleform::Render::GlyphCache::GetFill(pCache, TextLayer_Shapes, 0);
  ++Fill->RefCount;
  pFont = (Scaleform::GFx::Resource *)font->pFont;
  e.pFill = Fill;
  Scaleform::RefCountImpl::AddRef(pFont);
  v13 = font->pFont;
  e.EntryData.RasterData.Coord[2] = fontSize;
  e.EntryData.RasterData.Coord[3] = x;
  v14 = storage->Entries.Size;
  e.EntryData.VectorData.y = y;
  v15 = v14 >> 6;
  e.EntryData.UnderlineData.Style = (unsigned int)v13;
  e.EntryData.VectorData.GlyphIndex = glyphIndex;
  e.EntryData.VectorData.Flags = flags;
  if ( v15 >= storage->Entries.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4>::allocPage(&storage->Entries, v15);
  qmemcpy(
    &storage->Entries.Pages[v15][storage->Entries.Size++ & 0x3F],
    &e,
    sizeof(storage->Entries.Pages[v15][storage->Entries.Size++ & 0x3F]));
}
