void __thiscall survarium::booby_trap_set_core::remove_trap_impl(
        survarium::booby_trap_set_core *this,
        survarium::booby_trap_core *trap)
{
  survarium::inventory_item *v2; // ecx
  survarium::inventory *inventory; // eax
  survarium::inventory *v4; // ecx
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v5; // ecx
  survarium::base_project::resolve_link_object *v6; // eax
  survarium::inventory_holder *holder; // [esp+8h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  inventory = survarium::inventory_item::get_inventory(v2, (int)this);
  holder = survarium::inventory::holder(v4, (int)inventory);
  holder->remove_game_world_object(holder, trap);
  v6 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
         v5,
         (int)holder);
  trap->remove(trap, (survarium::scheduler *)v6);
}
