void __thiscall Scaleform::GFx::ResourceLib::BindHandle::~BindHandle(Scaleform::GFx::ResourceLib::BindHandle *this)
{
  if ( this->State == RS_Available )
  {
    Scaleform::GFx::Resource::Release(this->pResource);
  }
  else if ( this->State >= RS_WaitingResolve )
  {
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)this->pResource);
  }
}
