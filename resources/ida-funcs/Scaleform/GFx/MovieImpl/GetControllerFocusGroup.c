unsigned int __thiscall Scaleform::GFx::MovieImpl::GetControllerFocusGroup(
        Scaleform::GFx::MovieImpl *this,
        unsigned int controllerIdx)
{
  if ( controllerIdx < 0x10 )
    return this->FocusGroupIndexes[controllerIdx];
  else
    return 0;
}
