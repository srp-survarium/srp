void __thiscall Scaleform::ThreadList::~ThreadList(Scaleform::ThreadList *this)
{
  Scaleform::WaitConditionImpl *pImpl; // esi
  Scaleform::MutexImpl *v3; // edi

  pImpl = this->ThreadsEmpty.pImpl;
  if ( pImpl )
  {
    Scaleform::WaitConditionImpl::~WaitConditionImpl(this->ThreadsEmpty.pImpl);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pImpl);
  }
  v3 = this->ThreadMutex.pImpl;
  this->ThreadMutex.__vftable = (Scaleform::Mutex_vtbl *)&Scaleform::Mutex::`vftable'{for `Scaleform::Waitable'};
  this->ThreadMutex.__vftable = (Scaleform::AcquireInterface_vtbl *)&Scaleform::Mutex::`vftable'{for `Scaleform::AcquireInterface'};
  if ( v3 )
  {
    CloseHandle(v3->hMutexOrSemaphore);
    v3->AreadyLockedAcquire.__vftable = (Scaleform::Mutex_AreadyLockedAcquireInterface_vtbl *)&Scaleform::AcquireInterface::`vftable';
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v3);
  }
  this->ThreadMutex.__vftable = (Scaleform::AcquireInterface_vtbl *)&Scaleform::AcquireInterface::`vftable';
  Scaleform::Waitable::~Waitable(&this->ThreadMutex);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Object *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Object *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS3::Instances::fl::Object *> >::NodeHashF> > *)this);
}
