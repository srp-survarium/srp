Scaleform::GFx::AS3::Value *__thiscall Scaleform::GFx::AS3::Value::`scalar deleting destructor'(
        Scaleform::GFx::AS3::Value *this,
        char a2)
{
  if ( (this->Flags & 0x1F) > 9 )
  {
    if ( (this->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(this);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(this);
  }
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
