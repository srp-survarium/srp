double __thiscall Scaleform::GFx::AS3::Instances::fl::Date::DateHolder::MakeDate(
        Scaleform::GFx::AS3::Instances::fl::Date::DateHolder *this)
{
  double Day; // st7

  Day = Scaleform::GFx::AS3::Instances::fl::Date::MakeDay(this->Entries[0], this->Entries[1], this->Entries[2]);
  return Scaleform::GFx::AS3::Instances::fl::Date::TimeClip(Day * 86400000.0 + this->TimeInDay - this->TZA);
}
