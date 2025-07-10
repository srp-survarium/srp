int __thiscall Scaleform::GFx::ResourceWeakLib::BindResourceKey(
        Scaleform::GFx::ResourceWeakLib *this,
        Scaleform::GFx::ResourceLib::BindHandle *phandle,
        const Scaleform::GFx::ResourceKey *k)
{
  __int32 Type; // esi
  Scaleform::Lock *p_ResourceLock; // ebp
  const Scaleform::GFx::ResourceKey *v5; // ebx
  Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp> > *v6; // edi
  unsigned int v7; // eax
  signed int v8; // eax
  int v9; // esi
  Scaleform::GFx::ResourceLib::BindHandle *v10; // eax
  Scaleform::GFx::ResourceLib::ResourceSlot *v12; // eax
  Scaleform::GFx::ResourceLib::ResourceSlot *v13; // eax
  Scaleform::GFx::Resource *v14; // esi
  Scaleform::GFx::ResourceLib::BindHandle *v15; // edi
  Scaleform::GFx::Resource *v16; // ecx
  Scaleform::GFx::ResourceLib::ResolveState State; // edi
  unsigned int v18; // eax
  Scaleform::GFx::ResourceLib::BindHandle *v19; // eax
  Scaleform::GFx::ResourceWeakLib::ResourceNode n; // [esp+10h] [ebp-8h] BYREF

  Type = (__int32)this;
  p_ResourceLock = &this->ResourceLock;
  n.Type = (Scaleform::GFx::ResourceWeakLib::ResourceNode::NodeType)this;
  EnterCriticalSection(&this->ResourceLock.cs);
  v5 = k;
  v6 = (Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp> > *)(Type + 36);
  if ( *(_DWORD *)(Type + 36) )
  {
    v7 = k->pKeyInterface ? k->pKeyInterface->GetHashCode(k->pKeyInterface, k->hKeyData) : 0;
    v8 = Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp>>::findIndexCore<Scaleform::GFx::ResourceKey>(
           (Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp> > *)(Type + 36),
           v5,
           v7 & v6->pTable->SizeMask);
    if ( v8 >= 0 )
    {
      v9 = (int)&v6->pTable[2 * v8 + 2];
      if ( v9 )
      {
        if ( *(_DWORD *)v9 )
        {
          v15 = phandle;
          v16 = *(Scaleform::GFx::Resource **)(v9 + 4);
          phandle->pResource = v16;
          v15->State = RS_WaitingResolve;
          Scaleform::RefCountImpl::AddRef(v16);
          State = v15->State;
          LeaveCriticalSection(&p_ResourceLock->cs);
          return State;
        }
        if ( Scaleform::GFx::Resource::AddRef_NotZero(*(Scaleform::GFx::Resource **)(v9 + 4)) )
        {
          v10 = phandle;
          phandle->pResource = *(Scaleform::GFx::Resource **)(v9 + 4);
          v10->State = RS_Available;
          LeaveCriticalSection(&p_ResourceLock->cs);
          return 1;
        }
        Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp>>::RemoveAlt<Scaleform::GFx::ResourceKey>(
          v6,
          v5);
      }
      Type = n.Type;
    }
  }
  v12 = (Scaleform::GFx::ResourceLib::ResourceSlot *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                       Scaleform::Memory::pGlobalHeap,
                                                       76,
                                                       0);
  if ( v12
    && (Scaleform::GFx::ResourceLib::ResourceSlot::ResourceSlot(v12, (Scaleform::GFx::Resource *)Type, v5),
        (v14 = (Scaleform::GFx::Resource *)v13) != 0) )
  {
    n.Type = Node_Resolver;
    n.pResolver = v13;
    v18 = Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp::operator()(
            (Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp *)&phandle,
            &n);
    Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp>>::add<Scaleform::GFx::ResourceWeakLib::ResourceNode>(
      v6,
      v6,
      &n,
      v18);
    v19 = phandle;
    phandle->pResource = v14;
    v19->State = RS_NeedsResolve;
    LeaveCriticalSection(&p_ResourceLock->cs);
    return 3;
  }
  else
  {
    LeaveCriticalSection(&p_ResourceLock->cs);
    return 4;
  }
}
