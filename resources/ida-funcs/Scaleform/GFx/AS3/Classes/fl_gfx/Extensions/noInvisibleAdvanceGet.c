void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::noInvisibleAdvanceGet(
        Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *this,
        bool *result)
{
  Scaleform::GFx::AS3::VM *pVM; // eax

  pVM = this->pTraits.pObject->pVM;
  if ( *(&pVM[1].HandleException + 4) )
    *result = (*((_DWORD *)pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM + 4061) & 0x800) != 0;
}
