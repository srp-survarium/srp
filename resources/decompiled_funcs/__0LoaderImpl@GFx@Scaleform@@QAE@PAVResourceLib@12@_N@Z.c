void __thiscall Scaleform::GFx::LoaderImpl::LoaderImpl(
        Scaleform::GFx::LoaderImpl *this,
        Scaleform::GFx::ResourceLib *plib,
        bool debugHeap)
{
  Scaleform::GFx::ResourceWeakLib *pWeakLib; // edi
  Scaleform::GFx::ResourceWeakLib *pObject; // ecx
  Scaleform::Lock *v6; // eax
  Scaleform::GFx::StateBagImpl *v7; // edi
  Scaleform::RefCountVImpl *v8; // ecx
  Scaleform::GFx::StateBagImpl *v9; // ecx
  Scaleform::GFx::Resource *v10; // eax
  Scaleform::GFx::Resource *v11; // edi
  Scaleform::GFx::ImageCreator *v12; // eax
  Scaleform::GFx::State *v13; // eax
  Scaleform::GFx::State *v14; // edi
  Scaleform::GFx::TextClipboard *v15; // eax
  Scaleform::GFx::State *v16; // eax
  Scaleform::GFx::State *v17; // edi
  Scaleform::GFx::TextKeyMap *v18; // eax
  Scaleform::GFx::TextKeyMap *v19; // eax
  Scaleform::GFx::TextKeyMap *inited; // edi

  this->Scaleform::RefCountBase<Scaleform::GFx::LoaderImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::GFx::LoaderImpl_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->Scaleform::GFx::StateBag::__vftable = (Scaleform::GFx::StateBag_vtbl *)&Scaleform::GFx::StateBag::`vftable';
  this->Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>::__vftable = (Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>_vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger>::`vftable';
  this->Scaleform::RefCountBase<Scaleform::GFx::LoaderImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::GFx::LoaderImpl_vtbl *)&Scaleform::GFx::LoaderImpl::`vftable'{for `Scaleform::RefCountBase<Scaleform::GFx::LoaderImpl,2>'};
  this->Scaleform::GFx::StateBag::__vftable = (Scaleform::GFx::StateBag_vtbl *)&Scaleform::GFx::LoaderImpl::`vftable'{for `Scaleform::GFx::StateBag'};
  this->Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>::__vftable = (Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>_vtbl *)&Scaleform::GFx::LoaderImpl::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>'};
  this->pStateBag.pObject = 0;
  this->pWeakResourceLib.pObject = 0;
  this->LoadProcesses.Root.pPrev = (Scaleform::GFx::LoadProcessNode *)&this->LoadProcesses;
  this->LoadProcesses.Root.pNext = (Scaleform::GFx::LoadProcessNode *)&this->LoadProcesses;
  Scaleform::Lock::Lock(&this->LoadProcessesLock, 0);
  this->DebugHeap = debugHeap;
  if ( plib )
  {
    pWeakLib = plib->pWeakLib;
    if ( pWeakLib )
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)plib->pWeakLib);
    pObject = this->pWeakResourceLib.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pObject);
    this->pWeakResourceLib.pObject = pWeakLib;
  }
  v6 = (Scaleform::Lock *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 48, 0);
  v7 = (Scaleform::GFx::StateBagImpl *)v6;
  if ( v6 )
  {
    v6->cs.DebugInfo = (_RTL_CRITICAL_SECTION_DEBUG *)&Scaleform::RefCountImplCore::`vftable';
    v6->cs.LockCount = 1;
    v6->cs.RecursionCount = (int)&Scaleform::GFx::StateBag::`vftable';
    v6->cs.OwningThread = &Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger>::`vftable';
    v6->cs.DebugInfo = (_RTL_CRITICAL_SECTION_DEBUG *)&Scaleform::GFx::StateBagImpl::`vftable'{for `Scaleform::RefCountBase<Scaleform::GFx::StateBagImpl,2>'};
    v6->cs.RecursionCount = (int)&Scaleform::GFx::StateBagImpl::`vftable'{for `Scaleform::GFx::StateBag'};
    v6->cs.OwningThread = &Scaleform::GFx::StateBagImpl::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>'};
    v6->cs.LockSemaphore = 0;
    v6->cs.SpinCount = 0;
    Scaleform::Lock::Lock(v6 + 1, 0);
    v8 = (Scaleform::RefCountVImpl *)v7->pDelegate.pObject;
    if ( v8 )
      Scaleform::RefCountImpl::Release(v8);
    v7->pDelegate.pObject = 0;
  }
  else
  {
    v7 = 0;
  }
  v9 = this->pStateBag.pObject;
  if ( v9 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v9);
  this->pStateBag.pObject = v7;
  if ( v7 )
  {
    v10 = (Scaleform::GFx::Resource *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 8, 0);
    if ( v10 )
    {
      v10->__vftable = (Scaleform::GFx::Resource_vtbl *)&Scaleform::RefCountImplCore::`vftable';
      v10->RefCount.Value = 1;
      v10->__vftable = (Scaleform::GFx::Resource_vtbl *)&Scaleform::Log::`vftable';
      v11 = v10;
    }
    else
    {
      v11 = 0;
    }
    Scaleform::GFx::StateBag::SetLog(&this->pStateBag.pObject->Scaleform::GFx::StateBag, v11);
    if ( v11 )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v11);
    v12 = (Scaleform::GFx::ImageCreator *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 16, 0);
    if ( v12 )
    {
      Scaleform::GFx::ImageCreator::ImageCreator(v12, 0);
      v14 = v13;
    }
    else
    {
      v14 = 0;
    }
    this->pStateBag.pObject->SetState(&this->pStateBag.pObject->Scaleform::GFx::StateBag, State_ImageCreator, v14);
    if ( v14 )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v14);
    v15 = (Scaleform::GFx::TextClipboard *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 32, 0);
    if ( v15 )
    {
      Scaleform::GFx::TextClipboard::TextClipboard(v15);
      v17 = v16;
    }
    else
    {
      v17 = 0;
    }
    this->pStateBag.pObject->SetState(&this->pStateBag.pObject->Scaleform::GFx::StateBag, State_TextClipboard, v17);
    if ( v17 )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v17);
    v18 = (Scaleform::GFx::TextKeyMap *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 24, 0);
    if ( v18 )
      Scaleform::GFx::TextKeyMap::TextKeyMap(v18);
    else
      v19 = 0;
    inited = Scaleform::GFx::TextKeyMap::InitWindowsKeyMap(v19);
    this->pStateBag.pObject->SetState(&this->pStateBag.pObject->Scaleform::GFx::StateBag, State_TextKeyMap, inited);
    if ( inited )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)inited);
  }
}
