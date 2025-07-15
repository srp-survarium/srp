BOOL __usercall survarium::player_input_handler::alt_is_held@<eax>(
        survarium::player_input_handler *this@<ecx>,
        int a2@<eax>)
{
  int v2; // eax
  unsigned __int8 (__thiscall ***v3)(_DWORD, int); // esi

  v2 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(a2 + 352) + 168) + 40))(*(_DWORD *)(*(_DWORD *)(a2 + 352) + 168));
  v3 = (unsigned __int8 (__thiscall ***)(_DWORD, int))(*(int (__thiscall **)(int))(*(_DWORD *)v2 + 36))(v2);
  return (**v3)(v3, 184) || (**v3)(v3, 56);
}
