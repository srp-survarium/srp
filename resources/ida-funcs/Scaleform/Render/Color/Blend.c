Scaleform::Render::Color *__stdcall Scaleform::Render::Color::Blend(
        Scaleform::Render::Color *result,
        Scaleform::Render::Color c1,
        Scaleform::Render::Color c2,
        float f)
{
  Scaleform::Render::Color *v6; // eax
  float Red; // [esp+0h] [ebp-4h]
  float v8; // [esp+Ch] [ebp+8h]
  float v9; // [esp+Ch] [ebp+8h]
  float v10; // [esp+Ch] [ebp+8h]
  float v11; // [esp+Ch] [ebp+8h]
  float Green; // [esp+10h] [ebp+Ch]
  float Blue; // [esp+10h] [ebp+Ch]
  float Raw_high; // [esp+10h] [ebp+Ch]

  Red = (float)c1.Channels.Red;
  v8 = Red + ((double)c2.Channels.Red - Red) * f;
  result->Channels.Red = (int)(v8 + 0.5);
  Green = (float)c1.Channels.Green;
  v9 = ((double)c2.Channels.Green - Green) * f + Green;
  result->Channels.Green = (int)(v9 + 0.5);
  Blue = (float)c1.Channels.Blue;
  v10 = ((double)c2.Channels.Blue - Blue) * f + Blue;
  result->Channels.Blue = (int)(v10 + 0.5);
  Raw_high = (float)HIBYTE(c1.Raw);
  v11 = f * ((double)HIBYTE(c2.Raw) - Raw_high) + Raw_high;
  v6 = result;
  result->Channels.Alpha = (int)(v11 + 0.5);
  return v6;
}
