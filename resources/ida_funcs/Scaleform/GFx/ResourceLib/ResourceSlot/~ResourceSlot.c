void __thiscall Scaleform::GFx::ResourceLib::ResourceSlot::~ResourceSlot(
        Scaleform::GFx::ResourceLib::ResourceSlot *this)
{
  Scaleform::Lock *p_ResourceLock; // ebx
  Scaleform::GFx::Resource *volatile pResource; // edi
  Scaleform::GFx::ResourceLibBase *pLib; // ecx
  volatile LONG *v5; // edi
  Scaleform::GFx::ResourceKey::KeyInterface *pKeyInterface; // ecx
  Scaleform::GFx::ResourceWeakLib *pObject; // ecx

  p_ResourceLock = &this->pLib.pObject->ResourceLock;
  this->__vftable = (Scaleform::GFx::ResourceLib::ResourceSlot_vtbl *)&Scaleform::GFx::ResourceLib::ResourceSlot::`vftable';
  EnterCriticalSection(&p_ResourceLock->cs);
  if ( this->State )
  {
    if ( this->pResource )
    {
      pResource = this->pResource;
      if ( InterlockedExchangeAdd(&pResource->RefCount.Value, -1) == 1 )
      {
        pLib = pResource->pLib;
        if ( pLib )
        {
          pLib->RemoveResourceOnRelease(pLib, pResource);
          pResource->pLib = 0;
        }
        ((void (__thiscall *)(Scaleform::GFx::Resource *volatile, int))pResource->~Scaleform::GFx::Resource)(
          pResource,
          1);
      }
    }
  }
  else
  {
    Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp>>::RemoveAlt<Scaleform::GFx::ResourceKey>(
      &this->pLib.pObject->Resources,
      &this->Key);
  }
  LeaveCriticalSection(&p_ResourceLock->cs);
  Scaleform::Event::~Event(&this->ResolveComplete);
  v5 = (volatile LONG *)(this->ErrorMessage.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v5 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v5);
  pKeyInterface = this->Key.pKeyInterface;
  if ( pKeyInterface )
    pKeyInterface->Release(pKeyInterface, this->Key.hKeyData);
  pObject = this->pLib.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pObject);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
