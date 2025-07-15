void __thiscall vostok::engine::engine_world::initialize_core(
        vostok::engine::engine_world *this,
        vostok::engine::engine_world *thisa)
{
  char *v2; // ebx
  const char *v3; // edi
  vostok::strings::detail::tuples *v4; // ecx
  void *v5; // esp
  vostok::strings::detail::tuples *v6; // ecx
  BOOL v7; // [esp-4h] [ebp-48h]
  vostok::threading *v8; // [esp+0h] [ebp-44h] BYREF
  vostok::strings::detail::tuples STR_JOINA_tuples_unique_identifier; // [esp+Ch] [ebp-38h] BYREF
  vostok::command_line::key_initializator predicate[4]; // [esp+40h] [ebp-4h]

  if ( vostok::threading::g_debug_single_thread.m_type == type_unset )
  {
    predicate[0] = 0;
    vostok::threading::g_debug_single_thread.m_type = type_recursive;
    vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
  }
  if ( vostok::threading::g_debug_single_thread.m_type == type_recursive )
  {
    if ( !s_logical_core_count )
      vostok::threading::initialize_core_count(v8);
    if ( s_logical_core_count == 1 )
    {
      if ( thisa->command_line_editor(&thisa->vostok::engine_user::engine) )
        v2 = "editor + logic + render";
      else
        v2 = "logic + render";
    }
    else
    {
      v2 = "render";
    }
  }
  else
  {
    v2 = "main";
  }
  v3 = thisa->get_resources_path(thisa);
  vostok::strings::detail::tuples::tuples(&STR_JOINA_tuples_unique_identifier, v3, "/sources");
  v5 = alloca(vostok::strings::detail::tuples::size(v4, (unsigned int *)&STR_JOINA_tuples_unique_identifier));
  vostok::strings::detail::tuples::size(v6, (unsigned int *)&STR_JOINA_tuples_unique_identifier);
  vostok::strings::detail::tuples::concat((char *)&v8, &STR_JOINA_tuples_unique_identifier);
  v7 = !thisa->command_line_editor(&thisa->vostok::engine_user::engine);
  vostok::core::initialize(v2, (const char *)v7);
  survarium::scaleform_engine::initialize();
}
