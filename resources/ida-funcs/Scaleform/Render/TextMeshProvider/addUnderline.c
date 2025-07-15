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
  Scaleform::Render::PrimitiveFill *Fill; // eax
  unsigned int Size; // esi
  unsigned int v10; // esi
  _DWORD v11[9]; // [esp+Ch] [ebp-24h] BYREF

  pCache = this->pCache;
  v11[0] = 9;
  v11[1] = storage->Entries.Size;
  v11[2] = color;
  Fill = Scaleform::Render::GlyphCache::GetFill(pCache, TextLayer_Underline, 0);
  ++Fill->RefCount;
  *(float *)&v11[5] = x;
  Size = storage->Entries.Size;
  *(float *)&v11[6] = y;
  v11[3] = Fill;
  *(float *)&v11[7] = len;
  v10 = Size >> 6;
  v11[4] = style;
  if ( v10 >= storage->Entries.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4>::allocPage(&storage->Entries, v10);
  qmemcpy(
    &storage->Entries.Pages[v10][storage->Entries.Size++ & 0x3F],
    v11,
    sizeof(storage->Entries.Pages[v10][storage->Entries.Size++ & 0x3F]));
}
