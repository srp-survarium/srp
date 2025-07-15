void __thiscall Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(Scaleform::GFx::ASStringNode *this)
{
  Scaleform::String *v2; // eax
  void *v3; // edi
  Scaleform::GFx::ASStringManager *StringNode; // eax
  void *v5; // esi
  Scaleform::String str; // [esp+Ch] [ebp-8h] BYREF
  Scaleform::String v7; // [esp+10h] [ebp-4h] BYREF

  Scaleform::String::String(&v7, (char *)this->pData, this->Size);
  Scaleform::String::ToLower(v2, &str);
  v3 = (void *)(v7.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v7.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v3);
  StringNode = (Scaleform::GFx::ASStringManager *)Scaleform::GFx::ASStringManager::CreateStringNode(
                                                    this->pManager,
                                                    (char *)((str.HeapTypeBits & 0xFFFFFFFC) + 8),
                                                    *(_DWORD *)(str.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
  if ( StringNode != (Scaleform::GFx::ASStringManager *)&this->pManager->EmptyStringNode )
  {
    this->pLower = (Scaleform::GFx::ASStringNode *)StringNode;
    if ( StringNode != (Scaleform::GFx::ASStringManager *)this )
      ++StringNode->pHeap;
  }
  v5 = (void *)(str.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((str.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v5);
}
