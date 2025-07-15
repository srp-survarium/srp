vostok::ai::planning::goal *__cdecl vostok::ai::create_goal_by_type(
        vostok::ai::planning::goal_types_enum goal_type,
        vostok::configs::binary_config_value *goal_options,
        const vostok::ai::planning::pddl_domain *domain,
        vostok::ai::ai_world *world)
{
  const vostok::configs::binary_config_value *v4; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v5; // ecx
  vostok::memory::doug_lea_allocator *v6; // eax
  vostok::ai::planning::goal *v7; // eax
  survarium::game_camera *v8; // ecx
  vostok::memory::doug_lea_allocator *v9; // eax
  survarium::game_camera *v10; // ecx
  vostok::ai::planning::action_parameter *v11; // eax
  vostok::memory::doug_lea_allocator *v12; // eax
  vostok::ai::planning::action_parameter *v13; // eax
  survarium::game_camera *v14; // ecx
  vostok::memory::doug_lea_allocator *v15; // eax
  vostok::ai::planning::action_parameter *v16; // eax
  survarium::game_camera *v17; // ecx
  vostok::memory::doug_lea_allocator *v18; // eax
  survarium::game_camera *v19; // ecx
  vostok::ai::planning::action_parameter *v20; // eax
  vostok::memory::doug_lea_allocator *v21; // eax
  vostok::ai::planning::action_parameter *v22; // eax
  survarium::game_camera *v23; // ecx
  vostok::memory::doug_lea_allocator *v24; // eax
  survarium::game_camera *v25; // eax
  vostok::memory::doug_lea_allocator *v26; // eax
  vostok::ai::planning::action_parameter *v27; // eax
  survarium::game_camera *v28; // ecx
  vostok::memory::doug_lea_allocator *v29; // eax
  survarium::game_camera *v30; // ecx
  vostok::ai::planning::action_parameter *v31; // eax
  vostok::memory::doug_lea_allocator *v32; // eax
  survarium::game_camera *v33; // ecx
  vostok::ai::planning::action_parameter *v34; // eax
  vostok::memory::doug_lea_allocator *v35; // eax
  vostok::ai::planning::action_parameter *v36; // eax
  survarium::game_camera *v37; // ecx
  vostok::memory::doug_lea_allocator *v38; // eax
  survarium::game_camera *v39; // eax
  vostok::memory::doug_lea_allocator *v40; // eax
  vostok::ai::planning::action_parameter *v41; // eax
  survarium::game_camera *v42; // ecx
  const vostok::configs::binary_config_value *v43; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v44; // ecx
  vostok::configs::binary_config_value *v45; // eax
  vostok::ai::planning::pddl_predicate *v46; // eax
  const vostok::ai::planning::pddl_predicate *v47; // eax
  vostok::buffer_vector<vostok::resources::request> *v48; // ecx
  bool v50; // [esp-8h] [ebp-1E0h]
  vostok::ai::planning::action_parameter *v51; // [esp+0h] [ebp-1D8h]
  survarium::game_camera *v52; // [esp+4h] [ebp-1D4h]
  vostok::ai::planning::action_parameter *v53; // [esp+8h] [ebp-1D0h]
  vostok::ai::planning::action_parameter *v54; // [esp+Ch] [ebp-1CCh]
  vostok::ai::planning::action_parameter *v55; // [esp+10h] [ebp-1C8h]
  vostok::ai::planning::action_parameter *v56; // [esp+14h] [ebp-1C4h]
  survarium::game_camera *v57; // [esp+18h] [ebp-1C0h]
  vostok::ai::planning::action_parameter *v58; // [esp+1Ch] [ebp-1BCh]
  vostok::ai::planning::action_parameter *v59; // [esp+20h] [ebp-1B8h]
  vostok::ai::planning::action_parameter *v60; // [esp+24h] [ebp-1B4h]
  vostok::ai::planning::action_parameter *v61; // [esp+28h] [ebp-1B0h]
  vostok::ai::planning::action_parameter *v62; // [esp+2Ch] [ebp-1ACh]
  vostok::ai::planning::goal *v63; // [esp+30h] [ebp-1A8h]
  int *v64; // [esp+90h] [ebp-148h]
  int *v65; // [esp+98h] [ebp-140h]
  int *v66; // [esp+A0h] [ebp-138h]
  int *v67; // [esp+A8h] [ebp-130h]
  int *v68; // [esp+B0h] [ebp-128h]
  int *v69; // [esp+B8h] [ebp-120h]
  int *v70; // [esp+C0h] [ebp-118h]
  int *v71; // [esp+C8h] [ebp-110h]
  int *v72; // [esp+D0h] [ebp-108h]
  int *v73; // [esp+D8h] [ebp-100h]
  int *v74; // [esp+E0h] [ebp-F8h]
  int *v75; // [esp+E8h] [ebp-F0h]
  int *_Where; // [esp+F0h] [ebp-E8h]
  vostok::variant<32> *v77; // [esp+F8h] [ebp-E0h] BYREF
  vostok::variant<32> *value; // [esp+FCh] [ebp-DCh] BYREF
  char v79; // [esp+103h] [ebp-D5h]
  vostok::ai::planning::action_parameter *v80; // [esp+104h] [ebp-D4h]
  vostok::ai::planning::action_parameter *v81; // [esp+108h] [ebp-D0h]
  vostok::ai::planning::action_parameter *v82; // [esp+10Ch] [ebp-CCh]
  vostok::ai::planning::action_parameter *v83; // [esp+110h] [ebp-C8h]
  vostok::ai::planning::action_parameter *v84; // [esp+114h] [ebp-C4h]
  vostok::ai::planning::action_parameter *v85; // [esp+118h] [ebp-C0h]
  vostok::ai::planning::action_parameter *v86; // [esp+11Ch] [ebp-BCh]
  vostok::ai::planning::action_parameter *v87; // [esp+120h] [ebp-B8h]
  vostok::ai::planning::action_parameter *v88; // [esp+124h] [ebp-B4h]
  vostok::ai::planning::action_parameter *v89; // [esp+128h] [ebp-B0h]
  vostok::ai::planning::action_parameter *v90; // [esp+12Ch] [ebp-ACh]
  vostok::ai::planning::action_parameter *v91; // [esp+130h] [ebp-A8h]
  vostok::ai::planning::goal *v92; // [esp+134h] [ebp-A4h]
  unsigned int index; // [esp+138h] [ebp-A0h]
  const vostok::configs::binary_config_value *it_end_indices; // [esp+13Ch] [ebp-9Ch]
  const vostok::configs::binary_config_value *indices; // [esp+140h] [ebp-98h]
  const vostok::configs::binary_config_value *it_indices; // [esp+144h] [ebp-94h]
  bool property_value; // [esp+14Ah] [ebp-8Eh]
  bool shift_indices; // [esp+14Bh] [ebp-8Dh]
  const vostok::configs::binary_config_value *property; // [esp+14Ch] [ebp-8Ch]
  vostok::fixed_vector<unsigned int,4> parameters_indices; // [esp+150h] [ebp-88h] BYREF
  vostok::ai::predicate_types_enum type; // [esp+168h] [ebp-70h]
  unsigned int property_id; // [esp+16Ch] [ebp-6Ch]
  vostok::ai::planning::action_parameter *v103; // [esp+170h] [ebp-68h]
  vostok::configs::binary_config_value *v104; // [esp+174h] [ebp-64h]
  vostok::ai::planning::action_parameter *v105; // [esp+178h] [ebp-60h]
  vostok::configs::binary_config_value *v106; // [esp+17Ch] [ebp-5Ch]
  vostok::ai::planning::action_parameter *v107; // [esp+180h] [ebp-58h]
  vostok::ai::planning::action_parameter *v108; // [esp+184h] [ebp-54h]
  vostok::configs::binary_config_value *v109; // [esp+188h] [ebp-50h]
  vostok::ai::planning::action_parameter *v110; // [esp+18Ch] [ebp-4Ch]
  vostok::ai::planning::action_parameter *v111; // [esp+190h] [ebp-48h]
  vostok::configs::binary_config_value *v112; // [esp+194h] [ebp-44h]
  vostok::ai::planning::action_parameter *v113; // [esp+198h] [ebp-40h]
  vostok::ai::planning::action_parameter *owner; // [esp+19Ch] [ebp-3Ch]
  vostok::configs::binary_config_value *v115; // [esp+1A0h] [ebp-38h]
  vostok::ai::planning::action_parameter *v116; // [esp+1A4h] [ebp-34h]
  vostok::configs::binary_config_value *options; // [esp+1A8h] [ebp-30h]
  vostok::ai::planning::action_parameter *parameter; // [esp+1ACh] [ebp-2Ch]
  const vostok::configs::binary_config_value *param1_value; // [esp+1B0h] [ebp-28h]
  vostok::ai::planning::action_parameter *param1; // [esp+1B4h] [ebp-24h]
  const vostok::configs::binary_config_value *param0_value; // [esp+1B8h] [ebp-20h]
  vostok::ai::planning::action_parameter *param0; // [esp+1BCh] [ebp-1Ch]
  vostok::ai::planning::goal *result; // [esp+1C0h] [ebp-18h]
  unsigned int priority; // [esp+1C4h] [ebp-14h]
  const char *goal_caption; // [esp+1C8h] [ebp-10h]
  const vostok::configs::binary_config_value *properties; // [esp+1CCh] [ebp-Ch]
  const vostok::configs::binary_config_value *it_end; // [esp+1D0h] [ebp-8h]
  const vostok::configs::binary_config_value *it; // [esp+1D4h] [ebp-4h]

  v4 = vostok::configs::binary_config_value::operator[](goal_options, "priority");
  priority = (unsigned int)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                             v5,
                             (int)v4);
  goal_caption = goals_captions_17[goal_type];
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)goal_caption);
  _Where = vostok::memory::doug_lea_allocator::malloc_impl(v6, 0x98u);
  v92 = (vostok::ai::planning::goal *)operator new(0x98u, _Where);
  if ( v92 )
  {
    vostok::ai::planning::goal::goal(v92, goal_type, priority, goal_caption);
    v63 = v7;
  }
  else
  {
    v63 = 0;
  }
  result = v63;
  if ( goal_type )
  {
    switch ( goal_type )
    {
      case goal_type_blind_fire:
        options = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                            goal_options,
                                                            "parameter0");
        survarium::weapon_user_dead_state::finalize(v14);
        v73 = vostok::memory::doug_lea_allocator::malloc_impl(v15, 0x34u);
        v89 = (vostok::ai::planning::action_parameter *)operator new(0x34u, v73);
        if ( v89 )
        {
          vostok::ai::planning::action_parameter::action_parameter(v89, 2u);
          v60 = v16;
        }
        else
        {
          v60 = 0;
        }
        parameter = v60;
        vostok::ai::behaviour::fill_action_parameter(options, v60);
        vostok::ai::planning::goal::add_parameter(result, v60);
        break;
      case goal_type_play_animation:
        v115 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                         goal_options,
                                                         "parameter0");
        survarium::weapon_user_dead_state::finalize(v17);
        v72 = vostok::memory::doug_lea_allocator::malloc_impl(v18, 0x34u);
        v88 = (vostok::ai::planning::action_parameter *)operator new(0x34u, v72);
        if ( v88 )
        {
          vostok::ai::planning::action_parameter::action_parameter(v88, 0);
          v59 = v20;
        }
        else
        {
          v59 = 0;
        }
        owner = v59;
        survarium::weapon_user_dead_state::finalize(v19);
        v71 = vostok::memory::doug_lea_allocator::malloc_impl(v21, 0x34u);
        v87 = (vostok::ai::planning::action_parameter *)operator new(0x34u, v71);
        if ( v87 )
        {
          vostok::ai::planning::action_parameter::action_parameter(v87, 5u);
          v58 = v22;
        }
        else
        {
          v58 = 0;
        }
        v116 = v58;
        vostok::ai::behaviour::fill_action_parameter(v115, v58);
        vostok::ai::planning::goal::add_parameter(result, owner);
        vostok::ai::planning::goal::add_parameter(result, v58);
        break;
      case goal_type_play_sound:
        v112 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                         goal_options,
                                                         "parameter0");
        survarium::weapon_user_dead_state::finalize(v23);
        v70 = vostok::memory::doug_lea_allocator::malloc_impl(v24, 0x34u);
        v86 = (vostok::ai::planning::action_parameter *)operator new(0x34u, v70);
        if ( v86 )
        {
          vostok::ai::planning::action_parameter::action_parameter(v86, 0);
          v57 = v25;
        }
        else
        {
          v57 = 0;
        }
        v111 = (vostok::ai::planning::action_parameter *)v57;
        survarium::weapon_user_dead_state::finalize(v57);
        v69 = vostok::memory::doug_lea_allocator::malloc_impl(v26, 0x34u);
        v85 = (vostok::ai::planning::action_parameter *)operator new(0x34u, v69);
        if ( v85 )
        {
          vostok::ai::planning::action_parameter::action_parameter(v85, 6u);
          v56 = v27;
        }
        else
        {
          v56 = 0;
        }
        v113 = v56;
        vostok::ai::behaviour::fill_action_parameter(v112, v56);
        vostok::ai::planning::goal::add_parameter(result, v111);
        vostok::ai::planning::goal::add_parameter(result, v56);
        break;
      case goal_type_play_animation_with_sound:
        v109 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                         goal_options,
                                                         "parameter0");
        v106 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                         goal_options,
                                                         "parameter1");
        survarium::weapon_user_dead_state::finalize(v28);
        v68 = vostok::memory::doug_lea_allocator::malloc_impl(v29, 0x34u);
        v84 = (vostok::ai::planning::action_parameter *)operator new(0x34u, v68);
        if ( v84 )
        {
          vostok::ai::planning::action_parameter::action_parameter(v84, 0);
          v55 = v31;
        }
        else
        {
          v55 = 0;
        }
        v107 = v55;
        survarium::weapon_user_dead_state::finalize(v30);
        v67 = vostok::memory::doug_lea_allocator::malloc_impl(v32, 0x34u);
        v83 = (vostok::ai::planning::action_parameter *)operator new(0x34u, v67);
        if ( v83 )
        {
          vostok::ai::planning::action_parameter::action_parameter(v83, 5u);
          v54 = v34;
        }
        else
        {
          v54 = 0;
        }
        v110 = v54;
        survarium::weapon_user_dead_state::finalize(v33);
        v66 = vostok::memory::doug_lea_allocator::malloc_impl(v35, 0x34u);
        v82 = (vostok::ai::planning::action_parameter *)operator new(0x34u, v66);
        if ( v82 )
        {
          vostok::ai::planning::action_parameter::action_parameter(v82, 6u);
          v53 = v36;
        }
        else
        {
          v53 = 0;
        }
        v108 = v53;
        vostok::ai::behaviour::fill_action_parameter(v109, v110);
        vostok::ai::behaviour::fill_action_parameter(v106, v53);
        vostok::ai::planning::goal::add_parameter(result, v107);
        vostok::ai::planning::goal::add_parameter(result, v110);
        vostok::ai::planning::goal::add_parameter(result, v53);
        break;
      case goal_type_move_to_point:
        v104 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                         goal_options,
                                                         "parameter0");
        survarium::weapon_user_dead_state::finalize(v37);
        v65 = vostok::memory::doug_lea_allocator::malloc_impl(v38, 0x34u);
        v81 = (vostok::ai::planning::action_parameter *)operator new(0x34u, v65);
        if ( v81 )
        {
          vostok::ai::planning::action_parameter::action_parameter(v81, 0);
          v52 = v39;
        }
        else
        {
          v52 = 0;
        }
        v103 = (vostok::ai::planning::action_parameter *)v52;
        survarium::weapon_user_dead_state::finalize(v52);
        v64 = vostok::memory::doug_lea_allocator::malloc_impl(v40, 0x34u);
        v80 = (vostok::ai::planning::action_parameter *)operator new(0x34u, v64);
        if ( v80 )
        {
          vostok::ai::planning::action_parameter::action_parameter(v80, 7u);
          v51 = v41;
        }
        else
        {
          v51 = 0;
        }
        v105 = v51;
        vostok::ai::behaviour::fill_action_parameter(v104, v51);
        vostok::ai::planning::goal::add_parameter(result, v103);
        vostok::ai::planning::goal::add_parameter(result, v51);
        break;
    }
  }
  else
  {
    param0_value = vostok::configs::binary_config_value::operator[](goal_options, "parameter0");
    param1_value = vostok::configs::binary_config_value::operator[](goal_options, "parameter1");
    survarium::weapon_user_dead_state::finalize(v8);
    v75 = vostok::memory::doug_lea_allocator::malloc_impl(v9, 0x34u);
    v91 = (vostok::ai::planning::action_parameter *)operator new(0x34u, v75);
    if ( v91 )
    {
      vostok::ai::planning::action_parameter::action_parameter(v91, 1u);
      v62 = v11;
    }
    else
    {
      v62 = 0;
    }
    param0 = v62;
    survarium::weapon_user_dead_state::finalize(v10);
    v74 = vostok::memory::doug_lea_allocator::malloc_impl(v12, 0x34u);
    v90 = (vostok::ai::planning::action_parameter *)operator new(0x34u, v74);
    if ( v90 )
    {
      vostok::ai::planning::action_parameter::action_parameter(v90, 2u);
      v61 = v13;
    }
    else
    {
      v61 = 0;
    }
    param1 = v61;
    vostok::ai::behaviour::fill_action_parameter(param0_value, param0);
    vostok::ai::behaviour::fill_action_parameter(param1_value, v61);
    vostok::ai::planning::goal::add_parameter(result, param0);
    vostok::ai::planning::goal::add_parameter(result, v61);
  }
  vostok::ai::behaviour::fill_goal_filter_sets(goal_options, world, result);
  v79 = 0;
  survarium::weapon_user_dead_state::finalize(v42);
  properties = vostok::configs::binary_config_value::operator[](goal_options, "target_world_state_properties");
  it = (const vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)properties);
  it_end = vostok::configs::binary_config_value::end((vostok::configs::binary_config_value *)properties);
  while ( it != it_end )
  {
    property = it;
    v43 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)it, "property_id");
    property_id = (unsigned int)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                  v44,
                                  (int)v43);
    type = property_id;
    v45 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                    (vostok::configs::binary_config_value *)property,
                                                    (const char *)&stru_955964);
    property_value = vostok::configs::binary_config_value::operator bool(v45);
    v46 = vostok::ai::planning::pddl_domain::operator[](domain, type);
    shift_indices = vostok::ai::planning::pddl_predicate::has_owner_parameter(v46);
    vostok::buffer_vector<unsigned int>::buffer_vector<unsigned int>(
      &parameters_indices,
      (unsigned int *)parameters_indices.m_buffer,
      4u,
      0);
    if ( vostok::configs::binary_config_value::value_exists(
           (vostok::configs::binary_config_value *)property,
           "parameters_indices") )
    {
      if ( shift_indices )
      {
        value = 0;
        vostok::buffer_vector<unsigned int>::push_back(
          (vostok::buffer_vector<vostok::variant<32> const *> *)&parameters_indices,
          (const vostok::variant<32> **)&value);
      }
      indices = vostok::configs::binary_config_value::operator[](
                  (vostok::configs::binary_config_value *)property,
                  "parameters_indices");
      it_indices = (const vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)indices);
      it_end_indices = vostok::configs::binary_config_value::end((vostok::configs::binary_config_value *)indices);
      while ( it_indices != it_end_indices )
      {
        index = (unsigned int)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)it_indices,
                                (int)it_indices);
        v77 = (vostok::variant<32> *)(index + shift_indices);
        vostok::buffer_vector<unsigned int>::push_back(
          (vostok::buffer_vector<vostok::variant<32> const *> *)&parameters_indices,
          (const vostok::variant<32> **)&v77);
        ++it_indices;
      }
    }
    v50 = property_value;
    v47 = vostok::ai::planning::pddl_domain::operator[](domain, type);
    vostok::ai::planning::goal::add_target_property(result, v47, v50, &parameters_indices);
    vostok::buffer_vector<unsigned int>::~buffer_vector<unsigned int>(v48, &parameters_indices);
    ++it;
  }
  return result;
}
