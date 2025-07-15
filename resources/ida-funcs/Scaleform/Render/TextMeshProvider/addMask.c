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
  _DWORD v9[9]; // [esp+Ch] [ebp-24h] BYREF

  Size = storage->Entries.Size;
  v9[2] = 0;
  pCache = this->pCache;
  v9[0] = 11;
  v9[1] = Size;
  Fill = Scaleform::Render::GlyphCache::GetFill(pCache, TextLayer_Mask, 0);
  ++Fill->RefCount;
  *(float *)&v9[4] = this->ClipBox.x1;
  y1 = this->ClipBox.y1;
  v9[3] = Fill;
  *(float *)&v9[5] = y1;
  *(float *)&v9[6] = this->ClipBox.x2;
  y2 = this->ClipBox.y2;
  v8 = storage->Entries.Size >> 6;
  *(float *)&v9[7] = y2;
  if ( v8 >= storage->Entries.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4>::allocPage(&storage->Entries, v8);
  qmemcpy(
    &storage->Entries.Pages[v8][storage->Entries.Size++ & 0x3F],
    v9,
    sizeof(storage->Entries.Pages[v8][storage->Entries.Size++ & 0x3F]));
}
