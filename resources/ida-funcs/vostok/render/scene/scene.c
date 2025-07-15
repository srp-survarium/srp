void __thiscall vostok::render::scene::scene(
        vostok::render::scene *this,
        vostok::render::scene_configuration *renderer_configuration,
        _BYTE *a3)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  _DWORD *v5; // eax
  char *v6; // ecx
  _DWORD *v7; // eax
  char *v8; // ecx
  _DWORD *v9; // eax
  char *v10; // ecx
  _DWORD *v11; // eax
  char *v12; // ecx
  _DWORD *v13; // eax
  char *v14; // ecx
  _DWORD *v15; // eax
  char *v16; // ecx
  _DWORD *v17; // eax
  char *v18; // ecx
  char *v19; // ecx
  vostok::render::batched_geometry<vostok::render::lpv_vertex> *v20; // ecx
  vostok::render::batched_geometry<vostok::render::shadow_vertex> *v21; // ecx
  _DWORD *v22; // eax
  _DWORD *v23; // eax
  char *v24; // ecx
  _DWORD *v25; // eax
  char *v26; // ecx
  _DWORD *v27; // eax
  char *v28; // ecx
  vostok::fixed_vector<vostok::resources::managed_resource *,10000>::allign_helper *v29; // eax
  char *v30; // ecx
  vostok::fixed_vector<vostok::resources::managed_resource *,10000>::allign_helper *v31; // eax
  char *v32; // ecx
  vostok::fixed_vector<vostok::resources::managed_resource *,10000>::allign_helper *v33; // eax
  char *v34; // ecx
  vostok::fixed_vector<vostok::resources::managed_resource *,10000>::allign_helper *v35; // eax
  char *v36; // ecx
  vostok::fixed_vector<vostok::resources::managed_resource *,10000>::allign_helper *v37; // eax
  char *v38; // ecx
  _DWORD *v39; // eax
  char *v40; // ecx
  bool v41; // zf
  const char *v42; // ecx
  _DWORD *v43; // eax
  char *v44; // eax
  char *v45; // ecx
  char *v46; // ecx
  char *v47; // esi
  int v48; // edx
  const char *v49; // ecx
  vostok::collision::space_partitioning_tree *v50; // eax
  vostok::memory::doug_lea_allocator *v51; // esi
  char *v52; // eax
  vostok::memory::doug_lea_allocator *v53; // ecx
  vostok::render::lights_db *v54; // ecx
  int v55; // eax
  int v56; // xmm0_4
  unsigned int v57; // [esp+0h] [ebp-50h]
  unsigned int v58; // [esp+0h] [ebp-50h]
  unsigned int v59; // [esp+0h] [ebp-50h]
  const char *v60; // [esp+0h] [ebp-50h]
  unsigned int v61; // [esp+4h] [ebp-4Ch]
  unsigned int v62; // [esp+4h] [ebp-4Ch]
  const char *v63; // [esp+4h] [ebp-4Ch]
  unsigned int v64; // [esp+8h] [ebp-48h]
  boost::function<void __cdecl(vostok::memory::single_size_buffer_allocator<36,vostok::threading::single_threading_policy> const &)> on_out_of_memory; // [esp+10h] [ebp-40h] BYREF
  int v66; // [esp+30h] [ebp-20h]
  struct btDiscreteCollisionDetectorInterface v67; // [esp+34h] [ebp-1Ch]
  struct btDiscreteCollisionDetectorInterface v68; // [esp+38h] [ebp-18h]
  struct btDiscreteCollisionDetectorInterface v69; // [esp+3Ch] [ebp-14h]
  int v70; // [esp+40h] [ebp-10h]
  int v71; // [esp+44h] [ebp-Ch]
  int v72; // [esp+48h] [ebp-8h]
  int v73; // [esp+4Ch] [ebp-4h]

  vostok::resources::unmanaged_resource::unmanaged_resource(this, renderer_configuration, fs_iterator_class);
  *(_DWORD *)renderer_configuration = &vostok::render::base_scene::`vftable';
  *(_DWORD *)&renderer_configuration[264] = 0;
  *(_DWORD *)&renderer_configuration[268] = 0;
  *(_DWORD *)&renderer_configuration[272] = 0;
  on_out_of_memory.vtable = 0;
  *(_DWORD *)&renderer_configuration[276] = -1;
  *(_DWORD *)renderer_configuration = &vostok::render::scene::`vftable';
  vostok::memory::single_size_buffer_allocator<36,vostok::threading::single_threading_policy>::single_size_buffer_allocator<36,vostok::threading::single_threading_policy>(
    &on_out_of_memory,
    (vostok::memory::single_size_buffer_allocator<36,vostok::threading::single_threading_policy> *)&renderer_configuration[280],
    (vostok::memory::single_size_buffer_allocator<36,vostok::threading::single_threading_policy>::node *)&renderer_configuration[328],
    v57);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v4,
    (int *)&on_out_of_memory);
  v5 = (_DWORD *)((char *)&loc_90148 + (_DWORD)renderer_configuration);
  v6 = (char *)&loc_90148 + (_DWORD)renderer_configuration + 12;
  *v5 = v6;
  v5[1] = v6;
  v5[2] = (char *)&loc_90148 + (_DWORD)renderer_configuration + 24588;
  v7 = (int *)((char *)&dword_96154 + (_DWORD)renderer_configuration);
  v8 = (char *)&dword_96154 + (_DWORD)renderer_configuration + 12;
  *v7 = v8;
  v7[1] = v8;
  v7[2] = (char *)&loc_52000 + (_DWORD)v8;
  v9 = (int *)((char *)&dword_E8160 + (_DWORD)renderer_configuration);
  v10 = (char *)&dword_E8160 + (_DWORD)renderer_configuration + 12;
  *v9 = v10;
  v9[1] = v10;
  v9[2] = (char *)&dword_E8160 + (_DWORD)renderer_configuration + 286732;
  v11 = (_DWORD *)((char *)&loc_12E16C + (_DWORD)renderer_configuration);
  v12 = (char *)&loc_12E16C + (_DWORD)renderer_configuration + 12;
  *v11 = v12;
  v11[1] = v12;
  v11[2] = (char *)&loc_12E16C + (_DWORD)renderer_configuration + 589836;
  *((_BYTE *)&loc_1BE178 + (_DWORD)renderer_configuration) = 0;
  v13 = (_DWORD *)((char *)&loc_1BE17C + (_DWORD)renderer_configuration);
  v14 = (char *)&loc_1BE17C + (_DWORD)renderer_configuration + 12;
  *v13 = v14;
  v13[1] = v14;
  v13[2] = (char *)&loc_1BE17C + (_DWORD)renderer_configuration + 32780;
  v15 = (_DWORD *)((char *)&loc_1C6188 + (_DWORD)renderer_configuration);
  v16 = (char *)&loc_1C6188 + (_DWORD)renderer_configuration + 12;
  *v15 = v16;
  v15[1] = v16;
  v15[2] = (char *)&loc_1C6188 + (_DWORD)renderer_configuration + 16396;
  v17 = (int *)((char *)&dword_1CA194 + (_DWORD)renderer_configuration);
  v18 = (char *)&dword_1CA194 + (_DWORD)renderer_configuration + 12;
  *v17 = v18;
  v17[1] = v18;
  v17[2] = (char *)&dword_1CA194 + (_DWORD)renderer_configuration + 16396;
  v70 = 0;
  v71 = 0;
  v72 = 0;
  v73 = 0;
  v19 = (char *)survarium::weapon_user_animations_selector::stand_from_crouch_predicate + (_DWORD)renderer_configuration;
  *(_DWORD *)((char *)survarium::weapon_user_animations_selector::stand_from_crouch_predicate
            + (_DWORD)renderer_configuration) = 0;
  *(_DWORD *)((char *)survarium::weapon_user_animations_selector::stand_from_crouch_predicate
            + (_DWORD)renderer_configuration
            + 4) = v71;
  *(_DWORD *)((char *)survarium::weapon_user_animations_selector::stand_from_crouch_predicate
            + (_DWORD)renderer_configuration
            + 8) = v72;
  *(_DWORD *)((char *)survarium::weapon_user_animations_selector::stand_from_crouch_predicate
            + (_DWORD)renderer_configuration
            + 12) = v73;
  *v19 = 0;
  v19[20] = HIBYTE(renderer_configuration);
  *((_DWORD *)v19 + 1) = 0;
  *((_DWORD *)v19 + 2) = v19;
  *((_DWORD *)v19 + 3) = v19;
  *((_DWORD *)v19 + 4) = 0;
  vostok::tasks::task::task(
    (vostok::tasks::task *)((char *)survarium::weapon_user_animations_selector::stand_from_crouch_predicate
                          + (_DWORD)renderer_configuration),
    &renderer_configuration[(_DWORD)&loc_1CE1B5 + 3]);
  vostok::render::batched_geometry<vostok::render::lpv_vertex>::batched_geometry<vostok::render::lpv_vertex>(
    v20,
    (vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&renderer_configuration[(_DWORD)&loc_1CE217 + 1],
    (const D3D11_INPUT_ELEMENT_DESC *)3,
    v58,
    v61);
  *(_DWORD *)&renderer_configuration[(_DWORD)&loc_1CE217 + 1] = &vostok::render::lpv_batched_geometry::`vftable';
  vostok::render::batched_geometry<vostok::render::shadow_vertex>::batched_geometry<vostok::render::shadow_vertex>(
    v21,
    (int)&loc_330B64 + (_DWORD)renderer_configuration,
    (const D3D11_INPUT_ELEMENT_DESC *)3,
    v59,
    v62);
  *(_DWORD *)((char *)&loc_330B64 + (_DWORD)renderer_configuration) = &vostok::render::shadow_batched_geometry::`vftable';
  v22 = (_DWORD *)((char *)&loc_5534B0 + (_DWORD)renderer_configuration);
  *v22 = &vostok::render::scene::particle_engine::`vftable';
  v22[2] = renderer_configuration;
  v23 = (_DWORD *)((char *)&loc_5534BC + (_DWORD)renderer_configuration);
  v24 = (char *)&loc_5534BC + (_DWORD)renderer_configuration + 12;
  *v23 = v24;
  v23[1] = v24;
  v23[2] = (char *)&loc_100000 + (_DWORD)v24;
  v25 = (_DWORD *)((char *)&loc_6534C8 + (_DWORD)renderer_configuration);
  v26 = (char *)&loc_6534C8 + (_DWORD)renderer_configuration + 12;
  *v25 = v26;
  v25[1] = v26;
  v25[2] = (char *)&loc_A0000 + (_DWORD)v26;
  v27 = (_UNKNOWN **)((char *)&off_6F34D4 + (_DWORD)renderer_configuration);
  v28 = (char *)&off_6F34D4 + (_DWORD)renderer_configuration + 12;
  *v27 = v28;
  v27[1] = v28;
  v27[2] = (char *)&loc_100000 + (_DWORD)v28;
  *(_DWORD *)&renderer_configuration[8336608] = renderer_configuration + 8336620;
  *(_DWORD *)&renderer_configuration[8336612] = renderer_configuration + 8336620;
  *(_DWORD *)&renderer_configuration[8336616] = (char *)&loc_A0000 + (_DWORD)(renderer_configuration + 8336620);
  v29 = (vostok::fixed_vector<vostok::resources::managed_resource *,10000>::allign_helper *)((char *)&vostok::memory::s_resources.m_buffer[4182]
                                                                                           + (_DWORD)renderer_configuration);
  v30 = (char *)&vostok::memory::s_resources.m_buffer[4185] + (_DWORD)renderer_configuration;
  *v29 = (vostok::fixed_vector<vostok::resources::managed_resource *,10000>::allign_helper)v30;
  v29[1] = (vostok::fixed_vector<vostok::resources::managed_resource *,10000>::allign_helper)v30;
  v29[2] = (vostok::fixed_vector<vostok::resources::managed_resource *,10000>::allign_helper)((char *)&vostok::memory::s_resources.m_buffer[6233]
                                                                                            + (_DWORD)renderer_configuration);
  v31 = (vostok::fixed_vector<vostok::resources::managed_resource *,10000>::allign_helper *)((char *)&vostok::memory::s_resources.m_buffer[6233]
                                                                                           + (_DWORD)renderer_configuration);
  v32 = (char *)&vostok::memory::s_resources.m_buffer[6236] + (_DWORD)renderer_configuration;
  *v31 = (vostok::fixed_vector<vostok::resources::managed_resource *,10000>::allign_helper)v32;
  v31[1] = (vostok::fixed_vector<vostok::resources::managed_resource *,10000>::allign_helper)v32;
  v31[2] = (vostok::fixed_vector<vostok::resources::managed_resource *,10000>::allign_helper)((char *)&vostok::memory::s_resources.m_buffer[7260]
                                                                                            + (_DWORD)renderer_configuration);
  v33 = (vostok::fixed_vector<vostok::resources::managed_resource *,10000>::allign_helper *)((char *)&vostok::memory::s_resources.m_buffer[7260]
                                                                                           + (_DWORD)renderer_configuration);
  v34 = (char *)&vostok::memory::s_resources.m_buffer[7263] + (_DWORD)renderer_configuration;
  *v33 = (vostok::fixed_vector<vostok::resources::managed_resource *,10000>::allign_helper)v34;
  v33[1] = (vostok::fixed_vector<vostok::resources::managed_resource *,10000>::allign_helper)v34;
  v33[2] = (vostok::fixed_vector<vostok::resources::managed_resource *,10000>::allign_helper)((char *)&vostok::memory::s_resources.m_buffer[8287]
                                                                                            + (_DWORD)renderer_configuration);
  v35 = (vostok::fixed_vector<vostok::resources::managed_resource *,10000>::allign_helper *)((char *)&vostok::memory::s_resources.m_buffer[8287]
                                                                                           + (_DWORD)renderer_configuration);
  v36 = (char *)&vostok::memory::s_resources.m_buffer[8290] + (_DWORD)renderer_configuration;
  *v35 = (vostok::fixed_vector<vostok::resources::managed_resource *,10000>::allign_helper)v36;
  v35[1] = (vostok::fixed_vector<vostok::resources::managed_resource *,10000>::allign_helper)v36;
  v35[2] = (vostok::fixed_vector<vostok::resources::managed_resource *,10000>::allign_helper)((char *)&vostok::memory::s_resources.m_buffer[9314]
                                                                                            + (_DWORD)renderer_configuration);
  v37 = (vostok::fixed_vector<vostok::resources::managed_resource *,10000>::allign_helper *)((char *)&vostok::memory::s_resources.m_buffer[9314]
                                                                                           + (_DWORD)renderer_configuration);
  v38 = (char *)&vostok::memory::s_resources.m_buffer[9317] + (_DWORD)renderer_configuration;
  *v37 = (vostok::fixed_vector<vostok::resources::managed_resource *,10000>::allign_helper)v38;
  v37[1] = (vostok::fixed_vector<vostok::resources::managed_resource *,10000>::allign_helper)v38;
  v37[2] = (vostok::fixed_vector<vostok::resources::managed_resource *,10000>::allign_helper)((char *)&vostok::memory::s_resources
                                                                                            + (_DWORD)renderer_configuration
                                                                                            + 41376);
  v39 = (_DWORD *)((int)&SNaN_33 + (_DWORD)renderer_configuration);
  v40 = (char *)&SNaN_33 + (_DWORD)renderer_configuration + 12;
  *v39 = v40;
  v39[1] = v40;
  v41 = !help_bool;
  v39[2] = (char *)&SNaN_33 + (_DWORD)renderer_configuration + 4108;
  v42 = "screen_factors_task_0";
  if ( v41 )
    v42 = "screen_factors_task_1";
  *(_DWORD *)&renderer_configuration[9020724] = vostok::tasks::create_new_task_type(
                                                  v42,
                                                  (vostok::enum_flags<enum vostok::tasks::task_type_flags_enum>)1);
  *(_DWORD *)&renderer_configuration[9020728] = renderer_configuration + 9020740;
  *(_DWORD *)&renderer_configuration[9020732] = renderer_configuration + 9020740;
  *(_DWORD *)&renderer_configuration[9020736] = (char *)&loc_1C000 + (_DWORD)(renderer_configuration + 9020740);
  v43 = (int *)((char *)&dword_8B6544 + (_DWORD)renderer_configuration);
  *v43 = 0;
  v43[2] = 0;
  v43[3] = 0;
  v44 = &aAvbtcollisionw[(_DWORD)renderer_configuration + 4];
  v45 = &aAvbtcollisionw[(_DWORD)renderer_configuration + 16];
  *(_DWORD *)v44 = v45;
  *((_DWORD *)v44 + 1) = v45;
  *((_DWORD *)v44 + 2) = &aAvbtcollisionw[(_DWORD)renderer_configuration + 4112];
  v66 = 0;
  v67.__vftable = 0;
  v68.__vftable = 0;
  v46 = (char *)&btDiscreteCollisionDetectorInterface `RTTI Type Descriptor' + (_DWORD)renderer_configuration;
  v69.__vftable = 0;
  *(btDiscreteCollisionDetectorInterface_vtbl **)((char *)&btDiscreteCollisionDetectorInterface `RTTI Type Descriptor'.__vftable
                                                + (_DWORD)renderer_configuration) = 0;
  *(struct btDiscreteCollisionDetectorInterface *)((char *)&btDiscreteCollisionDetectorInterface `RTTI Type Descriptor'
                                                 + (_DWORD)renderer_configuration
                                                 + 4) = v67;
  *(struct btDiscreteCollisionDetectorInterface *)((char *)&btDiscreteCollisionDetectorInterface `RTTI Type Descriptor'
                                                 + (_DWORD)renderer_configuration
                                                 + 8) = v68;
  *(struct btDiscreteCollisionDetectorInterface *)((char *)&btDiscreteCollisionDetectorInterface `RTTI Type Descriptor'
                                                 + (_DWORD)renderer_configuration
                                                 + 12) = v69;
  v46[20] = HIBYTE(renderer_configuration);
  *v46 = 0;
  *((_DWORD *)v46 + 2) = v46;
  *((_DWORD *)v46 + 3) = v46;
  *((_DWORD *)v46 + 1) = 0;
  *((_DWORD *)v46 + 4) = 0;
  *(_DWORD *)&renderer_configuration[9139576] = renderer_configuration + 9139588;
  *(_DWORD *)&renderer_configuration[9139580] = renderer_configuration + 9139588;
  *(_DWORD *)&renderer_configuration[9139584] = renderer_configuration + 9147780;
  v47 = (char *)&unk_8B9588 + (_DWORD)renderer_configuration;
  vostok::tasks::task::task(
    (vostok::tasks::task *)&renderer_configuration[9147780],
    (char *)&unk_8B9588 + (_DWORD)renderer_configuration);
  v41 = !help_value;
  *(_DWORD *)((char *)&unk_8B9588 + (_DWORD)renderer_configuration + 160) = v48;
  v49 = "wanted_mips_task_0";
  if ( v41 )
    v49 = "wanted_mips_task_1";
  *((_DWORD *)v47 + 42) = vostok::tasks::create_new_task_type(
                            v49,
                            (vostok::enum_flags<enum vostok::tasks::task_type_flags_enum>)1);
  *((_DWORD *)v47 + 43) = 0;
  v47[196] = 0;
  help_value = 1;
  *(int *)((char *)&dword_8B9650 + (_DWORD)renderer_configuration) = (int)vostok::render::new_tree();
  *(int *)((char *)&dword_8B9654 + (_DWORD)renderer_configuration) = (int)vostok::render::new_tree();
  *(int *)((char *)&dword_8B9658 + (_DWORD)renderer_configuration) = (int)vostok::render::new_tree();
  v50 = vostok::render::new_tree();
  v51 = vostok::render::g_allocator;
  *(int *)((char *)&dword_8B965C + (_DWORD)renderer_configuration) = (int)v50;
  v52 = type_info::raw_name(&vostok::render::lights_db `RTTI Type Descriptor');
  if ( vostok::memory::doug_lea_allocator::malloc_impl(v53, (int)v51, 0x2014u, v52, v60, v63, v64) )
    vostok::render::lights_db::lights_db(v54);
  else
    v55 = 0;
  v56 = LODWORD(s_bm_current_air_resistance);
  *(int *)((char *)&dword_8B9660 + (_DWORD)renderer_configuration) = v55;
  *(int *)((char *)&dword_8B9664 + (_DWORD)renderer_configuration) = 0;
  *(int *)((char *)&dword_8B9668 + (_DWORD)renderer_configuration) = 0;
  *(int *)((char *)&dword_8B966C + (_DWORD)renderer_configuration) = 0;
  *(int *)((char *)&dword_8B9670 + (_DWORD)renderer_configuration) = 0;
  *(int *)((char *)&dword_8B9674 + (_DWORD)renderer_configuration) = v56;
  byte_8B9679[(_DWORD)renderer_configuration] = (*a3 & 8) != 0;
  byte_8B967A[(_DWORD)renderer_configuration] = (*a3 & 0x10) != 0;
  v41 = !help_bool;
  byte_8B967B[(_DWORD)renderer_configuration] = (*a3 & 0x20) != 0;
  help_bool = v41;
}
