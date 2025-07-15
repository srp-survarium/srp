void __thiscall vostok::logging::node::set(
        vostok::logging::node *this,
        char *initiator_path,
        int verbosity,
        unsigned int thread_id,
        vostok::memory::base_allocator *allocator,
        vostok::memory::base_allocator *allocator_to_clean)
{
  const char *v6; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v7; // ecx
  vostok::memory::base_allocator *v8; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v9; // ecx
  const vostok::variant<32> **v10; // eax
  vostok::logging::node *v11; // eax
  vostok::logging::node *v12; // [esp+8h] [ebp-C0h]
  void *_Where; // [esp+38h] [ebp-90h]
  boost::intrusive::rbtree_node<void *> *n_ptr[2]; // [esp+64h] [ebp-64h] BYREF
  stlp_std::priv::_STLP_alloc_proxy<vostok::sound::search::vertex_id_type *,vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type> > v16; // [esp+6Ch] [ebp-5Ch] BYREF
  boost::intrusive::tree_iterator<boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::logging::compare_nodes,unsigned int,0> >,0> result; // [esp+7Ch] [ebp-4Ch] BYREF
  vostok::logging::node *v18; // [esp+80h] [ebp-48h]
  boost::intrusive::multiset<vostok::logging::node_base,boost::intrusive::member_hook<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,boost::intrusive::compare<vostok::logging::compare_nodes>,boost::intrusive::constant_time_size<0>,boost::intrusive::none> *p_m_children; // [esp+84h] [ebp-44h]
  char *key; // [esp+88h] [ebp-40h] BYREF
  unsigned __int8 v21; // [esp+8Fh] [ebp-39h]
  const char *next_path_portion; // [esp+90h] [ebp-38h]
  vostok::fixed_string<32> path_portion; // [esp+94h] [ebp-34h] BYREF
  vostok::logging::node *child; // [esp+C0h] [ebp-8h]
  boost::intrusive::tree_iterator<boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::logging::compare_nodes,unsigned int,0> >,0> it; // [esp+C4h] [ebp-4h] BYREF

  if ( initiator_path && *initiator_path )
  {
    strchr(initiator_path, 0x3Au);
    next_path_portion = v6;
    vostok::fixed_string<32>::fixed_string<32>(&path_portion);
    if ( next_path_portion )
    {
      vostok::fs_new::path_string_impl::clear(&path_portion);
      vostok::buffer_string::append(&path_portion, initiator_path, next_path_portion);
    }
    else
    {
      vostok::fixed_string<16>::operator=((vostok::fixed_string<16> *)initiator_path, &path_portion);
    }
    key = (char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                    v7,
                    (int)&path_portion);
    boost::intrusive::detail::key_nodeptr_comp<vostok::logging::compare_nodes,boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::logging::compare_nodes,unsigned int,0>>>::key_nodeptr_comp<vostok::logging::compare_nodes,boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::logging::compare_nodes,unsigned int,0>>>(
      &v16,
      (const vostok::sound::std_allocator<vostok::sound::search::vertex_id_type> *)v21,
      (vostok::sound::search::vertex_id_type *)&this->m_children);
    n_ptr[1] = (boost::intrusive::rbtree_node<void *> *)v16._M_data;
    n_ptr[0] = boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::find<char const *,boost::intrusive::detail::key_nodeptr_comp<vostok::logging::compare_nodes,boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::logging::compare_nodes,unsigned int,0>>>>(
                 &this->m_children.tree_.data_.node_plus_pred_.header_plus_size_.header_,
                 &key,
                 (boost::intrusive::detail::key_nodeptr_comp<vostok::logging::compare_nodes,boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::logging::compare_nodes,unsigned int,0> > >)v16._M_data);
    boost::intrusive::tree_iterator<boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_packet,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,8>,vostok::network_core::udp_match_connection::comparer,unsigned int,1>>,0>::members::members(
      (boost::intrusive::tree_iterator<boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_packet,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,8>,vostok::network_core::udp_match_connection::comparer,unsigned int,1> >,0>::members *)&it,
      n_ptr,
      &this->m_children);
    child = 0;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_children);
    p_m_children = &this->m_children;
    if ( (boost::intrusive::multiset<vostok::logging::node_base,boost::intrusive::member_hook<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,boost::intrusive::compare<vostok::logging::compare_nodes>,boost::intrusive::constant_time_size<0>,boost::intrusive::none> *)it.members_.nodeptr_ == &this->m_children )
    {
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)(it.members_.nodeptr_ == &this->m_children.tree_.data_.node_plus_pred_.header_plus_size_.header_));
      _Where = vostok::memory::base_allocator::malloc_impl(v8, 0x54u);
      v18 = (vostok::logging::node *)operator new(0x54u, _Where);
      if ( v18 )
      {
        v10 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                v9,
                (int)&path_portion);
        vostok::logging::node::node(v18, (const char *)v10, invalid);
        v12 = v11;
      }
      else
      {
        v12 = 0;
      }
      child = v12;
      boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::logging::compare_nodes,unsigned int,0>>::insert_equal(
        &this->m_children.tree_,
        &result,
        v12);
    }
    else
    {
      child = (vostok::logging::node *)boost::intrusive::tree_iterator<boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::logging::compare_nodes,unsigned int,0>>,0>::operator->(&it);
    }
    if ( next_path_portion )
      vostok::logging::node::set(child, next_path_portion + 1, verbosity, thread_id, allocator, allocator_to_clean);
    else
      vostok::logging::node::set(child, 0, verbosity, thread_id, allocator, allocator_to_clean);
  }
  else
  {
    this->m_verbosity = verbosity & 0xFFFFFEFF;
    this->m_thread_id = thread_id;
    if ( (verbosity & 0x100) == 0 )
      vostok::logging::node::clean(this, allocator_to_clean);
  }
}
