void __thiscall Scaleform::GFx::AMP::Server::CloseConnection(Scaleform::GFx::AMP::Server *this)
{
  unsigned int *p_Size; // ebx
  unsigned int i; // edi
  bool v4; // al

  p_Size = &this->MovieStats.Data.Size;
  EnterCriticalSection((LPCRITICAL_SECTION)&this->MovieStats.Data.Size);
  for ( i = 0; i < this->Movies.Data.Policy.Capacity; ++i )
    Scaleform::GFx::AMP::ViewStats::DebugGo(*(Scaleform::GFx::AMP::ViewStats **)(*(_DWORD *)(this->Movies.Data.Size
                                                                                           + 4 * i)
                                                                               + 8));
  LeaveCriticalSection((LPCRITICAL_SECTION)p_Size);
  Scaleform::GFx::AMP::ThreadMgr::UninitAmp((Scaleform::GFx::AMP::ThreadMgr *)this->Port);
  if ( this->AppControlCaps.pObject )
    v4 = 1;
  else
    v4 = ((unsigned __int8 (__thiscall *)(Scaleform::GFx::AMP::Server *))this->Scaleform::RefCountBase<Scaleform::GFx::AMP::Server,579>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,579>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable[14].~Scaleform::GFx::AMP::Server)(this)
      && !((unsigned __int8 (__thiscall *)(Scaleform::GFx::AMP::Server *))this->Scaleform::RefCountBase<Scaleform::GFx::AMP::Server,579>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,579>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable[15].~Scaleform::GFx::AMP::Server)(this)
      && Scaleform::GFx::AMP::ThreadMgr::IsValidSocket((Scaleform::GFx::AMP::ThreadMgr *)this->Port)
      && ((unsigned __int8 (__thiscall *)(Scaleform::GFx::AMP::Server *))this->Scaleform::RefCountBase<Scaleform::GFx::AMP::Server,579>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,579>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable[6].~Scaleform::GFx::AMP::Server)(this) != 0;
  InterlockedExchange((volatile LONG *)&this->InitSocketLib, v4);
}
