void __thiscall Scaleform::GFx::AMP::Server::RemoveMovie(
        Scaleform::GFx::AMP::Server *this,
        Scaleform::GFx::MovieImpl *movie)
{
  Scaleform::GFx::AMP::ThreadMgr *pObject; // ecx
  unsigned int v4; // eax
  Scaleform::GFx::MovieImpl **BroadcastPort; // edx

  if ( (movie->pHeap->Info.Desc.Flags & 0x1000) == 0 )
  {
    EnterCriticalSection((LPCRITICAL_SECTION)&this->MovieStats.Data.Size);
    pObject = this->SocketThreadMgr.pObject;
    v4 = 0;
    if ( pObject )
    {
      BroadcastPort = (Scaleform::GFx::MovieImpl **)this->BroadcastPort;
      while ( *BroadcastPort != movie )
      {
        ++v4;
        ++BroadcastPort;
        if ( v4 >= (unsigned int)pObject )
          goto LABEL_14;
      }
      if ( pObject == (Scaleform::GFx::AMP::ThreadMgr *)1 )
      {
        if ( ((int)this->Movies.Data.Data & 0xFFFFFFFE) != 0 )
        {
          if ( this->BroadcastPort )
          {
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)this->BroadcastPort);
            this->BroadcastPort = 0;
          }
          this->Movies.Data.Data = 0;
        }
        this->SocketThreadMgr.pObject = 0;
      }
      else
      {
        memmove(
          this->BroadcastPort + 4 * v4,
          (const __m128i *)(this->BroadcastPort + 4 * v4 + 4),
          4 * ((_DWORD)pObject - v4) - 4);
        --this->SocketThreadMgr.pObject;
      }
    }
LABEL_14:
    if ( !this->SocketThreadMgr.pObject )
      this->Scaleform::RefCountBase<Scaleform::GFx::AMP::Server,579>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,579>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable[5].~Scaleform::GFx::AMP::Server(this);
    LeaveCriticalSection((LPCRITICAL_SECTION)&this->MovieStats.Data.Size);
  }
}
