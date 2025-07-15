Scaleform::Render::VectorGlyphShape *__thiscall Scaleform::Render::GlyphCache::CreateGlyphShape(
        Scaleform::Render::GlyphCache *this,
        Scaleform::Render::GlyphRunData *data,
        unsigned int glyphIndex,
        float screenSize,
        bool fauxBold,
        bool fauxItalic,
        unsigned int outline,
        bool needsVectorShape)
{
  Scaleform::Render::Font *pFont; // esi
  float (__thiscall *GetNominalGlyphHeight)(Scaleform::Render::Font *); // edx
  double v11; // st7
  Scaleform::Render::Font_vtbl *v12; // edx
  int v13; // eax
  const Scaleform::Render::ShapeDataInterface *v14; // eax
  Scaleform::Render::FontCacheHandle *pFontHandle; // ecx
  Scaleform::Ptr<Scaleform::Render::VectorGlyphShape> *v17; // eax
  Scaleform::Ptr<Scaleform::Render::VectorGlyphShape> *v18; // esi
  Scaleform::Render::VectorGlyphShape *pObject; // eax
  float *v20; // ecx
  Scaleform::Render::VectorGlyphShape *v21; // eax
  Scaleform::Render::MeshProvider_vtbl *v22; // edx
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor> >::TableType *pTable; // eax
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor> >::TableType *v24; // eax
  Scaleform::Render::VectorGlyphShape *pNext; // ecx
  unsigned int MaxVectorCacheSize; // edx
  unsigned int v27; // esi
  Scaleform::Render::GlyphCache::EvictNotifier *p_Notifier; // eax
  Scaleform::Render::VectorGlyphShape *v29; // edx
  Scaleform::Render::VectorGlyphShape **p_pNext; // eax
  Scaleform::Render::MeshKeySet *volatile *p_pKeySet; // ecx
  Scaleform::Render::VectorGlyphShape *v32; // ecx
  Scaleform::Render::VectorGlyphShape *v33; // eax
  Scaleform::Render::VectorGlyphShape *v34; // eax
  Scaleform::Render::VectorGlyphShape *v35; // esi
  unsigned __int8 v36; // dl
  unsigned __int8 v37; // al
  unsigned __int16 v38; // cx
  Scaleform::MemoryHeap *pHeap; // ecx
  void *(__thiscall *Alloc)(Scaleform::MemoryHeap *, unsigned int, const Scaleform::AllocInfo *); // edx
  Scaleform::Render::GlyphShape *v41; // eax
  float v42; // eax
  Scaleform::RefCountVImpl *v43; // ecx
  bool v44; // zf
  float v45; // eax
  Scaleform::RefCountNTSImpl *v46; // ecx
  Scaleform::Render::GlyphShape *v47; // eax
  const Scaleform::Render::ShapeDataInterface *v48; // eax
  unsigned int v49; // eax
  const Scaleform::Render::ShapeDataInterface *v50; // ecx
  unsigned int v51; // edx
  Scaleform::Render::VectorGlyphShape *v52; // [esp+54h] [ebp-38h] BYREF
  const Scaleform::Render::ShapeDataInterface *v53; // [esp+58h] [ebp-34h]
  const Scaleform::Render::ShapeDataInterface *v54; // [esp+5Ch] [ebp-30h]
  float *v55; // [esp+60h] [ebp-2Ch]
  const Scaleform::Render::ShapeDataInterface *shapeData; // [esp+64h] [ebp-28h]
  Scaleform::HashSetLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,2,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor> > *p_VectorGlyphCache; // [esp+68h] [ebp-24h]
  float y2; // [esp+6Ch] [ebp-20h]
  float y1; // [esp+70h] [ebp-1Ch]
  __int64 v60; // [esp+74h] [ebp-18h]
  Scaleform::Render::VectorGlyphKey key; // [esp+80h] [ebp-Ch] BYREF

  data->VectorSize = 0;
  data->RasterSize = 0;
  data->pShape = 0;
  data->pRaster = 0;
  pFont = data->pFont;
  data->GlyphBounds.x1 = 0.0;
  data->GlyphBounds.y1 = 0.0;
  LODWORD(y2) = &data->GlyphBounds;
  data->GlyphBounds.x2 = 0.0;
  data->GlyphBounds.y2 = 0.0;
  GetNominalGlyphHeight = pFont->GetNominalGlyphHeight;
  v55 = (float *)pFont;
  data->NomHeight = GetNominalGlyphHeight(pFont);
  data->NomWidth = pFont->GetNominalGlyphWidth(pFont);
  if ( (unsigned __int16)glyphIndex == 0xFFFF )
    return 0;
  if ( (pFont->Flags & 0x20) == 0 )
    screenSize = 0.0;
  v54 = 0;
  v53 = 0;
  v11 = screenSize;
  if ( screenSize != 0.0 )
  {
    LODWORD(y1) = (unsigned __int16)v52 | 0xC00;
    v60 = (__int64)v11;
    v12 = pFont->__vftable;
    shapeData = (const Scaleform::Render::ShapeDataInterface *)(__int64)v11;
    if ( v12->IsHintedRasterGlyph(pFont, glyphIndex, (unsigned int)shapeData) )
      v53 = shapeData;
    if ( pFont->IsHintedVectorGlyph(pFont, glyphIndex, (unsigned int)shapeData) )
      v54 = shapeData;
  }
  v13 = fauxItalic | (fauxBold ? 2 : 0);
  y1 = *(float *)&v13;
  if ( *(float *)&v13 == 0.0 && !v54 && !v53 && *(float *)&outline == 0.0 && !needsVectorShape )
  {
    v14 = pFont->GetPermanentGlyphShape(pFont, glyphIndex);
    data->pShape = v14;
    if ( v14 )
    {
      ((void (__thiscall *)(Scaleform::Render::Font *, unsigned int, float))pFont->GetGlyphBounds)(
        pFont,
        glyphIndex,
        COERCE_FLOAT(LODWORD(y2)));
      return 0;
    }
    LOBYTE(v13) = LOBYTE(y1);
  }
  pFontHandle = data->pFontHandle;
  key.GlyphIndex = glyphIndex;
  key.pFont = pFontHandle;
  key.HintedRaster = (unsigned __int8)v53;
  key.HintedVector = (unsigned __int8)v54;
  key.Flags = v13 & 3;
  key.Outline = outline;
  p_VectorGlyphCache = &this->VectorGlyphCache;
  v17 = Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor>>::GetAlt<Scaleform::Render::VectorGlyphKey>(
          &this->VectorGlyphCache,
          &key);
  v18 = v17;
  if ( v17 )
  {
    pObject = v17->pObject;
    v18->pObject->pPrev->pNext = v18->pObject->pNext;
    pObject->pNext->pPrev = pObject->pPrev;
    pObject->pPrev = this->VectorGlyphShapeList.Root.pPrev;
    pObject->pNext = (Scaleform::Render::VectorGlyphShape *)&this->Notifier;
    this->VectorGlyphShapeList.Root.pPrev->pNext = pObject;
    this->VectorGlyphShapeList.Root.pPrev = pObject;
    data->VectorSize = v18->pObject->Key.HintedVector;
    data->RasterSize = v18->pObject->Key.HintedRaster;
    data->pShape = v18->pObject->pShape.pObject;
    v20 = (float *)LODWORD(y2);
    data->pRaster = v18->pObject->pRaster.pObject;
    v21 = v18->pObject;
    v22 = v18->pObject->__vftable;
    y1 = v18->pObject->Bounds.y1;
    p_VectorGlyphCache = (Scaleform::HashSetLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,2,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor> > *)LODWORD(v21->Bounds.x2);
    shapeData = (const Scaleform::Render::ShapeDataInterface *)LODWORD(v21->Bounds.y2);
    *v20 = v21->Bounds.x1;
    v20[1] = y1;
    v20[2] = *(float *)&p_VectorGlyphCache;
    v20[3] = *(float *)&shapeData;
    v22->AddRef(&v21->Scaleform::Render::MeshProvider);
    return v18->pObject;
  }
  else
  {
    pTable = p_VectorGlyphCache->pTable;
    if ( p_VectorGlyphCache->pTable )
      pTable = (Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor> >::TableType *)pTable->EntryCount;
    if ( (unsigned int)pTable > this->Param.MaxVectorCacheSize )
    {
      v24 = p_VectorGlyphCache->pTable;
      pNext = this->VectorGlyphShapeList.Root.pNext;
      v52 = pNext;
      if ( v24 )
        v24 = (Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor> >::TableType *)v24->EntryCount;
      MaxVectorCacheSize = this->Param.MaxVectorCacheSize;
      v27 = (unsigned int)v24 - MaxVectorCacheSize;
      LODWORD(y2) = (char *)v24 - MaxVectorCacheSize;
      if ( (unsigned int)v24 - MaxVectorCacheSize > MaxVectorCacheSize )
      {
        v27 = MaxVectorCacheSize;
        y2 = *(float *)&MaxVectorCacheSize;
      }
      *(float *)&shapeData = 0.0;
      if ( v27 )
      {
        do
        {
          if ( this == (Scaleform::Render::GlyphCache *)-2960 )
            p_Notifier = 0;
          else
            p_Notifier = &this->Notifier;
          if ( pNext == (Scaleform::Render::VectorGlyphShape *)p_Notifier )
            break;
          v29 = pNext->pNext;
          p_pNext = &pNext->pNext;
          p_pKeySet = &pNext->hKeySet.pKeySet;
          LODWORD(v60) = v29;
          if ( !*p_pKeySet || (*p_pKeySet)->Meshes.Root.pNext == (Scaleform::Render::MeshKey *)&(*p_pKeySet)->Meshes )
          {
            v32 = v52;
            v52->pPrev->pNext = *p_pNext;
            (*p_pNext)->pPrev = v32->pPrev;
            Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor>>::RemoveAlt<Scaleform::Render::VectorGlyphShape *>(
              p_VectorGlyphCache,
              &v52);
            v27 = LODWORD(y2);
          }
          pNext = (Scaleform::Render::VectorGlyphShape *)v60;
          v52 = (Scaleform::Render::VectorGlyphShape *)v60;
          shapeData = (const Scaleform::Render::ShapeDataInterface *)((char *)shapeData + 1);
        }
        while ( (unsigned int)shapeData < v27 );
      }
    }
    v33 = (Scaleform::Render::VectorGlyphShape *)this->pHeap->Alloc(this->pHeap, 80, 0);
    if ( v33 )
    {
      Scaleform::Render::VectorGlyphShape::VectorGlyphShape(v33, this);
      v35 = v34;
    }
    else
    {
      v35 = 0;
    }
    v36 = (unsigned __int8)v54;
    v35->Key.pFont = data->pFontHandle;
    v37 = (unsigned __int8)v53;
    v35->Key.GlyphIndex = glyphIndex;
    v38 = LOBYTE(y1);
    v35->Key.HintedVector = v36;
    v35->Key.HintedRaster = v37;
    v35->Key.Flags = v38;
    v35->Key.Outline = (unsigned __int8)outline;
    pHeap = this->pHeap;
    Alloc = pHeap->Alloc;
    v52 = v35;
    v41 = (Scaleform::Render::GlyphShape *)Alloc(pHeap, 96u, 0);
    if ( v41 )
    {
      Scaleform::Render::GlyphShape::GlyphShape(v41);
      y1 = v42;
    }
    else
    {
      y1 = 0.0;
    }
    v43 = (Scaleform::RefCountVImpl *)v35->pShape.pObject;
    if ( v43 )
      Scaleform::RefCountImpl::Release(v43);
    v44 = v53 == 0;
    *(float *)&v35->pShape.pObject = y1;
    if ( !v44 )
    {
      v45 = COERCE_FLOAT((int)this->pHeap->Alloc(this->pHeap, 40, 0));
      if ( v45 == 0.0 )
      {
        y1 = 0.0;
      }
      else
      {
        *(_DWORD *)(LODWORD(v45) + 4) = 1;
        *(_DWORD *)LODWORD(v45) = &Scaleform::Render::GlyphRaster::`vftable';
        *(_DWORD *)(LODWORD(v45) + 8) = 0;
        *(_DWORD *)(LODWORD(v45) + 12) = 0;
        *(_DWORD *)(LODWORD(v45) + 16) = 0;
        *(_DWORD *)(LODWORD(v45) + 20) = 0;
        *(_DWORD *)(LODWORD(v45) + 24) = 0;
        *(_DWORD *)(LODWORD(v45) + 28) = 0;
        *(_DWORD *)(LODWORD(v45) + 32) = 0;
        *(_DWORD *)(LODWORD(v45) + 36) = 0;
        y1 = v45;
      }
      v46 = v35->pRaster.pObject;
      if ( v46 )
        Scaleform::RefCountNTSImpl::Release(v46);
      *(float *)&v35->pRaster.pObject = y1;
    }
    *(float *)&shapeData = 0.0;
    if ( !v54 )
      *(float *)&shapeData = COERCE_FLOAT((*(int (__thiscall **)(float *, unsigned int))(*(_DWORD *)v55 + 56))(v55, glyphIndex));
    y1 = v55[3];
    if ( *(float *)&shapeData == 0.0 )
    {
      if ( fauxBold || fauxItalic || *(float *)&outline != 0.0 )
      {
        v47 = (Scaleform::Render::GlyphShape *)this->pHeap->Alloc(this->pHeap, 96, 0);
        if ( v47 )
        {
          Scaleform::Render::GlyphShape::GlyphShape(v47);
          shapeData = v48;
        }
        else
        {
          *(float *)&shapeData = 0.0;
        }
        (*(void (__thiscall **)(float *, unsigned int, const Scaleform::Render::ShapeDataInterface *, const Scaleform::Render::ShapeDataInterface *))(*(_DWORD *)v55 + 60))(
          v55,
          glyphIndex,
          v54,
          shapeData);
        Scaleform::Render::GlyphCache::getGlyphBounds(this, v35, shapeData);
        Scaleform::Render::GlyphCache::copyAndTransformShape(
          this,
          v35,
          shapeData,
          fauxBold,
          fauxItalic,
          outline,
          y1,
          data->NomHeight);
        if ( *(float *)&shapeData != 0.0 )
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)shapeData);
      }
      else
      {
        Scaleform::Render::GlyphShape::Clear(v35->pShape.pObject);
        (*(void (__thiscall **)(float *, unsigned int, const Scaleform::Render::ShapeDataInterface *, Scaleform::Render::GlyphShape *))(*(_DWORD *)v55 + 60))(
          v55,
          glyphIndex,
          v54,
          v35->pShape.pObject);
        Scaleform::Render::GlyphCache::getGlyphBounds(this, v35, v35->pShape.pObject);
      }
    }
    else
    {
      (*(void (__thiscall **)(float *, unsigned int, Scaleform::Render::Rect<float> *))(*(_DWORD *)v55 + 28))(
        v55,
        glyphIndex,
        &v35->Bounds);
      Scaleform::Render::GlyphCache::copyAndTransformShape(
        this,
        v35,
        shapeData,
        fauxBold,
        fauxItalic,
        outline,
        y1,
        data->NomHeight);
    }
    v49 = (unsigned int)v53;
    if ( v53 )
    {
      (*(void (__thiscall **)(float *, unsigned int, const Scaleform::Render::ShapeDataInterface *, Scaleform::Render::GlyphRaster *))(*(_DWORD *)v55 + 64))(
        v55,
        glyphIndex,
        v53,
        v35->pRaster.pObject);
      v50 = v53;
      v35->pRaster.pObject->HintedSize = (unsigned int)v53;
      v49 = (unsigned int)v50;
    }
    v51 = (unsigned int)v54;
    *(float *)&v60 = v35->Bounds.y1;
    y1 = v35->Bounds.x2;
    y2 = v35->Bounds.y2;
    data->GlyphBounds.x1 = v35->Bounds.x1;
    data->GlyphBounds.y1 = *(float *)&v60;
    data->GlyphBounds.x2 = y1;
    data->GlyphBounds.y2 = y2;
    data->VectorSize = v51;
    data->RasterSize = v49;
    data->pShape = v35->pShape.pObject;
    data->pRaster = v35->pRaster.pObject;
    data->HintedNomHeight = v35->pShape.pObject->HintedSize;
    v35->pPrev = this->VectorGlyphShapeList.Root.pPrev;
    v35->pNext = (Scaleform::Render::VectorGlyphShape *)&this->Notifier;
    this->VectorGlyphShapeList.Root.pPrev->pNext = v35;
    this->VectorGlyphShapeList.Root.pPrev = v35;
    Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor>>::add<Scaleform::Render::VectorGlyphShape *>(
      p_VectorGlyphCache,
      p_VectorGlyphCache,
      &v52,
      (int)v35->Key.pFont
    ^ ((unsigned int)v35->Key.pFont >> 6)
    ^ v35->Key.GlyphIndex
    ^ v35->Key.HintedVector
    ^ v35->Key.HintedRaster
    ^ v35->Key.Flags
    ^ v35->Key.Outline);
    return v35;
  }
}
