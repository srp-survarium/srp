int __usercall render_point@<eax>(__int16 y1@<ax>, int x@<ecx>, int x0, int x1, __int16 y0)
{
  int v5; // esi
  int v6; // ebx
  int v7; // ecx
  int v8; // eax

  v5 = x - x0;
  v6 = y0 & 0x7FFF;
  v7 = (y1 & 0x7FFF) - v6;
  v8 = (int)(v5 * abs32(v7)) / (x1 - x0);
  if ( v7 >= 0 )
    return v8 + v6;
  else
    return v6 - v8;
}
