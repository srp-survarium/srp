void __userpurge survarium::flash_value::SetElement(
        survarium::flash_value *this@<ecx>,
        _DWORD *a2@<eax>,
        unsigned int idx,
        survarium::flash_value *value)
{
  (*(void (__stdcall **)(_DWORD, unsigned int, survarium::flash_value *))(*(_DWORD *)*a2 + 52))(a2[2], idx, value);
}
