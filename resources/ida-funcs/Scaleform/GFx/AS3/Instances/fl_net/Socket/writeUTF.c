void __thiscall Scaleform::GFx::AS3::Instances::fl_net::Socket::writeUTF(
        Scaleform::GFx::AS3::Instances::fl_net::Socket *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::ASString *value)
{
  unsigned int Size; // eax
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  unsigned __int16 v7; // di
  Scaleform::StringDataPtr v8; // [esp-8h] [ebp-1Ch]
  Scaleform::GFx::AS3::VM::Error v9; // [esp+Ch] [ebp-8h] BYREF

  if ( Scaleform::GFx::AS3::SocketThreadMgr::IsRunning(this->SockMgr.pObject) )
  {
    Size = value->pNode->Size;
    if ( Size <= 0xFFFF )
    {
      v7 = value->pNode->Size;
      Scaleform::GFx::AS3::SocketThreadMgr::SendShort(this->SockMgr.pObject, Size);
      Scaleform::GFx::AS3::SocketThreadMgr::SendBytes(this->SockMgr.pObject, value->pNode->pData, v7);
    }
    else
    {
      v8.pStr = "ByteArray::writeUTF";
      v8.Size = 19;
      Scaleform::GFx::AS3::VM::Error::Error(&v9, eNotImplementedError, this->pTraits.pObject->pVM, v8);
      Scaleform::GFx::AS3::VM::ThrowRangeError(this->pTraits.pObject->pVM, v5);
      pNode = v9.Message.pNode;
      --v9.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl_net::Socket::ExecuteIOErrorEvent(
      (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)this,
      "AS3 Net Socket: Attempting to write to closed socket");
    Scaleform::GFx::AS3::Instances::fl_net::Socket::ThrowIOError(this);
  }
}
