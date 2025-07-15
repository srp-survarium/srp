void __usercall survarium::profile_player_character::clear_resources(
        survarium::profile_player_character *this@<ecx>,
        int *a2@<eax>)
{
  int v3; // eax
  int v4; // eax

  v3 = *a2;
  if ( v3
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    survarium::player::remove(
      (survarium::player *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr,
      v3);
  }
  v4 = *a2;
  *a2 = 0;
  if ( v4 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(v4 + 496), 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        (vostok::resources::unmanaged_intrusive_base *)(v4 + 496),
        (vostok::resources::unmanaged_resource *)(v4 + 288));
  }
}
