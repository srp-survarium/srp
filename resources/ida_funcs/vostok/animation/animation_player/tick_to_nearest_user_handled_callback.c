bool __userpurge vostok::animation::animation_player::tick_to_nearest_user_handled_callback@<al>(
        vostok::animation::animation_player *this@<ecx>,
        int a2@<eax>,
        vostok::animation::subscribed_channel **current_time_in_ms)
{
  int v4; // ecx
  unsigned int v5; // eax
  vostok::animation::subscribed_channel **v6; // esi
  vostok::animation::mixing::n_ary_tree *v7; // ecx
  bool v8; // bl

  vostok::animation::animation_player::skip_time_if_needed(
    this,
    (vostok::animation::animation_player *)a2,
    (unsigned int)current_time_in_ms);
  do
  {
    if ( *(_DWORD *)(a2 + 34052) )
    {
      v4 = **(_DWORD **)(a2 + 34068);
      v5 = *(_DWORD *)(v4 + 164);
    }
    else
    {
      v5 = -1;
    }
    v6 = (vostok::animation::subscribed_channel **)(v5
                                                  + ((unsigned int)current_time_in_ms < v5
                                                   ? (unsigned int)current_time_in_ms - v5
                                                   : 0));
    vostok::animation::animation_player::skip_time_if_needed(
      (vostok::animation::animation_player *)v4,
      (vostok::animation::animation_player *)a2,
      (unsigned int)v6);
    ++*(_WORD *)(a2 + 34116);
    v8 = vostok::animation::mixing::n_ary_tree::tick(v7, a2 + 34048, v6, (bool *)(a2 + 34100));
    if ( !--*(_WORD *)(a2 + 34116) && !*(_BYTE *)(a2 + 34118) )
      vostok::animation::animation_player::compact_callbacks(
        (vostok::animation::animation_player *)v4,
        (vostok::animation::animation_player *)a2);
  }
  while ( !v8 && v6 != current_time_in_ms );
  return v8;
}
