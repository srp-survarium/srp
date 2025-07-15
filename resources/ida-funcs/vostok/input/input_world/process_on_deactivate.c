void __usercall vostok::input::input_world::process_on_deactivate(
        vostok::input::input_world *this@<ecx>,
        _DWORD **a2@<esi>)
{
  if ( a2[8] )
    (*(void (__thiscall **)(_DWORD *))(*a2[8] + 20))(a2[8]);
  if ( a2[9] )
    (*(void (__thiscall **)(_DWORD *))(*a2[9] + 28))(a2[9]);
  if ( a2[10] )
    (*(void (__thiscall **)(_DWORD *))(*a2[10] + 20))(a2[10]);
}
