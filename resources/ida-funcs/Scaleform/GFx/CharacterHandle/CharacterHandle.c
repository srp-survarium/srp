void __thiscall Scaleform::GFx::CharacterHandle::CharacterHandle(
        Scaleform::GFx::CharacterHandle *this,
        Scaleform::String name,
        Scaleform::GFx::DisplayObject *pparent,
        Scaleform::GFx::DisplayObject *pcharacter)
{
  Scaleform::GFx::ASStringNode **pData; // edi
  unsigned int v6; // eax
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax
  Scaleform::GFx::ASStringNode *v8; // eax
  Scaleform::GFx::DisplayObject *v9; // eax
  unsigned __int8 AvmObjOffset; // al
  Scaleform::GFx::ASStringNode *StringNode; // edi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v13; // zf
  void *v14; // edi

  pData = (Scaleform::GFx::ASStringNode **)name.pData;
  v6 = *(_DWORD *)name.HeapTypeBits;
  this->Name.pNode = (Scaleform::GFx::ASStringNode *)name.pData->Size;
  ++*(_DWORD *)(v6 + 12);
  p_EmptyStringNode = &(*pData)->pManager->EmptyStringNode;
  this->NamePath.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = *pData;
  this->OriginalName.pNode = *pData;
  ++v8->RefCount;
  v9 = pcharacter;
  this->RefCount = 1;
  this->pCharacter = v9;
  if ( v9 && v9->pASRoot->AVMVersion == 1 )
  {
    Scaleform::String::String(&name);
    if ( pparent )
    {
      AvmObjOffset = pparent->AvmObjOffset;
      if ( AvmObjOffset )
        (*(void (__thiscall **)(char *, Scaleform::String *))(*((_DWORD *)&pparent->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                              + AvmObjOffset)
                                                            + 24))(
          (char *)&pparent->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
        + 4 * AvmObjOffset,
          &name);
      Scaleform::String::AppendString(&name, (const __m128i *)".", 0xFFFFFFFF);
    }
    Scaleform::String::AppendString(&name, (const __m128i *)this->Name.pNode->pData, 0xFFFFFFFF);
    StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                   (*pData)->pManager,
                   (__m128i *)((name.HeapTypeBits & 0xFFFFFFFC) + 8),
                   *(_DWORD *)(name.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
    StringNode->RefCount += 2;
    pNode = this->NamePath.pNode;
    v13 = pNode->RefCount-- == 1;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    this->NamePath.pNode = StringNode;
    v13 = StringNode->RefCount-- == 1;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
    v14 = (void *)(name.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((name.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v14);
  }
}
