void __thiscall Scaleform::Render::TextMeshProvider::addBackground(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::TmpTextStorage *storage,
        unsigned int color,
        unsigned int borderColor,
        const Scaleform::Render::Rect<float> *rect)
{
  Scaleform::Render::GlyphCache *pCache; // ecx
  Scaleform::Render::PrimitiveFill *Fill; // eax
  unsigned int Size; // esi
  unsigned int v8; // esi
  _DWORD v9[9]; // [esp+Ch] [ebp-24h] BYREF

  pCache = this->pCache;
  v9[0] = 0;
  v9[1] = storage->Entries.Size;
  v9[2] = color;
  Fill = Scaleform::Render::GlyphCache::GetFill(pCache, TextLayer_Background, 0);
  ++Fill->RefCount;
  v9[3] = Fill;
  Size = storage->Entries.Size;
  *(float *)&v9[4] = rect->x1;
  v8 = Size >> 6;
  *(float *)&v9[5] = rect->y1;
  *(float *)&v9[6] = rect->x2;
  *(float *)&v9[7] = rect->y2;
  v9[8] = borderColor;
  if ( v8 >= storage->Entries.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4>::allocPage(&storage->Entries, v8);
  qmemcpy(
    &storage->Entries.Pages[v8][storage->Entries.Size++ & 0x3F],
    v9,
    sizeof(storage->Entries.Pages[v8][storage->Entries.Size++ & 0x3F]));
}
