void __thiscall Scaleform::GFx::ResourceWeakLib::UnpinAll(Scaleform::GFx::ResourceWeakLib *this)
{
  Scaleform::Lock *p_ResourceLock; // edi
  Scaleform::GFx::ResourceLib *pStrongLib; // eax
  const Scaleform::HashSetBase<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::AllocatorGH<Scaleform::GFx::Resource *,2>,Scaleform::HashsetEntry<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc> > *pHash; // ebx
  int Index; // esi
  unsigned int SizeMask; // edi
  int v7; // ecx
  unsigned int v8; // eax
  Scaleform::HashSetBase<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::AllocatorGH<Scaleform::GFx::Resource *,2>,Scaleform::HashsetEntry<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc> >::TableType *v9; // ecx
  Scaleform::Lock *v11; // [esp+Ch] [ebp-Ch]
  Scaleform::HashSetBase<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::AllocatorGH<Scaleform::GFx::Resource *,2>,Scaleform::HashsetEntry<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc> >::Iterator result; // [esp+10h] [ebp-8h] BYREF

  p_ResourceLock = &this->ResourceLock;
  v11 = &this->ResourceLock;
  EnterCriticalSection(&this->ResourceLock.cs);
  pStrongLib = this->pStrongLib;
  if ( pStrongLib )
  {
    Scaleform::HashSetBase<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::AllocatorGH<Scaleform::GFx::Resource *,2>,Scaleform::HashsetEntry<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc>>::Begin(
      &pStrongLib->PinSet,
      &result);
    pHash = result.pHash;
    Index = result.Index;
    while ( pHash && pHash->pTable && Index <= (signed int)pHash->pTable->SizeMask )
    {
      SizeMask = pHash->pTable[Index + 1].SizeMask;
      if ( InterlockedExchangeAdd((volatile LONG *)(SizeMask + 4), -1) == 1 )
      {
        v7 = *(_DWORD *)(SizeMask + 8);
        if ( v7 )
        {
          (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v7 + 4))(v7, SizeMask);
          *(_DWORD *)(SizeMask + 8) = 0;
        }
        (**(void (__thiscall ***)(unsigned int, int))SizeMask)(SizeMask, 1);
      }
      v8 = pHash->pTable->SizeMask;
      if ( Index <= (int)v8 && ++Index <= v8 )
      {
        v9 = &pHash->pTable[Index + 1];
        do
        {
          if ( v9->EntryCount != -2 )
            break;
          ++Index;
          ++v9;
        }
        while ( Index <= v8 );
      }
    }
    Scaleform::HashSetBase<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::AllocatorGH<Scaleform::GFx::Resource *,2>,Scaleform::HashsetEntry<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc>>::Clear(&this->pStrongLib->PinSet);
    p_ResourceLock = v11;
  }
  LeaveCriticalSection(&p_ResourceLock->cs);
}
