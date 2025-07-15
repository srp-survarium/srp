void __thiscall Scaleform::Render::TextMeshProvider::createVectorGlyph(
        Scaleform::Render::TextMeshProvider *this,
        unsigned int layerIdx,
        Scaleform::Render::Renderer2DImpl *ren,
        const Scaleform::Render::MatrixPoolImpl::HMatrix *m,
        unsigned int meshGenFlags)
{
  Scaleform::Render::TextMeshLayer *v6; // ebx
  Scaleform::Render::TextMeshEntry *v7; // esi
  Scaleform::Render::GlyphCache *pCache; // ecx
  double y; // st6
  unsigned int v10; // eax
  Scaleform::Render::MeshKey *MatchingKey; // eax
  Scaleform::Render::MeshKey *pObject; // ecx
  void (*AddRef)(void); // eax
  Scaleform::Render::VectorGlyphShape *v14; // eax
  double v15; // st7
  Scaleform::Render::Mesh *v16; // eax
  Scaleform::Render::MeshBase *v17; // eax
  Scaleform::Render::MeshBase *v18; // edi
  Scaleform::Render::MeshKey *v19; // esi
  Scaleform::RefCountVImpl *v20; // ecx
  Scaleform::Ptr<Scaleform::Render::MeshBase> *p_pMesh; // esi
  Scaleform::Render::MeshKey *v22; // eax
  Scaleform::Render::Mesh *v23; // esi
  Scaleform::RefCountVImpl *v24; // ecx
  Scaleform::Render::MeshProvider *v25; // ecx
  float v26; // [esp+28h] [ebp-160h] BYREF
  Scaleform::Render::VectorGlyphShape *v27; // [esp+2Ch] [ebp-15Ch]
  float v28; // [esp+30h] [ebp-158h]
  Scaleform::Render::MeshProvider *v29; // [esp+34h] [ebp-154h]
  Scaleform::Render::Matrix2x4<float> viewMatrix; // [esp+38h] [ebp-150h] BYREF
  unsigned __int16 Flags; // [esp+60h] [ebp-128h]
  Scaleform::Render::GlyphRunData v32; // [esp+68h] [ebp-120h] BYREF
  float v33[20]; // [esp+138h] [ebp-50h] BYREF

  v6 = &this->Layers.Data.Data[layerIdx];
  v7 = &this->Entries.Data.Data[v6->Start];
  Scaleform::Render::GlyphRunData::GlyphRunData(&v32);
  pCache = this->pCache;
  v32.pFont = v7->EntryData.VectorData.pFont;
  v32.pFontHandle = Scaleform::Render::GlyphCache::RegisterFont(pCache, v32.pFont);
  v32.FontSize = v7->EntryData.RasterData.Coord[2];
  v32.VectorSize = 0;
  v32.NomWidth = 0.0;
  v32.RasterSize = 0;
  v32.NomHeight = 0.0;
  v32.TexHeight = 0.0;
  v32.mColor = v7->mColor;
  v32.NewLineX = v7->EntryData.RasterData.Coord[3];
  y = v7->EntryData.VectorData.y;
  v32.HintedNomHeight = 0;
  v32.NewLineY = y;
  v32.GlyphBounds.x1 = 0.0;
  v32.GlyphBounds.y1 = 0.0;
  v32.GlyphBounds.x2 = 0.0;
  v32.GlyphBounds.y2 = 0.0;
  v32.HeightRatio = this->HeightRatio;
  Flags = v7->EntryData.VectorData.Flags;
  v27 = Scaleform::Render::GlyphCache::CreateGlyphShape(
          this->pCache,
          &v32,
          v7->EntryData.VectorData.GlyphIndex,
          0.0,
          (Flags & 8) != 0,
          (Flags & 0x10) != 0,
          Flags >> 12,
          1);
  v32.HintedNomHeight = v27->pShape.pObject->HintedSize;
  v28 = v32.FontSize / v32.NomHeight;
  v26 = this->HeightRatio * v28;
  viewMatrix.M[0][0] = v26;
  viewMatrix.M[0][1] = 0.0;
  viewMatrix.M[0][2] = 0.0;
  viewMatrix.M[0][3] = 0.0;
  viewMatrix.M[1][0] = 0.0;
  viewMatrix.M[1][2] = 0.0;
  viewMatrix.M[1][3] = 0.0;
  viewMatrix.M[1][1] = v26;
  v10 = Scaleform::Render::TextMeshProvider::CalcVectorParams(v6, v7, &viewMatrix, v28, m, ren, meshGenFlags, v33);
  MatchingKey = Scaleform::Render::MeshKeyManager::CreateMatchingKey(
                  ren->pMeshKeyManager.pObject,
                  v27,
                  0,
                  v10,
                  v33,
                  &ren->Tolerances);
  pObject = v6->pMeshKey.pObject;
  v26 = *(float *)&MatchingKey;
  if ( pObject )
    Scaleform::Render::MeshKey::Release(pObject);
  *(float *)&v6->pMeshKey.pObject = v26;
  AddRef = (void (*)(void))v27->AddRef;
  v29 = &v27->Scaleform::Render::MeshProvider;
  AddRef();
  v14 = v6->pShape.pObject;
  if ( v14 )
    v14->Release(&v14->Scaleform::Render::MeshProvider);
  v15 = v28;
  v6->pShape.pObject = v27;
  v6->SizeScale = v15;
  if ( !v6->pMeshKey.pObject->pMesh.pObject )
  {
    LODWORD(v26) = 70;
    v16 = (Scaleform::Render::Mesh *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                       Scaleform::Memory::pGlobalHeap,
                                       this,
                                       176,
                                       &v26);
    if ( v16 )
    {
      Scaleform::Render::Mesh::Mesh(v16, ren, v6->pMeshKey.pObject->pKeySet, &viewMatrix, 0.0, 0, meshGenFlags);
      v18 = v17;
    }
    else
    {
      v18 = 0;
    }
    v19 = v6->pMeshKey.pObject;
    v20 = (Scaleform::RefCountVImpl *)v19->pMesh.pObject;
    p_pMesh = &v19->pMesh;
    if ( v20 )
      Scaleform::RefCountImpl::Release(v20);
    p_pMesh->pObject = v18;
  }
  v22 = v6->pMeshKey.pObject;
  v23 = (Scaleform::Render::Mesh *)v22->pMesh.pObject;
  if ( v23 )
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v22->pMesh.pObject);
  v24 = (Scaleform::RefCountVImpl *)v6->pMesh.pObject;
  if ( v24 )
    Scaleform::RefCountImpl::Release(v24);
  v25 = v29;
  v6->pMesh.pObject = v23;
  v25->Release(v25);
}
