void __usercall survarium::flash_function_handler::~flash_function_handler(
        survarium::flash_function_handler *this@<ecx>,
        _DWORD *a2@<eax>)
{
  void (__thiscall ***v2)(_DWORD, int); // ecx

  v2 = (void (__thiscall ***)(_DWORD, int))a2[1];
  *a2 = &survarium::flash_function_handler::`vftable';
  if ( v2 )
    (**v2)(v2, 1);
}
