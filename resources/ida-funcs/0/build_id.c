unsigned int __cdecl build_id(char *day)
{
  signed int v1; // edi
  unsigned int v3; // esi
  char _Dst[256]; // [esp+8h] [ebp-11Ch] BYREF
  char src[4]; // [esp+108h] [ebp-1Ch] BYREF
  date date; // [esp+10Ch] [ebp-18h] BYREF
  date v8; // [esp+118h] [ebp-Ch] BYREF

  v8.day = 1;
  v8.month = 1;
  v8.year = 1;
  strcpy_s(_Dst, 0x100u, day);
  sscanf_s(_Dst, "%s %d %d", src, 16, &v8);
  v1 = 0;
  v8.month = 0;
  while ( _stricmp(month_id[v1++], src) )
  {
    if ( v1 >= 12 )
      goto LABEL_6;
  }
  v8.month = v1;
LABEL_6:
  date.day = 6;
  date.month = 1;
  date.year = 2012;
  v3 = day_count(&date);
  return day_count(&v8) - v3;
}
