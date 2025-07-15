void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc3_Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot_4_Scaleform::GFx::ASString_long_long_bool_::Method__())(Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *this, Scaleform::GFx::ASString *result, int beginIndex, Scaleform::String endIndex, bool includeLineEndings)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *, Scaleform::GFx::ASString *, int, Scaleform::String, bool); // eax

  result = Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot::getText;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot,4,Scaleform::GFx::ASString,long,long,bool>::Method) = Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot::getText;
  dword_8F1594 = 0;
  return result;
}
