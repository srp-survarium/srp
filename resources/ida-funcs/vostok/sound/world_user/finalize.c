void __thiscall vostok::sound::world_user::finalize(vostok::sound::world_user *this)
{
  vostok::sound::world_user *v1; // esi
  vostok::sound::world_user *v2; // [esp-4h] [ebp-Ch]
  vostok::sound::world_user *v3; // [esp-4h] [ebp-Ch]

  v1 = this;
  if ( this->m_deleted_producers )
  {
    vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::vectora<unsigned __int64>>(
      &this->m_deleted_producers,
      this->m_orders_allocator,
      (const char *const)0x3C);
    this = v2;
  }
  if ( v1->m_deleted_receivers )
  {
    vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::vectora<unsigned __int64>>(
      &v1->m_deleted_receivers,
      v1->m_orders_allocator,
      (const char *const)0x3F);
    this = v3;
  }
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,8>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,8>>::owner_finalize(
    (vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,8>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,8> > *)this,
    (int)&v1->m_channel.orders,
    (vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,8>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,8> > *)v1);
}
