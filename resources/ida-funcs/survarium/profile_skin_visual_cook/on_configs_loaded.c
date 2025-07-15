void __thiscall survarium::profile_skin_visual_cook::on_configs_loaded(
        survarium::profile_skin_visual_cook *this,
        vostok::resources::queries_result *data,
        const vostok::variant<32> **parent,
        const survarium::player_profile *profile)
{
  vostok::memory::doug_lea_allocator *v4; // esi
  char *v5; // eax
  vostok::memory::doug_lea_allocator *v6; // ecx
  char *v7; // eax
  vostok::render::skeleton_combined_cook_data *v8; // ecx
  vostok::particle::particle_system_instance_impl *v9; // eax
  vostok::particle::particle_system_instance_impl *m_object; // esi
  const vostok::configs::binary_config_value *v11; // eax
  vostok::particle::particle_system_instance_impl *v12; // ebx
  bool m_inlined_in_fat; // al
  vostok::buffer_string *v14; // esi
  vostok::configs::binary_config_value *v15; // eax
  char *pointer; // edx
  char *m_begin; // eax
  char *v18; // edx
  char *v19; // eax
  char *v20; // edx
  vostok::particle::particle_system_instance_impl_vtbl *v21; // eax
  char *v22; // edx
  vostok::particle::particle_emitter_instance *m_last; // eax
  survarium::pure_game_effect_emitter_base *v24; // eax
  char *type; // edi
  vostok::buffer_string *v26; // esi
  bool v27; // zf
  const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *v28; // eax
  vostok::particle::particle_system_instance_impl *v29; // esi
  char *v30; // edi
  vostok::configs::binary_config_value *v31; // eax
  vostok::buffer_string *v32; // ecx
  vostok::configs::binary_config_value *v33; // ecx
  char *v34; // edx
  char *v35; // eax
  char *v36; // edi
  vostok::buffer_string *v37; // ecx
  vostok::configs::binary_config_value *v38; // eax
  char *v39; // edx
  char *v40; // eax
  char *v41; // edx
  char *v42; // eax
  vostok::configs::binary_config_value *v43; // ecx
  char *v44; // edx
  vostok::buffer_string *v45; // esi
  char *v46; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v47; // ecx
  vostok::variant<32> *v48; // ecx
  vostok::configs::binary_config_value *v49; // [esp-4h] [ebp-1C4h]
  const char *v50; // [esp+0h] [ebp-1C0h]
  const char *v51; // [esp+4h] [ebp-1BCh]
  unsigned int v52; // [esp+8h] [ebp-1B8h]
  char v53; // [esp+Ch] [ebp-1B4h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v54; // [esp+10h] [ebp-1B0h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v55; // [esp+14h] [ebp-1ACh] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v56; // [esp+18h] [ebp-1A8h] BYREF
  vostok::resources::query_result *v57; // [esp+1Ch] [ebp-1A4h]
  vostok::configs::binary_config_value v58; // [esp+20h] [ebp-1A0h] BYREF
  int v59; // [esp+38h] [ebp-188h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v60; // [esp+3Ch] [ebp-184h] BYREF
  const char *v61; // [esp+40h] [ebp-180h]
  const char *v62; // [esp+44h] [ebp-17Ch]
  void *v63; // [esp+48h] [ebp-178h]
  const vostok::variant<32> **v64; // [esp+4Ch] [ebp-174h]
  vostok::particle::particle_system_instance_impl *v65; // [esp+50h] [ebp-170h]
  survarium::profile_skin_visual_cook *v66; // [esp+54h] [ebp-16Ch]
  vostok::buffer_string *v67; // [esp+58h] [ebp-168h]
  survarium::inventory_item_descr *v68; // [esp+5Ch] [ebp-164h]
  _BYTE v69[32]; // [esp+60h] [ebp-160h] BYREF
  vostok::variant<32> v70; // [esp+80h] [ebp-140h] BYREF
  const char *v71[3]; // [esp+B0h] [ebp-110h] BYREF
  _BYTE v72[260]; // [esp+BCh] [ebp-104h] BYREF
  char vars0; // [esp+1C0h] [ebp+0h] BYREF

  v4 = survarium::g_allocator;
  v66 = this;
  v5 = type_info::raw_name(&vostok::render::skeleton_combined_cook_data `RTTI Type Descriptor');
  v7 = vostok::memory::doug_lea_allocator::malloc_impl(v6, (int)v4, 0x1C98u, v5, v50, v51, v52);
  if ( v7 )
  {
    vostok::render::skeleton_combined_cook_data::skeleton_combined_cook_data(v8, (int)v7, 0);
    v54.m_object = v9;
  }
  else
  {
    v54.m_object = 0;
  }
  v70.m_helper = 0;
  v70.m_type_id = 0;
  vostok::variant<32>::set<vostok::render::skeleton_combined_cook_data *>(
    (vostok::variant<32> *)v8,
    &v70,
    (vostok::render::skeleton_combined_cook_data **)&v54);
  v71[0] = v72;
  v71[1] = v72;
  v71[2] = &vars0;
  v72[0] = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v55,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
  m_object = (vostok::particle::particle_system_instance_impl *)v55.m_object;
  v56.m_object = 0;
  if ( v55.m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v56);
    v56.m_object = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v55);
  v11 = vostok::configs::binary_config_value::operator[](
          (vostok::configs::binary_config_value *)v56.m_object->m_lods[0].m_template.m_object,
          "body_parts");
  v12 = v54.m_object;
  qmemcpy(v69, v11, 0x18u);
  v61 = "data";
  v62 = "data";
  v54.m_object[9].m_inlined_in_fat = 0;
  vostok::configs::binary_config_value::binary_config_value(0, (int)&v58);
  m_inlined_in_fat = v12[9].m_inlined_in_fat;
  v12[9].m_inlined_in_fat = m_inlined_in_fat + 1;
  v14 = (vostok::buffer_string *)(&v12->m_lods[9].m_emitter_instance_list.m_first + 211 * m_inlined_in_fat);
  v15 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)v69, "head");
  vostok::configs::binary_config_value::operator=(v15, &v58);
  pointer = (char *)vostok::configs::binary_config_value::operator[](&v58, "base_model")->data.pointer;
  m_begin = v14->m_begin;
  v14->m_end = v14->m_begin;
  *m_begin = 0;
  vostok::buffer_string::operator+=(v14, pointer);
  v18 = (char *)vostok::configs::binary_config_value::operator[](&v58, "part_name")->data.pointer;
  v14 += 23;
  v19 = v14->m_begin;
  v14->m_end = v14->m_begin;
  *v19 = 0;
  vostok::buffer_string::operator+=(v14, v18);
  v20 = (char *)vostok::configs::binary_config_value::operator[](
                  (vostok::configs::binary_config_value *)v69,
                  "skeleton")->data.pointer;
  v21 = v12->__vftable;
  v12->type = (unsigned int)v12->__vftable;
  LOBYTE(v21->~vostok::particle::particle_system_instance) = 0;
  vostok::buffer_string::operator+=((vostok::buffer_string *)v12, v20);
  v22 = (char *)vostok::configs::binary_config_value::operator[](
                  (vostok::configs::binary_config_value *)v69,
                  "bind_pose")->data.pointer;
  m_last = v12->m_lods[0].m_emitter_instance_list.m_last;
  LODWORD(v12->m_lods[0].m_distance) = m_last;
  LOBYTE(m_last->__vftable) = 0;
  vostok::buffer_string::operator+=((vostok::buffer_string *)&v12->m_lods[0].m_emitter_instance_list.m_last, v22);
  v24 = (survarium::pure_game_effect_emitter_base *)body_parts;
  v55.m_object = (survarium::pure_game_effect_emitter_base *)body_parts;
  v57 = &data->m_queries[1];
  v59 = 7;
  while ( 1 )
  {
    type = (char *)v24->type;
    v26 = (vostok::buffer_string *)(&v12->m_lods[9].m_emitter_instance_list.m_first + 211 * v12[9].m_inlined_in_fat);
    v63 = v24->__vftable;
    v27 = profile->slots[(_DWORD)v63].id == 0;
    v68 = &profile->slots[(_DWORD)v63];
    v67 = v26;
    v53 = 0;
    if ( v27 )
    {
      if ( vostok::configs::binary_config_value::value_exists(
             (vostok::configs::binary_config_value *)(16 * (_DWORD)v63),
             (int)v69,
             (unsigned int)type) )
      {
        v38 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)v69, type);
        vostok::configs::binary_config_value::operator=(v38, &v58);
        v53 = 1;
      }
      vostok::buffer_string::appendf(v71, v37, (vostok::buffer_string *)"%d_", 0);
    }
    else
    {
      v28 = (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)v57++;
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        &v60,
        v28 + 55);
      v29 = (vostok::particle::particle_system_instance_impl *)v60.m_object;
      v54.m_object = 0;
      if ( v60.m_object )
      {
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v54);
        v54.m_object = v29;
        _InterlockedExchangeAdd(&v29->m_reference_count, 1u);
      }
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v60);
      if ( v63 == (void *)2 )
      {
        v30 = (char *)v62;
      }
      else
      {
        v30 = (char *)v61;
        if ( v63 != (void *)4 )
          v30 = "data";
      }
      v31 = vostok::configs::binary_config_value::operator[](
              (vostok::configs::binary_config_value *)v54.m_object->m_lods[0].m_template.m_object,
              v30);
      vostok::configs::binary_config_value::operator=(v31, &v58);
      v53 = 1;
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v54);
      v26 = v67;
      vostok::buffer_string::appendf(v71, v32, (vostok::buffer_string *)"%d_", (const char *)v68->dict_id);
    }
    if ( v53 )
    {
      if ( vostok::configs::binary_config_value::value_exists(v49, (int)&v58, (unsigned int)"base_model_hud")
        && vostok::configs::binary_config_value::value_exists(v33, (int)&v58, (unsigned int)"part_name_hud") )
      {
        v34 = (char *)vostok::configs::binary_config_value::operator[](&v58, "base_model_hud")->data.pointer;
        v35 = v26->m_begin;
        v26->m_end = v26->m_begin;
        *v35 = 0;
        vostok::buffer_string::operator+=(v26, v34);
        v36 = "part_name_hud";
      }
      else
      {
        if ( !vostok::configs::binary_config_value::value_exists(v33, (int)&v58, (unsigned int)"base_model") )
          goto LABEL_32;
        v39 = (char *)vostok::configs::binary_config_value::operator[](&v58, "base_model")->data.pointer;
        v40 = v26->m_begin;
        v26->m_end = v26->m_begin;
        *v40 = 0;
        vostok::buffer_string::operator+=(v26, v39);
        v36 = "part_name";
      }
      v41 = (char *)vostok::configs::binary_config_value::operator[](&v58, v36)->data.pointer;
      v42 = v26[23].m_begin;
      v26[23].m_end = v42;
      *v42 = 0;
      vostok::buffer_string::operator+=(v26 + 23, v41);
      if ( vostok::configs::binary_config_value::value_exists(v43, (int)&v58, (unsigned int)"material") )
      {
        v44 = (char *)vostok::configs::binary_config_value::operator[](&v58, "material")->data.pointer;
        v45 = v26 + 46;
        v46 = v45->m_begin;
        v45->m_end = v45->m_begin;
        *v46 = 0;
        vostok::buffer_string::operator+=(v45, v44);
      }
      if ( v63 == (void *)5 )
        v62 = (const char *)vostok::configs::binary_config_value::operator[](&v58, "model_type")->data.pointer;
      if ( v63 == (void *)6 )
        v61 = (const char *)vostok::configs::binary_config_value::operator[](&v58, "model_type")->data.pointer;
      ++v12[9].m_inlined_in_fat;
    }
LABEL_32:
    v55.m_object = (survarium::pure_game_effect_emitter_base *)((char *)v55.m_object + 8);
    if ( !--v59 )
      break;
    v24 = v55.m_object;
  }
  v63 = v66;
  *(_DWORD *)&v69[4] = 0;
  *(_DWORD *)v69 = survarium::profile_skin_visual_cook::on_visual_loaded;
  v64 = parent;
  v65 = v12;
  *(_DWORD *)&v69[8] = v66;
  *(_DWORD *)&v69[12] = parent;
  *(_DWORD *)&v69[16] = v12;
  qmemcpy((void *)&v58, v69, sizeof(v58));
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    *(_DWORD *)v69 = 0;
  }
  else
  {
    qmemcpy(&v69[8], &v58, 0x18u);
    *(_DWORD *)v69 = (char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::profile_skin_visual_cook,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *,vostok::render::skeleton_combined_cook_data *>,boost::_bi::list4<boost::_bi::value<survarium::profile_skin_visual_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *>,boost::_bi::value<vostok::render::skeleton_combined_cook_data *>>>>'::`2'::stored_vtable
                   + 1;
  }
  vostok::resources::query_resource(
    v71[0],
    (vostok::variant<32> *)0x12,
    survarium::g_allocator,
    &v70,
    parent,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v47,
    (int *)v69);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v56);
  vostok::variant<32>::destroy_previous_variable_if_needed(v48, (int)&v70);
}
