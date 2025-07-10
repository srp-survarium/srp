void __thiscall vostok::ai::behaviour::create_goals(
        vostok::ai::behaviour *this,
        vostok::configs::binary_config_value *options,
        vostok::ai::ai_world *world)
{
  survarium::game_camera *v3; // ecx
  const vostok::configs::binary_config_value *v4; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v5; // ecx
  BOOL v6; // ecx
  bool has_passed_filters; // al
  int v9; // [esp+34h] [ebp-44h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+38h] [ebp-40h] BYREF
  char v11; // [esp+5Ah] [ebp-1Eh]
  char v12; // [esp+5Bh] [ebp-1Dh]
  vostok::ai::planning::goal *new_goal; // [esp+5Ch] [ebp-1Ch]
  const vostok::configs::binary_config_value *goal_type_value; // [esp+60h] [ebp-18h]
  unsigned int goal_type; // [esp+64h] [ebp-14h]
  vostok::ai::planning::goal_types_enum type; // [esp+68h] [ebp-10h]
  const vostok::configs::binary_config_value *goals_value; // [esp+6Ch] [ebp-Ch]
  const vostok::configs::binary_config_value *it_end; // [esp+70h] [ebp-8h]
  const vostok::configs::binary_config_value *it; // [esp+74h] [ebp-4h]

  v9 = 0;
  v12 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v11 = 0;
  survarium::weapon_user_dead_state::finalize(v3);
  goals_value = vostok::configs::binary_config_value::operator[](options, "goals");
  it = (const vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)goals_value);
  it_end = vostok::configs::binary_config_value::end((vostok::configs::binary_config_value *)goals_value);
  while ( it != it_end )
  {
    goal_type_value = it;
    v4 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)it, "type");
    goal_type = (unsigned int)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                v5,
                                (int)v4);
    type = goal_type;
    new_goal = vostok::ai::create_goal_by_type(
                 (vostok::ai::planning::goal_types_enum)goal_type,
                 (vostok::configs::binary_config_value *)goal_type_value,
                 this->m_domain,
                 world);
    if ( new_goal )
    {
      vostok::intrusive_list<vostok::ai::planning::generalized_action,vostok::ai::planning::generalized_action *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
        (vostok::intrusive_list<vostok::ai::planning::generalized_action,vostok::ai::planning::generalized_action *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)&this->m_goals,
        (survarium::game_camera *)new_goal,
        0);
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "ai:", error),
            v6 = has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>((boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v6);
        v9 |= 1u;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\behaviour_goals.cpp",
          0xC1u,
          "void __thiscall vostok::ai::behaviour::create_goals(const class vostok::configs::binary_config_value &,class v"
          "ostok::ai::ai_world &)",
          "ai:",
          error,
          "Unknown goal type was declared - %d",
          goal_type);
      }
      if ( (v9 & 1) != 0 )
      {
        v9 &= ~1u;
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v6,
          (int *)&log_callback);
      }
    }
    ++it;
  }
  vostok::ai::behaviour::sort_goals(this);
}
