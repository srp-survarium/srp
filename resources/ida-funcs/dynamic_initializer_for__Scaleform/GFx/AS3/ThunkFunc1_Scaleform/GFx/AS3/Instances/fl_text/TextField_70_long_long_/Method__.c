void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_text::TextField_70_long_long_::Method__())(Scaleform::GFx::AS3::Instances::fl_text::TextField *this, int *result, int charIndex)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, int *, int); // eax

  result = Scaleform::GFx::AS3::Instances::fl_text::TextField::getFirstCharInParagraph;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,70,long,long>::Method) = Scaleform::GFx::AS3::Instances::fl_text::TextField::getFirstCharInParagraph;
  dword_8F13E4 = 0;
  return result;
}
