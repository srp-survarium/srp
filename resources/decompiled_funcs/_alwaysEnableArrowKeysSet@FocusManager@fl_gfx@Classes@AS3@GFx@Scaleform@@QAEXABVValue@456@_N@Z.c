void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::alwaysEnableArrowKeysSet(
        Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this,
        const Scaleform::GFx::AS3::Value *result,
        bool enable)
{
  Scaleform::GFx::AS3::VM *pVM; // eax

  pVM = this->pTraits.pObject->pVM;
  if ( LOBYTE(pVM[1].ExceptionObj.Bonus.pWeakProxy) )
    *((_DWORD *)pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM + 4061) ^= (unsigned int)&vostok::memory::s_CRT_arena[39128632]
                                                                      & (*((_DWORD *)pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM
                                                                         + 4061)
                                                                       ^ (enable << 24));
}
