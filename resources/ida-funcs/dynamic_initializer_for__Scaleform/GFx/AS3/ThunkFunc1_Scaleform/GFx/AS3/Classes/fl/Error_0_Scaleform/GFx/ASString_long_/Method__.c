void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl::Error_0_Scaleform::GFx::ASString_long_::Method__())(Scaleform::GFx::AS3::Classes::fl::Error *this, Scaleform::GFx::ASString *result, int index)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Classes::fl::Error *, Scaleform::GFx::ASString *, int); // eax

  result = Scaleform::GFx::AS3::Classes::fl::Error::getErrorMessage;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Error,0,Scaleform::GFx::ASString,long>::Method) = Scaleform::GFx::AS3::Classes::fl::Error::getErrorMessage;
  dword_8F1E3C = 0;
  return result;
}
