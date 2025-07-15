void __thiscall vostok::render::skeleton_combined_cook_data::model_def::model_def(
        vostok::render::skeleton_combined_cook_data::model_def *this)
{
  char *m_buffer; // ecx

  m_buffer = this->base_model_name.m_string.m_buffer;
  this->base_model_name.m_string.m_begin = m_buffer;
  this->base_model_name.m_string.m_end = m_buffer;
  this->base_model_name.m_separator = 47;
  this->base_model_name.m_string.m_max_end = m_buffer + 260;
  *m_buffer = 0;
  this->part_name.m_string.m_buffer[0] = 0;
  this->part_name.m_string.m_begin = this->part_name.m_string.m_buffer;
  this->part_name.m_string.m_end = this->part_name.m_string.m_buffer;
  this->part_name.m_separator = 47;
  this->part_name.m_string.m_max_end = &this->part_name.m_separator;
  this->material_name.m_string.m_begin = this->material_name.m_string.m_buffer;
  this->material_name.m_string.m_end = this->material_name.m_string.m_buffer;
  this->material_name.m_string.m_max_end = &this->material_name.m_separator;
  this->material_name.m_string.m_buffer[0] = 0;
  this->material_name.m_separator = 47;
  this->owner_model_config.m_object = 0;
  this->export_properties_config.m_object = 0;
  this->material_effects.m_object = 0;
  this->converted_model.m_object = 0;
}
