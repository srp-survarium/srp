void __thiscall Scaleform::GFx::AMP::Server::AddSwf(
        Scaleform::GFx::AMP::Server *this,
        unsigned int swdHandle,
        const __m128i *swdId,
        const __m128i *filename)
{
  Scaleform::StringLH *v5; // eax
  Scaleform::StringLH *v6; // esi
  Scaleform::RefCountVImpl *v7; // [esp+Ch] [ebp-10h] BYREF
  int v8; // [esp+10h] [ebp-Ch] BYREF
  Scaleform::HashNode<unsigned long,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SwdInfo>,Scaleform::FixedSizeHash<unsigned long> >::NodeRef key; // [esp+14h] [ebp-8h] BYREF

  v8 = 579;
  v5 = (Scaleform::StringLH *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                Scaleform::Memory::pGlobalHeap,
                                &this[-1].RecordingStateLock.cs.LockSemaphore,
                                16,
                                &v8);
  v6 = v5;
  if ( v5 )
  {
    v5->HeapTypeBits = (unsigned int)&Scaleform::RefCountImplCore::`vftable';
    v5[1].HeapTypeBits = 1;
    v5->HeapTypeBits = (unsigned int)&Scaleform::GFx::AMP::Server::SwdInfo::`vftable';
    Scaleform::StringLH::StringLH(v5 + 2);
    Scaleform::StringLH::StringLH(v6 + 3);
  }
  else
  {
    v6 = 0;
  }
  Scaleform::String::operator=(v6 + 2, swdId);
  Scaleform::String::operator=(v6 + 3, filename);
  EnterCriticalSection((LPCRITICAL_SECTION)&this->LoaderLock.cs.SpinCount);
  key.pFirst = &swdHandle;
  v7 = (Scaleform::RefCountVImpl *)v6;
  key.pSecond = (const Scaleform::Ptr<Scaleform::GFx::AMP::Server::SwdInfo> *)&v7;
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SwdInfo>,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SwdInfo>,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SwdInfo>,Scaleform::FixedSizeHash<unsigned long>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SwdInfo>,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SwdInfo>,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned long,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SwdInfo>,Scaleform::FixedSizeHash<unsigned long>>::NodeRef>(
    (Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SwdInfo>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SwdInfo>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SwdInfo>,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SwdInfo>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SwdInfo>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> > *)&this->LoaderLock.cs.LockSemaphore,
    &this->LoaderLock.cs.LockSemaphore,
    &key);
  if ( v7 )
    Scaleform::RefCountImpl::Release(v7);
  LeaveCriticalSection((LPCRITICAL_SECTION)&this->LoaderLock.cs.SpinCount);
}
