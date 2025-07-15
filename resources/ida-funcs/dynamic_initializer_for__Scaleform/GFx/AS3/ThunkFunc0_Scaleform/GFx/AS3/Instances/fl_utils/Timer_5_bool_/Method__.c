void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_utils::Timer_5_bool_::Method__())(Scaleform::GFx::AS3::Instances::fl_utils::Timer *this, bool *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_utils::Timer *, bool *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_utils::Timer::runningGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_utils::Timer,5,bool>::Method) = Scaleform::GFx::AS3::Instances::fl_utils::Timer::runningGet;
  dword_AAC30C = 0;
  return result;
}
