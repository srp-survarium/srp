void __thiscall Scaleform::GFx::AS3::DefArgs2<Scaleform::GFx::AS3::Value const &,Scaleform::GFx::AS3::Value const &>::~DefArgs2<Scaleform::GFx::AS3::Value const &,Scaleform::GFx::AS3::Value const &>(
        Scaleform::GFx::AS3::DefArgs2<Scaleform::GFx::AS3::Value const &,Scaleform::GFx::AS3::Value const &> *this)
{
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value *v3; // ecx

  Flags = this->_1.Flags;
  v3 = &this->_1;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(v3);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(v3);
  }
  if ( (this->_0.Flags & 0x1F) > 9 )
  {
    if ( (this->_0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&this->_0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&this->_0);
  }
}
