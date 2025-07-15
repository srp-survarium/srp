bool __thiscall Scaleform::GFx::MovieImpl::GetDirtyFlag(Scaleform::GFx::MovieImpl *this, bool doReset)
{
  bool result; // al

  if ( (this->Flags & 0x400) != 0
    || (result = Scaleform::Render::ContextImpl::Context::HasChanges(&this->RenderContext)) )
  {
    result = 1;
  }
  if ( doReset )
    this->Flags &= ~0x400u;
  return result;
}
