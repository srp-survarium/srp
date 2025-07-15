void __thiscall Scaleform::GFx::Stream::LogParseClass(Scaleform::GFx::Stream *this, Scaleform::Render::Cxform *cxform)
{
  Scaleform::MsgFormat::Sink::SinkDataType v3; // [esp-Ch] [ebp-210h]
  _BYTE v4[512]; // [esp+4h] [ebp-200h] BYREF

  v3.DataPtr.Size = 512;
  v3.pStr = (Scaleform::String *)v4;
  Scaleform::GFx::Format(v3, cxform);
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(this, (const char *)&stru_7F9BE8.allocator, v4);
}


void __thiscall Scaleform::GFx::Stream::LogParseClass(
        Scaleform::GFx::Stream *this,
        const Scaleform::Render::Matrix2x4<float> *matrix)
{
  Scaleform::MsgFormat::Sink::SinkDataType v3; // [esp-Ch] [ebp-210h]
  _BYTE v4[512]; // [esp+4h] [ebp-200h] BYREF

  v3.DataPtr.Size = 512;
  v3.pStr = (Scaleform::String *)v4;
  Scaleform::GFx::Format(v3, *(float *)&matrix);
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(this, (const char *)&stru_7F9BE8.allocator, v4);
}


void __thiscall Scaleform::GFx::Stream::LogParseClass(
        Scaleform::GFx::Stream *this,
        const Scaleform::Render::Rect<float> *rc)
{
  double v3; // [esp+8h] [ebp-220h]
  double v4; // [esp+10h] [ebp-218h]
  double v5; // [esp+18h] [ebp-210h]
  float v6; // [esp+24h] [ebp-204h]
  float v7; // [esp+24h] [ebp-204h]
  float v8; // [esp+24h] [ebp-204h]
  float v9; // [esp+24h] [ebp-204h]
  char v10[512]; // [esp+28h] [ebp-200h] BYREF

  v6 = rc->y2 * 0.05000000074505806;
  v5 = v6;
  v7 = rc->x2 * 0.05000000074505806;
  v4 = v7;
  v8 = rc->y1 * 0.05000000074505806;
  v3 = v8;
  v9 = 0.05000000074505806 * rc->x1;
  Scaleform::SFsprintf(v10, 0x200u, "xmin = %g, ymin = %g, xmax = %g, ymax = %g\n", v9, v3, v4, v5);
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(this, (const char *)&stru_7F9BE8.allocator, v10);
}


void __thiscall Scaleform::GFx::Stream::LogParseClass(Scaleform::GFx::Stream *this, Scaleform::Render::Color color)
{
  Scaleform::MsgFormat::Sink::SinkDataType v3; // [esp-Ch] [ebp-210h]
  _BYTE v4[512]; // [esp+4h] [ebp-200h] BYREF

  v3.DataPtr.Size = 512;
  v3.pStr = (Scaleform::String *)v4;
  Scaleform::GFx::Format(v3, &color);
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(this, (const char *)&stru_7F9BE8.allocator, v4);
}
