vostok::sound::sound_buffer *__thiscall vostok::sound::sound_buffer_factory::new_sound_buffer(
        vostok::sound::sound_buffer_factory *this,
        const vostok::resources::resource_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base> *encoded_sound,
        unsigned int pcm_offset,
        unsigned int *next_pcm_offset)
{
  boost::intrusive::rbtree_node<void *> *n_ptr[2]; // [esp+74h] [ebp-34h] BYREF
  stlp_std::priv::_STLP_alloc_proxy<vostok::sound::search::vertex_id_type *,vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type> > v7; // [esp+7Ch] [ebp-2Ch] BYREF
  vostok::sound::sound_buffer *v8; // [esp+80h] [ebp-28h]
  char v9; // [esp+87h] [ebp-21h]
  stlp_std::pair<boost::intrusive::tree_iterator<boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::base_hook_traits<vostok::sound::sound_buffer,boost::intrusive::rbtree_node_traits<void *,0>,1,boost::intrusive::default_tag,3>,vostok::sound::sound_buffer_compare_predicate,unsigned int,1> >,0>,bool> v10; // [esp+88h] [ebp-20h] BYREF
  boost::intrusive::rbtree_node<void *> *p_header; // [esp+90h] [ebp-18h]
  unsigned __int8 v12; // [esp+97h] [ebp-11h]
  vostok::sound::sound_buffer *result; // [esp+98h] [ebp-10h]
  vostok::sound::lightweight_sound_buffer tmp; // [esp+9Ch] [ebp-Ch] BYREF
  boost::intrusive::tree_iterator<boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::base_hook_traits<vostok::sound::sound_buffer,boost::intrusive::rbtree_node_traits<void *,0>,1,boost::intrusive::default_tag,3>,vostok::sound::sound_buffer_compare_predicate,unsigned int,1> >,0> it; // [esp+A4h] [ebp-4h] BYREF

  vostok::sound::lightweight_sound_buffer::lightweight_sound_buffer(&tmp, encoded_sound, pcm_offset);
  boost::intrusive::detail::key_nodeptr_comp<vostok::logging::compare_nodes,boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::logging::compare_nodes,unsigned int,0>>>::key_nodeptr_comp<vostok::logging::compare_nodes,boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::logging::compare_nodes,unsigned int,0>>>(
    &v7,
    (const vostok::sound::std_allocator<vostok::sound::search::vertex_id_type> *)v12,
    (vostok::sound::search::vertex_id_type *)&this->m_cached_sound_buffers);
  n_ptr[1] = (boost::intrusive::rbtree_node<void *> *)v7._M_data;
  n_ptr[0] = boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::find<vostok::sound::lightweight_sound_buffer,boost::intrusive::detail::key_nodeptr_comp<vostok::sound::sound_buffer_compare_predicate,boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::base_hook_traits<vostok::sound::sound_buffer,boost::intrusive::rbtree_node_traits<void *,0>,1,boost::intrusive::default_tag,3>,vostok::sound::sound_buffer_compare_predicate,unsigned int,1>>>>(
               &this->m_cached_sound_buffers.tree_.data_.node_plus_pred_.header_plus_size_.header_,
               &tmp,
               (boost::intrusive::detail::key_nodeptr_comp<vostok::sound::sound_buffer_compare_predicate,boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::base_hook_traits<vostok::sound::sound_buffer,boost::intrusive::rbtree_node_traits<void *,0>,1,boost::intrusive::default_tag,3>,vostok::sound::sound_buffer_compare_predicate,unsigned int,1> > >)v7._M_data);
  boost::intrusive::tree_iterator<boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::base_hook_traits<vostok::sound::sound_buffer,boost::intrusive::rbtree_node_traits<void *,0>,1,boost::intrusive::default_tag,3>,vostok::sound::sound_buffer_compare_predicate,unsigned int,1>>,0>::members::members(
    &it.members_,
    n_ptr,
    &this->m_cached_sound_buffers);
  result = 0;
  p_header = &this->m_cached_sound_buffers.tree_.data_.node_plus_pred_.header_plus_size_.header_;
  if ( it.members_.nodeptr_ == &this->m_cached_sound_buffers.tree_.data_.node_plus_pred_.header_plus_size_.header_ )
  {
    if ( this->m_free_sound_buffers.m_first )
    {
      result = vostok::intrusive_list<vostok::sound::sound_buffer,vostok::sound::sound_buffer *,16,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::pop_front(&this->m_free_sound_buffers);
    }
    else
    {
      result = vostok::sound::sound_buffer_factory::find_least_recently_used(this);
      boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::base_hook_traits<vostok::sound::sound_buffer,boost::intrusive::rbtree_node_traits<void *,0>,1,boost::intrusive::default_tag,3>,vostok::sound::sound_buffer_compare_predicate,unsigned int,1>>::erase<vostok::sound::sound_buffer,vostok::sound::sound_buffer_compare_predicate>(
        &this->m_cached_sound_buffers.tree_,
        result,
        (vostok::sound::sound_buffer_compare_predicate)this->m_cached_sound_buffers.tree_.data_.node_plus_pred_.header_plus_size_.size_,
        0);
      vostok::intrusive_list<vostok::sound::sound_buffer,vostok::sound::sound_buffer *,16,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::erase(
        &this->m_lru_sound_buffers,
        result);
    }
    vostok::sound::sound_buffer::fill_buffer(result, encoded_sound, pcm_offset, next_pcm_offset);
    boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::base_hook_traits<vostok::sound::sound_buffer,boost::intrusive::rbtree_node_traits<void *,0>,1,boost::intrusive::default_tag,3>,vostok::sound::sound_buffer_compare_predicate,unsigned int,1>>::insert_unique(
      &this->m_cached_sound_buffers.tree_,
      &v10,
      result);
  }
  else
  {
    result = (vostok::sound::sound_buffer *)it.members_.nodeptr_;
    *next_pcm_offset = (unsigned int)it.members_.nodeptr_[5].parent_;
    vostok::intrusive_list<vostok::sound::sound_buffer,vostok::sound::sound_buffer *,16,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::erase(
      &this->m_lru_sound_buffers,
      result);
  }
  v9 = 0;
  vostok::intrusive_list<vostok::sound::sound_buffer,vostok::sound::sound_buffer *,16,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
    &this->m_lru_sound_buffers,
    result,
    0);
  ++result->m_reference_count;
  v8 = result;
  vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&tmp);
  return v8;
}
