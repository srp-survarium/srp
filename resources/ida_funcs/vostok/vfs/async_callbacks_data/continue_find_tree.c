void __thiscall vostok::vfs::async_callbacks_data::continue_find_tree(vostok::vfs::async_callbacks_data *this)
{
  survarium::game_camera *v1; // ecx
  survarium::game_camera *v2; // ecx
  const char *v3; // eax
  vostok::vfs::base_node<1> *v4; // eax
  survarium::game_camera *v5; // ecx
  unsigned int increment; // [esp-4h] [ebp-3ECh]
  vostok::vfs::vfs_hashset *p_hashset; // [esp+158h] [ebp-290h]
  vostok::vfs::vfs_locked_iterator v9; // [esp+188h] [ebp-260h] BYREF
  vostok::vfs::base_node<1> *topmost_node; // [esp+19Ch] [ebp-24Ch]
  vostok::vfs::node_to_expand *it_expanded; // [esp+1A0h] [ebp-248h]
  vostok::vfs::result_enum result; // [esp+1A4h] [ebp-244h]
  vostok::fs_new::virtual_path_string previous_path; // [esp+1A8h] [ebp-240h] BYREF
  vostok::intrusive_list<vostok::vfs::node_to_expand,vostok::vfs::node_to_expand *,8,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> new_to_expand; // [esp+2C0h] [ebp-128h] BYREF
  vostok::fs_new::virtual_path_string current_path; // [esp+2D0h] [ebp-118h] BYREF

  this->callbacks_count = 0;
  this->callbacks_called_count = 0;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)this,
    &new_to_expand);
  survarium::weapon_user_dead_state::finalize(v1);
  new_to_expand.m_first = 0;
  new_to_expand.m_last = 0;
  vostok::fs_new::virtual_path_string::virtual_path_string(&previous_path);
  vostok::fs_new::virtual_path_string::virtual_path_string(&current_path);
  result = result_error;
  for ( it_expanded = this->nodes_to_expand.m_first; it_expanded; it_expanded = it_expanded->next )
  {
    vostok::vfs::base_node<1>::get_full_path(it_expanded->node, (vostok::fs_new::native_path_string *)&current_path);
    survarium::weapon_user_dead_state::finalize(v2);
    if ( !vostok::operator==(&current_path, &previous_path) )
    {
      p_hashset = &this->env.file_system->hashset;
      v3 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&current_path);
      topmost_node = vostok::vfs::vfs_hashset::find_no_lock(p_hashset, v3, check_locks_false);
      increment = it_expanded->increment;
      v4 = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::physical_folder_node,1>(topmost_node->m_parent.pointer);
      result = vostok::vfs::fill_expand_nodes_and_incref(
                 topmost_node,
                 v4,
                 topmost_node,
                 &new_to_expand,
                 this,
                 increment);
      if ( result == result_success )
        break;
      if ( &previous_path != &current_path )
        vostok::buffer_string::operator=(
          (vostok::fixed_string<32> *)&current_path,
          (vostok::fixed_string<32> *)&previous_path);
      vostok::fs_new::path_string_impl::verify_self(&previous_path);
    }
  }
  vostok::vfs::free_nodes_to_expand(&this->nodes_to_expand);
  if ( result == result_success )
  {
    vostok::vfs::free_nodes_to_expand(&new_to_expand);
    vostok::vfs::vfs_iterator::vfs_iterator(&v9);
    v9.mount_operation_id = 0;
    boost::function2<void,vostok::ai::brain_unit const *,vostok::ai::animation_item const *>::operator()(
      (boost::function2<void,char const *,vostok::network_core::udp_match_packet const *> *)&this->env.callback,
      (const char *)&v9,
      (const vostok::network_core::udp_match_packet *)3);
    vostok::vfs::vfs_locked_iterator::~vfs_locked_iterator(&v9);
  }
  else
  {
    vostok::intrusive_list<vostok::vfs::node_to_expand,vostok::vfs::node_to_expand *,8,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::swap(
      &this->nodes_to_expand,
      &new_to_expand);
  }
  vostok::vfs::query_expand_nodes(&this->nodes_to_expand, this);
  survarium::weapon_user_dead_state::finalize(v5);
}
