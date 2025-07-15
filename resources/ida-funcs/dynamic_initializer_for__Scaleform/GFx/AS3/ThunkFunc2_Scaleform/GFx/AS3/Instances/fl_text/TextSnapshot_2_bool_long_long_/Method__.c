void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot_2_bool_long_long_::Method__())(Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *this, bool *result, int beginIndex, int endIndex)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *, bool *, int, int); // eax

  result = Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot::getSelected;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot,2,bool,long,long>::Method) = Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot::getSelected;
  dword_AACCF4 = 0;
  return result;
}
