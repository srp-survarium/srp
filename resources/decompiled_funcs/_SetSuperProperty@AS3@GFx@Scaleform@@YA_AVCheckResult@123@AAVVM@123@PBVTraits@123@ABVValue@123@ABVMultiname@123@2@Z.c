Scaleform::GFx::AS3::CheckResult *__cdecl Scaleform::GFx::AS3::SetSuperProperty(
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Traits *ot,
        Scaleform::GFx::AS3::Value *_this,
        const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *mn,
        const Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Value *v6; // ebx
  Scaleform::GFx::AS3::Traits *ValueTraits; // eax
  Scaleform::GFx::AS3::Traits *pObject; // esi
  Scaleform::GFx::AS3::SlotInfo *FixedSlot; // edi
  Scaleform::GFx::AS3::VTable *VT; // eax
  Scaleform::GFx::AS3::CheckResult *v11; // eax
  unsigned int index; // [esp+10h] [ebp-4h] BYREF

  v6 = _this;
  index = 0;
  ValueTraits = ot;
  if ( !ot )
    ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(vm, _this);
  pObject = (Scaleform::GFx::AS3::Traits *)ValueTraits->pParent.pObject;
  if ( pObject )
  {
    index = 0;
    FixedSlot = (Scaleform::GFx::AS3::SlotInfo *)Scaleform::GFx::AS3::FindFixedSlot(
                                                   (const Scaleform::GFx::AS3::SlotInfo *)vm,
                                                   pObject,
                                                   mn,
                                                   &index,
                                                   0);
    if ( FixedSlot
      && (VT = Scaleform::GFx::AS3::Traits::GetVT(pObject),
          Scaleform::GFx::AS3::SlotInfo::SetSlotValue(
            FixedSlot,
            (Scaleform::GFx::AS3::CheckResult *)&ot,
            vm,
            value,
            v6,
            VT)->Result) )
    {
      v11 = result;
      result->Result = 1;
    }
    else
    {
      v11 = result;
      result->Result = 0;
    }
  }
  else
  {
    v11 = result;
    result->Result = 0;
  }
  return v11;
}
