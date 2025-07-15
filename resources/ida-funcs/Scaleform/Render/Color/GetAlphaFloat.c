void __thiscall Scaleform::Render::Color::GetAlphaFloat(Scaleform::Render::Color *this, float *pa)
{
  unsigned __int8 Alpha; // al
  float v3; // xmm0_4

  Alpha = this->Channels.Alpha;
  if ( Alpha )
    v3 = (float)Alpha * 0.0039215689;
  else
    v3 = 0.0;
  *pa = v3;
}
