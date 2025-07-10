void __thiscall vostok::ai::planning::specified_problem::dump_target_world_state(
        vostok::ai::planning::specified_problem *this)
{
  survarium::game_camera *v1; // ecx
  survarium::game_camera *v2; // ecx
  survarium::game_camera *v3; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v4; // ecx
  char *v5; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v6; // ecx
  const vostok::variant<32> **v7; // eax
  survarium::game_camera *v8; // ecx
  survarium::game_camera *v9; // ecx
  survarium::game_camera *v10; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v11; // ecx
  char *v12; // eax
  bool has_passed_filters; // al
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v14; // ecx
  const vostok::variant<32> **v15; // eax
  unsigned int v16; // [esp+8h] [ebp-1148h]
  unsigned int v18; // [esp+40h] [ebp-1110h]
  unsigned int v19; // [esp+48h] [ebp-1108h]
  unsigned int type; // [esp+88h] [ebp-10C8h]
  unsigned int v21; // [esp+90h] [ebp-10C0h]
  char v22; // [esp+BCh] [ebp-1094h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v23; // [esp+C0h] [ebp-1090h] BYREF
  char v24; // [esp+E7h] [ebp-1069h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+E8h] [ebp-1068h] BYREF
  char v26; // [esp+10Fh] [ebp-1041h]
  const vostok::ai::planning::object_instance *object_by_type_and_index; // [esp+110h] [ebp-1040h]
  unsigned int j; // [esp+114h] [ebp-103Ch]
  vostok::buffer_vector<unsigned int> *p_m_indices; // [esp+118h] [ebp-1038h]
  unsigned int v30; // [esp+11Ch] [ebp-1034h]
  unsigned int i; // [esp+120h] [ebp-1030h]
  const vostok::ai::planning::object_instance *v32; // [esp+124h] [ebp-102Ch]
  unsigned int index; // [esp+128h] [ebp-1028h]
  survarium::game_camera *v34; // [esp+12Ch] [ebp-1024h]
  unsigned int k; // [esp+130h] [ebp-1020h]
  int v36; // [esp+134h] [ebp-101Ch]
  vostok::fixed_string<4096> v37; // [esp+138h] [ebp-1018h] BYREF
  unsigned int v38; // [esp+1148h] [ebp-8h]
  unsigned int v39; // [esp+114Ch] [ebp-4h]

  v22 = 0;
  vostok::fixed_string<4096>::fixed_string<4096>(&v37, "target world state:\n");
  v39 = this->m_target_offsets.m_end - this->m_target_offsets.m_begin;
  v36 = stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>::size(&this->m_target_world_state._M_impl);
  v38 = 0;
  if ( v39 )
  {
    for ( i = 0; i <= v39; ++i )
    {
      if ( i >= v39 )
      {
        v16 = v36;
      }
      else
      {
        survarium::weapon_user_dead_state::finalize(v1);
        v16 = this->m_target_offsets.m_begin[i];
      }
      v8 = (survarium::game_camera *)v16;
      v30 = v16;
      while ( v38 < v30 )
      {
        survarium::weapon_user_dead_state::finalize(v8);
        p_m_indices = &this->m_target_world_state._M_impl._M_start[v38].m_indices;
        vostok::buffer_string::append(&v37, *((char **)p_m_indices[3].m_begin + 7));
        vostok::buffer_string::append(&v37, " (");
        for ( j = 0; ; ++j )
        {
          v9 = (survarium::game_camera *)(p_m_indices->m_end - p_m_indices->m_begin);
          if ( j >= (unsigned int)v9 )
            break;
          survarium::weapon_user_dead_state::finalize(v9);
          v19 = *vostok::buffer_vector<unsigned int>::operator[](p_m_indices, j);
          v18 = *vostok::buffer_vector<unsigned int>::operator[](
                   (vostok::buffer_vector<unsigned int> *)(p_m_indices[3].m_begin + 1),
                   j);
          object_by_type_and_index = vostok::ai::planning::specified_problem::get_object_by_type_and_index(
                                       this,
                                       v18,
                                       v19);
          v24 = 0;
          survarium::weapon_user_dead_state::finalize(v10);
          v12 = (char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                          v11,
                          (int)&object_by_type_and_index->m_caption);
          vostok::buffer_string::append(&v37, v12);
          if ( j == p_m_indices->m_end - p_m_indices->m_begin - 1 )
            vostok::buffer_string::append(&v37, ")");
          else
            vostok::buffer_string::append(&v37, (char *)&stru_95AF78.m_key_bindings[32]);
        }
        if ( !(p_m_indices->m_end - p_m_indices->m_begin) )
          vostok::buffer_string::append(&v37, ")");
        v8 = (survarium::game_camera *)(this->m_target_world_state._M_impl._M_finish
                                      - this->m_target_world_state._M_impl._M_start
                                      - 1);
        if ( v38 < (unsigned int)v8 )
          vostok::buffer_string::append(&v37, "\n");
        ++v38;
      }
      if ( v38 < v36 - 1 )
        vostok::buffer_string::append(&v37, "  or  \n");
      v1 = (survarium::game_camera *)(i + 1);
    }
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "ai:", info),
          (v1 = (survarium::game_camera *)has_passed_filters) != 0) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>((boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v1);
      v22 = 2;
      v15 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v14, (int)&v37);
      vostok::logging::append(
        &v23,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\specified_problem.cpp",
        0x105u,
        "void __thiscall vostok::ai::planning::specified_problem::dump_target_world_state(void) const",
        "ai:",
        info,
        (const char *)v15);
    }
    if ( (v22 & 2) != 0 )
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)(v22 & 2),
        (int *)&v23);
  }
  else
  {
    for ( k = 0;
          k < stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>::size(&this->m_target_world_state._M_impl);
          ++k )
    {
      survarium::weapon_user_dead_state::finalize(v2);
      v34 = (survarium::game_camera *)&this->m_target_world_state._M_impl._M_start[k];
      vostok::buffer_string::append(&v37, *(char **)(LODWORD(v34->m_inverted_view_matrix.j.y) + 28));
      vostok::buffer_string::append(&v37, " (");
      for ( index = 0;
            index < (signed int)(LODWORD(v34->m_inverted_view_matrix.i.x) - (unsigned int)v34->__vftable) >> 2;
            ++index )
      {
        survarium::weapon_user_dead_state::finalize(v34);
        v21 = *vostok::buffer_vector<unsigned int>::operator[]((vostok::buffer_vector<unsigned int> *)v34, index);
        type = *vostok::buffer_vector<unsigned int>::operator[](
                  (vostok::buffer_vector<unsigned int> *)(LODWORD(v34->m_inverted_view_matrix.j.y) + 4),
                  index);
        v32 = vostok::ai::planning::specified_problem::get_object_by_type_and_index(this, type, v21);
        v26 = 0;
        survarium::weapon_user_dead_state::finalize(v3);
        v5 = (char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                       v4,
                       (int)&v32->m_caption);
        vostok::buffer_string::append(&v37, v5);
        if ( index == ((signed int)(LODWORD(v34->m_inverted_view_matrix.i.x) - (unsigned int)v34->__vftable) >> 2) - 1 )
          vostok::buffer_string::append(&v37, ")");
        else
          vostok::buffer_string::append(&v37, (char *)&stru_95AF78.m_key_bindings[32]);
      }
      if ( !((signed int)(LODWORD(v34->m_inverted_view_matrix.i.x) - (unsigned int)v34->__vftable) >> 2) )
        vostok::buffer_string::append(&v37, ")");
      if ( k < stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>::size(&this->m_target_world_state._M_impl)
             - 1 )
        vostok::buffer_string::append(&v37, "\n");
    }
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "ai:", info) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>((boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v2);
      v22 = 1;
      v7 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v6, (int)&v37);
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\specified_problem.cpp",
        0xE5u,
        "void __thiscall vostok::ai::planning::specified_problem::dump_target_world_state(void) const",
        "ai:",
        info,
        (const char *)v7);
    }
    if ( (v22 & 1) != 0 )
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v2,
        (int *)&log_callback);
  }
}
