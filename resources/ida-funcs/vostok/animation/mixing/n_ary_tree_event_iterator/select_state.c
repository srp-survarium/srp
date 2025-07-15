void __thiscall vostok::animation::mixing::n_ary_tree_event_iterator::select_state(
        vostok::animation::mixing::n_ary_tree_event_iterator *this,
        _DWORD *a2)
{
  vostok::animation::mixing::animation_event *v2; // eax
  vostok::animation::mixing::n_ary_tree_weight_event_iterator *v3; // ecx
  vostok::animation::mixing::n_ary_tree_weight_event_iterator *v4; // ecx
  vostok::animation::mixing::animation_event result; // [esp+10h] [ebp-24h] BYREF
  int v6; // [esp+20h] [ebp-14h]
  int v7; // [esp+24h] [ebp-10h]
  unsigned int v8; // [esp+28h] [ebp-Ch]
  int v9; // [esp+2Ch] [ebp-8h]

  v6 = *a2;
  v7 = a2[1];
  v8 = a2[2];
  v9 = a2[3];
  v2 = vostok::animation::mixing::n_ary_tree_weight_event_iterator::operator*(
         (vostok::animation::mixing::n_ary_tree_weight_event_iterator *)this,
         &result);
  if ( v2->event_time_in_ms >= v8 )
  {
    a2[8] = *a2;
    a2[9] = a2[1];
    a2[10] = a2[2];
    a2[11] = a2[3];
    a2[13] = 1;
    if ( vostok::animation::mixing::n_ary_tree_weight_event_iterator::operator*(v3, &result)->event_time_in_ms == a2[10] )
    {
      a2[13] = 3;
      *((_WORD *)a2 + 22) |= vostok::animation::mixing::n_ary_tree_weight_event_iterator::operator*(v4, &result)->event_type;
    }
  }
  else
  {
    a2[13] = 2;
    *((vostok::animation::mixing::animation_event *)a2 + 2) = *vostok::animation::mixing::n_ary_tree_weight_event_iterator::operator*(
                                                                 v3,
                                                                 &result);
  }
}
