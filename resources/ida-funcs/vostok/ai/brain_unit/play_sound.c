void __thiscall vostok::ai::brain_unit::play_sound(
        vostok::ai::brain_unit *this,
        const vostok::ai::sound_item *const sound_to_be_played)
{
  bool has_passed_filters; // al
  vostok::render::skeleton_model_instance *v3; // eax
  const char *v4; // eax
  const char *v5; // [esp-4h] [ebp-3Ch]
  const vostok::ai::game_object *v6; // [esp+4h] [ebp-34h]
  vostok::ai::brain_unit *thisa; // [esp+8h] [ebp-30h]
  char v8; // [esp+14h] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+18h] [ebp-20h] BYREF

  thisa = this;
  v8 = 0;
  if ( !vostok::core::g_log_filter_tree
    || (has_passed_filters = vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "ai:", info),
        (this = (vostok::ai::brain_unit *)has_passed_filters) != 0) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>((boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this);
    v8 = 1;
    v6 = thisa->m_npc->cast_game_object(thisa->m_npc);
    v3 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&sound_to_be_played->name);
    v4 = (const char *)((int (__thiscall *)(const vostok::ai::game_object *, vostok::render::skeleton_model_instance *))v6->get_name)(
                         v6,
                         v3);
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\brain_unit.cpp",
      0x122u,
      "void __thiscall vostok::ai::brain_unit::play_sound(const struct vostok::ai::sound_item *const )",
      "ai:",
      info,
      "%s: playing sound %s",
      v4,
      v5);
  }
  if ( (v8 & 1) != 0 )
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)this,
      (int *)&log_callback);
}
