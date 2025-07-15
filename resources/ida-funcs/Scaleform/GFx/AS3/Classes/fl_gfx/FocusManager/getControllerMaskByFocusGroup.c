void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::getControllerMaskByFocusGroup(
        Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this,
        unsigned int *result,
        unsigned int focusGroupIdx)
{
  Scaleform::GFx::AS3::VM *pVM; // eax

  pVM = this->pTraits.pObject->pVM;
  if ( *(&pVM[1].HandleException + 4) )
    *result = Scaleform::GFx::MovieImpl::GetControllerMaskByFocusGroup(
                (Scaleform::GFx::MovieImpl *)pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM,
                focusGroupIdx);
  else
    *result = 0;
}
