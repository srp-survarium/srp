void __thiscall Scaleform::GFx::AS3::Classes::UserDefined::UserDefined(
        Scaleform::GFx::AS3::Classes::UserDefined *this,
        Scaleform::GFx::AS3::ClassTraits::UserDefined *t)
{
  Scaleform::GFx::AS3::ClassTraits::UserDefined *v2; // edi
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  const Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *pVM; // edx

  v2 = t;
  Scaleform::GFx::AS3::Classes::UDBase::UDBase(this, t);
  this->__vftable = (Scaleform::GFx::AS3::Classes::UserDefined_vtbl *)&Scaleform::GFx::AS3::Classes::UserDefined::`vftable';
  if ( v2->SetupSlotValues(v2, (Scaleform::GFx::AS3::CheckResult *)&t, this)->Result )
  {
    pObject = this->pTraits.pObject;
    pVM = (const Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *)pObject->pVM;
    if ( pVM[8].Data.pHeap )
      Scaleform::GFx::AS3::Traits::StoreScopeStack(
        pObject,
        *(_DWORD *)(*(_DWORD *)(pVM[9].Data.Policy.Capacity
                              + 4 * ((unsigned int)(&pVM[8].Data.pHeap[-1].TrackDebugInfo + 2) >> 6))
                  + 96 * ((int)(&pVM[8].Data.pHeap[-1].TrackDebugInfo + 2) & 0x3F)
                  + 4),
        pVM + 5);
    else
      Scaleform::GFx::AS3::Traits::StoreScopeStack(pObject, 0, pVM + 5);
  }
}
