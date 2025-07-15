Scaleform::GFx::ASString *__cdecl Scaleform::GFx::AS3::GetThunkName(
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::ASString base,
        const Scaleform::GFx::AS3::ThunkInfo *thunk,
        Scaleform::String isClosure)
{
  char pData; // bl
  const char *NamespaceName; // esi
  unsigned int HeapTypeBits; // eax
  int v7; // edx
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::ASStringNode *pNode; // eax
  void *v10; // esi
  Scaleform::GFx::ASStringNode *v11; // eax
  Scaleform::GFx::ASStringNode *v12; // eax

  pData = (char)isClosure.pData;
  if ( base.pNode->Size )
  {
    Scaleform::GFx::ASString::Append(&base, (const __m128i *)"/", (Scaleform::GFx::ASStringNode *)1);
    if ( !pData )
      goto LABEL_14;
    NamespaceName = thunk->NamespaceName;
    if ( NamespaceName && *NamespaceName && strcmp(thunk->NamespaceName, Scaleform::GFx::AS3::NS_Vector) )
    {
      if ( !strcmp(thunk->NamespaceName, Scaleform::GFx::AS3::NS_AS3) )
      {
        Scaleform::GFx::ASString::operator+=(&base, (const __m128i *)"AS3");
      }
      else if ( !strcmp(thunk->NamespaceName, Scaleform::GFx::AS3::NS_flash_proxy) )
      {
        Scaleform::GFx::ASString::operator+=(&base, (const __m128i *)"flash_proxy");
      }
      else
      {
        Scaleform::GFx::ASString::operator+=(&base, (const __m128i *)thunk->NamespaceName);
      }
      Scaleform::GFx::ASString::operator+=(&base, (const __m128i *)"::");
    }
  }
  if ( pData )
  {
    HeapTypeBits = Scaleform::operator+(&isClosure, (const __m128i *)"MethodClosure ", &base)->HeapTypeBits;
    v7 = *(_DWORD *)(HeapTypeBits & 0xFFFFFFFC);
    goto LABEL_15;
  }
LABEL_14:
  HeapTypeBits = Scaleform::operator+(&isClosure, (const __m128i *)"Function ", &base)->HeapTypeBits;
  v7 = *(_DWORD *)(HeapTypeBits & 0xFFFFFFFC);
LABEL_15:
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 base.pNode->pManager,
                 (__m128i *)((HeapTypeBits & 0xFFFFFFFC) + 8),
                 v7 & 0x7FFFFFFF);
  ++StringNode->RefCount;
  pNode = base.pNode;
  --base.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  base.pNode = StringNode;
  v10 = (void *)(isClosure.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((isClosure.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v10);
  Scaleform::GFx::ASString::Append(
    &base,
    (const __m128i *)thunk->Name,
    (Scaleform::GFx::ASStringNode *)strlen(thunk->Name));
  Scaleform::GFx::ASString::Append(&base, (const __m128i *)"()", (Scaleform::GFx::ASStringNode *)2);
  v11 = base.pNode;
  ++base.pNode->RefCount;
  result->pNode = v11;
  v12 = base.pNode;
  --base.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  return result;
}
