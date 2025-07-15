void __thiscall Scaleform::GFx::AS3::Instances::fl_net::Socket::writeMultiByte(
        Scaleform::GFx::AS3::Instances::fl_net::Socket *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::ASString *value,
        const Scaleform::GFx::ASString *charSet)
{
  Scaleform::GFx::AS3::Instances::fl_net::URLLoader *ID; // edi
  Scaleform::GFx::AS3::SocketThreadMgr *pObject; // ecx
  const char *v6; // ecx
  int v7; // esi
  const char *v8; // ecx
  int v9; // esi
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v11; // eax
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::StringDataPtr v14; // [esp-8h] [ebp-30h]
  Scaleform::GFx::AS3::VM::Error v15; // [esp+10h] [ebp-18h] BYREF
  Scaleform::WStringBuffer wbuff; // [esp+18h] [ebp-10h] BYREF

  ID = (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)this;
  pObject = this->SockMgr.pObject;
  v15.ID = (Scaleform::GFx::AS3::VM::ErrorID)ID;
  if ( Scaleform::GFx::AS3::SocketThreadMgr::IsRunning(pObject) )
  {
    v6 = Scaleform::GFx::AS3::Instances::fl_net::Socket::UTF8_Names[0];
    v7 = 0;
    if ( Scaleform::GFx::AS3::Instances::fl_net::Socket::UTF8_Names[0] )
    {
      while ( strcmp(charSet->pNode->pData, v6) )
      {
        v6 = off_8766D8[v7++];
        if ( !v6 )
        {
          ID = (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)v15.ID;
          goto LABEL_7;
        }
      }
      Scaleform::GFx::AS3::SocketThreadMgr::SendBytes(
        *(Scaleform::GFx::AS3::SocketThreadMgr **)(v15.ID + 44),
        value->pNode->pData,
        value->pNode->Size);
    }
    else
    {
LABEL_7:
      v8 = Scaleform::GFx::AS3::Instances::fl_net::Socket::UTF16_Names[0];
      v9 = 0;
      if ( Scaleform::GFx::AS3::Instances::fl_net::Socket::UTF16_Names[0] )
      {
        while ( strcmp(charSet->pNode->pData, v8) )
        {
          v8 = (&off_8766EC)[v9++];
          if ( !v8 )
          {
            ID = (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)v15.ID;
            goto LABEL_13;
          }
        }
        pNode = value->pNode;
        memset(&wbuff, 0, sizeof(wbuff));
        Scaleform::WStringBuffer::SetString(&wbuff, (char *)pNode->pData, pNode->Size);
        Scaleform::GFx::AS3::SocketThreadMgr::SendBytes(
          *(Scaleform::GFx::AS3::SocketThreadMgr **)(v15.ID + 44),
          (const char *)wbuff.pText,
          2 * wbuff.Length);
        Scaleform::WStringBuffer::~WStringBuffer(&wbuff);
      }
      else
      {
LABEL_13:
        pVM = ID->pTraits.pObject->pVM;
        v14.pStr = "charSet";
        v14.Size = 7;
        Scaleform::GFx::AS3::VM::Error::Error(&v15, eInvalidArgumentError, pVM, v14);
        Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v11);
        v12 = v15.Message.pNode;
        --v15.Message.pNode->RefCount;
        if ( !v12->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v12);
      }
    }
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl_net::Socket::ExecuteIOErrorEvent(
      ID,
      "AS3 Net Socket: Attempting to write to closed socket");
    Scaleform::GFx::AS3::Instances::fl_net::Socket::ThrowIOError((Scaleform::GFx::AS3::Instances::fl_net::Socket *)ID);
  }
}
