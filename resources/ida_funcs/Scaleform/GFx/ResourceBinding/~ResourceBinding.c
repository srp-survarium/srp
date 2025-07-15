void __thiscall Scaleform::GFx::ResourceBinding::~ResourceBinding(Scaleform::GFx::ResourceBinding *this)
{
  Scaleform::GFx::ResourceBinding::Destroy(this);
  Scaleform::Lock::~Lock(&this->ResourceLock);
}
