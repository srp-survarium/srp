void __thiscall Scaleform::GFx::AS3::Value::SetBool(Scaleform::GFx::AS3::Value *this, bool v)
{
  Scaleform::GFx::AS3::Value::V1U v3; // [esp+4h] [ebp-8h]
  Scaleform::GFx::AS3::Value::V2U v4; // [esp+8h] [ebp-4h]

  if ( (this->Flags & 0x1F) > 9 )
  {
    if ( (this->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(this);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(this);
  }
  this->Flags = this->Flags & 0xFFFFFFE0 | 1;
  v3.VBool = v;
  this->value.VS._1 = v3;
  this->value.VS._2 = v4;
}
