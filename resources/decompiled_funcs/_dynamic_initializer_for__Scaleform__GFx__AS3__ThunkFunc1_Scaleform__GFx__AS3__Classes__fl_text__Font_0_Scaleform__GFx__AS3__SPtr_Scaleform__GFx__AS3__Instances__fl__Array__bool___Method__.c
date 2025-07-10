void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl_text::Font_0_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::Array__bool_::Method__())(Scaleform::GFx::AS3::Classes::fl_text::Font *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *result, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::Font> enumerateDeviceFonts)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Classes::fl_text::Font *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::Font>); // eax

  result = Scaleform::GFx::AS3::Classes::fl_text::Font::enumerateFonts;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_text::Font,0,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array>,bool>::Method) = Scaleform::GFx::AS3::Classes::fl_text::Font::enumerateFonts;
  dword_AACEF4 = 0;
  return result;
}
