void __userpurge survarium::flash_value::SetBoolean(survarium::flash_value *this@<ecx>, _DWORD *a2@<esi>, bool value)
{
  if ( (a2[1] & 0x40) != 0 )
  {
    (*(void (__stdcall **)(_DWORD *, _DWORD))(*(_DWORD *)*a2 + 8))(a2, a2[2]);
    *a2 = 0;
  }
  *((_BYTE *)a2 + 8) = value;
  a2[1] = 2;
}
