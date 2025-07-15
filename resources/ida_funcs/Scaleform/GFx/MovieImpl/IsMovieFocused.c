unsigned int __thiscall Scaleform::GFx::MovieImpl::IsMovieFocused(Scaleform::GFx::MovieImpl *this)
{
  return (this->Flags >> 18) & 1;
}
