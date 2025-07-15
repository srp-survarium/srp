void __thiscall Scaleform::HeapPT::HeapRoot::HeapRoot(
        Scaleform::HeapPT::HeapRoot *this,
        Scaleform::SysAllocPaged *sysAlloc)
{
  Scaleform::HeapPT::SysAllocWrapper::SysAllocWrapper(&this->AllocWrapper, sysAlloc);
  Scaleform::HeapPT::Starter::Starter(&this->AllocStarter, &this->AllocWrapper, 0x4000u, 0x1000u);
  Scaleform::HeapPT::Bookkeeper::Bookkeeper(&this->AllocBookkeeper, &this->AllocWrapper, 0x4000u);
  Scaleform::Lock::Lock(&this->RootLock.mLock, 0);
  this->pArenas = 0;
  this->NumArenas = 0;
  Scaleform::HeapPT::GlobalPageTable->pStarter = &this->AllocStarter;
  Scaleform::HeapPT::GlobalRoot = this;
}
