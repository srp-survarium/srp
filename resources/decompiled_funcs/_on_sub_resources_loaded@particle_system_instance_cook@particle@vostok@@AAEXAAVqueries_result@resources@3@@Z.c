void __thiscall vostok::particle::particle_system_instance_cook::on_sub_resources_loaded(
        vostok::particle::particle_system_instance_cook *this,
        vostok::resources::queries_result *data)
{
  _BYTE *v2; // eax
  vostok::resources::query_result *v3; // eax
  vostok::resources::query_result_for_user *v4; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *unmanaged_resource; // eax
  survarium::game_camera *v6; // ecx
  vostok::memory::pthreads3_allocator *v7; // eax
  vostok::particle::particle_system_instance_impl *v8; // eax
  unsigned int v9; // esi
  vostok::render::enum_vertex_input_type vertex_input_type; // eax
  void *v11; // esp
  vostok::resources::request *v12; // eax
  void *v13; // esp
  survarium::game_camera *v14; // ecx
  vostok::variant<32> *v15; // eax
  void *v16; // esp
  survarium::game_camera *v17; // ecx
  vostok::variant<32> **v18; // eax
  unsigned int v19; // esi
  survarium::game_camera *v20; // ecx
  vostok::variant<32> *v21; // eax
  vostok::resources::unmanaged_resource *v22; // ecx
  vostok::render::material_effects_instance_cook_data *v23; // eax
  const char *v24; // eax
  vostok::resources::queries_result *v25; // ecx
  vostok::resources::query_result_for_cook *parent_query; // eax
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v27; // [esp-Ch] [ebp-164h] BYREF
  BOOL v28; // [esp-8h] [ebp-160h]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v29; // [esp-4h] [ebp-15Ch] BYREF
  int v30; // [esp+0h] [ebp-158h] BYREF
  vostok::render::material_effects_instance_cook_data *v31; // [esp+4h] [ebp-154h]
  vostok::render::material_effects_instance_cook_data *v32; // [esp+8h] [ebp-150h]
  vostok::variant<32> *v33; // [esp+Ch] [ebp-14Ch]
  int *v34; // [esp+10h] [ebp-148h]
  int *v35; // [esp+14h] [ebp-144h]
  int *v36; // [esp+18h] [ebp-140h]
  vostok::fs_new::virtual_path_string *v37; // [esp+1Ch] [ebp-13Ch]
  vostok::particle::particle_emitter *v38; // [esp+20h] [ebp-138h]
  vostok::particle::particle_system_instance_impl *v39; // [esp+24h] [ebp-134h]
  vostok::particle::particle_system_instance_cook *thisa; // [esp+28h] [ebp-130h]
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::weapon_core_cook,vostok::resources::queries_result &,survarium::weapon_state_creation_params const *,survarium::weapon_core *>,boost::_bi::list4<boost::_bi::value<survarium::weapon_core_cook *>,boost::arg<1>,boost::_bi::value<survarium::weapon_state_creation_params const *>,boost::_bi::value<survarium::weapon_core *> > > v41; // [esp+2Ch] [ebp-12Ch]
  char *v42; // [esp+84h] [ebp-D4h]
  void *_Where; // [esp+98h] [ebp-C0h]
  vostok::memory::pthreads3_allocator *v46; // [esp+9Ch] [ebp-BCh]
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::particle::particle_system_instance_cook,vostok::resources::queries_result &,vostok::particle::particle_system_instance_impl *,vostok::particle::material_query_data *,vostok::render::material_effects_instance_cook_data *>,boost::_bi::list5<boost::_bi::value<vostok::particle::particle_system_instance_cook *>,boost::arg<1>,boost::_bi::value<vostok::particle::particle_system_instance_impl *>,boost::_bi::value<vostok::particle::material_query_data *>,boost::_bi::value<vostok::render::material_effects_instance_cook_data *> > > result; // [esp+A0h] [ebp-B8h] BYREF
  void (__thiscall *f)(vostok::particle::particle_system_instance_cook *, vostok::resources::queries_result *, vostok::configs::binary_config *, vostok::particle::material_query_data *, vostok::render::material_effects_instance_cook_data *); // [esp+B8h] [ebp-A0h]
  int f_4; // [esp+BCh] [ebp-9Ch]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+C0h] [ebp-98h] BYREF
  vostok::render::material_effects_instance_cook_data *v51; // [esp+E8h] [ebp-70h]
  vostok::render::material_effects_instance_cook_data *value; // [esp+ECh] [ebp-6Ch] BYREF
  vostok::variant<32> *v53; // [esp+F0h] [ebp-68h]
  vostok::fs_new::virtual_path_string *v54; // [esp+F4h] [ebp-64h]
  vostok::particle::particle_system_instance_impl *v55; // [esp+FCh] [ebp-5Ch]
  vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> v56; // [esp+100h] [ebp-58h] BYREF
  vostok::particle::particle_system *v57; // [esp+104h] [ebp-54h]
  char v58; // [esp+10Bh] [ebp-4Dh]
  unsigned int k; // [esp+10Ch] [ebp-4Ch]
  unsigned int i; // [esp+110h] [ebp-48h]
  vostok::particle::particle_emitter_instance *instance; // [esp+114h] [ebp-44h]
  const char *material_name; // [esp+118h] [ebp-40h] BYREF
  vostok::particle::particle_emitter *v63; // [esp+11Ch] [ebp-3Ch]
  unsigned int j; // [esp+120h] [ebp-38h]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> templ; // [esp+124h] [ebp-34h]
  vostok::particle::particle_emitter *emitter; // [esp+128h] [ebp-30h]
  unsigned int emitter_index; // [esp+12Ch] [ebp-2Ch]
  unsigned int lod_index; // [esp+130h] [ebp-28h]
  vostok::particle::particle_system_instance_impl *created_resource; // [esp+134h] [ebp-24h]
  vostok::particle::material_query_data *material_data; // [esp+138h] [ebp-20h]
  vostok::resources::request *material_requests; // [esp+13Ch] [ebp-1Ch]
  vostok::render::material_effects_instance_cook_data *cook_data; // [esp+140h] [ebp-18h]
  vostok::variant<32> **user_data_variants_ptrs; // [esp+144h] [ebp-14h]
  vostok::particle::particle_system *part_system; // [esp+148h] [ebp-10h]
  unsigned int num_material_queries; // [esp+14Ch] [ebp-Ch]
  vostok::variant<32> *user_data_variants; // [esp+150h] [ebp-8h]
  vostok::particle::material_query_data *material_data_it; // [esp+154h] [ebp-4h]

  thisa = this;
  v58 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v2 )
  {
    v29.m_object = (vostok::resources::unmanaged_resource *)vostok::resources::queries_result::is_successful(data);
    v28 = 0;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v29.m_object);
  }
  v3 = vostok::resources::queries_result::operator[](data, 0);
  unmanaged_resource = vostok::resources::query_result_for_user::get_unmanaged_resource(
                         v4,
                         (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v3,
                         (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v56);
  v57 = (vostok::particle::particle_system *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)unmanaged_resource);
  part_system = v57;
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v56);
  survarium::weapon_user_dead_state::finalize(v6);
  v46 = v7;
  _Where = vostok::memory::pthreads3_allocator::malloc_impl(v7, (char *)0x2C0);
  v55 = (vostok::particle::particle_system_instance_impl *)operator new(0x2C0u, _Where);
  if ( v55 )
  {
    vostok::particle::particle_system_instance_impl::particle_system_instance_impl(v55);
    v39 = v8;
  }
  else
  {
    v39 = 0;
  }
  created_resource = v39;
  num_material_queries = 0;
  for ( lod_index = 0; lod_index < part_system->m_num_lods; ++lod_index )
  {
    for ( emitter_index = 0; emitter_index < part_system->m_lods.pointer[lod_index].m_num_emitters; ++emitter_index )
    {
      emitter = &part_system->m_lods.pointer[lod_index].m_emitters_array.pointer[emitter_index];
      if ( !emitter->m_event.pointer && emitter->m_visibility )
        ++num_material_queries;
    }
  }
  v9 = 284 * num_material_queries;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)lod_index);
  material_data = (vostok::particle::material_query_data *)vostok::memory::malloc_helper<vostok::memory::pthreads3_allocator>(v9);
  material_data_it = material_data;
  for ( templ.m_object = 0; (unsigned int)templ.m_object < part_system->m_num_lods; ++templ.m_object )
  {
    v29.m_object = templ.m_object;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v29,
      (vostok::configs::binary_config *)part_system);
    vostok::particle::particle_system_instance_impl::set_template(created_resource, (unsigned int)templ.m_object, v29);
    for ( j = 0; j < part_system->m_lods.pointer[(int)templ.m_object].m_num_emitters; ++j )
    {
      v63 = &part_system->m_lods.pointer[(int)templ.m_object].m_emitters_array.pointer[j];
      if ( !v63->m_event.pointer && v63->m_visibility )
      {
        instance = vostok::particle::particle_world::create_emitter_instance(v63, 0, 0);
        if ( v63->m_material_name[0] )
          v38 = v63;
        else
          v38 = (vostok::particle::particle_emitter *)"default_particle";
        material_name = (const char *)v38;
        v54 = (vostok::fs_new::virtual_path_string *)operator new(0x11Cu, material_data_it);
        if ( v54 )
        {
          vostok::fs_new::virtual_path_string::virtual_path_string(v54);
          v37 = v54;
        }
        else
        {
          v37 = 0;
        }
        material_data_it->instance = instance;
        vostok::fs_new::virtual_path_string::operator=<char const *>(&material_data_it->material_name, &material_name);
        vertex_input_type = vostok::particle::particle_emitter_instance::get_vertex_input_type(instance);
        material_data_it->vertex_type = vertex_input_type;
        ++material_data_it;
        vostok::particle::particle_system_instance_impl::add_emitter_instance(
          created_resource,
          (unsigned int)templ.m_object,
          instance);
      }
    }
  }
  v11 = alloca(8 * num_material_queries);
  v36 = &v30;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)templ.m_object);
  material_requests = v12;
  v13 = alloca(48 * num_material_queries);
  v35 = &v30;
  survarium::weapon_user_dead_state::finalize(v14);
  user_data_variants = v15;
  v16 = alloca(4 * num_material_queries);
  v34 = &v30;
  survarium::weapon_user_dead_state::finalize(v17);
  user_data_variants_ptrs = v18;
  v19 = 16 * num_material_queries;
  survarium::weapon_user_dead_state::finalize(v20);
  cook_data = (vostok::render::material_effects_instance_cook_data *)vostok::memory::malloc_helper<vostok::memory::pthreads3_allocator>(v19);
  for ( i = 0; i < num_material_queries; ++i )
  {
    v53 = (vostok::variant<32> *)operator new(0x30u, &user_data_variants[i]);
    if ( v53 )
    {
      vostok::variant<32>::variant<32>(v53);
      v33 = v21;
    }
    else
    {
      v33 = 0;
    }
    user_data_variants_ptrs[i] = v33;
    v51 = (vostok::render::material_effects_instance_cook_data *)operator new(0x10u, &cook_data[i]);
    if ( v51 )
    {
      v29.m_object = (vostok::resources::unmanaged_resource *)2;
      v28 = 0;
      v27.m_object = v22;
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        &v27,
        0);
      vostok::render::material_effects_instance_cook_data::material_effects_instance_cook_data(
        v51,
        material_data[i].vertex_type,
        v27,
        v28,
        (vostok::render::enum_cull_mode)v29.m_object);
      v32 = v23;
      v31 = v23;
    }
    else
    {
      v31 = 0;
    }
    value = v31;
    vostok::variant<32>::set<vostok::render::material_effects_instance_cook_data *>(
      (vostok::variant<32> *)user_data_variants_ptrs,
      (int)user_data_variants_ptrs[i]->m_helper_storage,
      &value);
  }
  for ( k = 0; k < num_material_queries; ++k )
  {
    material_requests[k].id = material_effects_instance_class;
    v24 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&material_data[k]);
    material_requests[k].path = v24;
  }
  f = vostok::particle::particle_system_instance_cook::on_materials_loaded;
  f_4 = 0;
  v41 = *(boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::weapon_core_cook,vostok::resources::queries_result &,survarium::weapon_state_creation_params const *,survarium::weapon_core *>,boost::_bi::list4<boost::_bi::value<survarium::weapon_core_cook *>,boost::arg<1>,boost::_bi::value<survarium::weapon_state_creation_params const *>,boost::_bi::value<survarium::weapon_core *> > > *)boost::bind<void,vostok::particle::particle_system_instance_cook,vostok::resources::queries_result &,vostok::particle::particle_system_instance_impl *,vostok::particle::material_query_data *,vostok::render::material_effects_instance_cook_data *,vostok::particle::particle_system_instance_cook *,boost::arg<1>,vostok::particle::particle_system_instance_impl *,vostok::particle::material_query_data *,vostok::render::material_effects_instance_cook_data *>(&result, (void (__thiscall *__ptr64)(vostok::particle::particle_system_instance_cook *, vostok::resources::queries_result *, vostok::particle::particle_system_instance_impl *, vostok::particle::material_query_data *, vostok::render::material_effects_instance_cook_data *))(unsigned int)vostok::particle::particle_system_instance_cook::on_materials_loaded, thisa, 1_238, created_resource, material_data, cook_data);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v41.l_.a3_.t_,
    &callback);
  if ( boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::particle::particle_system_instance_cook,vostok::resources::queries_result &,vostok::particle::particle_system_instance_impl *,vostok::particle::material_query_data *,vostok::render::material_effects_instance_cook_data *>,boost::_bi::list5<boost::_bi::value<vostok::particle::particle_system_instance_cook *>,boost::arg<1>,boost::_bi::value<vostok::particle::particle_system_instance_impl *>,boost::_bi::value<vostok::particle::material_query_data *>,boost::_bi::value<vostok::render::material_effects_instance_cook_data *>>>>(
         (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::particle::particle_system_instance_cook,vostok::resources::queries_result &,vostok::particle::particle_system_instance_impl *,vostok::particle::material_query_data *,vostok::render::material_effects_instance_cook_data *>,boost::_bi::list5<boost::_bi::value<vostok::particle::particle_system_instance_cook *>,boost::arg<1>,boost::_bi::value<vostok::particle::particle_system_instance_impl *>,boost::_bi::value<vostok::particle::material_query_data *>,boost::_bi::value<vostok::render::material_effects_instance_cook_data *>>>>'::`2'::stored_vtable,
         v41,
         &callback.functor) )
  {
    v25 = (vostok::resources::queries_result *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::particle::particle_system_instance_cook,vostok::resources::queries_result &,vostok::particle::particle_system_instance_impl *,vostok::particle::material_query_data *,vostok::render::material_effects_instance_cook_data *>,boost::_bi::list5<boost::_bi::value<vostok::particle::particle_system_instance_cook *>,boost::arg<1>,boost::_bi::value<vostok::particle::particle_system_instance_impl *>,boost::_bi::value<vostok::particle::material_query_data *>,boost::_bi::value<vostok::render::material_effects_instance_cook_data *>>>>'::`2'::stored_vtable.base.manager
                                              + 1);
    v42 = (char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::particle::particle_system_instance_cook,vostok::resources::queries_result &,vostok::particle::particle_system_instance_impl *,vostok::particle::material_query_data *,vostok::render::material_effects_instance_cook_data *>,boost::_bi::list5<boost::_bi::value<vostok::particle::particle_system_instance_cook *>,boost::arg<1>,boost::_bi::value<vostok::particle::particle_system_instance_impl *>,boost::_bi::value<vostok::particle::material_query_data *>,boost::_bi::value<vostok::render::material_effects_instance_cook_data *>>>>'::`2'::stored_vtable.base.manager
        + 1;
    callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::particle::particle_system_instance_cook,vostok::resources::queries_result &,vostok::particle::particle_system_instance_impl *,vostok::particle::material_query_data *,vostok::render::material_effects_instance_cook_data *>,boost::_bi::list5<boost::_bi::value<vostok::particle::particle_system_instance_cook *>,boost::arg<1>,boost::_bi::value<vostok::particle::particle_system_instance_impl *>,boost::_bi::value<vostok::particle::material_query_data *>,boost::_bi::value<vostok::render::material_effects_instance_cook_data *>>>>'::`2'::stored_vtable.base.manager
                                                             + 1);
  }
  else
  {
    callback.vtable = 0;
  }
  v29.m_object = (vostok::resources::unmanaged_resource *)1;
  parent_query = vostok::resources::queries_result::get_parent_query(v25, (int)data);
  vostok::resources::query_resources(
    material_requests,
    num_material_queries,
    (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
    &vostok::memory::g_mt_allocator,
    (const vostok::variant<32> **)user_data_variants_ptrs,
    parent_query,
    (assert_on_fail_bool)v29.m_object);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&callback);
}
