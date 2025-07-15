void __thiscall Scaleform::GFx::AS2::AvmCharacter::VisitMembers(
        Scaleform::GFx::AS2::AvmCharacter *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *pvisitor,
        unsigned int visitFlags,
        const Scaleform::GFx::AS2::ObjectInterface *__formal)
{
  int v6; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v7; // esi
  unsigned int RefCount; // eax

  v6 = ((int (__thiscall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[12].SizeMask)(&this[-1].EventHandlers);
  v7 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v6;
  if ( v6 )
  {
    *(_DWORD *)(v6 + 12) = (*(_DWORD *)(v6 + 12) + 1) & 0x8FFFFFFF;
    (*(void (__thiscall **)(int, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *, unsigned int, Scaleform::GFx::AS2::AvmCharacter *))(*(_DWORD *)(v6 + 16) + 32))(
      v6 + 16,
      psc,
      pvisitor,
      visitFlags,
      this != (Scaleform::GFx::AS2::AvmCharacter *)4 ? this : 0);
    RefCount = v7->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      v7->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v7);
    }
  }
}
