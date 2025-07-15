void __thiscall Scaleform::GFx::AS3::VTable::SetMethod(
        Scaleform::GFx::AS3::VTable *this,
        Scaleform::GFx::AS3::AbsoluteIndex ind,
        const Scaleform::GFx::AS3::Value *m,
        Scaleform::GFx::AS3::SlotInfo::BindingType dt,
        const Scaleform::GFx::ASString *name)
{
  Scaleform::GFx::AS3::Value *v6; // esi
  int Index; // esi
  long double v8; // rax
  Scaleform::GFx::AS3::Value other; // [esp+8h] [ebp-10h] BYREF

  v6 = 0;
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
  v6 = &this->VTMethods.Data.Data[Index];
LABEL_7:
  Scaleform::GFx::AS3::VTable::SetMethodName(this, ind, dt, name);
  if ( (m->Flags & 0x1F) == 2 )
  {
    HIDWORD(v8) = this->pTraits;
    LODWORD(v8) = m->value.VS._1.VInt;
    other.Flags = 6;
    other.Bonus.pWeakProxy = 0;
    other.value.VNumber = v8;
    Scaleform::GFx::AS3::Value::Assign(v6, &other);
    Scaleform::GFx::AS3::Value::~Value(&other);
  }
  else
  {
    Scaleform::GFx::AS3::Value::Assign(v6, m);
  }
}
