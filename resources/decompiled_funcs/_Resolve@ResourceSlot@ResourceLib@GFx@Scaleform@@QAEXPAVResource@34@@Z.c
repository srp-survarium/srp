void __thiscall Scaleform::GFx::ResourceLib::ResourceSlot::Resolve(
        Scaleform::GFx::ResourceLib::ResourceSlot *this,
        Scaleform::GFx::Resource *pres)
{
  Scaleform::Lock *p_ResourceLock; // ebx
  Scaleform::HashSet<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp> > *p_Resources; // edi
  Scaleform::GFx::ResourceKey *p_Key; // ebp
  int v6; // eax
  signed int v7; // eax
  Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp> >::TableType *v8; // eax

  p_ResourceLock = &this->pLib.pObject->ResourceLock;
  EnterCriticalSection(&p_ResourceLock->cs);
  InterlockedExchangeAdd(&pres->RefCount.Value, 1);
  this->pResource = pres;
  p_Resources = &this->pLib.pObject->Resources;
  this->State = Resolve_Success;
  p_Key = &this->Key;
  if ( p_Resources->pTable
    && (!p_Key->pKeyInterface
      ? (v6 = 0)
      : (v6 = p_Key->pKeyInterface->GetHashCode(p_Key->pKeyInterface, this->Key.hKeyData)),
        v7 = Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp>>::findIndexCore<Scaleform::GFx::ResourceKey>(
               p_Resources,
               &this->Key,
               v6 & p_Resources->pTable->SizeMask),
        v7 >= 0) )
  {
    v8 = &p_Resources->pTable[2 * v7 + 2];
  }
  else
  {
    v8 = 0;
  }
  v8->SizeMask = (unsigned int)pres;
  v8->EntryCount = 0;
  pres->pLib = this->pLib.pObject;
  Scaleform::Event::SetEvent(&this->ResolveComplete);
  LeaveCriticalSection(&p_ResourceLock->cs);
}
