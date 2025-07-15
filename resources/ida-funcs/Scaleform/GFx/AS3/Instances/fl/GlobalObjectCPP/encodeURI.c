void __thiscall Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::encodeURI(
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *this,
        Scaleform::GFx::ASString *result,
        const Scaleform::GFx::ASString *uri)
{
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v6; // zf
  void *v7; // esi
  Scaleform::String encodedStr; // [esp+8h] [ebp-4h] BYREF

  Scaleform::String::String(&encodedStr);
  Scaleform::GFx::ASUtils::AS3::EncodeURI((char *)uri->pNode->pData, uri->pNode->Size, &encodedStr, 0);
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                 (__m128i *)((encodedStr.HeapTypeBits & 0xFFFFFFFC) + 8),
                 *(_DWORD *)(encodedStr.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
  StringNode->RefCount += 2;
  pNode = result->pNode;
  v6 = result->pNode->RefCount-- == 1;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  result->pNode = StringNode;
  v6 = StringNode->RefCount-- == 1;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
  v7 = (void *)(encodedStr.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((encodedStr.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
}
