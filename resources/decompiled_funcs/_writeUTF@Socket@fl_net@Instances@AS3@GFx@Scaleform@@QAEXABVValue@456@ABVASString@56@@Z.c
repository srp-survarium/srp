void __thiscall Scaleform::GFx::AS3::Instances::fl_net::Socket::writeUTF(
        Scaleform::GFx::AS3::Instances::fl_net::Socket *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::ASString *value)
{
  unsigned int Size; // eax
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  unsigned __int16 v8; // di
  Scaleform::GFx::AS3::VM::Error v9; // [esp+4h] [ebp-8h] BYREF

  if ( Scaleform::GFx::AS3::SocketThreadMgr::IsRunning(this->SockMgr.pObject) )
  {
    Size = value->pNode->Size;
    if ( Size <= 0xFFFF )
    {
      v8 = value->pNode->Size;
      Scaleform::GFx::AS3::SocketThreadMgr::SendShort(this->SockMgr.pObject, Size);
      Scaleform::GFx::AS3::SocketThreadMgr::SendBytes(this->SockMgr.pObject, value->pNode->pData, v8);
    }
    else
    {
      pVM = this->pTraits.pObject->pVM;
      Scaleform::GFx::AS3::VM::Error::Error(&v9, eNotImplementedError, pVM);
      Scaleform::GFx::AS3::VM::ThrowRangeError(pVM, v6);
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
