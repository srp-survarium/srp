void __thiscall Scaleform::GFx::AS3::Class::toString(
        Scaleform::GFx::AS3::Class *this,
        Scaleform::GFx::ASString *result)
{
  const Scaleform::GFx::ASString *v3; // eax
  Scaleform::String *v4; // eax
  Scaleform::String *v5; // eax
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v8; // zf
  void *v9; // esi
  void *v10; // esi
  Scaleform::GFx::ASStringNode *v11; // eax
  Scaleform::String v12; // [esp+8h] [ebp-Ch] BYREF
  Scaleform::String v13; // [esp+Ch] [ebp-8h] BYREF
  Scaleform::GFx::ASStringNode *v14; // [esp+10h] [ebp-4h] BYREF

  v3 = this->pTraits.pObject->GetName(this->pTraits.pObject, &v14);
  v4 = Scaleform::operator+(&v13, "[class ", v3);
  v5 = Scaleform::String::operator+(v4, &v12, "]");
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                 (char *)((v5->HeapTypeBits & 0xFFFFFFFC) + 8),
                 *(_DWORD *)(v5->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
  StringNode->RefCount += 2;
  pNode = result->pNode;
  v8 = result->pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  result->pNode = StringNode;
  v8 = StringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
  v9 = (void *)(v12.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v12.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v9);
  v10 = (void *)(v13.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v13.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v10);
  v11 = v14;
  --v14->RefCount;
  if ( !v11->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
}
