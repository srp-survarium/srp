void __thiscall vostok::render::skeleton_combined_model_cook::on_resources_loaded(
        vostok::render::skeleton_combined_model_cook *this,
        vostok::resources::queries_result *data,
        vostok::render::skeleton_combined_cook_data *parent,
        vostok::render::skeleton_combined_cook_data *cook_data)
{
  vostok::particle::particle_system_instance_impl *m_object; // esi
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *managed_resource; // eax
  vostok::memory::doug_lea_allocator *v7; // esi
  char *v8; // eax
  vostok::memory::doug_lea_allocator *v9; // ecx
  vostok::memory::doug_lea_allocator *v10; // ecx
  vostok::memory::doug_lea_allocator *v11; // ecx
  char *v12; // eax
  boost::function<void __cdecl(vostok::resources::queries_result &)> *v13; // ecx
  int v14; // esi
  void *v15; // esp
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v16; // eax
  const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *v17; // eax
  vostok::particle::particle_system_instance_impl *v18; // esi
  const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *v19; // eax
  vostok::particle::particle_system_instance_impl *v20; // esi
  vostok::particle::particle_system_instance_impl *v21; // esi
  vostok::particle::particle_system_instance_impl *v22; // esi
  vostok::configs::binary_config_value *v23; // eax
  vostok::configs::binary_config_value *v24; // eax
  char *pointer; // edx
  vostok::buffer_string *v26; // eax
  vostok::particle::particle_system_instance_impl_vtbl *v27; // ecx
  const vostok::configs::binary_config_value *v28; // eax
  vostok::fixed_string<260> *v29; // ecx
  const char **v30; // edi
  char *v31; // eax
  vostok::resources::managed_resource *v32; // eax
  vostok::memory::doug_lea_allocator *v33; // esi
  vostok::particle::particle_system_instance_impl *v34; // edi
  vostok::render::skeleton_combined_cook_data *v35; // ecx
  vostok::render::enum_vertex_input_type v36; // eax
  int v37; // eax
  unsigned int v38; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v39; // ecx
  vostok::memory::doug_lea_allocator *v40; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::skeleton_combined_model_cook,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *,vostok::render::skeleton_combined_cook_data *>,boost::_bi::list4<boost::_bi::value<vostok::render::skeleton_combined_model_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *>,boost::_bi::value<vostok::render::skeleton_combined_cook_data *> > > v41; // [esp-14h] [ebp-1C0h] BYREF
  BOOL v42; // [esp-4h] [ebp-1B0h]
  const char *v43; // [esp+0h] [ebp-1ACh] BYREF
  const char *v44; // [esp+4h] [ebp-1A8h]
  unsigned int v45; // [esp+8h] [ebp-1A4h]
  vostok::fixed_string<260> v46; // [esp+10h] [ebp-19Ch] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::skeleton_combined_model_cook,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *,vostok::render::skeleton_combined_cook_data *>,boost::_bi::list4<boost::_bi::value<vostok::render::skeleton_combined_model_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *>,boost::_bi::value<vostok::render::skeleton_combined_cook_data *> > > f; // [esp+120h] [ebp-8Ch] BYREF
  vostok::configs::binary_config_value v48; // [esp+140h] [ebp-6Ch] BYREF
  vostok::resources::query_result_for_cook *v49; // [esp+15Ch] [ebp-50h]
  vostok::render::skeleton_combined_cook_data *v50; // [esp+160h] [ebp-4Ch]
  vostok::render::skeleton_combined_cook_data *v51; // [esp+164h] [ebp-48h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v52; // [esp+168h] [ebp-44h] BYREF
  vostok::resources::query_result_for_cook *v53; // [esp+16Ch] [ebp-40h]
  unsigned int models_count; // [esp+170h] [ebp-3Ch]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v55; // [esp+174h] [ebp-38h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v56; // [esp+178h] [ebp-34h] BYREF
  char *v57; // [esp+17Ch] [ebp-30h]
  const char **v58; // [esp+180h] [ebp-2Ch]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v59; // [esp+184h] [ebp-28h] BYREF
  unsigned int v60; // [esp+188h] [ebp-24h]
  const vostok::variant<32> **v61; // [esp+18Ch] [ebp-20h]
  int __formal; // [esp+190h] [ebp-1Ch] BYREF
  char *v63; // [esp+194h] [ebp-18h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v64; // [esp+198h] [ebp-14h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v65; // [esp+19Ch] [ebp-10h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v66; // [esp+1A0h] [ebp-Ch] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v67; // [esp+1A4h] [ebp-8h] BYREF
  char *datab; // [esp+1B4h] [ebp+8h]
  int dataa; // [esp+1B4h] [ebp+8h]
  vostok::resources::query_result *v70; // [esp+1BCh] [ebp+10h]
  vostok::resources::query_result *v71; // [esp+1BCh] [ebp+10h]

  v53 = (vostok::resources::query_result_for_cook *)this;
  if ( data->m_result == 1 )
  {
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v65,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
    m_object = (vostok::particle::particle_system_instance_impl *)v65.m_object;
    v67.m_object = 0;
    if ( v65.m_object )
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v67);
      v67.m_object = m_object;
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
    }
    vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
      (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v67,
      (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&cook_data->skeleton);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v67);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v65);
    managed_resource = vostok::resources::query_result_for_user::get_managed_resource(&data->m_queries[1], &v64);
    vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
      managed_resource,
      &cook_data->bind_pose);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v64);
    v7 = vostok::render::g_allocator;
    models_count = cook_data->models_count;
    v8 = type_info::raw_name(&vostok::resources::request `RTTI Type Descriptor');
    v63 = vostok::memory::doug_lea_allocator::malloc_impl(v9, (int)v7, 8 * models_count, v8, v43, v44, v45);
    v65.m_object = (survarium::pure_game_effect_emitter_base *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                                 v10,
                                                                 (int)vostok::render::g_allocator,
                                                                 48 * models_count,
                                                                 "user_data_variant",
                                                                 v43,
                                                                 v44,
                                                                 v45);
    v12 = vostok::memory::doug_lea_allocator::malloc_impl(
            v11,
            (int)vostok::render::g_allocator,
            4 * models_count,
            "user_data_variant_ptrs",
            v43,
            v44,
            v45);
    v14 = cook_data->models_count;
    v61 = (const vostok::variant<32> **)v12;
    v15 = alloca(276 * v14);
    v60 = 0;
    if ( v14 )
    {
      v58 = &v43;
      v64.m_object = (vostok::resources::managed_resource *)v65.m_object;
      v70 = &data->m_queries[2];
      v57 = v63;
      v67.m_object = (vostok::particle::particle_system_instance_impl *)&cook_data->model_defs[0].material_name.m_string.m_end;
      do
      {
        v16 = vostok::resources::query_result_for_user::get_managed_resource(v70, &v52);
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
          v16,
          (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&v67.m_object->m_lods[0].m_distance);
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v52);
        v17 = (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v70[1];
        v71 = v70 + 2;
        vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
          &v55,
          v17 + 55);
        v18 = (vostok::particle::particle_system_instance_impl *)v55.m_object;
        v59.m_object = 0;
        if ( v55.m_object )
        {
          vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v59);
          v59.m_object = v18;
          _InterlockedExchangeAdd(&v18->m_reference_count, 1u);
        }
        vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
          (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v59,
          (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v67.m_object->m_lods[0].m_emitter_instance_list.gap4);
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v59);
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v55);
        v19 = (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)v71;
        v70 = v71 + 1;
        vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
          &v56,
          v19 + 55);
        v20 = (vostok::particle::particle_system_instance_impl *)v56.m_object;
        v66.m_object = 0;
        if ( v56.m_object )
        {
          vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v66);
          v66.m_object = v20;
          _InterlockedExchangeAdd(&v20->m_reference_count, 1u);
        }
        v21 = v67.m_object;
        vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
          (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v66,
          (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v67.m_object->m_lods[0].m_emitter_instance_list.m_first);
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v66);
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v56);
        qmemcpy(
          (void *)&v48,
          *(const void **)(*(_DWORD *)&v21->m_lods[0].m_emitter_instance_list.gap4 + 264),
          sizeof(v48));
        v22 = v67.m_object;
        v66.m_object = (vostok::particle::particle_system_instance_impl *)((char *)v67.m_object - 4);
        if ( (vostok::particle::particle_system_instance_impl_vtbl *)*((_DWORD *)&v67.m_object[-1].m_time_to_finish + 1) == v67.m_object->__vftable )
        {
          datab = (char *)v67.m_object[-1].m_lods[7].m_emitter_instance_list.m_last;
          v23 = vostok::configs::binary_config_value::operator[](&v48, "material_settings");
          v24 = vostok::configs::binary_config_value::operator[](v23, datab);
          pointer = (char *)vostok::configs::binary_config_value::operator[](v24, "material_name")->data.pointer;
          v26 = (vostok::buffer_string *)v66.m_object;
          v27 = v66.m_object->__vftable;
          v22->__vftable = v66.m_object->__vftable;
          LOBYTE(v27->~vostok::particle::particle_system_instance) = 0;
          vostok::buffer_string::operator+=(v26, pointer);
        }
        v28 = vostok::configs::binary_config_value::operator[](
                (vostok::configs::binary_config_value *)LODWORD(v22->m_lods[0].m_emitter_instance_list.m_first->m_second_inverted_transform.c.w),
                "type");
        v30 = v58;
        dataa = LOWORD(v28->data.max_storage);
        if ( v58 )
        {
          vostok::fixed_string<260>::fixed_string<260>(v29, &v46, (char *)v66.m_object->__vftable);
          vostok::fixed_string<260>::fixed_string<260>((vostok::fixed_string<260> *)v30, &v46);
          *((_BYTE *)v30 + 272) = 47;
        }
        v31 = v57;
        *(_DWORD *)v57 = *v30;
        *((_DWORD *)v31 + 1) = 15;
        v32 = v64.m_object;
        if ( v64.m_object )
        {
          v64.m_object->m_children_resources.m_lock = 0;
          v32->m_children_resources.m_thread_id = 0;
        }
        else
        {
          v32 = 0;
        }
        v33 = vostok::render::g_allocator;
        v34 = (vostok::particle::particle_system_instance_impl *)&v61[v60];
        v66.m_object = v34;
        v34->__vftable = (vostok::particle::particle_system_instance_impl_vtbl *)v32;
        __formal = (int)vostok::memory::new_helper<vostok::render::material_effects_instance_cook_data>::call<vostok::memory::doug_lea_allocator>(
                          v33,
                          v43,
                          v44,
                          v45);
        if ( __formal )
        {
          v42 = 1;
          v41.l_.a4_.t_ = v35;
          vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
            (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v41.l_.a4_,
            0);
          v36 = vostok::render::mesh_type_to_vertex_input_type(dataa);
          vostok::render::material_effects_instance_cook_data::material_effects_instance_cook_data(
            v36,
            (vostok::render::material_effects_instance_cook_data *)__formal,
            (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base>)v41.l_.a4_.t_,
            v42,
            (vostok::render::enum_cull_mode)v43);
          v34 = v66.m_object;
          __formal = v37;
        }
        else
        {
          __formal = 0;
        }
        vostok::variant<32>::set<vostok::render::material_effects_instance_cook_data *>(
          (vostok::variant<32> *)v35,
          &v34->~vostok::particle::particle_system_instance,
          (vostok::render::material_effects_instance_cook_data **)&__formal);
        v38 = cook_data->models_count;
        ++v60;
        v67.m_object = (vostok::particle::particle_system_instance_impl *)((char *)v67.m_object + 844);
        v58 += 69;
        v57 += 8;
        v64.m_object = (vostok::resources::managed_resource *)((char *)v64.m_object + 48);
      }
      while ( v60 < v38 );
    }
    v49 = v53;
    v48.id.pointer = (const char *)vostok::render::skeleton_combined_model_cook::on_material_effects_loaded;
    v50 = parent;
    v51 = cook_data;
    HIDWORD(v48.id.max_storage) = v53;
    v48.id_crc = (unsigned int)parent;
    *(_DWORD *)&v48.type = cook_data;
    v41.l_.a1_.t_ = (vostok::render::skeleton_combined_model_cook *)vostok::render::skeleton_combined_model_cook::on_material_effects_loaded;
    v41.l_.a3_.t_ = v53;
    v41.l_.a4_.t_ = parent;
    v41.f_.f_ = (void (__thiscall *)(vostok::render::skeleton_combined_model_cook *, vostok::resources::queries_result *, vostok::resources::query_result_for_cook *, vostok::render::skeleton_combined_cook_data *))&f;
    boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
      v13,
      v41,
      (int)cook_data);
    vostok::resources::query_resources(
      (const vostok::resources::request *)v63,
      models_count,
      vostok::render::g_allocator,
      v61,
      (const vostok::variant<32> **)parent,
      assert_on_fail_true);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v39,
      (int *)&f);
    if ( v61 )
      vostok::memory::doug_lea_allocator::free_impl(v40, (int)vostok::render::g_allocator, (char *)v61, v43, v44, v45);
    if ( v65.m_object )
      vostok::memory::doug_lea_allocator::free_impl(
        v40,
        (int)vostok::render::g_allocator,
        (char *)v65.m_object,
        v43,
        v44,
        v45);
    if ( v63 )
      vostok::memory::doug_lea_allocator::free_impl(v40, (int)vostok::render::g_allocator, v63, v43, v44, v45);
  }
  else
  {
    vostok::resources::check_queries_result(data);
    vostok::resources::query_result_for_cook::finish_query_impl(
      (vostok::resources::query_result_for_cook *)v42,
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)parent,
      result_success,
      assert_on_fail_true,
      result_out_of_memory|0x8);
  }
}
