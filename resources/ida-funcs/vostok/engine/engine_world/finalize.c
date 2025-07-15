void __thiscall __noreturn vostok::engine::engine_world::finalize(vostok::engine::engine_world *this, unsigned int a2)
{
  boost::function<void __cdecl(char const *)> *v2; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  boost::function<void __cdecl(char const *)> *v4; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  boost::function<void __cdecl(char const *)> *v6; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v7; // ecx
  boost::function<void __cdecl(char const *)> *v8; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v9; // ecx
  vostok::render::one_way_render_channel *v10; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v11; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v12; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v13; // ecx
  vostok::render::world *v14; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v15; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v16; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v17; // ecx
  boost::function<void __cdecl(char const *)> *v18; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v19; // ecx
  boost::function<void __cdecl(char const *)> *v20; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v21; // ecx
  boost::function<void __cdecl(char const *)> *v22; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v23; // ecx
  boost::function<void __cdecl(char const *)> *v24; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v25; // ecx
  vostok::resources::resources_manager *v26; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v27; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v28; // ecx
  boost::function<void __cdecl(void)> *v29; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v30; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v31; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v32; // ecx
  boost::function<void __cdecl(void)> *v33; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v34; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v35; // ecx
  boost::function<void __cdecl(void)> *v36; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v37; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v38; // ecx
  boost::function<void __cdecl(void)> *v39; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v40; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v41; // ecx
  boost::function<void __cdecl(void)> *v42; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v43; // ecx
  boost::function<void __cdecl(char const *)> *v44; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v45; // ecx
  vostok::resources::resources_manager *v46; // ecx
  vostok::render::world *v47; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::engine::engine_world>,boost::_bi::list1<boost::_bi::value<vostok::engine::engine_world *> > > v48; // [esp-14h] [ebp-64Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::engine::engine_world>,boost::_bi::list1<boost::_bi::value<vostok::engine::engine_world *> > > v49; // [esp-14h] [ebp-64Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::engine::engine_world>,boost::_bi::list1<boost::_bi::value<vostok::engine::engine_world *> > > v50; // [esp-14h] [ebp-64Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::engine::engine_world>,boost::_bi::list1<boost::_bi::value<vostok::engine::engine_world *> > > v51; // [esp-14h] [ebp-64Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::engine::engine_world>,boost::_bi::list1<boost::_bi::value<vostok::engine::engine_world *> > > v52; // [esp-14h] [ebp-64Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::engine::engine_world>,boost::_bi::list1<boost::_bi::value<vostok::engine::engine_world *> > > v53; // [esp-14h] [ebp-64Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::engine::engine_world>,boost::_bi::list1<boost::_bi::value<vostok::engine::engine_world *> > > v54; // [esp-14h] [ebp-64Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::engine::engine_world>,boost::_bi::list1<boost::_bi::value<vostok::engine::engine_world *> > > v55; // [esp-14h] [ebp-64Ch]
  boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> v56; // [esp-8h] [ebp-640h]
  boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> v57; // [esp-8h] [ebp-640h]
  boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> v58; // [esp-8h] [ebp-640h]
  boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> v59; // [esp-8h] [ebp-640h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::world>,boost::_bi::list1<boost::_bi::value<vostok::sound::world *> > > v60; // [esp-8h] [ebp-640h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::render::one_way_render_channel>,boost::_bi::list1<boost::_bi::value<vostok::render::one_way_render_channel *> > > v61; // [esp-8h] [ebp-640h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::world_user>,boost::_bi::list1<boost::_bi::value<vostok::sound::world_user *> > > v62; // [esp-8h] [ebp-640h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::world>,boost::_bi::list1<boost::_bi::value<vostok::network::world *> > > v63; // [esp-8h] [ebp-640h]
  boost::_bi::bind_t<void,void (__cdecl*)(vostok::network::world * &),boost::_bi::list1<boost::_bi::value<vostok::network::world *> > > v64; // [esp-8h] [ebp-640h]
  boost::_bi::bind_t<void,void (__cdecl*)(vostok::sound::world * &),boost::_bi::list1<boost::_bi::value<vostok::sound::world *> > > v65; // [esp-8h] [ebp-640h]
  HWND v66; // [esp-8h] [ebp-640h]
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v67; // [esp-4h] [ebp-63Ch]
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v68; // [esp-4h] [ebp-63Ch]
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v69; // [esp-4h] [ebp-63Ch]
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v70; // [esp-4h] [ebp-63Ch]
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v71; // [esp-4h] [ebp-63Ch]
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v72; // [esp-4h] [ebp-63Ch]
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v73; // [esp-4h] [ebp-63Ch]
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v74; // [esp-4h] [ebp-63Ch]
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v75; // [esp-4h] [ebp-63Ch]
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v76; // [esp-4h] [ebp-63Ch]
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v77; // [esp-4h] [ebp-63Ch]
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v78; // [esp-4h] [ebp-63Ch]
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v79; // [esp-4h] [ebp-63Ch]
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v80; // [esp-4h] [ebp-63Ch]
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v81; // [esp-4h] [ebp-63Ch]
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v82; // [esp-4h] [ebp-63Ch]
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v83; // [esp-4h] [ebp-63Ch]
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v84; // [esp-4h] [ebp-63Ch]
  int v85; // [esp+0h] [ebp-638h]
  int v86; // [esp+0h] [ebp-638h]
  int v87; // [esp+0h] [ebp-638h]
  int v88; // [esp+0h] [ebp-638h]
  int v89; // [esp+0h] [ebp-638h]
  int v90; // [esp+0h] [ebp-638h]
  int v91; // [esp+0h] [ebp-638h]
  int v92; // [esp+0h] [ebp-638h]
  int v93; // [esp+0h] [ebp-638h]
  int v94; // [esp+0h] [ebp-638h]
  int v95; // [esp+0h] [ebp-638h]
  int v96; // [esp+0h] [ebp-638h]
  int v97; // [esp+0h] [ebp-638h]
  int v98; // [esp+0h] [ebp-638h]
  int v99; // [esp+0h] [ebp-638h]
  int v100; // [esp+0h] [ebp-638h]
  int v101; // [esp+0h] [ebp-638h]
  int v102; // [esp+0h] [ebp-638h]
  int v103; // [esp+0h] [ebp-638h]
  int v104; // [esp+0h] [ebp-638h]
  bool v105; // [esp+Fh] [ebp-629h]
  int v106; // [esp+14h] [ebp-624h]
  int v107; // [esp+1Ch] [ebp-61Ch]
  boost::function<void __cdecl(void)> v108; // [esp+98h] [ebp-5A0h] BYREF
  boost::function<void __cdecl(void)> v109; // [esp+B8h] [ebp-580h] BYREF
  boost::function<void __cdecl(void)> v110; // [esp+D8h] [ebp-560h] BYREF
  boost::function<void __cdecl(void)> v111; // [esp+F8h] [ebp-540h] BYREF
  boost::function<void __cdecl(void)> v112; // [esp+118h] [ebp-520h] BYREF
  boost::function<void __cdecl(void)> process_callback; // [esp+138h] [ebp-500h] BYREF
  boost::function<void __cdecl(void)> v114; // [esp+158h] [ebp-4E0h] BYREF
  boost::function<void __cdecl(void)> v115; // [esp+178h] [ebp-4C0h] BYREF
  boost::function<void __cdecl(void)> v116; // [esp+198h] [ebp-4A0h] BYREF
  boost::function<void __cdecl(void)> v117; // [esp+1B8h] [ebp-480h] BYREF
  boost::function<void __cdecl(void)> v118; // [esp+1D8h] [ebp-460h] BYREF
  boost::function<void __cdecl(void)> v119; // [esp+1F8h] [ebp-440h] BYREF
  boost::function<void __cdecl(void)> v120; // [esp+218h] [ebp-420h] BYREF
  boost::function<void __cdecl(void)> v121; // [esp+238h] [ebp-400h] BYREF
  boost::function<void __cdecl(void)> v122; // [esp+258h] [ebp-3E0h] BYREF
  boost::function<void __cdecl(void)> v123; // [esp+278h] [ebp-3C0h] BYREF
  boost::function<void __cdecl(void)> v124; // [esp+298h] [ebp-3A0h] BYREF
  boost::function<void __cdecl(void)> v125; // [esp+2B8h] [ebp-380h] BYREF
  boost::function<void __cdecl(void)> v126; // [esp+2D8h] [ebp-360h] BYREF
  boost::function<void __cdecl(void)> v127; // [esp+2F8h] [ebp-340h] BYREF
  boost::function<void __cdecl(void)> v128; // [esp+318h] [ebp-320h] BYREF
  boost::function<void __cdecl(void)> v129; // [esp+338h] [ebp-300h] BYREF
  boost::function<void __cdecl(void)> v130; // [esp+358h] [ebp-2E0h] BYREF
  boost::function<void __cdecl(void)> v131; // [esp+378h] [ebp-2C0h] BYREF
  boost::function<void __cdecl(void)> v132; // [esp+398h] [ebp-2A0h] BYREF
  boost::function<void __cdecl(void)> v133; // [esp+3B8h] [ebp-280h] BYREF
  boost::function<void __cdecl(void)> v134; // [esp+3D8h] [ebp-260h] BYREF
  boost::function<void __cdecl(void)> f; // [esp+3F8h] [ebp-240h] BYREF
  boost::function<void __cdecl(void)> v136; // [esp+418h] [ebp-220h] BYREF
  boost::function<void __cdecl(void)> v137; // [esp+438h] [ebp-200h] BYREF
  boost::function<void __cdecl(void)> v138; // [esp+458h] [ebp-1E0h] BYREF
  boost::function<void __cdecl(void)> v139; // [esp+478h] [ebp-1C0h] BYREF
  boost::function<void __cdecl(void)> v140; // [esp+498h] [ebp-1A0h] BYREF
  boost::function<void __cdecl(void)> v141; // [esp+4B8h] [ebp-180h] BYREF
  boost::function<void __cdecl(void)> v142; // [esp+4D8h] [ebp-160h] BYREF
  boost::function<void __cdecl(void)> v143; // [esp+4F8h] [ebp-140h] BYREF
  boost::function<void __cdecl(void)> v144; // [esp+518h] [ebp-120h] BYREF
  boost::function<void __cdecl(void)> v145; // [esp+538h] [ebp-100h] BYREF
  boost::function<void __cdecl(void)> v146; // [esp+558h] [ebp-E0h] BYREF
  boost::function<void __cdecl(void)> callback; // [esp+578h] [ebp-C0h] BYREF
  boost::function<void __cdecl(void)> v148; // [esp+598h] [ebp-A0h] BYREF
  boost::function<void __cdecl(void)> v149; // [esp+5B8h] [ebp-80h] BYREF
  boost::function<void __cdecl(void)> v150; // [esp+5D8h] [ebp-60h] BYREF
  boost::function<void __cdecl(void)> v151; // [esp+5F8h] [ebp-40h] BYREF
  boost::function<void __cdecl(void)> v152; // [esp+618h] [ebp-20h] BYREF

  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>::operator=(
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)this,
    (vostok::particle::particle_system_instance_impl **)(a2 + 680));
  v105 = *(_DWORD *)(a2 + 676) != 0;
  if ( !*(_BYTE *)(a2 + 752) )
  {
    v2 = *(boost::function<void __cdecl(char const *)> **)(a2 + 732);
    if ( !v2 )
      v2 = (boost::function<void __cdecl(char const *)> *)_InterlockedExchange((volatile __int32 *)(a2 + 732), 1);
    *(_DWORD *)&v56.l_ = v106;
    v56.f_ = (void (__cdecl *)())vostok::memory::process_allocator::finalize_impl;
    boost::function<void __cdecl (char const *)>::function<void __cdecl (char const *)>(
      v2,
      (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&callback,
      v56,
      v85);
    run(logic, &callback, continue_process_loop, dont_wait_for_completion, 0);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v3,
      (int *)&callback);
    *(_DWORD *)&v57.l_ = v106;
    v57.f_ = (void (__cdecl *)())vostok::memory::process_allocator::finalize_impl;
    boost::function<void __cdecl (char const *)>::function<void __cdecl (char const *)>(
      v4,
      (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v131,
      v57,
      v86);
    run(network, &v131, continue_process_loop, dont_wait_for_completion, 0);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v5,
      (int *)&v131);
    *(_DWORD *)&v58.l_ = v106;
    v58.f_ = (void (__cdecl *)())vostok::memory::process_allocator::finalize_impl;
    boost::function<void __cdecl (char const *)>::function<void __cdecl (char const *)>(
      v6,
      (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v111,
      v58,
      v87);
    run(sound, &v111, continue_process_loop, dont_wait_for_completion, 0);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v7,
      (int *)&v111);
    *(_DWORD *)&v59.l_ = v106;
    v59.f_ = (void (__cdecl *)())vostok::memory::process_allocator::finalize_impl;
    boost::function<void __cdecl (char const *)>::function<void __cdecl (char const *)>(
      v8,
      (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v108,
      v59,
      v88);
    run(editor, &v108, continue_process_loop, dont_wait_for_completion, 0);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v9,
      (int *)&v108);
    process_callback.vtable = 0;
    vostok::apc::wait(logic, &process_callback);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v67,
      (int *)&process_callback);
    v133.vtable = 0;
    vostok::apc::wait(network, &v133);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v68,
      (int *)&v133);
    v115.vtable = 0;
    vostok::apc::wait(sound, &v115);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v69,
      (int *)&v115);
    v143.vtable = 0;
    vostok::apc::wait(editor, &v143);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v70,
      (int *)&v143);
    while ( !vostok::render::one_way_render_channel::render_process_commands(v10, *(_DWORD *)(a2 + 672), 0) )
      ;
    if ( v105 )
    {
      while ( !vostok::render::one_way_render_channel::render_process_commands(v10, *(_DWORD *)(a2 + 672) + 176, 0) )
        ;
    }
    v60.l_.a1_.t_ = *(vostok::sound::world **)(a2 + 688);
    v60.f_.f_ = (void (__thiscall *)(vostok::sound::world *)) __thiscall vostok::sound::world::`vcall'{12,{flat}};
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function<void __cdecl(void)> *) __thiscall vostok::sound::world::`vcall'{12,{flat}},
      (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::world>,boost::_bi::list1<boost::_bi::value<vostok::sound::world *> > > *)&v117,
      v60,
      v89);
    run(sound, &v117, continue_process_loop, wait_for_completion, 0);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v11,
      (int *)&v117);
    HIDWORD(v48.f_.f_) = vostok::engine::engine_world::logic_clear_resources;
    *(_QWORD *)&v48.l_.a1_.t_ = __PAIR64__(a2, 0);
    LODWORD(v48.f_.f_) = &f;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(0, v48, v107);
    run(logic, &f, continue_process_loop, dont_wait_for_completion, 0);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v12,
      (int *)&f);
    HIDWORD(v49.f_.f_) =  __thiscall vostok::engine::engine_world::`vcall'{8,{flat}};
    *(_QWORD *)&v49.l_.a1_.t_ = __PAIR64__(a2, 8);
    LODWORD(v49.f_.f_) = &v119;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function<void __cdecl(void)> *)8,
      v49,
      v107);
    vostok::apc::wait(logic, &v119);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v71,
      (int *)&v119);
    v151.vtable = 0;
    vostok::apc::wait(editor, &v151);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v72,
      (int *)&v151);
    HIDWORD(v50.f_.f_) = vostok::engine::engine_world::sound_clear_resources;
    *(_QWORD *)&v50.l_.a1_.t_ = __PAIR64__(a2, 0);
    LODWORD(v50.f_.f_) = &v121;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(0, v50, v107);
    run(sound, &v121, continue_process_loop, dont_wait_for_completion, 0);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v13,
      (int *)&v121);
    while ( !vostok::render::one_way_render_channel::render_process_commands(
               &v14->m_logic_channel,
               *(_DWORD *)(a2 + 672),
               0) )
      ;
    if ( v105 )
    {
      while ( !vostok::render::one_way_render_channel::render_process_commands(
                 &v14->m_logic_channel,
                 *(_DWORD *)(a2 + 672) + 176,
                 0) )
        ;
    }
    vostok::render::world::clear_resources(v14, *(_DWORD *)(a2 + 672));
    v137.vtable = 0;
    vostok::apc::wait(network, &v137);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v73,
      (int *)&v137);
    v123.vtable = 0;
    vostok::apc::wait(sound, &v123);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v74,
      (int *)&v123);
    HIDWORD(v51.f_.f_) = vostok::engine::engine_world::logic_dispatch_callbacks;
    *(_QWORD *)&v51.l_.a1_.t_ = __PAIR64__(a2, 0);
    LODWORD(v51.f_.f_) = &v145;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(0, v51, v107);
    run(logic, &v145, continue_process_loop, dont_wait_for_completion, 0);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v15,
      (int *)&v145);
    v125.vtable = 0;
    vostok::apc::wait(logic, &v125);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v75,
      (int *)&v125);
    v139.vtable = 0;
    vostok::apc::wait(editor, &v139);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v76,
      (int *)&v139);
    v61.l_.a1_.t_ = *(vostok::render::one_way_render_channel **)(a2 + 672);
    v61.f_.f_ = (void (__thiscall *)(vostok::render::one_way_render_channel *))vostok::render::one_way_render_channel::owner_finalize;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function<void __cdecl(void)> *)vostok::render::one_way_render_channel::owner_finalize,
      (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::render::one_way_render_channel>,boost::_bi::list1<boost::_bi::value<vostok::render::one_way_render_channel *> > > *)&v127,
      v61,
      v90);
    run(logic, &v127, continue_process_loop, dont_wait_for_completion, 0);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v16,
      (int *)&v127);
    v62.l_.a1_.t_ = (vostok::sound::world_user *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 688) + 8))(*(_DWORD *)(a2 + 688));
    v62.f_.f_ = vostok::sound::world_user::finalize;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function<void __cdecl(void)> *)vostok::sound::world_user::finalize,
      (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::world_user>,boost::_bi::list1<boost::_bi::value<vostok::sound::world_user *> > > *)&v149,
      v62,
      v91);
    run(logic, &v149, continue_process_loop, dont_wait_for_completion, 0);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v17,
      (int *)&v149);
    s_resources_callbacks_have_been_dispatched = 0;
    boost::function<void __cdecl (char const *)>::function<void __cdecl (char const *)>(
      v18,
      (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v129,
      (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0>)(unsigned int)thread_dispatch_callbacks,
      v92);
    run(logic, &v129, continue_process_loop, dont_wait_for_completion, 1);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v19,
      (int *)&v129);
    boost::function<void __cdecl (char const *)>::function<void __cdecl (char const *)>(
      v20,
      (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v141,
      (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0>)(unsigned int)thread_dispatch_callbacks,
      v93);
    run(network, &v141, continue_process_loop, dont_wait_for_completion, 1);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v21,
      (int *)&v141);
    boost::function<void __cdecl (char const *)>::function<void __cdecl (char const *)>(
      v22,
      (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v109,
      (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0>)(unsigned int)thread_dispatch_callbacks,
      v94);
    run(sound, &v109, continue_process_loop, dont_wait_for_completion, 1);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v23,
      (int *)&v109);
    boost::function<void __cdecl (char const *)>::function<void __cdecl (char const *)>(
      v24,
      (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v110,
      (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0>)(unsigned int)thread_dispatch_callbacks,
      v95);
    run(editor, &v110, continue_process_loop, dont_wait_for_completion, 1);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v25,
      (int *)&v110);
    vostok::resources::resources_manager::wait_and_dispatch_callbacks(v26, 1, 0);
    _InterlockedExchange(&s_resources_callbacks_have_been_dispatched, 1);
    v112.vtable = 0;
    vostok::apc::wait(logic, &v112);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v77,
      (int *)&v112);
    v114.vtable = 0;
    vostok::apc::wait(network, &v114);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v78,
      (int *)&v114);
    v116.vtable = 0;
    vostok::apc::wait(sound, &v116);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v79,
      (int *)&v116);
    v118.vtable = 0;
    vostok::apc::wait(editor, &v118);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v80,
      (int *)&v118);
    HIDWORD(v52.f_.f_) = vostok::engine::engine_world::network_clear_resources;
    *(_QWORD *)&v52.l_.a1_.t_ = __PAIR64__(a2, 0);
    LODWORD(v52.f_.f_) = &v120;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(0, v52, v107);
    run(logic, &v120, continue_process_loop, dont_wait_for_completion, 0);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v27,
      (int *)&v120);
    HIDWORD(v53.f_.f_) = vostok::engine::engine_world::network_tick;
    *(_QWORD *)&v53.l_.a1_.t_ = __PAIR64__(a2, 0);
    LODWORD(v53.f_.f_) = &v122;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(0, v53, v107);
    run(network, &v122, continue_process_loop, wait_for_completion, 1);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v28,
      (int *)&v122);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      v29,
      &v124,
      (void (__cdecl *)())vostok::resources::schedule_release_all_resources,
      v96);
    run(res_man, &v124, continue_process_loop, wait_for_completion, 0);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v30,
      (int *)&v124);
    HIDWORD(v54.f_.f_) = vostok::engine::engine_world::logic_finalize_modules;
    *(_QWORD *)&v54.l_.a1_.t_ = __PAIR64__(a2, 0);
    LODWORD(v54.f_.f_) = &v126;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(0, v54, v107);
    run(logic, &v126, continue_process_loop, dont_wait_for_completion, 0);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v31,
      (int *)&v126);
    v63.l_.a1_.t_ = *(vostok::network::world **)(a2 + 684);
    v63.f_.f_ = (void (__thiscall *)(vostok::network::world *)) __thiscall survarium::collision_geometry_subscriber::`vcall'{4,{flat}};
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function<void __cdecl(void)> *) __thiscall survarium::collision_geometry_subscriber::`vcall'{4,{flat}},
      (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::world>,boost::_bi::list1<boost::_bi::value<vostok::network::world *> > > *)&v128,
      v63,
      v97);
    run(logic, &v128, continue_process_loop, dont_wait_for_completion, 0);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v32,
      (int *)&v128);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      v33,
      (boost::_bi::bind_t<void,void (__cdecl*)(bool),boost::_bi::list1<boost::_bi::value<bool> > > *)&v130,
      (boost::_bi::bind_t<void,void (__cdecl*)(bool),boost::_bi::list1<boost::_bi::value<bool> > >)(unsigned int)vostok::resources::finalize_thread_usage,
      v98);
    run(logic, &v130, break_process_loop, dont_wait_for_completion, 1);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v34,
      (int *)&v130);
    v64.l_.a1_.t_ = *(vostok::network::world **)(a2 + 684);
    v64.f_ = vostok::network::destroy_world;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function<void __cdecl(void)> *)vostok::network::destroy_world,
      (boost::_bi::bind_t<void,void (__cdecl*)(vostok::network::world * &),boost::_bi::list1<boost::_bi::value<vostok::network::world *> > > *)&v132,
      v64,
      v99);
    run(network, &v132, continue_process_loop, dont_wait_for_completion, 0);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v35,
      (int *)&v132);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      v36,
      (boost::_bi::bind_t<void,void (__cdecl*)(bool),boost::_bi::list1<boost::_bi::value<bool> > > *)&v134,
      (boost::_bi::bind_t<void,void (__cdecl*)(bool),boost::_bi::list1<boost::_bi::value<bool> > >)(unsigned int)vostok::resources::finalize_thread_usage,
      v100);
    run(network, &v134, break_process_loop, dont_wait_for_completion, 1);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v37,
      (int *)&v134);
    v65.l_.a1_.t_ = *(vostok::sound::world **)(a2 + 688);
    v65.f_ = vostok::sound::destroy_world;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function<void __cdecl(void)> *)vostok::sound::destroy_world,
      (boost::_bi::bind_t<void,void (__cdecl*)(vostok::sound::world * &),boost::_bi::list1<boost::_bi::value<vostok::sound::world *> > > *)&v136,
      v65,
      v101);
    run(sound, &v136, continue_process_loop, dont_wait_for_completion, 0);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v38,
      (int *)&v136);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      v39,
      (boost::_bi::bind_t<void,void (__cdecl*)(bool),boost::_bi::list1<boost::_bi::value<bool> > > *)&v138,
      (boost::_bi::bind_t<void,void (__cdecl*)(bool),boost::_bi::list1<boost::_bi::value<bool> > >)(unsigned int)vostok::resources::finalize_thread_usage,
      v102);
    run(sound, &v138, break_process_loop, dont_wait_for_completion, 1);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v40,
      (int *)&v138);
    if ( v105 )
    {
      HIDWORD(v55.f_.f_) = vostok::engine::engine_world::unload_editor;
      *(_QWORD *)&v55.l_.a1_.t_ = __PAIR64__(a2, 0);
      LODWORD(v55.f_.f_) = &v140;
      boost::function<void __cdecl (void)>::function<void __cdecl (void)>(0, v55, v107);
      run(editor, &v140, continue_process_loop, dont_wait_for_completion, 0);
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v41,
        (int *)&v140);
      boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
        v42,
        (boost::_bi::bind_t<void,void (__cdecl*)(bool),boost::_bi::list1<boost::_bi::value<bool> > > *)&v142,
        (boost::_bi::bind_t<void,void (__cdecl*)(bool),boost::_bi::list1<boost::_bi::value<bool> > >)(unsigned int)vostok::resources::finalize_thread_usage,
        v103);
      run(editor, &v142, continue_process_loop, wait_for_completion, 1);
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v43,
        (int *)&v142);
      boost::function<void __cdecl (char const *)>::function<void __cdecl (char const *)>(
        v44,
        (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v144,
        (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0>)(unsigned int)vostok::memory::process_allocator::finalize_impl,
        v104);
      run(editor, &v144, break_process_loop, wait_for_completion, 1);
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v45,
        (int *)&v144);
    }
    v146.vtable = 0;
    vostok::apc::wait(logic, &v146);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v81,
      (int *)&v146);
    v148.vtable = 0;
    vostok::apc::wait(network, &v148);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v82,
      (int *)&v148);
    v150.vtable = 0;
    vostok::apc::wait(sound, &v150);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v83,
      (int *)&v150);
    v152.vtable = 0;
    vostok::apc::wait(editor, &v152);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v84,
      (int *)&v152);
    vostok::resources::resources_manager::wait_and_dispatch_callbacks(v46, 1, 0);
    vostok::render::world::~world(
      v47,
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)s_world_1.m_variable);
    s_world_1.m_initialized = 0;
    v66 = *(HWND *)(a2 + 712);
    *(_DWORD *)(a2 + 672) = 0;
    ShowWindow(v66, 0);
    s_world_5 = 0;
  }
  vostok::debug::terminate(-100000, (char *)uri);
}
