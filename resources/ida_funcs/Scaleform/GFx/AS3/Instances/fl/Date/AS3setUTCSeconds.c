void __thiscall Scaleform::GFx::AS3::Instances::fl::Date::AS3setUTCSeconds(
        Scaleform::GFx::AS3::Instances::fl::Date *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Instances::fl::Date::applyTimeArgs(this, result, argc, argv, Time_Second, 0.0);
}
