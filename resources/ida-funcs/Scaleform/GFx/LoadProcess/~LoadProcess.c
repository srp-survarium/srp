void __thiscall Scaleform::GFx::LoadProcess::~LoadProcess(Scaleform::GFx::LoadProcess *this)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::GFx::MovieDataDef::LoadTaskData *v3; // eax
  Scaleform::GFx::LoadUpdateSync *v4; // edi
  Scaleform::RefCountVImpl *v5; // ecx
  Scaleform::RefCountVImpl *v6; // ecx
  Scaleform::AmpServer *Instance; // eax
  Scaleform::RefCountVImpl *v8; // ecx
  Scaleform::Array<Scaleform::GFx::ExecuteTag *,2,Scaleform::ArrayConstPolicy<32,16,0> > *p_InitActionTags; // edi
  int i; // ebx
  Scaleform::GFx::ExecuteTag **Data; // eax
  Scaleform::RefCountVImpl *v12; // ecx
  Scaleform::RefCountVImpl *v13; // ecx
  Scaleform::RefCountVImpl *v14; // ecx

  this->Scaleform::GFx::LoaderTask::Scaleform::GFx::Task::Scaleform::RefCountBase<Scaleform::GFx::Task,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::GFx::LoadProcess_vtbl *)&Scaleform::GFx::LoadProcess::`vftable'{for `Scaleform::GFx::LoaderTask'};
  this->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::__vftable = (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>_vtbl *)&Scaleform::GFx::LoadProcess::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>'};
  pObject = (Scaleform::RefCountVImpl *)this->pJpegTables.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pJpegTables.pObject = 0;
  v3 = this->pLoadData.pObject;
  v4 = v3->pFrameUpdate.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v3->pFrameUpdate.pObject);
  Scaleform::GFx::Stream::ShutDown(&this->ProcessInfo.Stream);
  v5 = (Scaleform::RefCountVImpl *)this->pLoadData.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::Release(v5);
  this->pLoadData.pObject = 0;
  v6 = (Scaleform::RefCountVImpl *)this->pBindProcess.pObject;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  this->pBindProcess.pObject = 0;
  if ( v4 )
  {
    Scaleform::Mutex::DoLock(&v4->mMutex);
    v4->LoadFinished = 1;
    Scaleform::WaitCondition::NotifyAll(&v4->WC);
    Scaleform::Mutex::Unlock(&v4->mMutex);
  }
  Instance = Scaleform::AmpServer::GetInstance();
  Instance->RemoveLoadProcess(Instance, this);
  if ( v4 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v4);
  v8 = (Scaleform::RefCountVImpl *)this->LoadProcessStats.pObject;
  if ( v8 )
    Scaleform::RefCountImpl::Release(v8);
  if ( this->InitActionTags.Data.Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->InitActionTags.Data.Data);
  p_InitActionTags = &this->InitActionTags;
  for ( i = 1; i >= 0; --i )
  {
    Data = p_InitActionTags[-1].Data.Data;
    --p_InitActionTags;
    if ( Data )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
  }
  v12 = (Scaleform::RefCountVImpl *)this->pJpegTables.pObject;
  if ( v12 )
    Scaleform::RefCountImpl::Release(v12);
  Scaleform::GFx::ExporterInfoImpl::~ExporterInfoImpl(&this->ProcessInfo.Header.mExporterInfo);
  Scaleform::GFx::Stream::~Stream(&this->ProcessInfo.Stream);
  v13 = (Scaleform::RefCountVImpl *)this->pLoadData.pObject;
  if ( v13 )
    Scaleform::RefCountImpl::Release(v13);
  v14 = (Scaleform::RefCountVImpl *)this->pBindProcess.pObject;
  if ( v14 )
    Scaleform::RefCountImpl::Release(v14);
  this->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::__vftable = (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>_vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger>::`vftable';
  Scaleform::GFx::LoaderTask::~LoaderTask(this);
}
