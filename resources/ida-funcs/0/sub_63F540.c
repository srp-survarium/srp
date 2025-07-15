unsigned int __cdecl sub_63F540(int a1, int a2)
{
  if ( a2 == 2 )
    return ((unsigned __int16)(a1 & 0xFF00) >> 8) | ((unsigned __int8)a1 << 8);
  else
    return ((a1 & 0xFF000000) >> 24) | ((a1 & 0xFF0000u) >> 8) | ((a1 & 0xFF00) << 8) | ((unsigned __int8)a1 << 24);
}
