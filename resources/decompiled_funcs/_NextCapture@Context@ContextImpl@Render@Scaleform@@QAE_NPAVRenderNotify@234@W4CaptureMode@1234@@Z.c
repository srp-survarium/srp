char __thiscall Scaleform::Render::ContextImpl::Context::NextCapture(
        Scaleform::Render::ContextImpl::Context *this,
        Scaleform::Render::ContextImpl::RenderNotify *pnotify,
        Scaleform::Render::ContextImpl::Context::CaptureMode mode)
{
  char v4; // bl
  Scaleform::Render::ContextImpl::Snapshot *displaySnaphot; // [esp+Ch] [ebp-4h] BYREF

  displaySnaphot = 0;
  v4 = Scaleform::Render::ContextImpl::Context::nextCapture_LockScope(this, &displaySnaphot, pnotify, mode);
  if ( displaySnaphot )
    Scaleform::Render::ContextImpl::Context::nextCapture_NotifyChanges(this, displaySnaphot, pnotify);
  return v4;
}
