void __thiscall Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr::Descr(
        Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *this,
        unsigned int f,
        Scaleform::GFx::AS3::Value *frMethod)
{
  this->Method = *frMethod;
  if ( (frMethod->Flags & 0x1F) <= 9 )
  {
    this->Frame = f;
  }
  else
  {
    if ( (frMethod->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(frMethod);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(frMethod);
    this->Frame = f;
  }
}
