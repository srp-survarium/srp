BOOL __cdecl Scaleform::Render::Text::LineBuffer::LineIndexComparator::Less(
        const Scaleform::Render::Text::LineBuffer::Line *p1,
        int index)
{
  signed int TextPos; // eax
  unsigned int v3; // ecx

  TextPos = p1->Data32.TextPos;
  if ( (p1->MemSize & 0x80000000) != 0 )
  {
    TextPos &= (unsigned int)&vostok::memory::s_CRT_arena[5574199];
    if ( (unsigned __int8 *)TextPos == &vostok::memory::s_CRT_arena[5574199] )
      TextPos = -1;
  }
  if ( index < TextPos )
    return TextPos - index < 0;
  v3 = (p1->MemSize & 0x80000000) == 0 ? p1->Data32.TextLength : HIBYTE(p1->Data8.TextPosAndLength);
  return index >= (int)(TextPos + v3) && TextPos - index < 0;
}
