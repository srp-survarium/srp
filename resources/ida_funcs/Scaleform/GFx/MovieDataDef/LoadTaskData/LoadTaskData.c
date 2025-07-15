void __thiscall Scaleform::GFx::MovieDataDef::LoadTaskData::LoadTaskData(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this,
        Scaleform::GFx::MovieDataDef *pdataDef,
        char *purl,
        Scaleform::MemoryHeap *pheap)
{
  Scaleform::MemoryHeap *v5; // ecx
  Scaleform::GFx::PathAllocator *v6; // eax
  Scaleform::GFx::PathAllocator *v7; // eax
  void *v8; // edi
  Scaleform::GFx::LoadUpdateSync *v9; // eax
  Scaleform::GFx::LoadUpdateSync *v10; // edi
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::GFx::SpriteDef *v12; // eax
  Scaleform::GFx::SpriteDef *v13; // eax
  Scaleform::GFx::SpriteDef *v14; // edi
  Scaleform::GFx::TextFieldDef *v15; // eax
  Scaleform::GFx::TextFieldDef *v16; // eax
  Scaleform::GFx::TextFieldDef *v17; // edi
  Scaleform::GFx::ButtonDef *v18; // eax
  Scaleform::GFx::MovieDataDef *v19; // eax
  Scaleform::GFx::SwfShapeCharacterDef *v20; // ebp
  Scaleform::GFx::ShapeDataBase *v21; // eax
  Scaleform::GFx::ShapeDataBase *v22; // edi
  Scaleform::GFx::ShapeDataBase *v23; // eax
  Scaleform::RefCountVImpl *v24; // edi
  Scaleform::GFx::Resource *v25; // eax
  Scaleform::GFx::Resource *v26; // ebp
  _DWORD *v27; // eax
  _DWORD *v28; // edi
  char v29; // [esp+3Ch] [ebp-8h]
  Scaleform::String url; // [esp+40h] [ebp-4h] BYREF
  Scaleform::GFx::MovieDataDef *pdataDefa; // [esp+48h] [ebp+4h]
  Scaleform::GFx::Resource *purla; // [esp+4Ch] [ebp+8h]
  char pheapa; // [esp+50h] [ebp+Ch]
  Scaleform::GFx::Resource *pheapb; // [esp+50h] [ebp+Ch]

  this->__vftable = (Scaleform::GFx::MovieDataDef::LoadTaskData_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->TagMemAllocator.pHeap = pheap;
  this->TagMemAllocator.pAllocations = 0;
  this->TagMemAllocator.pCurrent = 0;
  this->TagMemAllocator.BytesLeft = 0;
  this->pPathAllocator = 0;
  this->__vftable = (Scaleform::GFx::MovieDataDef::LoadTaskData_vtbl *)&Scaleform::GFx::MovieDataDef::LoadTaskData::`vftable';
  this->pHeap = pheap;
  v29 = 0;
  this->pImageHeap.pObject = 0;
  Scaleform::StringLH::StringLH(&this->FileURL, purl);
  Scaleform::GFx::MovieHeaderData::MovieHeaderData(&this->Header);
  this->pFrameUpdate.pObject = 0;
  this->BindData.pFrameData.Value = 0;
  this->BindData.pFrameDataLast = 0;
  this->BindData.pImports.Value = 0;
  this->BindData.pImportsLast = 0;
  this->BindData.pFonts.Value = 0;
  this->BindData.pFontsLast = 0;
  this->BindData.pResourceNodes.Value = 0;
  this->BindData.pResourceNodesLast = 0;
  Scaleform::Lock::Lock(&this->ResourceLock, 0);
  this->pExtMovieDef.pObject = 0;
  this->Resources.mHash.pTable = 0;
  this->Exports.mHash.pTable = 0;
  this->InvExports.mHash.pTable = 0;
  Scaleform::Lock::Lock(&this->PlaylistLock, 0);
  this->Playlist.Data.Data = 0;
  this->Playlist.Data.Size = 0;
  this->Playlist.Data.Policy.Capacity = 0;
  this->InitActionList.Data.Data = 0;
  this->InitActionList.Data.Size = 0;
  this->InitActionList.Data.Policy.Capacity = 0;
  this->NamedFrames.mHash.pTable = 0;
  this->GradientIdGenerator.Id = (unsigned int)&loc_50000;
  this->pSoundStream = 0;
  this->Scenes.pObject = 0;
  this->Scenes.Owner = 1;
  v5 = this->pHeap;
  this->FileAttributes = 0;
  this->pMetadata = 0;
  this->MetadataSize = 0;
  v6 = (Scaleform::GFx::PathAllocator *)v5->Alloc(v5, 12u, 0);
  if ( v6 )
    Scaleform::GFx::PathAllocator::PathAllocator(v6, 0x2000u);
  else
    v7 = 0;
  this->pPathAllocator = v7;
  this->LoadingCanceled = 0;
  this->LoadState = LS_Uninitialized;
  this->LoadingFrame = 0;
  this->TagCount = 0;
  this->ResIndexCounter = 0;
  this->InitActionsCnt = 0;
  if ( pdataDef->MovieType != MT_Image
    || (Scaleform::String::String(&url, purl),
        v29 = 1,
        pheapa = 0,
        !Scaleform::GFx::LoaderImpl::IsProtocolImage(&url, 0, 0)) )
  {
    pheapa = 1;
  }
  if ( (v29 & 1) != 0 )
  {
    v29 &= ~1u;
    v8 = (void *)(url.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((url.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
  }
  if ( pheapa )
  {
    v9 = (Scaleform::GFx::LoadUpdateSync *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 36, 0);
    v10 = v9;
    if ( v9 )
    {
      v9->__vftable = (Scaleform::GFx::LoadUpdateSync_vtbl *)&Scaleform::RefCountImplCore::`vftable';
      v9->RefCount = 1;
      v9->__vftable = (Scaleform::GFx::LoadUpdateSync_vtbl *)&Scaleform::GFx::LoadUpdateSync::`vftable';
      Scaleform::Mutex::Mutex(&v9->mMutex, 1, 0);
      Scaleform::WaitCondition::WaitCondition(&v10->WC);
      v10->LoadFinished = 0;
    }
    else
    {
      v10 = 0;
    }
    pObject = (Scaleform::RefCountVImpl *)this->pFrameUpdate.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    this->pFrameUpdate.pObject = v10;
  }
  v12 = (Scaleform::GFx::SpriteDef *)this->pHeap->Alloc(this->pHeap, 56, 0);
  if ( v12 )
  {
    Scaleform::GFx::SpriteDef::SpriteDef(v12, pdataDef);
    v14 = v13;
    purla = v13;
  }
  else
  {
    purla = 0;
    v14 = 0;
  }
  Scaleform::GFx::SpriteDef::InitEmptyClipDef(v14);
  Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(this, (Scaleform::GFx::ResourceId)65537, v14);
  v15 = (Scaleform::GFx::TextFieldDef *)this->pHeap->Alloc(this->pHeap, 96, 0);
  if ( v15 )
  {
    Scaleform::GFx::TextFieldDef::TextFieldDef(v15);
    v17 = v16;
    pheapb = v16;
  }
  else
  {
    pheapb = 0;
    v17 = 0;
  }
  Scaleform::GFx::TextFieldDef::InitEmptyTextDef(v17);
  Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(
    this,
    (Scaleform::GFx::ResourceId)((char *)&_sbh_sizeHeaderList.unused + 2),
    v17);
  v18 = (Scaleform::GFx::ButtonDef *)this->pHeap->Alloc(this->pHeap, 52, 0);
  if ( v18 )
  {
    Scaleform::GFx::ButtonDef::ButtonDef(v18);
    pdataDefa = v19;
  }
  else
  {
    pdataDefa = 0;
  }
  Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(this, (Scaleform::GFx::ResourceId)65539, pdataDefa);
  v20 = (Scaleform::GFx::SwfShapeCharacterDef *)this->pHeap->Alloc(this->pHeap, 24, 0);
  if ( v20 )
  {
    v21 = (Scaleform::GFx::ShapeDataBase *)this->pHeap->Alloc(this->pHeap, 16, 0);
    v22 = v21;
    if ( v21 )
    {
      Scaleform::GFx::ShapeDataBase::ShapeDataBase(v21, Empty_Shape);
      v22->__vftable = (Scaleform::GFx::ShapeDataBase_vtbl *)&Scaleform::GFx::ConstShapeNoStyles::`vftable';
      v23 = v22;
    }
    else
    {
      v23 = 0;
    }
    v29 |= 2u;
    v24 = (Scaleform::RefCountVImpl *)v23;
    Scaleform::GFx::SwfShapeCharacterDef::SwfShapeCharacterDef(v20, v23);
    v26 = v25;
  }
  else
  {
    v24 = (Scaleform::RefCountVImpl *)pdataDefa;
    v26 = 0;
  }
  if ( (v29 & 2) != 0 && v24 )
    Scaleform::RefCountImpl::Release(v24);
  Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(this, (Scaleform::GFx::ResourceId)&unk_10004, v26);
  v27 = this->pHeap->Alloc(this->pHeap, 32, 0);
  if ( v27 )
  {
    *v27 = &Scaleform::GFx::Resource::`vftable';
    v27[1] = 1;
    v27[2] = 0;
    v27[3] = 0x40000;
    *v27 = &Scaleform::GFx::Video::VideoCharacterDef::`vftable';
    v27[4] = 0;
    v27[5] = 0;
    v27[6] = 0;
    *((_BYTE *)v27 + 28) = 0;
    *((_BYTE *)v27 + 29) = 0;
    *((_BYTE *)v27 + 30) = 2;
    v28 = v27;
  }
  else
  {
    v28 = 0;
  }
  v28[4] = 0;
  v28[5] = 0;
  v28[6] = 0;
  *((_BYTE *)v28 + 28) = 0;
  *((_BYTE *)v28 + 29) = 0;
  *((_BYTE *)v28 + 30) = 2;
  Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(
    this,
    (Scaleform::GFx::ResourceId)65541,
    (Scaleform::GFx::Resource *)v28);
  Scaleform::GFx::Resource::Release((Scaleform::GFx::Resource *)v28);
  if ( v26 )
    Scaleform::GFx::Resource::Release(v26);
  if ( pdataDefa )
    Scaleform::GFx::Resource::Release(pdataDefa);
  if ( pheapb )
    Scaleform::GFx::Resource::Release(pheapb);
  if ( purla )
    Scaleform::GFx::Resource::Release(purla);
}
