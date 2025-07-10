void __thiscall Scaleform::GFx::ResourceBinding::ResourceBinding(
        Scaleform::GFx::ResourceBinding *this,
        Scaleform::MemoryHeap *pheap)
{
  this->pHeap = pheap;
  Scaleform::Lock::Lock(&this->ResourceLock, 0);
  this->pResources = 0;
  this->ResourceCount = 0;
  this->Frozen = 0;
  this->pOwnerDefRes = 0;
}
