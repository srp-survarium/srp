int vostok::core::_dynamic_initializer_for__s_preinitializer__()
{
  s_debug_engine = (vostok::debug::engine *)&s_preinitializer;
  vostok::debug::g_disable_output_to_debugger = vostok::collision::box_geometry_instance::is_valid((vostok::render::stage_screen_space_reflections *)&s_preinitializer) == 0;
  return atexit(vostok::core::_dynamic_atexit_destructor_for__s_preinitializer__);
}
