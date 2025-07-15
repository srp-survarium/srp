void __thiscall Scaleform::GFx::AS3::Value::~Value(Scaleform::GFx::AS3::Value *this)
{
  if ( (this->Flags & 0x1F) > 9 )
  {
    if ( (this->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(this);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(this);
  }
}
