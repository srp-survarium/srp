void __thiscall survarium::object_sky_ambient_occlusion::load(
        survarium::object_sky_ambient_occlusion *this,
        const vostok::configs::binary_config_value *t,
        const char *__formal,
        boost::function<void __cdecl(survarium::game_object_ &)> *cb)
{
  char *pointer; // edx
  char *m_begin; // ecx

  survarium::load_transform(t, &this->m_transform);
  this->m_generated = 0;
  this->m_width = (int)vostok::configs::binary_config_value::operator[](t, "width")->data.pointer;
  this->m_height = (int)vostok::configs::binary_config_value::operator[](t, "height")->data.pointer;
  this->m_depth = (int)vostok::configs::binary_config_value::operator[](t, "depth")->data.pointer;
  this->m_enabled = vostok::configs::binary_config_value::operator[](t, "enabled")->data.pointer != 0;
  this->m_resolution_x = (int)vostok::configs::binary_config_value::operator[](t, "resolution_x")->data.pointer;
  this->m_resolution_y = (int)vostok::configs::binary_config_value::operator[](t, "resolution_y")->data.pointer;
  pointer = (char *)vostok::configs::binary_config_value::operator[](t, "texture")->data.pointer;
  m_begin = this->m_texture_name.m_begin;
  if ( m_begin != pointer )
  {
    this->m_texture_name.m_end = m_begin;
    *m_begin = 0;
    vostok::buffer_string::operator+=(&this->m_texture_name, pointer);
  }
  boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
    (boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *)m_begin,
    cb,
    (const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *)this);
}
