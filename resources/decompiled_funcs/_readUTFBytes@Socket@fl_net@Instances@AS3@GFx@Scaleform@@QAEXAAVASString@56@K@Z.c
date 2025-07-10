void __thiscall Scaleform::GFx::AS3::Instances::fl_net::Socket::readUTFBytes(
        Scaleform::GFx::AS3::Instances::fl_net::Socket *this,
        Scaleform::GFx::ASString *result,
        unsigned int length)
{
  Scaleform::GFx::AS3::SocketThreadMgr *pObject; // ecx
  unsigned int Size; // eax
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v8; // zf
  Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> bytesRead; // [esp+4h] [ebp-Ch] BYREF

  if ( Scaleform::GFx::AS3::SocketThreadMgr::IsRunning(this->SockMgr.pObject) )
  {
    pObject = this->SockMgr.pObject;
    memset(&bytesRead, 0, sizeof(bytesRead));
    if ( Scaleform::GFx::AS3::SocketThreadMgr::ReadBytes(pObject, &bytesRead, length) )
    {
      Size = bytesRead.Data.Size;
      if ( length < bytesRead.Data.Size )
        Size = length;
      StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                     this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                     bytesRead.Data.Data,
                     Size);
      StringNode->RefCount += 2;
      pNode = result->pNode;
      v8 = result->pNode->RefCount-- == 1;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      result->pNode = StringNode;
      v8 = StringNode->RefCount-- == 1;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
    }
    else
    {
      Scaleform::GFx::AS3::Instances::fl_net::Socket::ExecuteIOErrorEvent(
        (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)this,
        "AS3 Net Socket: Failed to read UTF String");
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
