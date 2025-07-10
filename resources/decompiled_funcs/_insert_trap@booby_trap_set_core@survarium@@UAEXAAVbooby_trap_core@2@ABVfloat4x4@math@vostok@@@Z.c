void __thiscall survarium::booby_trap_set_core::insert_trap(
        survarium::booby_trap_set_core *this,
        survarium::booby_trap_core *trap,
        const vostok::math::float4x4 *transform)
{
  survarium::inventory_item *v3; // ecx
  survarium::inventory *inventory; // eax
  survarium::inventory *v5; // ecx
  survarium::game_camera *v6; // ecx
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v7; // ecx
  survarium::base_project::resolve_link_object *v8; // eax
  vostok::physics::world *world; // [esp+8h] [ebp-8h]
  survarium::inventory_holder *holder; // [esp+Ch] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  inventory = survarium::inventory_item::get_inventory(v3, (int)this);
  holder = survarium::inventory::holder(v5, (int)inventory);
  world = holder->get_physics_world(holder);
  survarium::weapon_user_dead_state::finalize(v6);
  v8 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
         v7,
         (int)holder);
  trap->insert(trap, world, transform, (survarium::scheduler *)v8);
  holder->insert_game_world_object(holder, trap);
}
