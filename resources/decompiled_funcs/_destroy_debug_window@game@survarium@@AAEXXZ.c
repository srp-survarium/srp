void __usercall survarium::game::destroy_debug_window(survarium::game *this@<ecx>, int a2@<esi>)
{
  (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(a2 + 144) + 36))(*(_DWORD *)(a2 + 144), *(_DWORD *)(a2 + 2164));
  *(_DWORD *)(a2 + 2164) = 0;
}
