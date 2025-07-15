void __thiscall Scaleform::GFx::LoadProcess::LoadProcess(
        Scaleform::GFx::LoadProcess *this,
        Scaleform::GFx::MovieDataDef *pdataDef,
        int pstates,
        unsigned int loadFlags)
{
  int v5; // ecx
  int v6; // eax
  unsigned int v7; // eax
  Scaleform::GFx::Resource *pObject; // ecx
  Scaleform::RefCountVImpl *v9; // ecx
  unsigned int v10; // eax
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpServer *v12; // eax
  Scaleform::GFx::AMP::ViewStats *v13; // eax
  Scaleform::GFx::AMP::ViewStats *v14; // eax
  Scaleform::GFx::AMP::ViewStats *v15; // ebx
  Scaleform::RefCountVImpl *v16; // ecx
  Scaleform::AmpServer *v17; // eax

  Scaleform::GFx::LoaderTask::LoaderTask(this, (Scaleform::GFx::Resource *)pstates, Id_MovieDataLoad);
  this->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::__vftable = (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>_vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger>::`vftable';
  this->Scaleform::GFx::LoaderTask::Scaleform::GFx::Task::Scaleform::RefCountBase<Scaleform::GFx::Task,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::GFx::LoadProcess_vtbl *)&Scaleform::GFx::LoadProcess::`vftable'{for `Scaleform::GFx::LoaderTask'};
  this->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::__vftable = (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>_vtbl *)&Scaleform::GFx::LoadProcess::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>'};
  this->pBindProcess.pObject = 0;
  this->pLoadData.pObject = 0;
  Scaleform::GFx::Stream::Stream(&this->ProcessInfo.Stream, 0, pdataDef->pData.pObject->pHeap, 0, 0);
  Scaleform::GFx::MovieHeaderData::MovieHeaderData(&this->ProcessInfo.Header);
  v5 = pstates;
  this->ProcessInfo.FileAttributes = 0;
  this->pJpegTables.pObject = 0;
  this->FrameTags[0].Data.Data = 0;
  this->FrameTags[0].Data.Size = 0;
  this->FrameTags[0].Data.Policy.Capacity = 0;
  this->FrameTags[1].Data.Data = 0;
  this->FrameTags[1].Data.Size = 0;
  this->FrameTags[1].Data.Policy.Capacity = 0;
  this->InitActionTags.Data.Data = 0;
  this->InitActionTags.Data.Size = 0;
  this->InitActionTags.Data.Policy.Capacity = 0;
  this->LoadProcessStats.pObject = 0;
  v6 = *(_DWORD *)(v5 + 16);
  if ( v6 )
    v7 = *(_DWORD *)(v6 + 12);
  else
    v7 = 0;
  this->ParseFlags = v7;
  pObject = (Scaleform::GFx::Resource *)pdataDef->pData.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::AddRef(pObject);
  v9 = (Scaleform::RefCountVImpl *)this->pLoadData.pObject;
  if ( v9 )
    Scaleform::RefCountImpl::Release(v9);
  v10 = loadFlags;
  this->pLoadData.pObject = pdataDef->pData.pObject;
  this->pDataDef_Unsafe = pdataDef;
  this->pTimelineDef = 0;
  this->LoadFlags = v10;
  this->LoadState = LS_LoadingRoot;
  this->ImportIndex = 0;
  this->ImportDataCount = 0;
  this->ResourceDataCount = 0;
  this->FontDataCount = 0;
  this->pImportDataLast = 0;
  this->pImportData = 0;
  this->pResourceDataLast = 0;
  this->pResourceData = 0;
  this->pFontDataLast = 0;
  this->pFontData = 0;
  this->pAltStream = 0;
  this->pTempBindData = 0;
  this->ASInitActionTagsNum = 0;
  Instance = Scaleform::AmpServer::GetInstance();
  if ( Instance->IsEnabled(Instance) )
  {
    v12 = Scaleform::AmpServer::GetInstance();
    pstates = 2;
    v13 = (Scaleform::GFx::AMP::ViewStats *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                              Scaleform::Memory::pGlobalHeap,
                                              v12,
                                              288,
                                              &pstates);
    if ( v13 )
    {
      Scaleform::GFx::AMP::ViewStats::ViewStats(v13);
      v15 = v14;
    }
    else
    {
      v15 = 0;
    }
    v16 = (Scaleform::RefCountVImpl *)this->LoadProcessStats.pObject;
    if ( v16 )
      Scaleform::RefCountImpl::Release(v16);
    this->LoadProcessStats.pObject = v15;
    v17 = Scaleform::AmpServer::GetInstance();
    v17->AddLoadProcess(v17, this);
  }
}
