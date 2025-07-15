void __thiscall Scaleform::GFx::AMP::Server::Server(Scaleform::GFx::AMP::Server *this)
{
  Scaleform::MemoryHeap *v2; // eax
  Scaleform::MemoryHeap *(__thiscall *CreateHeap)(Scaleform::MemoryHeap *, const char *, const Scaleform::MemoryHeap::HeapDesc *); // edx
  Scaleform::GFx::AMP::SendThreadCallback *v4; // eax
  Scaleform::GFx::AMP::SendThreadCallback *v5; // edi
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::GFx::AMP::StatusChangedCallback *v7; // eax
  Scaleform::GFx::AMP::StatusChangedCallback *v8; // eax
  Scaleform::GFx::AMP::StatusChangedCallback *v9; // edi
  Scaleform::RefCountVImpl *v10; // ecx
  Scaleform::GFx::AMP::MessageAppControl *v11; // eax
  Scaleform::GFx::AMP::MessageAppControl *v12; // eax
  Scaleform::GFx::AMP::MessageAppControl *v13; // edi
  Scaleform::RefCountVImpl *v14; // ecx
  Scaleform::GFx::AMP::Server::RenderProfile *v15; // eax
  Scaleform::GFx::AMP::Server::RenderProfile *v16; // eax
  Scaleform::GFx::AMP::Server::RenderProfile *v17; // edi
  Scaleform::RefCountVImpl *v18; // ecx
  Scaleform::GFx::AMP::MessageTypeRegistry *v19; // eax
  Scaleform::GFx::AMP::MessageTypeRegistry *v20; // edi
  Scaleform::GFx::Resource *v21; // eax
  Scaleform::GFx::Resource *v22; // eax
  Scaleform::GFx::Resource *v23; // eax
  Scaleform::GFx::Resource *v24; // eax
  Scaleform::GFx::Resource *v25; // eax
  Scaleform::GFx::Resource *v26; // eax
  Scaleform::GFx::Resource *v27; // eax
  Scaleform::GFx::AMP::ThreadMgr *v28; // eax
  Scaleform::GFx::AMP::StatusChangedCallback *v29; // ecx
  Scaleform::GFx::AMP::ConnStatusInterface *v30; // edx
  Scaleform::GFx::AMP::SendThreadCallback *v31; // ecx
  Scaleform::GFx::AMP::SendInterface *v32; // ecx
  Scaleform::GFx::AMP::ThreadMgr *v33; // eax
  Scaleform::GFx::AMP::ThreadMgr *v34; // ebp
  Scaleform::RefCountVImpl *v35; // ecx
  int v36; // [esp+6Ch] [ebp-54h] BYREF
  int v37; // [esp+70h] [ebp-50h] BYREF
  int v38; // [esp+74h] [ebp-4Ch] BYREF
  int v39; // [esp+78h] [ebp-48h] BYREF
  int v40; // [esp+7Ch] [ebp-44h] BYREF
  int v41; // [esp+80h] [ebp-40h] BYREF
  int v42; // [esp+84h] [ebp-3Ch] BYREF
  int v43; // [esp+88h] [ebp-38h] BYREF
  int v44; // [esp+8Ch] [ebp-34h] BYREF
  int v45; // [esp+90h] [ebp-30h] BYREF
  int v46; // [esp+94h] [ebp-2Ch] BYREF
  int v47; // [esp+98h] [ebp-28h] BYREF
  int v48; // [esp+9Ch] [ebp-24h] BYREF
  _DWORD v49[8]; // [esp+A0h] [ebp-20h] BYREF

  this->Scaleform::RefCountBase<Scaleform::GFx::AMP::Server,579>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,579>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::GFx::AMP::Server_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->Scaleform::AmpServer::__vftable = (Scaleform::AmpServer_vtbl *)&Scaleform::AmpServer::`vftable';
  this->Scaleform::RefCountBase<Scaleform::GFx::AMP::Server,579>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,579>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::GFx::AMP::Server_vtbl *)&Scaleform::GFx::AMP::Server::`vftable'{for `Scaleform::RefCountBase<Scaleform::GFx::AMP::Server,579>'};
  this->Scaleform::AmpServer::__vftable = (Scaleform::AmpServer_vtbl *)&Scaleform::GFx::AMP::Server::`vftable'{for `Scaleform::AmpServer'};
  Scaleform::GFx::AMP::ServerState::ServerState(&this->CurrentState);
  Scaleform::Lock::Lock(&this->CurrentStateLock, 0);
  this->ToggleState = 0;
  this->ForceState = 0;
  this->PendingForceState = 0;
  this->PendingProfileLevel = -1;
  Scaleform::Lock::Lock(&this->ToggleStateLock, 0);
  this->Port = 7534;
  this->BroadcastPort = 7533;
  this->SocketThreadMgr.pObject = 0;
  this->Movies.Data.Data = 0;
  this->Movies.Data.Size = 0;
  this->Movies.Data.Policy.Capacity = 0;
  this->MovieStats.Data.Data = 0;
  this->MovieStats.Data.Size = 0;
  this->MovieStats.Data.Policy.Capacity = 0;
  Scaleform::Lock::Lock(&this->MovieLock, 0);
  this->Images.Data.Data = 0;
  this->Images.Data.Size = 0;
  this->Images.Data.Policy.Capacity = 0;
  Scaleform::Lock::Lock(&this->ImageLock, 0);
  this->LoadProcesses.Data.Data = 0;
  this->LoadProcesses.Data.Size = 0;
  this->LoadProcesses.Data.Policy.Capacity = 0;
  Scaleform::Lock::Lock(&this->LoadProcessLock, 0);
  this->TaskStats.Data.Data = 0;
  this->TaskStats.Data.Size = 0;
  this->TaskStats.Data.Policy.Capacity = 0;
  this->Loaders.Data.Data = 0;
  this->Loaders.Data.Size = 0;
  this->Loaders.Data.Policy.Capacity = 0;
  this->CurrentRenderer = 0;
  this->RenderStats.pObject = 0;
  Scaleform::Lock::Lock(&this->LoaderLock, 0);
  this->HandleToSwdIdMap.mHash.pTable = 0;
  Scaleform::Lock::Lock(&this->SwfLock, 0);
  this->HandleToSourceFileMap.mHash.pTable = 0;
  Scaleform::Lock::Lock(&this->SourceFileLock, 0);
  Scaleform::Event::Event(&this->ConnectedEvent, 0, 0);
  Scaleform::Event::Event(&this->SendingEvent, 0, 0);
  this->ConnectionWaitDelay = 0;
  this->InitSocketLib = 1;
  this->SocketFactory = 0;
  InterlockedExchange((volatile LONG *)&this->Profiling, 0);
  InterlockedExchange((volatile LONG *)&this->SoundMemory, 0);
  InterlockedExchange((volatile LONG *)&this->NumStrokes, 0);
  InterlockedExchange((volatile LONG *)&this->FontThrashing, 0);
  InterlockedExchange((volatile LONG *)&this->FontFailures, 0);
  InterlockedExchange((volatile LONG *)&this->MemReportLocked, 0);
  InterlockedExchange((volatile LONG *)&this->ProfileLevelLocked, 0);
  Scaleform::Lock::Lock(&this->ObjectsReportLock, 0);
  this->ObjectsReportRequested = 0;
  this->ObjectsReportFlags = 0;
  this->AppControlCallback = 0;
  this->SendCallback.pObject = 0;
  this->StatusCallback.pObject = 0;
  this->AppControlCaps.pObject = 0;
  this->RecordingState = Amp_Server_Recording_Off;
  Scaleform::Lock::Lock(&this->RecordingStateLock, 0);
  v2 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  CreateHeap = v2->CreateHeap;
  v49[2] = 0x4000;
  v49[3] = 0x4000;
  v49[0] = 4096;
  v49[1] = 16;
  v49[4] = -1;
  memset(&v49[5], 0, 12);
  this->ReportHeap = CreateHeap(v2, "Memory Report", (const Scaleform::MemoryHeap::HeapDesc *)v49);
  v36 = 579;
  v4 = (Scaleform::GFx::AMP::SendThreadCallback *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                    Scaleform::Memory::pGlobalHeap,
                                                    this,
                                                    12,
                                                    &v36);
  if ( v4 )
  {
    v4->Scaleform::RefCountBase<Scaleform::GFx::AMP::SendThreadCallback,579>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,579>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::GFx::AMP::SendThreadCallback_vtbl *)&Scaleform::RefCountImplCore::`vftable';
    v4->RefCount = 1;
    v4->Scaleform::GFx::AMP::SendInterface::__vftable = (Scaleform::GFx::AMP::SendInterface_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
    v4->Scaleform::RefCountBase<Scaleform::GFx::AMP::SendThreadCallback,579>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,579>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::GFx::AMP::SendThreadCallback_vtbl *)&Scaleform::GFx::AMP::SendThreadCallback::`vftable'{for `Scaleform::RefCountBase<Scaleform::GFx::AMP::SendThreadCallback,579>'};
    v4->Scaleform::GFx::AMP::SendInterface::__vftable = (Scaleform::GFx::AMP::SendInterface_vtbl *)&Scaleform::GFx::AMP::SendThreadCallback::`vftable'{for `Scaleform::GFx::AMP::SendInterface'};
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  pObject = (Scaleform::RefCountVImpl *)this->SendCallback.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->SendCallback.pObject = v5;
  v37 = 579;
  v7 = (Scaleform::GFx::AMP::StatusChangedCallback *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                       Scaleform::Memory::pGlobalHeap,
                                                       this,
                                                       16,
                                                       &v37);
  if ( v7 )
  {
    Scaleform::GFx::AMP::StatusChangedCallback::StatusChangedCallback(v7, &this->ConnectedEvent);
    v9 = v8;
  }
  else
  {
    v9 = 0;
  }
  v10 = (Scaleform::RefCountVImpl *)this->StatusCallback.pObject;
  if ( v10 )
    Scaleform::RefCountImpl::Release(v10);
  this->StatusCallback.pObject = v9;
  v38 = 580;
  v11 = (Scaleform::GFx::AMP::MessageAppControl *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                    Scaleform::Memory::pGlobalHeap,
                                                    this,
                                                    36,
                                                    &v38);
  if ( v11 )
  {
    Scaleform::GFx::AMP::MessageAppControl::MessageAppControl(v11, 0);
    v13 = v12;
  }
  else
  {
    v13 = 0;
  }
  v14 = (Scaleform::RefCountVImpl *)this->AppControlCaps.pObject;
  if ( v14 )
    Scaleform::RefCountImpl::Release(v14);
  this->AppControlCaps.pObject = v13;
  v39 = 579;
  v15 = (Scaleform::GFx::AMP::Server::RenderProfile *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                        Scaleform::Memory::pGlobalHeap,
                                                        this,
                                                        12,
                                                        &v39);
  if ( v15 )
  {
    Scaleform::GFx::AMP::Server::RenderProfile::RenderProfile(v15);
    v17 = v16;
  }
  else
  {
    v17 = 0;
  }
  v18 = (Scaleform::RefCountVImpl *)this->RenderStats.pObject;
  if ( v18 )
    Scaleform::RefCountImpl::Release(v18);
  this->RenderStats.pObject = v17;
  Scaleform::Event::SetEvent(&this->SendingEvent);
  v40 = 580;
  v19 = (Scaleform::GFx::AMP::MessageTypeRegistry *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                      Scaleform::Memory::pGlobalHeap,
                                                      this,
                                                      12,
                                                      &v40);
  if ( v19 )
  {
    v19->__vftable = (Scaleform::GFx::AMP::MessageTypeRegistry_vtbl *)&Scaleform::RefCountImplCore::`vftable';
    v19->RefCount = 1;
    v19->__vftable = (Scaleform::GFx::AMP::MessageTypeRegistry_vtbl *)&Scaleform::GFx::AMP::MessageTypeRegistry::`vftable';
    v19->DescriptorMap.mHash.pTable = 0;
    v20 = v19;
  }
  else
  {
    v20 = 0;
  }
  v41 = 580;
  v21 = (Scaleform::GFx::Resource *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                      Scaleform::Memory::pGlobalHeap,
                                      this,
                                      12,
                                      &v41);
  if ( v21 )
  {
    v21->__vftable = (Scaleform::GFx::Resource_vtbl *)&Scaleform::RefCountImplCore::`vftable';
    v21->RefCount.Value = 1;
    v21->__vftable = (Scaleform::GFx::Resource_vtbl *)&Scaleform::GFx::AMP::AppControlMsgHandler::`vftable';
    v21->pLib = (Scaleform::GFx::ResourceLibBase *)this;
  }
  else
  {
    v21 = 0;
  }
  Scaleform::GFx::AMP::MessageTypeRegistry::AddMessageType<Scaleform::GFx::AMP::MessageAppControl>(
    v20,
    v21,
    (Scaleform::RefCountVImpl *)1);
  v42 = 580;
  v22 = (Scaleform::GFx::Resource *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                      Scaleform::Memory::pGlobalHeap,
                                      this,
                                      12,
                                      &v42);
  if ( v22 )
  {
    v22->__vftable = (Scaleform::GFx::Resource_vtbl *)&Scaleform::RefCountImplCore::`vftable';
    v22->RefCount.Value = 1;
    v22->__vftable = (Scaleform::GFx::Resource_vtbl *)&Scaleform::GFx::AMP::InitStateMsgHandler::`vftable';
    v22->pLib = (Scaleform::GFx::ResourceLibBase *)this;
  }
  else
  {
    v22 = 0;
  }
  Scaleform::GFx::AMP::MessageTypeRegistry::AddMessageType<Scaleform::GFx::AMP::MessageInitState>(
    v20,
    v22,
    (Scaleform::RefCountVImpl *)1);
  v43 = 580;
  v23 = (Scaleform::GFx::Resource *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                      Scaleform::Memory::pGlobalHeap,
                                      this,
                                      12,
                                      &v43);
  if ( v23 )
  {
    v23->__vftable = (Scaleform::GFx::Resource_vtbl *)&Scaleform::RefCountImplCore::`vftable';
    v23->RefCount.Value = 1;
    v23->__vftable = (Scaleform::GFx::Resource_vtbl *)&Scaleform::GFx::AMP::SwdRequestMsgHandler::`vftable';
    v23->pLib = (Scaleform::GFx::ResourceLibBase *)this;
  }
  else
  {
    v23 = 0;
  }
  Scaleform::GFx::AMP::MessageTypeRegistry::AddMessageType<Scaleform::GFx::AMP::MessageSwdRequest>(v20, v23, 0);
  v44 = 580;
  v24 = (Scaleform::GFx::Resource *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                      Scaleform::Memory::pGlobalHeap,
                                      this,
                                      12,
                                      &v44);
  if ( v24 )
  {
    v24->__vftable = (Scaleform::GFx::Resource_vtbl *)&Scaleform::RefCountImplCore::`vftable';
    v24->RefCount.Value = 1;
    v24->__vftable = (Scaleform::GFx::Resource_vtbl *)&Scaleform::GFx::AMP::SourceRequestMsgHandler::`vftable';
    v24->pLib = (Scaleform::GFx::ResourceLibBase *)this;
  }
  else
  {
    v24 = 0;
  }
  Scaleform::GFx::AMP::MessageTypeRegistry::AddMessageType<Scaleform::GFx::AMP::MessageSourceRequest>(v20, v24, 0);
  v45 = 580;
  v25 = (Scaleform::GFx::Resource *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                      Scaleform::Memory::pGlobalHeap,
                                      this,
                                      12,
                                      &v45);
  if ( v25 )
  {
    v25->__vftable = (Scaleform::GFx::Resource_vtbl *)&Scaleform::RefCountImplCore::`vftable';
    v25->RefCount.Value = 1;
    v25->__vftable = (Scaleform::GFx::Resource_vtbl *)&Scaleform::GFx::AMP::ObjectsReportRequestMsgHandler::`vftable';
    v25->pLib = (Scaleform::GFx::ResourceLibBase *)this;
  }
  else
  {
    v25 = 0;
  }
  Scaleform::GFx::AMP::MessageTypeRegistry::AddMessageType<Scaleform::GFx::AMP::MessageObjectsReportRequest>(
    v20,
    v25,
    0);
  v46 = 580;
  v26 = (Scaleform::GFx::Resource *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                      Scaleform::Memory::pGlobalHeap,
                                      this,
                                      12,
                                      &v46);
  if ( v26 )
  {
    v26->__vftable = (Scaleform::GFx::Resource_vtbl *)&Scaleform::RefCountImplCore::`vftable';
    v26->RefCount.Value = 1;
    v26->__vftable = (Scaleform::GFx::Resource_vtbl *)&Scaleform::GFx::AMP::ImageRequestMsgHandler::`vftable';
    v26->pLib = (Scaleform::GFx::ResourceLibBase *)this;
  }
  else
  {
    v26 = 0;
  }
  Scaleform::GFx::AMP::MessageTypeRegistry::AddMessageType<Scaleform::GFx::AMP::MessageImageRequest>(v20, v26, 0);
  v47 = 580;
  v27 = (Scaleform::GFx::Resource *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                      Scaleform::Memory::pGlobalHeap,
                                      this,
                                      12,
                                      &v47);
  if ( v27 )
  {
    v27->__vftable = (Scaleform::GFx::Resource_vtbl *)&Scaleform::RefCountImplCore::`vftable';
    v27->RefCount.Value = 1;
    v27->__vftable = (Scaleform::GFx::Resource_vtbl *)&Scaleform::GFx::AMP::FontRequestMsgHandler::`vftable';
    v27->pLib = (Scaleform::GFx::ResourceLibBase *)this;
  }
  else
  {
    v27 = 0;
  }
  Scaleform::GFx::AMP::MessageTypeRegistry::AddMessageType<Scaleform::GFx::AMP::MessageFontRequest>(v20, v27, 0);
  v48 = 579;
  v28 = (Scaleform::GFx::AMP::ThreadMgr *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                            Scaleform::Memory::pGlobalHeap,
                                            this,
                                            432,
                                            &v48);
  if ( v28 )
  {
    v29 = this->StatusCallback.pObject;
    if ( v29 )
      v30 = &v29->Scaleform::GFx::AMP::ConnStatusInterface;
    else
      v30 = 0;
    v31 = this->SendCallback.pObject;
    if ( v31 )
      v32 = &v31->Scaleform::GFx::AMP::SendInterface;
    else
      v32 = 0;
    Scaleform::GFx::AMP::ThreadMgr::ThreadMgr(v28, 1, v32, v30, &this->SendingEvent, 0, this->SocketFactory, v20);
    v34 = v33;
  }
  else
  {
    v34 = 0;
  }
  v35 = (Scaleform::RefCountVImpl *)this->SocketThreadMgr.pObject;
  if ( v35 )
    Scaleform::RefCountImpl::Release(v35);
  this->SocketThreadMgr.pObject = v34;
  this->GpaDomain = 0;
  this->GpaStringHandle = 0;
  this->GpaGroupId = 0;
  if ( v20 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v20);
}
