void __thiscall survarium::artefact_core_cook::on_config_loaded(
        survarium::artefact_core_cook *this,
        vostok::resources::queries_result *data)
{
  vostok::particle::particle_system_instance_impl *v2; // esi
  vostok::resources::query_result_for_cook *m_parent_query; // ebx
  vostok::variant<32> *m_user_data; // esi
  boost::function1<void,vostok::resources::queries_result &> *v5; // ecx
  vostok::configs::binary_config_value *v6; // eax
  const char **v7; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // ecx
  _BYTE v9[28]; // [esp-1Ch] [ebp-8Ch] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v10; // [esp+10h] [ebp-60h] BYREF
  survarium::artefact_cook_data v11; // [esp+14h] [ebp-5Ch] BYREF
  survarium::artefact_core_cook *f; // [esp+1Ch] [ebp-54h]
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::artefact_core_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> const &,unsigned short,void *>,boost::_bi::list5<boost::_bi::value<survarium::artefact_core_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<unsigned short>,boost::_bi::value<void *> > > f_4; // [esp+20h] [ebp-50h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::artefact_core_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> const &,unsigned short,void *>,boost::_bi::list5<boost::_bi::value<survarium::artefact_core_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<unsigned short>,boost::_bi::value<void *> > > result; // [esp+38h] [ebp-38h] BYREF
  int v15[8]; // [esp+50h] [ebp-20h] BYREF

  f = this;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v11,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
  v2 = *(vostok::particle::particle_system_instance_impl **)&v11.item_dict_id;
  v10.m_object = 0;
  if ( *(_DWORD *)&v11.item_dict_id )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v10);
    v10.m_object = v2;
    _InterlockedExchangeAdd(&v2->m_reference_count, 1u);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v11);
  m_parent_query = data->m_parent_query;
  m_user_data = m_parent_query->m_user_data;
  if ( m_user_data )
  {
    vostok::variant<32>::try_get<survarium::artefact_cook_data>(m_user_data, &v11);
  }
  else
  {
    v11.game_world = 0;
    v11.item_dict_id = 0;
  }
  *(_DWORD *)&v9[24] = 0;
  *(_DWORD *)&v9[20] = survarium::artefact_core_cook::on_effect_loaded;
  *(survarium::artefact_cook_data *)&v9[12] = v11;
  *(_DWORD *)&v9[8] = 0;
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v9[8],
    &v10);
  *(_DWORD *)&v9[4] = (unsigned __int8)1_138;
  *(_DWORD *)v9 = f;
  boost::bind<void,survarium::artefact_core_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> const &,unsigned short,void *,survarium::artefact_core_cook *,boost::arg<1>,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,unsigned short,void *>(
    &result,
    *(void (__thiscall *__ptr64 *)(survarium::artefact_core_cook *, vostok::resources::queries_result *, const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *, unsigned __int16, void *))v9,
    *(survarium::artefact_core_cook **)&v9[8],
    *(__int16 *)&v9[12],
    *(vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)&v9[16],
    *(int *)&v9[20],
    *(void **)&v9[24]);
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::artefact_core_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> const &,unsigned short,void *>,boost::_bi::list5<boost::_bi::value<survarium::artefact_core_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<unsigned short>,boost::_bi::value<void *>>>::bind_t<void,boost::_mfi::mf4<void,survarium::artefact_core_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> const &,unsigned short,void *>,boost::_bi::list5<boost::_bi::value<survarium::artefact_core_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<unsigned short>,boost::_bi::value<void *>>>(
    &f_4,
    &result);
  v15[0] = 0;
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::artefact_core_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> const &,unsigned short,void *>,boost::_bi::list5<boost::_bi::value<survarium::artefact_core_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<unsigned short>,boost::_bi::value<void *>>>::bind_t<void,boost::_mfi::mf4<void,survarium::artefact_core_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> const &,unsigned short,void *>,boost::_bi::list5<boost::_bi::value<survarium::artefact_core_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<unsigned short>,boost::_bi::value<void *>>>(
    (boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::artefact_core_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> const &,unsigned short,void *>,boost::_bi::list5<boost::_bi::value<survarium::artefact_core_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<unsigned short>,boost::_bi::value<void *> > > *)&v9[4],
    &f_4);
  boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::artefact_core_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> const &,unsigned short,void *>,boost::_bi::list5<boost::_bi::value<survarium::artefact_core_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<unsigned short>,boost::_bi::value<void *>>>>(
    v5,
    (int)v15,
    *(boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::artefact_core_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> const &,unsigned short,void *>,boost::_bi::list5<boost::_bi::value<survarium::artefact_core_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<unsigned short>,boost::_bi::value<void *> > > *)&v9[4]);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&f_4.l_.a3_);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&result.l_.a3_);
  v6 = vostok::configs::binary_config_value::operator[](
         (vostok::configs::binary_config_value *)v10.m_object->m_lods[0].m_template.m_object,
         "data");
  v7 = (const char **)vostok::configs::binary_config_value::operator[](v6, "effect");
  vostok::resources::query_resource(
    *v7,
    (vostok::variant<32> *)0x6A,
    survarium::g_allocator,
    0,
    (const vostok::variant<32> **)m_parent_query,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v8, v15);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v10);
}
