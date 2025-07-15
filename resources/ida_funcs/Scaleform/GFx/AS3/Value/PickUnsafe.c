void __thiscall Scaleform::GFx::AS3::Value::PickUnsafe(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::Instances::FunctionBase *v)
{
  Scaleform::GFx::AS3::Value::V2U v2; // [esp+4h] [ebp-4h]

  this->Flags = this->Flags & 0xFFFFFFE0 | 0xE;
  this->value.VS._1.VInt = (int)v;
  this->value.VS._2 = v2;
}


void __thiscall Scaleform::GFx::AS3::Value::PickUnsafe(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::Object *v)
{
  Scaleform::GFx::AS3::Value::V2U v2; // [esp+4h] [ebp-4h]

  this->Flags = this->Flags & 0xFFFFFFE0 | 0xC;
  this->value.VS._1.VInt = (int)v;
  this->value.VS._2 = v2;
}


void __thiscall Scaleform::GFx::AS3::Value::PickUnsafe(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::Instances::ThunkFunction *v)
{
  Scaleform::GFx::AS3::Value::V2U v2; // [esp+4h] [ebp-4h]

  this->Flags = this->Flags & 0xFFFFFFE0 | 0xF;
  this->value.VS._1.VInt = (int)v;
  this->value.VS._2 = v2;
}
