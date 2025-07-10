void __thiscall Scaleform::Render::TextMeshProvider::addUnderline(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::TmpTextStorage *storage,
        unsigned int color,
        Scaleform::Render::TextUnderlineStyle style,
        float x,
        float y,
        float len)
{
  Scaleform::Render::GlyphCache *pCache; // ecx
  unsigned int Size; // eax
  Scaleform::Render::PrimitiveFill *Fill; // eax
  unsigned int v10; // esi
  unsigned int v11; // esi
  Scaleform::Render::TmpTextMeshEntry e; // [esp+Ch] [ebp-24h] BYREF

  pCache = this->pCache;
  e.LayerType = 9;
  Size = storage->Entries.Size;
  e.TextureId = 0;
  e.EntryIdx = Size;
  e.mColor = color;
  Fill = Scaleform::Render::GlyphCache::GetFill(pCache, TextLayer_Underline, 0);
  ++Fill->RefCount;
  e.EntryData.RasterData.Coord[1] = x;
  v10 = storage->Entries.Size;
  e.EntryData.RasterData.Coord[2] = y;
  e.pFill = Fill;
  e.EntryData.RasterData.Coord[3] = len;
  v11 = v10 >> 6;
  e.EntryData.UnderlineData.Style = style;
  if ( v11 >= storage->Entries.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4>::allocPage(&storage->Entries, v11);
  qmemcpy(
    &storage->Entries.Pages[v11][storage->Entries.Size++ & 0x3F],
    &e,
    sizeof(storage->Entries.Pages[v11][storage->Entries.Size++ & 0x3F]));
}
