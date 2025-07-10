char __thiscall Scaleform::GFx::AS2::AvmCharacter::SetMemberFlags(
        Scaleform::GFx::AS2::AvmCharacter *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        const Scaleform::GFx::ASString *name,
        int flags)
{
  int v4; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v5; // esi
  char v6; // bl
  unsigned int RefCount; // eax

  v4 = ((int (__thiscall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[13].EntryCount)(&this[-1].EventHandlers);
  v5 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v4;
  if ( !v4 )
    return 0;
  *(_DWORD *)(v4 + 12) = (*(_DWORD *)(v4 + 12) + 1) & 0x8FFFFFFF;
  v6 = (*(int (__thiscall **)(int, Scaleform::GFx::AS2::ASStringContext *, const Scaleform::GFx::ASString *, int))(*(_DWORD *)(v4 + 16) + 28))(
         v4 + 16,
         psc,
         name,
         flags);
  RefCount = v5->RefCount;
  if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
  {
    v5->RefCount = RefCount - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
  }
  return v6;
}
