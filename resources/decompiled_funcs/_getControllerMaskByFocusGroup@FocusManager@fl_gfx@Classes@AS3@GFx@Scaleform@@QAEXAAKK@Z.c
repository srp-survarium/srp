void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::getControllerMaskByFocusGroup(
        Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this,
        unsigned int *result,
        unsigned int focusGroupIdx)
{
  Scaleform::GFx::AS3::VM *pVM; // eax

  pVM = this->pTraits.pObject->pVM;
  if ( LOBYTE(pVM[1].ExceptionObj.Bonus.pWeakProxy) )
    *result = Scaleform::GFx::MovieImpl::GetControllerMaskByFocusGroup(
                (Scaleform::GFx::MovieImpl *)pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM,
                focusGroupIdx);
  else
    *result = 0;
}
