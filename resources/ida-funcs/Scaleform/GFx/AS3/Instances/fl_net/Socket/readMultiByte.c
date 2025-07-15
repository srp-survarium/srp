void __thiscall Scaleform::GFx::AS3::Instances::fl_net::Socket::readMultiByte(
        Scaleform::GFx::AS3::Instances::fl_net::Socket *this,
        Scaleform::GFx::ASString *result,
        unsigned int length,
        const Scaleform::GFx::ASString *charSet)
{
  Scaleform::GFx::AS3::SocketThreadMgr *pObject; // ecx
  Scaleform::GFx::AS3::VM *pVM; // edx
  const char *v7; // ecx
  int v8; // esi
  const char *v9; // ecx
  int v10; // esi
  unsigned int Size; // eax
  Scaleform::GFx::ASStringNode *StringNode; // eax
  Scaleform::GFx::ASStringNode *v13; // esi
  Scaleform::GFx::ASStringNode *v14; // ecx
  bool v15; // zf
  Scaleform::GFx::ASStringNode *v16; // ecx
  const char *v17; // ecx
  int v18; // esi
  const Scaleform::GFx::AS3::VM::Error *v19; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  unsigned int v21; // eax
  Scaleform::StringDataPtr v22; // [esp-8h] [ebp-2Ch]
  Scaleform::GFx::AS3::VM *vm; // [esp+Ch] [ebp-18h]
  Scaleform::GFx::AS3::VM::Error v24; // [esp+10h] [ebp-14h] BYREF
  Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> bytesRead; // [esp+18h] [ebp-Ch] BYREF

  if ( !Scaleform::GFx::AS3::SocketThreadMgr::IsRunning(this->SockMgr.pObject) )
  {
    Scaleform::GFx::AS3::Instances::fl_net::Socket::ExecuteIOErrorEvent(
      (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)this,
      "AS3 Net Socket: Attempting to read from closed socket");
    Scaleform::GFx::AS3::Instances::fl_net::Socket::ThrowIOError(this);
    return;
  }
  pObject = this->SockMgr.pObject;
  memset(&bytesRead, 0, sizeof(bytesRead));
  if ( !Scaleform::GFx::AS3::SocketThreadMgr::ReadBytes(pObject, &bytesRead, length) )
  {
    Scaleform::GFx::AS3::Instances::fl_net::Socket::ExecuteIOErrorEvent(
      (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)this,
      "AS3 Net Socket: Failed to read Bytes");
    Scaleform::GFx::AS3::Instances::fl_net::Socket::ThrowEOFError(this);
    goto LABEL_31;
  }
  pVM = this->pTraits.pObject->pVM;
  v7 = Scaleform::GFx::AS3::Instances::fl_net::Socket::ASCII_Names[0];
  v8 = 0;
  vm = pVM;
  if ( Scaleform::GFx::AS3::Instances::fl_net::Socket::ASCII_Names[0] )
  {
    while ( strcmp(charSet->pNode->pData, v7) )
    {
      v7 = off_8766AC[v8++];
      if ( !v7 )
        goto LABEL_8;
    }
    Size = bytesRead.Data.Size;
    if ( length < bytesRead.Data.Size )
      Size = length;
    goto LABEL_12;
  }
LABEL_8:
  v9 = Scaleform::GFx::AS3::Instances::fl_net::Socket::UTF8_Names[0];
  v10 = 0;
  if ( Scaleform::GFx::AS3::Instances::fl_net::Socket::UTF8_Names[0] )
  {
    while ( strcmp(charSet->pNode->pData, v9) )
    {
      v9 = off_8766D8[v10++];
      if ( !v9 )
        goto LABEL_19;
    }
    Size = bytesRead.Data.Size;
    if ( bytesRead.Data.Size > 2
      && *bytesRead.Data.Data == -17
      && bytesRead.Data.Data[1] == -69
      && bytesRead.Data.Data[2] == -65 )
    {
      Size = bytesRead.Data.Size - 3;
    }
LABEL_12:
    StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                   vm->StringManagerRef->pStringManager,
                   (__m128i *)bytesRead.Data.Data,
                   Size);
    goto LABEL_13;
  }
LABEL_19:
  v17 = Scaleform::GFx::AS3::Instances::fl_net::Socket::UTF16_Names[0];
  v18 = 0;
  if ( !Scaleform::GFx::AS3::Instances::fl_net::Socket::UTF16_Names[0] )
  {
LABEL_29:
    v22.pStr = "charSet";
    v22.Size = 7;
    Scaleform::GFx::AS3::VM::Error::Error(&v24, eInvalidArgumentError, vm, v22);
    Scaleform::GFx::AS3::VM::ThrowTypeError(vm, v19);
    pNode = v24.Message.pNode;
    --v24.Message.pNode->RefCount;
    v16 = pNode;
    if ( pNode->RefCount )
      goto LABEL_31;
    goto LABEL_30;
  }
  while ( strcmp(charSet->pNode->pData, v17) )
  {
    v17 = (&off_8766EC)[v18++];
    if ( !v17 )
      goto LABEL_29;
  }
  v21 = bytesRead.Data.Size;
  if ( length < bytesRead.Data.Size )
    v21 = length;
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 vm->StringManagerRef->pStringManager,
                 (wchar_t *)bytesRead.Data.Data,
                 v21);
LABEL_13:
  v13 = StringNode;
  StringNode->RefCount += 2;
  v14 = result->pNode;
  v15 = result->pNode->RefCount-- == 1;
  if ( v15 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  result->pNode = v13;
  v15 = v13->RefCount-- == 1;
  if ( !v15 )
    goto LABEL_31;
  v16 = v13;
LABEL_30:
  Scaleform::GFx::ASStringNode::ReleaseNode(v16);
LABEL_31:
  if ( bytesRead.Data.Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, bytesRead.Data.Data);
}
