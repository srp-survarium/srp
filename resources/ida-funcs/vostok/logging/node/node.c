void __thiscall vostok::logging::node::node(
        vostok::logging::node *this,
        const char *name,
        vostok::logging::verbosity filter)
{
  survarium::game_camera *v3; // ecx

  stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::_Impl_vector<void *,survarium::std_allocator<void *>>(
    (survarium::vector<vostok::resources::request> *)this,
    this);
  vostok::fixed_string<32>::fixed_string<32>(&this->name, name);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_children);
  boost::intrusive::rbtree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::init_header(&this->m_children.tree_.data_.node_plus_pred_.header_plus_size_.header_);
  survarium::weapon_user_dead_state::finalize(v3);
  this->m_verbosity = filter;
  this->m_thread_id = -1;
}
