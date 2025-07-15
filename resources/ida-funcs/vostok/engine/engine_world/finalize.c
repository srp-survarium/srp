void __userpurge __noreturn vostok::engine::engine_world::finalize(
        vostok::engine::engine_world *this@<ecx>,
        double a2@<st0>,
        vostok::engine::engine_world *thisa)
{
  vostok::configs::binary_config *m_object; // eax
  vostok::apc::callback *v4; // esi
  vostok::apc::callback *v5; // esi
  void (__cdecl *v6)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::apc::callback *v7; // esi
  vostok::apc::callback *v8; // esi
  void (__cdecl *v9)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::apc::callback *v10; // esi
  vostok::apc::callback *v11; // esi
  void (__cdecl *v12)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::apc::callback *v13; // esi
  vostok::apc::callback *v14; // esi
  void (__cdecl *v15)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::apc::callback *v16; // esi
  vostok::apc::callback *v17; // esi
  void (__cdecl *v18)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::render::one_way_render_channel *v19; // ecx
  vostok::apc::callback *v20; // esi
  boost::function0<void> *v21; // ecx
  vostok::apc::callback *v22; // esi
  void (__cdecl *v23)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::apc::callback *v24; // edi
  vostok::apc::callback *v25; // edi
  void (__cdecl *v26)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function0<void> *v27; // ecx
  vostok::apc::callback *v28; // edi
  vostok::render::one_way_render_channel *v29; // ecx
  vostok::apc::callback *v30; // edi
  void (__cdecl *v31)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function0<void> *v32; // ecx
  vostok::apc::callback *v33; // esi
  vostok::apc::callback *v34; // esi
  void (__cdecl *v35)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::apc::callback *v36; // esi
  vostok::apc::callback *v37; // esi
  void (__cdecl *v38)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::apc::callback *v39; // esi
  vostok::apc::callback *v40; // esi
  void (__cdecl *v41)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::apc::callback *v42; // esi
  vostok::apc::callback *v43; // esi
  void (__cdecl *v44)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::apc::callback *v45; // esi
  vostok::apc::callback *v46; // esi
  void (__cdecl *v47)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::apc::callback *v48; // esi
  vostok::apc::callback *v49; // esi
  void (__cdecl *v50)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::apc::callback *v51; // esi
  vostok::resources::resources_manager *v52; // ecx
  vostok::apc::callback *v53; // esi
  void (__cdecl *v54)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::apc::callback *v55; // esi
  vostok::apc::callback *v56; // esi
  void (__cdecl *v57)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::apc::callback *v58; // edi
  boost::function0<void> *v59; // ecx
  vostok::apc::callback *v60; // edi
  void (__cdecl *v61)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::apc::callback *v62; // edi
  boost::function0<void> *v63; // ecx
  vostok::apc::callback *v64; // edi
  void (__cdecl *v65)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::apc::callback *v66; // edi
  vostok::apc::callback *v67; // edi
  void (__cdecl *v68)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::apc::callback *v69; // esi
  vostok::apc::callback *v70; // esi
  void (__cdecl *v71)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::apc::callback *v72; // esi
  vostok::apc::callback *v73; // esi
  void (__cdecl *v74)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::apc::callback *v75; // esi
  vostok::apc::callback *v76; // esi
  void (__cdecl *v77)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::apc::callback *v78; // esi
  vostok::apc::callback *v79; // esi
  void (__cdecl *v80)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::apc::callback *v81; // esi
  vostok::apc::callback *v82; // esi
  void (__cdecl *v83)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::apc::callback *v84; // esi
  boost::function<void __cdecl(void)> *v85; // ecx
  vostok::apc::callback *v86; // esi
  void (__cdecl *v87)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function0<void> *v88; // ecx
  vostok::resources::resources_manager *v89; // ecx
  vostok::engine::engine_world *v90; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::engine::engine_world>,boost::_bi::list1<boost::_bi::value<vostok::engine::engine_world *> > > v91; // [esp-10h] [ebp-430h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::engine::engine_world>,boost::_bi::list1<boost::_bi::value<vostok::engine::engine_world *> > > v92; // [esp-10h] [ebp-430h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::engine::engine_world>,boost::_bi::list1<boost::_bi::value<vostok::engine::engine_world *> > > v93; // [esp-10h] [ebp-430h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::engine::engine_world>,boost::_bi::list1<boost::_bi::value<vostok::engine::engine_world *> > > v94; // [esp-10h] [ebp-430h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::engine::engine_world>,boost::_bi::list1<boost::_bi::value<vostok::engine::engine_world *> > > v95; // [esp-10h] [ebp-430h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::engine::engine_world>,boost::_bi::list1<boost::_bi::value<vostok::engine::engine_world *> > > v96; // [esp-10h] [ebp-430h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::engine::engine_world>,boost::_bi::list1<boost::_bi::value<vostok::engine::engine_world *> > > v97; // [esp-10h] [ebp-430h]
  boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> v98; // [esp-8h] [ebp-428h]
  boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> v99; // [esp-8h] [ebp-428h]
  boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> v100; // [esp-8h] [ebp-428h]
  boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> v101; // [esp-8h] [ebp-428h]
  boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> v102; // [esp-8h] [ebp-428h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::world>,boost::_bi::list1<boost::_bi::value<vostok::sound::world *> > > v103; // [esp-8h] [ebp-428h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::render::one_way_render_channel>,boost::_bi::list1<boost::_bi::value<vostok::render::one_way_render_channel *> > > v104; // [esp-8h] [ebp-428h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::world_user>,boost::_bi::list1<boost::_bi::value<vostok::sound::world_user *> > > v105; // [esp-8h] [ebp-428h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::world>,boost::_bi::list1<boost::_bi::value<vostok::network::world *> > > v106; // [esp-8h] [ebp-428h]
  boost::_bi::bind_t<void,void (__cdecl*)(bool),boost::_bi::list1<boost::_bi::value<bool> > > v107; // [esp-8h] [ebp-428h]
  boost::_bi::bind_t<void,void (__cdecl*)(vostok::network::world * &),boost::_bi::list1<boost::_bi::value<vostok::network::world *> > > v108; // [esp-8h] [ebp-428h]
  boost::_bi::bind_t<void,void (__cdecl*)(bool),boost::_bi::list1<boost::_bi::value<bool> > > v109; // [esp-8h] [ebp-428h]
  boost::_bi::bind_t<void,void (__cdecl*)(vostok::sound::world * &),boost::_bi::list1<boost::_bi::value<vostok::sound::world *> > > v110; // [esp-8h] [ebp-428h]
  boost::_bi::bind_t<void,void (__cdecl*)(bool),boost::_bi::list1<boost::_bi::value<bool> > > v111; // [esp-8h] [ebp-428h]
  boost::_bi::bind_t<void,void (__cdecl*)(bool),boost::_bi::list1<boost::_bi::value<bool> > > v112; // [esp-8h] [ebp-428h]
  int v113; // [esp+0h] [ebp-420h]
  int v114; // [esp+0h] [ebp-420h]
  int v115; // [esp+0h] [ebp-420h]
  int v116; // [esp+0h] [ebp-420h]
  int v117; // [esp+0h] [ebp-420h]
  int v118; // [esp+0h] [ebp-420h]
  int v119; // [esp+0h] [ebp-420h]
  bool is_editor; // [esp+Fh] [ebp-411h]
  boost::function0<void> *v121; // [esp+14h] [ebp-40Ch]
  boost::function0<void> *v122; // [esp+14h] [ebp-40Ch]
  __int64 v123; // [esp+18h] [ebp-408h]
  vostok::command_line::key_initializator v124[4]; // [esp+20h] [ebp-400h]
  vostok::network::world *m_network_world; // [esp+24h] [ebp-3FCh]
  vostok::sound::world *t; // [esp+28h] [ebp-3F8h]
  vostok::network::world *v127; // [esp+2Ch] [ebp-3F4h]
  vostok::command_line::key_initializator v128[4]; // [esp+30h] [ebp-3F0h]
  vostok::sound::world *m_sound_world; // [esp+34h] [ebp-3ECh]
  vostok::command_line::key_initializator predicate[4]; // [esp+38h] [ebp-3E8h]
  vostok::command_line::key_initializator v131[4]; // [esp+3Ch] [ebp-3E4h]
  boost::function0<void> v132; // [esp+40h] [ebp-3E0h] BYREF
  vostok::sound::world *v133; // [esp+60h] [ebp-3C0h]
  vostok::engine::engine_world *v134; // [esp+64h] [ebp-3BCh]
  boost::function0<void> v135; // [esp+68h] [ebp-3B8h] BYREF
  vostok::engine::engine_world *v136; // [esp+8Ch] [ebp-394h]
  boost::function0<void> v137; // [esp+90h] [ebp-390h] BYREF
  vostok::engine::engine_world *v138; // [esp+B4h] [ebp-36Ch]
  boost::function0<void> v139; // [esp+B8h] [ebp-368h] BYREF
  vostok::render::one_way_render_channel *v140; // [esp+DCh] [ebp-344h]
  boost::function0<void> v141; // [esp+E0h] [ebp-340h] BYREF
  vostok::engine::engine_world *v142; // [esp+104h] [ebp-31Ch]
  vostok::engine::engine_world *v143; // [esp+108h] [ebp-318h]
  vostok::render::one_way_render_channel *v144; // [esp+10Ch] [ebp-314h]
  boost::function0<void> v145; // [esp+110h] [ebp-310h] BYREF
  vostok::engine::engine_world *v146; // [esp+134h] [ebp-2ECh]
  boost::function0<void> v147; // [esp+138h] [ebp-2E8h] BYREF
  vostok::sound::world_user *v148; // [esp+15Ch] [ebp-2C4h]
  boost::function0<void> v149; // [esp+160h] [ebp-2C0h] BYREF
  boost::function0<void> v150; // [esp+180h] [ebp-2A0h] BYREF
  boost::function0<void> v151; // [esp+1A0h] [ebp-280h] BYREF
  boost::function0<void> v152; // [esp+1C0h] [ebp-260h] BYREF
  boost::function0<void> v153; // [esp+1E0h] [ebp-240h] BYREF
  boost::function0<void> v154; // [esp+200h] [ebp-220h] BYREF
  boost::function0<void> v155; // [esp+220h] [ebp-200h] BYREF
  boost::function<void __cdecl(void)> v156; // [esp+240h] [ebp-1E0h] BYREF
  boost::function<void __cdecl(void)> v157; // [esp+260h] [ebp-1C0h] BYREF
  boost::function<void __cdecl(void)> v158; // [esp+280h] [ebp-1A0h] BYREF
  boost::function<void __cdecl(void)> v159; // [esp+2A0h] [ebp-180h] BYREF
  boost::function<void __cdecl(void)> v160; // [esp+2C0h] [ebp-160h] BYREF
  boost::function<void __cdecl(void)> f; // [esp+2E0h] [ebp-140h] BYREF
  boost::function<void __cdecl(void)> v162; // [esp+300h] [ebp-120h] BYREF
  boost::function<void __cdecl(void)> v163; // [esp+320h] [ebp-100h] BYREF
  boost::function0<void> v164; // [esp+340h] [ebp-E0h] BYREF
  boost::function0<void> v165; // [esp+360h] [ebp-C0h] BYREF
  boost::function<void __cdecl(void)> v166; // [esp+380h] [ebp-A0h] BYREF
  boost::function<void __cdecl(void)> v167; // [esp+3A0h] [ebp-80h] BYREF
  boost::function<void __cdecl(void)> v168; // [esp+3C0h] [ebp-60h] BYREF
  boost::function<void __cdecl(void)> v169; // [esp+3E0h] [ebp-40h] BYREF
  boost::function<void __cdecl(void)> callback; // [esp+400h] [ebp-20h] BYREF

  m_object = thisa->m_shader_mask_config.m_object;
  thisa->m_shader_mask_config.m_object = 0;
  if ( m_object )
  {
    this = (vostok::engine::engine_world *)&m_object->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        (vostok::resources::unmanaged_intrusive_base *)this,
        m_object);
  }
  is_editor = thisa->m_editor != 0;
  if ( !thisa->m_early_destruction_started )
  {
    if ( !thisa->m_destruction_started )
      _InterlockedExchange(&thisa->m_destruction_started, 1);
    *(_DWORD *)&v98.l_ = v121;
    v98.f_ = (void (__cdecl *)())survarium::weapon_user_dead_state::finalize;
    v135.vtable = 0;
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,void (__cdecl *)(void),boost::_bi::list0>>(
      v121,
      (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v135,
      v98);
    v4 = g_threads.m_begin + 1;
    if ( v4->m_thread_id == GetCurrentThreadId() )
    {
      boost::function0<void>::operator()(&v135);
    }
    else
    {
      vostok::apc::wait(logic);
      v5 = g_threads.m_begin + 1;
      boost::function<void __cdecl (void)>::operator=(
        &g_threads.m_begin[1].m_callback,
        (const boost::function<void __cdecl(void)> *)&v135);
      v5->m_break_parameters = continue_process_loop;
      _InterlockedExchange(&v5->m_pending, 1);
    }
    if ( v135.vtable )
    {
      if ( ((int)v135.vtable & 1) == 0 )
      {
        v6 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v135.vtable & 0xFFFFFFFE);
        if ( v6 )
          v6(&v135.functor, &v135.functor, 2);
      }
      v135.vtable = 0;
    }
    *(_DWORD *)&v99.l_ = v121;
    v99.f_ = (void (__cdecl *)())survarium::weapon_user_dead_state::finalize;
    v137.vtable = 0;
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,void (__cdecl *)(void),boost::_bi::list0>>(
      v121,
      (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v137,
      v99);
    v7 = g_threads.m_begin + 3;
    if ( v7->m_thread_id == GetCurrentThreadId() )
    {
      boost::function0<void>::operator()(&v137);
    }
    else
    {
      vostok::apc::wait(network);
      v8 = g_threads.m_begin + 3;
      boost::function<void __cdecl (void)>::operator=(
        &g_threads.m_begin[3].m_callback,
        (const boost::function<void __cdecl(void)> *)&v137);
      v8->m_break_parameters = continue_process_loop;
      _InterlockedExchange(&v8->m_pending, 1);
    }
    if ( v137.vtable )
    {
      if ( ((int)v137.vtable & 1) == 0 )
      {
        v9 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v137.vtable & 0xFFFFFFFE);
        if ( v9 )
          v9(&v137.functor, &v137.functor, 2);
      }
      v137.vtable = 0;
    }
    *(_DWORD *)&v100.l_ = v121;
    v100.f_ = (void (__cdecl *)())survarium::weapon_user_dead_state::finalize;
    v139.vtable = 0;
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,void (__cdecl *)(void),boost::_bi::list0>>(
      v121,
      (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v139,
      v100);
    v10 = g_threads.m_begin + 4;
    if ( v10->m_thread_id == GetCurrentThreadId() )
    {
      boost::function0<void>::operator()(&v139);
    }
    else
    {
      vostok::apc::wait(sound);
      v11 = g_threads.m_begin + 4;
      boost::function<void __cdecl (void)>::operator=(
        &g_threads.m_begin[4].m_callback,
        (const boost::function<void __cdecl(void)> *)&v139);
      v11->m_break_parameters = continue_process_loop;
      _InterlockedExchange(&v11->m_pending, 1);
    }
    if ( v139.vtable )
    {
      if ( ((int)v139.vtable & 1) == 0 )
      {
        v12 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v139.vtable & 0xFFFFFFFE);
        if ( v12 )
          v12(&v139.functor, &v139.functor, 2);
      }
      v139.vtable = 0;
    }
    *(_DWORD *)&v101.l_ = v121;
    v101.f_ = (void (__cdecl *)())survarium::weapon_user_dead_state::finalize;
    v141.vtable = 0;
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,void (__cdecl *)(void),boost::_bi::list0>>(
      v121,
      (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v141,
      v101);
    v13 = g_threads.m_begin + 2;
    if ( v13->m_thread_id == GetCurrentThreadId() )
    {
      boost::function0<void>::operator()(&v141);
    }
    else
    {
      vostok::apc::wait(editor);
      v14 = g_threads.m_begin + 2;
      boost::function<void __cdecl (void)>::operator=(
        &g_threads.m_begin[2].m_callback,
        (const boost::function<void __cdecl(void)> *)&v141);
      v14->m_break_parameters = continue_process_loop;
      _InterlockedExchange(&v14->m_pending, 1);
    }
    if ( v141.vtable )
    {
      if ( ((int)v141.vtable & 1) == 0 )
      {
        v15 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v141.vtable & 0xFFFFFFFE);
        if ( v15 )
          v15(&v141.functor, &v141.functor, 2);
      }
      v141.vtable = 0;
    }
    if ( s_build_resources.m_type == type_unset )
    {
      predicate[0] = 0;
      s_build_resources.m_type = type_recursive;
      vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
    }
    if ( s_build_resources.m_type != type_recursive )
    {
      *(_DWORD *)&v102.l_ = v121;
      v102.f_ = (void (__cdecl *)())survarium::weapon_user_dead_state::finalize;
      v132.vtable = 0;
      boost::function0<void>::assign_to<boost::_bi::bind_t<void,void (__cdecl *)(void),boost::_bi::list0>>(
        v121,
        (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v132,
        v102);
      v16 = g_threads.m_begin + 5;
      if ( v16->m_thread_id == GetCurrentThreadId() )
      {
        boost::function0<void>::operator()(&v132);
      }
      else
      {
        vostok::apc::wait(build);
        v17 = g_threads.m_begin + 5;
        boost::function<void __cdecl (void)>::operator=(
          &g_threads.m_begin[5].m_callback,
          (const boost::function<void __cdecl(void)> *)&v132);
        v17->m_break_parameters = continue_process_loop;
        _InterlockedExchange(&v17->m_pending, 1);
      }
      if ( v132.vtable )
      {
        if ( ((int)v132.vtable & 1) == 0 )
        {
          v18 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v132.vtable & 0xFFFFFFFE);
          if ( v18 )
            v18(&v132.functor, &v132.functor, 2);
        }
        v132.vtable = 0;
      }
    }
    vostok::apc::wait(logic);
    vostok::apc::wait(network);
    vostok::apc::wait(sound);
    vostok::apc::wait(editor);
    if ( s_build_resources.m_type == type_unset )
    {
      v131[0] = 0;
      s_build_resources.m_type = type_recursive;
      vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
    }
    if ( s_build_resources.m_type != type_recursive )
      vostok::apc::wait(build);
    while ( !vostok::render::one_way_render_channel::render_process_commands(v19, (int)thisa->m_render_world, 0) )
      ;
    if ( is_editor )
    {
      while ( !vostok::render::one_way_render_channel::render_process_commands(
                 v19,
                 (int)&thisa->m_render_world->m_editor_channel,
                 0) )
        ;
    }
    v103.l_.a1_.t_ = thisa->m_sound_world;
    v103.f_.f_ = (void (__thiscall *)(vostok::sound::world *)) __thiscall vostok::sound::world::`vcall'{12,{flat}};
    t = v103.l_.a1_.t_;
    v133 = v103.l_.a1_.t_;
    v145.vtable = 0;
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::world>,boost::_bi::list1<boost::_bi::value<vostok::sound::world *>>>>(
      (boost::function0<void> *) __thiscall vostok::sound::world::`vcall'{12,{flat}},
      (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::world>,boost::_bi::list1<boost::_bi::value<vostok::sound::world *> > > *)&v145,
      v103);
    v20 = g_threads.m_begin + 4;
    if ( v20->m_thread_id == GetCurrentThreadId() )
    {
      boost::function0<void>::operator()(&v145);
    }
    else
    {
      vostok::apc::wait(sound);
      v22 = g_threads.m_begin + 4;
      boost::function<void __cdecl (void)>::operator=(
        &g_threads.m_begin[4].m_callback,
        (const boost::function<void __cdecl(void)> *)&v145);
      v22->m_break_parameters = continue_process_loop;
      _InterlockedExchange(&v22->m_pending, 1);
      vostok::apc::wait(sound);
    }
    if ( v145.vtable )
    {
      if ( ((int)v145.vtable & 1) == 0 )
      {
        v23 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v145.vtable & 0xFFFFFFFE);
        if ( v23 )
          v23(&v145.functor, &v145.functor, 2);
      }
      v145.vtable = 0;
    }
    v91.f_.f_ = (void (__thiscall *__ptr64)(vostok::engine::engine_world *))(unsigned int)vostok::engine::engine_world::logic_clear_resources;
    LODWORD(v123) = thisa;
    v143 = thisa;
    v134 = thisa;
    *(_QWORD *)&v91.l_.a1_.t_ = v123;
    boost::function0<void>::function0<void>(v21, (int)&v152, (int)thisa, v91, v113);
    v24 = g_threads.m_begin + 1;
    if ( v24->m_thread_id == GetCurrentThreadId() )
    {
      boost::function0<void>::operator()(&v152);
    }
    else
    {
      vostok::apc::wait(logic);
      v25 = g_threads.m_begin + 1;
      boost::function<void __cdecl (void)>::operator=(
        &g_threads.m_begin[1].m_callback,
        (const boost::function<void __cdecl(void)> *)&v152);
      v25->m_break_parameters = continue_process_loop;
      _InterlockedExchange(&v25->m_pending, 1);
    }
    if ( v152.vtable )
    {
      if ( ((int)v152.vtable & 1) == 0 )
      {
        v26 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v152.vtable & 0xFFFFFFFE);
        if ( v26 )
          v26(&v152.functor, &v152.functor, 2);
      }
      v152.vtable = 0;
    }
    vostok::apc::wait(logic);
    vostok::apc::wait(editor);
    v92.f_.f_ = (void (__thiscall *__ptr64)(vostok::engine::engine_world *))(unsigned int)vostok::engine::engine_world::sound_clear_resources;
    LODWORD(v123) = thisa;
    v142 = thisa;
    v136 = thisa;
    *(_QWORD *)&v92.l_.a1_.t_ = v123;
    boost::function0<void>::function0<void>(v27, (int)&v150, (int)thisa, v92, v114);
    v28 = g_threads.m_begin + 4;
    if ( v28->m_thread_id == GetCurrentThreadId() )
    {
      boost::function0<void>::operator()(&v150);
    }
    else
    {
      vostok::apc::wait(sound);
      v30 = g_threads.m_begin + 4;
      boost::function<void __cdecl (void)>::operator=(
        &g_threads.m_begin[4].m_callback,
        (const boost::function<void __cdecl(void)> *)&v150);
      v30->m_break_parameters = continue_process_loop;
      v29 = (vostok::render::one_way_render_channel *)_InterlockedExchange(&v30->m_pending, 1);
    }
    if ( v150.vtable )
    {
      if ( ((int)v150.vtable & 1) == 0 )
      {
        v31 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v150.vtable & 0xFFFFFFFE);
        if ( v31 )
          v31(&v150.functor, &v150.functor, 2);
      }
      v150.vtable = 0;
    }
    while ( !vostok::render::one_way_render_channel::render_process_commands(v29, (int)thisa->m_render_world, 0) )
      ;
    if ( is_editor )
    {
      while ( !vostok::render::one_way_render_channel::render_process_commands(
                 v29,
                 (int)&thisa->m_render_world->m_editor_channel,
                 0) )
        ;
    }
    vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base>::operator=(
      &thisa->m_render_world->m_render_engine_world->m_renderer->m_renderer_context->m_scene_view,
      0);
    vostok::apc::wait(network);
    vostok::apc::wait(sound);
    v93.f_.f_ = (void (__thiscall *__ptr64)(vostok::engine::engine_world *))(unsigned int)vostok::engine::engine_world::logic_dispatch_callbacks;
    LODWORD(v123) = thisa;
    v146 = thisa;
    v138 = thisa;
    *(_QWORD *)&v93.l_.a1_.t_ = v123;
    boost::function0<void>::function0<void>(v32, (int)&v154, (int)thisa, v93, v115);
    v33 = g_threads.m_begin + 1;
    if ( v33->m_thread_id == GetCurrentThreadId() )
    {
      boost::function0<void>::operator()(&v154);
    }
    else
    {
      vostok::apc::wait(logic);
      v34 = g_threads.m_begin + 1;
      boost::function<void __cdecl (void)>::operator=(
        &g_threads.m_begin[1].m_callback,
        (const boost::function<void __cdecl(void)> *)&v154);
      v34->m_break_parameters = continue_process_loop;
      _InterlockedExchange(&v34->m_pending, 1);
    }
    if ( v154.vtable )
    {
      if ( ((int)v154.vtable & 1) == 0 )
      {
        v35 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v154.vtable & 0xFFFFFFFE);
        if ( v35 )
          v35(&v154.functor, &v154.functor, 2);
      }
      v154.vtable = 0;
    }
    vostok::apc::wait(logic);
    vostok::apc::wait(editor);
    v104.l_.a1_.t_ = &thisa->m_render_world->m_logic_channel;
    v104.f_.f_ = vostok::render::one_way_render_channel::owner_finalize;
    v144 = v104.l_.a1_.t_;
    v140 = v104.l_.a1_.t_;
    v147.vtable = 0;
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::render::one_way_render_channel>,boost::_bi::list1<boost::_bi::value<vostok::render::one_way_render_channel *>>>>(
      (boost::function0<void> *)vostok::render::one_way_render_channel::owner_finalize,
      (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::render::one_way_render_channel>,boost::_bi::list1<boost::_bi::value<vostok::render::one_way_render_channel *> > > *)&v147,
      v104);
    v36 = g_threads.m_begin + 1;
    if ( v36->m_thread_id == GetCurrentThreadId() )
    {
      boost::function0<void>::operator()(&v147);
    }
    else
    {
      vostok::apc::wait(logic);
      v37 = g_threads.m_begin + 1;
      boost::function<void __cdecl (void)>::operator=(
        &g_threads.m_begin[1].m_callback,
        (const boost::function<void __cdecl(void)> *)&v147);
      v37->m_break_parameters = continue_process_loop;
      _InterlockedExchange(&v37->m_pending, 1);
    }
    if ( v147.vtable )
    {
      if ( ((int)v147.vtable & 1) == 0 )
      {
        v38 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v147.vtable & 0xFFFFFFFE);
        if ( v38 )
          v38(&v147.functor, &v147.functor, 2);
      }
      v147.vtable = 0;
    }
    v105.l_.a1_.t_ = thisa->m_sound_world->get_logic_world_user(thisa->m_sound_world);
    v105.f_.f_ = vostok::sound::world_user::finalize;
    v148 = v105.l_.a1_.t_;
    v149.vtable = 0;
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::world_user>,boost::_bi::list1<boost::_bi::value<vostok::sound::world_user *>>>>(
      (boost::function0<void> *)vostok::sound::world_user::finalize,
      (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::world_user>,boost::_bi::list1<boost::_bi::value<vostok::sound::world_user *> > > *)&v149,
      v105);
    v39 = g_threads.m_begin + 1;
    if ( v39->m_thread_id == GetCurrentThreadId() )
    {
      boost::function0<void>::operator()(&v149);
    }
    else
    {
      vostok::apc::wait(logic);
      v40 = g_threads.m_begin + 1;
      boost::function<void __cdecl (void)>::operator=(
        &g_threads.m_begin[1].m_callback,
        (const boost::function<void __cdecl(void)> *)&v149);
      v40->m_break_parameters = continue_process_loop;
      _InterlockedExchange(&v40->m_pending, 1);
    }
    if ( v149.vtable )
    {
      if ( ((int)v149.vtable & 1) == 0 )
      {
        v41 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v149.vtable & 0xFFFFFFFE);
        if ( v41 )
          v41(&v149.functor, &v149.functor, 2);
      }
      v149.vtable = 0;
    }
    s_resources_callbacks_have_been_dispatched = 0;
    f.vtable = 0;
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,void (__cdecl *)(void),boost::_bi::list0>>(
      0,
      (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&f,
      (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0>)(unsigned int)thread_dispatch_callbacks);
    v42 = g_threads.m_begin + 1;
    if ( v42->m_thread_id != GetCurrentThreadId() )
    {
      vostok::apc::wait(logic);
      v43 = g_threads.m_begin + 1;
      boost::function<void __cdecl (void)>::operator=(&g_threads.m_begin[1].m_callback, &f);
      v43->m_break_parameters = continue_process_loop;
      _InterlockedExchange(&v43->m_pending, 1);
    }
    if ( f.vtable )
    {
      if ( ((int)f.vtable & 1) == 0 )
      {
        v44 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)f.vtable & 0xFFFFFFFE);
        if ( v44 )
          v44(&f.functor, &f.functor, 2);
      }
    }
    v162.vtable = 0;
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,void (__cdecl *)(void),boost::_bi::list0>>(
      0,
      (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v162,
      (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0>)(unsigned int)thread_dispatch_callbacks);
    v45 = g_threads.m_begin + 3;
    if ( v45->m_thread_id != GetCurrentThreadId() )
    {
      vostok::apc::wait(network);
      v46 = g_threads.m_begin + 3;
      boost::function<void __cdecl (void)>::operator=(&g_threads.m_begin[3].m_callback, &v162);
      v46->m_break_parameters = continue_process_loop;
      _InterlockedExchange(&v46->m_pending, 1);
    }
    if ( v162.vtable )
    {
      if ( ((int)v162.vtable & 1) == 0 )
      {
        v47 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v162.vtable & 0xFFFFFFFE);
        if ( v47 )
          v47(&v162.functor, &v162.functor, 2);
      }
    }
    v159.vtable = 0;
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,void (__cdecl *)(void),boost::_bi::list0>>(
      0,
      (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v159,
      (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0>)(unsigned int)thread_dispatch_callbacks);
    v48 = g_threads.m_begin + 4;
    if ( v48->m_thread_id != GetCurrentThreadId() )
    {
      vostok::apc::wait(sound);
      v49 = g_threads.m_begin + 4;
      boost::function<void __cdecl (void)>::operator=(&g_threads.m_begin[4].m_callback, &v159);
      v49->m_break_parameters = continue_process_loop;
      _InterlockedExchange(&v49->m_pending, 1);
    }
    if ( v159.vtable )
    {
      if ( ((int)v159.vtable & 1) == 0 )
      {
        v50 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v159.vtable & 0xFFFFFFFE);
        if ( v50 )
          v50(&v159.functor, &v159.functor, 2);
      }
    }
    v163.vtable = 0;
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,void (__cdecl *)(void),boost::_bi::list0>>(
      0,
      (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v163,
      (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0>)(unsigned int)thread_dispatch_callbacks);
    v51 = g_threads.m_begin + 2;
    if ( v51->m_thread_id != GetCurrentThreadId() )
    {
      vostok::apc::wait(editor);
      v53 = g_threads.m_begin + 2;
      boost::function<void __cdecl (void)>::operator=(&g_threads.m_begin[2].m_callback, &v163);
      v53->m_break_parameters = continue_process_loop;
      _InterlockedExchange(&v53->m_pending, 1);
    }
    if ( v163.vtable )
    {
      if ( ((int)v163.vtable & 1) == 0 )
      {
        v54 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v163.vtable & 0xFFFFFFFE);
        if ( v54 )
          v54(&v163.functor, &v163.functor, 2);
      }
    }
    if ( s_build_resources.m_type == type_unset )
    {
      v124[0] = 0;
      s_build_resources.m_type = type_recursive;
      vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
    }
    if ( s_build_resources.m_type != type_recursive )
    {
      v156.vtable = 0;
      boost::function0<void>::assign_to<boost::_bi::bind_t<void,void (__cdecl *)(void),boost::_bi::list0>>(
        0,
        (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v156,
        (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0>)(unsigned int)thread_dispatch_callbacks);
      v55 = g_threads.m_begin + 5;
      if ( v55->m_thread_id != GetCurrentThreadId() )
      {
        vostok::apc::wait(build);
        v56 = g_threads.m_begin + 5;
        boost::function<void __cdecl (void)>::operator=(&g_threads.m_begin[5].m_callback, &v156);
        v56->m_break_parameters = continue_process_loop;
        _InterlockedExchange(&v56->m_pending, 1);
      }
      if ( v156.vtable )
      {
        if ( ((int)v156.vtable & 1) == 0 )
        {
          v57 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v156.vtable & 0xFFFFFFFE);
          if ( v57 )
            v57(&v156.functor, &v156.functor, 2);
        }
      }
    }
    vostok::resources::resources_manager::wait_and_dispatch_callbacks(
      v52,
      a2,
      vostok::resources::g_resources_manager.m_variable,
      1,
      0);
    _InterlockedExchange(&s_resources_callbacks_have_been_dispatched, 1);
    vostok::apc::wait(logic);
    vostok::apc::wait(network);
    vostok::apc::wait(sound);
    vostok::apc::wait(editor);
    if ( s_build_resources.m_type == type_unset )
    {
      v128[0] = 0;
      s_build_resources.m_type = type_recursive;
      vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
    }
    if ( s_build_resources.m_type != type_recursive )
      vostok::apc::wait(build);
    v94.f_.f_ = (void (__thiscall *__ptr64)(vostok::engine::engine_world *))(unsigned int)vostok::engine::engine_world::network_clear_resources;
    LODWORD(v123) = thisa;
    *(_QWORD *)&v94.l_.a1_.t_ = v123;
    boost::function0<void>::function0<void>((boost::function0<void> *)thisa, (int)&v165, 1, v94, v116);
    v58 = g_threads.m_begin + 1;
    if ( v58->m_thread_id == GetCurrentThreadId() )
    {
      boost::function0<void>::operator()(&v165);
    }
    else
    {
      vostok::apc::wait(logic);
      v60 = g_threads.m_begin + 1;
      boost::function<void __cdecl (void)>::operator=(
        &g_threads.m_begin[1].m_callback,
        (const boost::function<void __cdecl(void)> *)&v165);
      v60->m_break_parameters = continue_process_loop;
      _InterlockedExchange(&v60->m_pending, 1);
    }
    if ( v165.vtable )
    {
      if ( ((int)v165.vtable & 1) == 0 )
      {
        v61 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v165.vtable & 0xFFFFFFFE);
        if ( v61 )
          v61(&v165.functor, &v165.functor, 2);
      }
    }
    LODWORD(v123) = thisa;
    v95.f_.f_ = (void (__thiscall *__ptr64)(vostok::engine::engine_world *))(unsigned int)vostok::engine::engine_world::network_tick;
    *(_QWORD *)&v95.l_.a1_.t_ = v123;
    boost::function0<void>::function0<void>(v59, (int)&v166, (int)GetCurrentThreadId, v95, v117);
    v62 = g_threads.m_begin + 3;
    if ( v62->m_thread_id != GetCurrentThreadId() )
    {
      vostok::apc::wait(network);
      v64 = g_threads.m_begin + 3;
      boost::function<void __cdecl (void)>::operator=(&g_threads.m_begin[3].m_callback, &v166);
      v64->m_break_parameters = continue_process_loop;
      _InterlockedExchange(&v64->m_pending, 1);
      vostok::apc::wait(network);
    }
    if ( v166.vtable )
    {
      if ( ((int)v166.vtable & 1) == 0 )
      {
        v65 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v166.vtable & 0xFFFFFFFE);
        if ( v65 )
          v65(&v166.functor, &v166.functor, 2);
      }
    }
    LODWORD(v123) = thisa;
    v122 = 0;
    v96.f_.f_ = (void (__thiscall *__ptr64)(vostok::engine::engine_world *))(unsigned int)vostok::engine::engine_world::logic_finalize_modules;
    *(_QWORD *)&v96.l_.a1_.t_ = v123;
    boost::function0<void>::function0<void>(v63, (int)&v164, (int)GetCurrentThreadId, v96, v118);
    v66 = g_threads.m_begin + 1;
    if ( v66->m_thread_id == GetCurrentThreadId() )
    {
      boost::function0<void>::operator()(&v164);
    }
    else
    {
      vostok::apc::wait(logic);
      v67 = g_threads.m_begin + 1;
      boost::function<void __cdecl (void)>::operator=(
        &g_threads.m_begin[1].m_callback,
        (const boost::function<void __cdecl(void)> *)&v164);
      v67->m_break_parameters = continue_process_loop;
      _InterlockedExchange(&v67->m_pending, 1);
    }
    if ( v164.vtable )
    {
      if ( ((int)v164.vtable & 1) == 0 )
      {
        v68 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v164.vtable & 0xFFFFFFFE);
        if ( v68 )
          v68(&v164.functor, &v164.functor, 2);
      }
    }
    v106.f_.f_ = (void (__thiscall *)(vostok::network::world *)) __thiscall vostok::ai::perceptors::enemy_perceptor::`vcall'{4,{flat}};
    m_network_world = thisa->m_network_world;
    v106.l_.a1_.t_ = m_network_world;
    v151.vtable = 0;
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::world>,boost::_bi::list1<boost::_bi::value<vostok::network::world *>>>>(
      (boost::function0<void> *)m_network_world,
      (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::world>,boost::_bi::list1<boost::_bi::value<vostok::network::world *> > > *)&v151,
      v106);
    v69 = g_threads.m_begin + 1;
    if ( v69->m_thread_id == GetCurrentThreadId() )
    {
      boost::function0<void>::operator()(&v151);
    }
    else
    {
      vostok::apc::wait(logic);
      v70 = g_threads.m_begin + 1;
      boost::function<void __cdecl (void)>::operator=(
        &g_threads.m_begin[1].m_callback,
        (const boost::function<void __cdecl(void)> *)&v151);
      v70->m_break_parameters = continue_process_loop;
      _InterlockedExchange(&v70->m_pending, 1);
    }
    if ( v151.vtable )
    {
      if ( ((int)v151.vtable & 1) == 0 )
      {
        v71 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v151.vtable & 0xFFFFFFFE);
        if ( v71 )
          v71(&v151.functor, &v151.functor, 2);
      }
    }
    LOBYTE(v122) = 0;
    *(_DWORD *)&v107.l_.a1_.t_ = v122;
    v107.f_ = vostok::resources::finalize_thread_usage;
    v157.vtable = 0;
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,void (__cdecl *)(bool),boost::_bi::list1<boost::_bi::value<bool>>>>(
      v122,
      (boost::_bi::bind_t<void,void (__cdecl*)(bool),boost::_bi::list1<boost::_bi::value<bool> > > *)&v157,
      v107);
    v72 = g_threads.m_begin + 1;
    if ( v72->m_thread_id != GetCurrentThreadId() )
    {
      vostok::apc::wait(logic);
      v73 = g_threads.m_begin + 1;
      boost::function<void __cdecl (void)>::operator=(&g_threads.m_begin[1].m_callback, &v157);
      v73->m_break_parameters = break_process_loop;
      _InterlockedExchange(&v73->m_pending, 1);
    }
    if ( v157.vtable )
    {
      if ( ((int)v157.vtable & 1) == 0 )
      {
        v74 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v157.vtable & 0xFFFFFFFE);
        if ( v74 )
          v74(&v157.functor, &v157.functor, 2);
      }
    }
    v108.f_ = vostok::network::destroy_world;
    v127 = thisa->m_network_world;
    v108.l_.a1_.t_ = v127;
    v153.vtable = 0;
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,void (__cdecl *)(vostok::network::world * &),boost::_bi::list1<boost::_bi::value<vostok::network::world *>>>>(
      (boost::function0<void> *)v127,
      (boost::_bi::bind_t<void,void (__cdecl*)(vostok::network::world * &),boost::_bi::list1<boost::_bi::value<vostok::network::world *> > > *)&v153,
      v108);
    v75 = g_threads.m_begin + 3;
    if ( v75->m_thread_id == GetCurrentThreadId() )
    {
      boost::function0<void>::operator()(&v153);
    }
    else
    {
      vostok::apc::wait(network);
      v76 = g_threads.m_begin + 3;
      boost::function<void __cdecl (void)>::operator=(
        &g_threads.m_begin[3].m_callback,
        (const boost::function<void __cdecl(void)> *)&v153);
      v76->m_break_parameters = continue_process_loop;
      _InterlockedExchange(&v76->m_pending, 1);
    }
    if ( v153.vtable )
    {
      if ( ((int)v153.vtable & 1) == 0 )
      {
        v77 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v153.vtable & 0xFFFFFFFE);
        if ( v77 )
          v77(&v153.functor, &v153.functor, 2);
      }
    }
    LOBYTE(v122) = 0;
    *(_DWORD *)&v109.l_.a1_.t_ = v122;
    v109.f_ = vostok::resources::finalize_thread_usage;
    v158.vtable = 0;
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,void (__cdecl *)(bool),boost::_bi::list1<boost::_bi::value<bool>>>>(
      v122,
      (boost::_bi::bind_t<void,void (__cdecl*)(bool),boost::_bi::list1<boost::_bi::value<bool> > > *)&v158,
      v109);
    v78 = g_threads.m_begin + 3;
    if ( v78->m_thread_id != GetCurrentThreadId() )
    {
      vostok::apc::wait(network);
      v79 = g_threads.m_begin + 3;
      boost::function<void __cdecl (void)>::operator=(&g_threads.m_begin[3].m_callback, &v158);
      v79->m_break_parameters = break_process_loop;
      _InterlockedExchange(&v79->m_pending, 1);
    }
    if ( v158.vtable )
    {
      if ( ((int)v158.vtable & 1) == 0 )
      {
        v80 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v158.vtable & 0xFFFFFFFE);
        if ( v80 )
          v80(&v158.functor, &v158.functor, 2);
      }
    }
    v110.f_ = vostok::sound::destroy_world;
    m_sound_world = thisa->m_sound_world;
    v110.l_.a1_.t_ = m_sound_world;
    v155.vtable = 0;
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,void (__cdecl *)(vostok::sound::world * &),boost::_bi::list1<boost::_bi::value<vostok::sound::world *>>>>(
      (boost::function0<void> *)m_sound_world,
      (boost::_bi::bind_t<void,void (__cdecl*)(vostok::sound::world * &),boost::_bi::list1<boost::_bi::value<vostok::sound::world *> > > *)&v155,
      v110);
    v81 = g_threads.m_begin + 4;
    if ( v81->m_thread_id == GetCurrentThreadId() )
    {
      boost::function0<void>::operator()(&v155);
    }
    else
    {
      vostok::apc::wait(sound);
      v82 = g_threads.m_begin + 4;
      boost::function<void __cdecl (void)>::operator=(
        &g_threads.m_begin[4].m_callback,
        (const boost::function<void __cdecl(void)> *)&v155);
      v82->m_break_parameters = continue_process_loop;
      _InterlockedExchange(&v82->m_pending, 1);
    }
    if ( v155.vtable )
    {
      if ( ((int)v155.vtable & 1) == 0 )
      {
        v83 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v155.vtable & 0xFFFFFFFE);
        if ( v83 )
          v83(&v155.functor, &v155.functor, 2);
      }
    }
    LOBYTE(v122) = 0;
    *(_DWORD *)&v111.l_.a1_.t_ = v122;
    v111.f_ = vostok::resources::finalize_thread_usage;
    v160.vtable = 0;
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,void (__cdecl *)(bool),boost::_bi::list1<boost::_bi::value<bool>>>>(
      v122,
      (boost::_bi::bind_t<void,void (__cdecl*)(bool),boost::_bi::list1<boost::_bi::value<bool> > > *)&v160,
      v111);
    v84 = g_threads.m_begin + 4;
    if ( v84->m_thread_id != GetCurrentThreadId() )
    {
      vostok::apc::wait(sound);
      v86 = g_threads.m_begin + 4;
      boost::function<void __cdecl (void)>::operator=(&g_threads.m_begin[4].m_callback, &v160);
      v86->m_break_parameters = break_process_loop;
      _InterlockedExchange(&v86->m_pending, 1);
    }
    if ( v160.vtable )
    {
      if ( ((int)v160.vtable & 1) == 0 )
      {
        v87 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v160.vtable & 0xFFFFFFFE);
        if ( v87 )
          v87(&v160.functor, &v160.functor, 2);
      }
    }
    if ( is_editor )
    {
      LODWORD(v123) = thisa;
      v122 = 0;
      v97.f_.f_ = (void (__thiscall *__ptr64)(vostok::engine::engine_world *))(unsigned int)vostok::engine::engine_world::unload_editor;
      *(_QWORD *)&v97.l_.a1_.t_ = v123;
      boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v85, (int)GetCurrentThreadId, v97, v119);
      vostok::apc::run(editor, &callback, continue_process_loop, dont_wait_for_completion);
      boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&callback);
      v169.vtable = 0;
      boost::function0<void>::assign_to<boost::_bi::bind_t<void,void (__cdecl *)(bool),boost::_bi::list1<boost::_bi::value<bool>>>>(
        v88,
        (boost::_bi::bind_t<void,void (__cdecl*)(bool),boost::_bi::list1<boost::_bi::value<bool> > > *)&v169,
        (boost::_bi::bind_t<void,void (__cdecl*)(bool),boost::_bi::list1<boost::_bi::value<bool> > >)(unsigned int)vostok::resources::finalize_thread_usage);
      vostok::apc::run_remote_only(editor, &v169, continue_process_loop, wait_for_completion);
      boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v169);
      v167.vtable = 0;
      boost::function0<void>::assign_to<boost::_bi::bind_t<void,void (__cdecl *)(void),boost::_bi::list0>>(
        0,
        (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)&v167,
        (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0>)(unsigned int)survarium::weapon_user_dead_state::finalize);
      vostok::apc::run_remote_only(editor, &v167, break_process_loop, wait_for_completion);
      boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v167);
    }
    if ( vostok::command_line::key::is_set(&s_build_resources) )
    {
      LOBYTE(v122) = 0;
      *(_DWORD *)&v112.l_.a1_.t_ = v122;
      v112.f_ = vostok::resources::finalize_thread_usage;
      v168.vtable = 0;
      boost::function0<void>::assign_to<boost::_bi::bind_t<void,void (__cdecl *)(bool),boost::_bi::list1<boost::_bi::value<bool>>>>(
        v122,
        (boost::_bi::bind_t<void,void (__cdecl*)(bool),boost::_bi::list1<boost::_bi::value<bool> > > *)&v168,
        v112);
      vostok::apc::run_remote_only(build, &v168, continue_process_loop, wait_for_completion);
      boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v168);
    }
    vostok::apc::wait(logic);
    vostok::apc::wait(network);
    vostok::apc::wait(sound);
    vostok::apc::wait(editor);
    vostok::resources::resources_manager::wait_and_dispatch_callbacks(
      v89,
      a2,
      vostok::resources::g_resources_manager.m_variable,
      1,
      0);
    vostok::engine::engine_world::destroy_render(v90, (int)thisa);
  }
  vostok::engine::engine_world::finalize_resources(this);
}
