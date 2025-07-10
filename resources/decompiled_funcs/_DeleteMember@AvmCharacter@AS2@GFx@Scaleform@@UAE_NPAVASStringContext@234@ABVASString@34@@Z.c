char __thiscall Scaleform::GFx::AS2::AvmCharacter::DeleteMember(
        Scaleform::GFx::AS2::AvmCharacter *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *name)
{
  Scaleform::GFx::ASStringNode *v4; // eax
  bool v5; // zf
  int StandardMemberConstant; // eax
  int v7; // edi
  int v9; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v10; // esi
  unsigned int RefCount; // eax

  if ( (name->pNode->HashFlags & 0x20000000) == 0 )
  {
    if ( !Scaleform::GFx::ASConstString::GetLength(name) || Scaleform::GFx::ASConstString::GetCharAt(name, 0) != 95 )
      goto LABEL_14;
    v4 = Scaleform::GFx::ASConstString::ToLowerNode(name);
    ++v4->RefCount;
    if ( (v4->HashFlags & 0x10000000) == 0 )
    {
      v5 = v4->RefCount-- == 1;
      if ( v5 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v4);
      goto LABEL_14;
    }
    v5 = v4->RefCount-- == 1;
    if ( v5 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  }
  StandardMemberConstant = Scaleform::GFx::AS2::AvmCharacter::GetStandardMemberConstant(
                             (Scaleform::GFx::AS2::AvmCharacter *)((char *)this - 4),
                             name);
  v7 = StandardMemberConstant;
  if ( StandardMemberConstant != -1
    && StandardMemberConstant <= 32
    && (((int (__thiscall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[17].EntryCount)(&this[-1].EventHandlers)
      & (1 << StandardMemberConstant)) != 0 )
  {
    if ( v7 == 31 )
    {
      this->pProto.pObject[2].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::Object_vtbl *)((int)this->pProto.pObject[2].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable & 0xFFFFF9FF);
      return 1;
    }
    return 0;
  }
LABEL_14:
  v9 = ((int (__thiscall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[13].EntryCount)(&this[-1].EventHandlers);
  v10 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v9;
  if ( !v9 )
    return 0;
  *(_DWORD *)(v9 + 12) = (*(_DWORD *)(v9 + 12) + 1) & 0x8FFFFFFF;
  v5 = (*(unsigned __int8 (__thiscall **)(int, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *))(*(_DWORD *)(v9 + 16) + 24))(
         v9 + 16,
         psc,
         name) == 0;
  RefCount = v10->RefCount;
  if ( v5 )
  {
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      v10->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v10);
    }
    return 0;
  }
  if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
  {
    v10->RefCount = RefCount - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v10);
  }
  return 1;
}
