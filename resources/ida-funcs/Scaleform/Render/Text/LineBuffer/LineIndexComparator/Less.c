BOOL __cdecl Scaleform::Render::Text::LineBuffer::LineIndexComparator::Less(
        const Scaleform::Render::Text::LineBuffer::Line *a1,
        int a2)
{
  signed int TextPos; // eax
  unsigned int v3; // ecx

  TextPos = a1->Data32.TextPos;
  if ( (a1->MemSize & 0x80000000) != 0 )
  {
    TextPos &= 0xFFFFFFu;
    if ( TextPos == 0xFFFFFF )
      TextPos = -1;
  }
  if ( a2 < TextPos )
    return TextPos - a2 < 0;
  v3 = (a1->MemSize & 0x80000000) == 0 ? a1->Data32.TextLength : HIBYTE(a1->Data8.TextPosAndLength);
  return a2 >= (int)(TextPos + v3) && TextPos - a2 < 0;
}
