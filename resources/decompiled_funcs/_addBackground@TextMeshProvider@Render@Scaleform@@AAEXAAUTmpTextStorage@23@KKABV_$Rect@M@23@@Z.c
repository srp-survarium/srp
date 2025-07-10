void __thiscall Scaleform::Render::TextMeshProvider::addBackground(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::TmpTextStorage *storage,
        unsigned int color,
        unsigned int borderColor,
        const Scaleform::Render::Rect<float> *rect)
{
  Scaleform::Render::GlyphCache *pCache; // ecx
  unsigned int Size; // eax
  Scaleform::Render::PrimitiveFill *Fill; // eax
  unsigned int v8; // esi
  unsigned int v9; // esi
  Scaleform::Render::TmpTextMeshEntry e; // [esp+Ch] [ebp-24h] BYREF

  pCache = this->pCache;
  e.LayerType = 0;
  Size = storage->Entries.Size;
  e.TextureId = 0;
  e.EntryIdx = Size;
  e.mColor = color;
  Fill = Scaleform::Render::GlyphCache::GetFill(pCache, TextLayer_Background, 0);
  ++Fill->RefCount;
  e.pFill = Fill;
  v8 = storage->Entries.Size;
  e.EntryData.RasterData.Coord[0] = rect->x1;
  v9 = v8 >> 6;
  e.EntryData.RasterData.Coord[1] = rect->y1;
  e.EntryData.RasterData.Coord[2] = rect->x2;
  e.EntryData.RasterData.Coord[3] = rect->y2;
  e.EntryData.BackgroundData.BorderColor = borderColor;
  if ( v9 >= storage->Entries.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4>::allocPage(&storage->Entries, v9);
  qmemcpy(
    &storage->Entries.Pages[v9][storage->Entries.Size++ & 0x3F],
    &e,
    sizeof(storage->Entries.Pages[v9][storage->Entries.Size++ & 0x3F]));
}
