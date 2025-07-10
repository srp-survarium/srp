void __thiscall Scaleform::GFx::AS3::Instances::fl::Error::toStringProto(
        Scaleform::GFx::AS3::Instances::fl::Error *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringNode *v3; // eax
  Scaleform::GFx::ASString *v4; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v6; // zf
  Scaleform::GFx::ASStringNode *v7; // ebx
  Scaleform::GFx::ASStringNode *v8; // ecx
  unsigned int *p_RefCount; // eax
  char *v10; // ecx
  void *v11; // esi
  Scaleform::GFx::ASStringNode *v12; // [esp+Ch] [ebp-4h] BYREF

  this->pTraits.pObject->GetName(this->pTraits.pObject, (Scaleform::GFx::ASString *)&v12);
  v3 = v12;
  ++v12->RefCount;
  v4 = result;
  pNode = result->pNode;
  v6 = result->pNode->RefCount-- == 1;
  v7 = v3;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v8 = v12;
  p_RefCount = &v12->RefCount;
  v4->pNode = v7;
  if ( !--*p_RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  if ( this->message.pNode->Size )
  {
    v10 = (char *)((Scaleform::operator+((Scaleform::String *)&result, ": ", &this->message)->HeapTypeBits & 0xFFFFFFFC)
                 + 8);
    Scaleform::GFx::ASString::Append(v4, v10, (Scaleform::GFx::ASStringNode *)strlen(v10));
    v11 = (void *)((unsigned int)result & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)result & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v11);
  }
}
