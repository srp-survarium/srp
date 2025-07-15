void __thiscall Scaleform::Render::TextMeshProvider::addCursor(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::TmpTextStorage *storage,
        unsigned int color,
        const Scaleform::Render::Rect<float> *rect)
{
  Scaleform::Render::GlyphCache *pCache; // ecx
  Scaleform::Render::PrimitiveFill *Fill; // eax
  unsigned int Size; // esi
  unsigned int v7; // esi
  _DWORD v8[9]; // [esp+Ch] [ebp-24h] BYREF

  pCache = this->pCache;
  v8[0] = 10;
  v8[1] = storage->Entries.Size;
  v8[2] = color;
  Fill = Scaleform::Render::GlyphCache::GetFill(pCache, TextLayer_Cursor, 0);
  ++Fill->RefCount;
  v8[3] = Fill;
  Size = storage->Entries.Size;
  *(float *)&v8[4] = rect->x1;
  v7 = Size >> 6;
  *(float *)&v8[5] = rect->y1;
  *(float *)&v8[6] = rect->x2;
  *(float *)&v8[7] = rect->y2;
  if ( v7 >= storage->Entries.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4>::allocPage(&storage->Entries, v7);
  qmemcpy(
    &storage->Entries.Pages[v7][storage->Entries.Size++ & 0x3F],
    v8,
    sizeof(storage->Entries.Pages[v7][storage->Entries.Size++ & 0x3F]));
}
