void __thiscall Scaleform::GFx::AS3::Value::Assign(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::Instances::Function *v)
{
  Scaleform::GFx::AS3::Value::V2U v3; // [esp+8h] [ebp-4h]

  if ( (this->Flags & 0x1F) > 9 )
  {
    if ( (this->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(this);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(this);
  }
  this->Flags = this->Flags & 0xFFFFFFE0 | 0xE;
  this->value.VS._1.VInt = (int)v;
  this->value.VS._2 = v3;
  if ( v )
    v->RefCount = (v->RefCount + 1) & 0x8FBFFFFF;
}
