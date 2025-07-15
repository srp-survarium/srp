char __thiscall Scaleform::GFx::AS3::SocketThreadMgr::ReadBytes(
        Scaleform::GFx::AS3::SocketThreadMgr *this,
        Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *valueRead,
        int length)
{
  int v4; // ebx
  Scaleform::GFx::AS3::SocketBuffer *pObject; // ecx
  int (__thiscall *Read)(struct Scaleform::GFx::AS3::SocketBuffer *, unsigned __int8 *, int); // eax
  unsigned int v7; // esi
  char *v8; // eax
  int i; // [esp+10h] [ebp-8h]
  Scaleform::Lock *locker; // [esp+14h] [ebp-4h]

  locker = &this->ReceivedBufferLock;
  EnterCriticalSection(&this->ReceivedBufferLock.cs);
  v4 = length;
  if ( !length )
    v4 = this->ReceivedBuffer.pObject->BytesAvailable(this->ReceivedBuffer.pObject);
  i = 0;
  if ( v4 <= 0 )
  {
LABEL_13:
    LeaveCriticalSection(&locker->cs);
    return 1;
  }
  else
  {
    while ( this->ReceivedBuffer.pObject->BytesAvailable(this->ReceivedBuffer.pObject) )
    {
      pObject = this->ReceivedBuffer.pObject;
      Read = pObject->Read;
      LOBYTE(length) = 0;
      Read(pObject, (unsigned __int8 *)&length, 1);
      v7 = valueRead->Data.Size + 1;
      if ( v7 >= valueRead->Data.Size )
      {
        if ( v7 >= valueRead->Data.Policy.Capacity )
          Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &valueRead->Data,
            valueRead,
            v7 + (v7 >> 2));
      }
      else if ( v7 < valueRead->Data.Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &valueRead->Data,
          valueRead,
          valueRead->Data.Size + 1);
      }
      v8 = &valueRead->Data.Data[v7 - 1];
      valueRead->Data.Size = v7;
      if ( v8 )
        *v8 = length;
      if ( ++i >= v4 )
        goto LABEL_13;
    }
    LeaveCriticalSection(&locker->cs);
    return 0;
  }
}
