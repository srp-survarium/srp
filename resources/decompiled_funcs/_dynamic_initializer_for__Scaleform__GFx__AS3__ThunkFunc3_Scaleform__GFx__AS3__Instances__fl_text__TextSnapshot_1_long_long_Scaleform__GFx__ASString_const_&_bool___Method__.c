void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc3_Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot_1_long_long_Scaleform::GFx::ASString_const___bool_::Method__())(Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *this, int *result, int beginIndex, Scaleform::String textToFind, const char *caseSensitive)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *, int *, int, Scaleform::String, const char *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot::findText;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot,1,long,long,Scaleform::GFx::ASString const &,bool>::Method) = Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot::findText;
  dword_AACF44 = 0;
  return result;
}
