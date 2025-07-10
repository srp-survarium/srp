void __thiscall Scaleform::GFx::CharacterHandle::ChangeName(
        Scaleform::GFx::CharacterHandle *this,
        Scaleform::String name,
        Scaleform::GFx::DisplayObject *pparent)
{
  const Scaleform::GFx::ASString *pData; // ebp
  Scaleform::GFx::ASStringNode *Size; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v7; // zf
  Scaleform::GFx::DisplayObject *v8; // esi
  unsigned __int8 AvmObjOffset; // al
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::ASStringNode *v11; // ecx
  void *v12; // esi

  pData = (const Scaleform::GFx::ASString *)name.pData;
  Size = (Scaleform::GFx::ASStringNode *)name.pData->Size;
  ++*(_DWORD *)(*(_DWORD *)name.HeapTypeBits + 12);
  pNode = this->Name.pNode;
  v7 = pNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  this->Name.pNode = Size;
  v8 = pparent;
  if ( pparent && pparent->pASRoot->AVMVersion == 1 )
  {
    Scaleform::String::String(&name);
    AvmObjOffset = v8->AvmObjOffset;
    if ( AvmObjOffset )
      (*(void (__thiscall **)(int, Scaleform::String *))(*((_DWORD *)&v8->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                         + AvmObjOffset)
                                                       + 24))(
        (int)v8 + 4 * AvmObjOffset,
        &name);
    Scaleform::String::AppendString(
      &name,
      (char *)&stru_957BE0.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags,
      0xFFFFFFFF);
    Scaleform::String::AppendString(&name, (char *)this->Name.pNode->pData, 0xFFFFFFFF);
    StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                   pData->pNode->pManager,
                   (char *)((name.HeapTypeBits & 0xFFFFFFFC) + 8),
                   *(_DWORD *)(name.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
    StringNode->RefCount += 2;
    v11 = this->NamePath.pNode;
    v7 = v11->RefCount-- == 1;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    this->NamePath.pNode = StringNode;
    v7 = StringNode->RefCount-- == 1;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
    v12 = (void *)(name.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((name.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v12);
  }
}
