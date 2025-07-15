int __thiscall dynamic_initializer_for__s_draw_draw_frustum_images_cc__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_draw_draw_frustum_images_cc,
    "r_draw_frustum_images",
    0,
    command_type_engine_internal,
    execution_filter_general);
  s_draw_draw_frustum_images_cc.m_value = &s_draw_draw_frustum_images_value;
  s_draw_draw_frustum_images_cc.m_min = 0;
  s_draw_draw_frustum_images_cc.m_max = 1;
  s_draw_draw_frustum_images_cc.__vftable = (vostok::console_commands::cc_bool_vtbl *)&vostok::console_commands::cc_bool::`vftable';
  s_draw_draw_frustum_images_cc.m_need_args = 1;
  return atexit(dynamic_atexit_destructor_for__s_draw_draw_frustum_images_cc__);
}
