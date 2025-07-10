void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl_text::Font_1_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Class___::Method__())(Scaleform::GFx::AS3::Classes::fl_text::Font *this, const Scaleform::GFx::AS3::Value *result, Scaleform::String font)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Classes::fl_text::Font *, const Scaleform::GFx::AS3::Value *, Scaleform::String); // eax

  result = Scaleform::GFx::AS3::Classes::fl_text::Font::registerFont;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_text::Font,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Class *>::Method) = Scaleform::GFx::AS3::Classes::fl_text::Font::registerFont;
  dword_AACD5C = 0;
  return result;
}
