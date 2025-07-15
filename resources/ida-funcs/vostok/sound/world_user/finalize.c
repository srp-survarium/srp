void __thiscall vostok::sound::world_user::finalize(vostok::sound::world_user *this)
{
  if ( this->m_deleted_producers )
    vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::vectora<unsigned __int64>>(
      this->m_allocator,
      &this->m_deleted_producers);
  if ( this->m_deleted_receivers )
    vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::vectora<unsigned __int64>>(
      this->m_allocator,
      &this->m_deleted_receivers);
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_response,vostok::sound::sound_response,4>,vostok::intrusive_spsc_queue<vostok::sound::sound_response,vostok::sound::sound_response,4>>::owner_finalize(&this->m_channel.orders);
}
