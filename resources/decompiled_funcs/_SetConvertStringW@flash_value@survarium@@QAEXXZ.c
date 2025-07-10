void __usercall survarium::flash_value::SetConvertStringW(survarium::flash_value *this@<ecx>, _DWORD *a2@<esi>)
{
  if ( (a2[1] & 0x40) != 0 )
  {
    (*(void (__stdcall **)(_DWORD *, _DWORD))(*(_DWORD *)*a2 + 8))(a2, a2[2]);
    *a2 = 0;
  }
  a2[1] = 135;
}
