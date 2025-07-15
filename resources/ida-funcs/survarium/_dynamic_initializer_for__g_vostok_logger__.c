int survarium::_dynamic_initializer_for__g_vostok_logger__()
{
  g_vostok_logger.RefCount = 1;
  g_vostok_logger.__vftable = (survarium::vostok_scaleform_log_vtbl *)&survarium::vostok_scaleform_log::`vftable';
  return atexit(survarium::_dynamic_atexit_destructor_for__g_vostok_logger__);
}
