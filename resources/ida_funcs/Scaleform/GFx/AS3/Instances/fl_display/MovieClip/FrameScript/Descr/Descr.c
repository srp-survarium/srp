void __thiscall Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr::Descr(
        Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *this,
        const Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *o)
{
  this->Method.Flags = o->Method.Flags;
  this->Method.Bonus.pWeakProxy = o->Method.Bonus.pWeakProxy;
  this->Method.value.VNumber = o->Method.value.VNumber;
  if ( (o->Method.Flags & 0x1F) > 9 )
  {
    if ( (o->Method.Flags & 0x200) != 0 )
    {
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&o->Method);
      this->Frame = o->Frame;
      return;
    }
    Scaleform::GFx::AS3::Value::AddRefInternal(&o->Method);
  }
  this->Frame = o->Frame;
}


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
