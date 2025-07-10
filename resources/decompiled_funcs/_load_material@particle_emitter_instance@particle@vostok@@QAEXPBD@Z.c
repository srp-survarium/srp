// local variable allocation has failed, the output may be wrong!
void __thiscall vostok::particle::particle_emitter_instance::load_material(
        vostok::particle::particle_emitter_instance *this,
        const char *material_name)
{
  vostok::variant<32> *v2; // ecx
  void *v3; // eax
  unsigned int v4; // ecx
  int v5; // eax
  vostok::variant<32> *v6; // ecx
  __int64 v7; // [esp+162h] [ebp-C4h] BYREF
  vostok::particle::particle_emitter_instance *thisa; // [esp+16Ah] [ebp-BCh]
  char *v9; // [esp+172h] [ebp-B4h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+176h] [ebp-B0h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_cook *>,boost::arg<1> > > v11; // [esp+196h] [ebp-90h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > result; // [esp+1A6h] [ebp-80h] BYREF
  void (__thiscall *f)(vostok::particle::particle_emitter_instance *, vostok::resources::queries_result *); // [esp+1B6h] [ebp-70h]
  int f_4; // [esp+1BAh] [ebp-6Ch]
  int v15; // [esp+1BEh] [ebp-68h]
  int v16; // [esp+1C2h] [ebp-64h]
  vostok::render::material_effects_instance_cook_data *v17; // [esp+1C6h] [ebp-60h]
  int v18; // [esp+1CAh] [ebp-5Ch]
  int v19; // [esp+1CEh] [ebp-58h]
  int v20; // [esp+1D2h] [ebp-54h]
  unsigned __int8 v21; // [esp+1D9h] [ebp-4Dh]
  int v22; // [esp+1DAh] [ebp-4Ch]
  int v23; // [esp+1DEh] [ebp-48h]
  int v24; // [esp+1E2h] [ebp-44h]
  vostok::render::enum_vertex_input_type in_vertex_input_type; // [esp+1EAh] [ebp-3Ch]
  vostok::variant<32> v27; // [esp+1EEh] [ebp-38h] BYREF
  vostok::variant<32> *v28; // [esp+222h] [ebp-4h]

  v28 = (vostok::variant<32> *)this;
  vostok::variant<32>::variant<32>(&v27);
  in_vertex_input_type = null_vertex_input_type;
  if ( *(_DWORD *)&v28[4].m_storage[16] )
  {
    in_vertex_input_type = particle_vertex_input_type;
    v2 = v28;
    if ( *(_DWORD *)&v28[4].m_storage[4] )
    {
      v23 = v24;
      v23 = *(_DWORD *)&v28[4].m_storage[4];
      v22 = (*(int (__thiscall **)(int))(*(_DWORD *)v23 + 52))(v23);
      v21 = 0;
      if ( !v22 )
      {
        v20 = *(_DWORD *)&v28[4].m_storage[4];
        v19 = v20;
        v18 = v20;
        v21 = *(_BYTE *)(v20 + 136);
      }
      v2 = (vostok::variant<32> *)v21;
      if ( v21 )
        in_vertex_input_type = particle_subuv_vertex_input_type;
    }
  }
  else if ( *(_DWORD *)&v28[4].m_storage[20] )
  {
    in_vertex_input_type = particle_beamtrail_vertex_input_type;
  }
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v2);
  v3 = vostok::memory::new_helper<vostok::render::material_effects_instance_cook_data>::call<vostok::memory::pthreads3_allocator>();
  v17 = (vostok::render::material_effects_instance_cook_data *)operator new(0x10u, v3);
  if ( v17 )
  {
    thisa = (vostok::particle::particle_emitter_instance *)2;
    v7 = v4;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&v7,
      0);
    vostok::render::material_effects_instance_cook_data::material_effects_instance_cook_data(
      v17,
      in_vertex_input_type,
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v7,
      SBYTE4(v7),
      (vostok::render::enum_cull_mode)thisa);
    v16 = v5;
    v15 = v5;
  }
  else
  {
    v15 = 0;
  }
  v6 = v28;
  *(_DWORD *)&v28[4].m_storage[8] = v15;
  vostok::variant<32>::set<vostok::render::material_effects_instance_cook_data *>(
    v6,
    (int)&v27,
    (vostok::render::material_effects_instance_cook_data *const *)&v28[4].m_storage[8]);
  f = vostok::particle::particle_emitter_instance::on_material_loaded;
  f_4 = 0;
  thisa = (vostok::particle::particle_emitter_instance *)(unsigned __int8)1_240;
  v11 = *(boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_cook *>,boost::arg<1> > > *)boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>((boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&result, (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)vostok::particle::particle_emitter_instance::on_material_loaded, (survarium::weapon_core_animation_end_aware_state *)v28);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v11.l_.a1_.t_,
    &callback);
  if ( boost::detail::function::basic_vtable2<bool,char const *,enum survarium::hit_affects_type_enum>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::mf2<bool,survarium::artefact_lifebone_core,char const *,enum survarium::hit_affects_type_enum>,boost::_bi::list3<boost::_bi::value<survarium::artefact_lifebone_core *>,boost::arg<1>,boost::arg<2>>>>(
         (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::particle::particle_emitter_instance,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::particle::particle_emitter_instance *>,boost::arg<1>>>>'::`2'::stored_vtable,
         v11,
         &callback.functor) )
  {
    v9 = (char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::particle::particle_emitter_instance,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::particle::particle_emitter_instance *>,boost::arg<1>>>>'::`2'::stored_vtable.base.manager
       + 1;
    callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::particle::particle_emitter_instance,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::particle::particle_emitter_instance *>,boost::arg<1>>>>'::`2'::stored_vtable.base.manager
                                                             + 1);
  }
  else
  {
    callback.vtable = 0;
  }
  vostok::resources::query_resource(
    material_name,
    material_effects_instance_class,
    &callback,
    &vostok::memory::g_mt_allocator,
    &v27,
    0,
    assert_on_fail_true);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&callback);
  vostok::variant<32>::~variant<32>(&v27);
}
