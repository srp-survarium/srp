void __thiscall Scaleform::GFx::AS3::Instances::fl::Date::dateSet(
        Scaleform::GFx::AS3::Instances::fl::Date *this,
        const Scaleform::GFx::AS3::Value *result,
        long double value)
{
  int LocalTZA; // [esp+14h] [ebp-4h]

  LocalTZA = Scaleform::GFx::AS3::Instances::fl::Date::GetLocalTZA(this);
  Scaleform::GFx::AS3::Instances::fl::Date::applyDateArg(this, Date_Day, value, (double)LocalTZA);
}
