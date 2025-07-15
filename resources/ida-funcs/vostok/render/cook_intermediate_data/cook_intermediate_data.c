void __userpurge vostok::render::cook_intermediate_data::cook_intermediate_data(
        vostok::render::cook_intermediate_data *this@<ecx>,
        const vostok::fs_new::virtual_path_string *in_resource_path@<eax>,
        vostok::resources::query_result_for_cook *in_query_result)
{
  vostok::fixed_string<260>::fixed_string<260>(&this->root_model_path.m_string, &in_resource_path->m_string);
  this->parent_query = in_query_result;
  this->status_failed = 0;
  this->render_model_data_ready = 0;
  this->material_data_ready = 0;
  this->root_model_path.m_separator = 47;
  this->result_model.m_object = 0;
  this->assets = 0;
  this->m_num_render_models = 0;
  this->model_settings_config.m_object = 0;
  this->m_surface_materials.m_begin = (const char **)this->m_surface_materials.m_buffer;
  this->m_surface_materials.m_end = (const char **)this->m_surface_materials.m_buffer;
  this->m_surface_materials.m_max_end = (const char **)&this[1].root_model_path.m_string.m_begin;
}
