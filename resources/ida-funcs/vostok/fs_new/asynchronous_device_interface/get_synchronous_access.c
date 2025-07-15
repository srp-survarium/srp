void __thiscall vostok::fs_new::asynchronous_device_interface::get_synchronous_access(
        vostok::fs_new::asynchronous_device_interface *this,
        vostok::fs_new::synchronous_device_interface *in_out_synchronous_interface,
        vostok::memory::base_allocator *allocator)
{
  vostok::memory::base_allocator *v3; // eax
  DWORD v4; // eax
  vostok::fs_new::asynchronous_device_query *v5; // eax
  vostok::fs_new::asynchronous_device_query *v6; // [esp+0h] [ebp-18h]
  vostok::fs_new::asynchronous_device_query *v7; // [esp+4h] [ebp-14h]
  vostok::fs_new::synchronize_device_query *v9; // [esp+10h] [ebp-8h]
  vostok::fs_new::synchronize_device_query *synchronize_query; // [esp+14h] [ebp-4h]
  vostok::fs_new::synchronize_device_query *synchronize_querya; // [esp+14h] [ebp-4h]

  synchronize_query = 0;
  if ( this->m_device_mode == device_mode_asynchronous
    && this->m_synchronous_thread_id != vostok::threading::current_thread_id() )
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
    synchronize_querya = (vostok::fs_new::synchronize_device_query *)vostok::memory::malloc_helper<vostok::memory::base_allocator>(
                                                                       v3,
                                                                       0x40u);
    if ( synchronize_querya )
    {
      v9 = (vostok::fs_new::synchronize_device_query *)operator new(0x40u, synchronize_querya);
      if ( v9 )
      {
        v4 = vostok::threading::current_thread_id();
        vostok::fs_new::synchronize_device_query::synchronize_device_query(v9, this, v4, allocator);
        v6 = v5;
      }
      else
      {
        v6 = 0;
      }
      v7 = v6;
    }
    else
    {
      v7 = 0;
    }
    synchronize_query = (vostok::fs_new::synchronize_device_query *)v7;
    if ( v7 )
      vostok::fs_new::asynchronous_device_interface::push_high_priority_query(this, v7);
    else
      in_out_synchronous_interface->m_out_of_memory = 1;
  }
  vostok::fs_new::synchronous_device_interface::initialize_private(
    in_out_synchronous_interface,
    &this->m_device,
    synchronize_query);
}
