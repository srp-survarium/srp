void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::noInvisibleAdvanceSet(
        Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *this,
        const Scaleform::GFx::AS3::Value *result,
        bool value)
{
  Scaleform::GFx::AS3::VM *pVM; // eax
  _DWORD *v4; // eax

  pVM = this->pTraits.pObject->pVM;
  if ( LOBYTE(pVM[1].ExceptionObj.Bonus.pWeakProxy) )
  {
    v4 = (_DWORD *)((char *)pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM + 16244);
    if ( value )
      *v4 |= 0x800u;
    else
      *v4 &= ~0x800u;
  }
}
