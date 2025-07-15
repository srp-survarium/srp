void __thiscall Scaleform::Render::TextMeshProvider::addCursor(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::TmpTextStorage *storage,
        unsigned int color,
        const Scaleform::Render::Rect<float> *rect)
{
  Scaleform::Render::GlyphCache *pCache; // ecx
  unsigned int Size; // eax
  Scaleform::Render::PrimitiveFill *Fill; // eax
  unsigned int v7; // esi
  unsigned int v8; // esi
  Scaleform::Render::TmpTextMeshEntry e; // [esp+Ch] [ebp-24h] BYREF

  pCache = this->pCache;
  e.LayerType = 10;
  Size = storage->Entries.Size;
  e.TextureId = 0;
  e.EntryIdx = Size;
  e.mColor = color;
  Fill = Scaleform::Render::GlyphCache::GetFill(pCache, TextLayer_Cursor, 0);
  ++Fill->RefCount;
  e.pFill = Fill;
  v7 = storage->Entries.Size;
  e.EntryData.RasterData.Coord[0] = rect->x1;
  v8 = v7 >> 6;
  e.EntryData.RasterData.Coord[1] = rect->y1;
  e.EntryData.RasterData.Coord[2] = rect->x2;
  e.EntryData.RasterData.Coord[3] = rect->y2;
  if ( v8 >= storage->Entries.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4>::allocPage(&storage->Entries, v8);
  qmemcpy(
    &storage->Entries.Pages[v8][storage->Entries.Size++ & 0x3F],
    &e,
    sizeof(storage->Entries.Pages[v8][storage->Entries.Size++ & 0x3F]));
}
