void __thiscall Scaleform::Render::Color::GetRGBFloat(Scaleform::Render::Color *this, float *pr, float *pg, float *pb)
{
  unsigned __int8 Red; // al
  float v5; // xmm0_4
  float v6; // xmm1_4
  unsigned __int8 Green; // al
  float v8; // xmm1_4
  unsigned __int8 Blue; // cl

  Red = this->Channels.Red;
  v5 = 0.0;
  if ( Red )
    v6 = (float)Red * 0.0039215689;
  else
    v6 = 0.0;
  *pr = v6;
  Green = this->Channels.Green;
  if ( Green )
    v8 = (float)Green * 0.0039215689;
  else
    v8 = 0.0;
  *pg = v8;
  Blue = this->Channels.Blue;
  if ( Blue )
    v5 = (float)Blue * 0.0039215689;
  *pb = v5;
}
