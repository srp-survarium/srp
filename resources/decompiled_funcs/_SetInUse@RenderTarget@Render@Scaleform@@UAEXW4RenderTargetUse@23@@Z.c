void __thiscall Scaleform::Render::RenderTarget::SetInUse(
        Scaleform::Render::RenderTarget *this,
        Scaleform::Render::RenderTargetUse inUse)
{
  this->SetInUse(this, inUse == RTUse_InUse);
}
