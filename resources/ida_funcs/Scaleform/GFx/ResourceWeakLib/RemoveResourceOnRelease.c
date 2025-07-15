void __thiscall Scaleform::GFx::ResourceWeakLib::RemoveResourceOnRelease(
        Scaleform::GFx::ResourceWeakLib *this,
        Scaleform::GFx::Resource *pres)
{
  Scaleform::Lock *p_ResourceLock; // ebp
  Scaleform::GFx::ResourceKey *v4; // eax
  Scaleform::HashSet<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp> > *p_Resources; // esi
  const Scaleform::GFx::ResourceKey *v6; // edi
  int v7; // eax
  signed int v8; // eax
  int v9; // edi
  const Scaleform::GFx::ResourceKey *v10; // eax
  int v11; // [esp+10h] [ebp-8h] BYREF
  int v12; // [esp+14h] [ebp-4h]

  p_ResourceLock = &this->ResourceLock;
  EnterCriticalSection(&this->ResourceLock.cs);
  v4 = pres->GetKey(pres, &v11);
  p_Resources = &this->Resources;
  v6 = v4;
  if ( p_Resources->pTable
    && (!v4->pKeyInterface ? (v7 = 0) : (v7 = v4->pKeyInterface->GetHashCode(v4->pKeyInterface, v4->hKeyData)),
        v8 = Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp>>::findIndexCore<Scaleform::GFx::ResourceKey>(
               p_Resources,
               v6,
               v7 & p_Resources->pTable->SizeMask),
        v8 >= 0) )
  {
    v9 = (int)&p_Resources->pTable[2 * v8 + 2];
  }
  else
  {
    v9 = 0;
  }
  if ( v11 )
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v11 + 8))(v11, v12);
  if ( v9 )
  {
    if ( !*(_DWORD *)v9 && *(Scaleform::GFx::Resource **)(v9 + 4) == pres )
    {
      v10 = pres->GetKey(pres, &v11);
      Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp>>::RemoveAlt<Scaleform::GFx::ResourceKey>(
        p_Resources,
        v10);
      if ( v11 )
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v11 + 8))(v11, v12);
    }
  }
  LeaveCriticalSection(&p_ResourceLock->cs);
}
