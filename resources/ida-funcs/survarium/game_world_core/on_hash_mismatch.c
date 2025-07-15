void __thiscall survarium::game_world_core::on_hash_mismatch(
        survarium::game_world_core *this,
        survarium::game_world_core *time_in_ms,
        unsigned int descriptors_begin,
        boost::detail::function::vtable_base *reader,
        int a5)
{
  bool has_passed_filters; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v6; // ecx
  survarium::game_state_history_item *v7; // esi
  bool v8; // al
  bool v9; // zf
  bool v10; // al
  bool v11; // al
  survarium::players_mask_history_item *i; // eax
  void *v13; // esp
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *m_match_options; // ecx
  float *v15; // eax
  int *v16; // ebx
  unsigned __int8 manager; // al
  bool v18; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v19; // ecx
  bool v20; // al
  const char *v21; // esi
  bool v22; // al
  bool v23; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v24; // ecx
  bool v25; // al
  bool v26; // al
  bool v27; // al
  bool v28; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v29; // ecx
  bool v30; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v31; // esi
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v32; // ecx
  bool v33; // al
  bool v34; // al
  bool v35; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v36; // ecx
  bool v37; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v38; // ecx
  float *v39; // edi
  vostok::buffer_string *v40; // esi
  bool v41; // cf
  bool v42; // zf
  int v43; // eax
  bool v44; // al
  bool v45; // al
  bool v46; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v47; // ecx
  bool v48; // al
  const char *v49; // esi
  const char *v50; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v51; // ecx
  bool v52; // al
  char *m_max_end; // xmm0_4
  bool v54; // al
  char *v55; // xmm0_4
  bool v56; // al
  char *m_end; // xmm0_4
  bool v58; // al
  char *v59; // xmm0_4
  const char *v60; // eax
  vostok::buffer_string *v61; // ecx
  const char *v62; // eax
  vostok::buffer_string *v63; // ecx
  const char *v64; // eax
  vostok::buffer_string *v65; // ecx
  const char *v66; // eax
  vostok::buffer_string *v67; // ecx
  const char *v68; // eax
  vostok::buffer_string *v69; // ecx
  const char *v70; // eax
  char *m_begin_low; // eax
  const char *v72; // eax
  const char *v73; // eax
  char *v74; // ecx
  const char *v75; // eax
  const char *v76; // eax
  unsigned int v77; // esi
  vostok::buffer_string *j; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v79; // ecx
  bool v80; // al
  void (__cdecl *v81)(const boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, boost::detail::function::functor_manager_operation_type); // esi
  vostok::buffer_string *k; // ecx
  bool v83; // al
  char *v84; // eax
  vostok::buffer_string *v85; // esi
  _BYTE *v86; // edi
  vostok::buffer_string *v87; // ecx
  bool v88; // cf
  bool v89; // zf
  int v90; // eax
  vostok::buffer_string *v91; // esi
  vostok::buffer_string *v92; // ecx
  const char *v93; // edi
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v94; // ecx
  int v95; // edi
  char *v96; // eax
  unsigned __int8 v97; // al
  bool v98; // al
  bool v99; // al
  bool v100; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *vtable; // esi
  bool v102; // al
  bool v103; // al
  void *obj_ptr; // eax
  vostok::network_core::mutable_buffer *v105; // ecx
  double v106; // [esp+20h] [ebp-120C0h]
  double v107; // [esp+20h] [ebp-120C0h]
  double v108; // [esp+20h] [ebp-120C0h]
  double v109; // [esp+20h] [ebp-120C0h]
  double v110; // [esp+28h] [ebp-120B8h]
  double v111; // [esp+28h] [ebp-120B8h]
  double v112; // [esp+28h] [ebp-120B8h]
  double v113; // [esp+28h] [ebp-120B8h]
  double v114; // [esp+30h] [ebp-120B0h]
  double v115; // [esp+30h] [ebp-120B0h]
  double v116; // [esp+30h] [ebp-120B0h]
  double v117; // [esp+30h] [ebp-120B0h]
  double v118; // [esp+38h] [ebp-120A8h]
  double v119; // [esp+38h] [ebp-120A8h]
  double v120; // [esp+38h] [ebp-120A8h]
  double v121; // [esp+38h] [ebp-120A8h]
  double v122; // [esp+40h] [ebp-120A0h]
  double v123; // [esp+40h] [ebp-120A0h]
  double v124; // [esp+40h] [ebp-120A0h]
  double v125; // [esp+40h] [ebp-120A0h]
  char *v126; // [esp+40h] [ebp-120A0h]
  unsigned int v127; // [esp+44h] [ebp-1209Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v128; // [esp+44h] [ebp-1209Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v129; // [esp+44h] [ebp-1209Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v130; // [esp+44h] [ebp-1209Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v131; // [esp+44h] [ebp-1209Ch]
  int v132; // [esp+44h] [ebp-1209Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v133; // [esp+44h] [ebp-1209Ch]
  char *m_begin; // [esp+44h] [ebp-1209Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v135; // [esp+44h] [ebp-1209Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v136; // [esp+44h] [ebp-1209Ch]
  void (__cdecl *v137)(const boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, boost::detail::function::functor_manager_operation_type); // [esp+44h] [ebp-1209Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v138; // [esp+44h] [ebp-1209Ch]
  int v139; // [esp+44h] [ebp-1209Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v140; // [esp+44h] [ebp-1209Ch]
  void (__cdecl *v141)(const boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, boost::detail::function::functor_manager_operation_type); // [esp+44h] [ebp-1209Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v142; // [esp+44h] [ebp-1209Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v143; // [esp+44h] [ebp-1209Ch]
  void (__cdecl *v144)(const boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, boost::detail::function::functor_manager_operation_type); // [esp+44h] [ebp-1209Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v145; // [esp+44h] [ebp-1209Ch]
  int v146; // [esp+44h] [ebp-1209Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v147; // [esp+44h] [ebp-1209Ch]
  void (__cdecl *v148)(const boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, boost::detail::function::functor_manager_operation_type); // [esp+44h] [ebp-1209Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v149; // [esp+44h] [ebp-1209Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v150; // [esp+44h] [ebp-1209Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v151; // [esp+44h] [ebp-1209Ch]
  int v152; // [esp+44h] [ebp-1209Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v153; // [esp+44h] [ebp-1209Ch]
  void (__cdecl *v154)(const boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, boost::detail::function::functor_manager_operation_type); // [esp+44h] [ebp-1209Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v155; // [esp+44h] [ebp-1209Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v156; // [esp+44h] [ebp-1209Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v157; // [esp+44h] [ebp-1209Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v158; // [esp+44h] [ebp-1209Ch]
  int v159; // [esp+44h] [ebp-1209Ch]
  vostok::buffer_string *v160; // [esp+44h] [ebp-1209Ch]
  vostok::buffer_string *v161; // [esp+44h] [ebp-1209Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v162; // [esp+44h] [ebp-1209Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v163; // [esp+44h] [ebp-1209Ch]
  vostok::buffer_string *v164; // [esp+44h] [ebp-1209Ch]
  vostok::buffer_string *v165; // [esp+44h] [ebp-1209Ch]
  vostok::buffer_string *v166; // [esp+44h] [ebp-1209Ch]
  vostok::buffer_string *v167; // [esp+44h] [ebp-1209Ch]
  const char *v168; // [esp+44h] [ebp-1209Ch]
  vostok::buffer_string *v169; // [esp+44h] [ebp-1209Ch]
  vostok::buffer_string *v170; // [esp+44h] [ebp-1209Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v171; // [esp+44h] [ebp-1209Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v172; // [esp+44h] [ebp-1209Ch]
  int v173; // [esp+44h] [ebp-1209Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v174; // [esp+44h] [ebp-1209Ch]
  int v175; // [esp+44h] [ebp-1209Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v176; // [esp+44h] [ebp-1209Ch]
  void (__cdecl *v177)(const boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, boost::detail::function::functor_manager_operation_type); // [esp+44h] [ebp-1209Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v178; // [esp+44h] [ebp-1209Ch]
  const char *v179; // [esp+48h] [ebp-12098h] BYREF
  survarium::game_world_core *v180; // [esp+10044h] [ebp-209Ch]
  _BYTE *v181; // [esp+10058h] [ebp-2088h] BYREF
  _BYTE *v182; // [esp+1005Ch] [ebp-2084h]
  char *v183; // [esp+10060h] [ebp-2080h]
  _BYTE v184[8192]; // [esp+10064h] [ebp-207Ch] BYREF
  char v185; // [esp+12064h] [ebp-7Ch] BYREF
  int v186; // [esp+1206Ch] [ebp-74h] BYREF
  vostok::buffer_string *v187; // [esp+12070h] [ebp-70h]
  HINSTANCE__ *v188; // [esp+12074h] [ebp-6Ch]
  int v189; // [esp+12078h] [ebp-68h]
  int v190; // [esp+1207Ch] [ebp-64h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v191; // [esp+12080h] [ebp-60h] BYREF
  char *v192; // [esp+120A0h] [ebp-40h]
  vostok::buffer_string *v193; // [esp+120A4h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v194; // [esp+120A8h] [ebp-38h] BYREF
  char *profile_name; // [esp+120C8h] [ebp-18h]
  const char *v196; // [esp+120CCh] [ebp-14h]
  vostok::buffer_string *v197; // [esp+120D0h] [ebp-10h]
  float *v198; // [esp+120D4h] [ebp-Ch]
  char *right; // [esp+120D8h] [ebp-8h]
  int v200; // [esp+120DCh] [ebp-4h]
  unsigned int time_in_msa; // [esp+120ECh] [ebp+Ch]
  char time_in_ms_3; // [esp+120EFh] [ebp+Fh]

  v200 = 0;
  if ( !vostok::core::g_log_filter_tree
    || (has_passed_filters = vostok::logging::has_passed_filters(
                               (vostok::logging::filter_tree *)"net_hash",
                               (const char *)3),
        this = v180,
        has_passed_filters) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
      &v191);
    v200 = 1;
    vostok::logging::append(
      &v191,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\game_world_core.cpp",
      0x5E2u,
      "void __thiscall survarium::game_world_core::on_hash_mismatch(const unsigned int,const struct vostok::network_core:"
      ":buffer_writer::serialization_operation_descriptor *,class vostok::network_core::buffer_reader &)",
      "net_hash",
      warning,
      "hash MISMATCH : %d.%03d",
      descriptors_begin / 0x3E8,
      descriptors_begin % 0x3E8);
  }
  if ( (v200 & 1) != 0 )
  {
    v200 &= ~1u;
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
      (int *)&v191);
  }
  v7 = survarium::history<survarium::game_state_history_item,vostok::memory::single_size_buffer_allocator<760148,vostok::threading::single_threading_policy>>::nearest_item<stlp_std::less_equal>(
         (survarium::history<survarium::game_state_history_item,vostok::memory::single_size_buffer_allocator<760148,vostok::threading::single_threading_policy> > *)this,
         (int)&time_in_ms->m_game_states_history,
         descriptors_begin);
  if ( !v7 )
  {
    if ( !vostok::core::g_log_filter_tree
      || (v8 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)3),
          v6 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v180,
          v8) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v6,
        &v191);
      v200 |= 2u;
      vostok::logging::append(
        &v191,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\game_world_core.cpp",
        0x5E6u,
        "void __thiscall survarium::game_world_core::on_hash_mismatch(const unsigned int,const struct vostok::network_cor"
        "e::buffer_writer::serialization_operation_descriptor *,class vostok::network_core::buffer_reader &)",
        "net_hash",
        warning,
        "hash mismatch received, but item was deleted, SKIPPING");
    }
    v9 = (v200 & 2) == 0;
