Scaleform::GFx::AS3::CheckResult *__cdecl Scaleform::GFx::AS3::GetSuperProperty(
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Traits *ot,
        Scaleform::GFx::AS3::Value *resulta,
        Scaleform::GFx::AS3::Value *_this,
        const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *mn,
        Scaleform::GFx::AS3::SlotInfo::ValTarget vtt)
{
  Scaleform::GFx::AS3::Traits *ValueTraits; // eax
  Scaleform::GFx::AS3::Traits *pObject; // esi
  Scaleform::GFx::AS3::SlotInfo *FixedSlot; // edi
  Scaleform::GFx::AS3::VTable *VT; // eax
  Scaleform::GFx::AS3::CheckResult *v11; // eax
  Scaleform::GFx::AS3::SlotInfo::ValTarget v12; // [esp-4h] [ebp-24h]
  unsigned int index; // [esp+Ch] [ebp-14h] BYREF
  Scaleform::GFx::AS3::Value v; // [esp+10h] [ebp-10h] BYREF

  ValueTraits = ot;
  if ( !ot )
    ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(vm, _this);
  pObject = ValueTraits->pParent.pObject;
  if ( pObject )
  {
    index = 0;
    FixedSlot = (Scaleform::GFx::AS3::SlotInfo *)Scaleform::GFx::AS3::FindFixedSlot(
                                                   (const Scaleform::GFx::AS3::SlotInfo *)vm,
                                                   pObject,
                                                   mn,
                                                   &index,
                                                   0);
    if ( FixedSlot )
    {
      v12 = vtt;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0;
      VT = Scaleform::GFx::AS3::Traits::GetVT(pObject);
      if ( Scaleform::GFx::AS3::SlotInfo::GetSlotValueUnsafe(
             FixedSlot,
             (Scaleform::GFx::AS3::CheckResult *)&ot,
             vm,
             &v,
             (Scaleform::GFx::ASStringNode *)_this,
             VT,
             v12)->Result )
      {
        Scaleform::GFx::AS3::Value::Swap(resulta, &v);
        result->Result = 1;
        Scaleform::GFx::AS3::Value::~Value(&v);
        return result;
      }
      Scaleform::GFx::AS3::Value::~Value(&v);
    }
  }
  v11 = result;
  result->Result = 0;
  return v11;
}
