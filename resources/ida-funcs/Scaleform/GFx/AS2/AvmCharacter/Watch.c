char __thiscall Scaleform::GFx::AS2::AvmCharacter::Watch(
        Scaleform::GFx::AS2::AvmCharacter *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        const Scaleform::GFx::ASString *prop,
        const Scaleform::GFx::AS2::FunctionRef *callback,
        const Scaleform::GFx::AS2::Value *userData)
{
  int v5; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v6; // esi
  char v7; // bl
  unsigned int RefCount; // eax

  v5 = ((int (__thiscall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[13].EntryCount)(&this[-1].EventHandlers);
  v6 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v5;
  if ( !v5 )
    return 0;
  *(_DWORD *)(v5 + 12) = (*(_DWORD *)(v5 + 12) + 1) & 0x8FFFFFFF;
  v7 = (*(int (__thiscall **)(int, Scaleform::GFx::AS2::ASStringContext *, const Scaleform::GFx::ASString *, const Scaleform::GFx::AS2::FunctionRef *, const Scaleform::GFx::AS2::Value *))(*(_DWORD *)(v5 + 16) + 76))(
         v5 + 16,
         psc,
         prop,
         callback,
         userData);
  RefCount = v6->RefCount;
  if ( (RefCount & 0x3FFFFFF) != 0 )
  {
    v6->RefCount = RefCount - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
  }
  return v7;
}
