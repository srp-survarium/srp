void __thiscall Scaleform::GFx::FontGlyphPacker::GenerateFontBitmaps(
        Scaleform::GFx::FontGlyphPacker *this,
        const Scaleform::Array<Scaleform::GFx::FontResource *,2,Scaleform::ArrayDefaultPolicy> *fonts)
{
  unsigned int v2; // edi
  unsigned int v3; // eax
  Scaleform::Render::Font *pObject; // ecx
  int GlyphCountLimit; // ebx
  Scaleform::Render::Font *v7; // ecx
  Scaleform::Render::Font *v8; // ecx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,unsigned int,Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey>,Scaleform::HashNode<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,unsigned int,Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,unsigned int,Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,unsigned int,Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey>,Scaleform::HashNode<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,unsigned int,Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey>::NodeHashF> >::TableType *pTable; // eax
  int v10; // ecx
  int v11; // edx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,unsigned int,Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey>,Scaleform::HashNode<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,unsigned int,Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,unsigned int,Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,unsigned int,Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey>,Scaleform::HashNode<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,unsigned int,Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey>::NodeHashF> >::TableType *v12; // eax
  bool v13; // zf
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,unsigned int,Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey>,Scaleform::HashNode<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,unsigned int,Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,unsigned int,Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,unsigned int,Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey>,Scaleform::HashNode<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,unsigned int,Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey>::NodeHashF> >::TableType *v14; // eax
  Scaleform::Render::Font *v15; // ecx
  int v16; // ebx
  Scaleform::Render::Font *v17; // ecx
  unsigned int v18; // eax
  unsigned int v19; // [esp+10h] [ebp-10h]
  Scaleform::ArrayDataBase<Scaleform::Render::TextureGlyph,Scaleform::AllocatorGH<Scaleform::Render::TextureGlyph,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [esp+14h] [ebp-Ch] BYREF

  v2 = 0;
  v3 = 0;
  v19 = 0;
  if ( fonts->Data.Size )
  {
    do
    {
      pObject = fonts->Data.Data[v2]->pFont.pObject;
      if ( !pObject->GetTextureGlyphData(pObject) )
      {
        GlyphCountLimit = this->pFontPackParams->GlyphCountLimit;
        if ( !GlyphCountLimit
          || (v7 = fonts->Data.Data[v2]->pFont.pObject, (int)v7->GetGlyphShapeCount(v7) <= GlyphCountLimit) )
        {
          v8 = fonts->Data.Data[v2]->pFont.pObject;
          v19 += v8->GetGlyphShapeCount(v8);
        }
      }
      ++v2;
    }
    while ( v2 < fonts->Data.Size );
    v3 = v19;
    v2 = 0;
  }
  memset(&pheapAddr, 0, sizeof(pheapAddr));
  if ( v3 )
    Scaleform::ArrayDataBase<Scaleform::Render::TextureGlyph,Scaleform::AllocatorGH<Scaleform::Render::TextureGlyph,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &pheapAddr,
      &pheapAddr,
      v3);
  pTable = this->GlyphGeometryHash.mHash.pTable;
  if ( pTable )
  {
    v10 = 0;
    v11 = pTable->SizeMask + 1;
    do
    {
      v12 = this->GlyphGeometryHash.mHash.pTable;
      v13 = v12[v10 + 1].EntryCount == -2;
      v14 = &v12[v10 + 1];
      if ( !v13 )
        v14->EntryCount = -2;
      v10 += 3;
      --v11;
    }
    while ( v11 );
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->GlyphGeometryHash.mHash.pTable);
    this->GlyphGeometryHash.mHash.pTable = 0;
  }
  if ( fonts->Data.Size )
  {
    do
    {
      v15 = fonts->Data.Data[v2]->pFont.pObject;
      if ( !v15->GetTextureGlyphData(v15) )
      {
        v16 = this->pFontPackParams->GlyphCountLimit;
        if ( !v16 || (v17 = fonts->Data.Data[v2]->pFont.pObject, (int)v17->GetGlyphShapeCount(v17) <= v16) )
          Scaleform::GFx::FontGlyphPacker::generateGlyphInfo(
            this,
            (Scaleform::Array<Scaleform::GFx::FontGlyphPacker::GlyphInfo,2,Scaleform::ArrayDefaultPolicy> *)&pheapAddr,
            fonts->Data.Data[v2]);
      }
      ++v2;
    }
    while ( v2 < fonts->Data.Size );
  }
  v18 = Scaleform::GFx::FontGlyphPacker::packGlyphRects(
          this,
          (Scaleform::Array<Scaleform::GFx::FontGlyphPacker::GlyphInfo,2,Scaleform::ArrayDefaultPolicy> *)&pheapAddr);
  Scaleform::GFx::FontGlyphPacker::generateTextures(
    this,
    (Scaleform::Array<Scaleform::GFx::FontGlyphPacker::GlyphInfo,2,Scaleform::ArrayDefaultPolicy> *)&pheapAddr,
    v18);
  if ( pheapAddr.Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)pheapAddr.Data);
}
