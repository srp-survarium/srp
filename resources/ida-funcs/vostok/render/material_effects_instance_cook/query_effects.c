void __thiscall vostok::render::material_effects_instance_cook::query_effects(
        vostok::render::material_effects_instance_cook *this,
        vostok::render::material_effects_instance_cook *parent,
        vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *cook_data,
        int a2)
{
  vostok::resources::creation_request *v4; // ecx
  vostok::particle::particle_system_instance_impl *v5; // esi
  vostok::configs::binary_config_value *v6; // ebx
  vostok::configs::binary_config_value *v7; // ecx
  vostok::resources::query_result_for_cook *v8; // ecx
  vostok::configs::binary_config_value *v9; // ebx
  vostok::configs::binary_config_value *v10; // ecx
  vostok::configs::binary_config_value *v11; // ecx
  vostok::configs::binary_config_value *v12; // eax
  vostok::configs::binary_config_value *v13; // ecx
  vostok::configs::binary_config_value *v14; // eax
  vostok::configs::binary_config_value *v15; // ecx
  vostok::configs::binary_config_value *v16; // eax
  vostok::configs::binary_config_value *v17; // eax
  vostok::resources::creation_request *v18; // eax
  vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *v19; // edi
  vostok::configs::binary_config_value *v20; // ecx
  const vostok::configs::binary_config_value *v21; // eax
  vostok::configs::binary_config_value *v22; // ecx
  vostok::configs::binary_config_value *v23; // eax
  vostok::configs::binary_config_value *v24; // eax
  bool v25; // zf
  vostok::configs::binary_config_value *v26; // ecx
  const vostok::configs::binary_config_value *v27; // eax
  vostok::configs::binary_config_value *v28; // ecx
  vostok::configs::binary_config_value *v29; // eax
  vostok::configs::binary_config_value *v30; // eax
  vostok::configs::binary_config_value *v31; // ecx
  const vostok::configs::binary_config_value *v32; // eax
  vostok::configs::binary_config_value *v33; // ecx
  vostok::configs::binary_config_value *v34; // eax
  vostok::configs::binary_config_value *v35; // eax
  vostok::configs::binary_config_value *v36; // ecx
  const vostok::configs::binary_config_value *v37; // eax
  vostok::configs::binary_config_value *v38; // ecx
  vostok::configs::binary_config_value *v39; // eax
  vostok::configs::binary_config_value *v40; // eax
  const vostok::configs::binary_config_value *v41; // eax
  vostok::configs::binary_config_value *v42; // ecx
  vostok::configs::binary_config_value *v43; // eax
  const vostok::configs::binary_config_value *v44; // eax
  vostok::configs::binary_config_value *v45; // ecx
  vostok::configs::binary_config_value *v46; // eax
  vostok::configs::binary_config_value *v47; // eax
  vostok::configs::binary_config_value *v48; // eax
  unsigned int v49; // ecx
  unsigned int *v50; // edx
  int v51; // ebx
  unsigned int i; // esi
  const char *v53; // eax
  vostok::configs::binary_config_value *v54; // ecx
  unsigned int v55; // ebx
  vostok::memory::doug_lea_allocator *v56; // esi
  char *v57; // eax
  vostok::memory::doug_lea_allocator *v58; // ecx
  vostok::render::material_effects_instance *v59; // ecx
  survarium::pure_game_effect_emitter_base *v60; // eax
  vostok::resources::query_result_for_cook *v61; // ecx
  void *v62; // esp
  void *v63; // esp
  void *v64; // esp
  void *v65; // esp
  unsigned int v66; // eax
  const char **v67; // ecx
  const char *v68; // edx
  vostok::command_line::key *v69; // ecx
  int v70; // edi
  int v71; // eax
  unsigned int v72; // esi
  vostok::render::material_effects_instance_cook *v73; // ecx
  bool is_set; // al
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v75; // ecx
  vostok::variant<32> *v76; // ecx
  vostok::particle::particle_system_instance_impl *m_object; // edi
  int v78; // esi
  _BYTE v79[28]; // [esp-1Ch] [ebp-C0h] BYREF
  const char *v80; // [esp+0h] [ebp-A4h] BYREF
  const char *v81; // [esp+4h] [ebp-A0h]
  unsigned int v82; // [esp+8h] [ebp-9Ch]
  _DWORD type[6]; // [esp+10h] [ebp-94h]
  boost::_bi::bind_t<void,boost::_mfi::mf5<void,vostok::render::material_effects_instance_cook,vostok::resources::queries_result &,vostok::render::material_effects_instance_cook_data *,unsigned int *,unsigned int *,unsigned int>,boost::_bi::list6<boost::_bi::value<vostok::render::material_effects_instance_cook *>,boost::arg<1>,boost::_bi::value<vostok::render::material_effects_instance_cook_data *>,boost::_bi::value<unsigned int *>,boost::_bi::value<unsigned int *>,boost::_bi::value<unsigned int> > > f; // [esp+28h] [ebp-7Ch] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf5<void,vostok::render::material_effects_instance_cook,vostok::resources::queries_result &,vostok::render::material_effects_instance_cook_data *,unsigned int *,unsigned int *,unsigned int>,boost::_bi::list6<boost::_bi::value<vostok::render::material_effects_instance_cook *>,boost::arg<1>,boost::_bi::value<vostok::render::material_effects_instance_cook_data *>,boost::_bi::value<unsigned int *>,boost::_bi::value<unsigned int *>,boost::_bi::value<unsigned int> > > v85; // [esp+54h] [ebp-50h] BYREF
  vostok::fs_new::virtual_path_string *pathes; // [esp+6Ch] [ebp-38h]
  unsigned int data_index; // [esp+70h] [ebp-34h] BYREF
  unsigned int *exists_vertex_inputs; // [esp+74h] [ebp-30h]
  unsigned int *exists_stages; // [esp+78h] [ebp-2Ch]
  vostok::particle::particle_emitter_instance **p_m_first; // [esp+7Ch] [ebp-28h]
  int v91; // [esp+80h] [ebp-24h]
  vostok::resources::creation_request *requests; // [esp+84h] [ebp-20h]
  unsigned int *a5; // [esp+88h] [ebp-1Ch]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v94; // [esp+8Ch] [ebp-18h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v95; // [esp+90h] [ebp-14h] BYREF
  bool v96; // [esp+94h] [ebp-10h]
  bool v97; // [esp+95h] [ebp-Fh]
  bool v98; // [esp+96h] [ebp-Eh]
  bool v99; // [esp+97h] [ebp-Dh]
  const vostok::configs::binary_config_value *root_config; // [esp+98h] [ebp-Ch]
  char v101; // [esp+9Eh] [ebp-6h]
  bool v102; // [esp+9Fh] [ebp-5h]

  v4 = *(vostok::resources::creation_request **)a2;
  v95.m_object = 0;
  v5 = *(vostok::particle::particle_system_instance_impl **)(a2 + 4);
  requests = v4;
  if ( v5 )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v95);
    v95.m_object = v5;
    _InterlockedExchangeAdd(&v5->m_reference_count, 1u);
  }
  p_m_first = &v95.m_object->m_lods[4].m_emitter_instance_list.m_first;
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v94,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v95.m_object->m_lods[4].m_emitter_instance_list.m_first);
  root_config = vostok::configs::binary_config_value::operator[](
                  (vostok::configs::binary_config_value *)v94.m_object->m_lods[0].m_template.m_object,
                  "material");
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v94);
  v102 = 0;
  v99 = 0;
  v101 = 0;
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v94,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)p_m_first);
  v6 = vostok::configs::binary_config_value::operator[](
         (vostok::configs::binary_config_value *)v94.m_object->m_lods[0].m_template.m_object,
         "material");
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v94);
  if ( vostok::configs::binary_config_value::value_exists(v7, (int)v6, (unsigned int)"g_stage") )
  {
    v9 = vostok::configs::binary_config_value::operator[](v6, "g_stage");
    if ( vostok::configs::binary_config_value::value_exists(v10, (int)v9, (unsigned int)"with_vegetation") )
    {
      v12 = vostok::configs::binary_config_value::operator[](v9, "with_vegetation");
      v96 = vostok::configs::binary_config_value::operator[](v12, "value")->data.pointer != 0;
    }
    else
    {
      v96 = 0;
    }
    if ( vostok::configs::binary_config_value::value_exists(v11, (int)v9, (unsigned int)"with_skeletal_meshes") )
    {
      v14 = vostok::configs::binary_config_value::operator[](v9, "with_skeletal_meshes");
      v97 = vostok::configs::binary_config_value::operator[](v14, "value")->data.pointer != 0;
    }
    else
    {
      v97 = 0;
    }
    if ( vostok::configs::binary_config_value::value_exists(
           v13,
           (int)v9,
           (unsigned int)"with_static_vertex_color_meshes") )
    {
      v16 = vostok::configs::binary_config_value::operator[](v9, "with_static_vertex_color_meshes");
      v98 = vostok::configs::binary_config_value::operator[](v16, "value")->data.pointer != 0;
    }
    else
    {
      v98 = 0;
    }
    if ( vostok::configs::binary_config_value::value_exists(v15, (int)v9, (unsigned int)"with_particles") )
    {
      v17 = vostok::configs::binary_config_value::operator[](v9, "with_particles");
      LOBYTE(v8) = vostok::configs::binary_config_value::operator[](v17, "value")->data.pointer != 0;
    }
    else
    {
      LOBYTE(v8) = 0;
    }
    if ( (v18 = *(vostok::resources::creation_request **)a2, (*(_DWORD *)a2 & 4) != 0) && !v98
      || ((unsigned __int8)v18 & 0x78) != 0 && !v97
      || ((unsigned __int16)v18 & 0x800) != 0 && !v96
      || ((char)v18 < 0 || ((unsigned __int16)v18 & 0x300) != 0) && !(_BYTE)v8 )
    {
      v19 = cook_data;
      *(_DWORD *)&v79[24] = 11;
      *(_DWORD *)&v79[20] = 0;
      *(_DWORD *)&v79[16] = 1;
LABEL_19:
      vostok::resources::query_result_for_cook::finish_query_impl(
        v8,
        v19,
        *(vostok::resources::cook_base::result_enum *)&v79[16],
        *(const assert_on_fail_bool *)&v79[20],
        *(vostok::resources::cook_base::result_enum *)&v79[24]);
      goto LABEL_82;
    }
  }
  if ( vostok::configs::binary_config_value::value_exists(
         (vostok::configs::binary_config_value *)v8,
         (int)root_config,
         (unsigned int)"lighting") )
  {
    v21 = vostok::configs::binary_config_value::operator[](root_config, "lighting");
    if ( vostok::configs::binary_config_value::value_exists(v22, (int)v21, (unsigned int)"two_sided") )
    {
      v23 = vostok::configs::binary_config_value::operator[](root_config, "lighting");
      v24 = vostok::configs::binary_config_value::operator[](v23, "two_sided");
      v25 = vostok::configs::binary_config_value::operator[](v24, "value")->data.pointer == 0;
      v101 = 1;
      v102 = !v25;
    }
  }
  if ( vostok::configs::binary_config_value::value_exists(v20, (int)root_config, (unsigned int)"forward") )
  {
    v27 = vostok::configs::binary_config_value::operator[](root_config, "forward");
    if ( vostok::configs::binary_config_value::value_exists(v28, (int)v27, (unsigned int)"two_sided") )
    {
      v29 = vostok::configs::binary_config_value::operator[](root_config, "forward");
      v30 = vostok::configs::binary_config_value::operator[](v29, "two_sided");
      v25 = vostok::configs::binary_config_value::operator[](v30, "value")->data.pointer == 0;
      v101 = 1;
      v102 = !v25;
    }
  }
  if ( vostok::configs::binary_config_value::value_exists(v26, (int)root_config, (unsigned int)"forward") )
  {
    v32 = vostok::configs::binary_config_value::operator[](root_config, "forward");
    if ( vostok::configs::binary_config_value::value_exists(v33, (int)v32, (unsigned int)"draw_to_gbuffer") )
    {
      v34 = vostok::configs::binary_config_value::operator[](root_config, "forward");
      v35 = vostok::configs::binary_config_value::operator[](v34, "draw_to_gbuffer");
      v99 = vostok::configs::binary_config_value::operator[](v35, "value")->data.pointer != 0;
    }
  }
  if ( vostok::configs::binary_config_value::value_exists(v31, (int)root_config, (unsigned int)"distortion") )
  {
    v37 = vostok::configs::binary_config_value::operator[](root_config, "distortion");
    if ( vostok::configs::binary_config_value::value_exists(v38, (int)v37, (unsigned int)"two_sided") )
    {
      v39 = vostok::configs::binary_config_value::operator[](root_config, "distortion");
      v40 = vostok::configs::binary_config_value::operator[](v39, "two_sided");
      v25 = vostok::configs::binary_config_value::operator[](v40, "value")->data.pointer == 0;
      v101 = 1;
      v102 = !v25;
    }
  }
  if ( vostok::configs::binary_config_value::value_exists(v36, (int)root_config, (unsigned int)"g_stage") )
  {
    v41 = vostok::configs::binary_config_value::operator[](root_config, "g_stage");
    if ( vostok::configs::binary_config_value::value_exists(v42, (int)v41, (unsigned int)"effect") )
    {
      v43 = vostok::configs::binary_config_value::operator[](root_config, "g_stage");
      v44 = vostok::configs::binary_config_value::operator[](v43, "effect");
      if ( vostok::configs::binary_config_value::value_exists(v45, (int)v44, (unsigned int)"two_sided") )
      {
        v46 = vostok::configs::binary_config_value::operator[](root_config, "g_stage");
        v47 = vostok::configs::binary_config_value::operator[](v46, "effect");
        v48 = vostok::configs::binary_config_value::operator[](v47, "two_sided");
        v25 = vostok::configs::binary_config_value::operator[](v48, "value")->data.pointer == 0;
        v101 = 1;
        v102 = !v25;
      }
    }
  }
  v49 = 0;
  a5 = 0;
  do
  {
    if ( ((1 << v49) & (unsigned int)requests) != 0 )
    {
      v50 = a5;
      a5 = (unsigned int *)((char *)a5 + 1);
      type[(_DWORD)v50] = 1 << v49;
    }
    ++v49;
  }
  while ( v49 < 0xF );
  v51 = 0;
  for ( i = 0; i < 0x1C; ++i )
  {
    if ( vostok::render::is_material_stages_index(i) )
    {
      v53 = vostok::render::stage_type_to_string(i);
      if ( v53 )
      {
        if ( vostok::configs::binary_config_value::value_exists(v54, (int)root_config, (unsigned int)v53) )
        {
          if ( i == 1 )
            ++v51;
          ++v51;
        }
      }
    }
  }
  v55 = (_DWORD)a5 * v51;
  if ( !v55 )
  {
    v56 = vostok::render::g_allocator;
    v57 = type_info::raw_name(&vostok::render::material_effects_instance `RTTI Type Descriptor');
    if ( vostok::memory::doug_lea_allocator::malloc_impl(v58, (int)v56, 0x228u, v57, v80, v81, v82) )
      vostok::render::material_effects_instance::material_effects_instance(v59, 0);
    else
      v60 = 0;
    *(_DWORD *)&v79[24] = 552;
    *(_DWORD *)&v79[20] = &vostok::resources::nocache_memory;
    *(_DWORD *)&v79[16] = v59;
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v79[16],
      v60);
    v19 = cook_data;
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      v61,
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)cook_data,
      *(vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v79[16],
      *(const vostok::resources::memory_type **)&v79[20],
      *(unsigned int *)&v79[24]);
    *(_DWORD *)&v79[24] = 0;
    *(_DWORD *)&v79[20] = 1;
    *(_DWORD *)&v79[16] = 3;
    goto LABEL_19;
  }
  v62 = alloca(48 * v55);
  v94.m_object = (vostok::particle::particle_system_instance_impl *)&v80;
  v63 = alloca(4 * v55);
  p_m_first = (vostok::particle::particle_emitter_instance **)&v80;
  v64 = alloca(276 * v55);
  pathes = (vostok::fs_new::virtual_path_string *)&v80;
  v65 = alloca(16 * v55);
  v66 = 0;
  requests = (vostok::resources::creation_request *)&v80;
  v67 = &v80;
  do
  {
    if ( v67 )
    {
      v67[10] = 0;
      v67[11] = 0;
      v68 = (const char *)v67;
    }
    else
    {
      v68 = 0;
    }
    (&v80)[v66++] = v68;
    v67 += 12;
  }
  while ( v66 < v55 );
  exists_stages = vostok::memory::new_array_helper<unsigned int>::call<vostok::memory::doug_lea_allocator>(
                    vostok::render::g_allocator,
                    v55,
                    v80,
                    v81,
                    v82);
  exists_vertex_inputs = vostok::memory::new_array_helper<unsigned int>::call<vostok::memory::doug_lea_allocator>(
                           vostok::render::g_allocator,
                           v55,
                           v80,
                           v81,
                           v82);
  v69 = *(vostok::command_line::key **)&v79[24];
  data_index = 0;
  v91 = 0;
  if ( a5 )
  {
    while ( 1 )
    {
      v70 = 1;
      if ( v101 )
        break;
      v71 = *(_DWORD *)(a2 + 8);
      if ( v71 != -1 )
      {
        if ( !v71 )
        {
LABEL_75:
          v70 = 1;
          goto LABEL_76;
        }
        if ( v71 == 1 )
          *(_DWORD *)&v79[24] = 2;
        else
LABEL_72:
          *(_DWORD *)&v79[24] = 3;
        v70 = *(_DWORD *)&v79[24];
      }
LABEL_76:
      v72 = type[v91];
      v85.l_.a3_.t_ = (vostok::render::material_effects_instance_cook_data *)vostok::render::vertex_input_type_to_index(v72);
      v85.l_.a5_.t_ = (unsigned int *)v99;
      v85.l_.a6_.t_ = -1;
      v85.l_.a4_.t_ = (unsigned int *)v70;
      vostok::render::material_effects_instance_cook::gather_request_user_data(
        v73,
        requests,
        pathes,
        exists_stages,
        exists_vertex_inputs,
        v72,
        (vostok::variant<32> *)v94.m_object,
        root_config,
        (vostok::render::effect_compile_data *)&v95,
        (const vostok::render::surface_effect_parameters *)&v85.l_.a3_,
        &data_index);
      if ( ++v91 >= (unsigned int)a5 )
        goto LABEL_77;
    }
    if ( (v102 ? 0 : 2) == 0 )
      goto LABEL_75;
    goto LABEL_72;
  }
LABEL_77:
  is_set = vostok::command_line::key::is_set(v69, (int)&s_sync_effects_creation_key);
  *(_DWORD *)&v79[24] = a5;
  *(_DWORD *)&v79[20] = exists_vertex_inputs;
  *(_DWORD *)&v79[16] = exists_stages;
  *(_DWORD *)&v79[12] = a2;
  *(_DWORD *)&v79[8] = (unsigned __int8)1_64;
  *(_DWORD *)v79 = &f;
  if ( is_set )
  {
    qmemcpy(
      &v79[4],
      boost::bind<void,vostok::render::material_effects_instance_cook,vostok::resources::queries_result &,vostok::render::material_effects_instance_cook_data *,unsigned int *,unsigned int *,unsigned int,vostok::render::material_effects_instance_cook *,boost::arg<1>,vostok::render::material_effects_instance_cook_data *,unsigned int *,unsigned int *,unsigned int>(
        parent,
        &v85,
        *(void (__thiscall **)(vostok::render::material_effects_instance_cook *, vostok::resources::queries_result *, vostok::render::material_effects_instance_cook_data *, unsigned int *, unsigned int *, unsigned int))&v79[8],
        *(int *)&v79[12],
        *(vostok::render::material_effects_instance_cook_data **)&v79[16],
        *(unsigned int **)&v79[20],
        *(unsigned int **)&v79[24]),
      0x18u);
    boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
      0,
      *(boost::_bi::bind_t<void,boost::_mfi::mf5<void,vostok::render::material_effects_instance_cook,vostok::resources::queries_result &,vostok::render::material_effects_instance_cook_data *,unsigned int *,unsigned int *,unsigned int>,boost::_bi::list6<boost::_bi::value<vostok::render::material_effects_instance_cook *>,boost::arg<1>,boost::_bi::value<vostok::render::material_effects_instance_cook_data *>,boost::_bi::value<unsigned int *>,boost::_bi::value<unsigned int *>,boost::_bi::value<unsigned int> > > *)v79,
      *(int *)&v79[24]);
    vostok::resources::query_create_resources_and_wait(
      requests,
      v55,
      vostok::render::g_allocator,
      (const vostok::variant<32> *const *)p_m_first,
      (const vostok::variant<32> **)cook_data);
  }
  else
  {
    qmemcpy(
      &v79[4],
      boost::bind<void,vostok::render::material_effects_instance_cook,vostok::resources::queries_result &,vostok::render::material_effects_instance_cook_data *,unsigned int *,unsigned int *,unsigned int,vostok::render::material_effects_instance_cook *,boost::arg<1>,vostok::render::material_effects_instance_cook_data *,unsigned int *,unsigned int *,unsigned int>(
        parent,
        &v85,
        *(void (__thiscall **)(vostok::render::material_effects_instance_cook *, vostok::resources::queries_result *, vostok::render::material_effects_instance_cook_data *, unsigned int *, unsigned int *, unsigned int))&v79[8],
        *(int *)&v79[12],
        *(vostok::render::material_effects_instance_cook_data **)&v79[16],
        *(unsigned int **)&v79[20],
        *(unsigned int **)&v79[24]),
      0x18u);
    boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
      0,
      *(boost::_bi::bind_t<void,boost::_mfi::mf5<void,vostok::render::material_effects_instance_cook,vostok::resources::queries_result &,vostok::render::material_effects_instance_cook_data *,unsigned int *,unsigned int *,unsigned int>,boost::_bi::list6<boost::_bi::value<vostok::render::material_effects_instance_cook *>,boost::arg<1>,boost::_bi::value<vostok::render::material_effects_instance_cook_data *>,boost::_bi::value<unsigned int *>,boost::_bi::value<unsigned int *>,boost::_bi::value<unsigned int> > > *)v79,
      *(int *)&v79[24]);
    vostok::resources::query_create_resources(
      requests,
      v55,
      vostok::render::g_allocator,
      (const vostok::variant<32> *const *)p_m_first,
      (const vostok::variant<32> **)cook_data);
  }
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v75,
    (int *)&f);
  m_object = v94.m_object;
  do
  {
    v78 = (int)m_object;
    m_object = (vostok::particle::particle_system_instance_impl *)((char *)m_object + 48);
    vostok::variant<32>::destroy_previous_variable_if_needed(v76, v78);
    --v55;
  }
  while ( v55 );
LABEL_82:
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v95);
}
