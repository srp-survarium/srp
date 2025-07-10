void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_text::Font_3_bool_Scaleform::GFx::ASString_const___::Method__())(Scaleform::GFx::AS3::Instances::fl_text::Font *this, bool *result, const Scaleform::GFx::ASString *str)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_text::Font *, bool *, const Scaleform::GFx::ASString *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_text::Font::hasGlyphs;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::Font,3,bool,Scaleform::GFx::ASString const &>::Method) = Scaleform::GFx::AS3::Instances::fl_text::Font::hasGlyphs;
  dword_AACFE4 = 0;
  return result;
}
