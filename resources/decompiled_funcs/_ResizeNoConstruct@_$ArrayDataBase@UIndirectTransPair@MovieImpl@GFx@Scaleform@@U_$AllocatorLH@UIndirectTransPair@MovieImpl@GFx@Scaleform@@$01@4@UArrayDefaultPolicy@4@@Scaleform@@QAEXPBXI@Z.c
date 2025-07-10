void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::IndirectTransPair,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::IndirectTransPair,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::IndirectTransPair,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::IndirectTransPair,2>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newSize)
{
  unsigned int Size; // eax

  Size = this->Size;
  if ( newSize >= Size )
  {
    if ( newSize >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SocketThreadMgr::EventInfo,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SocketThreadMgr::EventInfo,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)this,
        pheapAddr,
        newSize + (newSize >> 2));
  }
  else
  {
    Scaleform::ConstructorMov<Scaleform::GFx::MovieImpl::IndirectTransPair>::DestructArray(
      &this->Data[newSize],
      Size - newSize);
    if ( newSize < this->Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SocketThreadMgr::EventInfo,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SocketThreadMgr::EventInfo,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)this,
        pheapAddr,
        newSize);
      this->Size = newSize;
      return;
    }
  }
  this->Size = newSize;
}
