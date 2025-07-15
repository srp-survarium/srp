void __cdecl Scaleform::GFx::AS2::StringProto::StringConcat(Scaleform::GFx::ASStringNode *fn)
{
  Scaleform::GFx::ASStringNode *v1; // esi
  Scaleform::GFx::ASStringNode *pLower; // eax
  const __m128i ***v3; // eax
  int i; // ebx
  Scaleform::GFx::AS2::Environment *pData; // edx
  unsigned int v6; // eax
  Scaleform::GFx::AS2::Value *v7; // ecx
  Scaleform::GFx::ASStringNode *v8; // edi
  bool v9; // zf
  __m128i *v10; // eax
  Scaleform::GFx::ASStringNode *StringNode; // edi
  Scaleform::GFx::AS2::Value *pManager; // esi
  Scaleform::StringBuffer v13; // [esp+4h] [ebp-18h] BYREF

  v1 = fn;
  if ( fn->pLower
    && (*((int (__thiscall **)(Scaleform::GFx::ASStringNode *))fn->pLower->$7DDA6D7E09E348E44B226E8441B9AFBF::pData + 2))(fn->pLower) == 8 )
  {
    pLower = v1->pLower;
    if ( pLower )
      v3 = (const __m128i ***)&pLower[-1].8;
    else
      v3 = 0;
    Scaleform::StringBuffer::StringBuffer(&v13, *v3[13], (unsigned int)v3[13][5], Scaleform::Memory::pGlobalHeap);
    for ( i = 0; i < (int)v1[1].pManager; ++i )
    {
      pData = (Scaleform::GFx::AS2::Environment *)v1[1].pData;
      v6 = (unsigned int)v1[1].pLower - i;
      v7 = 0;
      if ( v6 <= 32 * (pData->Stack.Pages.Data.Size - 1) + pData->Stack.pCurrent - pData->Stack.pPageStart )
        v7 = &pData->Stack.Pages.Data.Data[v6 >> 5]->Values[v6 & 0x1F];
      Scaleform::GFx::AS2::Value::ToStringImpl(v7, (Scaleform::GFx::ASString *)&fn, pData, -1, 0);
      v8 = fn;
      Scaleform::StringBuffer::AppendString(&v13, (const __m128i *)fn->pData, 0xFFFFFFFF);
      v9 = v8->RefCount-- == 1;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    }
    v10 = (__m128i *)v13.pData;
    if ( !v13.pData )
      v10 = (__m128i *)uri;
    StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                   *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)v1[1].pData + 29) + 20) + 12)
                                                       + 788),
                   v10,
                   v13.Size);
    ++StringNode->RefCount;
    pManager = (Scaleform::GFx::AS2::Value *)v1->pManager;
    if ( pManager->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(pManager);
    pManager->T.Type = 5;
    pManager->NV.Int32Value = (int)StringNode;
    v9 = ++StringNode->RefCount == 1;
    --StringNode->RefCount;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
    Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&v13);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      (Scaleform::GFx::AS2::Environment *)v1[1].pData,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "String");
  }
}
