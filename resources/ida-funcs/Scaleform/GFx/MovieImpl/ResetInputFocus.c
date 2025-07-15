void __thiscall Scaleform::GFx::MovieImpl::ResetInputFocus(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::Ptr<Scaleform::GFx::Sprite> controllerIdx)
{
  Scaleform::GFx::MovieImpl::SetFocusTo(this, 0, controllerIdx, GFx_FocusMovedByAS);
}
