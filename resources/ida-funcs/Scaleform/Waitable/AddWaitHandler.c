char __thiscall Scaleform::Waitable::AddWaitHandler(
        Scaleform::Waitable *this,
        void (__cdecl *handler)(void *),
        void *pdata)
{
  Scaleform::Waitable::HandlerArray *pHandlers; // eax
  _RTL_CRITICAL_SECTION *p_cs; // esi
  Scaleform::Waitable::HandlerStruct val; // [esp+4h] [ebp-8h] BYREF

  pHandlers = this->pHandlers;
  if ( !pHandlers )
    return 0;
  p_cs = &pHandlers->HandlersLock.cs;
  val.Handler = handler;
  val.pUserData = pdata;
  EnterCriticalSection(&pHandlers->HandlersLock.cs);
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1>>>::PushBack(
    &this->pHandlers->Handlers,
    &val);
  LeaveCriticalSection(p_cs);
  return 1;
}
