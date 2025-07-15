void __thiscall vostok::animation::mixing::n_ary_tree::update_event_iterators(
        vostok::animation::mixing::n_ary_tree *this,
        _DWORD *target_time_in_ms,
        vostok::animation::mixing::n_ary_tree_event_iterator *a3)
{
  const vostok::animation::mixing::animation_state *const *v3; // eax
  const boost::function<unsigned char __cdecl(void const *)> *v4; // ecx
  unsigned __int8 *v5; // edi
  int v6; // esi
  unsigned __int8 *v7; // eax
  int v8; // esi
  int v9; // eax
  event_iterator_predicate v10; // [esp+10h] [ebp-8h] BYREF
  const vostok::animation::mixing::animation_state *const *v11; // [esp+14h] [ebp-4h]

  while ( 1 )
  {
    v9 = *(_DWORD *)target_time_in_ms[5];
    if ( *(vostok::animation::mixing::n_ary_tree_event_iterator **)(v9 + 160) != a3 )
      break;
    vostok::animation::mixing::n_ary_tree_event_iterator::operator++(a3, v9 + 120);
    v3 = (const vostok::animation::mixing::animation_state *const *)target_time_in_ms[5];
    v4 = (const boost::function<unsigned char __cdecl(void const *)> *)target_time_in_ms[7];
    v5 = (unsigned __int8 *)(v3 + 1);
    v6 = (4 * target_time_in_ms[8] - 4) >> 2;
    v11 = v3;
    v10.m_animated_object_resolver = v4;
    if ( v6 > 0 )
    {
      while ( 1 )
      {
        if ( event_iterator_predicate::operator()(
               &v10,
               *v3,
               *(const vostok::animation::mixing::animation_state *const *)&v5[4 * (v6 >> 1)]) )
        {
          v5 += 4 * (v6 >> 1) + 4;
          v6 += -1 - (v6 >> 1);
        }
        else
        {
          v6 >>= 1;
        }
        if ( v6 <= 0 )
          break;
        v3 = v11;
      }
    }
    v7 = (unsigned __int8 *)target_time_in_ms[5];
    v8 = *(_DWORD *)v7;
    stlp_std::priv::__copy_trivial(v7 + 4, v5, v7);
    *((_DWORD *)v5 - 1) = v8;
  }
}
