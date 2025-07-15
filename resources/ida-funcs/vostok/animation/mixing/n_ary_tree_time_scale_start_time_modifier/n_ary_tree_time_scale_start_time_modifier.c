_DWORD *__usercall vostok::animation::mixing::n_ary_tree_time_scale_start_time_modifier::n_ary_tree_time_scale_start_time_modifier@<eax>(
        vostok::animation::mixing::n_ary_tree_time_scale_start_time_modifier *this@<ecx>,
        int a2@<eax>,
        _DWORD *a3@<esi>,
        int a4@<xmm0>)
{
  int v4; // edi

  *a3 = &vostok::animation::mixing::n_ary_tree_time_scale_start_time_modifier::`vftable';
  a3[1] = this;
  a3[2] = a4;
  if ( !*(_DWORD *)(a2 + 4) )
    return a3;
  v4 = *(_DWORD *)(a2 + 88);
  if ( v4 )
  {
    if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v4 + 12))(v4) )
      (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v4 + 8))(v4, a3);
  }
  return a3;
}
