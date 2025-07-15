void __usercall _alloca_probe_16(int this@<ecx>, int a2@<eax>)
{
  char v2; // sp
  int v3; // ecx

  v3 = (v2 + 8 - (_BYTE)a2) & 0xF;
  _chkstk(__CFADD__(v3, a2) ? -1 : v3 + a2, this);
}
