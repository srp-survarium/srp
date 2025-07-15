char __thiscall Scaleform::Waitable::RemoveWaitHandler(
        Scaleform::Waitable *this,
        void (__cdecl *handler)(void *),
        void *pdata)
{
  Scaleform::Waitable::HandlerArray *pHandlers; // eax
  _RTL_CRITICAL_SECTION *p_cs; // edi
  char v7; // bl
  Scaleform::Waitable::HandlerArray *v8; // ecx
  unsigned int Size; // edx
  int v10; // eax
  Scaleform::ArrayData<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1> > *p_Data; // esi
  Scaleform::Waitable::HandlerStruct *i; // ecx
  unsigned int v13; // ecx

  pHandlers = this->pHandlers;
  if ( !pHandlers )
    return 0;
  p_cs = &pHandlers->HandlersLock.cs;
  v7 = 0;
  EnterCriticalSection(&pHandlers->HandlersLock.cs);
  v8 = this->pHandlers;
  Size = v8->Handlers.Data.Size;
  v10 = 0;
  if ( Size )
  {
    p_Data = &v8->Handlers.Data;
    for ( i = v8->Handlers.Data.Data; i->Handler != handler || i->pUserData != pdata; ++i )
    {
      if ( ++v10 >= Size )
      {
        LeaveCriticalSection(p_cs);
        return 0;
      }
    }
    v13 = p_Data->Size;
    if ( v13 == 1 )
    {
      Scaleform::ArrayData<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1>>::Resize(
        p_Data,
        0);
      LeaveCriticalSection(p_cs);
      return 1;
    }
    memmove((int)&p_Data->Data[v10], (const __m128i *)&p_Data->Data[v10 + 1], 8 * (v13 - v10) - 8);
    --p_Data->Size;
    v7 = 1;
  }
  LeaveCriticalSection(p_cs);
  return v7;
}
