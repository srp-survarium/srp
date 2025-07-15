double __thiscall Scaleform::GFx::MovieImpl::GetBackgroundAlpha(Scaleform::GFx::MovieImpl *this)
{
  return (float)((double)this->BackgroundColor.Channels.Alpha / 255.0);
}
