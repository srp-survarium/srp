void __thiscall Scaleform::GFx::AMP::Server::AddMovie(Scaleform::GFx::AMP::Server *this, int movie)
{
  int v2; // ebp
  unsigned int *p_BroadcastPort; // edi
  unsigned int v5; // esi
  int *v6; // eax
  Scaleform::GFx::Resource *v7; // eax
  Scaleform::GFx::Resource *v8; // esi
  Scaleform::GFx::Resource *v9; // ecx
  Scaleform::GFx::Resource *v10; // edi
  Scaleform::GFx::Resource **v11; // esi

  v2 = movie;
  if ( (*(_DWORD *)(*(_DWORD *)(movie + 32) + 28) & 0x1000) == 0 )
  {
    if ( !Scaleform::GFx::AMP::ThreadMgr::IsRunning((Scaleform::GFx::AMP::ThreadMgr *)this->Port) )
      this->Scaleform::RefCountBase<Scaleform::GFx::AMP::Server,579>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,579>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable[4].~Scaleform::GFx::AMP::Server(this);
    EnterCriticalSection((LPCRITICAL_SECTION)&this->MovieStats.Data.Size);
    p_BroadcastPort = &this->BroadcastPort;
    v5 = (unsigned int)&this->SocketThreadMgr.pObject->__vftable + 1;
    if ( (Scaleform::GFx::AMP::ThreadMgr *)v5 >= this->SocketThreadMgr.pObject )
    {
      if ( (Scaleform::GFx::MovieImpl **)v5 >= this->Movies.Data.Data )
        Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)p_BroadcastPort,
          p_BroadcastPort,
          v5 + (v5 >> 2));
    }
    else if ( v5 < (unsigned int)this->Movies.Data.Data >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)p_BroadcastPort,
        p_BroadcastPort,
        (unsigned int)&this->SocketThreadMgr.pObject->__vftable + 1);
    }
    v6 = (int *)(*p_BroadcastPort + 4 * v5 - 4);
    this->SocketThreadMgr.pObject = (Scaleform::GFx::AMP::ThreadMgr *)v5;
    if ( v6 )
      *v6 = v2;
    movie = 579;
    v7 = (Scaleform::GFx::Resource *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                       Scaleform::Memory::pGlobalHeap,
                                       &this[-1].RecordingStateLock.cs.LockSemaphore,
                                       12,
                                       &movie);
    v8 = v7;
    if ( v7 )
    {
      v7->__vftable = (Scaleform::GFx::Resource_vtbl *)&Scaleform::RefCountImplCore::`vftable';
      v7->RefCount.Value = 1;
      v7->__vftable = (Scaleform::GFx::Resource_vtbl *)&Scaleform::GFx::AMP::Server::RenderProfile::`vftable';
      v9 = *(Scaleform::GFx::Resource **)(v2 + 24);
      if ( v9 )
        Scaleform::RefCountImpl::AddRef(v9);
      v8->pLib = *(Scaleform::GFx::ResourceLibBase **)(v2 + 24);
      v10 = v8;
    }
    else
    {
      v10 = 0;
    }
    Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AMP::Server::RenderProfile>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AMP::Server::RenderProfile>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Movies.Data.Size,
      &this->Movies.Data.Size,
      this->Movies.Data.Policy.Capacity + 1);
    v11 = (Scaleform::GFx::Resource **)(this->Movies.Data.Size + 4 * this->Movies.Data.Policy.Capacity - 4);
    if ( this->Movies.Data.Size + 4 * this->Movies.Data.Policy.Capacity != 4 )
    {
      if ( v10 )
        Scaleform::RefCountImpl::AddRef(v10);
      *v11 = v10;
    }
    if ( v10 )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v10);
    LeaveCriticalSection((LPCRITICAL_SECTION)&this->MovieStats.Data.Size);
  }
}
