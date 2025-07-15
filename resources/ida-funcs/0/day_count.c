unsigned int __usercall day_count@<eax>(const date *date@<edi>)
{
  unsigned int year; // ecx
  BOOL v2; // ebx
  unsigned int month; // eax
  unsigned int v4; // esi

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
