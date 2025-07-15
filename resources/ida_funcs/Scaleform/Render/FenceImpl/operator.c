BOOL __thiscall Scaleform::Render::FenceImpl::operator>(
        Scaleform::Render::FenceImpl *this,
        const Scaleform::Render::FenceImpl *fence)
{
  return this->FenceID > fence->FenceID;
}
