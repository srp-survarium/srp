void __thiscall Scaleform::RefCountImpl::AddRef(Scaleform::GFx::Resource *this)
{
  InterlockedExchangeAdd(&this->RefCount.Value, 1);
}
