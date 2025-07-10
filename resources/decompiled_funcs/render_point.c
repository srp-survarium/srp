int __usercall render_point@<eax>(__int16 y1@<ax>, int x@<ecx>, int x0, int x1, __int16 y0)
{
  int v5; // ebx
  int v6; // edi
  int v7; // eax

  v5 = y0 & 0x7FFF;
  v6 = (y1 & 0x7FFF) - v5;
  v7 = (int)((x - x0) * abs32(v6)) / (x1 - x0);
  if ( v6 >= 0 )
    return v7 + v5;
  else
    return v5 - v7;
}
