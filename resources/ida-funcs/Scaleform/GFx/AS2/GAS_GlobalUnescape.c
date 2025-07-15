void __cdecl Scaleform::GFx::AS2::GAS_GlobalUnescape(Scaleform::String fn)
{
  Scaleform::String::DataDesc *pData; // edi
  Scaleform::GFx::AS2::Value *RefCount; // esi
  Scaleform::GFx::AS2::Environment *Size; // eax
  Scaleform::GFx::AS2::Value *v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // ebx
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::AS2::Value *v7; // edi
  bool v8; // zf
  void *v9; // esi
  Scaleform::GFx::ASString v10; // [esp+8h] [ebp-4h] BYREF

  pData = fn.pData;
  RefCount = (Scaleform::GFx::AS2::Value *)fn.pData->RefCount;
  Scaleform::GFx::AS2::Value::DropRefs(RefCount);
  RefCount->T.Type = 0;
  if ( pData[2].RefCount == 1 )
  {
    Size = (Scaleform::GFx::AS2::Environment *)pData[2].Size;
    v4 = 0;
    if ( *(_DWORD *)pData[2].Data <= 32 * (Size->Stack.Pages.Data.Size - 1)
                                   + Size->Stack.pCurrent
                                   - Size->Stack.pPageStart )
      v4 = &Size->Stack.Pages.Data.Data[*(_DWORD *)pData[2].Data >> 5]->Values[*(_DWORD *)pData[2].Data & 0x1F];
    Scaleform::GFx::AS2::Value::ToStringImpl(v4, &v10, Size, -1, 0);
    Scaleform::String::String(&fn);
    pNode = v10.pNode;
    Scaleform::GFx::ASUtils::Unescape(v10.pNode->pData, v10.pNode->Size, &fn);
    StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                   *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(pData[2].Size + 116) + 20)
                                                                   + 12)
                                                       + 788),
                   (__m128i *)((fn.HeapTypeBits & 0xFFFFFFFC) + 8),
                   *(_DWORD *)(fn.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
    ++StringNode->RefCount;
    v7 = (Scaleform::GFx::AS2::Value *)pData->RefCount;
    if ( v7->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v7);
    v7->T.Type = 5;
    v7->NV.Int32Value = (int)StringNode;
    v8 = ++StringNode->RefCount == 1;
    --StringNode->RefCount;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
    v9 = (void *)(fn.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((fn.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v9);
    v8 = pNode->RefCount-- == 1;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
