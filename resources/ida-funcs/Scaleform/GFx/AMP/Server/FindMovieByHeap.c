char __thiscall Scaleform::GFx::AMP::Server::FindMovieByHeap(
        Scaleform::GFx::AMP::Server *this,
        Scaleform::MemoryHeap *heap,
        Scaleform::GFx::MovieImpl **movie)
{
  unsigned int *p_Size; // ebp
  Scaleform::GFx::AMP::ThreadMgr *pObject; // ebx
  int v6; // esi
  unsigned int BroadcastPort; // eax
  bool v8; // zf
  _DWORD *v9; // eax

  p_Size = &this->MovieStats.Data.Size;
  EnterCriticalSection((LPCRITICAL_SECTION)&this->MovieStats.Data.Size);
  pObject = this->SocketThreadMgr.pObject;
  v6 = 0;
  if ( pObject )
  {
    while ( 1 )
    {
      BroadcastPort = this->BroadcastPort;
      v8 = *(_DWORD *)(BroadcastPort + 4 * v6) == 0;
      v9 = (_DWORD *)(BroadcastPort + 4 * v6);
      if ( !v8 && (Scaleform::MemoryHeap *)(*(int (__thiscall **)(_DWORD))(*(_DWORD *)*v9 + 188))(*v9) == heap )
        break;
      if ( ++v6 >= (unsigned int)pObject )
        goto LABEL_5;
    }
    Scaleform::RefCountImpl::AddRef(*(Scaleform::GFx::Resource **)(this->BroadcastPort + 4 * v6));
    *movie = *(Scaleform::GFx::MovieImpl **)(this->BroadcastPort + 4 * v6);
    LeaveCriticalSection((LPCRITICAL_SECTION)p_Size);
    return 1;
  }
  else
  {
LABEL_5:
    LeaveCriticalSection((LPCRITICAL_SECTION)p_Size);
    return 0;
  }
}
