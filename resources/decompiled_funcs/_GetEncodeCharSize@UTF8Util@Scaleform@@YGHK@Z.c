int __stdcall Scaleform::UTF8Util::GetEncodeCharSize(unsigned int ucs_character)
{
  if ( ucs_character <= 0x7F )
    return 1;
  if ( ucs_character <= 0x7FF )
    return 2;
  if ( ucs_character <= 0xFFFF )
    return 3;
  if ( ucs_character <= 0x1FFFFF )
    return 4;
  if ( ucs_character > (unsigned int)&vostok::memory::s_CRT_arena[55905847] )
    return ucs_character > 0x7FFFFFFF ? 0 : 6;
  return 5;
}
