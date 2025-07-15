void __thiscall Scaleform::GFx::TextureGlyphData::TextureGlyphData(
        Scaleform::GFx::TextureGlyphData *this,
        const Scaleform::GFx::TextureGlyphData *orig)
{
  Scaleform::ArrayLH<Scaleform::Render::TextureGlyph,261,Scaleform::ArrayDefaultPolicy> *p_TextureGlyphs; // esi
  unsigned int Size; // ebx
  unsigned int v4; // ebp
  unsigned int v5; // ebp
  int v6; // ebx
  _DWORD *p_EntryCount; // ecx
  unsigned int v8; // eax
  unsigned int v9; // edx
  _DWORD *v10; // ecx
  _DWORD *v11; // edi
  signed int v12; // esi
  int v13; // eax
  int v14; // eax
  unsigned int v15; // eax
  _DWORD *v16; // ecx
  Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >::NodeRef key; // [esp+14h] [ebp-8h] BYREF

  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::TextureGlyphData_vtbl *)&Scaleform::GFx::TextureGlyphData::`vftable';
  this->PackTextureConfig = orig->PackTextureConfig;
  p_TextureGlyphs = &this->TextureGlyphs;
  this->TextureGlyphs.Data.Data = 0;
  this->TextureGlyphs.Data.Size = 0;
  this->TextureGlyphs.Data.Policy.Capacity = 0;
  this->GlyphsTextures.mHash.pTable = 0;
  this->FileCreation = orig->FileCreation;
  Size = orig->TextureGlyphs.Data.Size;
  v4 = this->TextureGlyphs.Data.Size;
  Scaleform::ArrayDataBase<Scaleform::Render::TextureGlyph,Scaleform::AllocatorLH<Scaleform::Render::TextureGlyph,261>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->TextureGlyphs.Data,
    &this->TextureGlyphs,
    Size);
  if ( Size > v4 )
    Scaleform::ConstructorMov<Scaleform::Render::TextureGlyph>::ConstructArray(
      (char *)&p_TextureGlyphs->Data.Data[v4],
      Size - v4);
  v5 = orig->TextureGlyphs.Data.Size;
  if ( v5 )
  {
    v6 = 0;
    do
    {
      Scaleform::Render::TextureGlyph::operator=(&p_TextureGlyphs->Data.Data[v6], &orig->TextureGlyphs.Data.Data[v6]);
      ++v6;
      --v5;
    }
    while ( v5 );
  }
  p_EntryCount = &orig->GlyphsTextures.mHash.pTable->EntryCount;
  if ( p_EntryCount )
  {
    v9 = p_EntryCount[1];
    v8 = 0;
    v10 = p_EntryCount + 2;
    do
    {
      if ( *v10 != -2 )
        break;
      ++v8;
      v10 += 5;
    }
    while ( v8 <= v9 );
    p_EntryCount = &orig->GlyphsTextures.mHash.pTable;
  }
  else
  {
    v8 = 0;
  }
  v11 = p_EntryCount;
  v12 = v8;
  while ( v11 )
  {
    v13 = *v11;
    if ( !*v11 || v12 > *(_DWORD *)(v13 + 4) )
      break;
    v14 = v13 + 20 * v12;
    key.pSecond = (const Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource> *)(v14 + 20);
    key.pFirst = (const Scaleform::GFx::ResourceId *)(v14 + 16);
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,261>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeRef>(
      &this->GlyphsTextures.mHash,
      &this->GlyphsTextures,
      &key);
    v15 = *(_DWORD *)(*v11 + 4);
    if ( v12 <= (int)v15 && ++v12 <= v15 )
    {
      v16 = (_DWORD *)(*v11 + 20 * v12 + 8);
      do
      {
        if ( *v16 != -2 )
          break;
        ++v12;
        v16 += 5;
      }
      while ( v12 <= v15 );
    }
  }
}


void __thiscall Scaleform::GFx::TextureGlyphData::TextureGlyphData(
        Scaleform::GFx::TextureGlyphData *this,
        unsigned int glyphCount,
        bool isLoadedFromFile)
{
  Scaleform::ArrayLH<Scaleform::Render::TextureGlyph,261,Scaleform::ArrayDefaultPolicy> *p_TextureGlyphs; // edi
  unsigned int Size; // ebx

  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::TextureGlyphData_vtbl *)&Scaleform::GFx::TextureGlyphData::`vftable';
  this->PackTextureConfig.NominalSize = 48;
  this->PackTextureConfig.PadPixels = 3;
  this->PackTextureConfig.TextureWidth = 1024;
  this->PackTextureConfig.TextureHeight = 1024;
  p_TextureGlyphs = &this->TextureGlyphs;
  this->TextureGlyphs.Data.Data = 0;
  this->TextureGlyphs.Data.Size = 0;
  this->TextureGlyphs.Data.Policy.Capacity = 0;
  this->GlyphsTextures.mHash.pTable = 0;
  this->FileCreation = isLoadedFromFile;
  Size = this->TextureGlyphs.Data.Size;
  Scaleform::ArrayDataBase<Scaleform::Render::TextureGlyph,Scaleform::AllocatorLH<Scaleform::Render::TextureGlyph,261>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->TextureGlyphs.Data,
    &this->TextureGlyphs,
    glyphCount);
  if ( glyphCount > Size )
    Scaleform::ConstructorMov<Scaleform::Render::TextureGlyph>::ConstructArray(
      (char *)&p_TextureGlyphs->Data.Data[Size],
      glyphCount - Size);
}
