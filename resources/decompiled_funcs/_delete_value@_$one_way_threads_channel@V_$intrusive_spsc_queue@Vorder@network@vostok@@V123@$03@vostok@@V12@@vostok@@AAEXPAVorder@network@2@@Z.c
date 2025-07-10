void __thiscall vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>,vostok::intrusive_spsc_queue<vostok::network::order,vostok::network::order,4>>::delete_value(
        vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4>,vostok::intrusive_spsc_queue<vostok::network::response,vostok::network::response,4> > *this,
        vostok::network::response *value)
{
  vostok::memory::base_allocator *v2; // eax
  vostok::memory::detail::call_destructor_predicate call_destructor_predicate; // [esp+13h] [ebp-5h] BYREF
  vostok::network::response *temp; // [esp+14h] [ebp-4h] BYREF

  temp = value;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  call_destructor_predicate = 0;
  vostok::memory::detail::delete_helper_impl<vostok::memory::base_allocator,vostok::sound::sound_order,vostok::memory::detail::call_destructor_predicate>(
    v2,
    (vostok::sound::sound_order **)&temp,
    &call_destructor_predicate);
}
