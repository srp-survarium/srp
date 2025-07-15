void __usercall survarium::game::create_debug_window(survarium::game *this@<ecx>, int a2@<esi>)
{
  int v2; // eax
  void (__thiscall ***v3)(_DWORD, int *); // ecx
  int v4; // ecx
  int v5; // [esp+8h] [ebp-Ch] BYREF
  int v6; // [esp+Ch] [ebp-8h]

  v2 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 144) + 8))(*(_DWORD *)(a2 + 144));
  *(_DWORD *)(a2 + 2164) = v2;
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v2 + 16))(v2, 1);
  v3 = *(void (__thiscall ****)(_DWORD, int *))(a2 + 2164);
  v5 = 0;
  v6 = 1123024896;
  (**v3)(v3, &v5);
  v4 = *(_DWORD *)(a2 + 2164);
  v5 = 1157431296;
  v6 = 1145044992;
  (*(void (__thiscall **)(int, int *))(*(_DWORD *)v4 + 8))(v4, &v5);
}
