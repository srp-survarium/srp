void __usercall survarium::flash_text::get_width(survarium::flash_text *this@<ecx>, _DWORD *a2@<eax>)
{
  _BYTE v2[16]; // [esp+0h] [ebp-10h] BYREF

  (*(void (__thiscall **)(_DWORD, _BYTE *))(*(_DWORD *)*a2 + 76))(*a2, v2);
}
