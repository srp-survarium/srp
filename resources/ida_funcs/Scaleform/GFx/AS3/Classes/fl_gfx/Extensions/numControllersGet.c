void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::numControllersGet(
        Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *this,
        unsigned int *result)
{
  Scaleform::GFx::AS3::VM *pVM; // eax

  pVM = this->pTraits.pObject->pVM;
  if ( LOBYTE(pVM[1].ExceptionObj.Bonus.pWeakProxy) )
    *result = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM + 180))(pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM);
}
