void __cdecl Scaleform::GFx::AS2::RectangleProto::ToString(Scaleform::String fn)
{
  Scaleform::String::DataDesc *pData; // esi
  int v2; // eax
  Scaleform::GFx::AS2::RectangleObject *v3; // edi
  Scaleform::GFx::ASStringNode *StringNode; // edi
  Scaleform::GFx::AS2::Value *RefCount; // esi
  bool v6; // zf
  void *v7; // esi
  Scaleform::GFx::ASString v8; // [esp+4h] [ebp-50h] BYREF
  Scaleform::GFx::ASString v9; // [esp+8h] [ebp-4Ch] BYREF
  Scaleform::GFx::ASString v10; // [esp+Ch] [ebp-48h] BYREF
  Scaleform::GFx::ASString v11; // [esp+10h] [ebp-44h] BYREF
  Scaleform::GFx::AS2::Value v12; // [esp+14h] [ebp-40h] BYREF
  Scaleform::GFx::AS2::Value v13; // [esp+24h] [ebp-30h] BYREF
  Scaleform::GFx::AS2::Value v14; // [esp+34h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value v15; // [esp+44h] [ebp-10h] BYREF

  pData = fn.pData;
  if ( *(_DWORD *)fn.pData->Data
    && (*(int (__thiscall **)(_DWORD))(**(_DWORD **)fn.pData->Data + 8))(*(_DWORD *)fn.pData->Data) == 17 )
  {
    v2 = *(_DWORD *)pData->Data;
    if ( v2 )
    {
      v3 = (Scaleform::GFx::AS2::RectangleObject *)(v2 - 16);
      if ( v2 != 16 )
      {
        `vector constructor iterator'(
          (char *)&v12,
          0x10u,
          4,
          (void *(__thiscall *)(void *))Scaleform::GFx::AS2::Value::Value);
        Scaleform::GFx::AS2::RectangleObject::GetProperties(
          v3,
          (Scaleform::GFx::ASStringNode *)(pData[2].Size + 116),
          &v12);
        Scaleform::GFx::AS2::Value::ToStringImpl(&v12, &v8, (Scaleform::GFx::AS2::Environment *)pData[2].Size, 6, 0);
        Scaleform::GFx::AS2::Value::ToStringImpl(&v13, &v9, (Scaleform::GFx::AS2::Environment *)pData[2].Size, 6, 0);
        Scaleform::GFx::AS2::Value::ToStringImpl(&v14, &v10, (Scaleform::GFx::AS2::Environment *)pData[2].Size, 6, 0);
        Scaleform::GFx::AS2::Value::ToStringImpl(&v15, &v11, (Scaleform::GFx::AS2::Environment *)pData[2].Size, 6, 0);
        Scaleform::String::String(&fn);
        Scaleform::String::AppendString(&fn, (const __m128i *)"(x=", 0xFFFFFFFF);
        Scaleform::String::AppendString(&fn, (const __m128i *)v8.pNode->pData, 0xFFFFFFFF);
        Scaleform::String::AppendString(&fn, (const __m128i *)", y=", 0xFFFFFFFF);
        Scaleform::String::AppendString(&fn, (const __m128i *)v9.pNode->pData, 0xFFFFFFFF);
        Scaleform::String::AppendString(&fn, (const __m128i *)", width=", 0xFFFFFFFF);
        Scaleform::String::AppendString(&fn, (const __m128i *)v10.pNode->pData, 0xFFFFFFFF);
        Scaleform::String::AppendString(&fn, (const __m128i *)", height=", 0xFFFFFFFF);
        Scaleform::String::AppendString(&fn, (const __m128i *)v11.pNode->pData, 0xFFFFFFFF);
        Scaleform::String::AppendString(&fn, (const __m128i *)")", 0xFFFFFFFF);
        StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                       *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(pData[2].Size + 116)
                                                                                   + 20)
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
        v6 = ++StringNode->RefCount == 1;
        --StringNode->RefCount;
        if ( v6 )
          Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
        v7 = (void *)(fn.HeapTypeBits & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd((volatile LONG *)((fn.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
        `vector destructor iterator'(
          (char *)&v8,
          4u,
          4,
          (void (__thiscall *)(void *))Scaleform::GFx::ASString::~ASString);
        `vector destructor iterator'(
          (char *)&v12,
          0x10u,
          4,
          (void (__thiscall *)(void *))Scaleform::GFx::AS2::Value::~Value);
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      (Scaleform::GFx::AS2::Environment *)pData[2].Size,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Rectangle");
  }
}
