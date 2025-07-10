void __thiscall Scaleform::Render::FenceImpl::WaitFence(
        Scaleform::Render::FenceImpl *this,
        Scaleform::Render::FenceType waitType)
{
  Scaleform::Render::FenceFrame *Parent; // edx

  Parent = this->Parent;
  if ( Parent )
    ((void (__thiscall *)(Scaleform::Render::RenderSync *, Scaleform::Render::FenceType, _DWORD, _DWORD, Scaleform::Render::FenceFrame *))this->RSContext->WaitFence)(
      this->RSContext,
      waitType,
      this->APIHandle,
      HIDWORD(this->APIHandle),
      Parent);
}
