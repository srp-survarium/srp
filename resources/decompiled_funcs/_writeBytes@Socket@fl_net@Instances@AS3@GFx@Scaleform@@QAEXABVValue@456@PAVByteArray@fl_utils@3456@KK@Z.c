void __thiscall Scaleform::GFx::AS3::Instances::fl_net::Socket::writeBytes(
        Scaleform::GFx::AS3::Instances::fl_net::Socket *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *bytes,
        unsigned int offset,
        unsigned int length)
{
  unsigned int v6; // ecx
  unsigned int v7; // edx
  unsigned int v8; // eax
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v10; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v12; // [esp+4h] [ebp-8h] BYREF

  if ( Scaleform::GFx::AS3::SocketThreadMgr::IsRunning(this->SockMgr.pObject) )
  {
    if ( bytes )
    {
      v6 = bytes->Length;
      v7 = offset;
      if ( v6 < offset )
        v7 = bytes->Length;
      v8 = length;
      if ( !length )
        v8 = v6 - v7;
      if ( v8 <= v6 - v7 )
      {
        if ( v8 )
          Scaleform::GFx::AS3::SocketThreadMgr::SendBytes(
            this->SockMgr.pObject,
            (const char *)&bytes->Data.Data.Data[v7],
            v8);
      }
      else
      {
        pVM = this->pTraits.pObject->pVM;
        Scaleform::GFx::AS3::VM::Error::Error(&v12, eParamRangeError, pVM);
        Scaleform::GFx::AS3::VM::ThrowRangeError(pVM, v10);
        pNode = v12.Message.pNode;
        --v12.Message.pNode->RefCount;
        if ( !pNode->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      }
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
