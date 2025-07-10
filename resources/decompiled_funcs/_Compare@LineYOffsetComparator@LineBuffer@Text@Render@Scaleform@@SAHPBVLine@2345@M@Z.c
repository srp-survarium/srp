int __cdecl Scaleform::Render::Text::LineBuffer::LineYOffsetComparator::Compare(
        const Scaleform::Render::Text::LineBuffer::Line *p1,
        float yoffset)
{
  bool v3; // cl
  double v4; // st7
  double v5; // st6
  signed int v6; // eax
  float si1; // [esp+4h] [ebp+4h]
  int yoffseta; // [esp+8h] [ebp+8h]

  v3 = (p1->MemSize & 0x80000000) != 0;
  si1 = (float)p1->Data32.OffsetY;
  v4 = yoffset;
  v5 = si1;
  if ( si1 > (double)yoffset )
    return (int)(v5 - v4);
  v6 = v3 ? p1->Data8.Height : p1->Data32.Height;
  yoffseta = v3 ? p1->Data8.Leading : p1->Data32.Leading;
  if ( (double)v6 + v5 + (double)yoffseta <= v4 )
    return (int)(v5 - v4);
  else
    return 0;
}
