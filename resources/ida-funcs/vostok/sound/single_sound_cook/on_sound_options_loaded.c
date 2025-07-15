void __thiscall vostok::sound::single_sound_cook::on_sound_options_loaded(
        vostok::sound::single_sound_cook *this,
        vostok::resources::queries_result *data,
        vostok::resources::query_result_for_cook *parent)
{
  char *requested_path; // eax
  vostok::fixed_string<260> *v4; // ecx
  volatile int m_result; // ecx
  vostok::particle::particle_system_instance_impl *m_object; // esi
  const char **v7; // eax
  const vostok::configs::binary_config_value *v8; // eax
  vostok::configs::binary_config_value *v9; // ecx
  float pointer; // xmm0_4
  vostok::configs::binary_config_value *v11; // ecx
  const vostok::configs::binary_config_value *v12; // eax
  float v13; // xmm0_4
  vostok::configs::binary_config_value *v14; // ecx
  const vostok::configs::binary_config_value *v15; // eax
  float v16; // xmm0_4
  vostok::configs::binary_config_value *v17; // ecx
  int v18; // ecx
  bool v19; // zf
  const char *v20; // edi
  char *v21; // esi
  boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *v22; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v23; // ecx
  _BYTE v24[40]; // [esp-24h] [ebp-314h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v25; // [esp+10h] [ebp-2E0h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v26; // [esp+14h] [ebp-2DCh] BYREF
  vostok::sound::sound_options __that; // [esp+18h] [ebp-2D8h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::single_sound_cook,vostok::resources::queries_result &,vostok::sound::sound_options>,boost::_bi::list3<boost::_bi::value<vostok::sound::single_sound_cook *>,boost::arg<1>,boost::_bi::value<vostok::sound::sound_options> > > *result; // [esp+2Ch] [ebp-2C4h]
  vostok::configs::binary_config_value v29; // [esp+30h] [ebp-2C0h] BYREF
  vostok::resources::request requests; // [esp+48h] [ebp-2A8h] BYREF
  char *v31; // [esp+50h] [ebp-2A0h]
  int v32; // [esp+54h] [ebp-29Ch]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+58h] [ebp-298h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::single_sound_cook,vostok::resources::queries_result &,vostok::sound::sound_options>,boost::_bi::list3<boost::_bi::value<vostok::sound::single_sound_cook *>,boost::arg<1>,boost::_bi::value<vostok::sound::sound_options> > > v34; // [esp+78h] [ebp-278h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::single_sound_cook,vostok::resources::queries_result &,vostok::sound::sound_options>,boost::_bi::list3<boost::_bi::value<vostok::sound::single_sound_cook *>,boost::arg<1>,boost::_bi::value<vostok::sound::sound_options> > > v35; // [esp+98h] [ebp-258h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::single_sound_cook,vostok::resources::queries_result &,vostok::sound::sound_options>,boost::_bi::list3<boost::_bi::value<vostok::sound::single_sound_cook *>,boost::arg<1>,boost::_bi::value<vostok::sound::sound_options> > > v36; // [esp+B8h] [ebp-238h] BYREF
  char _Dst[256]; // [esp+D8h] [ebp-218h] BYREF
  vostok::buffer_string v38[22]; // [esp+1D8h] [ebp-118h] BYREF
  char v39; // [esp+2E8h] [ebp-8h]

  result = (boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::single_sound_cook,vostok::resources::queries_result &,vostok::sound::sound_options>,boost::_bi::list3<boost::_bi::value<vostok::sound::single_sound_cook *>,boost::arg<1>,boost::_bi::value<vostok::sound::sound_options> > > *)this;
  requested_path = (char *)vostok::resources::query_result_for_user::get_requested_path(parent);
  vostok::fixed_string<260>::fixed_string<260>(v4, v38, requested_path);
  m_result = data->m_result;
  __that.fixed_spl = FLOAT_60_0;
  v39 = 47;
  __that.spl.m_object = 0;
  __that.volume_k = s_bm_current_air_resistance;
  __that.lp_filter_k = s_bm_current_air_resistance;
  __that.pan_3d = 1;
  __that.can_be_displaced = 1;
  __that.use_hdr = 1;
  if ( m_result == 1 )
  {
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v26,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
    m_object = (vostok::particle::particle_system_instance_impl *)v26.m_object;
    v25.m_object = 0;
    if ( v26.m_object )
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v25);
      v25.m_object = m_object;
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
    }
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v26);
    qmemcpy(
      (void *)&v29,
      vostok::configs::binary_config_value::operator[](
        (vostok::configs::binary_config_value *)v25.m_object->m_lods[0].m_template.m_object,
        "options"),
      sizeof(v29));
    v7 = (const char **)vostok::configs::binary_config_value::operator[](&v29, "spl_preset");
    strcpy_s(_Dst, 0x100u, *v7);
    v8 = vostok::configs::binary_config_value::operator[](&v29, "spl_value");
    if ( v8->type == 2 )
      pointer = *(float *)&v8->data.pointer;
    else
      pointer = (float)(int)v8->data.pointer;
    __that.fixed_spl = pointer;
    if ( vostok::configs::binary_config_value::value_exists(v9, (int)&v29, (unsigned int)"volume_k") )
    {
      v12 = vostok::configs::binary_config_value::operator[](&v29, "volume_k");
      if ( v12->type == 2 )
        v13 = *(float *)&v12->data.pointer;
      else
        v13 = (float)(int)v12->data.pointer;
      __that.volume_k = v13;
    }
    if ( vostok::configs::binary_config_value::value_exists(v11, (int)&v29, (unsigned int)"lp_filter_k") )
    {
      v15 = vostok::configs::binary_config_value::operator[](&v29, "lp_filter_k");
      if ( v15->type == 2 )
        v16 = *(float *)&v15->data.pointer;
      else
        v16 = (float)(int)v15->data.pointer;
      __that.lp_filter_k = v16;
    }
    if ( vostok::configs::binary_config_value::value_exists(v14, (int)&v29, (unsigned int)"can_be_displaced") )
      __that.can_be_displaced = vostok::configs::binary_config_value::operator[](&v29, "can_be_displaced")->data.pointer != 0;
    if ( vostok::configs::binary_config_value::value_exists(v17, (int)&v29, (unsigned int)"use_hdr") )
      __that.use_hdr = vostok::configs::binary_config_value::operator[](&v29, "use_hdr")->data.pointer != 0;
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v25);
  }
  else
  {
    strcpy_s(_Dst, 0x100u, "default");
  }
  v18 = 8;
  v19 = 1;
  v20 = "default";
  v21 = _Dst;
  do
  {
    if ( !v18 )
      break;
    v19 = *v21++ == *v20++;
    --v18;
  }
  while ( v19 );
  __that.use_spl_curve = !v19;
  vostok::buffer_string::append((vostok::buffer_string *)v18, (int)v38, ".high");
  requests.path = v38[0].m_begin;
  v31 = _Dst;
  *(_DWORD *)&v24[32] = 0;
  *(_DWORD *)&v24[28] = vostok::sound::single_sound_cook::on_sub_resources_loaded;
  requests.id = encoded_sound_class;
  v32 = 42;
  vostok::sound::sound_options::sound_options(
    (vostok::sound::sound_options *)&v24[8],
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&__that);
  *(_DWORD *)&v24[4] = (unsigned __int8)1_25;
  boost::bind<void,vostok::sound::single_sound_cook,vostok::resources::queries_result &,vostok::sound::sound_options,vostok::sound::single_sound_cook *,boost::arg<1>,vostok::sound::sound_options>(
    (int)&v35,
    result,
    *(void (__thiscall *__ptr64 *)(vostok::sound::single_sound_cook *, vostok::resources::queries_result *, vostok::sound::sound_options))&v24[4],
    *(vostok::sound::single_sound_cook **)&v24[12],
    (boost::arg<1>)v24[16],
    *(vostok::sound::sound_options *)&v24[20]);
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::single_sound_cook,vostok::resources::queries_result &,vostok::sound::sound_options>,boost::_bi::list3<boost::_bi::value<vostok::sound::single_sound_cook *>,boost::arg<1>,boost::_bi::value<vostok::sound::sound_options>>>::bind_t<void,boost::_mfi::mf2<void,vostok::sound::single_sound_cook,vostok::resources::queries_result &,vostok::sound::sound_options>,boost::_bi::list3<boost::_bi::value<vostok::sound::single_sound_cook *>,boost::arg<1>,boost::_bi::value<vostok::sound::sound_options>>>(
    &v34,
    &v35);
  callback.vtable = 0;
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::single_sound_cook,vostok::resources::queries_result &,vostok::sound::sound_options>,boost::_bi::list3<boost::_bi::value<vostok::sound::single_sound_cook *>,boost::arg<1>,boost::_bi::value<vostok::sound::sound_options>>>::bind_t<void,boost::_mfi::mf2<void,vostok::sound::single_sound_cook,vostok::resources::queries_result &,vostok::sound::sound_options>,boost::_bi::list3<boost::_bi::value<vostok::sound::single_sound_cook *>,boost::arg<1>,boost::_bi::value<vostok::sound::sound_options>>>(
    &v36,
    &v34);
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::single_sound_cook,vostok::resources::queries_result &,vostok::sound::sound_options>,boost::_bi::list3<boost::_bi::value<vostok::sound::single_sound_cook *>,boost::arg<1>,boost::_bi::value<vostok::sound::sound_options>>>::bind_t<void,boost::_mfi::mf2<void,vostok::sound::single_sound_cook,vostok::resources::queries_result &,vostok::sound::sound_options>,boost::_bi::list3<boost::_bi::value<vostok::sound::single_sound_cook *>,boost::arg<1>,boost::_bi::value<vostok::sound::sound_options>>>(
    (boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::single_sound_cook,vostok::resources::queries_result &,vostok::sound::sound_options>,boost::_bi::list3<boost::_bi::value<vostok::sound::single_sound_cook *>,boost::arg<1>,boost::_bi::value<vostok::sound::sound_options> > > *)&v24[4],
    &v36);
  *(_DWORD *)v24 = &callback.functor;
  callback.vtable = boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::single_sound_cook,vostok::resources::queries_result &,vostok::sound::sound_options>,boost::_bi::list3<boost::_bi::value<vostok::sound::single_sound_cook *>,boost::arg<1>,boost::_bi::value<vostok::sound::sound_options>>>>(
                      v22,
                      *(boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::single_sound_cook,vostok::resources::queries_result &,vostok::sound::sound_options>,boost::_bi::list3<boost::_bi::value<vostok::sound::single_sound_cook *>,boost::arg<1>,boost::_bi::value<vostok::sound::sound_options> > > *)v24,
                      *(boost::detail::function::function_buffer **)&v24[32]) != 0
                  ? (boost::detail::function::vtable_base *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::single_sound_cook,vostok::resources::queries_result &,vostok::sound::sound_options>,boost::_bi::list3<boost::_bi::value<vostok::sound::single_sound_cook *>,boost::arg<1>,boost::_bi::value<vostok::sound::sound_options>>>>'::`2'::stored_vtable
                  : 0;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v36.l_.a3_);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v34.l_.a3_);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v35.l_.a3_);
  vostok::resources::query_resources(
    &requests,
    2u,
    &vostok::memory::g_resources_unmanaged_allocator,
    0,
    (const vostok::variant<32> **)parent,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v23,
    (int *)&callback);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&__that);
}
