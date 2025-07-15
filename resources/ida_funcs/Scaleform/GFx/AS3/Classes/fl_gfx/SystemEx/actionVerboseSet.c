void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx::actionVerboseSet(
        Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *this,
        const Scaleform::GFx::AS3::Value *result,
        BOOL verbose)
{
  void (__thiscall *v4)(Scaleform::GFx::AS3::VM *); // ecx

  v4 = this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM;
  (*(void (__thiscall **)(void (__thiscall *)(Scaleform::GFx::AS3::VM *), BOOL))(*(_DWORD *)v4 + 268))(v4, verbose);
  this->pTraits.pObject->pVM->UI->NeedToCheck = verbose;
}
