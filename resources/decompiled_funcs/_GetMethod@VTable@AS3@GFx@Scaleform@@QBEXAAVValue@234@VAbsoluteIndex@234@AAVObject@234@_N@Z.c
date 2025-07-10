void __thiscall Scaleform::GFx::AS3::VTable::GetMethod(
        Scaleform::GFx::AS3::VTable *this,
        Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::AbsoluteIndex ind,
        Scaleform::GFx::AS3::Object *_this,
        bool super)
{
  Scaleform::GFx::AS3::Value *v5; // eax
  Scaleform::GFx::AS3::Value::V1U v6; // edx
  Scaleform::GFx::AS3::Value other; // [esp+0h] [ebp-10h] BYREF

  v5 = &this->VTMethods.Data.Data[ind.Index];
  if ( (v5->Flags & 0x1F) == 5 )
  {
    v6 = v5->value.VS._1;
    other.Flags = 16;
    other.Bonus.pWeakProxy = 0;
    *(_QWORD *)&other.value.VNumber = __PAIR64__((unsigned int)_this, v6.VUInt);
    if ( _this )
      _this->RefCount = (_this->RefCount + 1) & 0x8FBFFFFF;
    Scaleform::GFx::AS3::Value::Assign(value, &other);
  }
  else
  {
    if ( (v5->Flags & 0x1F) != 6 )
    {
      Scaleform::GFx::AS3::Value::Assign(value, v5);
      return;
    }
    other.Bonus.pWeakProxy = 0;
    *(_QWORD *)&other.value.VNumber = __PAIR64__((unsigned int)_this, ind.Index);
    if ( _this )
      _this->RefCount = (_this->RefCount + 1) & 0x8FBFFFFF;
    other.Flags = (super ? 0x800 : 0) | 0x11;
    Scaleform::GFx::AS3::Value::Assign(value, &other);
  }
  Scaleform::GFx::AS3::Value::~Value(&other);
}
