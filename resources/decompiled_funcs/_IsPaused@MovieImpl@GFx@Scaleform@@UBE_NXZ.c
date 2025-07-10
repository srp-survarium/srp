unsigned int __thiscall Scaleform::GFx::MovieImpl::IsPaused(Scaleform::GFx::MovieImpl *this)
{
  return (this->Flags >> 20) & 1;
}
