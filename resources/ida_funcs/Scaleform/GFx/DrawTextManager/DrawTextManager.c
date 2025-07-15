void __thiscall Scaleform::GFx::DrawTextManager::DrawTextManager(
        Scaleform::GFx::DrawTextManager *this,
        Scaleform::GFx::Loader *ploader)
{
  Scaleform::MemoryHeap *v3; // eax
  Scaleform::MemoryHeap *(__thiscall *CreateHeap)(Scaleform::MemoryHeap *, const char *, const Scaleform::MemoryHeap::HeapDesc *); // edx
  Scaleform::MemoryHeap *v5; // eax
  int v6; // eax
  Scaleform::GFx::DrawTextManagerImpl *v7; // edi
  Scaleform::GFx::Resource *pObject; // ecx
  Scaleform::Lock *v9; // eax
  Scaleform::Lock *v10; // edi
  Scaleform::RefCountVImpl *LockSemaphore; // ecx
  Scaleform::Lock *v12; // ebp
  Scaleform::GFx::DrawTextManagerImpl *pImpl; // edi
  Scaleform::RefCountVImpl *v14; // ecx
  Scaleform::Ptr<Scaleform::GFx::StateBagImpl> *p_pStateBag; // edi
  Scaleform::Log *v17; // ebp
  Scaleform::GFx::Resource **Log; // eax
  Scaleform::Log *v19; // ecx
  Scaleform::GFx::Resource *v20; // eax
  Scaleform::GFx::Resource *v21; // ebp
  Scaleform::Render::Text::Allocator *v22; // eax
  Scaleform::GFx::Loader *v23; // eax
  Scaleform::GFx::DrawTextManagerImpl *v24; // ebp
  Scaleform::RefCountNTSImpl *v25; // ecx
  _DWORD *p_pObject; // ebp
  Scaleform::GFx::Loader *v27; // eax
  Scaleform::GFx::StateBagImpl *v28; // ecx
  Scaleform::GFx::StateBag *v29; // ecx
  Scaleform::GFx::DrawTextManagerImpl *v30; // ebp
  Scaleform::RefCountNTSImpl *v31; // ecx
  _DWORD *v32; // ebp
  Scaleform::RefCountVImpl *v33; // eax
  Scaleform::GFx::State *v34; // ebp
  Scaleform::RefCountVImpl *v35; // eax
  Scaleform::GFx::State *v36; // ebp
  Scaleform::RefCountVImpl *v37; // eax
  Scaleform::GFx::State *v38; // ebp
  Scaleform::GFx::Resource *ContextNotify; // eax
  Scaleform::GFx::Resource *v40; // edi
  Scaleform::GFx::Resource *pLib; // ebp
  Scaleform::RefCountVImpl **p_pWeakLib; // edi
  Scaleform::GFx::ResourceWeakLib *v43; // eax
  Scaleform::GFx::Resource *v44; // eax
  Scaleform::GFx::FontManager *v45; // eax
  Scaleform::GFx::FontManager *v46; // eax
  Scaleform::GFx::FontManager *v47; // ebp
  Scaleform::GFx::DrawTextManagerImpl *v48; // edi
  Scaleform::RefCountVImpl *v49; // ecx
  Scaleform::Ptr<Scaleform::GFx::FontManager> *p_pFontManager; // edi
  Scaleform::GFx::DrawTextManagerImpl *v51; // edi
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::Render::ContextImpl::Context *p_RenderContext; // edi
  Scaleform::Render::TreeRoot::NodeData *v54; // eax
  Scaleform::Render::ContextImpl::EntryData *v55; // ebp
  Scaleform::Render::ContextImpl::Entry *EntryHelper; // eax
  Scaleform::GFx::DrawTextManagerImpl *v57; // edi
  Scaleform::Render::ContextImpl::Entry *v58; // ecx
  Scaleform::Render::TreeRoot *v59; // ebp
  Scaleform::Render::TreeRoot *v61; // ecx
  Scaleform::RefCountVImpl **p_DispHandle; // edi
  Scaleform::Render::ContextImpl::RTHandle v63; // [esp+7Ch] [ebp-30h] BYREF
  Scaleform::Ptr<Scaleform::Log> result; // [esp+80h] [ebp-2Ch] BYREF
  Scaleform::Ptr<Scaleform::Log> v65; // [esp+84h] [ebp-28h] BYREF
  Scaleform::Render::Color color; // [esp+88h] [ebp-24h] BYREF
  _DWORD v67[8]; // [esp+8Ch] [ebp-20h] BYREF
  Scaleform::GFx::Loader *ploadera; // [esp+B0h] [ebp+4h]
  Scaleform::GFx::Loader *ploaderb; // [esp+B0h] [ebp+4h]
  Scaleform::RefCountVImpl *ploaderc; // [esp+B0h] [ebp+4h]

  this->RefCount = 1;
  this->Scaleform::GFx::StateBag::__vftable = (Scaleform::GFx::StateBag_vtbl *)&Scaleform::GFx::StateBag::`vftable';
  this->Scaleform::RefCountBaseNTS<Scaleform::GFx::DrawTextManager,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,2>::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable = (Scaleform::GFx::DrawTextManager_vtbl *)&Scaleform::GFx::DrawTextManager::`vftable'{for `Scaleform::RefCountBaseNTS<Scaleform::GFx::DrawTextManager,2>'};
  this->Scaleform::GFx::StateBag::__vftable = (Scaleform::GFx::StateBag_vtbl *)&Scaleform::GFx::DrawTextManager::`vftable'{for `Scaleform::GFx::StateBag'};
  v3 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  CreateHeap = Scaleform::Memory::pGlobalHeap->CreateHeap;
  v67[0] = v3->Info.Desc.Flags & 0x1000;
  v67[2] = 0x4000;
  v67[3] = 0x4000;
  v67[1] = 16;
  v67[4] = -1;
  memset(&v67[5], 0, 12);
  v5 = (Scaleform::MemoryHeap *)((int (__stdcall *)(const char *, _DWORD *))CreateHeap)("DrawText Manager", v67);
  this->pHeap = v5;
  v6 = (int)v5->Alloc(v5, 232u, 0);
  v7 = (Scaleform::GFx::DrawTextManagerImpl *)v6;
  if ( v6 )
  {
    *(_DWORD *)v6 = 0;
    *(_DWORD *)(v6 + 4) = 0;
    *(_DWORD *)(v6 + 8) = 0;
    *(_DWORD *)(v6 + 12) = 0;
    *(_DWORD *)(v6 + 16) = 0;
    *(_DWORD *)(v6 + 20) = 0;
    *(_DWORD *)(v6 + 24) = 0;
    Scaleform::GFx::DrawTextManager::TextParams::TextParams((Scaleform::GFx::DrawTextManager::TextParams *)(v6 + 28));
    v7->pLoaderImpl.pObject = 0;
    v7->RTFlags = 0;
    Scaleform::Render::ContextImpl::Context::Context(&v7->RenderContext, (int)v7, Scaleform::Memory::pGlobalHeap);
    v7->DispHandle.pData.pObject = 0;
  }
  else
  {
    v7 = 0;
  }
  this->pImpl = v7;
  pObject = v7->pMovieDef.pObject;
  if ( pObject )
    Scaleform::GFx::Resource::Release(pObject);
  v7->pMovieDef.pObject = 0;
  v9 = (Scaleform::Lock *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 48, 0);
  v10 = v9;
  if ( v9 )
  {
    v9->cs.DebugInfo = (_RTL_CRITICAL_SECTION_DEBUG *)&Scaleform::RefCountImplCore::`vftable';
    v9->cs.LockCount = 1;
    v9->cs.RecursionCount = (int)&Scaleform::GFx::StateBag::`vftable';
    v9->cs.OwningThread = &Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger>::`vftable';
    v9->cs.DebugInfo = (_RTL_CRITICAL_SECTION_DEBUG *)&Scaleform::GFx::StateBagImpl::`vftable'{for `Scaleform::RefCountBase<Scaleform::GFx::StateBagImpl,2>'};
    v9->cs.RecursionCount = (int)&Scaleform::GFx::StateBagImpl::`vftable'{for `Scaleform::GFx::StateBag'};
    v9->cs.OwningThread = &Scaleform::GFx::StateBagImpl::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>'};
    v9->cs.LockSemaphore = 0;
    v9->cs.SpinCount = 0;
    Scaleform::Lock::Lock(v9 + 1, 0);
    LockSemaphore = (Scaleform::RefCountVImpl *)v10->cs.LockSemaphore;
    if ( LockSemaphore )
      Scaleform::RefCountImpl::Release(LockSemaphore);
    v10->cs.LockSemaphore = 0;
    v12 = v10;
  }
  else
  {
    v12 = 0;
  }
  pImpl = this->pImpl;
  v14 = (Scaleform::RefCountVImpl *)pImpl->pStateBag.pObject;
  p_pStateBag = &pImpl->pStateBag;
  if ( v14 )
    Scaleform::RefCountImpl::Release(v14);
  p_pStateBag->pObject = (Scaleform::GFx::StateBagImpl *)v12;
  v17 = Scaleform::GFx::StateBag::GetLog(ploader, &result)->pObject;
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)result.pObject);
  if ( v17 )
  {
    Log = (Scaleform::GFx::Resource **)Scaleform::GFx::StateBag::GetLog(ploader, &v65);
    Scaleform::GFx::StateBag::SetLog(&this->pImpl->pStateBag.pObject->Scaleform::GFx::StateBag, *Log);
    v19 = v65.pObject;
    if ( !v65.pObject )
      goto LABEL_24;
    goto LABEL_23;
  }
  v20 = (Scaleform::GFx::Resource *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 8, 0);
  if ( v20 )
  {
    v20->__vftable = (Scaleform::GFx::Resource_vtbl *)&Scaleform::RefCountImplCore::`vftable';
    v20->RefCount.Value = 1;
    v20->__vftable = (Scaleform::GFx::Resource_vtbl *)&Scaleform::Log::`vftable';
    v21 = v20;
  }
  else
  {
    v21 = 0;
  }
  Scaleform::GFx::StateBag::SetLog(&this->pImpl->pStateBag.pObject->Scaleform::GFx::StateBag, v21);
  if ( v21 )
  {
    v19 = (Scaleform::Log *)v21;
LABEL_23:
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v19);
  }
