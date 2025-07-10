void __thiscall Scaleform::GFx::AS3::PropRef::~PropRef(Scaleform::GFx::AS3::PropRef *this)
{
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value *p_This; // ecx

  Flags = this->This.Flags;
  p_This = &this->This;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_This);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_This);
  }
}
