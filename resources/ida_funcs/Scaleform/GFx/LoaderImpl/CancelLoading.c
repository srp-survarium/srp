void __thiscall Scaleform::GFx::LoaderImpl::CancelLoading(Scaleform::GFx::LoaderImpl *this)
{
  Scaleform::RefCountVImpl *v2; // ebx
  Scaleform::GFx::LoaderImpl *i; // esi

  v2 = (Scaleform::RefCountVImpl *)this->pStateBag.pObject->GetStateAddRef(
                                     &this->pStateBag.pObject->Scaleform::GFx::StateBag,
                                     21);
  if ( v2 )
  {
    EnterCriticalSection(&this->LoadProcessesLock.cs);
    for ( i = (Scaleform::GFx::LoaderImpl *)this->LoadProcesses.Root.pNext;
          i != (Scaleform::GFx::LoaderImpl *)&this->LoadProcesses;
          i = (Scaleform::GFx::LoaderImpl *)this->LoadProcesses.Root.pNext )
    {
      i->Scaleform::RefCountBase<Scaleform::GFx::LoaderImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable[1].~Scaleform::GFx::LoaderImpl = (void (__thiscall *)(struct Scaleform::GFx::LoaderImpl *))i->RefCount;
      *(_DWORD *)i->RefCount = i->Scaleform::RefCountBase<Scaleform::GFx::LoaderImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable;
      ((void (__thiscall *)(Scaleform::RefCountVImpl *, Scaleform::GFx::StateBag_vtbl *))v2->Release)(
        v2,
        i->Scaleform::GFx::StateBag::__vftable);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, i);
    }
    LeaveCriticalSection(&this->LoadProcessesLock.cs);
    Scaleform::RefCountImpl::Release(v2);
  }
}
