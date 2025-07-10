void __cdecl vostok::ai::get_id_by_name(survarium::game_camera *objects, const char *name)
{
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v2; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+1Ch] [ebp-28h] BYREF
  unsigned int i; // [esp+40h] [ebp-4h]

  for ( i = 0; ; ++i )
  {
    v2 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)objects;
    if ( i >= (signed int)(LODWORD(objects->m_inverted_view_matrix.i.x) - (unsigned int)objects->__vftable) >> 2 )
      break;
    survarium::weapon_user_dead_state::finalize(objects);
    if ( vostok::strings::equal(*((const char **)&objects->get_projection_matrix + i), name) )
      return;
  }
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "ai:", error) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v2);
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\ai_world.cpp",
      0x10Bu,
      "unsigned int __cdecl vostok::ai::get_id_by_name(const class vostok::fixed_vector<char *,32> &,const char *)",
      "ai:",
      error,
      "object %s is absent in dictionary",
      name);
  }
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v2,
    (int *)&log_callback);
}
