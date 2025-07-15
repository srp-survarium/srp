void __userpurge survarium::flash_value::SetNumber(survarium::flash_value *this@<ecx>, double *a2@<esi>, float value)
{
  if ( (*((_DWORD *)a2 + 1) & 0x40) != 0 )
  {
    (*(void (__stdcall **)(double *, _DWORD))(**(_DWORD **)a2 + 8))(a2, *((_DWORD *)a2 + 2));
    *(_DWORD *)a2 = 0;
  }
  *((_DWORD *)a2 + 1) = 5;
  a2[1] = value;
}
