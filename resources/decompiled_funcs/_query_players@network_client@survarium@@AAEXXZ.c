void __usercall survarium::network_client::query_players(survarium::network_client *this@<ecx>, _DWORD *a2@<eax>)
{
  unsigned int v3; // edi
  void *v4; // esp
  void *v5; // esp
  void *v6; // esp
  int v7; // edi
  int v8; // edx
  int v9; // eax
  void *v10; // ecx
  unsigned int v11; // eax
  vostok::variant<32> *m_end; // ecx
  const vostok::variant<32> **v13; // eax
  vostok::variant<32> *v14; // ecx
  vostok::resources::request *v15; // eax
  vostok::resources::unmanaged_resource *v16; // eax
  vostok::detail::abstract_type_helper *m_helper; // ecx
  int v18; // eax
  int v19; // esi
  _BYTE *v20; // ecx
  _BYTE *v21; // eax
  _BYTE *v22; // edi
  void (__cdecl *v23)(__int64 *, __int64 *, int); // eax
  vostok::variant<32> *v24; // edi
  vostok::detail::abstract_type_helper **p_m_helper; // esi
  _BYTE v26[8]; // [esp+0h] [ebp-90h] BYREF
  vostok::variant<32> ud; // [esp+8h] [ebp-88h] BYREF
  vostok::resources::unmanaged_intrusive_base *v28; // [esp+38h] [ebp-58h]
  vostok::resources::request *requests_end; // [esp+3Ch] [ebp-54h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> *callback; // [esp+40h] [ebp-50h]
  __int64 v31; // [esp+44h] [ebp-4Ch]
  vostok::buffer_vector<vostok::variant<32> const *> user_data_ptrs; // [esp+4Ch] [ebp-44h]
  vostok::buffer_vector<vostok::resources::request> requests; // [esp+54h] [ebp-3Ch]
  vostok::variant<32> *v34; // [esp+5Ch] [ebp-34h]
  vostok::buffer_vector<vostok::variant<32> > user_datas; // [esp+60h] [ebp-30h]
  unsigned int v36; // [esp+68h] [ebp-28h]
  __int64 v37; // [esp+70h] [ebp-20h] BYREF
  survarium::player_initial_info info; // [esp+78h] [ebp-18h]
  unsigned int players_count; // [esp+88h] [ebp-8h]
  unsigned __int8 i; // [esp+8Fh] [ebp-1h]

  v3 = *(unsigned __int8 *)((*(int (__thiscall **)(_DWORD *))(*a2 + 64))(a2) + 9064);
  players_count = v3;
  v4 = alloca(8 * v3);
  requests_end = (vostok::resources::request *)v26;
  requests.m_end = (vostok::resources::request *)v26;
  v5 = alloca(48 * v3);
  v34 = (vostok::variant<32> *)v26;
  user_datas.m_end = (vostok::variant<32> *)v26;
  v6 = alloca(4 * v3);
  callback = (boost::function<void __cdecl(vostok::resources::queries_result &)> *)v26;
  user_data_ptrs.m_end = (const vostok::variant<32> **)v26;
  i = 0;
  if ( v3 )
  {
    v7 = 0;
    do
    {
      v8 = *a2;
      info.id = i;
      v9 = (*(int (__thiscall **)(_DWORD *))(v8 + 64))(a2);
      v10 = (void *)(a2[6] + 152);
      info.profile = (survarium::player_profile *)(v9 + 440 * v7 + 252);
      info.is_demo_player = 0;
      info.game_scene = v10;
      ud.m_helper = 0;
      ud.m_type_id = 0;
      v11 = vostok::detail::type_to_int<survarium::player_initial_info>::get();
      m_end = user_datas.m_end;
      *(survarium::player_initial_info *)ud.m_storage = info;
      ud.m_type_id = v11;
      *(_DWORD *)ud.m_helper_storage = &vostok::detail::concrete_type_helper<survarium::player_initial_info>::`vftable';
      ud.m_helper = (vostok::detail::abstract_type_helper *)&ud;
      if ( user_datas.m_end )
      {
        user_datas.m_end->m_type_id = v11;
        m_end->m_helper = 0;
        vostok::variant<32>::operator=(m_end, &ud);
        m_end = user_datas.m_end;
      }
      v13 = user_data_ptrs.m_end;
      v14 = m_end + 1;
      user_datas.m_end = v14;
      if ( user_data_ptrs.m_end )
        *user_data_ptrs.m_end = v14 - 1;
      user_data_ptrs.m_end = v13 + 1;
      v15 = requests.m_end;
      if ( requests.m_end )
      {
        requests.m_end->path = "gameplay/players/default.player";
        v15->id = player_class;
      }
      requests.m_end = v15 + 1;
      v16 = (vostok::resources::unmanaged_resource *)a2[2 * v7 + 3846];
      a2[2 * v7 + 3846] = 0;
      if ( v16 )
      {
        v28 = &v16->vostok::resources::unmanaged_intrusive_base;
        if ( !_InterlockedExchangeAdd(&v16->m_reference_count, 0xFFFFFFFF) )
          vostok::resources::unmanaged_intrusive_base::destroy(&v16->vostok::resources::unmanaged_intrusive_base, v16);
      }
      m_helper = ud.m_helper;
      LOBYTE(a2[2 * v7 + 3847]) = 0;
      if ( m_helper )
        m_helper->destroy(m_helper, ud.m_storage);
      v7 = ++i;
    }
    while ( i < players_count );
    v3 = players_count;
  }
  *(_QWORD *)&info.profile = (unsigned int)survarium::network_client::on_players_ready;
  v31 = (unsigned int)survarium::network_client::on_players_ready;
  *(_QWORD *)&info.game_scene = __PAIR64__(v3, (unsigned int)a2);
  user_data_ptrs = (vostok::buffer_vector<vostok::variant<32> const *>)__PAIR64__(v3, (unsigned int)a2);
  if ( survarium::generate_shaders_world::is_loading() )
  {
    v36 = 0;
  }
  else
  {
    v37 = v31;
    *(vostok::buffer_vector<vostok::variant<32> const *> *)&info.profile = user_data_ptrs;
    v36 = (unsigned int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::network_client,vostok::resources::queries_result &,unsigned int>,boost::_bi::list3<boost::_bi::value<survarium::network_client *>,boost::arg<1>,boost::_bi::value<unsigned int>>>>'::`2'::stored_vtable
        + 1;
  }
  v18 = (*(int (__thiscall **)(_DWORD *))(*a2 + 64))(a2);
  v19 = a2[6];
  v20 = *(_BYTE **)(v19 + 1552);
  v21 = (_BYTE *)(v18 + 9077);
  if ( v20 != v21 )
  {
    *(_DWORD *)(v19 + 1556) = v20;
    *v20 = 0;
    if ( v21 )
    {
      for ( ; *v21; ++v21 )
      {
        v22 = *(_BYTE **)(v19 + 1556);
        if ( (unsigned int)v22 >= *(_DWORD *)(v19 + 1560) )
          break;
        *v22 = *v21;
        ++*(_DWORD *)(v19 + 1556);
      }
      **(_BYTE **)(v19 + 1556) = 0;
    }
  }
  survarium::game_world::load(
    *(survarium::game_world **)(v19 + 1552),
    (const char *)(v19 + 152),
    *(vostok::resources::request **)(v19 + 1552),
    requests_end,
    (const vostok::variant<32> **)requests.m_end,
    callback);
  *(_BYTE *)(v19 + 1025) = 0;
  if ( v36 )
  {
    if ( (v36 & 1) == 0 )
    {
      v23 = *(void (__cdecl **)(__int64 *, __int64 *, int))(v36 & 0xFFFFFFFE);
      if ( v23 )
        v23(&v37, &v37, 2);
    }
  }
  v24 = user_datas.m_end;
  if ( v34 != user_datas.m_end )
  {
    p_m_helper = &v34->m_helper;
    do
    {
      if ( *p_m_helper )
      {
        (*p_m_helper)->destroy(*p_m_helper, p_m_helper - 8);
        *p_m_helper = 0;
      }
      p_m_helper += 12;
    }
    while ( p_m_helper - 10 != (vostok::detail::abstract_type_helper **)v24 );
  }
}