LABEL_11:
    if ( !v9 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v6,
        (int *)&v191);
    *(_DWORD *)(a5 + 4) = *(_DWORD *)a5 + *(_DWORD *)(a5 + 8);
    return;
  }
  if ( *(_DWORD *)&v7->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B9937 + 1] != descriptors_begin )
  {
    if ( !vostok::core::g_log_filter_tree
      || (v10 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)3),
          v6 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v180,
          v10) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v6,
        &v191);
      v200 |= 4u;
      vostok::logging::append(
        &v191,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\game_world_core.cpp",
        0x5ECu,
        "void __thiscall survarium::game_world_core::on_hash_mismatch(const unsigned int,const struct vostok::network_cor"
        "e::buffer_writer::serialization_operation_descriptor *,class vostok::network_core::buffer_reader &)",
        "net_hash",
        warning,
        "hash mismatch received, but item was not yet created after RESYNC, SKIPPING");
    }
    v9 = (v200 & 4) == 0;
    goto LABEL_11;
  }
  if ( v7->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B993F + 2] )
  {
    if ( !vostok::core::g_log_filter_tree
      || (v11 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)3),
          v6 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v180,
          v11) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v6,
        &v191);
      v200 |= 8u;
      vostok::logging::append(
        &v191,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\game_world_core.cpp",
        0x5F2u,
        "void __thiscall survarium::game_world_core::on_hash_mismatch(const unsigned int,const struct vostok::network_cor"
        "e::buffer_writer::serialization_operation_descriptor *,class vostok::network_core::buffer_reader &)",
        "net_hash",
        warning,
        "hash mismatch received, but item was received for RESYNC, SKIPPING");
    }
    v9 = (v200 & 8) == 0;
    goto LABEL_11;
  }
  survarium::game_world_core::fill_debug_info(time_in_ms, v7);
  for ( i = time_in_ms->m_active_clients_history.m_items.m_last; ; i = i->prev )
  {
    if ( !i )
    {
      time_in_msa = 0;
      goto LABEL_29;
    }
    if ( i->time_in_ms <= descriptors_begin )
      break;
  }
  time_in_msa = (unsigned int)i;
