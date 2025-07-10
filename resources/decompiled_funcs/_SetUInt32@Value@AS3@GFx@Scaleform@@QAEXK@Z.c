void __thiscall Scaleform::GFx::AS3::Value::SetUInt32(Scaleform::GFx::AS3::Value *this, unsigned int v)
{
  unsigned int v3; // edx
  Scaleform::GFx::AS3::Value::V2U v4; // [esp+8h] [ebp-4h]

  if ( (this->Flags & 0x1F) > 9 )
  {
    if ( (this->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(this);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(this);
  }
  v3 = this->Flags & 0xFFFFFFE3;
  this->value.VS._1.VInt = v;
  this->Flags = v3 | 3;
  this->value.VS._2 = v4;
}
