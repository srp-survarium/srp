void __thiscall Scaleform::GFx::AS3::Value::SetUndefined(Scaleform::GFx::AS3::Value *this)
{
  if ( (this->Flags & 0x1F) > 9 )
  {
    if ( (this->Flags & 0x200) != 0 )
    {
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(this);
      this->Flags &= 0xFFFFFFE0;
      return;
    }
    Scaleform::GFx::AS3::Value::ReleaseInternal(this);
  }
  this->Flags &= 0xFFFFFFE0;
}
