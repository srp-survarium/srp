void __thiscall Scaleform::GFx::AS3::Instances::fl::QName::AS3toString(
        Scaleform::GFx::AS3::Instances::fl::QName *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // eax
  Scaleform::String *v4; // eax
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::ASStringNode *v6; // ecx
  bool v7; // zf
  void *v8; // esi
  Scaleform::GFx::ASStringNode *pNode; // edi
  Scaleform::GFx::ASStringNode *v10; // esi
  Scaleform::GFx::ASStringNode *v11; // ecx
  Scaleform::GFx::ASStringNode *v12; // ecx
  Scaleform::String v13; // [esp+8h] [ebp-4h] BYREF

  pObject = this->Ns.pObject;
  if ( pObject )
  {
    pNode = pObject->Uri.pNode;
    if ( pNode->Size )
    {
      ++pNode->RefCount;
      v12 = result->pNode;
      v7 = result->pNode->RefCount-- == 1;
      if ( v7 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v12);
      result->pNode = pNode;
      Scaleform::GFx::ASString::Append(result, (const __m128i *)"::", (Scaleform::GFx::ASStringNode *)2);
      Scaleform::GFx::ASString::Append(result, (Scaleform::GFx::ASStringNode *)&this->LocalName);
    }
    else
    {
      v10 = this->LocalName.pNode;
      ++v10->RefCount;
      v11 = result->pNode;
      v7 = result->pNode->RefCount-- == 1;
      if ( v7 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v11);
      result->pNode = v10;
    }
  }
  else
  {
    v4 = Scaleform::operator+(&v13, (const __m128i *)"*::", &this->LocalName);
    StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                   result->pNode->pManager,
                   (__m128i *)((v4->HeapTypeBits & 0xFFFFFFFC) + 8),
                   *(_DWORD *)(v4->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
    ++StringNode->RefCount;
    v6 = result->pNode;
    v7 = result->pNode->RefCount-- == 1;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v6);
    result->pNode = StringNode;
    v8 = (void *)(v13.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((v13.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
  }
}
