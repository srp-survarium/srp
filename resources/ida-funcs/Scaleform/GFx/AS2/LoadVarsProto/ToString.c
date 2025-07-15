void __cdecl Scaleform::GFx::AS2::LoadVarsProto::ToString(Scaleform::String fn)
{
  Scaleform::String::DataDesc *pData; // edi
  int v2; // eax
  int v3; // esi
  unsigned int Size; // eax
  int Length; // eax
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::AS2::Value *RefCount; // edi
  bool v8; // zf
  void *v9; // esi
  _DWORD v10[3]; // [esp+10h] [ebp-Ch] BYREF

  pData = fn.pData;
  if ( *(_DWORD *)fn.pData->Data
    && (*(int (__thiscall **)(_DWORD))(**(_DWORD **)fn.pData->Data + 8))(*(_DWORD *)fn.pData->Data) == 27 )
  {
    v2 = *(_DWORD *)pData->Data;
    if ( v2 )
      v3 = v2 - 16;
    else
      v3 = 0;
    Scaleform::String::String(&fn);
    Size = pData[2].Size;
    v10[2] = &fn;
    v10[1] = Size;
    v10[0] = &`Scaleform::GFx::AS2::LoadVarsProto::ToString'::`7'::MemberVisitor::`vftable';
    (*(void (__thiscall **)(int, unsigned int, _DWORD *, _DWORD, _DWORD))(*(_DWORD *)(v3 + 16) + 32))(
      v3 + 16,
      Size + 116,
      v10,
      0,
      0);
    Length = Scaleform::String::GetLength(&fn);
    Scaleform::String::Remove(&fn, Length - 1, 1);
    StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                   *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(pData[2].Size + 116) + 20)
                                                                   + 12)
                                                       + 788),
                   (__m128i *)((fn.HeapTypeBits & 0xFFFFFFFC) + 8),
                   *(_DWORD *)(fn.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
    ++StringNode->RefCount;
    RefCount = (Scaleform::GFx::AS2::Value *)pData->RefCount;
    if ( RefCount->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(RefCount);
    RefCount->T.Type = 5;
    RefCount->NV.Int32Value = (int)StringNode;
    v8 = ++StringNode->RefCount == 1;
    --StringNode->RefCount;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
    v9 = (void *)(fn.HeapTypeBits & 0xFFFFFFFC);
    v10[0] = &Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
    if ( InterlockedExchangeAdd((volatile LONG *)((fn.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v9);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      (Scaleform::GFx::AS2::Environment *)pData[2].Size,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "LoadVars");
  }
}
