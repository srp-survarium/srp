void __thiscall vostok::sound::sound_scene::emit_sound_propagators_impl(
        vostok::sound::sound_scene *this,
        const vostok::sound::create_sound_propagator_params *params)
{
  char v3; // [esp+24h] [ebp-48h]
  boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> v4; // [esp+2Ch] [ebp-40h] BYREF
  char v5; // [esp+53h] [ebp-19h]
  unsigned int i; // [esp+54h] [ebp-18h]
  vostok::sound::new_sound_propagator *prop; // [esp+58h] [ebp-14h]
  vostok::sound::sound_instance_proxy_internal *proxy; // [esp+5Ch] [ebp-10h]
  unsigned int old_props_count; // [esp+60h] [ebp-Ch]
  const vostok::sound::sound_propagator_emitter *emitter; // [esp+64h] [ebp-8h]
  vostok::sound::new_sound_propagator *last; // [esp+68h] [ebp-4h]

  v3 = 0;
  proxy = params->m_proxy;
  emitter = proxy->m_propagator_emitter;
  old_props_count = proxy->m_propagators.m_size;
  emitter->emit_sound_propagators(
    emitter,
    proxy,
    params->m_mode,
    params->m_playback_id,
    0,
    0,
    params->m_producer,
    params->m_ignorable_receiver);
  prop = proxy->m_propagators.m_first;
  for ( i = 0; i < old_props_count; ++i )
  {
    prop = prop->m_next_for_proxies;
    prop->m_is_callback_executer = 0;
  }
  last = prop;
  while ( prop )
  {
    last = prop;
    prop = prop->m_next_for_proxies;
  }
  v5 = 0;
  last->m_is_callback_executer = 1;
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "sound:", info) )
  {
    v4.vtable = 0;
    boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      &v4,
      vostok::core::g_log_callback);
    v3 = 1;
    vostok::logging::append(
      (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&v4,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\sound_scene_propagators.cpp",
      0x7Bu,
      "void __thiscall vostok::sound::sound_scene::emit_sound_propagators_impl(const struct vostok::sound::create_sound_p"
      "ropagator_params &)",
      "sound:",
      info,
      "sound propagators with id %d created",
      params->m_proxy->m_id);
  }
  if ( (v3 & 1) != 0 )
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>(&v4);
  if ( !old_props_count )
    vostok::intrusive_list<vostok::sound::sound_instance_proxy_internal,vostok::sound::sound_instance_proxy_internal *,488,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
      &this->m_active_proxies,
      proxy,
      0);
}
