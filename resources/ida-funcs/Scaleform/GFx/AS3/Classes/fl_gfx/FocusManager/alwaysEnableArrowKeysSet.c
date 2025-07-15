void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::alwaysEnableArrowKeysSet(
        Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this,
        const Scaleform::GFx::AS3::Value *result,
        bool enable)
{
  Scaleform::GFx::AS3::VM *pVM; // eax

  pVM = this->pTraits.pObject->pVM;
  if ( *(&pVM[1].HandleException + 4) )
    *((_DWORD *)pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM + 4061) ^= (*((_DWORD *)pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM
                                                                         + 4061)
                                                                       ^ (enable << 24))
                                                                      & 0x3000000;
}
