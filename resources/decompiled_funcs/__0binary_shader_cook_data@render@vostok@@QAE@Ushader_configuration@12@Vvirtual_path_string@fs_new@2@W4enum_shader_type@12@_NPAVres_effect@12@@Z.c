void __userpurge vostok::render::binary_shader_cook_data::binary_shader_cook_data(
        vostok::render::binary_shader_cook_data *this@<esi>,
        vostok::render::res_effect *in_effect_resource@<eax>,
        vostok::render::shader_configuration in_configuration,
        vostok::fs_new::virtual_path_string in_shader_name,
        vostok::render::enum_shader_type in_shader_type,
        bool in_is_need_check_time)
{
  vostok::render::enum_shader_type v6; // edx

  this->effect_resource = in_effect_resource;
  this->configuration = in_configuration;
  this->shader_name.m_string.m_max_end = &this->shader_name.m_separator;
  this->shader_name.m_string.m_begin = this->shader_name.m_string.m_buffer;
  this->shader_name.m_string.m_end = this->shader_name.m_string.m_buffer;
  memcpy(
    (unsigned __int8 *)this->shader_name.m_string.m_buffer,
    (unsigned __int8 *)in_shader_name.m_string.m_begin,
    in_shader_name.m_string.m_end - in_shader_name.m_string.m_begin);
  this->shader_name.m_string.m_end += in_shader_name.m_string.m_end - in_shader_name.m_string.m_begin;
  v6 = STACK[0x128];
  *this->shader_name.m_string.m_end = 0;
  this->shader_name.m_separator = 47;
  this->shader_type = v6;
  this->is_need_check_time = 1;
}
