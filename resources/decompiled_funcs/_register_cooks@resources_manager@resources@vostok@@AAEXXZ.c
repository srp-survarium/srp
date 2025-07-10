void __thiscall vostok::resources::resources_manager::register_cooks(vostok::resources::resources_manager *this)
{
  vostok::resources::unknown_data_class_cook *v1; // ecx

  vostok::resources::resources_manager::get_binary_config_cook(this);
  vostok::resources::resources_manager::register_cook(&s_sub_fat_cook);
  if ( (_S3_5 & 1) == 0 )
  {
    _S3_5 |= 1u;
    vostok::resources::unknown_data_class_cook::unknown_data_class_cook(v1);
    atexit(vostok::resources::resources_manager::register_cooks_::_2_::_dynamic_atexit_destructor_for__unknown_data_cook__);
  }
  vostok::resources::resources_manager::register_cook(&unknown_data_cook);
}
