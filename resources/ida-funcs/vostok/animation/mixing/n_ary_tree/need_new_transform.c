bool __thiscall vostok::animation::mixing::n_ary_tree::need_new_transform(
        vostok::animation::mixing::n_ary_tree *this,
        unsigned int target_time_in_ms,
        int a3)
{
  unsigned int v3; // ebx
  _DWORD *v4; // esi
  bool result; // al
  int v6; // ecx
  int v7; // ecx

  v3 = target_time_in_ms;
  v4 = *(_DWORD **)(target_time_in_ms + 4);
  for ( result = 0; v4; v4 = (_DWORD *)v4[10] )
  {
    v6 = v4[7];
    if ( *(_DWORD *)(v6 + 160) == a3 && (*(_WORD *)(v6 + 164) & 0x1DF) != 0 )
    {
      v7 = 136 * *(_DWORD *)(v3 + 36);
      target_time_in_ms = v4[9];
      stlp_std::priv::__find<vostok::animation::mixing::animated_object_holder *,void const *>(
        *(vostok::animation::mixing::animated_object_holder **)(v3 + 24),
        (const void **)&target_time_in_ms,
        (vostok::animation::mixing::animated_object_holder *)(*(_DWORD *)(v3 + 24) + v7))->need_new_transform = 1;
      result = 1;
    }
  }
  return result;
}
