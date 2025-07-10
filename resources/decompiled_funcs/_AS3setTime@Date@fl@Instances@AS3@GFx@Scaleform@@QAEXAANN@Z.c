void __thiscall Scaleform::GFx::AS3::Instances::fl::Date::AS3setTime(
        Scaleform::GFx::AS3::Instances::fl::Date *this,
        long double *result,
        double millisecond)
{
  double v4; // st7

  v4 = Scaleform::GFx::AS3::Instances::fl::Date::TimeClip(millisecond);
  this->TimeValue = v4;
  this->UseDST = 0;
  *result = v4;
}
