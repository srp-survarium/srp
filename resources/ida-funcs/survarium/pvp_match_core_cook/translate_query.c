// bad sp value at call has been detected, the output may be wrong!
void __userpurge survarium::pvp_match_core_cook::translate_query(
        survarium::pvp_match_core_cook *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        const vostok::variant<32> **parent)
{
  const vostok::variant<32> *v5; // eax
  vostok::physics::engine *v7; // eax
  int v8; // eax
  int v9; // edi
  void *v10; // esp
  void *v11; // esp
  void *v12; // esp
  vostok::buffer_vector<vostok::variant<32> > *v13; // ecx
  vostok::variant<32> *v14; // ecx
  vostok::variant<32> *v15; // ecx
  vostok::buffer_vector<vostok::variant<32> const *> *v16; // ecx
  vostok::buffer_vector<vostok::variant<32> const *> *v17; // ecx
  vostok::buffer_vector<vostok::variant<32> > *v18; // ecx
  vostok::variant<32> *v19; // ecx
  _DWORD *v20; // esi
  vostok::variant<32> *v21; // ecx
  vostok::buffer_vector<vostok::variant<32> const *> *v22; // ecx
  vostok::buffer_vector<vostok::variant<32> > *v23; // ecx
  vostok::variant<32> *v24; // ecx
  vostok::variant<32> *v25; // esi
  vostok::variant<32> *v26; // ecx
  vostok::buffer_vector<vostok::variant<32> const *> *v27; // ecx
  vostok::buffer_vector<vostok::variant<32> > *v28; // ecx
  vostok::variant<32> *v29; // ecx
  _DWORD *v30; // esi
  vostok::variant<32> *v31; // ecx
  vostok::buffer_vector<vostok::variant<32> const *> *v32; // ecx
  vostok::buffer_vector<vostok::variant<32> > *v33; // ecx
  vostok::variant<32> *v34; // ecx
  _DWORD *v35; // esi
  vostok::variant<32> *v36; // ecx
  int v37; // eax
  vostok::buffer_vector<vostok::variant<32> const *> *v38; // ecx
  const vostok::variant<32> *v39; // edi
  char v40; // al
  vostok::buffer_vector<vostok::variant<32> > *v41; // ecx
  vostok::variant<32> *v42; // ecx
  vostok::resources::class_id_enum v43; // esi
  vostok::variant<32> *v44; // ecx
  vostok::buffer_vector<vostok::variant<32> const *> *v45; // ecx
  char *v46; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v47; // ecx
  vostok::buffer_vector<vostok::variant<32> > *v48; // ecx
  _DWORD v50[10]; // [esp-C8h] [ebp-D4h] BYREF
  survarium::pvp_match_core_cook *v51; // [esp-A0h] [ebp-ACh]
  unsigned int v52; // [esp-9Ch] [ebp-A8h]
  vostok::variant<32> v53; // [esp-98h] [ebp-A4h] BYREF
  int v54[2]; // [esp-68h] [ebp-74h] BYREF
  vostok::variant<32> v55; // [esp-60h] [ebp-6Ch] BYREF
  vostok::buffer_vector<vostok::resources::request> v56; // [esp-30h] [ebp-3Ch] BYREF
  vostok::buffer_vector<vostok::variant<32> const *> *v57; // [esp-24h] [ebp-30h]
  _BYTE *v58; // [esp-20h] [ebp-2Ch] BYREF
  _BYTE *v59; // [esp-1Ch] [ebp-28h]
  _BYTE *v60; // [esp-18h] [ebp-24h]
  int v61; // [esp-14h] [ebp-20h]
  vostok::resources::request v62; // [esp-10h] [ebp-1Ch] BYREF
  vostok::variant<32> *v63; // [esp-8h] [ebp-14h] BYREF
  _BYTE v64[3]; // [esp-4h] [ebp-10h] BYREF
  unsigned __int8 v65; // [esp-1h] [ebp-Dh]
  int v66; // [esp+0h] [ebp-Ch]
  void *v67; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v66 = a2;
  v67 = retaddr;
  v5 = parent[66];
  v51 = this;
  vostok::variant<32>::try_get<survarium::pvp_match_core_query_user_data>(
    &v55,
    (int)v5,
    (survarium::pvp_match_core_query_user_data *)&v55);
  if ( this )
    v7 = (vostok::physics::engine *)&this->gap20;
  else
    v7 = 0;
  vostok::physics::create_world_bt(v7);
  (*(void (__thiscall **)(int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, survarium::pvp_match_core_cook *, unsigned int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, vostok::detail::abstract_type_helper *, unsigned int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, vostok::detail::abstract_type_helper *, unsigned int, vostok::resources::request *, vostok::resources::request *, vostok::resources::request *, int, _BYTE *, _BYTE *, _BYTE *, int, const char *, vostok::resources::class_id_enum, vostok::variant<32> *))(*(_DWORD *)v8 + 8))(
    v8,
    a3,
    a4,
    v50[0],
    v50[1],
    v50[2],
    v50[3],
    v50[4],
    v50[5],
    v50[6],
    v50[7],
    v50[8],
    v50[9],
    v51,
    v52,
    *(_DWORD *)v53.m_helper_storage,
    *(_DWORD *)&v53.m_helper_storage[4],
    *(_DWORD *)v53.m_storage,
    *(_DWORD *)&v53.m_storage[4],
    *(_DWORD *)&v53.m_storage[8],
    *(_DWORD *)&v53.m_storage[12],
    *(_DWORD *)&v53.m_storage[16],
    *(_DWORD *)&v53.m_storage[20],
    *(_DWORD *)&v53.m_storage[24],
    *(_DWORD *)&v53.m_storage[28],
    v53.m_helper,
    v53.m_type_id,
    v54[0],
    v54[1],
    *(_DWORD *)v55.m_helper_storage,
    *(_DWORD *)&v55.m_helper_storage[4],
    *(_DWORD *)v55.m_storage,
    *(_DWORD *)&v55.m_storage[4],
    *(_DWORD *)&v55.m_storage[8],
    *(_DWORD *)&v55.m_storage[12],
    *(_DWORD *)&v55.m_storage[16],
    *(_DWORD *)&v55.m_storage[20],
    *(_DWORD *)&v55.m_storage[24],
    *(_DWORD *)&v55.m_storage[28],
    v55.m_helper,
    v55.m_type_id,
    v56.m_begin,
    v56.m_end,
    v56.m_max_end,
    v8,
    v58,
    v59,
    v60,
    v61,
    v62.path,
    v62.id,
    v63);
  v9 = 8 * ((v55.m_storage[12] == 0) + 3 + *(unsigned __int8 *)(*(_DWORD *)&v55.m_helper_storage[4] + 29772) + 2);
  v52 = (v55.m_storage[12] == 0) + 3 + *(unsigned __int8 *)(*(_DWORD *)&v55.m_helper_storage[4] + 29772) + 2;
  v10 = alloca(v9);
  v56.m_max_end = (vostok::resources::request *)&v64[v9];
  v56.m_begin = (vostok::resources::request *)v64;
  v56.m_end = (vostok::resources::request *)v64;
  v11 = alloca(4 * v52);
  *(_DWORD *)&v55.m_storage[28] = v64;
  v55.m_helper = (vostok::detail::abstract_type_helper *)v64;
  v55.m_type_id = (unsigned int)&v64[4 * v52];
  v12 = alloca(48 * v52);
  v58 = v64;
  v59 = v64;
  v60 = &v64[48 * v52];
  vostok::buffer_vector<vostok::resources::request>::push_back(&v56, &v62);
  v53.m_helper = 0;
  v53.m_type_id = 0;
  vostok::buffer_vector<vostok::variant<32>>::push_back(v13, (int)&v58, &v53);
  vostok::variant<32>::destroy_previous_variable_if_needed(v14, (int)&v53);
  vostok::variant<32>::set<void *>(v15, (_DWORD *)v59 - 12, (void **)&v55);
  vostok::buffer_vector<vostok::variant<32> const *>::push_back(
    v16,
    (int)&v55.m_storage[28],
    (const vostok::variant<32> **)&v63);
  v62.path = "game_material_manager";
  v62.id = game_material_manager_class;
  vostok::buffer_vector<vostok::resources::request>::push_back(&v56, &v62);
  vostok::buffer_vector<vostok::variant<32> const *>::push_back(
    v17,
    (int)&v55.m_storage[28],
    (const vostok::variant<32> **)&v63);
  if ( !v55.m_storage[12] )
  {
    v62.path = uri;
    v62.id = gather_victory_items_rule_class;
    vostok::buffer_vector<vostok::resources::request>::push_back(&v56, &v62);
    v53.m_helper = 0;
    v53.m_type_id = 0;
    vostok::buffer_vector<vostok::variant<32>>::push_back(v18, (int)&v58, &v53);
    vostok::variant<32>::destroy_previous_variable_if_needed(v19, (int)&v53);
    v20 = v59 - 48;
    vostok::variant<32>::destroy_previous_variable_if_needed(v21, (int)(v59 - 48));
    v20[11] = vostok::detail::type_to_int<survarium::gather_victory_items_rule_query_data>::get();
    if ( v20 != (_DWORD *)-8 )
    {
      v20[2] = *(_DWORD *)&v55.m_helper_storage[4];
      v22 = v57;
      v20[3] = v57;
    }
    *v20 = &vostok::detail::concrete_type_helper<survarium::gather_victory_items_rule_query_data>::`vftable';
    v20[10] = v20;
    vostok::buffer_vector<vostok::variant<32> const *>::push_back(
      v22,
      (int)&v55.m_storage[28],
      (const vostok::variant<32> **)&v63);
  }
  v62.path = uri;
  v62.id = player_respawn_rule_class;
  vostok::buffer_vector<vostok::resources::request>::push_back(&v56, &v62);
  v53.m_helper = 0;
  v53.m_type_id = 0;
  *(_DWORD *)&v55.m_storage[16] = *(_DWORD *)&v55.m_helper_storage[4];
  v55.m_storage[20] = v55.m_storage[12];
  *(_DWORD *)&v55.m_storage[24] = v57;
  vostok::buffer_vector<vostok::variant<32>>::push_back(v23, (int)&v58, &v53);
  vostok::variant<32>::destroy_previous_variable_if_needed(v24, (int)&v53);
  v25 = (vostok::variant<32> *)(v59 - 48);
  v63 = (vostok::variant<32> *)(v59 - 48);
  vostok::variant<32>::destroy_previous_variable_if_needed(v26, (int)(v59 - 48));
  v25->m_type_id = vostok::detail::type_to_int<survarium::player_respawn_rule_query_data>::get();
  if ( v25 != (vostok::variant<32> *)-8 )
  {
    *(_DWORD *)v25->m_storage = *(_DWORD *)&v55.m_storage[16];
    *(_DWORD *)&v25->m_storage[4] = *(_DWORD *)&v55.m_storage[20];
    *(_DWORD *)&v25->m_storage[8] = *(_DWORD *)&v55.m_storage[24];
    v25 = v63;
  }
  *(_DWORD *)v25->m_helper_storage = &vostok::detail::concrete_type_helper<survarium::player_respawn_rule_query_data>::`vftable';
  v25->m_helper = (vostok::detail::abstract_type_helper *)v25;
  vostok::buffer_vector<vostok::variant<32> const *>::push_back(
    v27,
    (int)&v55.m_storage[28],
    (const vostok::variant<32> **)&v63);
  v62.path = uri;
  v62.id = timelimit_rule_class;
  vostok::buffer_vector<vostok::resources::request>::push_back(&v56, &v62);
  v53.m_helper = 0;
  v53.m_type_id = 0;
  v55.m_storage[24] = v55.m_storage[12];
  vostok::buffer_vector<vostok::variant<32>>::push_back(v28, (int)&v58, &v53);
  vostok::variant<32>::destroy_previous_variable_if_needed(v29, (int)&v53);
  v30 = v59 - 48;
  vostok::variant<32>::destroy_previous_variable_if_needed(v31, (int)(v59 - 48));
  v30[11] = vostok::detail::type_to_int<survarium::timelimit_rule_query_data>::get();
  if ( v30 != (_DWORD *)-8 )
  {
    v30[2] = *(_DWORD *)&v55.m_helper_storage[4];
    v32 = *(vostok::buffer_vector<vostok::variant<32> const *> **)&v55.m_storage[24];
    v30[3] = *(_DWORD *)&v55.m_storage[24];
  }
  *v30 = &vostok::detail::concrete_type_helper<survarium::timelimit_rule_query_data>::`vftable';
  v30[10] = v30;
  vostok::buffer_vector<vostok::variant<32> const *>::push_back(
    v32,
    (int)&v55.m_storage[28],
    (const vostok::variant<32> **)&v63);
  v62.path = uri;
  v62.id = kd_stats_rule_class;
  vostok::buffer_vector<vostok::resources::request>::push_back(&v56, &v62);
  v53.m_helper = 0;
  v53.m_type_id = 0;
  vostok::buffer_vector<vostok::variant<32>>::push_back(v33, (int)&v58, &v53);
  vostok::variant<32>::destroy_previous_variable_if_needed(v34, (int)&v53);
  v35 = v59 - 48;
  vostok::variant<32>::destroy_previous_variable_if_needed(v36, (int)(v59 - 48));
  v37 = vostok::detail::type_to_int<survarium::kd_stats_rule_query_data>::get();
  v39 = *(const vostok::variant<32> **)&v55.m_helper_storage[4];
  v35[11] = v37;
  if ( v35 != (_DWORD *)-8 )
    v35[2] = v39;
  *v35 = &vostok::detail::concrete_type_helper<survarium::kd_stats_rule_query_data>::`vftable';
  v35[10] = v35;
  vostok::buffer_vector<vostok::variant<32> const *>::push_back(
    v38,
    (int)&v55.m_storage[28],
    (const vostok::variant<32> **)&v63);
  v40 = v39[620].m_storage[4];
  v65 = 0;
  HIBYTE(v61) = v40;
  if ( v40 )
  {
    *(_DWORD *)&v55.m_storage[20] = "gameplay/players/default.player";
    *(_DWORD *)&v55.m_storage[24] = 85;
    v63 = (vostok::variant<32> *)v39;
    do
    {
      v50[5] = v63;
      LOBYTE(v50[6]) = v65;
      v50[7] = *(_DWORD *)v55.m_helper_storage;
      LOBYTE(v50[9]) = 0;
      v50[8] = v57;
      vostok::buffer_vector<vostok::resources::request>::push_back(
        &v56,
        (const vostok::resources::request *)&v55.m_storage[20]);
      v53.m_helper = 0;
      v53.m_type_id = 0;
      vostok::buffer_vector<vostok::variant<32>>::push_back(v41, (int)&v58, &v53);
      vostok::variant<32>::destroy_previous_variable_if_needed(v42, (int)&v53);
      v43 = (vostok::resources::class_id_enum)(v59 - 48);
      vostok::variant<32>::set<survarium::player_initial_info>(v44, (survarium::player_profile *)(v59 - 48), &v50[5]);
      v62.id = v43;
      vostok::buffer_vector<vostok::variant<32> const *>::push_back(
        v45,
        (int)&v55.m_storage[28],
        (const vostok::variant<32> **)&v62.id);
      ++v65;
      v63 += 31;
    }
    while ( v65 < HIBYTE(v61) );
  }
  v50[2] = v51;
  qmemcpy(&v50[3], &v55, 0x18u);
  v50[9] = v57;
  v54[0] = 0;
  *(_DWORD *)v53.m_storage = survarium::pvp_match_core_cook::on_resources_loaded;
  *(_DWORD *)&v53.m_storage[4] = 0;
  qmemcpy(&v53.m_storage[8], &v50[2], 0x20u);
  v63 = (vostok::variant<32> *)v50;
  qmemcpy(v50, v53.m_storage, sizeof(v50));
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    v54[0] = 0;
  }
  else
  {
    qmemcpy(v53.m_storage, v50, 0x28u);
    v46 = (char *)operator new(0x28u);
    if ( v46 )
    {
      qmemcpy(v46, v53.m_storage, 0x28u);
      *(_DWORD *)v55.m_helper_storage = v46;
    }
    else
    {
      *(_DWORD *)v55.m_helper_storage = 0;
    }
    v54[0] = (int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::pvp_match_core_cook,vostok::resources::queries_result &,survarium::pvp_match_core_query_user_data,vostok::physics::world *>,boost::_bi::list4<boost::_bi::value<survarium::pvp_match_core_cook *>,boost::arg<1>,boost::_bi::value<survarium::pvp_match_core_query_user_data>,boost::_bi::value<vostok::physics::world *>>>>'::`2'::stored_vtable;
  }
  vostok::resources::query_resources(
    v56.m_begin,
    v52,
    &vostok::memory::g_resources_unmanaged_allocator,
    *(const vostok::variant<32> *const **)&v55.m_storage[28],
    parent,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v47, v54);
  vostok::buffer_vector<vostok::variant<32>>::~buffer_vector<vostok::variant<32>>(v48, (int *)&v58);
}
