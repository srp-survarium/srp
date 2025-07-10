void __thiscall Scaleform::GFx::AS3::Value::AssignUnsafe(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::Instances::Function *v)
{
  Scaleform::GFx::AS3::Value::V2U v2; // [esp+4h] [ebp-4h]

  this->Flags = this->Flags & 0xFFFFFFE0 | 0xE;
  this->value.VS._1.VInt = (int)v;
  this->value.VS._2 = v2;
  if ( v )
    v->RefCount = (v->RefCount + 1) & 0x8FBFFFFF;
}
