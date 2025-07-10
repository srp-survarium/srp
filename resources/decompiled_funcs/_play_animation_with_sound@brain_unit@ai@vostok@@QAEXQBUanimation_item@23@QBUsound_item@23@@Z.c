void __thiscall vostok::ai::brain_unit::play_animation_with_sound(
        vostok::ai::brain_unit *this,
        const vostok::ai::animation_item *const animation_to_be_played,
        const vostok::ai::sound_item *const sound_to_be_played)
{
  bool has_passed_filters; // al
  vostok::render::skeleton_model_instance *v4; // eax
  const char *v5; // eax
  const char *v6; // [esp-8h] [ebp-40h]
  vostok::render::skeleton_model_instance *v7; // [esp-4h] [ebp-3Ch]
  const char *v8; // [esp-4h] [ebp-3Ch]
  const vostok::ai::game_object *v9; // [esp+4h] [ebp-34h]
  vostok::ai::brain_unit *thisa; // [esp+8h] [ebp-30h]
  char v11; // [esp+14h] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+18h] [ebp-20h] BYREF

  thisa = this;
  v11 = 0;
  if ( !vostok::core::g_log_filter_tree
    || (has_passed_filters = vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "ai:", info),
        (this = (vostok::ai::brain_unit *)has_passed_filters) != 0) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>((boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this);
    v11 = 1;
    v9 = thisa->m_npc->cast_game_object(thisa->m_npc);
    v7 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&sound_to_be_played->name);
    v4 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&animation_to_be_played->name);
    v5 = (const char *)((int (__thiscall *)(const vostok::ai::game_object *, vostok::render::skeleton_model_instance *, vostok::render::skeleton_model_instance *))v9->get_name)(
                         v9,
                         v4,
                         v7);
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\brain_unit.cpp",
      0x12Fu,
      "void __thiscall vostok::ai::brain_unit::play_animation_with_sound(const struct vostok::ai::animation_item *const ,"
      "const struct vostok::ai::sound_item *const )",
      "ai:",
      info,
      "%s: playing animation %s with sound %s",
      v5,
      v6,
      v8);
  }
  if ( (v11 & 1) != 0 )
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)this,
      (int *)&log_callback);
  vostok::ai::brain_unit::play_animation(thisa, animation_to_be_played);
  vostok::ai::brain_unit::play_sound(thisa, sound_to_be_played);
}
