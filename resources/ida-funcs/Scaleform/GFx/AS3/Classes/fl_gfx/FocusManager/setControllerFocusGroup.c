void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::setControllerFocusGroup(
        Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this,
        bool *result,
        unsigned int controllerIdx,
        unsigned int focusGroupIdx)
{
  Scaleform::GFx::AS3::VM *pVM; // eax

  pVM = this->pTraits.pObject->pVM;
  if ( *(&pVM[1].HandleException + 4) )
    *result = (*(int (__thiscall **)(void (__thiscall *)(Scaleform::GFx::AS3::VM *), unsigned int, unsigned int))(*(_DWORD *)pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM + 220))(
                pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM,
                controllerIdx,
                focusGroupIdx);
  else
    *result = 0;
}
