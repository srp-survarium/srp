void __thiscall Scaleform::GFx::AS3::Value::SetNull(Scaleform::GFx::AS3::Value *this)
{
  unsigned int v2; // edx
  Scaleform::GFx::AS3::Value::V2U v3; // [esp+8h] [ebp-4h]

  if ( (this->Flags & 0x1F) > 9 )
  {
    if ( (this->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(this);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(this);
  }
  v2 = this->Flags & 0xFFFFFFE0 | 0xC;
  this->value.VS._1.VInt = 0;
  this->Flags = v2;
  this->value.VS._2 = v3;
}
