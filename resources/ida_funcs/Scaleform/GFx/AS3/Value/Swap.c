void __thiscall Scaleform::GFx::AS3::Value::Swap(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::Value *other)
{
  unsigned int Flags; // edx
  Scaleform::GFx::AS3::Value::V2U v3; // ebx
  Scaleform::GFx::AS3::Value::Extra v4; // esi
  Scaleform::GFx::AS3::Value::V1U v5; // edi

  Flags = other->Flags;
  v3.VObj = (Scaleform::GFx::AS3::Object *)other->value.VS._2;
  other->Flags = this->Flags;
  v4.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)other->Bonus;
  other->Bonus.pWeakProxy = this->Bonus.pWeakProxy;
  v5 = other->value.VS._1;
  other->value.VNumber = this->value.VNumber;
  this->value.VS._1 = v5;
  this->Bonus = v4;
  this->value.VS._2 = v3;
  this->Flags = Flags;
}