LABEL_29:
  v13 = alloca((int)&_sbh_sizeHeaderList);
  v187 = (vostok::buffer_string *)&v179;
  v191.functor.vostok_pointer_size_alignment[5] = &v186;
  v186 = 0;
  v188 = &_sbh_sizeHeaderList;
  v189 = 0;
  v127 = *(_DWORD *)(time_in_msa + 8);
  v191.functor.obj_ptr = 0;
  *((_QWORD *)&v191.functor.data + 1) = 0;
  *(&v191.functor.data + 16) = -1;
  survarium::game_state_history_item::serialize(0, (int)v7, (vostok::network_core::buffer_writer *)&v191.functor, v127);
  v196 = 0;
  v193 = 0;
  v181 = v184;
  v182 = v184;
  v183 = &v185;
  v197 = v187;
  v15 = *(float **)(a5 + 4);
  v184[0] = 0;
  v16 = *(int **)&v7->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B9949 + 3];
  v198 = v15;
  time_in_ms_3 = -1;
  if ( !v16 )
    goto LABEL_235;
  while ( reader )
  {
    LOBYTE(m_match_options) = *((_BYTE *)v16 + 28);
    if ( (_BYTE)m_match_options == 0xFF )
      profile_name = "<generic>";
    else
      profile_name = time_in_ms->m_match_options->player_profiles.elems[(unsigned __int8)m_match_options].profile_name;
    manager = (unsigned __int8)reader[7].manager;
    if ( manager != (_BYTE)m_match_options )
    {
      if ( manager == 0xFF )
      {
        right = "<generic>";
      }
      else
      {
        m_match_options = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)time_in_ms->m_match_options;
        right = (char *)(&m_match_options->functor + 62 * manager);
      }
      if ( !vostok::core::g_log_filter_tree
        || (v18 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)3),
            m_match_options = v128,
            v18) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          m_match_options,
          &v194);
        v200 |= 0x10u;
        vostok::logging::append(
          &v194,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\game_world_core.cpp",
          0x611u,
          "void __thiscall survarium::game_world_core::on_hash_mismatch(const unsigned int,const struct vostok::network_c"
          "ore::buffer_writer::serialization_operation_descriptor *,class vostok::network_core::buffer_reader &)",
          "net_hash",
          warning,
          "PLAYERS differ: %s => %s",
          profile_name,
          right);
      }
      if ( (v200 & 0x10) != 0 )
      {
        v200 &= ~0x10u;
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)m_match_options,
          (int *)&v194);
      }
    }
    v19 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)reader;
    if ( (void (__cdecl *)(const boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, boost::detail::function::functor_manager_operation_type))v16[6] != reader[6].manager )
    {
      if ( time_in_ms_3 != *((_BYTE *)v16 + 28) )
      {
        time_in_ms_3 = *((_BYTE *)v16 + 28);
        if ( !vostok::core::g_log_filter_tree
          || (v20 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)3),
              v19 = v129,
              v20) )
        {
          boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
            v19,
            &v194);
          v200 |= 0x20u;
          vostok::logging::append(
            &v194,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\game_world_core.cpp",
            0x616u,
            "void __thiscall survarium::game_world_core::on_hash_mismatch(const unsigned int,const struct vostok::network"
            "_core::buffer_writer::serialization_operation_descriptor *,class vostok::network_core::buffer_reader &)",
            "net_hash",
            warning,
            "PLAYER : %s",
            profile_name);
        }
        if ( (v200 & 0x20) != 0 )
        {
          v200 &= ~0x20u;
          boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
            (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v19,
            (int *)&v194);
        }
      }
      v21 = v196;
      if ( v196
        && (v19 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v193,
            (char *)*((_DWORD *)v196 + 6) == v193[2].m_begin)
        && !vostok::strings::compare((const char *)v16[1], (const char *)reader[1].manager) )
      {
        if ( !vostok::core::g_log_filter_tree
          || (v22 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)3),
              v19 = v130,
              v22) )
        {
          boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
            v19,
            &v194);
          v200 |= 0x40u;
          vostok::logging::append(
            &v194,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\game_world_core.cpp",
            0x61Au,
            "void __thiscall survarium::game_world_core::on_hash_mismatch(const unsigned int,const struct vostok::network"
            "_core::buffer_writer::serialization_operation_descriptor *,class vostok::network_core::buffer_reader &)",
            "net_hash",
            warning,
            "THE LAST EQUAL:");
          v21 = v196;
        }
        if ( (v200 & 0x40) != 0 )
        {
          v200 &= ~0x40u;
          boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
            (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v19,
            (int *)&v194);
          v21 = v196;
        }
        if ( !vostok::core::g_log_filter_tree
          || (v23 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)3),
              v19 = v131,
              v23) )
        {
          boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
            v19,
            &v194);
          v132 = *((_DWORD *)v196 + 6);
          v200 |= 0x80u;
          vostok::logging::append(
            &v194,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\game_world_core.cpp",
            0x61Bu,
            "void __thiscall survarium::game_world_core::on_hash_mismatch(const unsigned int,const struct vostok::network"
            "_core::buffer_writer::serialization_operation_descriptor *,class vostok::network_core::buffer_reader &)",
            "net_hash",
            warning,
            "%s(%d): %s - %s, %s[%d]",
            *((const char **)v196 + 4),
            *((_DWORD *)v196 + 5),
            *((const char **)v196 + 2),
            *((const char **)v196 + 3),
            *((const char **)v196 + 1),
            v132);
          v21 = v196;
        }
        if ( (v200 & 0x80u) != 0 )
        {
          v200 &= ~0x80u;
          boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
            (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v19,
            (int *)&v194);
          v21 = v196;
        }
        vostok::debug::printf(
          "%s(%d): %s - %s, %s[%d]\n",
          *((const char **)v21 + 4),
          *((_DWORD *)v21 + 5),
          *((const char **)v21 + 2),
          *((const char **)v21 + 3),
          *((const char **)v21 + 1),
          *((_DWORD *)v21 + 6));
        if ( !vostok::core::g_log_filter_tree
          || (v25 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)3),
              v24 = v133,
              v25) )
        {
          boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
            v24,
            &v194);
          m_begin = v193[2].m_begin;
          v200 |= 0x100u;
          vostok::logging::append(
            &v194,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\game_world_core.cpp",
            0x61Du,
            "void __thiscall survarium::game_world_core::on_hash_mismatch(const unsigned int,const struct vostok::network"
            "_core::buffer_writer::serialization_operation_descriptor *,class vostok::network_core::buffer_reader &)",
            "net_hash",
            warning,
            "%s(%d): %s - %s, %s[%d]",
            v193[1].m_end,
            v193[1].m_max_end,
            v193->m_max_end,
            v193[1].m_begin,
            v193->m_end,
            m_begin);
        }
        if ( (v200 & 0x100) != 0 )
        {
          v200 &= ~0x100u;
          boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
            (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v24,
            (int *)&v194);
        }
        vostok::debug::printf(
          "%s(%d): %s - %s, %s[%d]\n",
          v193[1].m_end,
          v193[1].m_max_end,
          v193->m_max_end,
          v193[1].m_begin,
          v193->m_end,
          v193[2].m_begin);
      }
      else
      {
        if ( !vostok::core::g_log_filter_tree
          || (v26 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)3),
              v19 = v135,
              v26) )
        {
          boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
            v19,
            &v194);
          v200 |= 0x200u;
          vostok::logging::append(
            &v194,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\game_world_core.cpp",
            0x621u,
            "void __thiscall survarium::game_world_core::on_hash_mismatch(const unsigned int,const struct vostok::network"
            "_core::buffer_writer::serialization_operation_descriptor *,class vostok::network_core::buffer_reader &)",
            "net_hash",
            warning,
            "differs from the very start!");
        }
        if ( (v200 & 0x200) != 0 )
        {
          v200 &= ~0x200u;
          boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
            (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v19,
            (int *)&v194);
        }
      }
      if ( !vostok::core::g_log_filter_tree
        || (v27 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)3),
            v19 = v136,
            v27) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v19,
          &v194);
        v137 = reader[6].manager;
        v200 |= 0x400u;
        vostok::logging::append(
          &v194,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\game_world_core.cpp",
          0x623u,
          "void __thiscall survarium::game_world_core::on_hash_mismatch(const unsigned int,const struct vostok::network_c"
          "ore::buffer_writer::serialization_operation_descriptor *,class vostok::network_core::buffer_reader &)",
          "net_hash",
          warning,
          "VALUE SIZE and TYPES differ: %s[%d] => %s[%d]",
          (const char *)v16[1],
          v16[6],
          (const char *)reader[1].manager,
          v137);
      }
      if ( (v200 & 0x400) != 0 )
      {
        v200 &= ~0x400u;
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v19,
          (int *)&v194);
      }
      if ( !vostok::core::g_log_filter_tree
        || (v28 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)3),
            v19 = v138,
            v28) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v19,
          &v194);
        v139 = v16[6];
        v200 |= 0x800u;
        vostok::logging::append(
          &v194,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\game_world_core.cpp",
          0x624u,
          "void __thiscall survarium::game_world_core::on_hash_mismatch(const unsigned int,const struct vostok::network_c"
          "ore::buffer_writer::serialization_operation_descriptor *,class vostok::network_core::buffer_reader &)",
          "net_hash",
          warning,
          "%s(%d): %s - %s, %s[%d]",
          (const char *)v16[4],
          v16[5],
          (const char *)v16[2],
          (const char *)v16[3],
          (const char *)v16[1],
          v139);
      }
      if ( (v200 & 0x800) != 0 )
      {
        v200 &= ~0x800u;
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v19,
          (int *)&v194);
      }
      vostok::debug::printf(
        "%s(%d): %s - %s, %s[%d]\n",
        (const char *)v16[4],
        v16[5],
        (const char *)v16[2],
        (const char *)v16[3],
        (const char *)v16[1],
        v16[6]);
      if ( !vostok::core::g_log_filter_tree
        || (v30 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)3),
            v29 = v140,
            v30) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v29,
          &v194);
        v141 = reader[6].manager;
        v200 |= 0x1000u;
        vostok::logging::append(
          &v194,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\game_world_core.cpp",
          0x626u,
          "void __thiscall survarium::game_world_core::on_hash_mismatch(const unsigned int,const struct vostok::network_c"
          "ore::buffer_writer::serialization_operation_descriptor *,class vostok::network_core::buffer_reader &)",
          "net_hash",
          warning,
          "%s(%d): %s - %s, %s[%d]",
          (const char *)reader[4].manager,
          reader[5].manager,
          (const char *)reader[2].manager,
          (const char *)reader[3].manager,
          (const char *)reader[1].manager,
          v141);
      }
      if ( (v200 & 0x1000) != 0 )
      {
        v200 &= ~0x1000u;
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v29,
          (int *)&v194);
      }
      vostok::debug::printf(
        "%s(%d): %s - %s, %s[%d]\n",
        (const char *)reader[4].manager,
        reader[5].manager,
        (const char *)reader[2].manager,
        (const char *)reader[3].manager,
        (const char *)reader[1].manager,
        reader[6].manager);
    }
    v31 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)reader;
    if ( vostok::strings::compare((const char *)v16[1], (const char *)reader[1].manager) )
    {
      if ( time_in_ms_3 != *((_BYTE *)v16 + 28) )
      {
        time_in_ms_3 = *((_BYTE *)v16 + 28);
        if ( !vostok::core::g_log_filter_tree
          || (v33 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)3),
              v32 = v142,
              v33) )
        {
          boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
            v32,
            &v194);
          v200 |= 0x2000u;
          vostok::logging::append(
            &v194,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\game_world_core.cpp",
            0x62Du,
            "void __thiscall survarium::game_world_core::on_hash_mismatch(const unsigned int,const struct vostok::network"
            "_core::buffer_writer::serialization_operation_descriptor *,class vostok::network_core::buffer_reader &)",
            "net_hash",
            warning,
            "PLAYER : %s",
            profile_name);
        }
        if ( (v200 & 0x2000) != 0 )
        {
          v200 &= ~0x2000u;
          boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
            (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v32,
            (int *)&v194);
        }
      }
      if ( !vostok::core::g_log_filter_tree
        || (v34 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)3),
            v32 = v143,
            v34) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v32,
          &v194);
        v144 = reader[6].manager;
        v200 |= 0x4000u;
        vostok::logging::append(
          &v194,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\game_world_core.cpp",
          0x630u,
          "void __thiscall survarium::game_world_core::on_hash_mismatch(const unsigned int,const struct vostok::network_c"
          "ore::buffer_writer::serialization_operation_descriptor *,class vostok::network_core::buffer_reader &)",
          "net_hash",
          warning,
          "TYPES differ: %s[%d] => %s[%d]",
          (const char *)v16[1],
          v16[6],
          (const char *)reader[1].manager,
          v144);
      }
      if ( (v200 & 0x4000) != 0 )
      {
        v200 &= ~0x4000u;
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v32,
          (int *)&v194);
      }
      if ( !vostok::core::g_log_filter_tree
        || (v35 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)3),
            v32 = v145,
            v35) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v32,
          &v194);
        v146 = v16[6];
        v200 |= 0x8000u;
        vostok::logging::append(
          &v194,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\game_world_core.cpp",
          0x631u,
          "void __thiscall survarium::game_world_core::on_hash_mismatch(const unsigned int,const struct vostok::network_c"
          "ore::buffer_writer::serialization_operation_descriptor *,class vostok::network_core::buffer_reader &)",
          "net_hash",
          warning,
          "%s(%d): %s - %s, %s[%d]",
          (const char *)v16[4],
          v16[5],
          (const char *)v16[2],
          (const char *)v16[3],
          (const char *)v16[1],
          v146);
      }
      if ( (v200 & 0x8000) != 0 )
      {
        v200 &= ~0x8000u;
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v32,
          (int *)&v194);
      }
      vostok::debug::printf(
        "%s(%d): %s - %s, %s[%d]\n",
        (const char *)v16[4],
        v16[5],
        (const char *)v16[2],
        (const char *)v16[3],
        (const char *)v16[1],
        v16[6]);
      if ( !vostok::core::g_log_filter_tree
        || (v37 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)3),
            v36 = v147,
            v37) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v36,
          &v194);
        v148 = reader[6].manager;
        v200 |= (unsigned int)&_sbh_sizeHeaderList;
        vostok::logging::append(
          &v194,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\game_world_core.cpp",
          0x633u,
          "void __thiscall survarium::game_world_core::on_hash_mismatch(const unsigned int,const struct vostok::network_c"
          "ore::buffer_writer::serialization_operation_descriptor *,class vostok::network_core::buffer_reader &)",
          "net_hash",
          warning,
          "%s(%d): %s - %s, %s[%d]",
          (const char *)reader[4].manager,
          reader[5].manager,
          (const char *)reader[2].manager,
          (const char *)reader[3].manager,
          (const char *)reader[1].manager,
          v148);
      }
      if ( ((unsigned int)&_sbh_sizeHeaderList & v200) != 0 )
      {
        v200 &= ~0x10000u;
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v36,
          (int *)&v194);
      }
      v31 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)reader;
      vostok::debug::printf(
        "%s(%d): %s - %s, %s[%d]\n",
        (const char *)reader[4].manager,
        reader[5].manager,
        (const char *)reader[2].manager,
        (const char *)reader[3].manager,
        (const char *)reader[1].manager,
        reader[6].manager);
    }
    v38 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v16[6];
    if ( v38 == v31->functor.bound_memfunc_ptr.obj_ptr )
    {
      v39 = v198;
      v40 = v197;
      v43 = 0;
      v41 = 0;
      v42 = 1;
      do
      {
        if ( !v38 )
          break;
        v41 = LOBYTE(v40->m_begin) < *(_BYTE *)v39;
        v42 = LOBYTE(v40->m_begin) == *(_BYTE *)v39;
        v40 = (vostok::buffer_string *)((char *)v40 + 1);
        v39 = (float *)((char *)v39 + 1);
        v38 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)((char *)v38 - 1);
      }
      while ( v42 );
      if ( !v42 )
        v43 = -v41 - (v41 - 1);
      if ( !v43 )
        goto LABEL_221;
    }
    if ( time_in_ms_3 != *((_BYTE *)v16 + 28) )
    {
      time_in_ms_3 = *((_BYTE *)v16 + 28);
      if ( !vostok::core::g_log_filter_tree
        || (v44 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)3),
            v38 = v149,
            v44) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v38,
          &v194);
        v200 |= (unsigned int)&loc_20000;
        vostok::logging::append(
          &v194,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\game_world_core.cpp",
          0x63Du,
          "void __thiscall survarium::game_world_core::on_hash_mismatch(const unsigned int,const struct vostok::network_c"
          "ore::buffer_writer::serialization_operation_descriptor *,class vostok::network_core::buffer_reader &)",
          "net_hash",
          warning,
          "PLAYER : %s",
          profile_name);
      }
      if ( ((unsigned int)&loc_20000 & v200) != 0 )
      {
        v200 &= ~0x20000u;
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v38,
          (int *)&v194);
      }
    }
    if ( !vostok::core::g_log_filter_tree
      || (v45 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)3),
          v38 = v150,
          v45) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v38,
        &v194);
      v200 |= (unsigned int)&loc_3FFFF + 1;
      vostok::logging::append(
        &v194,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\game_world_core.cpp",
        0x640u,
        "void __thiscall survarium::game_world_core::on_hash_mismatch(const unsigned int,const struct vostok::network_cor"
        "e::buffer_writer::serialization_operation_descriptor *,class vostok::network_core::buffer_reader &)",
        "net_hash",
        warning,
        "VALUES differ:");
    }
    if ( (((unsigned int)&loc_3FFFF + 1) & v200) != 0 )
    {
      v200 &= ~0x40000u;
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v38,
        (int *)&v194);
    }
    if ( !vostok::core::g_log_filter_tree
      || (v46 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)3),
          v38 = v151,
          v46) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v38,
        &v194);
      v152 = v16[6];
      v200 |= 0x80000u;
      vostok::logging::append(
        &v194,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\game_world_core.cpp",
        0x641u,
        "void __thiscall survarium::game_world_core::on_hash_mismatch(const unsigned int,const struct vostok::network_cor"
        "e::buffer_writer::serialization_operation_descriptor *,class vostok::network_core::buffer_reader &)",
        "net_hash",
        warning,
        "[L]%s(%d): %s - %s, %s[%d]",
        (const char *)v16[4],
        v16[5],
        (const char *)v16[2],
        (const char *)v16[3],
        (const char *)v16[1],
        v152);
    }
    if ( (v200 & 0x80000) != 0 )
    {
      v200 &= ~0x80000u;
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v38,
        (int *)&v194);
    }
    vostok::debug::printf(
      "%s(%d): %s - %s, %s[%d]\n",
      (const char *)v16[4],
      v16[5],
      (const char *)v16[2],
      (const char *)v16[3],
      (const char *)v16[1],
      v16[6]);
    if ( !vostok::core::g_log_filter_tree
      || (v48 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)3),
          v47 = v153,
          v48) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v47,
        &v194);
      v154 = reader[6].manager;
      v200 |= (unsigned int)&loc_100000;
      vostok::logging::append(
        &v194,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\game_world_core.cpp",
        0x643u,
        "void __thiscall survarium::game_world_core::on_hash_mismatch(const unsigned int,const struct vostok::network_cor"
        "e::buffer_writer::serialization_operation_descriptor *,class vostok::network_core::buffer_reader &)",
        "net_hash",
        warning,
        "[R]%s(%d): %s - %s, %s[%d]",
        (const char *)reader[4].manager,
        reader[5].manager,
        (const char *)reader[2].manager,
        (const char *)reader[3].manager,
        (const char *)reader[1].manager,
        v154);
    }
    if ( ((unsigned int)&loc_100000 & v200) != 0 )
    {
      v200 &= ~0x100000u;
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v47,
        (int *)&v194);
    }
    vostok::debug::printf(
      "%s(%d): %s - %s, %s[%d]\n",
      (const char *)reader[4].manager,
      reader[5].manager,
      (const char *)reader[2].manager,
      (const char *)reader[3].manager,
      (const char *)reader[1].manager,
      reader[6].manager);
    v182 = v181;
    *v181 = 0;
    v49 = (const char *)v16[1];
    v50 = type_info::name(&vostok::math::float4x4 `RTTI Type Descriptor', &__type_info_root_node);
    if ( vostok::strings::compare(v50, v49) )
    {
      right = (char *)v16[1];
      v60 = type_info::name(&float `RTTI Type Descriptor', &__type_info_root_node);
      if ( !vostok::strings::compare(v60, right) )
        vostok::buffer_string::appendf(
          &v181,
          v61,
          (vostok::buffer_string *)"%.8g => %.8g, difference = %.8g ",
          (const char *)COERCE_UNSIGNED_INT64(*(float *)&v197->m_begin),
          (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(*(float *)&v197->m_begin)),
          *v198,
          (float)(*(float *)&v197->m_begin - *v198));
      right = (char *)v16[1];
      v62 = type_info::name(&vostok::math::float2 `RTTI Type Descriptor', &__type_info_root_node);
      if ( !vostok::strings::compare(v62, right) )
        vostok::buffer_string::appendf(
          &v181,
          v63,
          (vostok::buffer_string *)"[%.8g][%.8g] -> [%.8g][%.8g] ",
          (const char *)COERCE_UNSIGNED_INT64(*(float *)&v197->m_begin),
          (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(*(float *)&v197->m_begin)),
          *(float *)&v197->m_end,
          *v198,
          v198[1]);
      right = (char *)v16[1];
      v64 = type_info::name(&vostok::math::float3 `RTTI Type Descriptor', &__type_info_root_node);
      if ( vostok::strings::compare(v64, right) )
      {
        right = (char *)v16[1];
        v66 = type_info::name(&unsigned __int64 `RTTI Type Descriptor', &__type_info_root_node);
        if ( vostok::strings::compare(v66, right) )
        {
          right = (char *)v16[1];
          v68 = type_info::name(&unsigned int `RTTI Type Descriptor', &__type_info_root_node);
          if ( vostok::strings::compare(v68, right) )
          {
            right = (char *)v16[1];
            v70 = type_info::name(&unsigned short `RTTI Type Descriptor', &__type_info_root_node);
            if ( vostok::strings::compare(v70, right) )
            {
              right = (char *)v16[1];
              v72 = type_info::name(&unsigned char `RTTI Type Descriptor', &__type_info_root_node);
              if ( vostok::strings::compare(v72, right) )
              {
                right = (char *)v16[1];
                v73 = type_info::name(&bool `RTTI Type Descriptor', &__type_info_root_node);
                if ( vostok::strings::compare(v73, right) )
                {
                  right = (char *)v16[1];
                  v76 = type_info::name(&void * `RTTI Type Descriptor', &__type_info_root_node);
                  if ( !vostok::strings::compare(v76, right) )
                  {
                    v182 = v181;
                    *v181 = 0;
                    vostok::buffer_string::appendf(
                      &v181,
                      v65,
                      (vostok::buffer_string *)"u8 const local_buffer[] = { ",
                      v179);
                    v77 = 0;
                    for ( j = v160; v77 < v16[6]; j = v161 )
                      vostok::buffer_string::appendf(
                        &v181,
                        j,
                        (vostok::buffer_string *)"0x%02x, ",
                        (const char *)*((unsigned __int8 *)&v197->m_begin + v77++));
                    vostok::buffer_string::appendf(&v181, j, (vostok::buffer_string *)"};", v179);
                    v79 = v162;
                    if ( !vostok::core::g_log_filter_tree
                      || (v80 = vostok::logging::has_passed_filters(
                                  (vostok::logging::filter_tree *)"net_hash",
                                  (const char *)3),
                          v79 = v163,
                          v80) )
                    {
                      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
                        v79,
                        &v194);
                      v200 |= (unsigned int)&s_ui_commands_allocator.m_buffer[18812576];
                      vostok::logging::append(
                        &v194,
                        (void *const)vostok::core::g_log_flags,
                        &vostok::core::g_log_format,
                        ".\\game_world_core.cpp",
                        0x666u,
                        "void __thiscall survarium::game_world_core::on_hash_mismatch(const unsigned int,const struct vos"
                        "tok::network_core::buffer_writer::serialization_operation_descriptor *,class vostok::network_cor"
                        "e::buffer_reader &)",
                        "net_hash",
                        warning,
                        (char *)&stru_7F9BE8.allocator,
                        v181);
                    }
                    if ( ((unsigned int)&s_ui_commands_allocator.m_buffer[18812576] & v200) != 0 )
                    {
                      v200 &= ~0x2000000u;
                      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
                        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v79,
                        (int *)&v194);
                    }
                    v182 = v181;
                    *v181 = 0;
                    vostok::buffer_string::appendf(
                      &v181,
                      (vostok::buffer_string *)v79,
                      (vostok::buffer_string *)"u8 const remote_buffer[] = { ",
                      v179);
                    v81 = 0;
                    for ( k = v164; (char *)v81 < (char *)reader[6].manager; k = v165 )
                    {
                      vostok::buffer_string::appendf(
                        &v181,
                        k,
                        (vostok::buffer_string *)"0x%02x, ",
                        (const char *)*((unsigned __int8 *)v198 + (_DWORD)v81));
                      v81 = (void (__cdecl *)(const boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, boost::detail::function::functor_manager_operation_type))((char *)v81 + 1);
                    }
                    vostok::buffer_string::appendf(&v181, k, (vostok::buffer_string *)"};", v179);
                    v65 = v166;
                  }
                }
                else
                {
                  v74 = "true";
                  if ( !*(_BYTE *)v198 )
                    v74 = "false";
                  v75 = "true";
                  if ( !LOBYTE(v197->m_begin) )
                    v75 = "false";
                  vostok::buffer_string::appendf(
                    &v181,
                    (vostok::buffer_string *)v74,
                    (vostok::buffer_string *)"%s -> %s ",
                    v75,
                    v74);
                }
                goto LABEL_196;
              }
              v159 = *(unsigned __int8 *)v198;
              m_begin_low = (char *)LOBYTE(v197->m_begin);
            }
            else
            {
              v159 = *(unsigned __int16 *)v198;
              m_begin_low = (char *)LOWORD(v197->m_begin);
            }
            v126 = m_begin_low;
          }
          else
          {
            v159 = *(_DWORD *)v198;
            v126 = v197->m_begin;
          }
          vostok::buffer_string::appendf(&v181, v69, (vostok::buffer_string *)"%d -> %d ", v126, v159);
        }
        else
        {
          vostok::buffer_string::appendf(
            &v181,
            v67,
            (vostok::buffer_string *)"%I64d -> %I64d ",
            v197->m_begin,
            v197->m_end,
            *(_DWORD *)v198,
            *((_DWORD *)v198 + 1));
        }
      }
      else
      {
        vostok::buffer_string::appendf(
          &v181,
          v197,
          (vostok::buffer_string *)"[%.8g][%.8g][%.8g] -> [%.8g][%.8g][%.8g], difference [%.8g][%.8g][%.8g]",
          (const char *)COERCE_UNSIGNED_INT64(*(float *)&v197->m_begin),
          (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(*(float *)&v197->m_begin)),
          *(float *)&v197->m_end,
          *(float *)&v197->m_max_end,
          *v198,
          v198[1],
          v198[2],
          (float)(*(float *)&v197->m_begin - *v198),
          (float)(*(float *)&v197->m_end - v198[1]),
          (float)(*(float *)&v197->m_max_end - v198[2]));
      }
