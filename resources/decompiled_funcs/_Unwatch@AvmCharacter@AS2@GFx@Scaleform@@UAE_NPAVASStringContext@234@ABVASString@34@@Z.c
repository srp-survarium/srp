char __thiscall Scaleform::GFx::AS2::AvmCharacter::Unwatch(
        Scaleform::GFx::AS2::AvmCharacter *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        const Scaleform::GFx::ASString *prop)
{
  int v3; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v4; // esi
  char v5; // bl
  unsigned int RefCount; // eax

  v3 = ((int (__thiscall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[13].EntryCount)(&this[-1].EventHandlers);
  v4 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v3;
  if ( !v3 )
    return 0;
  *(_DWORD *)(v3 + 12) = (*(_DWORD *)(v3 + 12) + 1) & 0x8FFFFFFF;
  v5 = (*(int (__thiscall **)(int, Scaleform::GFx::AS2::ASStringContext *, const Scaleform::GFx::ASString *))(*(_DWORD *)(v3 + 16) + 80))(
         v3 + 16,
         psc,
         prop);
  RefCount = v4->RefCount;
  if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
  {
    v4->RefCount = RefCount - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v4);
  }
  return v5;
}
