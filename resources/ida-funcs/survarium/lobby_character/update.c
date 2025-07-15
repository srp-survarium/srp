void __userpurge survarium::lobby_character::update(
        survarium::lobby_character *this@<ecx>,
        int a2@<esi>,
        unsigned int current_time_in_ms,
        const unsigned int frame_delta_in_ms)
{
  int v4; // ecx

  v4 = *(_DWORD *)(a2 + 4564);
  if ( v4 )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v4 + 48))(v4, current_time_in_ms);
      survarium::player::mt_draw(*(survarium::player **)(a2 + 4564));
    }
  }
}
