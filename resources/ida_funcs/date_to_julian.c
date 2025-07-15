int __usercall date_to_julian@<eax>(int y@<edi>, int m@<ecx>, int d)
{
  return 1461 * ((m - 14) / 12 + y + 4800) / 4
       + d
       + 367 * (m - 12 * ((m - 14) / 12) - 2) / 12
       - 3 * (((m - 14) / 12 + y + 4900) / 100) / 4
       - 32075;
}
