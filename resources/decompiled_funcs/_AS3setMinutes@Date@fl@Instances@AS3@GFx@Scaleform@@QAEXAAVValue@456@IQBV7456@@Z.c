void __thiscall Scaleform::GFx::AS3::Instances::fl::Date::AS3setMinutes(
        Scaleform::GFx::AS3::Instances::fl::Date *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  int LocalTZA; // [esp+Ch] [ebp-4h]

  LocalTZA = Scaleform::GFx::AS3::Instances::fl::Date::GetLocalTZA(this);
  Scaleform::GFx::AS3::Instances::fl::Date::applyTimeArgs(this, result, argc, argv, Time_Minute, (double)LocalTZA);
}
