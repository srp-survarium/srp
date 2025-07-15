void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot_3_Scaleform::GFx::ASString_bool_::Method__())(Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *this, Scaleform::GFx::ASString *result, Scaleform::String includeLineEndings)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *, Scaleform::GFx::ASString *, Scaleform::String); // eax

  result = Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot::getSelectedText;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot,3,Scaleform::GFx::ASString,bool>::Method) = Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot::getSelectedText;
  dword_8F1614 = 0;
  return result;
}
