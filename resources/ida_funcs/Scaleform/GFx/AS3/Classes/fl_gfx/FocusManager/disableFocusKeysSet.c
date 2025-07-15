void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::disableFocusKeysSet(
        Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this,
        const Scaleform::GFx::AS3::Value *result,
        bool disable)
{
  Scaleform::GFx::AS3::VM *pVM; // eax

  pVM = this->pTraits.pObject->pVM;
  if ( LOBYTE(pVM[1].ExceptionObj.Bonus.pWeakProxy) )
    *((_DWORD *)pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM + 4061) = *((_DWORD *)pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM
                                                                       + 4061)
                                                                     & 0x3FFFFFFF
                                                                     | (disable << 30);
}
