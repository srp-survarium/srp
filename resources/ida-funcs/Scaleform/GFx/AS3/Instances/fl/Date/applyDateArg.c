void __thiscall Scaleform::GFx::AS3::Instances::fl::Date::applyDateArg(
        Scaleform::GFx::AS3::Instances::fl::Date *this,
        Scaleform::GFx::AS3::Instances::fl::Date::DateEntry arg,
        long double value,
        long double tza)
{
  double Day; // st7
  Scaleform::GFx::AS3::Instances::fl::Date::DateHolder d; // [esp+30h] [ebp-28h] BYREF

  Scaleform::GFx::AS3::Instances::fl::Date::DateHolder::DateHolder(&d, this->TimeValue, tza);
  d.Entries[arg] = value;
  Day = Scaleform::GFx::AS3::Instances::fl::Date::MakeDay(d.Entries[0], d.Entries[1], d.Entries[2]);
  this->TimeValue = Scaleform::GFx::AS3::Instances::fl::Date::TimeClip(Day * 86400000.0 + d.TimeInDay - d.TZA);
}
