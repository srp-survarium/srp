double __thiscall Scaleform::GFx::AS3::Instances::fl::Date::TimeHolder::MakeDate(
        Scaleform::GFx::AS3::Instances::fl::Date::TimeHolder *this)
{
  double Time; // st7

  Time = Scaleform::GFx::AS3::Instances::fl::Date::MakeTime(
           this->Entries[0],
           this->Entries[1],
           this->Entries[2],
           this->Entries[3]);
  return Scaleform::GFx::AS3::Instances::fl::Date::TimeClip(Time + this->Day * 86400000.0 - this->TZA);
}
