void __thiscall survarium::object_lpv_occluder::load(
        survarium::object_lpv_occluder *this,
        const vostok::configs::binary_config_value *t,
        const char *__formal,
        boost::function<void __cdecl(survarium::game_object_ &)> *cb)
{
  boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *v5; // [esp-4h] [ebp-Ch]

  survarium::load_transform(t, &this->m_transform);
  boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
    v5,
    cb,
    (const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *)this);
}
