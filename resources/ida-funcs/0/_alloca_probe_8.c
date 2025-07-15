void __usercall _alloca_probe_8(int a1@<eax>, int a2@<ecx>)
{
  char v2; // sp
  int v3; // ecx

  v3 = (v2 + 8 - (_BYTE)a1) & 7;
  _chkstk(__CFADD__(v3, a1) ? -1 : v3 + a1, a2);
}
