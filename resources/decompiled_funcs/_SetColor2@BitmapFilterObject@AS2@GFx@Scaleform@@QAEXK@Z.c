void __thiscall Scaleform::GFx::AS2::BitmapFilterObject::SetColor2(
        Scaleform::GFx::AS2::BitmapFilterObject *this,
        unsigned int c)
{
  Scaleform::Render::BlurFilterParams *v2; // eax
  unsigned __int8 Alpha; // cl

  v2 = Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(this);
  Alpha = v2->Colors[1].Channels.Alpha;
  v2->Colors[1].Raw = c;
  v2->Colors[1].Channels.Alpha = Alpha;
}
