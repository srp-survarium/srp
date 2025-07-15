void __thiscall Scaleform::HeapMH::RootMH::~RootMH(Scaleform::HeapMH::RootMH *this)
{
  Scaleform::HeapMH::RootMH::FreeTables(this);
  Scaleform::HeapMH::GlobalRootMH = 0;
  Scaleform::Lock::~Lock(&this->RootLock.mLock);
}
