void __thiscall Scaleform::GFx::AS3::Instances::fl_net::Socket::readBytes(
        Scaleform::GFx::AS3::Instances::fl_net::Socket *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *bytes,
        unsigned int offset,
        unsigned int length)
{
  Scaleform::GFx::AS3::SocketThreadMgr *pObject; // ecx
  const Scaleform::GFx::AS3::Value *Undefined; // eax
  const Scaleform::GFx::AS3::Value *v8; // eax
  unsigned int i; // esi
  const Scaleform::GFx::AS3::Value *v10; // eax
  unsigned __int8 v11; // [esp-8h] [ebp-18h]
  Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> bytesRead; // [esp+4h] [ebp-Ch] BYREF

  if ( Scaleform::GFx::AS3::SocketThreadMgr::IsRunning(this->SockMgr.pObject) )
  {
    pObject = this->SockMgr.pObject;
    memset(&bytesRead, 0, sizeof(bytesRead));
    if ( Scaleform::GFx::AS3::SocketThreadMgr::ReadBytes(pObject, &bytesRead, length) )
    {
      if ( offset + length >= bytesRead.Data.Size )
      {
        Undefined = Scaleform::GFx::AS3::Value::GetUndefined();
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::lengthSet(bytes, Undefined, offset + length);
      }
      v8 = Scaleform::GFx::AS3::Value::GetUndefined();
      Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::positionSet(bytes, v8, offset);
      for ( i = 0; i < bytesRead.Data.Size; ++i )
      {
        v11 = bytesRead.Data.Data[i];
        v10 = Scaleform::GFx::AS3::Value::GetUndefined();
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::writeByte(bytes, v10, v11);
      }
    }
    else
    {
      Scaleform::GFx::AS3::Instances::fl_net::Socket::ExecuteIOErrorEvent(
        (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)this,
        "AS3 Net Socket: Failed to read Bytes");
      Scaleform::GFx::AS3::Instances::fl_net::Socket::ThrowEOFError(this);
    }
    if ( bytesRead.Data.Data )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, bytesRead.Data.Data);
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl_net::Socket::ExecuteIOErrorEvent(
      (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)this,
      "AS3 Net Socket: Attempting to read from closed socket");
    Scaleform::GFx::AS3::Instances::fl_net::Socket::ThrowIOError(this);
  }
}