LABEL_196:
      if ( !vostok::core::g_log_filter_tree
        || (v83 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)3),
            v65 = v167,
            v83) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v65,
          &v194);
        v200 |= (unsigned int)&s_ui_commands_allocator.m_buffer[52367008];
        vostok::logging::append(
          &v194,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\game_world_core.cpp",
          0x66Fu,
          "void __thiscall survarium::game_world_core::on_hash_mismatch(const unsigned int,const struct vostok::network_c"
          "ore::buffer_writer::serialization_operation_descriptor *,class vostok::network_core::buffer_reader &)",
          "net_hash",
          warning,
          (char *)&stru_7F9BE8.allocator,
          v181);
      }
      if ( ((unsigned int)&s_ui_commands_allocator.m_buffer[52367008] & v200) != 0 )
      {
        v200 &= ~0x4000000u;
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v65,
          (int *)&v194);
      }
      v84 = (char *)(((unsigned int)(v16[6] - 1) >> 3) + 1);
      if ( (unsigned int)(v16[6] - 1) >> 3 != -1 )
      {
        v196 = 0;
        v193 = v197;
        v190 = (char *)v198 - (char *)v197;
        right = v84;
        do
        {
          v85 = v193;
          v86 = (char *)v193 + v190;
          v87 = (vostok::buffer_string *)((unsigned int)(v16[6] - (_DWORD)v196) < 8 ? v16[6] - (_DWORD)v196 - 8 + 8 : 8);
          v90 = 0;
          v88 = 0;
          v89 = 1;
          v192 = (char *)v193 + v190;
          do
          {
            if ( !v87 )
              break;
            v88 = LOBYTE(v85->m_begin) < *v86;
            v89 = LOBYTE(v85->m_begin) == *v86;
            v85 = (vostok::buffer_string *)((char *)v85 + 1);
            ++v86;
            v87 = (vostok::buffer_string *)((char *)v87 - 1);
          }
          while ( v89 );
          if ( !v89 )
            v90 = -v88 - (v88 - 1);
          if ( v90 )
          {
            v168 = v196;
            v182 = v181;
            *v181 = 0;
            vostok::buffer_string::appendf(&v181, v87, (vostok::buffer_string *)"%03x : ", v168);
            v91 = v193;
            v92 = (unsigned int)(v16[6] - (_DWORD)v196) < 8 ? (vostok::buffer_string *)(v16[6] - (_DWORD)v196 - 8) : 0;
            v93 = (char *)&v193->m_max_end + (_DWORD)v92;
            profile_name = (char *)v193;
            if ( v193 != (vostok::buffer_string *)v93 )
            {
              do
              {
                vostok::buffer_string::appendf(
                  &v181,
                  v92,
                  (vostok::buffer_string *)"%02x ",
                  (const char *)(unsigned __int8)*profile_name++);
                v92 = v169;
              }
              while ( profile_name != v93 );
            }
            vostok::buffer_string::appendf(&v181, v92, (vostok::buffer_string *)" ->  ", v179);
            v94 = (unsigned int)(v16[6] - (_DWORD)v196) < 8
                ? (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)(v16[6] - (_DWORD)v196 - 8)
                : 0;
            v95 = (int)&v91->m_max_end + (_DWORD)v94;
            if ( v91 != (vostok::buffer_string *)v95 )
            {
              v96 = (char *)(v192 - (char *)v91);
              for ( v192 -= (int)v91; ; v96 = v192 )
              {
                v97 = v96[(_DWORD)v91];
                v170 = (vostok::buffer_string *)(LOBYTE(v91->m_begin) != v97 ? 46 : 32);
                vostok::buffer_string::appendf(&v181, v170, (vostok::buffer_string *)"%02x%c", (const char *)v97, v170);
                v91 = (vostok::buffer_string *)((char *)v91 + 1);
                if ( v91 == (vostok::buffer_string *)v95 )
                  break;
              }
            }
            if ( !vostok::core::g_log_filter_tree
              || (v98 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)3),
                  v94 = v171,
                  v98) )
            {
              boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
                v94,
                &v194);
              v200 |= 0x8000000u;
              vostok::logging::append(
                &v194,
                (void *const)vostok::core::g_log_flags,
                &vostok::core::g_log_format,
                ".\\game_world_core.cpp",
                0x680u,
                "void __thiscall survarium::game_world_core::on_hash_mismatch(const unsigned int,const struct vostok::net"
                "work_core::buffer_writer::serialization_operation_descriptor *,class vostok::network_core::buffer_reader &)",
                "net_hash",
                warning,
                (char *)&stru_7F9BE8.allocator,
                v181);
            }
            if ( (v200 & 0x8000000) != 0 )
            {
              v200 &= ~0x8000000u;
              boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
                (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v94,
                (int *)&v194);
            }
          }
          v196 += 8;
          v193 = (vostok::buffer_string *)((char *)v193 + 8);
          --right;
        }
        while ( right );
      }
      goto LABEL_221;
    }
    if ( !vostok::core::g_log_filter_tree
      || (v52 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)3),
          v51 = v155,
          v52) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v51,
        &v194);
      v122 = v198[3];
      v118 = v198[2];
      v114 = v198[1];
      v110 = *v198;
      v106 = *(float *)&v197[1].m_begin;
      m_max_end = v197->m_max_end;
      v200 |= (unsigned int)&loc_200000;
      vostok::logging::append(
        &v194,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\game_world_core.cpp",
        0x647u,
        "void __thiscall survarium::game_world_core::on_hash_mismatch(const unsigned int,const struct vostok::network_cor"
        "e::buffer_writer::serialization_operation_descriptor *,class vostok::network_core::buffer_reader &)",
        "net_hash",
        warning,
        "[%.8g][%.8g][%.8g][%.8g] => [%.8g][%.8g][%.8g][%.8g]",
        *(float *)&v197->m_begin,
        *(float *)&v197->m_end,
        *(float *)&m_max_end,
        v106,
        v110,
        v114,
        v118,
        v122);
    }
    if ( ((unsigned int)&loc_200000 & v200) != 0 )
    {
      v200 &= ~0x200000u;
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v51,
        (int *)&v194);
    }
    if ( !vostok::core::g_log_filter_tree
      || (v54 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)3),
          v51 = v156,
          v54) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v51,
        &v194);
      v123 = v198[7];
      v119 = v198[6];
      v115 = v198[5];
      v111 = v198[4];
      v107 = *(float *)&v197[2].m_end;
      v55 = v197[2].m_begin;
      v200 |= (unsigned int)&loc_400000;
      vostok::logging::append(
        &v194,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\game_world_core.cpp",
        0x648u,
        "void __thiscall survarium::game_world_core::on_hash_mismatch(const unsigned int,const struct vostok::network_cor"
        "e::buffer_writer::serialization_operation_descriptor *,class vostok::network_core::buffer_reader &)",
        "net_hash",
        warning,
        "[%.8g][%.8g][%.8g][%.8g] => [%.8g][%.8g][%.8g][%.8g]",
        *(float *)&v197[1].m_end,
        *(float *)&v197[1].m_max_end,
        *(float *)&v55,
        v107,
        v111,
        v115,
        v119,
        v123);
    }
    if ( ((unsigned int)&loc_400000 & v200) != 0 )
    {
      v200 &= ~0x400000u;
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v51,
        (int *)&v194);
    }
    if ( !vostok::core::g_log_filter_tree
      || (v56 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)3),
          v51 = v157,
          v56) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v51,
        &v194);
      v124 = v198[11];
      v120 = v198[10];
      v116 = v198[9];
      v112 = v198[8];
      v108 = *(float *)&v197[3].m_max_end;
      m_end = v197[3].m_end;
      v200 |= 0x800000u;
      vostok::logging::append(
        &v194,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\game_world_core.cpp",
        0x649u,
        "void __thiscall survarium::game_world_core::on_hash_mismatch(const unsigned int,const struct vostok::network_cor"
        "e::buffer_writer::serialization_operation_descriptor *,class vostok::network_core::buffer_reader &)",
        "net_hash",
        warning,
        "[%.8g][%.8g][%.8g][%.8g] => [%.8g][%.8g][%.8g][%.8g]",
        *(float *)&v197[2].m_max_end,
        *(float *)&v197[3].m_begin,
        *(float *)&m_end,
        v108,
        v112,
        v116,
        v120,
        v124);
    }
    if ( (v200 & 0x800000) != 0 )
    {
      v200 &= ~0x800000u;
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v51,
        (int *)&v194);
    }
    if ( !vostok::core::g_log_filter_tree
      || (v58 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)3),
          v51 = v158,
          v58) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v51,
        &v194);
      v125 = v198[15];
      v121 = v198[14];
      v117 = v198[13];
      v113 = v198[12];
      v109 = *(float *)&v197[5].m_begin;
      v59 = v197[4].m_max_end;
      v200 |= (unsigned int)&s_ui_commands_allocator.m_buffer[2035360];
      vostok::logging::append(
        &v194,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\game_world_core.cpp",
        0x64Au,
        "void __thiscall survarium::game_world_core::on_hash_mismatch(const unsigned int,const struct vostok::network_cor"
        "e::buffer_writer::serialization_operation_descriptor *,class vostok::network_core::buffer_reader &)",
        "net_hash",
        warning,
        "[%.8g][%.8g][%.8g][%.8g] => [%.8g][%.8g][%.8g][%.8g]",
        *(float *)&v197[4].m_begin,
        *(float *)&v197[4].m_end,
        *(float *)&v59,
        v109,
        v113,
        v117,
        v121,
        v125);
    }
    if ( ((unsigned int)&s_ui_commands_allocator.m_buffer[2035360] & v200) != 0 )
    {
      v200 &= ~0x1000000u;
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v51,
        (int *)&v194);
    }
