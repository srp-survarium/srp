void __thiscall vostok::sound::sound_buffer_factory::~sound_buffer_factory(vostok::sound::sound_buffer_factory *this)
{
  vostok::sound::sound_buffer *pointer; // [esp+48h] [ebp-10h] BYREF
  vostok::sound::sound_buffer *object_to_be_deleted; // [esp+4Ch] [ebp-Ch] BYREF
  vostok::sound::sound_buffer *lru_sound_buffer; // [esp+50h] [ebp-8h]
  vostok::sound::sound_buffer *free_sound_buffer; // [esp+54h] [ebp-4h]

  boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::base_hook_traits<vostok::sound::sound_buffer,boost::intrusive::rbtree_node_traits<void *,0>,1,boost::intrusive::default_tag,3>,vostok::sound::sound_buffer_compare_predicate,unsigned int,1>>::clear(&this->m_cached_sound_buffers.tree_);
  lru_sound_buffer = this->m_lru_sound_buffers.m_first;
  while ( lru_sound_buffer )
  {
    object_to_be_deleted = lru_sound_buffer;
    lru_sound_buffer = lru_sound_buffer->m_next;
    vostok::sound::sound_buffer::~sound_buffer(object_to_be_deleted);
    vostok::memory::free_helper<vostok::memory::single_size_buffer_allocator<44200,vostok::threading::single_threading_policy>,vostok::sound::sound_buffer>(
      &this->m_sound_buffers_allocator,
      &object_to_be_deleted);
  }
  free_sound_buffer = this->m_free_sound_buffers.m_first;
  while ( free_sound_buffer )
  {
    pointer = free_sound_buffer;
    free_sound_buffer = free_sound_buffer->m_next;
    vostok::sound::sound_buffer::~sound_buffer(pointer);
    vostok::memory::free_helper<vostok::memory::single_size_buffer_allocator<44200,vostok::threading::single_threading_policy>,vostok::sound::sound_buffer>(
      &this->m_sound_buffers_allocator,
      &pointer);
  }
  boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::base_hook_traits<vostok::sound::sound_buffer,boost::intrusive::rbtree_node_traits<void *,0>,1,boost::intrusive::default_tag,3>,vostok::sound::sound_buffer_compare_predicate,unsigned int,1>>::clear(&this->m_cached_sound_buffers.tree_);
}
