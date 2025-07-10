void __thiscall Scaleform::GFx::AS3::VTable::SetMethod(
        Scaleform::GFx::AS3::VTable *this,
        Scaleform::GFx::AS3::AbsoluteIndex ind,
        const Scaleform::GFx::AS3::Value *m,
        Scaleform::GFx::AS3::SlotInfo::BindingType dt)
{
  Scaleform::GFx::AS3::Value *v5; // ecx
  int Index; // ecx
  Scaleform::GFx::AS3::Value::V1U v7; // edx
  Scaleform::GFx::AS3::Value other; // [esp+0h] [ebp-10h] BYREF

  v5 = 0;
  if ( dt < BT_Code )
    goto LABEL_7;
  if ( dt <= BT_Get )
  {
    Index = ind.Index;
  }
  else
  {
    if ( dt != BT_Set )
      goto LABEL_7;
    Index = ind.Index + 1;
  }
  v5 = &this->VTMethods.Data.Data[Index];
LABEL_7:
  if ( (m->Flags & 0x1F) == 2 )
  {
    v7 = m->value.VS._1;
    other.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)this->pTraits;
    other.Flags = 6;
    other.Bonus.pWeakProxy = 0;
    other.value.VS._1 = v7;
    Scaleform::GFx::AS3::Value::Assign(v5, &other);
    Scaleform::GFx::AS3::Value::~Value(&other);
  }
  else
  {
    Scaleform::GFx::AS3::Value::Assign(v5, m);
  }
}
