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
  Scaleform::Render::PrimitiveFill *Fill; // eax
  Scaleform::Render::Font *pFont; // ecx
  Scaleform::Render::Font *v12; // eax
  unsigned int Size; // esi
  unsigned int v14; // esi
  _DWORD v15[9]; // [esp+Ch] [ebp-24h] BYREF

  pCache = this->pCache;
  v15[0] = 8;
  v15[1] = storage->Entries.Size;
  v15[2] = color;
  Fill = Scaleform::Render::GlyphCache::GetFill(pCache, TextLayer_Shapes, 0);
  ++Fill->RefCount;
  pFont = font->pFont;
  v15[3] = Fill;
  Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)pFont);
  v12 = font->pFont;
  *(float *)&v15[6] = fontSize;
  *(float *)&v15[7] = x;
  Size = storage->Entries.Size;
  *(float *)&v15[8] = y;
  v14 = Size >> 6;
  v15[4] = v12;
  LOWORD(v15[5]) = glyphIndex;
  HIWORD(v15[5]) = flags;
  if ( v14 >= storage->Entries.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4>::allocPage(&storage->Entries, v14);
  qmemcpy(
    &storage->Entries.Pages[v14][storage->Entries.Size++ & 0x3F],
    v15,
    sizeof(storage->Entries.Pages[v14][storage->Entries.Size++ & 0x3F]));
}
