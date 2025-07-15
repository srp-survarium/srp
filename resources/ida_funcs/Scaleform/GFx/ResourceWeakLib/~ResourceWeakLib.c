void __thiscall Scaleform::GFx::ResourceWeakLib::~ResourceWeakLib(Scaleform::GFx::ResourceWeakLib *this)
{
  _DWORD *p_EntryCount; // ecx
  Scaleform::HashSet<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp> > *p_Resources; // edi
  unsigned int v4; // eax
  unsigned int v5; // edx
  _DWORD *v6; // ecx
  _DWORD *v7; // esi
  int v8; // ecx
  unsigned int v9; // ecx
  _DWORD *v10; // edx
  Scaleform::MemoryHeap *pObject; // ecx
  int v12; // ecx
  int v13; // edx

  this->__vftable = (Scaleform::GFx::ResourceWeakLib_vtbl *)&Scaleform::GFx::ResourceWeakLib::`vftable';
  EnterCriticalSection(&this->ResourceLock.cs);
  p_EntryCount = &this->Resources.pTable->EntryCount;
  p_Resources = &this->Resources;
  if ( p_EntryCount )
  {
    v5 = p_EntryCount[1];
    v4 = 0;
    v6 = p_EntryCount + 2;
    do
    {
      if ( *v6 != -2 )
        break;
      ++v4;
      v6 += 4;
    }
    while ( v4 <= v5 );
    p_EntryCount = &this->Resources.pTable;
  }
  else
  {
    v4 = 0;
  }
  v7 = p_EntryCount;
  while ( v7 )
  {
    v8 = *v7;
    if ( !*v7 || (signed int)v4 > *(_DWORD *)(v8 + 4) )
      break;
    *(_DWORD *)(*(_DWORD *)(16 * v4 + v8 + 20) + 8) = 0;
    v9 = *(_DWORD *)(*v7 + 4);
    if ( (int)v4 <= (int)v9 && ++v4 <= v9 )
    {
      v10 = (_DWORD *)(*v7 + 16 * v4 + 8);
      do
      {
        if ( *v10 != -2 )
          break;
        ++v4;
        v10 += 4;
      }
      while ( v4 <= v9 );
    }
  }
  LeaveCriticalSection(&this->ResourceLock.cs);
  pObject = this->pImageHeap.pObject;
  if ( pObject )
    pObject->Release(pObject);
  if ( p_Resources->pTable )
  {
    v12 = 0;
    v13 = p_Resources->pTable->SizeMask + 1;
    do
    {
      if ( p_Resources->pTable[v12 + 1].EntryCount != -2 )
        p_Resources->pTable[v12 + 1].EntryCount = -2;
      v12 += 2;
      --v13;
    }
    while ( v13 );
    if ( p_Resources->pTable )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_Resources->pTable);
    p_Resources->pTable = 0;
  }
  Scaleform::Lock::~Lock(&this->ResourceLock);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
