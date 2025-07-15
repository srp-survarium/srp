void __userpurge vostok::animation::mixing::n_ary_tree::add_offset(
        vostok::animation::mixing::n_ary_tree *this@<ecx>,
        int a2@<eax>,
        const unsigned int offset_time_in_ms)
{
  _DWORD *i; // esi
  _DWORD *v5; // edi
  int v6; // eax
  int v7; // eax
  _DWORD v8[3]; // [esp+10h] [ebp-Ch] BYREF
  _DWORD *v9; // [esp+24h] [ebp+8h]

  *(_DWORD *)(a2 + 44) += offset_time_in_ms;
  for ( i = *(_DWORD **)(a2 + 4); i; i = (_DWORD *)i[10] )
  {
    v5 = i + 22;
    v6 = (int)&i[i[1] + 22];
    v8[0] = &vostok::animation::mixing::n_ary_tree_offset_adder::`vftable';
    v8[1] = offset_time_in_ms;
    v9 = (_DWORD *)v6;
    if ( i + 22 != (_DWORD *)v6 )
    {
      do
      {
        (*(void (__thiscall **)(_DWORD, _DWORD *))(*(_DWORD *)*v5 + 8))(*v5, v8);
        ++v5;
      }
      while ( v5 != v9 );
    }
    v7 = i[7] + 120;
    if ( *(_WORD *)(i[7] + 164) )
      *(_DWORD *)(i[7] + 160) += offset_time_in_ms;
    if ( *(_WORD *)(v7 + 28) )
      *(_DWORD *)(v7 + 24) += offset_time_in_ms;
    if ( *(_WORD *)(v7 + 12) )
      *(_DWORD *)(v7 + 8) += offset_time_in_ms;
  }
}
