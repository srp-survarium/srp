void __userpurge vostok::resources::query_result::init_save(
        vostok::resources::query_result *this@<esi>,
        vostok::resources::query_result *data_to_save_generator@<eax>,
        vostok::resources::save_generated_data *save_data)
{
  this->m_data_to_save_generator = data_to_save_generator;
  vostok::threading::interlocked_and(&this->m_flags, 0xFFFFFFF9);
  vostok::threading::interlocked_or(&this->m_flags, 8u);
  strcpy_s(this->m_request_path, this->m_request_path_max_size, save_data->m_virtual_path);
  this->m_save_generated_data = save_data;
}
