void __thiscall Scaleform::GFx::CharacterHandle::CharacterHandle(
        Scaleform::GFx::CharacterHandle *this,
        Scaleform::String name,
        Scaleform::GFx::DisplayObject *pparent,
        Scaleform::GFx::DisplayObject *pcharacter)
{
  const Scaleform::GFx::ASString *pData; // edi
  Scaleform::GFx::ASStringNode *Size; // eax
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::DisplayObject *v9; // eax
  unsigned __int8 AvmObjOffset; // al
  Scaleform::GFx::ASStringNode *StringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // ecx
  bool v13; // zf
  void *v14; // edi

  pData = (const Scaleform::GFx::ASString *)name.pData;
  Size = (Scaleform::GFx::ASStringNode *)name.pData->Size;
  this->Name.pNode = (Scaleform::GFx::ASStringNode *)name.pData->Size;
  ++Size->RefCount;
  p_EmptyStringNode = &pData->pNode->pManager->EmptyStringNode;
  this->NamePath.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  pNode = pData->pNode;
  this->OriginalName = (Scaleform::GFx::ASString)pData->pNode;
  ++pNode->RefCount;
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
      Scaleform::String::AppendString(
        &name,
        (char *)&stru_957BE0.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags,
        0xFFFFFFFF);
    }
    Scaleform::String::AppendString(&name, (char *)this->Name.pNode->pData, 0xFFFFFFFF);
    StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                   pData->pNode->pManager,
                   (char *)((name.HeapTypeBits & 0xFFFFFFFC) + 8),
                   *(_DWORD *)(name.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
    StringNode->RefCount += 2;
    v12 = this->NamePath.pNode;
    v13 = v12->RefCount-- == 1;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
    this->NamePath.pNode = StringNode;
    v13 = StringNode->RefCount-- == 1;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
    v14 = (void *)(name.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((name.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v14);
  }
}
