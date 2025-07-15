void __thiscall Scaleform::Render::TextMeshProvider::sortEntries(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::TmpTextStorage *storage)
{
  unsigned int v3; // esi
  unsigned int v4; // ecx
  Scaleform::Render::TmpTextMeshEntry **Pages; // edx
  int v6; // edi
  int v7; // eax
  unsigned int Size; // esi
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // ebx
  Scaleform::Render::MatrixPoolImpl::DataHeader *v10; // eax
  Scaleform::ArrayDataBase<Scaleform::Render::TextMeshEntry,Scaleform::AllocatorDH<Scaleform::Render::TextMeshEntry,2>,Scaleform::ArrayDefaultPolicy> *v11; // edi
  Scaleform::RefCountNTSImpl **p_pObject; // ecx
  Scaleform::RefCountNTSImpl *v13; // ecx
  bool v14; // zf
  int v15; // eax
  unsigned int i; // esi
  unsigned int v17; // edi
  Scaleform::Render::MatrixPoolImpl::DataHeader *v18; // ebx
  Scaleform::Render::MatrixPoolImpl::DataHeader *v19; // eax
  Scaleform::ArrayDataBase<Scaleform::Render::TextMeshLayer,Scaleform::AllocatorDH<Scaleform::Render::TextMeshLayer,2>,Scaleform::ArrayDefaultPolicy> *v20; // esi
  unsigned int v21; // edi
  Scaleform::Render::TextMeshLayer *v22; // eax
  unsigned int v23; // ebx
  char *v24; // esi
  Scaleform::Render::TmpTextMeshEntry *v25; // edi
  Scaleform::RefCountNTSImpl *v26; // ecx
  char *v27; // esi
  Scaleform::Render::TmpTextMeshLayer *v28; // edi
  Scaleform::RefCountVImpl *v29; // ecx
  Scaleform::Render::PrimitiveFill *v30; // edi
  Scaleform::RefCountNTSImpl *v31; // ecx
  Scaleform::Render::MatrixPoolImpl::HMatrix other; // [esp+10h] [ebp-10h] BYREF
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v33; // [esp+14h] [ebp-Ch]
  const void *pFill; // [esp+18h] [ebp-8h]
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v35; // [esp+1Ch] [ebp-4h]
  Scaleform::Render::TmpTextStorage *storagea; // [esp+24h] [ebp+4h]
  Scaleform::Render::TmpTextStorage *storageb; // [esp+24h] [ebp+4h]
  Scaleform::Render::TmpTextStorage *storagec; // [esp+24h] [ebp+4h]
  Scaleform::Render::TmpTextStorage *storaged; // [esp+24h] [ebp+4h]

  v3 = 0;
  other.pHandle = (Scaleform::Render::MatrixPoolImpl::EntryHandle *)this;
  storage->Layers.Size = 0;
  Scaleform::Alg::QuickSortSliced<Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4>,Scaleform::Render::TextMeshProvider::CmpEntries>(
    &storage->Entries,
    0,
    storage->Entries.Size);
  v4 = 0;
  if ( storage->Entries.Size )
  {
    do
    {
      Pages = storage->Entries.Pages;
      v6 = (int)&Pages[v3 >> 6][v3 & 0x3F];
      v7 = (int)&Pages[v4 >> 6][v4 & 0x3F];
      if ( (*(_WORD *)v7 != *(_WORD *)v6 || *(_DWORD *)(v7 + 12) != *(_DWORD *)(v6 + 12)) && v3 > v4 )
      {
        Scaleform::Render::TextMeshProvider::addLayer(
          (Scaleform::Render::TextMeshProvider *)other.pHandle,
          storage,
          v4,
          v3);
        v4 = v3;
      }
      ++v3;
    }
    while ( v3 < storage->Entries.Size );
    if ( v3 > v4 )
      Scaleform::Render::TextMeshProvider::addLayer(
        (Scaleform::Render::TextMeshProvider *)other.pHandle,
        storage,
        v4,
        v3);
  }
  Size = storage->Entries.Size;
  pHeader = other.pHandle[10].pHeader;
  v10 = other.pHandle[12].pHeader;
  v11 = (Scaleform::ArrayDataBase<Scaleform::Render::TextMeshEntry,Scaleform::AllocatorDH<Scaleform::Render::TextMeshEntry,2>,Scaleform::ArrayDefaultPolicy> *)&other.pHandle[9];
  v35 = other.pHandle + 9;
  pFill = v10;
  if ( Size >= (unsigned int)pHeader )
  {
    if ( (Scaleform::Render::MatrixPoolImpl::DataHeader *)Size >= other.pHandle[11].pHeader )
      Scaleform::ArrayDataBase<Scaleform::Render::TextMeshEntry,Scaleform::AllocatorDH<Scaleform::Render::TextMeshEntry,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v11,
        v10,
        Size + (Size >> 2));
  }
  else
  {
    p_pObject = &v11->Data[(int)pHeader - 1].pFill.pObject;
    storagea = (Scaleform::Render::TmpTextStorage *)p_pObject;
    v33 = (Scaleform::Render::MatrixPoolImpl::EntryHandle *)((char *)pHeader - Size);
    do
    {
      v13 = *p_pObject;
      if ( v13 )
        Scaleform::RefCountNTSImpl::Release(v13);
      p_pObject = (Scaleform::RefCountNTSImpl **)&storagea[-1].Entries.NumPages;
      v14 = v33 == (Scaleform::Render::MatrixPoolImpl::EntryHandle *)1;
      v33 = (Scaleform::Render::MatrixPoolImpl::EntryHandle *)((char *)v33 - 1);
      storagea = (Scaleform::Render::TmpTextStorage *)((char *)storagea - 32);
    }
    while ( !v14 );
    if ( Size < (unsigned int)other.pHandle[11].pHeader >> 1 )
      Scaleform::ArrayDataBase<Scaleform::Render::TextMeshEntry,Scaleform::AllocatorDH<Scaleform::Render::TextMeshEntry,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v11,
        pFill,
        Size);
  }
  other.pHandle[10].pHeader = (Scaleform::Render::MatrixPoolImpl::DataHeader *)Size;
  if ( Size > (unsigned int)pHeader )
  {
    v15 = (int)&v11->Data[(_DWORD)pHeader];
    for ( i = Size - (_DWORD)pHeader; i; --i )
    {
      if ( v15 )
        *(_DWORD *)(v15 + 8) = 0;
      v15 += 32;
    }
  }
  v17 = storage->Layers.Size;
  v18 = other.pHandle[14].pHeader;
  v19 = other.pHandle[16].pHeader;
  v20 = (Scaleform::ArrayDataBase<Scaleform::Render::TextMeshLayer,Scaleform::AllocatorDH<Scaleform::Render::TextMeshLayer,2>,Scaleform::ArrayDefaultPolicy> *)&other.pHandle[13];
  v33 = other.pHandle + 13;
  storageb = (Scaleform::Render::TmpTextStorage *)v19;
  if ( v17 >= (unsigned int)v18 )
  {
    if ( (Scaleform::Render::MatrixPoolImpl::DataHeader *)v17 >= other.pHandle[15].pHeader )
      Scaleform::ArrayDataBase<Scaleform::Render::TextMeshLayer,Scaleform::AllocatorDH<Scaleform::Render::TextMeshLayer,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v20,
        v19,
        v17 + (v17 >> 2));
  }
  else
  {
    Scaleform::ConstructorMov<Scaleform::Render::TextMeshLayer>::DestructArray(&v20->Data[v17], (unsigned int)v18 - v17);
    if ( v17 < (unsigned int)other.pHandle[15].pHeader >> 1 )
      Scaleform::ArrayDataBase<Scaleform::Render::TextMeshLayer,Scaleform::AllocatorDH<Scaleform::Render::TextMeshLayer,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v20,
        storageb,
        v17);
  }
  other.pHandle[14].pHeader = (Scaleform::Render::MatrixPoolImpl::DataHeader *)v17;
  if ( v17 > (unsigned int)v18 && (v21 = v17 - (_DWORD)v18, v22 = &v20->Data[(_DWORD)v18], v21) )
  {
    do
    {
      v23 = 0;
      if ( v22 )
      {
        v22->pMesh.pObject = 0;
        v22->pMeshKey.pObject = 0;
        v22->pShape.pObject = 0;
        v22->M.pHandle = &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle;
        v22->pFill.pObject = 0;
      }
      ++v22;
      --v21;
    }
    while ( v21 );
  }
  else
  {
    v23 = 0;
  }
  if ( storage->Entries.Size )
  {
    storagec = 0;
    do
    {
      v24 = (char *)storagec + (unsigned int)v35->pHeader;
      v25 = &storage->Entries.Pages[v23 >> 6][v23 & 0x3F];
      *(_WORD *)v24 = v25->LayerType;
      *((_WORD *)v24 + 1) = v25->TextureId;
      *((_DWORD *)v24 + 1) = v25->mColor;
      v26 = (Scaleform::RefCountNTSImpl *)*((_DWORD *)v24 + 2);
      pFill = v25->pFill;
      if ( v26 )
        Scaleform::RefCountNTSImpl::Release(v26);
      storagec = (Scaleform::Render::TmpTextStorage *)((char *)storagec + 32);
      *((_DWORD *)v24 + 2) = pFill;
      *((_DWORD *)v24 + 3) = v25->EntryData.VectorData.pFont;
      *((_DWORD *)v24 + 4) = LODWORD(v25->EntryData.RasterData.Coord[1]);
      *((_DWORD *)v24 + 5) = LODWORD(v25->EntryData.RasterData.Coord[2]);
      *((_DWORD *)v24 + 6) = LODWORD(v25->EntryData.RasterData.Coord[3]);
      ++v23;
      *((_DWORD *)v24 + 7) = v25->EntryData.RasterData.pGlyph;
    }
    while ( v23 < storage->Entries.Size );
    v20 = (Scaleform::ArrayDataBase<Scaleform::Render::TextMeshLayer,Scaleform::AllocatorDH<Scaleform::Render::TextMeshLayer,2>,Scaleform::ArrayDefaultPolicy> *)v33;
    v23 = 0;
  }
  if ( storage->Layers.Size )
  {
    storaged = 0;
    while ( 1 )
    {
      v27 = (char *)storaged + (unsigned int)v20->Data;
      v28 = &storage->Layers.Pages[v23 >> 4][v23 & 0xF];
      *(_DWORD *)v27 = v28->Type;
      *((_DWORD *)v27 + 1) = v28->Start;
      *((_DWORD *)v27 + 2) = v28->Count;
      v29 = (Scaleform::RefCountVImpl *)*((_DWORD *)v27 + 3);
      if ( v29 )
        Scaleform::RefCountImpl::Release(v29);
      *((_DWORD *)v27 + 3) = 0;
      other.pHandle = &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle;
      Scaleform::Render::MatrixPoolImpl::HMatrix::operator=(
        (Scaleform::Render::MatrixPoolImpl::HMatrix *)v27 + 6,
        &other);
      if ( other.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
        Scaleform::Render::MatrixPoolImpl::DataHeader::Release(other.pHandle->pHeader);
      v30 = v28->pFill;
      if ( v30 )
        ++v30->RefCount;
      v31 = (Scaleform::RefCountNTSImpl *)*((_DWORD *)v27 + 7);
      if ( v31 )
        Scaleform::RefCountNTSImpl::Release(v31);
      storaged = (Scaleform::Render::TmpTextStorage *)((char *)storaged + 36);
      *((_DWORD *)v27 + 7) = v30;
      *((float *)v27 + 8) = 1.0;
      if ( ++v23 >= storage->Layers.Size )
        break;
      v20 = (Scaleform::ArrayDataBase<Scaleform::Render::TextMeshLayer,Scaleform::AllocatorDH<Scaleform::Render::TextMeshLayer,2>,Scaleform::ArrayDefaultPolicy> *)v33;
    }
  }
}
