void __thiscall Scaleform::GFx::AS3::Instances::fl::Date::timeSet(
        Scaleform::GFx::AS3::Instances::fl::Date *this,
        const Scaleform::GFx::AS3::Value *result,
        double value)
{
  double v4; // st7
  __int16 Flags; // ax
  char v6; // cl
  Scaleform::GFx::AS3::Value r; // [esp+Ch] [ebp-10h] BYREF

  r.Flags = 0;
  r.Bonus.pWeakProxy = 0;
  v4 = Scaleform::GFx::AS3::Instances::fl::Date::TimeClip(value);
  this->TimeValue = v4;
  Flags = r.Flags;
  r.value.VNumber = v4;
  v6 = r.Flags & 0x1F;
  this->UseDST = 0;
  if ( v6 > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
  }
}
