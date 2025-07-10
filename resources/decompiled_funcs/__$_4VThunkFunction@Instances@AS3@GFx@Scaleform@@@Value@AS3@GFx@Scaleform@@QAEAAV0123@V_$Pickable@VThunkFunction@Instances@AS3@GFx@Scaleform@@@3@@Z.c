Scaleform::GFx::AS3::Value *__thiscall Scaleform::GFx::AS3::Value::operator=<Scaleform::GFx::AS3::Instances::ThunkFunction>(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::ThunkFunction> v)
{
  unsigned int v3; // edx
  Scaleform::GFx::AS3::Value::V2U v5; // [esp+Ch] [ebp-4h]

  if ( (this->Flags & 0x1F) > 9 )
  {
    if ( (this->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(this);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(this);
  }
  v3 = this->Flags & 0xFFFFFFEF;
  LODWORD(this->value.VNumber) = v;
  this->value.VS._2 = v5;
  this->Flags = v3 | 0xF;
  return this;
}
