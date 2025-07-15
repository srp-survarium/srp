void __thiscall Scaleform::GFx::ResourceWeakLib::PinResource(Scaleform::GFx::ResourceWeakLib *this, unsigned int pres)
{
  Scaleform::Lock *p_ResourceLock; // ebp
  Scaleform::GFx::ResourceLib *pStrongLib; // eax
  Scaleform::HashSetBase<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::AllocatorGH<Scaleform::GFx::Resource *,2>,Scaleform::HashsetEntry<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc> >::TableType *pTable; // esi
  unsigned int v6; // ebx
  Scaleform::HashSetBase<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::AllocatorGH<Scaleform::GFx::Resource *,2>,Scaleform::HashsetEntry<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc> > *p_PinSet; // edi
  signed int v8; // eax

  p_ResourceLock = &this->ResourceLock;
  EnterCriticalSection(&this->ResourceLock.cs);
  pStrongLib = this->pStrongLib;
  if ( pStrongLib )
  {
    pTable = pStrongLib->PinSet.pTable;
    v6 = pres;
    p_PinSet = &pStrongLib->PinSet;
    if ( !pTable
      || (v8 = Scaleform::HashSetBase<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::AllocatorGH<Scaleform::GFx::Resource *,2>,Scaleform::HashsetEntry<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc>>::findIndexCore<Scaleform::GFx::Resource *>(
                 p_PinSet,
                 (Scaleform::GFx::Resource *const *)&pres,
                 pTable->SizeMask & (pres ^ (pres >> 6))),
          v8 < 0)
      || &pTable[v8] == (Scaleform::HashSetBase<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::AllocatorGH<Scaleform::GFx::Resource *,2>,Scaleform::HashsetEntry<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc> >::TableType *)-12 )
    {
      Scaleform::HashSetBase<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::AllocatorGH<Scaleform::GFx::Resource *,2>,Scaleform::HashsetEntry<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc>>::add<Scaleform::GFx::Resource *>(
        p_PinSet,
        p_PinSet,
        (Scaleform::GFx::Resource **)&pres,
        v6 ^ (v6 >> 6));
      InterlockedExchangeAdd((volatile LONG *)(v6 + 4), 1);
    }
  }
  LeaveCriticalSection(&p_ResourceLock->cs);
}
