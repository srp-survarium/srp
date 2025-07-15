void __userpurge survarium::flash_value::PushBack(
        survarium::flash_value *this@<ecx>,
        _DWORD *a2@<eax>,
        survarium::flash_value *value)
{
  (*(void (__thiscall **)(_DWORD, _DWORD, survarium::flash_value *))(*(_DWORD *)*a2 + 60))(*a2, a2[2], value);
}
