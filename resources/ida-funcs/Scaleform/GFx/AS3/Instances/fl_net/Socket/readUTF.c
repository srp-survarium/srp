void __thiscall Scaleform::GFx::AS3::Instances::fl_net::Socket::readUTF(
        Scaleform::GFx::AS3::Instances::fl_net::Socket *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::SocketThreadMgr *pObject; // ecx
  __int16 Size; // ax
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v7; // zf
  __int16 length; // [esp+4h] [ebp-10h] BYREF
  Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> bytesRead; // [esp+8h] [ebp-Ch] BYREF

  if ( Scaleform::GFx::AS3::SocketThreadMgr::IsRunning(this->SockMgr.pObject) )
  {
    if ( Scaleform::GFx::AS3::SocketThreadMgr::ReadShort(this->SockMgr.pObject, &length) )
    {
      pObject = this->SockMgr.pObject;
      memset(&bytesRead, 0, sizeof(bytesRead));
      if ( Scaleform::GFx::AS3::SocketThreadMgr::ReadBytes(pObject, &bytesRead, length) )
      {
        Size = length;
        if ( length >= SLOWORD(bytesRead.Data.Size) )
          Size = bytesRead.Data.Size;
        StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                       this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                       (wchar_t *)bytesRead.Data.Data,
                       Size);
        StringNode->RefCount += 2;
        pNode = result->pNode;
        v7 = result->pNode->RefCount-- == 1;
        if ( v7 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        result->pNode = StringNode;
        v7 = StringNode->RefCount-- == 1;
        if ( v7 )
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
        "AS3 Net Socket: Failed to read UTF String");
      Scaleform::GFx::AS3::Instances::fl_net::Socket::ThrowEOFError(this);
    }
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl_net::Socket::ExecuteIOErrorEvent(
      (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)this,
      "AS3 Net Socket: Attempting to read from closed socket");
    Scaleform::GFx::AS3::Instances::fl_net::Socket::ThrowIOError(this);
  }
}
