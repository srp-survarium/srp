Scaleform::Render::Color *__stdcall Scaleform::Render::Color::Blend(
        Scaleform::Render::Color *result,
        Scaleform::Render::Color c1,
        Scaleform::Render::Color c2,
        float f)
{
  Scaleform::Render::Color *v6; // eax
  float Red; // [esp+0h] [ebp-4h]
  float c1a; // [esp+Ch] [ebp+8h]
  float c1b; // [esp+Ch] [ebp+8h]
  float c1c; // [esp+Ch] [ebp+8h]
  float c1d; // [esp+Ch] [ebp+8h]
  float c2a; // [esp+10h] [ebp+Ch]
  float c2b; // [esp+10h] [ebp+Ch]
  float c2c; // [esp+10h] [ebp+Ch]

  Red = (float)c1.Channels.Red;
  c1a = Red + ((double)c2.Channels.Red - Red) * f;
  result->Channels.Red = (int)(c1a + 0.5);
  c2a = (float)c1.Channels.Green;
  c1b = ((double)c2.Channels.Green - c2a) * f + c2a;
  result->Channels.Green = (int)(c1b + 0.5);
  c2b = (float)c1.Channels.Blue;
  c1c = ((double)c2.Channels.Blue - c2b) * f + c2b;
  result->Channels.Blue = (int)(c1c + 0.5);
  c2c = (float)HIBYTE(c1.Raw);
  c1d = f * ((double)HIBYTE(c2.Raw) - c2c) + c2c;
  v6 = result;
  result->Channels.Alpha = (int)(c1d + 0.5);
  return v6;
}
