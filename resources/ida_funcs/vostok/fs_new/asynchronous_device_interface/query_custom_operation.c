char __thiscall vostok::fs_new::asynchronous_device_interface::query_custom_operation(
        vostok::fs_new::asynchronous_device_interface *this,
        const vostok::fs_new::query_custom_operation_args *args,
        vostok::memory::base_allocator *allocator)
{
  vostok::memory::base_allocator *v4; // eax
  vostok::fs_new::custom_operation_query *v5; // eax
  vostok::fs_new::custom_operation_query *v6; // [esp+4h] [ebp-A8h]
  vostok::fs_new::custom_operation_query *v7; // [esp+8h] [ebp-A4h]
  vostok::fs_new::custom_operation_query *v9; // [esp+24h] [ebp-88h]
  vostok::fs_new::custom_operation_query synchronous_query; // [esp+2Ch] [ebp-80h] BYREF
  vostok::fs_new::custom_operation_query *new_query; // [esp+A8h] [ebp-4h]

  if ( this->m_device_mode )
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
    new_query = (vostok::fs_new::custom_operation_query *)vostok::memory::malloc_helper<vostok::memory::base_allocator>(
                                                            v4,
                                                            0x78u);
    if ( new_query )
    {
      v9 = (vostok::fs_new::custom_operation_query *)operator new(0x78u, new_query);
      if ( v9 )
      {
        vostok::fs_new::custom_operation_query::custom_operation_query(v9, args, allocator, &this->m_device);
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
    new_query = v7;
    if ( v7 )
    {
      vostok::fs_new::asynchronous_device_interface::push_query(this, new_query);
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    vostok::fs_new::custom_operation_query::custom_operation_query(&synchronous_query, args, allocator, &this->m_device);
    vostok::fs_new::custom_operation_query::execute(&synchronous_query);
    vostok::fs_new::custom_operation_query::callback_if_needed(&synchronous_query);
    synchronous_query.__vftable = (vostok::fs_new::custom_operation_query_vtbl *)&vostok::fs_new::custom_operation_query::`vftable';
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)&synchronous_query.m_args,
      (int *)&synchronous_query.m_args.callback);
    boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&synchronous_query.m_args);
    synchronous_query.__vftable = (vostok::fs_new::custom_operation_query_vtbl *)&vostok::fs_new::asynchronous_device_query::`vftable';
    return 1;
  }
}
