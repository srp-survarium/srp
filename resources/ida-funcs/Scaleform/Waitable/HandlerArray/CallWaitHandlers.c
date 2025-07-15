void __thiscall Scaleform::Waitable::HandlerArray::CallWaitHandlers(Scaleform::Waitable::HandlerArray *this)
{
  Scaleform::Lock *p_HandlersLock; // ebp
  unsigned int Size; // eax
  unsigned int v4; // ebx
  Scaleform::Waitable::HandlerStruct *Data; // edi
  unsigned int i; // esi
  Scaleform::Array<Scaleform::Waitable::HandlerStruct,2,Scaleform::ArrayConstPolicy<0,16,1> > v7; // [esp+8h] [ebp-Ch] BYREF

  p_HandlersLock = &this->HandlersLock;
  EnterCriticalSection(&this->HandlersLock.cs);
  Size = this->Handlers.Data.Size;
  if ( Size )
  {
    if ( Size == 1 )
    {
      this->Handlers.Data.Data->Handler(this->Handlers.Data.Data->pUserData);
      LeaveCriticalSection(&p_HandlersLock->cs);
      return;
    }
    Scaleform::Array<Scaleform::Waitable::HandlerStruct,2,Scaleform::ArrayConstPolicy<0,16,1>>::Array<Scaleform::Waitable::HandlerStruct,2,Scaleform::ArrayConstPolicy<0,16,1>>(
      &v7,
      &this->Handlers);
    v4 = v7.Data.Size;
    Data = v7.Data.Data;
    for ( i = 0; i < v4; ++i )
      Data[i].Handler(Data[i].pUserData);
    if ( Data )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
  }
  LeaveCriticalSection(&p_HandlersLock->cs);
}