LABEL_221:
    v197 = (vostok::buffer_string *)((char *)v197 + v16[6]);
    m_match_options = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)reader[6].manager;
    v198 = (float *)((int)v198 + (_DWORD)m_match_options);
    v196 = (const char *)v16;
    v16 = (int *)*v16;
    v193 = (vostok::buffer_string *)reader;
    reader = (boost::detail::function::vtable_base *)reader->manager;
    if ( !v16 )
      break;
  }
  while ( v16 )
  {
    if ( !vostok::core::g_log_filter_tree
      || (v99 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)3),
          m_match_options = v172,
          v99) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        m_match_options,
        &v194);
      v173 = v16[6];
      v200 |= 0x10000000u;
      vostok::logging::append(
        &v194,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\game_world_core.cpp",
        0x685u,
        "void __thiscall survarium::game_world_core::on_hash_mismatch(const unsigned int,const struct vostok::network_cor"
        "e::buffer_writer::serialization_operation_descriptor *,class vostok::network_core::buffer_reader &)",
        "net_hash",
        warning,
        "MISSING LOCAL VALUE: %s[%d]",
        (const char *)v16[1],
        v173);
    }
    if ( (v200 & 0x10000000) != 0 )
    {
      v200 &= ~0x10000000u;
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)m_match_options,
        (int *)&v194);
    }
    if ( !vostok::core::g_log_filter_tree
      || (v100 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)3),
          m_match_options = v174,
          v100) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        m_match_options,
        &v194);
      v175 = v16[6];
      v200 |= 0x20000000u;
      vostok::logging::append(
        &v194,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\game_world_core.cpp",
        0x686u,
        "void __thiscall survarium::game_world_core::on_hash_mismatch(const unsigned int,const struct vostok::network_cor"
        "e::buffer_writer::serialization_operation_descriptor *,class vostok::network_core::buffer_reader &)",
        "net_hash",
        warning,
        "%s(%d): %s - %s, %s[%d]",
        (const char *)v16[4],
        v16[5],
        (const char *)v16[2],
        (const char *)v16[3],
        (const char *)v16[1],
        v175);
    }
    if ( (v200 & 0x20000000) != 0 )
    {
      v200 &= ~0x20000000u;
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)m_match_options,
        (int *)&v194);
    }
    vostok::debug::printf(
      "%s(%d): %s - %s, %s[%d]\n",
      (const char *)v16[4],
      v16[5],
      (const char *)v16[2],
      (const char *)v16[3],
      (const char *)v16[1],
      v16[6]);
    v16 = (int *)*v16;
  }
