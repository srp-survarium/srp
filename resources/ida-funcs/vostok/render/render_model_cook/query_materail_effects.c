void __thiscall vostok::render::render_model_cook::query_materail_effects(
        vostok::render::render_model_cook *this,
        vostok::render::cook_intermediate_data *cook_data,
        vostok::render::cook_intermediate_data *pointer)
{
  vostok::render::cook_intermediate_data *v3; // esi
  vostok::memory::doug_lea_allocator *v4; // ecx
  unsigned int m_num_render_models; // ebx
  void *v6; // esp
  void *v7; // esp
  void *v8; // esp
  void *v9; // esp
  vostok::buffer_string *v10; // ebx
  bool v11; // zf
  unsigned int material_index; // eax
  vostok::fs_new::virtual_path_string *v13; // ecx
  vostok::particle::particle_system_instance_impl *m_object; // esi
  survarium::pure_game_effect_emitter_base **v15; // eax
  survarium::pure_game_effect_emitter_base *v16; // ecx
  vostok::particle::particle_system_instance_impl *v17; // eax
  vostok::buffer_string *v18; // ecx
  vostok::fixed_string<260> *v19; // ecx
  char *m_begin; // eax
  char *v21; // eax
  char *m_end; // edx
  const vostok::resources::request *v23; // eax
  unsigned int v24; // ecx
  const vostok::variant<32> *v25; // eax
  vostok::memory::doug_lea_allocator *v26; // esi
  const vostok::variant<32> **v27; // edi
  vostok::render::cook_intermediate_data *v28; // ecx
  vostok::render::enum_vertex_input_type v29; // eax
  int v30; // eax
  unsigned int v31; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v32; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::render_model_cook,vostok::resources::queries_result &,vostok::render::cook_intermediate_data *>,boost::_bi::list3<boost::_bi::value<vostok::render::render_model_cook *>,boost::arg<1>,boost::_bi::value<vostok::render::cook_intermediate_data *> > > v33; // [esp-10h] [ebp-190h] BYREF
  BOOL v34; // [esp-4h] [ebp-184h]
  const char *v35; // [esp+0h] [ebp-180h] BYREF
  const char *v36; // [esp+4h] [ebp-17Ch]
  unsigned int v37; // [esp+8h] [ebp-178h]
  vostok::fixed_string<260> v38; // [esp+Ch] [ebp-174h] BYREF
  char v39; // [esp+11Ch] [ebp-64h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::render_model_cook,vostok::resources::queries_result &,vostok::render::cook_intermediate_data *>,boost::_bi::list3<boost::_bi::value<vostok::render::render_model_cook *>,boost::arg<1>,boost::_bi::value<vostok::render::cook_intermediate_data *> > > f; // [esp+120h] [ebp-60h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v41; // [esp+140h] [ebp-40h] BYREF
  unsigned int v42; // [esp+144h] [ebp-3Ch]
  void (__thiscall *v43)(vostok::render::render_model_cook *, vostok::resources::queries_result *, vostok::render::cook_intermediate_data *); // [esp+148h] [ebp-38h]
  vostok::render::cook_intermediate_data *v44; // [esp+14Ch] [ebp-34h]
  const vostok::variant<32> **v45; // [esp+150h] [ebp-30h]
  const vostok::resources::request *v46; // [esp+158h] [ebp-28h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v47; // [esp+15Ch] [ebp-24h] BYREF
  const vostok::variant<32> *const *v48; // [esp+160h] [ebp-20h]
  int v49; // [esp+164h] [ebp-1Ch]
  vostok::render::cook_intermediate_data *v50; // [esp+168h] [ebp-18h]
  survarium::pure_game_effect_emitter_base *object; // [esp+16Ch] [ebp-14h] BYREF
  unsigned int v52; // [esp+170h] [ebp-10h]
  int __formal; // [esp+174h] [ebp-Ch] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v54; // [esp+178h] [ebp-8h] BYREF

  v3 = pointer;
  if ( pointer->status_failed )
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      (vostok::resources::query_result_for_cook *)this,
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)pointer->parent_query,
      result_success,
      assert_on_fail_true,
      result_out_of_memory|0x8);
    if ( v3->assets )
      vostok::memory::delete_array_helper<vostok::memory::doug_lea_allocator,vostok::render::model_asset>(
        &v3->assets,
        v4,
        vostok::render::g_allocator);
    vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::cook_intermediate_data>(
      vostok::render::g_allocator,
      &pointer,
      v35,
      v36,
      v37);
  }
  else
  {
    m_num_render_models = pointer->m_num_render_models;
    v42 = m_num_render_models;
    v6 = alloca(276 * m_num_render_models);
    v7 = alloca(8 * m_num_render_models);
    v46 = (const vostok::resources::request *)&v35;
    v8 = alloca(48 * m_num_render_models);
    __formal = (int)&v35;
    v9 = alloca(4 * m_num_render_models);
    v52 = 0;
    v48 = (const vostok::variant<32> *const *)&v35;
    if ( m_num_render_models )
    {
      v50 = 0;
      v49 = __formal;
      v10 = (vostok::buffer_string *)&v35;
      do
      {
        __formal = (unsigned __int16)vostok::configs::binary_config_value::operator[](
                                       (*(vostok::configs::binary_config_value ***)((char *)&v50->root_model_path.m_string.m_max_end
                                                                                  + (unsigned int)v3->assets))[66],
                                       "type")->data.pointer;
        v11 = cook_data->root_model_path.m_string.m_max_end == (char *)26;
        v44 = 0;
        if ( v11 )
          __formal = 200;
        material_index = vostok::render::cook_intermediate_data::find_material_index(
                           v50,
                           (int)v3,
                           *(char **)&v50->root_model_path.m_string.m_buffer[(unsigned int)v3->assets]);
        object = 0;
        if ( material_index != -1 )
        {
          m_object = (vostok::particle::particle_system_instance_impl *)v3->assets[material_index].material.m_object;
          v54.m_object = 0;
          if ( m_object )
          {
            vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v54);
            v54.m_object = m_object;
            _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
          }
          vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
            &v41,
            &v54);
          v16 = *v15;
          *v15 = 0;
          object = v16;
          vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v41);
          vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v54);
        }
        if ( v10 )
        {
          vostok::fs_new::virtual_path_string::virtual_path_string(v13, (int)v10);
          v54.m_object = v17;
        }
        else
        {
          v54.m_object = 0;
        }
        vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
          &v47,
          (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&object);
        v38.m_begin = v38.m_buffer;
        v38.m_end = v38.m_buffer;
        v38.m_max_end = &v39;
        v38.m_buffer[0] = 0;
        v39 = 47;
        if ( v47.m_object
          && (v18 = (vostok::buffer_string *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr) != 0 )
        {
          vostok::fs_new::path_string_impl::assignf(
            &v38,
            (vostok::buffer_string *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr,
            (vostok::buffer_string *)&stru_7F9BE8.allocator,
            (const char *)v47.m_object->m_lods[0].m_template.m_object);
        }
        else
        {
          vostok::fs_new::path_string_impl::assignf(&v38, v18, (vostok::buffer_string *)&stru_7F9BE8.allocator, uri);
        }
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v47);
        vostok::fixed_string<260>::operator=(&v38, (const vostok::fixed_string<260> *)v54.m_object);
        if ( v10->m_end == v10->m_begin )
        {
          m_begin = v10->m_begin;
          if ( v10->m_begin != "nomaterial" )
          {
            v10->m_end = m_begin;
            *m_begin = 0;
            vostok::buffer_string::operator+=(v10, "nomaterial");
          }
        }
        vostok::fixed_string<260>::fixed_string<260>(v19, (vostok::buffer_string *)&v38.m_end, v10->m_begin);
        v21 = v10->m_begin;
        m_end = v38.m_end;
        v10->m_end = v10->m_begin;
        *v21 = 0;
        vostok::buffer_string::operator+=(v10, m_end);
        v23 = v46;
        v24 = v52;
        v46[v52].path = v10->m_begin;
        v23[v24].id = material_effects_instance_class;
        v25 = (const vostok::variant<32> *)v49;
        if ( v49 )
        {
          *(_DWORD *)(v49 + 40) = 0;
          v25->m_type_id = 0;
        }
        else
        {
          v25 = 0;
        }
        v26 = vostok::render::g_allocator;
        v27 = (const vostok::variant<32> **)&v48[v24];
        v45 = v27;
        *v27 = v25;
        v54.m_object = (vostok::particle::particle_system_instance_impl *)vostok::memory::new_helper<vostok::render::material_effects_instance_cook_data>::call<vostok::memory::doug_lea_allocator>(
                                                                            v26,
                                                                            v35,
                                                                            v36,
                                                                            v37);
        if ( v54.m_object )
        {
          v34 = 1;
          v33.l_.a3_.t_ = v28;
          vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
            (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v33.l_.a3_,
            object);
          v29 = vostok::render::mesh_type_to_vertex_input_type(__formal);
          vostok::render::material_effects_instance_cook_data::material_effects_instance_cook_data(
            v29,
            (vostok::render::material_effects_instance_cook_data *)v54.m_object,
            (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base>)v33.l_.a3_.t_,
            v34,
            (vostok::render::enum_cull_mode)v35);
          v27 = v45;
          __formal = v30;
        }
        else
        {
          __formal = 0;
        }
        vostok::variant<32>::set<vostok::render::material_effects_instance_cook_data *>(
          (vostok::variant<32> *)v28,
          *v27,
          (vostok::render::material_effects_instance_cook_data **)&__formal);
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&object);
        v31 = pointer->m_num_render_models;
        ++v52;
        v50 = (vostok::render::cook_intermediate_data *)((char *)v50 + 288);
        v49 += 48;
        v3 = pointer;
        v10 += 23;
      }
      while ( v52 < v31 );
    }
    v45 = (const vostok::variant<32> **)v3;
    v44 = cook_data;
    v43 = vostok::render::render_model_cook::finish_model_creation;
    v33.l_.a1_.t_ = (vostok::render::render_model_cook *)vostok::render::render_model_cook::finish_model_creation;
    v33.l_.a3_.t_ = cook_data;
    v33.f_.f_ = (void (__thiscall *)(vostok::render::render_model_cook *, vostok::resources::queries_result *, vostok::render::cook_intermediate_data *))&f;
    boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
      (boost::function<void __cdecl(vostok::resources::queries_result &)> *)this,
      v33,
      (int)v3);
    vostok::resources::query_resources(
      v46,
      v42,
      vostok::render::g_allocator,
      v48,
      (const vostok::variant<32> **)pointer->parent_query,
      assert_on_fail_true);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v32,
      (int *)&f);
  }
}
