void __thiscall Scaleform::GFx::AMP::Server::~Server(Scaleform::GFx::AMP::Server *this)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::RefCountVImpl *v3; // ecx
  Scaleform::RefCountVImpl *v4; // ecx
  Scaleform::RefCountVImpl *v5; // ecx
  Scaleform::RefCountVImpl *v6; // ecx
  Scaleform::RefCountVImpl *v7; // ecx

  this->Scaleform::RefCountBase<Scaleform::GFx::AMP::Server,579>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,579>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::GFx::AMP::Server_vtbl *)&Scaleform::GFx::AMP::Server::`vftable'{for `Scaleform::RefCountBase<Scaleform::GFx::AMP::Server,579>'};
  this->Scaleform::AmpServer::__vftable = (Scaleform::AmpServer_vtbl *)&Scaleform::GFx::AMP::Server::`vftable'{for `Scaleform::AmpServer'};
  pObject = (Scaleform::RefCountVImpl *)this->SocketThreadMgr.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->SocketThreadMgr.pObject = 0;
  this->ReportHeap->Release(this->ReportHeap);
  Scaleform::Lock::~Lock(&this->RecordingStateLock);
  v3 = (Scaleform::RefCountVImpl *)this->AppControlCaps.pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  v4 = (Scaleform::RefCountVImpl *)this->StatusCallback.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  v5 = (Scaleform::RefCountVImpl *)this->SendCallback.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::Release(v5);
  Scaleform::Lock::~Lock(&this->ObjectsReportLock);
  Scaleform::Event::~Event(&this->SendingEvent);
  Scaleform::Event::~Event(&this->ConnectedEvent);
  Scaleform::Lock::~Lock(&this->SourceFileLock);
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&this->HandleToSourceFileMap);
  Scaleform::Lock::~Lock(&this->SwfLock);
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SwdInfo>,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SwdInfo>,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SwdInfo>,Scaleform::FixedSizeHash<unsigned long>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SwdInfo>,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SwdInfo>,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SwdInfo>,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SwdInfo>,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SwdInfo>,Scaleform::FixedSizeHash<unsigned long>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SwdInfo>,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SwdInfo>,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF>>(&this->HandleToSwdIdMap.mHash);
  Scaleform::Lock::~Lock(&this->LoaderLock);
  v6 = (Scaleform::RefCountVImpl *)this->RenderStats.pObject;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Loaders.Data.Data);
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,2>,Scaleform::ArrayDefaultPolicy> *)&this->TaskStats);
  Scaleform::Lock::~Lock(&this->LoadProcessLock);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->LoadProcesses.Data.Data);
  Scaleform::Lock::~Lock(&this->ImageLock);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Images.Data.Data);
  Scaleform::Lock::~Lock(&this->MovieLock);
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,2>,Scaleform::ArrayDefaultPolicy> *)&this->MovieStats);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Movies.Data.Data);
  v7 = (Scaleform::RefCountVImpl *)this->SocketThreadMgr.pObject;
  if ( v7 )
    Scaleform::RefCountImpl::Release(v7);
  Scaleform::Lock::~Lock(&this->ToggleStateLock);
  Scaleform::Lock::~Lock(&this->CurrentStateLock);
  Scaleform::GFx::AMP::ServerState::~ServerState(&this->CurrentState);
  this->Scaleform::AmpServer::__vftable = (Scaleform::AmpServer_vtbl *)&Scaleform::AmpServer::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
