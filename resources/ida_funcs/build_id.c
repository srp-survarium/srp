unsigned int __usercall build_id@<eax>(const char *current_date@<eax>)
{
  int v1; // esi
  unsigned int v2; // esi
  date current; // [esp+8h] [ebp-11Ch] BYREF
  char month_string[16]; // [esp+14h] [ebp-110h] BYREF
  char buffer[256]; // [esp+24h] [ebp-100h] BYREF

  current.day = 1;
  current.month = 1;
  current.year = 1;
  strcpy_s(buffer, 0x100u, current_date);
  sscanf_s(buffer, "%s %d %d", month_string, 16, &current);
  v1 = 0;
  current.month = 0;
  while ( _stricmp(month_id[v1], month_string) )
  {
    if ( ++v1 >= 12 )
      goto LABEL_6;
  }
  current.month = v1 + 1;
LABEL_6:
  *(_DWORD *)month_string = 6;
  *(_DWORD *)&month_string[4] = 1;
  *(_DWORD *)&month_string[8] = 2012;
  v2 = day_count((const date *)month_string);
  return day_count(&current) - v2;
}
