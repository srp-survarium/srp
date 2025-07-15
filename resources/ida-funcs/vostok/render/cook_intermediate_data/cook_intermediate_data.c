void __userpurge vostok::render::cook_intermediate_data::cook_intermediate_data(
        vostok::render::cook_intermediate_data *this@<esi>,
        const vostok::fs_new::virtual_path_string *in_resource_path@<eax>,
        vostok::resources::query_result_for_cook *in_query_result)
{
  unsigned __int8 *m_begin; // edx
  unsigned int v4; // ecx
  unsigned int v5; // edi

  m_begin = (unsigned __int8 *)in_resource_path->m_string.m_begin;
  v4 = in_resource_path->m_string.m_end - in_resource_path->m_string.m_begin;
  this->root_model_path.m_string.m_max_end = &this->root_model_path.m_separator;
  v5 = v4;
  this->root_model_path.m_string.m_begin = this->root_model_path.m_string.m_buffer;
  this->root_model_path.m_string.m_end = this->root_model_path.m_string.m_buffer;
  memcpy((unsigned __int8 *)this->root_model_path.m_string.m_buffer, m_begin, v4);
  this->root_model_path.m_string.m_end += v5;
  *this->root_model_path.m_string.m_end = 0;
  this->status_failed = 0;
  this->render_model_data_ready = 0;
  this->material_data_ready = 0;
  this->root_model_path.m_separator = 47;
  this->parent_query = in_query_result;
  this->result_model.m_object = 0;
  this->assets = 0;
  this->m_num_render_models = 0;
  this->model_settings_config.m_object = 0;
  this->m_surface_materials._M_impl._M_start = 0;
  this->m_surface_materials._M_impl._M_finish = 0;
  this->m_surface_materials._M_impl._M_end_of_storage._M_data = 0;
}
