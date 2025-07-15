bool __userpurge vostok::animation::animation_player::tick@<al>(
        vostok::animation::animation_player *this@<ecx>,
        int a2@<eax>,
        vostok::animation::subscribed_channel **current_time_in_ms)
{
  bool v4; // al
  vostok::animation::animation_player *v5; // ecx
  bool v6; // bl

  vostok::animation::animation_player::skip_time_if_needed(
    this,
    (vostok::animation::animation_player *)a2,
    (unsigned int)current_time_in_ms);
  ++*(_WORD *)(a2 + 34116);
  v4 = vostok::animation::mixing::n_ary_tree::tick(
         (vostok::animation::mixing::n_ary_tree *)(a2 + 34048),
         a2 + 34048,
         current_time_in_ms,
         (bool *)(a2 + 34100));
  --*(_WORD *)(a2 + 34116);
  v6 = v4;
  if ( !*(_WORD *)(a2 + 34116) && !*(_BYTE *)(a2 + 34118) )
    vostok::animation::animation_player::compact_callbacks(v5, (vostok::animation::animation_player *)a2);
  return v6;
}
