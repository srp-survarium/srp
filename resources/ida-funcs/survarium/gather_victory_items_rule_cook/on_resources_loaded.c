void __userpurge survarium::gather_victory_items_rule_cook::on_resources_loaded(
        survarium::gather_victory_items_rule_cook *this@<ecx>,
        vostok::resources::resource_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base> *a2@<ebp>,
        const vostok::variant<32> *const *a3@<edi>,
        const char *a4@<esi>,
        vostok::resources::queries_result *data,
        survarium::pure_game_effect_emitter_base_vtbl *physics_world,
        unsigned int seed)
{
  vostok::memory::doug_lea_allocator *v7; // esi
  const vostok::variant<32> **m_parent_query; // eax
  char *v9; // eax
  vostok::memory::doug_lea_allocator *v10; // ecx
  char *v11; // eax
  survarium::gather_victory_items_rule *v12; // ecx
  int v13; // eax
  vostok::configs::binary_config_value *v14; // eax
  vostok::configs::binary_config_value *v15; // eax
  const vostok::configs::binary_config_value *v16; // eax
  const stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > *v17; // edi
  const vostok::variant<32> **v18; // esi
  survarium::gather_victory_items_rule *v19; // ecx
  unsigned __int16 pointer; // di
  vostok::memory::doug_lea_allocator *v21; // esi
  char *v22; // eax
  vostok::memory::doug_lea_allocator *v23; // ecx
  char *v24; // eax
  survarium::pure_game_effect_emitter_base *m_object; // edx
  int v26; // ecx
  vostok::detail::abstract_type_helper *v27; // esi
  vostok::detail::abstract_type_helper *v28; // edi
  vostok::configs::binary_config_value *M_start; // eax
  const vostok::configs::binary_config_value *v30; // eax
  vostok::detail::abstract_type_helper_vtbl **v31; // esi
  vostok::detail::abstract_type_helper *v32; // edi
  vostok::resources::resource_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base> *v33; // esi
  const vostok::configs::binary_config_value *v34; // eax
  const vostok::variant<32> **v35; // esi
  int v36; // eax
  vostok::vfs::base_node<1> **p_m_link_target; // esi
  vostok::detail::abstract_type_helper *v38; // eax
  vostok::resources::resource_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base> *v39; // esi
  vostok::memory::doug_lea_allocator *v40; // esi
  char *v41; // eax
  vostok::memory::doug_lea_allocator *v42; // ecx
  survarium::pure_game_effect_emitter_base *v43; // eax
  vostok::configs::binary_config_value *m_root; // eax
  vostok::configs::binary_config_value *v45; // eax
  unsigned int v46; // edi
  void *v47; // esp
  void *v48; // esp
  vostok::variant<32> *v49; // ecx
  void *v50; // esi
  void *v51; // esp
  vostok::resources::resource_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base> *v52; // ecx
  void *v53; // edi
  vostok::variant<32> *v54; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v55; // ecx
  vostok::buffer_vector<vostok::variant<32> > *v56; // ecx
  vostok::variant<32> v57; // [esp-A8h] [ebp-B4h] BYREF
  vostok::variant<32> v58; // [esp-70h] [ebp-7Ch] BYREF
  vostok::resources::creation_request v59; // [esp-3Ch] [ebp-48h] BYREF
  const vostok::variant<32> **v60; // [esp-2Ch] [ebp-38h]
  vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v61; // [esp-28h] [ebp-34h] BYREF
  void *v62[3]; // [esp-24h] [ebp-30h] BYREF
  int v63; // [esp-18h] [ebp-24h]
  const vostok::variant<32> **v64; // [esp-14h] [ebp-20h] BYREF
  int v65; // [esp-10h] [ebp-1Ch]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v66; // [esp-Ch] [ebp-18h] BYREF
  unsigned __int8 v67; // [esp-5h] [ebp-11h]
  stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base>,vostok::vectora_allocator<vostok::resources::resource_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base> > > v68; // [esp-4h] [ebp-10h] BYREF
  vostok::memory::base_allocator *retaddr; // [esp+Ch] [ebp+0h]

  v68._M_finish = a2;
  v68._M_end_of_storage.m_allocator = retaddr;
  *(_DWORD *)&v57.m_helper_storage[4] = a4;
  v7 = survarium::g_allocator;
  *(_DWORD *)v57.m_helper_storage = a3;
  m_parent_query = (const vostok::variant<32> **)data->m_parent_query;
  v59.m_id = (vostok::resources::class_id_enum)this;
  v60 = m_parent_query;
  v9 = type_info::raw_name(&survarium::gather_victory_items_rule `RTTI Type Descriptor');
  v11 = vostok::memory::doug_lea_allocator::malloc_impl(
          v10,
          (int)v7,
          0x160u,
          v9,
          (const char *const)a3,
          *(const char *const *)&v57.m_helper_storage[4],
          *(const unsigned int *)v57.m_storage);
  if ( v11 )
  {
    survarium::gather_victory_items_rule::gather_victory_items_rule(v12, (int)v11, seed);
    v65 = v13;
  }
  else
  {
    v65 = 0;
  }
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v66,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
  vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<survarium::server_game_project,vostok::resources::unmanaged_intrusive_base>,vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&v66,
    &v61);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v66);
  v14 = vostok::configs::binary_config_value::operator[](v61.m_object->m_config.m_object->m_root, "server_objects");
  v68._M_start = (vostok::resources::resource_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base> *)vostok::configs::binary_config_value::operator[](v14, "victory_item_spawners")->data.pointer;
  v15 = vostok::configs::binary_config_value::operator[](v61.m_object->m_config.m_object->m_root, "server_objects");
  v16 = vostok::configs::binary_config_value::operator[](v15, "victory_item_spawners");
  v17 = (const stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > *)v65;
  v18 = (const vostok::variant<32> **)((char *)v16->data.pointer + 24 * v16->count);
  v66.m_object = (survarium::pure_game_effect_emitter_base *)(v65 + 288);
  v62[0] = 0;
  v64 = v18;
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::resize(
    (stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > *)(v65 + 288),
    ((char *)v18 - (char *)v68._M_start) / 24,
    v62);
  if ( (const vostok::variant<32> **)v68._M_start != v18 )
  {
    do
    {
      pointer = (unsigned __int16)vostok::configs::binary_config_value::operator[](
                                    (vostok::configs::binary_config_value *)v68._M_start,
                                    "point_id")->data.pointer;
      v21 = survarium::g_allocator;
      v22 = type_info::raw_name(&survarium::victory_item_spawner `RTTI Type Descriptor');
      v24 = vostok::memory::doug_lea_allocator::malloc_impl(
              v23,
              (int)v21,
              0x1Cu,
              v22,
              *(const char *const *)v57.m_helper_storage,
              *(const char *const *)&v57.m_helper_storage[4],
              *(const unsigned int *)v57.m_storage);
      m_object = v66.m_object;
      v26 = 4 * pointer;
      *(void (__thiscall **)(struct survarium::pure_game_effect_emitter_base *))((char *)&v66.m_object->~survarium::pure_game_effect_emitter_base
                                                                               + v26) = (void (__thiscall *)(struct survarium::pure_game_effect_emitter_base *))v24;
      v63 = *(int *)((char *)&m_object->~survarium::pure_game_effect_emitter_base + v26);
      v27 = (vostok::detail::abstract_type_helper *)vostok::configs::binary_config_value::operator[](
                                                      (vostok::configs::binary_config_value *)v68._M_start,
                                                      "position")->data.pointer;
      v28 = (vostok::detail::abstract_type_helper *)v63;
      M_start = (vostok::configs::binary_config_value *)v68._M_start;
      *(vostok::detail::abstract_type_helper *)v63 = (vostok::detail::abstract_type_helper)v27->__vftable;
      ++v27;
      ++v28;
      v28->__vftable = v27->__vftable;
      v28[1].__vftable = v27[1].__vftable;
      v30 = vostok::configs::binary_config_value::operator[](M_start, "rotation");
      v31 = (vostok::detail::abstract_type_helper_vtbl **)v30->data.pointer;
      v32 = (vostok::detail::abstract_type_helper *)(v63 + 12);
      *(_DWORD *)(v63 + 12) = *(_DWORD *)v30->data.pointer;
      ++v31;
      ++v32;
      v32->__vftable = *v31;
      v32[1].__vftable = v31[1];
      v33 = v68._M_start;
      v34 = vostok::configs::binary_config_value::operator[](
              (vostok::configs::binary_config_value *)v68._M_start,
              "priority");
      v19 = (survarium::gather_victory_items_rule *)v63;
      *(_DWORD *)(v63 + 24) = v34->data.pointer;
      v68._M_start = v33 + 6;
    }
    while ( &v33[6] != (vostok::resources::resource_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base> *)v64 );
    v17 = (const stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > *)v65;
  }
  v64 = (const vostok::variant<32> **)(data->m_size - 1);
  v35 = v64;
  survarium::gather_victory_items_rule::select_spawners(v19, v17, (int)v64);
  v36 = 0;
  v67 = 0;
  if ( v35 )
  {
    v63 = (int)&v17[17];
    do
    {
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        &v66,
        (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[v36 + 1].m_unmanaged_resource);
      if ( v66.m_object )
        p_m_link_target = &v66.m_object[-1].m_fat_it.m_link_target;
      else
        p_m_link_target = 0;
      v68._M_start = 0;
      if ( p_m_link_target )
      {
        vostok::intrusive_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v68);
        v68._M_start = (vostok::resources::resource_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base> *)p_m_link_target;
        _InterlockedExchangeAdd((volatile signed __int32 *)p_m_link_target + 76, 1u);
      }
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v66);
      v68._M_start[116].m_object = (survarium::victory_item_core *)v65;
      v38 = (vostok::detail::abstract_type_helper *)v63;
      v39 = *(vostok::resources::resource_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base> **)(v63 + 4);
      if ( v39 == *(vostok::resources::resource_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base> **)(v63 + 12) )
      {
        stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base>,vostok::vectora_allocator<vostok::resources::resource_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base>>>::_M_insert_overflow_aux(
          &v68,
          v63,
          v39,
          (vostok::intrusive_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v68,
          *(unsigned int *)v57.m_helper_storage,
          v57.m_helper_storage[4]);
      }
      else
      {
        if ( v39 )
        {
          vostok::intrusive_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
            v39,
            (const vostok::intrusive_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v68);
          v38 = (vostok::detail::abstract_type_helper *)v63;
        }
        v38[1].__vftable = (vostok::detail::abstract_type_helper_vtbl *)((char *)v38[1].__vftable + 4);
      }
      vostok::intrusive_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v68);
      v36 = ++v67;
    }
    while ( v67 < (unsigned int)v64 );
    v17 = (const stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > *)v65;
  }
  v40 = survarium::g_allocator;
  v41 = type_info::raw_name(&survarium::victory_items_container_core_creation_params `RTTI Type Descriptor');
  v43 = (survarium::pure_game_effect_emitter_base *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                      v42,
                                                      (int)v40,
                                                      8u,
                                                      v41,
                                                      *(const char *const *)v57.m_helper_storage,
                                                      *(const char *const *)&v57.m_helper_storage[4],
                                                      *(const unsigned int *)v57.m_storage);
  if ( v43 )
  {
    v43->__vftable = physics_world;
    v43->type = (unsigned int)v17;
    v66.m_object = v43;
  }
  else
  {
    v66.m_object = 0;
  }
  m_root = v61.m_object->m_config.m_object->m_root;
  v63 = 8;
  v45 = vostok::configs::binary_config_value::operator[](m_root, "server_objects");
  qmemcpy(v57.m_storage, vostok::configs::binary_config_value::operator[](v45, "victory_items_containers"), 0x18u);
  v46 = 24 * HIWORD(*(_DWORD *)&v57.m_storage[20]) / 24;
  v62[0] = (void *)v46;
  v47 = alloca(16 * v46);
  v59.m_name = (const char *)&v57;
  v59.m_data.m_data = (const char *)&v57;
  v59.m_data.m_size = (unsigned int)&v57 + 16 * v46;
  v48 = alloca(48 * v46);
  v58.m_helper = 0;
  v58.m_type_id = 0;
  vostok::buffer_vector<vostok::variant<32>>::buffer_vector<vostok::variant<32>>(
    (vostok::buffer_vector<vostok::variant<32> > *)&v57.m_storage[24],
    v46,
    v46,
    &v57,
    &v58);
  vostok::variant<32>::destroy_previous_variable_if_needed(v49, (int)&v58);
  v50 = v62[0];
  v64 = 0;
  v51 = alloca(4 * (int)v62[0]);
  vostok::buffer_vector<vostok::variant<32> const *>::buffer_vector<vostok::variant<32> const *>(
    (vostok::buffer_vector<vostok::variant<32> const *> *)&v57,
    (vostok::buffer_vector<vostok::variant<32> const *> **)&v57.m_type_id,
    v50,
    (unsigned int)v50,
    &v64,
    *(const vostok::variant<32> *const **)v57.m_helper_storage);
  v53 = 0;
  if ( v50 )
  {
    *(vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v58.m_storage[28] = v66;
    v58.m_helper = (vostok::detail::abstract_type_helper *)v63;
    v68._M_start = *(vostok::resources::resource_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base> **)&v57.m_storage[24];
    *(_DWORD *)&v58.m_storage[24] = "victory_items_container";
    v58.m_type_id = 88;
    v63 = *(_DWORD *)v57.m_storage;
    do
    {
      vostok::buffer_vector<vostok::resources::creation_request>::push_back(
        (vostok::buffer_vector<vostok::resources::creation_request> *)v52,
        &v59,
        &v58.m_storage[24]);
      vostok::variant<32>::set<vostok::configs::binary_config_value>(
        v54,
        (const vostok::configs::binary_config_value *)v68._M_start,
        (const void *)v63);
      v52 = v68._M_start;
      v63 += 24;
      v68._M_start += 12;
      *(_DWORD *)(v57.m_type_id + 4 * (_DWORD)v53) = v52;
      v53 = (char *)v53 + 1;
    }
    while ( v53 != v50 );
  }
  v62[1] = (void *)v59.m_id;
  v62[2] = v66.m_object;
  *(_DWORD *)&v58.m_storage[20] = 0;
  *(_DWORD *)&v58.m_storage[16] = survarium::gather_victory_items_rule_cook::on_containers_ready;
  v63 = v65;
  *(_DWORD *)&v58.m_storage[24] = v59.m_id;
  *(vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v58.m_storage[28] = v66;
  v58.m_helper = (vostok::detail::abstract_type_helper *)v65;
  qmemcpy(v57.m_storage, &v58.m_storage[16], 0x18u);
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    *(_DWORD *)&v58.m_storage[8] = 0;
  }
  else
  {
    qmemcpy(&v58.m_storage[16], v57.m_storage, 0x18u);
    *(_DWORD *)&v58.m_storage[8] = (char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::gather_victory_items_rule_cook,vostok::resources::queries_result &,survarium::victory_items_container_core_creation_params *,survarium::gather_victory_items_rule *>,boost::_bi::list4<boost::_bi::value<survarium::gather_victory_items_rule_cook *>,boost::arg<1>,boost::_bi::value<survarium::victory_items_container_core_creation_params *>,boost::_bi::value<survarium::gather_victory_items_rule *>>>>'::`2'::stored_vtable
                                 + 1;
  }
  vostok::resources::query_create_resources(
    (const vostok::resources::creation_request *)v59.m_name,
    (unsigned int)v62[0],
    survarium::g_allocator,
    (const vostok::variant<32> *const *)v57.m_type_id,
    v60);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v55,
    (int *)&v58.m_storage[8]);
  vostok::buffer_vector<vostok::variant<32>>::~buffer_vector<vostok::variant<32>>(v56, (int *)&v57.m_storage[24]);
  vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v61);
}
