void __thiscall Scaleform::GFx::AMP::Server::MovieAdvance(Scaleform::GFx::AMP::Server *this, int movie)
{
  _RTL_CRITICAL_SECTION *p_MemReportLocked; // ebx
  int v4; // edi
  Scaleform::GFx::AMP::MessageObjectsReport *v5; // edi
  char *v6; // eax
  Scaleform::RefCountVImpl *v7; // eax
  Scaleform::GFx::AMP::ObjectsLog v8; // [esp+18h] [ebp-20h] BYREF

  p_MemReportLocked = (_RTL_CRITICAL_SECTION *)&this->MemReportLocked;
  EnterCriticalSection((LPCRITICAL_SECTION)&this->MemReportLocked);
  v4 = movie;
  if ( this->ObjectsReportLock.cs.LockSemaphore == (void *)Scaleform::GFx::AMP::ViewStats::GetViewHandle(*(Scaleform::GFx::AMP::ViewStats **)(movie + 24)) )
  {
    v8.RefCount = 1;
    v8.__vftable = (Scaleform::GFx::AMP::ObjectsLog_vtbl *)&Scaleform::GFx::AMP::ObjectsLog::`vftable';
    Scaleform::StringBuffer::StringBuffer(&v8.Report, Scaleform::Memory::pGlobalHeap);
    (*(void (__thiscall **)(int, unsigned int, Scaleform::GFx::AMP::ObjectsLog *, _DWORD))(*(_DWORD *)v4 + 204))(
      v4,
      this->ObjectsReportLock.cs.SpinCount,
      &v8,
      0);
    movie = 580;
    v5 = (Scaleform::GFx::AMP::MessageObjectsReport *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                        Scaleform::Memory::pGlobalHeap,
                                                        &this[-1].RecordingStateLock.cs.LockSemaphore,
                                                        28,
                                                        &movie);
    if ( v5 )
    {
      v6 = Scaleform::GFx::AMP::ObjectsLog::ToCStr(&v8);
      Scaleform::GFx::AMP::MessageObjectsReport::MessageObjectsReport(v5, v6);
    }
    else
    {
      v7 = 0;
    }
    Scaleform::GFx::AMP::ThreadMgr::SendAmpMessage((Scaleform::GFx::AMP::ThreadMgr *)this->Port, v7);
    this->ObjectsReportLock.cs.LockSemaphore = 0;
    Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&v8.Report);
    Scaleform::Log::~Log(&v8);
  }
  LeaveCriticalSection(p_MemReportLocked);
}
