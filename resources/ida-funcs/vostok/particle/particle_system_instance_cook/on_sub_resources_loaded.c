void __thiscall vostok::particle::particle_system_instance_cook::on_sub_resources_loaded(
        vostok::particle::particle_system_instance_cook *this,
        vostok::resources::queries_result *data)
{
  vostok::memory::base_allocator *m_allocator; // esi
  char *v4; // eax
  vostok::memory::base_allocator *v5; // eax
  vostok::particle::particle_system_instance_impl *v6; // ecx
  unsigned int v7; // edi
  vostok::particle::particle_system_instance_impl *v8; // eax
  survarium::pure_game_effect_emitter_base *m_object; // ebx
  volatile int m_flags; // ecx
  void (__thiscall **p_decrease_quality)(struct survarium::pure_game_effect_emitter_base *, unsigned int); // eax
  volatile int v12; // esi
  void (__thiscall *v13)(struct survarium::pure_game_effect_emitter_base *, unsigned int); // edx
  _BYTE *v14; // ecx
  vostok::memory::base_allocator *v15; // esi
  char *v16; // eax
  survarium::pure_game_effect_emitter_base_vtbl *v17; // eax
  const vostok::variant<32> *const *v18; // ecx
  vostok::particle::particle_emitter *v19; // edi
  int v20; // eax
  int v21; // esi
  const char *v22; // eax
  const char **v23; // edi
  bool v24; // zf
  int v25; // ecx
  void *v26; // esp
  void *v27; // esp
  void *v28; // esp
  vostok::memory::base_allocator *v29; // esi
  char *v30; // eax
  unsigned int v31; // eax
  unsigned int v32; // ecx
  unsigned int v33; // ebx
  vostok::particle::particle_system_instance_impl *v34; // esi
  const vostok::variant<32> *v35; // eax
  vostok::particle::particle_system_instance_impl *v36; // eax
  void *v37; // esp
  vostok::render::enum_cull_mode *v38; // ebx
  const vostok::resources::request *v39; // eax
  const char *v40; // edx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v41; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v42; // [esp-8h] [ebp-194h] BYREF
  vostok::particle::particle_system_instance_impl *v43; // [esp-4h] [ebp-190h]
  vostok::render::enum_cull_mode v44[4]; // [esp+0h] [ebp-18Ch] BYREF
  vostok::fixed_string<260> v45; // [esp+10h] [ebp-17Ch] BYREF
  int v46; // [esp+120h] [ebp-6Ch] BYREF
  _DWORD v47[6]; // [esp+128h] [ebp-64h] BYREF
  _DWORD v48[6]; // [esp+144h] [ebp-48h] BYREF
  unsigned int v49; // [esp+15Ch] [ebp-30h]
  vostok::particle::particle_system_instance_impl *v50; // [esp+160h] [ebp-2Ch]
  vostok::particle::particle_system_instance_cook *v51; // [esp+164h] [ebp-28h]
  const vostok::resources::request *v52; // [esp+168h] [ebp-24h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v53; // [esp+16Ch] [ebp-20h] BYREF
  vostok::particle::particle_system_instance_impl *v54; // [esp+170h] [ebp-1Ch]
  const vostok::variant<32> *const *v55; // [esp+174h] [ebp-18h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v56; // [esp+178h] [ebp-14h] BYREF
  int v57; // [esp+17Ch] [ebp-10h]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *p_m_template; // [esp+180h] [ebp-Ch]
  unsigned int lod_index; // [esp+184h] [ebp-8h]

  v51 = this;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v53,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v53);
  m_allocator = this->m_allocator;
  v4 = type_info::raw_name(&vostok::particle::particle_system_instance_impl `RTTI Type Descriptor');
  v5 = (vostok::memory::base_allocator *)m_allocator->call_malloc(
                                           m_allocator,
                                           784u,
                                           v4,
                                           "vostok::particle::particle_system_instance_cook::on_sub_resources_loaded",
                                           ".\\particle_system_instance_cook.cpp",
                                           45u);
  v7 = 0;
  if ( v5 )
  {
    vostok::particle::particle_system_instance_impl::particle_system_instance_impl(
      v6,
      v5,
      (vostok::memory::base_allocator_vtbl *)this->m_allocator);
    v50 = v8;
  }
  else
  {
    v50 = 0;
  }
  m_object = v53.m_object;
  m_flags = v53.m_object[1].vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
  v49 = 0;
  if ( m_flags )
  {
    p_decrease_quality = &v53.m_object[1].decrease_quality;
    v12 = m_flags;
    do
    {
      v13 = *p_decrease_quality;
      if ( *p_decrease_quality )
      {
        v14 = (char *)*(p_decrease_quality - 2) + 370;
        do
        {
          if ( !*(_DWORD *)(v14 - 42) && *v14 )
            ++v7;
          v14 += 384;
          v13 = (void (__thiscall *)(struct survarium::pure_game_effect_emitter_base *, unsigned int))((char *)v13 - 1);
        }
        while ( v13 );
      }
      p_decrease_quality += 8;
      --v12;
    }
    while ( v12 );
    v49 = v7;
  }
  v15 = v51->m_allocator;
  v16 = type_info::raw_name(&vostok::particle::material_query_data `RTTI Type Descriptor');
  v53.m_object = (survarium::pure_game_effect_emitter_base *)v15->call_malloc(
                                                               v15,
                                                               12 * v7,
                                                               v16,
                                                               "vostok::particle::particle_system_instance_cook::on_sub_resources_loaded",
                                                               ".\\particle_system_instance_cook.cpp",
                                                               61u);
  v57 = (int)v53.m_object;
  lod_index = 0;
  if ( m_object[1].vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags )
  {
    v55 = 0;
    p_m_template = &v50->m_lods[0].m_template;
    do
    {
      vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
        (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v56,
        m_object);
      vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
        (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v56,
        p_m_template);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v56);
      v17 = m_object[1].__vftable;
      v18 = v55;
      v54 = 0;
      if ( *(void (__thiscall **)(struct survarium::pure_game_effect_emitter_base *, unsigned int))((char *)&v17->decrease_quality
                                                                                                  + (_DWORD)v55) )
      {
        v52 = 0;
        do
        {
          v19 = (vostok::particle::particle_emitter *)((char *)v52
                                                     + *(unsigned int *)((char *)&v17->link_child_resource + (_DWORD)v18));
          if ( !v19->m_event.pointer && v19->m_visibility )
          {
            vostok::particle::particle_world::create_emitter_instance(v51->m_allocator, v19, 0);
            v21 = v20;
            v22 = (const char *)v19;
            if ( !v19->m_material_name[0] )
              v22 = "default_particle";
            v23 = (const char **)v57;
            *(_DWORD *)(v57 + 4) = v21;
            *v23 = v22;
            v24 = *(_DWORD *)(v21 + 480) == 0;
            v57 = 1;
            if ( v24 )
            {
              if ( *(_DWORD *)(v21 + 484) )
                v57 = 512;
            }
            else
            {
              v25 = *(_DWORD *)(v21 + 472);
              v57 = 128;
              if ( v25
                && !(*(int (__thiscall **)(int))(*(_DWORD *)v25 + 60))(v25)
                && *(_BYTE *)(*(_DWORD *)(v21 + 472) + 208) )
              {
                v57 = 256;
              }
            }
            v43 = v50;
            v23[2] = (const char *)v57;
            v57 = (int)(v23 + 3);
            vostok::particle::particle_system_instance_impl::add_emitter_instance(
              lod_index,
              (vostok::particle::particle_system_instance_impl *)v21,
              v43);
            v18 = v55;
          }
          v54 = (vostok::particle::particle_system_instance_impl *)((char *)v54 + 1);
          v17 = m_object[1].__vftable;
          v52 += 48;
        }
        while ( (char *)v54 < (char *)*(void (__thiscall **)(struct survarium::pure_game_effect_emitter_base *, unsigned int))((char *)&v17->decrease_quality + (_DWORD)v18) );
      }
      ++lod_index;
      p_m_template += 8;
      v55 = v18 + 8;
    }
    while ( lod_index < m_object[1].vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags );
    v7 = v49;
  }
  v26 = alloca(8 * v7);
  v52 = (const vostok::resources::request *)v44;
  v27 = alloca(48 * v7);
  v56.m_object = (vostok::particle::particle_system_instance_impl *)v44;
  v28 = alloca(4 * v7);
  v29 = v51->m_allocator;
  v55 = (const vostok::variant<32> *const *)v44;
  v30 = type_info::raw_name(&vostok::render::material_effects_instance_cook_data `RTTI Type Descriptor');
  v31 = (unsigned int)v29->call_malloc(
                        v29,
                        16 * v7,
                        v30,
                        "vostok::particle::particle_system_instance_cook::on_sub_resources_loaded",
                        ".\\particle_system_instance_cook.cpp",
                        93u);
  v32 = 0;
  v33 = 0;
  v57 = v31;
  if ( v7 )
  {
    v34 = v56.m_object;
    lod_index = v31;
    v54 = v56.m_object;
    p_m_template = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&v53.m_object->m_flags;
    while ( 1 )
    {
      if ( v34 )
      {
        v34->m_children_resources.m_lock = 0;
        v34->m_children_resources.m_thread_id = 0;
        v35 = (const vostok::variant<32> *)v34;
      }
      else
      {
        v35 = 0;
      }
      v55[v33] = v35;
      if ( lod_index )
      {
        v43 = 0;
        v42.m_object = 0;
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
          &v42,
          0);
        vostok::render::material_effects_instance_cook_data::material_effects_instance_cook_data(
          (vostok::render::enum_vertex_input_type)p_m_template->m_object,
          (vostok::render::material_effects_instance_cook_data *)lod_index,
          v42,
          (bool)v43,
          v44[0]);
        v7 = v49;
        v34 = v54;
        v56.m_object = v36;
      }
      else
      {
        v56.m_object = 0;
      }
      vostok::variant<32>::set<vostok::render::material_effects_instance_cook_data *>(
        (vostok::variant<32> *)(v32 * 8),
        v55[v33]->m_helper_storage,
        (vostok::render::material_effects_instance_cook_data **)&v56);
      lod_index += 16;
      p_m_template += 3;
      ++v33;
      v34 = (vostok::particle::particle_system_instance_impl *)((char *)v34 + 48);
      v54 = v34;
      if ( v33 >= v7 )
        break;
      v32 = 0;
    }
  }
  v37 = alloca(276 * v7);
  lod_index = 0;
  v38 = v44;
  if ( v7 )
  {
    p_m_template = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)v53.m_object;
    do
    {
      if ( v38 )
      {
        vostok::fixed_string<260>::fixed_string<260>(
          (vostok::fixed_string<260> *)(v32 * 8),
          &v45,
          (char *)p_m_template->m_object);
        vostok::fixed_string<260>::fixed_string<260>((vostok::fixed_string<260> *)v38, &v45);
        *((_BYTE *)v38 + 272) = 47;
      }
      v39 = v52;
      p_m_template += 3;
      v32 = lod_index++;
      v52[v32].id = material_effects_instance_class;
      v40 = (const char *)*v38;
      v38 += 69;
      v39[v32].path = v40;
    }
    while ( lod_index < v7 );
  }
  v47[1] = 0;
  v47[0] = vostok::particle::particle_system_instance_cook::on_materials_loaded;
  v47[2] = v51;
  v47[3] = v50;
  v47[4] = v53.m_object;
  v47[5] = v57;
  v43 = (vostok::particle::particle_system_instance_impl *)v48;
  qmemcpy(v48, v47, sizeof(v48));
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    v46 = 0;
  }
  else
  {
    qmemcpy(v47, v48, sizeof(v47));
    v46 = (int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::particle::particle_system_instance_cook,vostok::resources::queries_result &,vostok::particle::particle_system_instance_impl *,vostok::particle::material_query_data *,vostok::render::material_effects_instance_cook_data *>,boost::_bi::list5<boost::_bi::value<vostok::particle::particle_system_instance_cook *>,boost::arg<1>,boost::_bi::value<vostok::particle::particle_system_instance_impl *>,boost::_bi::value<vostok::particle::material_query_data *>,boost::_bi::value<vostok::render::material_effects_instance_cook_data *>>>>'::`2'::stored_vtable
        + 1;
  }
  vostok::resources::query_resources(
    v52,
    v49,
    v51->m_allocator,
    v55,
    (const vostok::variant<32> **)data->m_parent_query,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v41, &v46);
}
