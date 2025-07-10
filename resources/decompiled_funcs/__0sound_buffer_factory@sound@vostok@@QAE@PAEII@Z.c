void __thiscall vostok::sound::sound_buffer_factory::sound_buffer_factory(
        vostok::sound::sound_buffer_factory *this,
        unsigned __int8 *buffer,
        unsigned int size,
        unsigned int max_buffers)
{
  vostok::sound::sound_buffer *m_mute_buffer; // [esp+30h] [ebp-1Ch]
  vostok::sound::sound_buffer_compare_predicate cmp; // [esp+42h] [ebp-Ah] BYREF
  boost::intrusive::detail::base_hook_traits<vostok::sound::sound_buffer,boost::intrusive::rbtree_node_traits<void *,0>,1,boost::intrusive::default_tag,3> v_traits; // [esp+43h] [ebp-9h] BYREF
  vostok::sound::sound_buffer *new_buffer; // [esp+44h] [ebp-8h]
  unsigned int i; // [esp+48h] [ebp-4h]

  this->m_free_sound_buffers.m_size = 0;
  this->m_free_sound_buffers.m_first = 0;
  this->m_free_sound_buffers.m_last = 0;
  this->m_lru_sound_buffers.m_size = 0;
  this->m_lru_sound_buffers.m_first = 0;
  this->m_lru_sound_buffers.m_last = 0;
  v_traits = 0;
  cmp = 0;
  boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::base_hook_traits<vostok::sound::sound_buffer,boost::intrusive::rbtree_node_traits<void *,0>,1,boost::intrusive::default_tag,3>,vostok::sound::sound_buffer_compare_predicate,unsigned int,1>>::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::base_hook_traits<vostok::sound::sound_buffer,boost::intrusive::rbtree_node_traits<void *,0>,1,boost::intrusive::default_tag,3>,vostok::sound::sound_buffer_compare_predicate,unsigned int,1>>(
    &this->m_cached_sound_buffers.tree_,
    &cmp,
    &v_traits);
  vostok::memory::single_size_buffer_allocator<44200,vostok::threading::single_threading_policy>::single_size_buffer_allocator<44200,vostok::threading::single_threading_policy>(
    &this->m_sound_buffers_allocator,
    buffer,
    size);
  for ( i = 0; i < max_buffers - 1; ++i )
  {
    new_buffer = (vostok::sound::sound_buffer *)vostok::memory::single_size_buffer_allocator<44200,vostok::threading::single_threading_policy>::malloc_impl(
                                                  &this->m_sound_buffers_allocator,
                                                  0xACA8u);
    if ( new_buffer )
      vostok::sound::sound_buffer::sound_buffer(new_buffer);
    vostok::intrusive_list<vostok::sound::sound_buffer,vostok::sound::sound_buffer *,16,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
      &this->m_free_sound_buffers,
      new_buffer,
      0);
  }
  if ( max_buffers )
  {
    this->m_mute_buffer = (vostok::sound::sound_buffer *)vostok::memory::single_size_buffer_allocator<44200,vostok::threading::single_threading_policy>::allocate(&this->m_sound_buffers_allocator);
    m_mute_buffer = this->m_mute_buffer;
    if ( m_mute_buffer )
      vostok::sound::sound_buffer::sound_buffer(m_mute_buffer);
  }
}
