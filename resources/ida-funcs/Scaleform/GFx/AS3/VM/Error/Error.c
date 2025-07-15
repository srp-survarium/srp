void __thiscall Scaleform::GFx::AS3::VM::Error::Error(
        Scaleform::GFx::AS3::VM::Error *this,
        Scaleform::GFx::AS3::VM::ErrorID id,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v3; // ebx
  Scaleform::GFx::AS3::VM::ErrorID v5; // edi
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax
  Scaleform::GFx::ASStringNode *StringNode; // edi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v9; // zf
  void *v10; // edi
  int ind; // [esp+Ch] [ebp-10h] BYREF
  Scaleform::MsgFormat::Sink result; // [esp+10h] [ebp-Ch] BYREF

  v3 = vm;
  v5 = id;
  this->ID = id;
  p_EmptyStringNode = &v3->StringManagerRef->pStringManager->EmptyStringNode;
  this->Message.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  Scaleform::String::String((Scaleform::String *)&id);
  ind = v5;
  vm = (Scaleform::GFx::AS3::VM *)Scaleform::GFx::AS3::GetErrorMsg(v5);
  result.SinkData.pStr = (Scaleform::String *)&id;
  result.Type = tStr;
  Scaleform::Format<int,char const *>(&result, "Error #{0}: {1}", &ind, (const char **)&vm);
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 v3->StringManagerRef->pStringManager,
                 (__m128i *)((id & 0xFFFFFFFC) + 8),
                 *(_DWORD *)(id & 0xFFFFFFFC) & 0x7FFFFFFF);
  StringNode->RefCount += 2;
  pNode = this->Message.pNode;
  v9 = pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  this->Message.pNode = StringNode;
  v9 = StringNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
  v10 = (void *)(id & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((id & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v10);
}


void __thiscall Scaleform::GFx::AS3::VM::Error::Error(
        Scaleform::GFx::AS3::VM::Error *this,
        Scaleform::GFx::AS3::VM_vtbl *id,
        Scaleform::GFx::ASStringNode *vm,
        Scaleform::GFx::AS3::Value *arg1,
        Scaleform::GFx::AS3::Value *arg2)
{
  Scaleform::GFx::AS3::VM *v5; // ebx
  Scaleform::GFx::AS3::VM::ErrorID v7; // edi
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // ebp
  Scaleform::GFx::AS3::Value *v10; // ecx
  Scaleform::GFx::ASStringManager *pStringManager; // eax
  Scaleform::GFx::AS3::VM_vtbl *pData; // eax
  char *ErrorMsg; // eax
  Scaleform::GFx::ASStringNode *StringNode; // edi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v16; // zf
  Scaleform::GFx::ASStringNode *v17; // eax
  Scaleform::GFx::ASStringNode *v18; // eax
  void *v19; // edi
  void *v20; // edi
  Scaleform::GFx::ASString s1; // [esp+10h] [ebp-1Ch] BYREF
  Scaleform::String tmpMsg; // [esp+14h] [ebp-18h] BYREF
  Scaleform::String fullMsg; // [esp+18h] [ebp-14h] BYREF
  int ind; // [esp+1Ch] [ebp-10h] BYREF
  Scaleform::MsgFormat::Sink result; // [esp+20h] [ebp-Ch] BYREF

  v5 = (Scaleform::GFx::AS3::VM *)vm;
  v7 = (Scaleform::GFx::AS3::VM::ErrorID)id;
  this->ID = (Scaleform::GFx::AS3::VM::ErrorID)id;
  p_EmptyStringNode = &v5->StringManagerRef->pStringManager->EmptyStringNode;
  this->Message.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  Scaleform::String::String(&fullMsg);
  Scaleform::String::String(&tmpMsg);
  StringManagerRef = v5->StringManagerRef;
  v10 = arg1;
  s1.pNode = &StringManagerRef->pStringManager->EmptyStringNode;
  ++s1.pNode->RefCount;
  ind = v7;
  Scaleform::GFx::AS3::Value::Convert2String(v10, (Scaleform::GFx::AS3::CheckResult *)&id, &s1);
  pStringManager = StringManagerRef->pStringManager;
  vm = &pStringManager->EmptyStringNode;
  ++pStringManager->EmptyStringNode.RefCount;
  Scaleform::GFx::AS3::Value::Convert2String(
    arg2,
    (Scaleform::GFx::AS3::CheckResult *)&id,
    (Scaleform::GFx::ASString *)&vm);
  pData = (Scaleform::GFx::AS3::VM_vtbl *)vm->pData;
  arg1 = (Scaleform::GFx::AS3::Value *)s1.pNode->pData;
  id = pData;
  result.Type = tStr;
  result.SinkData.pStr = &tmpMsg;
  ErrorMsg = (char *)Scaleform::GFx::AS3::GetErrorMsg(v7);
  Scaleform::Format<char const *,char const *>(&result, ErrorMsg, (const char **)&arg1, (const char **)&id);
  result.SinkData.pStr = &fullMsg;
  result.Type = tStr;
  Scaleform::Format<int,Scaleform::String>(&result, "Error #{0}: {1}", &ind, (const Scaleform::StringLH *)&tmpMsg);
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 v5->StringManagerRef->pStringManager,
                 (__m128i *)((fullMsg.HeapTypeBits & 0xFFFFFFFC) + 8),
                 *(_DWORD *)(fullMsg.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
  StringNode->RefCount += 2;
  pNode = this->Message.pNode;
  v16 = pNode->RefCount-- == 1;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  this->Message.pNode = StringNode;
  v16 = StringNode->RefCount-- == 1;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
  v17 = vm;
  --vm->RefCount;
  if ( !v17->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
  v18 = s1.pNode;
  --s1.pNode->RefCount;
  if ( !v18->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  v19 = (void *)(tmpMsg.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((tmpMsg.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v19);
  v20 = (void *)(fullMsg.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((fullMsg.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v20);
}


void __thiscall Scaleform::GFx::AS3::VM::Error::Error(
        Scaleform::GFx::AS3::VM::Error *this,
        Scaleform::GFx::AS3::VM_vtbl *id,
        Scaleform::GFx::ASStringNode *vm,
        Scaleform::GFx::AS3::Value *arg1)
{
  Scaleform::GFx::AS3::VM *v4; // ebx
  Scaleform::GFx::AS3::VM_vtbl *v6; // edi
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax
  Scaleform::GFx::AS3::Value *v8; // ecx
  char *ErrorMsg; // eax
  Scaleform::GFx::ASStringNode *StringNode; // edi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v12; // zf
  Scaleform::GFx::ASStringNode *v13; // eax
  void *v14; // edi
  void *v15; // edi
  Scaleform::String tmpMsg; // [esp+10h] [ebp-18h] BYREF
  Scaleform::String fullMsg; // [esp+14h] [ebp-14h] BYREF
  int ind; // [esp+18h] [ebp-10h] BYREF
  Scaleform::MsgFormat::Sink result; // [esp+1Ch] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::VM *)vm;
  v6 = id;
  this->ID = (Scaleform::GFx::AS3::VM::ErrorID)id;
  p_EmptyStringNode = &v4->StringManagerRef->pStringManager->EmptyStringNode;
  this->Message.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  Scaleform::String::String(&fullMsg);
  Scaleform::String::String(&tmpMsg);
  v8 = arg1;
  vm = &v4->StringManagerRef->pStringManager->EmptyStringNode;
  ++vm->RefCount;
  ind = (int)v6;
  Scaleform::GFx::AS3::Value::Convert2String(
    v8,
    (Scaleform::GFx::AS3::CheckResult *)&id,
    (Scaleform::GFx::ASString *)&vm);
  id = (Scaleform::GFx::AS3::VM_vtbl *)vm->pData;
  result.Type = tStr;
  result.SinkData.pStr = &tmpMsg;
  ErrorMsg = (char *)Scaleform::GFx::AS3::GetErrorMsg((int)v6);
  Scaleform::Format<char const *>(&result, ErrorMsg, (const char **)&id);
  result.SinkData.pStr = &fullMsg;
  result.Type = tStr;
  Scaleform::Format<int,Scaleform::String>(&result, "Error #{0}: {1}", &ind, (const Scaleform::StringLH *)&tmpMsg);
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 v4->StringManagerRef->pStringManager,
                 (__m128i *)((fullMsg.HeapTypeBits & 0xFFFFFFFC) + 8),
                 *(_DWORD *)(fullMsg.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
  StringNode->RefCount += 2;
  pNode = this->Message.pNode;
  v12 = pNode->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  this->Message.pNode = StringNode;
  v12 = StringNode->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
  v13 = vm;
  --vm->RefCount;
  if ( !v13->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  v14 = (void *)(tmpMsg.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((tmpMsg.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v14);
  v15 = (void *)(fullMsg.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((fullMsg.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v15);
}


void __thiscall Scaleform::GFx::AS3::VM::Error::Error(
        Scaleform::GFx::AS3::VM::Error *this,
        Scaleform::GFx::AS3::VM_vtbl *id,
        Scaleform::GFx::ASStringNode *vm,
        Scaleform::GFx::AS3::Value *arg1,
        Scaleform::StringDataPtr arg2)
{
  Scaleform::GFx::AS3::VM *v5; // ebx
  Scaleform::GFx::AS3::VM_vtbl *v7; // edi
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax
  Scaleform::GFx::AS3::Value *v9; // ecx
  char *ErrorMsg; // eax
  Scaleform::GFx::ASStringNode *StringNode; // edi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v13; // zf
  Scaleform::GFx::ASStringNode *v14; // eax
  void *v15; // edi
  void *v16; // edi
  Scaleform::String tmpMsg; // [esp+10h] [ebp-18h] BYREF
  Scaleform::String fullMsg; // [esp+14h] [ebp-14h] BYREF
  int ind; // [esp+18h] [ebp-10h] BYREF
  Scaleform::MsgFormat::Sink result; // [esp+1Ch] [ebp-Ch] BYREF

  v5 = (Scaleform::GFx::AS3::VM *)vm;
  v7 = id;
  this->ID = (Scaleform::GFx::AS3::VM::ErrorID)id;
  p_EmptyStringNode = &v5->StringManagerRef->pStringManager->EmptyStringNode;
  this->Message.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  Scaleform::String::String(&fullMsg);
  Scaleform::String::String(&tmpMsg);
  v9 = arg1;
  vm = &v5->StringManagerRef->pStringManager->EmptyStringNode;
  ++vm->RefCount;
  ind = (int)v7;
  Scaleform::GFx::AS3::Value::Convert2String(
    v9,
    (Scaleform::GFx::AS3::CheckResult *)&id,
    (Scaleform::GFx::ASString *)&vm);
  id = (Scaleform::GFx::AS3::VM_vtbl *)vm->pData;
  result.Type = tStr;
  result.SinkData.pStr = &tmpMsg;
  ErrorMsg = (char *)Scaleform::GFx::AS3::GetErrorMsg((int)v7);
  Scaleform::Format<char const *,Scaleform::StringDataPtr>(&result, ErrorMsg, (const char **)&id, &arg2);
  result.SinkData.pStr = &fullMsg;
  result.Type = tStr;
  Scaleform::Format<int,Scaleform::String>(&result, "Error #{0}: {1}", &ind, (const Scaleform::StringLH *)&tmpMsg);
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 v5->StringManagerRef->pStringManager,
                 (__m128i *)((fullMsg.HeapTypeBits & 0xFFFFFFFC) + 8),
                 *(_DWORD *)(fullMsg.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
  StringNode->RefCount += 2;
  pNode = this->Message.pNode;
  v13 = pNode->RefCount-- == 1;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  this->Message.pNode = StringNode;
  v13 = StringNode->RefCount-- == 1;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
  v14 = vm;
  --vm->RefCount;
  if ( !v14->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  v15 = (void *)(tmpMsg.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((tmpMsg.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v15);
  v16 = (void *)(fullMsg.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((fullMsg.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v16);
}


void __thiscall Scaleform::GFx::AS3::VM::Error::Error(
        Scaleform::GFx::AS3::VM::Error *this,
        Scaleform::GFx::AS3::VM::ErrorID id,
        Scaleform::String vm,
        int arg1)
{
  Scaleform::GFx::AS3::VM *pData; // ebx
  Scaleform::GFx::AS3::VM::ErrorID v6; // edi
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax
  char *ErrorMsg; // eax
  Scaleform::GFx::ASStringNode *StringNode; // edi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v11; // zf
  void *v12; // edi
  void *v13; // edi
  int ind; // [esp+Ch] [ebp-10h] BYREF
  Scaleform::MsgFormat::Sink result; // [esp+10h] [ebp-Ch] BYREF

  pData = (Scaleform::GFx::AS3::VM *)vm.pData;
  v6 = id;
  this->ID = id;
  p_EmptyStringNode = &pData->StringManagerRef->pStringManager->EmptyStringNode;
  this->Message.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  Scaleform::String::String(&vm);
  Scaleform::String::String((Scaleform::String *)&id);
  ind = v6;
  result.Type = tStr;
  result.SinkData.pStr = (Scaleform::String *)&id;
  ErrorMsg = (char *)Scaleform::GFx::AS3::GetErrorMsg(v6);
  Scaleform::Format<long>(&result, ErrorMsg, &arg1);
  result.SinkData.pStr = &vm;
  result.Type = tStr;
  Scaleform::Format<int,Scaleform::String>(&result, "Error #{0}: {1}", &ind, (const Scaleform::StringLH *)&id);
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 pData->StringManagerRef->pStringManager,
                 (__m128i *)((vm.HeapTypeBits & 0xFFFFFFFC) + 8),
                 *(_DWORD *)(vm.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
  StringNode->RefCount += 2;
  pNode = this->Message.pNode;
  v11 = pNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  this->Message.pNode = StringNode;
  v11 = StringNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
  v12 = (void *)(id & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((id & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v12);
  v13 = (void *)(vm.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((vm.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v13);
}


void __thiscall Scaleform::GFx::AS3::VM::Error::Error(
        Scaleform::GFx::AS3::VM::Error *this,
        Scaleform::GFx::AS3::VM::ErrorID id,
        Scaleform::String vm,
        int arg1,
        int arg2)
{
  Scaleform::GFx::AS3::VM *pData; // ebx
  Scaleform::GFx::AS3::VM::ErrorID v7; // edi
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax
  char *ErrorMsg; // eax
  Scaleform::GFx::ASStringNode *StringNode; // edi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v12; // zf
  void *v13; // edi
  void *v14; // edi
  int ind; // [esp+Ch] [ebp-10h] BYREF
  Scaleform::MsgFormat::Sink result; // [esp+10h] [ebp-Ch] BYREF

  pData = (Scaleform::GFx::AS3::VM *)vm.pData;
  v7 = id;
  this->ID = id;
  p_EmptyStringNode = &pData->StringManagerRef->pStringManager->EmptyStringNode;
  this->Message.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  Scaleform::String::String(&vm);
  Scaleform::String::String((Scaleform::String *)&id);
  ind = v7;
  result.Type = tStr;
  result.SinkData.pStr = (Scaleform::String *)&id;
  ErrorMsg = (char *)Scaleform::GFx::AS3::GetErrorMsg(v7);
  Scaleform::Format<int,int>(&result, ErrorMsg, &arg1, &arg2);
  result.SinkData.pStr = &vm;
  result.Type = tStr;
  Scaleform::Format<int,Scaleform::String>(&result, "Error #{0}: {1}", &ind, (const Scaleform::StringLH *)&id);
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 pData->StringManagerRef->pStringManager,
                 (__m128i *)((vm.HeapTypeBits & 0xFFFFFFFC) + 8),
                 *(_DWORD *)(vm.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
  StringNode->RefCount += 2;
  pNode = this->Message.pNode;
  v12 = pNode->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  this->Message.pNode = StringNode;
  v12 = StringNode->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
  v13 = (void *)(id & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((id & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v13);
  v14 = (void *)(vm.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((vm.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v14);
}


void __thiscall Scaleform::GFx::AS3::VM::Error::Error(
        Scaleform::GFx::AS3::VM::Error *this,
        Scaleform::GFx::AS3::VM::ErrorID id,
        Scaleform::String vm,
        Scaleform::StringDataPtr arg1,
        Scaleform::StringDataPtr arg2)
{
  Scaleform::GFx::AS3::VM *pData; // ebx
  Scaleform::GFx::AS3::VM::ErrorID v7; // edi
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax
  char *ErrorMsg; // eax
  Scaleform::GFx::ASStringNode *StringNode; // edi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v12; // zf
  void *v13; // edi
  void *v14; // edi
  int ind; // [esp+Ch] [ebp-10h] BYREF
  Scaleform::MsgFormat::Sink result; // [esp+10h] [ebp-Ch] BYREF

  pData = (Scaleform::GFx::AS3::VM *)vm.pData;
  v7 = id;
  this->ID = id;
  p_EmptyStringNode = &pData->StringManagerRef->pStringManager->EmptyStringNode;
  this->Message.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  Scaleform::String::String(&vm);
  Scaleform::String::String((Scaleform::String *)&id);
  ind = v7;
  result.Type = tStr;
  result.SinkData.pStr = (Scaleform::String *)&id;
  ErrorMsg = (char *)Scaleform::GFx::AS3::GetErrorMsg(v7);
  Scaleform::Format<Scaleform::StringDataPtr,Scaleform::StringDataPtr>(&result, ErrorMsg, &arg1, &arg2);
  result.SinkData.pStr = &vm;
  result.Type = tStr;
  Scaleform::Format<int,Scaleform::String>(&result, "Error #{0}: {1}", &ind, (const Scaleform::StringLH *)&id);
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 pData->StringManagerRef->pStringManager,
                 (__m128i *)((vm.HeapTypeBits & 0xFFFFFFFC) + 8),
                 *(_DWORD *)(vm.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
  StringNode->RefCount += 2;
  pNode = this->Message.pNode;
  v12 = pNode->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  this->Message.pNode = StringNode;
  v12 = StringNode->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
  v13 = (void *)(id & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((id & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v13);
  v14 = (void *)(vm.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((vm.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v14);
}


void __thiscall Scaleform::GFx::AS3::VM::Error::Error(
        Scaleform::GFx::AS3::VM::Error *this,
        Scaleform::GFx::AS3::VM::ErrorID id,
        Scaleform::String vm,
        Scaleform::StringDataPtr arg1)
{
  Scaleform::GFx::AS3::VM *pData; // ebx
  Scaleform::GFx::AS3::VM::ErrorID v6; // edi
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax
  char *ErrorMsg; // eax
  Scaleform::GFx::ASStringNode *StringNode; // edi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v11; // zf
  void *v12; // edi
  void *v13; // edi
  int ind; // [esp+Ch] [ebp-10h] BYREF
  Scaleform::MsgFormat::Sink result; // [esp+10h] [ebp-Ch] BYREF

  pData = (Scaleform::GFx::AS3::VM *)vm.pData;
  v6 = id;
  this->ID = id;
  p_EmptyStringNode = &pData->StringManagerRef->pStringManager->EmptyStringNode;
  this->Message.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  Scaleform::String::String(&vm);
  Scaleform::String::String((Scaleform::String *)&id);
  ind = v6;
  result.Type = tStr;
  result.SinkData.pStr = (Scaleform::String *)&id;
  ErrorMsg = (char *)Scaleform::GFx::AS3::GetErrorMsg(v6);
  Scaleform::Format<Scaleform::StringDataPtr>(&result, ErrorMsg, &arg1);
  result.SinkData.pStr = &vm;
  result.Type = tStr;
  Scaleform::Format<int,Scaleform::String>(&result, "Error #{0}: {1}", &ind, (const Scaleform::StringLH *)&id);
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 pData->StringManagerRef->pStringManager,
                 (__m128i *)((vm.HeapTypeBits & 0xFFFFFFFC) + 8),
                 *(_DWORD *)(vm.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
  StringNode->RefCount += 2;
  pNode = this->Message.pNode;
  v11 = pNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  this->Message.pNode = StringNode;
  v11 = StringNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
  v12 = (void *)(id & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((id & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v12);
  v13 = (void *)(vm.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((vm.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v13);
}


void __thiscall Scaleform::GFx::AS3::VM::Error::Error(
        Scaleform::GFx::AS3::VM::Error *this,
        Scaleform::GFx::AS3::VM_vtbl *id,
        Scaleform::GFx::ASStringNode *vm,
        Scaleform::StringDataPtr arg1,
        Scaleform::GFx::AS3::Value *arg2)
{
  Scaleform::GFx::AS3::VM *v5; // ebx
  Scaleform::GFx::AS3::VM_vtbl *v7; // edi
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax
  Scaleform::GFx::AS3::Value *v9; // ecx
  char *ErrorMsg; // eax
  Scaleform::GFx::ASStringNode *StringNode; // edi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v13; // zf
  Scaleform::GFx::ASStringNode *v14; // eax
  void *v15; // edi
  void *v16; // edi
  Scaleform::String tmpMsg; // [esp+10h] [ebp-18h] BYREF
  Scaleform::String fullMsg; // [esp+14h] [ebp-14h] BYREF
  int ind; // [esp+18h] [ebp-10h] BYREF
  Scaleform::MsgFormat::Sink result; // [esp+1Ch] [ebp-Ch] BYREF

  v5 = (Scaleform::GFx::AS3::VM *)vm;
  v7 = id;
  this->ID = (Scaleform::GFx::AS3::VM::ErrorID)id;
  p_EmptyStringNode = &v5->StringManagerRef->pStringManager->EmptyStringNode;
  this->Message.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  Scaleform::String::String(&fullMsg);
  Scaleform::String::String(&tmpMsg);
  v9 = arg2;
  vm = &v5->StringManagerRef->pStringManager->EmptyStringNode;
  ++vm->RefCount;
  ind = (int)v7;
  Scaleform::GFx::AS3::Value::Convert2String(
    v9,
    (Scaleform::GFx::AS3::CheckResult *)&id,
    (Scaleform::GFx::ASString *)&vm);
  id = (Scaleform::GFx::AS3::VM_vtbl *)vm->pData;
  result.Type = tStr;
  result.SinkData.pStr = &tmpMsg;
  ErrorMsg = (char *)Scaleform::GFx::AS3::GetErrorMsg((int)v7);
  Scaleform::Format<Scaleform::StringDataPtr,char const *>(&result, ErrorMsg, &arg1, (const char **)&id);
  result.SinkData.pStr = &fullMsg;
  result.Type = tStr;
  Scaleform::Format<int,Scaleform::String>(&result, "Error #{0}: {1}", &ind, (const Scaleform::StringLH *)&tmpMsg);
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 v5->StringManagerRef->pStringManager,
                 (__m128i *)((fullMsg.HeapTypeBits & 0xFFFFFFFC) + 8),
                 *(_DWORD *)(fullMsg.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
  StringNode->RefCount += 2;
  pNode = this->Message.pNode;
  v13 = pNode->RefCount-- == 1;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  this->Message.pNode = StringNode;
  v13 = StringNode->RefCount-- == 1;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
  v14 = vm;
  --vm->RefCount;
  if ( !v14->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  v15 = (void *)(tmpMsg.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((tmpMsg.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v15);
  v16 = (void *)(fullMsg.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((fullMsg.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v16);
}


void __thiscall Scaleform::GFx::AS3::VM::Error::Error(
        Scaleform::GFx::AS3::VM::Error *this,
        Scaleform::GFx::AS3::VM::ErrorID id,
        Scaleform::String vm,
        Scaleform::StringDataPtr arg1,
        int arg2,
        int arg3,
        int arg4)
{
  Scaleform::GFx::AS3::VM *pData; // ebx
  Scaleform::GFx::AS3::VM::ErrorID v9; // edi
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax
  char *ErrorMsg; // eax
  Scaleform::GFx::ASStringNode *StringNode; // edi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v14; // zf
  void *v15; // edi
  void *v16; // edi
  int ind; // [esp+Ch] [ebp-10h] BYREF
  Scaleform::MsgFormat::Sink result; // [esp+10h] [ebp-Ch] BYREF

  pData = (Scaleform::GFx::AS3::VM *)vm.pData;
  v9 = id;
  this->ID = id;
  p_EmptyStringNode = &pData->StringManagerRef->pStringManager->EmptyStringNode;
  this->Message.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  Scaleform::String::String(&vm);
  Scaleform::String::String((Scaleform::String *)&id);
  result.SinkData.pStr = (Scaleform::String *)&id;
  ind = v9;
  result.Type = tStr;
  ErrorMsg = (char *)Scaleform::GFx::AS3::GetErrorMsg(v9);
  Scaleform::Format<Scaleform::StringDataPtr,int,int,int>(&result, ErrorMsg, &arg1, &arg2, &arg3, &arg4);
  result.SinkData.pStr = &vm;
  result.Type = tStr;
  Scaleform::Format<int,Scaleform::String>(&result, "Error #{0}: {1}", &ind, (const Scaleform::StringLH *)&id);
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 pData->StringManagerRef->pStringManager,
                 (__m128i *)((vm.HeapTypeBits & 0xFFFFFFFC) + 8),
                 *(_DWORD *)(vm.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
  StringNode->RefCount += 2;
  pNode = this->Message.pNode;
  v14 = pNode->RefCount-- == 1;
  if ( v14 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  this->Message.pNode = StringNode;
  v14 = StringNode->RefCount-- == 1;
  if ( v14 )
    Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
  v15 = (void *)(id & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((id & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v15);
  v16 = (void *)(vm.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((vm.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v16);
}
