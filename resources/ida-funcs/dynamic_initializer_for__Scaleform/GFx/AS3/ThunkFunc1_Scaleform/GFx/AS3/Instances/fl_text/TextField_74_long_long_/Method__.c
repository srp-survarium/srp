void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_text::TextField_74_long_long_::Method__())(Scaleform::GFx::AS3::Instances::fl_text::TextField *this, int *result, int lineIndex)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, int *, int); // eax

  result = Scaleform::GFx::AS3::Instances::fl_text::TextField::getLineLength;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,74,long,long>::Method) = Scaleform::GFx::AS3::Instances::fl_text::TextField::getLineLength;
  dword_8F15FC = 0;
  return result;
}
