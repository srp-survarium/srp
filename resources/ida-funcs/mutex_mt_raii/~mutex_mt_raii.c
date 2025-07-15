void __usercall mutex_mt_raii::~mutex_mt_raii(mutex_mt_raii *this@<ecx>, int *a2@<eax>)
{
  bool v2; // zf
  int v3; // eax
  _RTL_CRITICAL_SECTION *v4; // eax

  v2 = *((_BYTE *)a2 + 4) == 0;
  v3 = *a2;
  if ( v2 )
    v4 = (_RTL_CRITICAL_SECTION *)(v3 + 80);
  else
    v4 = (_RTL_CRITICAL_SECTION *)(v3 + 56);
  LeaveCriticalSection(v4);
}