LABEL_235:
  vtable = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)reader;
  if ( reader )
  {
    do
    {
      if ( !vostok::core::g_log_filter_tree
        || (v102 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)3),
            m_match_options = v176,
            v102) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          m_match_options,
          &v194);
        v177 = reader[6].manager;
        v200 |= 0x40000000u;
        vostok::logging::append(
          &v194,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\game_world_core.cpp",
          0x68Cu,
          "void __thiscall survarium::game_world_core::on_hash_mismatch(const unsigned int,const struct vostok::network_c"
          "ore::buffer_writer::serialization_operation_descriptor *,class vostok::network_core::buffer_reader &)",
          "net_hash",
          warning,
          "MISSING REMOTE VALUE: %s[%d]",
          (const char *)reader[1].manager,
          v177);
        vtable = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)reader;
      }
      if ( (v200 & 0x40000000) != 0 )
      {
        v200 &= ~0x40000000u;
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)m_match_options,
          (int *)&v194);
        vtable = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)reader;
      }
      if ( !vostok::core::g_log_filter_tree
        || (v103 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)3),
            m_match_options = v178,
            v103) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          m_match_options,
          &v194);
        v200 |= 0x80000000;
        vostok::logging::append(
          &v194,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\game_world_core.cpp",
          0x68Du,
          "void __thiscall survarium::game_world_core::on_hash_mismatch(const unsigned int,const struct vostok::network_c"
          "ore::buffer_writer::serialization_operation_descriptor *,class vostok::network_core::buffer_reader &)",
          "net_hash",
          warning,
          "%s(%d): %s, %s[%d]",
          (const char *)reader[4].manager,
          reader[5].manager,
          (const char *)reader[2].manager,
          (const char *)reader[3].manager,
          reader[1].manager);
        vtable = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)reader;
      }
      if ( v200 < 0 )
      {
        v200 &= ~0x80000000;
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)m_match_options,
          (int *)&v194);
        vtable = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)reader;
      }
      vostok::debug::printf(
        "%s(%d): %s - %s, %s[%d]\n",
        (const char *)vtable->functor.vostok_pointer_size_alignment[2],
        vtable->functor.vostok_pointer_size_alignment[3],
        (const char *)vtable->functor.obj_ptr,
        (const char *)vtable->functor.vostok_pointer_size_alignment[1],
        (const char *)(&vtable->vtable)[1],
        vtable->functor.bound_memfunc_ptr.obj_ptr);
      obj_ptr = vtable->functor.bound_memfunc_ptr.obj_ptr;
      vtable = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)vtable->vtable;
      v198 = (float *)((int)v198 + (_DWORD)obj_ptr);
      reader = (boost::detail::function::vtable_base *)vtable;
    }
    while ( vtable );
  }
  *(_DWORD *)(a5 + 4) = v198;
  vostok::network_core::buffer_writer::~buffer_writer(
    (vostok::network_core::buffer_writer *)a5,
    (vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)&v191.functor);
  vostok::network_core::mutable_buffer::~mutable_buffer(v105, &v186);
}
