char __thiscall Scaleform::GFx::AS2::AvmCharacter::HasMember(
        Scaleform::GFx::AS2::AvmCharacter *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *name,
        int inclPrototypes)
{
  Scaleform::GFx::ASStringNode *v5; // eax
  bool v6; // zf
  int StandardMemberConstant; // eax
  int v9; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v10; // esi
  char v11; // bl
  unsigned int RefCount; // eax

  if ( (name->pNode->HashFlags & 0x20000000) == 0 )
  {
    if ( !Scaleform::GFx::ASConstString::GetLength(name) || Scaleform::GFx::ASConstString::GetCharAt(name, 0) != 95 )
      goto LABEL_13;
    v5 = Scaleform::GFx::ASConstString::ToLowerNode(name);
    ++v5->RefCount;
    if ( (v5->HashFlags & 0x10000000) == 0 )
    {
      v6 = v5->RefCount-- == 1;
      if ( v6 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v5);
      goto LABEL_13;
    }
    v6 = v5->RefCount-- == 1;
    if ( v6 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  }
  StandardMemberConstant = Scaleform::GFx::AS2::AvmCharacter::GetStandardMemberConstant(
                             (Scaleform::GFx::AS2::AvmCharacter *)((char *)this - 4),
                             name);
  if ( StandardMemberConstant != -1
    && StandardMemberConstant <= 32
    && (((int (__thiscall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[17].EntryCount)(&this[-1].EventHandlers)
      & (1 << StandardMemberConstant)) != 0 )
  {
    return 1;
  }
LABEL_13:
  v9 = ((int (__thiscall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[13].EntryCount)(&this[-1].EventHandlers);
  v10 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v9;
  if ( !v9 )
    return 0;
  *(_DWORD *)(v9 + 12) = (*(_DWORD *)(v9 + 12) + 1) & 0x8FFFFFFF;
  v11 = (*(int (__thiscall **)(int, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, int))(*(_DWORD *)(v9 + 16) + 36))(
          v9 + 16,
          psc,
          name,
          inclPrototypes);
  RefCount = v10->RefCount;
  if ( (RefCount & 0x3FFFFFF) != 0 )
  {
    v10->RefCount = RefCount - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v10);
  }
  return v11;
}
