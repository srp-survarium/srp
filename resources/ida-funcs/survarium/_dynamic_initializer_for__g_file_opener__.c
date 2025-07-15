int survarium::_dynamic_initializer_for__g_file_opener__()
{
  g_file_opener.RefCount = 1;
  g_file_opener.SType = State_FileOpener;
  GFx_Compile_with_SF_BUILD_DEBUG = 0;
  g_file_opener.__vftable = (survarium::vostok_file_opener_vtbl *)&survarium::vostok_file_opener::`vftable';
  g_file_opener.cached_file.raw_data = 0;
  g_file_opener.cached_file.raw_data_size = 0;
  return atexit(survarium::_dynamic_atexit_destructor_for__g_file_opener__);
}
