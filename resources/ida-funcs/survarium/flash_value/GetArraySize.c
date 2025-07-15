int __usercall survarium::flash_value::GetArraySize@<eax>(survarium::flash_value *this@<ecx>, _DWORD *a2@<eax>)
{
  return (*(int (__stdcall **)(_DWORD))(*(_DWORD *)*a2 + 40))(a2[2]);
}
