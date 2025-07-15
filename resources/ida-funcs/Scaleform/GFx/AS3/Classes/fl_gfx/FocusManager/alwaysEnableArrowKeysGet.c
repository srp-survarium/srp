void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::alwaysEnableArrowKeysGet(
        Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this,
        bool *result)
{
  Scaleform::GFx::AS3::VM *pVM; // eax
  Scaleform::GFx::AS3::VM_vtbl *v3; // ecx
  int v4; // eax

  pVM = this->pTraits.pObject->pVM;
  if ( *(&pVM[1].HandleException + 4) )
  {
    v3 = pVM[1].__vftable;
    v4 = *((_BYTE *)v3[1].~Scaleform::GFx::AS3::VM + 16247) & 3;
    if ( v4 == 3 )
    {
      v4 = -1;
LABEL_6:
      *result = v4 == 1;
      return;
    }
    if ( (*((_BYTE *)v3[1].~Scaleform::GFx::AS3::VM + 16247) & 3) != 0 )
      goto LABEL_6;
    *result = 0;
  }
}
