Scaleform::GFx::ASStringNode *__thiscall Scaleform::GFx::ASConstString::ToUpperNode(
        Scaleform::GFx::ASConstString *this)
{
  Scaleform::String *v2; // eax
  void *v3; // esi
  Scaleform::GFx::ASStringNode *StringNode; // eax
  void *v5; // esi
  Scaleform::GFx::ASStringNode *v6; // edi
  Scaleform::String str; // [esp+Ch] [ebp-8h] BYREF
  Scaleform::String v9; // [esp+10h] [ebp-4h] BYREF

  Scaleform::String::String(&v9, (char *)this->pNode->pData, this->pNode->Size);
  Scaleform::String::ToUpper(v2, &str);
  v3 = (void *)(v9.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v9.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v3);
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 this->pNode->pManager,
                 (char *)((str.HeapTypeBits & 0xFFFFFFFC) + 8),
                 *(_DWORD *)(str.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
  v5 = (void *)(str.HeapTypeBits & 0xFFFFFFFC);
  v6 = StringNode;
  if ( InterlockedExchangeAdd((volatile LONG *)((str.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v5);
  return v6;
}
