void __thiscall Scaleform::GFx::AS3::Classes::UserDefined::UserDefined(
        Scaleform::GFx::AS3::Classes::UserDefined *this,
        Scaleform::GFx::AS3::ClassTraits::UserDefined *t)
{
  Scaleform::GFx::AS3::ClassTraits::UserDefined *v2; // edi
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  Scaleform::GFx::AS3::VM *pVM; // edx

  v2 = t;
  Scaleform::GFx::AS3::Classes::UDBase::UDBase(this, t);
  this->__vftable = (Scaleform::GFx::AS3::Classes::UserDefined_vtbl *)&Scaleform::GFx::AS3::Classes::UserDefined::`vftable';
  if ( v2->SetupSlotValues(v2, (Scaleform::GFx::AS3::CheckResult *)&t, this)->Result )
  {
    pObject = this->pTraits.pObject;
    pVM = pObject->pVM;
    if ( pVM->CallStack.Size )
      Scaleform::GFx::AS3::Traits::StoreScopeStack(
        pObject,
        pVM->CallStack.Pages[(pVM->CallStack.Size - 1) >> 6][(pVM->CallStack.Size - 1) & 0x3F].ScopeStackBaseInd,
        &pVM->ScopeStack);
    else
      Scaleform::GFx::AS3::Traits::StoreScopeStack(pObject, 0, &pVM->ScopeStack);
  }
}
