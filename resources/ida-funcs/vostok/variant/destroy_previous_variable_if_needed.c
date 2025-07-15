void __usercall vostok::variant<32>::destroy_previous_variable_if_needed(vostok::variant<32> *this@<ecx>, int a2@<esi>)
{
  int v2; // ecx

  v2 = *(_DWORD *)(a2 + 40);
  if ( v2 )
  {
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v2 + 4))(v2, a2 + 8);
    *(_DWORD *)(a2 + 40) = 0;
  }
}
