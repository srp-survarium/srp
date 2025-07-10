void __thiscall Scaleform::GFx::AS3::Value::SetNumber(Scaleform::GFx::AS3::Value *this, long double v)
{
  if ( (this->Flags & 0x1F) > 9 )
  {
    if ( (this->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(this);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(this);
  }
  this->Flags = this->Flags & 0xFFFFFFE0 | 4;
  this->value.VNumber = v;
}
