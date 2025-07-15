void __thiscall vostok::render::skeleton_combined_cook_data::model_def::model_def(
        vostok::render::skeleton_combined_cook_data::model_def *this)
{
  vostok::fs_new::virtual_path_string *v2; // ecx
  vostok::fs_new::virtual_path_string *v3; // ecx

  vostok::fs_new::virtual_path_string::virtual_path_string(&this->base_model_name, (int)this);
  vostok::fs_new::virtual_path_string::virtual_path_string(v2, (int)&this->part_name);
  vostok::fs_new::virtual_path_string::virtual_path_string(v3, (int)&this->material_name);
  this->owner_model_config.m_object = 0;
  this->export_properties_config.m_object = 0;
  this->material_effects.m_object = 0;
  this->converted_model.m_object = 0;
}
