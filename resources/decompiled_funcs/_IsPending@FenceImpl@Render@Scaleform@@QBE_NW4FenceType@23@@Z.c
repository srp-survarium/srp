bool __thiscall Scaleform::Render::FenceImpl::IsPending(
        Scaleform::Render::FenceImpl *this,
        Scaleform::Render::FenceType waitType)
{
  Scaleform::Render::FenceFrame *Parent; // edx

  Parent = this->Parent;
  if ( Parent )
    return ((int (__thiscall *)(Scaleform::Render::RenderSync *, Scaleform::Render::FenceType, _DWORD, _DWORD, Scaleform::Render::FenceFrame *))this->RSContext->IsPending)(
             this->RSContext,
             waitType,
             this->APIHandle,
             HIDWORD(this->APIHandle),
             Parent);
  else
    return 0;
}
