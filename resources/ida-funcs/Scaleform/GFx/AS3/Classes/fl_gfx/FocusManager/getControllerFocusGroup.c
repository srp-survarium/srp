void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::getControllerFocusGroup(
        Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this,
        unsigned int *result,
        unsigned int controllerIdx)
{
  Scaleform::GFx::AS3::VM *pVM; // eax

  pVM = this->pTraits.pObject->pVM;
  if ( *(&pVM[1].HandleException + 4) )
    *result = (*(int (__thiscall **)(void (__thiscall *)(Scaleform::GFx::AS3::VM *), unsigned int))(*(_DWORD *)pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM
                                                                                                  + 224))(
                pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM,
                controllerIdx);
  else
    *result = 0;
}
