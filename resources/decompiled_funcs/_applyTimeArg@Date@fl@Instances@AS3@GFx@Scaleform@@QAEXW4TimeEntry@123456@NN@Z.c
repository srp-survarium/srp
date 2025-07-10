void __thiscall Scaleform::GFx::AS3::Instances::fl::Date::applyTimeArg(
        Scaleform::GFx::AS3::Instances::fl::Date *this,
        Scaleform::GFx::AS3::Instances::fl::Date::TimeEntry arg,
        long double value,
        long double tza)
{
  double Time; // st7
  Scaleform::GFx::AS3::Instances::fl::Date::TimeHolder t; // [esp+30h] [ebp-30h] BYREF

  Scaleform::GFx::AS3::Instances::fl::Date::TimeHolder::TimeHolder(&t, this->TimeValue, tza);
  t.Entries[arg] = value;
  Time = Scaleform::GFx::AS3::Instances::fl::Date::MakeTime(t.Entries[0], t.Entries[1], t.Entries[2], t.Entries[3]);
  this->TimeValue = Scaleform::GFx::AS3::Instances::fl::Date::TimeClip(Time + t.Day * 86400000.0 - t.TZA);
}
