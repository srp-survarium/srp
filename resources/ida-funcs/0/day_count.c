unsigned int __cdecl day_count(const date *date)
{
  unsigned int year; // ecx
  BOOL v2; // edi
  unsigned int month; // eax
  unsigned int v4; // ecx

  year = date->year;
  v2 = !(year % 0x190) || (year & 3) == 0 && year % 0x64;
  month = date->month;
  v4 = ((year - 1) >> 2) + 365 * (year - 1) + (year - 1) / 0x190 - (year - 1) / 0x64;
  if ( month > 1 )
    v4 += 31;
  if ( month > 2 )
    v4 += v2 + 28;
  if ( month > 3 )
    v4 += 31;
  if ( month > 4 )
    v4 += 30;
  if ( month > 5 )
    v4 += 31;
  if ( month > 6 )
    v4 += 30;
  if ( month > 7 )
    v4 += 31;
  if ( month > 8 )
    v4 += 31;
  if ( month > 9 )
    v4 += 30;
  if ( month > 0xA )
    v4 += 31;
  if ( month > 0xB )
    v4 += 30;
  return date->day + v4 - 1;
}
