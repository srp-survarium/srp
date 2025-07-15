void __thiscall survarium::object_light::load(
        survarium::object_light *this,
        const vostok::configs::binary_config_value *t,
        const char *__formal,
        boost::function<void __cdecl(survarium::game_object_ &)> *cb)
{
  boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *v5; // ecx

  survarium::load_transform(t, &this->m_transform);
  vostok::render::load_props_impl<vostok::configs::binary_config_value>(survarium::g_allocator, &this->m_props, t);
  boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
    v5,
    cb,
    (const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *)this);
}
