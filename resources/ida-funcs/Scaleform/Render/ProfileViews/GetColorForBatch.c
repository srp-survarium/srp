Scaleform::Render::Color *__thiscall Scaleform::Render::ProfileViews::GetColorForBatch(
        Scaleform::Render::ProfileViews *this,
        Scaleform::Render::Color *result,
        __int16 base,
        unsigned __int16 index)
{
  float h; // [esp+18h] [ebp+8h]

  h = (double)((index ^ (unsigned __int16)(base ^ (16 * base))) & 0x3FF) / 1023.0;
  Scaleform::Render::Color::SetHSV(result, h, 0.80000001, 0.89999998);
  result->Channels.Alpha = -64;
  return result;
}
