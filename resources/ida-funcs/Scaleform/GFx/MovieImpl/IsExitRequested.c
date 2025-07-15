unsigned int __thiscall Scaleform::GFx::MovieImpl::IsExitRequested(Scaleform::GFx::MovieImpl *this)
{
  return (this->Flags >> 21) & 1;
}
