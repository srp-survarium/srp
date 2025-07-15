void __userpurge survarium::gather_victory_items_rule_cook::translate_query(
        survarium::gather_victory_items_rule_cook *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        const vostok::variant<32> **parent)
{
  vostok::variant<32> *v5; // esi
  void *v6; // esp
  void *v7; // esp
  int v8; // esi
  void *v9; // esp
  vostok::buffer_vector<vostok::variant<32> const *> *v10; // ecx
  vostok::buffer_vector<vostok::variant<32> > *v11; // ecx
  vostok::variant<32> *v12; // ecx
  vostok::resources::class_id_enum v13; // esi
  vostok::variant<32> *v14; // ecx
  vostok::buffer_vector<vostok::variant<32> const *> *v15; // ecx
  vostok::detail::abstract_type_helper *match_id; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v17; // ecx
  vostok::buffer_vector<vostok::variant<32> > *v18; // ecx
  vostok::resources::request *v19; // [esp-94h] [ebp-A0h]
  _DWORD v20[2]; // [esp-90h] [ebp-9Ch] BYREF
  vostok::variant<32> v21; // [esp-88h] [ebp-94h] BYREF
  vostok::resources::request v22[3]; // [esp-58h] [ebp-64h] BYREF
  _DWORD *v23; // [esp-40h] [ebp-4Ch] BYREF
  _DWORD *v24; // [esp-3Ch] [ebp-48h]
  _DWORD *v25; // [esp-38h] [ebp-44h]
  const vostok::variant<32> *const *v26[3]; // [esp-34h] [ebp-40h] BYREF
  survarium::gather_victory_items_rule_cook *v27; // [esp-28h] [ebp-34h]
  vostok::resources::request v28; // [esp-24h] [ebp-30h] BYREF
  vostok::buffer_vector<vostok::resources::request> v29; // [esp-1Ch] [ebp-28h] BYREF
  survarium::gather_victory_items_rule_query_data v30; // [esp-10h] [ebp-1Ch] BYREF
  const vostok::variant<32> *v31; // [esp-8h] [ebp-14h] BYREF
  unsigned __int8 v32; // [esp-1h] [ebp-Dh]
  int v33; // [esp+0h] [ebp-Ch]
  void *v34; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v33 = a2;
  v34 = retaddr;
  v20[1] = a4;
  v5 = (vostok::variant<32> *)parent[66];
  v20[0] = a3;
  v27 = this;
  vostok::variant<32>::try_get<survarium::gather_victory_items_rule_query_data>(v5, &v30);
  v32 = v30.match_options->victory_items_count + 1;
  v6 = alloca(8 * v32);
  v29.m_max_end = (vostok::resources::request *)&v20[2 * v32];
  v29.m_begin = (vostok::resources::request *)v20;
  v29.m_end = (vostok::resources::request *)v20;
  v7 = alloca(4 * v32);
  v8 = 12 * v32;
  v26[0] = (const vostok::variant<32> *const *)v20;
  v26[1] = (const vostok::variant<32> *const *)v20;
  v26[2] = (const vostok::variant<32> *const *)&v20[v32];
  v9 = alloca(v8 * 4);
  v23 = v20;
  v24 = v20;
  v25 = &v20[v8];
  v28.path = v30.match_options->map_name;
  v28.id = game_project_class;
  vostok::buffer_vector<vostok::resources::request>::push_back(&v29, &v28);
  v31 = 0;
  vostok::buffer_vector<vostok::variant<32> const *>::push_back(v10, (int)v26, &v31);
  if ( v32 > 1u )
  {
    v22[2].path = "gameplay/victory_items/default.options";
    v22[2].id = victory_item_class;
    v31 = (const vostok::variant<32> *)(unsigned __int8)(v32 - 1);
    do
    {
      vostok::buffer_vector<vostok::resources::request>::push_back(&v29, &v22[2]);
      v21.m_helper = 0;
      v21.m_type_id = 0;
      vostok::buffer_vector<vostok::variant<32>>::push_back(v11, (int)&v23, &v21);
      vostok::variant<32>::destroy_previous_variable_if_needed(v12, (int)&v21);
      v13 = (vostok::resources::class_id_enum)(v24 - 12);
      vostok::variant<32>::set<vostok::physics::world *>(v14, v24 - 12, &v30.physics_world);
      v28.id = v13;
      vostok::buffer_vector<vostok::variant<32> const *>::push_back(
        v15,
        (int)v26,
        (const vostok::variant<32> **)&v28.id);
      v31 = (const vostok::variant<32> *)((char *)v31 - 1);
    }
    while ( v31 );
  }
  match_id = (vostok::detail::abstract_type_helper *)v30.match_options->match_id;
  *(_DWORD *)&v21.m_storage[16] = survarium::gather_victory_items_rule_cook::on_resources_loaded;
  *(_DWORD *)&v21.m_storage[20] = 0;
  *(_DWORD *)&v21.m_storage[24] = v27;
  *(_DWORD *)&v21.m_storage[28] = v30.physics_world;
  v21.m_helper = match_id;
  v19 = v22;
  qmemcpy(v22, &v21.m_storage[16], sizeof(v22));
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    *(_DWORD *)&v21.m_storage[8] = 0;
  }
  else
  {
    qmemcpy(&v21.m_storage[16], v22, 0x18u);
    *(_DWORD *)&v21.m_storage[8] = (char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::gather_victory_items_rule_cook,vostok::resources::queries_result &,vostok::physics::world *,unsigned int>,boost::_bi::list4<boost::_bi::value<survarium::gather_victory_items_rule_cook *>,boost::arg<1>,boost::_bi::value<vostok::physics::world *>,boost::_bi::value<unsigned int>>>>'::`2'::stored_vtable
                                 + 1;
  }
  vostok::resources::query_resources(
    v29.m_begin,
    v29.m_end - v29.m_begin,
    survarium::g_allocator,
    v26[0],
    parent,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v17,
    (int *)&v21.m_storage[8]);
  vostok::buffer_vector<vostok::variant<32>>::~buffer_vector<vostok::variant<32>>(v18, (int *)&v23);
}
