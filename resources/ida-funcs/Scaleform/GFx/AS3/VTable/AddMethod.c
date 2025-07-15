Scaleform::GFx::AS3::AbsoluteIndex *__thiscall Scaleform::GFx::AS3::VTable::AddMethod(
        Scaleform::GFx::AS3::VTable *this,
        Scaleform::GFx::AS3::AbsoluteIndex *result,
        const Scaleform::GFx::AS3::Value *m,
        Scaleform::GFx::AS3::SlotInfo::BindingType dt,
        const Scaleform::GFx::ASString *name)
{
  unsigned int Size; // edi
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Value,331,Scaleform::ArrayDefaultPolicy> *p_VTMethods; // ecx
  long double v8; // rax
  Scaleform::GFx::AS3::Value *v9; // ecx
  Scaleform::GFx::AS3::AbsoluteIndex *v10; // eax
  Scaleform::GFx::AS3::Value val; // [esp+10h] [ebp-10h] BYREF

  if ( dt == BT_Code )
  {
    p_VTMethods = &this->VTMethods;
LABEL_8:
    Size = this->VTMethods.Data.Size;
    goto LABEL_9;
  }
  if ( dt != BT_Get )
  {
    if ( dt != BT_Set )
    {
      Size = 0;
      goto LABEL_10;
    }
    val.Flags = 0;
    val.Bonus.pWeakProxy = 0;
    Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,331>,Scaleform::ArrayDefaultPolicy>::PushBack(
      &this->VTMethods.Data,
      &val);
    p_VTMethods = &this->VTMethods;
    goto LABEL_8;
  }
  Size = this->VTMethods.Data.Size;
  val.Flags = 0;
  val.Bonus.pWeakProxy = 0;
  Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,331>,Scaleform::ArrayDefaultPolicy>::PushBack(
    &this->VTMethods.Data,
    &val);
  p_VTMethods = &this->VTMethods;
LABEL_9:
  val.Flags = 0;
  val.Bonus.pWeakProxy = 0;
  Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,331>,Scaleform::ArrayDefaultPolicy>::PushBack(
    &p_VTMethods->Data,
    &val);
LABEL_10:
  Scaleform::GFx::AS3::VTable::SetMethodName(this, (Scaleform::GFx::AS3::AbsoluteIndex)Size, dt, name);
  if ( (m->Flags & 0x1F) == 2 )
  {
    HIDWORD(v8) = this->pTraits;
    LODWORD(v8) = m->value.VS._1.VInt;
    v9 = &this->VTMethods.Data.Data[Size];
    val.Flags = 6;
    val.Bonus.pWeakProxy = 0;
    val.value.VNumber = v8;
    Scaleform::GFx::AS3::Value::Assign(v9, &val);
    Scaleform::GFx::AS3::Value::~Value(&val);
  }
  else
  {
    Scaleform::GFx::AS3::Value::Assign(&this->VTMethods.Data.Data[Size], m);
  }
  v10 = result;
  result->Index = this->VTMethods.Data.Size - ((dt != BT_Code) + 1);
  return v10;
}
