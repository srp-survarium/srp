void __thiscall Scaleform::Render::TextMeshProvider::addMask(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::TmpTextStorage *storage)
{
  unsigned int Size; // edx
  Scaleform::Render::GlyphCache *pCache; // ecx
  Scaleform::Render::PrimitiveFill *Fill; // eax
  double y1; // st7
  double y2; // st7
  unsigned int v8; // esi
  Scaleform::Render::TmpTextMeshEntry e; // [esp+Ch] [ebp-24h] BYREF

  Size = storage->Entries.Size;
  e.TextureId = 0;
  e.mColor = 0;
  pCache = this->pCache;
  e.LayerType = 11;
  e.EntryIdx = Size;
  Fill = Scaleform::Render::GlyphCache::GetFill(pCache, TextLayer_Mask, 0);
  ++Fill->RefCount;
  e.EntryData.RasterData.Coord[0] = this->ClipBox.x1;
  y1 = this->ClipBox.y1;
  e.pFill = Fill;
  e.EntryData.RasterData.Coord[1] = y1;
  e.EntryData.RasterData.Coord[2] = this->ClipBox.x2;
  y2 = this->ClipBox.y2;
  v8 = storage->Entries.Size >> 6;
  e.EntryData.RasterData.Coord[3] = y2;
  if ( v8 >= storage->Entries.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4>::allocPage(&storage->Entries, v8);
  qmemcpy(
    &storage->Entries.Pages[v8][storage->Entries.Size++ & 0x3F],
    &e,
    sizeof(storage->Entries.Pages[v8][storage->Entries.Size++ & 0x3F]));
}