LABEL_24:
  v22 = (Scaleform::Render::Text::Allocator *)this->pHeap->Alloc(this->pHeap, 76, 0);
  if ( v22 )
  {
    Scaleform::Render::Text::Allocator::Allocator(v22, this->pHeap, 0);
    ploadera = v23;
  }
  else
  {
    ploadera = 0;
  }
  v24 = this->pImpl;
  v25 = v24->pTextAllocator.pObject;
  p_pObject = &v24->pTextAllocator.pObject;
  if ( v25 )
    Scaleform::RefCountNTSImpl::Release(v25);
  *p_pObject = ploadera;
  v27 = (Scaleform::GFx::Loader *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 32, 0);
  if ( v27 )
  {
    v28 = this->pImpl->pStateBag.pObject;
    if ( v28 )
      v29 = &v28->Scaleform::GFx::StateBag;
    else
      v29 = 0;
    v27->pImpl = (Scaleform::GFx::LoaderImpl *)1;
    v27->pStrongResourceLib = (Scaleform::GFx::ResourceLib *)&Scaleform::GFx::StateBag::`vftable';
    v27->__vftable = (Scaleform::GFx::Loader_vtbl *)&Scaleform::GFx::FontManagerStates::`vftable'{for `Scaleform::RefCountBaseNTS<Scaleform::GFx::FontManagerStates,327>'};
    v27->pStrongResourceLib = (Scaleform::GFx::ResourceLib *)&Scaleform::GFx::FontManagerStates::`vftable'{for `Scaleform::GFx::StateBag'};
    v27->DefLoadFlags = 0;
    v27[1].__vftable = 0;
    v27[1].pImpl = 0;
    v27[1].pStrongResourceLib = 0;
    v27[1].DefLoadFlags = (unsigned int)v29;
    ploaderb = v27;
  }
  else
  {
    ploaderb = 0;
  }
  v30 = this->pImpl;
  v31 = v30->pFontStates.pObject;
  v32 = &v30->pFontStates.pObject;
  if ( v31 )
    Scaleform::RefCountNTSImpl::Release(v31);
  *v32 = ploaderb;
  v33 = (Scaleform::RefCountVImpl *)ploader->GetStateAddRef(ploader, 17);
  if ( v33 )
  {
    Scaleform::RefCountImpl::Release(v33);
    v34 = ploader->GetStateAddRef(ploader, 17);
    this->pImpl->pStateBag.pObject->SetState(
      &this->pImpl->pStateBag.pObject->Scaleform::GFx::StateBag,
      State_FontLib,
      v34);
    if ( v34 )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v34);
  }
  v35 = (Scaleform::RefCountVImpl *)ploader->GetStateAddRef(ploader, 20);
  if ( v35 )
  {
    Scaleform::RefCountImpl::Release(v35);
    v36 = ploader->GetStateAddRef(ploader, 20);
    this->pImpl->pStateBag.pObject->SetState(
      &this->pImpl->pStateBag.pObject->Scaleform::GFx::StateBag,
      State_FontMap,
      v36);
    if ( v36 )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v36);
  }
  v37 = (Scaleform::RefCountVImpl *)ploader->GetStateAddRef(ploader, 19);
  if ( v37 )
  {
    Scaleform::RefCountImpl::Release(v37);
    v38 = ploader->GetStateAddRef(ploader, 19);
    this->pImpl->pStateBag.pObject->SetState(
      &this->pImpl->pStateBag.pObject->Scaleform::GFx::StateBag,
      State_FontProvider,
      v38);
    if ( v38 )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v38);
  }
  ContextNotify = (Scaleform::GFx::Resource *)Scaleform::Render::Renderer2D::GetContextNotify((Scaleform::GFx::AS3::SoundObject *)ploader);
  v40 = ContextNotify;
  ploaderc = (Scaleform::RefCountVImpl *)ContextNotify;
  if ( ContextNotify )
  {
    Scaleform::RefCountImpl::AddRef(ContextNotify);
    pLib = (Scaleform::GFx::Resource *)v40->pLib;
    p_pWeakLib = (Scaleform::RefCountVImpl **)&this->pImpl->pWeakLib;
    if ( pLib )
      Scaleform::RefCountImpl::AddRef(pLib);
  }
  else
  {
    v43 = (Scaleform::GFx::ResourceWeakLib *)Scaleform::Memory::pGlobalHeap->Alloc(
                                               Scaleform::Memory::pGlobalHeap,
                                               44,
                                               0);
    if ( v43 )
    {
      Scaleform::GFx::ResourceWeakLib::ResourceWeakLib(v43, 0);
      pLib = v44;
    }
    else
    {
      pLib = 0;
    }
    p_pWeakLib = (Scaleform::RefCountVImpl **)&this->pImpl->pWeakLib;
  }
  if ( *p_pWeakLib )
    Scaleform::RefCountImpl::Release(*p_pWeakLib);
  *p_pWeakLib = (Scaleform::RefCountVImpl *)pLib;
  v45 = (Scaleform::GFx::FontManager *)this->pHeap->Alloc(this->pHeap, 60, 0);
  if ( v45 )
  {
    Scaleform::GFx::FontManager::FontManager(v45, this->pImpl->pWeakLib.pObject, this->pImpl->pFontStates.pObject);
    v47 = v46;
  }
  else
  {
    v47 = 0;
  }
  v48 = this->pImpl;
  v49 = (Scaleform::RefCountVImpl *)v48->pFontManager.pObject;
  p_pFontManager = &v48->pFontManager;
  if ( v49 )
    Scaleform::RefCountImpl::Release(v49);
  p_pFontManager->pObject = v47;
  v51 = this->pImpl;
  pHeap = v51->RenderContext.pHeap;
  p_RenderContext = &v51->RenderContext;
  v54 = (Scaleform::Render::TreeRoot::NodeData *)pHeap->Alloc(pHeap, 208u, 0);
  v55 = v54;
  if ( v54 )
    Scaleform::Render::TreeRoot::NodeData::NodeData(v54);
  EntryHelper = Scaleform::Render::ContextImpl::Context::createEntryHelper(p_RenderContext, v55);
  v57 = this->pImpl;
  v58 = v57->pRootNode.pObject;
  v59 = (Scaleform::Render::TreeRoot *)EntryHelper;
  if ( v57->pRootNode.pObject )
  {
    if ( v58->RefCount-- == 1 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v58);
  }
  v57->pRootNode.pObject = v59;
  v61 = this->pImpl->pRootNode.pObject;
  color = 0;
  Scaleform::Render::TreeRoot::SetBackgroundColor(v61, &color);
  Scaleform::Render::ContextImpl::RTHandle::RTHandle(&v63, this->pImpl->pRootNode.pObject);
  p_DispHandle = (Scaleform::RefCountVImpl **)&this->pImpl->DispHandle;
  if ( v63.pData.pObject )
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v63.pData.pObject);
  if ( *p_DispHandle )
    Scaleform::RefCountImpl::Release(*p_DispHandle);
  *p_DispHandle = (Scaleform::RefCountVImpl *)v63.pData.pObject;
  Scaleform::Render::ContextImpl::RTHandle::~RTHandle(&v63);
  if ( ploaderc )
    Scaleform::RefCountImpl::Release(ploaderc);
}
