void __userpurge survarium::flash_value::GetMember(
        survarium::flash_value *this@<ecx>,
        _DWORD *a2@<eax>,
        const char *name,
        survarium::flash_value *value)
{
  (*(void (__stdcall **)(_DWORD, const char *, survarium::flash_value *, bool))(*(_DWORD *)*a2 + 16))(
    a2[2],
    name,
    value,
    (a2[1] & 0x8F) == 10);
}
