void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::disableFocusKeysGet(
        Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this,
        bool *result)
{
  Scaleform::GFx::AS3::VM *pVM; // eax
  int v3; // eax

  pVM = this->pTraits.pObject->pVM;
  if ( LOBYTE(pVM[1].ExceptionObj.Bonus.pWeakProxy) )
  {
    v3 = *((_DWORD *)pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM + 4061) >> 30;
    if ( v3 == 3 )
    {
      v3 = -1;
LABEL_6:
      *result = v3 == 1;
      return;
    }
    if ( v3 )
      goto LABEL_6;
    *result = 0;
  }
}
