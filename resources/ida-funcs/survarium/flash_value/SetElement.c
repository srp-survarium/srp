void __userpurge survarium::flash_value::SetElement(
        survarium::flash_value *this@<ecx>,
        _DWORD *a2@<eax>,
        unsigned int idx,
        survarium::flash_value *value)
{
  (*(void (__stdcall **)(_DWORD, unsigned int, survarium::flash_value *))(*(_DWORD *)*a2 + 52))(a2[2], idx, value);
}


void __userpurge survarium::flash_value::SetElement(
        survarium::flash_value *this@<eax>,
        const char *value@<ecx>,
        unsigned int idx)
{
  int v3; // ecx
  int v4; // eax
  int v5; // [esp+Ch] [ebp-18h] BYREF
  int v6; // [esp+10h] [ebp-14h]
  const char *v7; // [esp+14h] [ebp-10h]

  v7 = value;
  v3 = *(_DWORD *)this->body;
  v4 = *(_DWORD *)&this->body[8];
  v5 = 0;
  v6 = 6;
  (*(void (__thiscall **)(int, int, unsigned int, int *))(*(_DWORD *)v3 + 52))(v3, v4, idx, &v5);
  if ( (v6 & 0x40) != 0 )
    (*(void (__thiscall **)(int, int *, const char *))(*(_DWORD *)v5 + 8))(v5, &v5, v7);
}
