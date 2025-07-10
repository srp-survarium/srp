void __usercall survarium::flash_value::PushBack(
        survarium::flash_value *this@<eax>,
        survarium::flash_value *value@<esi>)
{
  (*(void (__stdcall **)(_DWORD, survarium::flash_value *))(**(_DWORD **)this->body + 60))(
    *(_DWORD *)&this->body[8],
    value);
}
