Scaleform::String *__cdecl Scaleform::GFx::Format(
        Scaleform::MsgFormat::Sink::SinkDataType buf,
        const Scaleform::Render::Color *color)
{
  const Scaleform::Render::Color *v2; // eax
  int Blue; // edx
  int Green; // ecx
  int Red; // edx
  int v7; // [esp+4h] [ebp-18h] BYREF
  int v8; // [esp+8h] [ebp-14h] BYREF
  int v9; // [esp+Ch] [ebp-10h] BYREF
  Scaleform::MsgFormat::Sink v10; // [esp+10h] [ebp-Ch] BYREF

  v2 = color;
  Blue = color->Channels.Blue;
  color = (const Scaleform::Render::Color *)color->Channels.Alpha;
  Green = v2->Channels.Green;
  v7 = Blue;
  Red = v2->Channels.Red;
  v8 = Green;
  v9 = Red;
  v10.Type = tDataPtr;
  v10.SinkData = buf;
  Scaleform::Format<int,int,int,int>(&v10, "RGBA: {0} {1} {2} {3}\n", &v9, &v8, &v7, (int *)&color);
  return buf.pStr;
}


Scaleform::String *__cdecl Scaleform::GFx::Format(
        Scaleform::MsgFormat::Sink::SinkDataType buf,
        Scaleform::Render::Cxform *cxform)
{
  Scaleform::MsgFormat::Sink v3; // [esp+4h] [ebp-Ch] BYREF

  v3.Type = tDataPtr;
  v3.SinkData = buf;
  Scaleform::Format<float,float,float,float,float,float,float,float>(
    &v3,
    "    *         +\n| {0:4.4} {1:4.4}|\n| {2:4.4} {3:4.4}|\n| {4:4.4} {5:4.4}|\n| {6:4.4} {7:4.4}|\n",
    (float *)cxform,
    cxform->M[1],
    &cxform->M[0][1],
    &cxform->M[1][1],
    &cxform->M[0][2],
    &cxform->M[1][2],
    &cxform->M[0][3],
    &cxform->M[1][3]);
  return buf.pStr;
}


Scaleform::String *__cdecl Scaleform::GFx::Format(Scaleform::MsgFormat::Sink::SinkDataType buf, float matrix)
{
  float *v2; // eax
  float v4; // [esp+4h] [ebp-10h] BYREF
  Scaleform::MsgFormat::Sink v5; // [esp+8h] [ebp-Ch] BYREF

  v2 = (float *)LODWORD(matrix);
  matrix = *(float *)(LODWORD(matrix) + 28) * 0.05000000074505806;
  v4 = 0.05000000074505806 * v2[3];
  v5.Type = tDataPtr;
  v5.SinkData = buf;
  Scaleform::Format<float,float,float,float,float,float>(
    &v5,
    "| {0:4.4} {1:4.4} {2:4.4} |\n| {3:4.4} {4:4.4} {5:4.4} |\n",
    v2,
    v2 + 1,
    &v4,
    v2 + 4,
    v2 + 5,
    &matrix);
  return buf.pStr;
}
