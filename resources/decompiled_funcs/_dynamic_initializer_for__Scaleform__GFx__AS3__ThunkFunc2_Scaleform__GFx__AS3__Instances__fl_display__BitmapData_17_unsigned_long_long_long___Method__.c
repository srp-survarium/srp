void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl_display::BitmapData_17_unsigned_long_long_long_::Method__())(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this, unsigned int *result, int x, int y)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *, unsigned int *, int, int); // eax

  result = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getPixel32;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,17,unsigned long,long,long>::Method) = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getPixel32;
  dword_AAE32C = 0;
  return result;
}
