void __thiscall Scaleform::GFx::AS3::VM::Error::Error(
        Scaleform::GFx::AS3::VM::Error *this,
        Scaleform::GFx::AS3::VM::ErrorID id,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax
  Scaleform::GFx::ASStringNode *StringNode; // edi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v7; // zf
  void *v8; // edi
  Scaleform::String fullMsg; // [esp+Ch] [ebp-314h] BYREF
  int ind; // [esp+10h] [ebp-310h] BYREF
  Scaleform::MsgFormat::Sink r; // [esp+14h] [ebp-30Ch] BYREF
  Scaleform::MsgFormat v12; // [esp+20h] [ebp-300h] BYREF

  this->ID = id;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  this->Message.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  Scaleform::String::String(&fullMsg);
  r.SinkData.pStr = &fullMsg;
  ind = id;
  r.Type = tStr;
  Scaleform::MsgFormat::MsgFormat(&v12, &r);
  Scaleform::MsgFormat::Parse(&v12, "Error #{0}");
  Scaleform::MsgFormat::FormatD1<int>(&v12, &ind);
  Scaleform::MsgFormat::FinishFormatD(&v12);
  Scaleform::MsgFormat::~MsgFormat(&v12);
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 vm->StringManagerRef->pStringManager,
                 (char *)((fullMsg.HeapTypeBits & 0xFFFFFFFC) + 8),
                 *(_DWORD *)(fullMsg.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
  StringNode->RefCount += 2;
  pNode = this->Message.pNode;
  v7 = pNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  this->Message.pNode = StringNode;
  v7 = StringNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
  v8 = (void *)(fullMsg.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((fullMsg.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
}
