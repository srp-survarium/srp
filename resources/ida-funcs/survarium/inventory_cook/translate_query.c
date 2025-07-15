void __userpurge survarium::inventory_cook::translate_query(
        survarium::inventory_cook *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        const vostok::variant<32> **parent)
{
  const vostok::variant<32> *v5; // esi
  void *v6; // esp
  void *v7; // esp
  int v8; // ecx
  int *v9; // eax
  survarium::inventory_cooker_data *v10; // esi
  survarium::player_profile *profile; // ecx
  void *game_scene; // edi
  _DWORD *v13; // esi
  vostok::variant<32> *v14; // ecx
  vostok::buffer_vector<vostok::variant<32> const *> *id; // ecx
  vostok::buffer_vector<vostok::variant<32> const *> *v16; // ecx
  survarium::player_profile *v17; // ecx
  int v18; // edi
  bool v19; // zf
  survarium::dictionary_item *v20; // eax
  vostok::configs::binary_config_value *v21; // eax
  const vostok::configs::binary_config_value *v22; // eax
  _BYTE *v23; // edi
  survarium::items_dictionary *dictionary; // ecx
  vostok::variant<32> *v25; // ecx
  char v26; // al
  void *v27; // edi
  vostok::variant<32> *v28; // esi
  vostok::buffer_vector<vostok::variant<32> const *> *v29; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v30; // ecx
  vostok::variant<32> *v31; // ecx
  vostok::variant<32> **v32; // esi
  int k; // edi
  _BYTE v34[92]; // [esp-5E0h] [ebp-5ECh] BYREF
  int v35; // [esp-584h] [ebp-590h] BYREF
  _DWORD v36[46]; // [esp-580h] [ebp-58Ch] BYREF
  _DWORD v37[13]; // [esp-4C8h] [ebp-4D4h] BYREF
  int v38; // [esp-494h] [ebp-4A0h] BYREF
  vostok::variant<32> *v39; // [esp-70h] [ebp-7Ch] BYREF
  int v40[4]; // [esp-68h] [ebp-74h] BYREF
  vostok::resources::request v41; // [esp-58h] [ebp-64h]
  void *physics_world; // [esp-50h] [ebp-5Ch]
  void *v43; // [esp-4Ch] [ebp-58h]
  survarium::inventory_cook *v44; // [esp-48h] [ebp-54h]
  void (__thiscall *v45)(survarium::inventory_cook *, vostok::resources::queries_result *, survarium::inventory *); // [esp-44h] [ebp-50h]
  int v46; // [esp-40h] [ebp-4Ch]
  vostok::resources::request v47; // [esp-3Ch] [ebp-48h] BYREF
  const vostok::variant<32> *const *v48[3]; // [esp-34h] [ebp-40h] BYREF
  vostok::buffer_vector<vostok::resources::request> v49; // [esp-28h] [ebp-34h] BYREF
  unsigned int j; // [esp-1Ch] [ebp-28h]
  vostok::resources::request v51; // [esp-18h] [ebp-24h] BYREF
  survarium::inventory_cooker_data *v52; // [esp-10h] [ebp-1Ch] BYREF
  survarium::profile_slot_enum v53; // [esp-Ch] [ebp-18h] BYREF
  vostok::variant<32> *pointer; // [esp-8h] [ebp-14h] BYREF
  vostok::resources::class_id_enum i; // [esp-4h] [ebp-10h]
  int v56; // [esp+0h] [ebp-Ch]
  void *v57; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v56 = a2;
  v57 = retaddr;
  v37[1] = a4;
  v37[0] = a3;
  v36[45] = &v52;
  v5 = parent[66];
  v44 = this;
  vostok::variant<32>::try_get<survarium::inventory_cooker_data *>((vostok::variant<32> *)this, (int)v5, &v52);
  v6 = alloca(184);
  v49.m_begin = (vostok::resources::request *)v36;
  v49.m_end = (vostok::resources::request *)v36;
  v49.m_max_end = (vostok::resources::request *)v37;
  v7 = alloca(96);
  v48[0] = (const vostok::variant<32> *const *)v34;
  v48[1] = (const vostok::variant<32> *const *)v34;
  v48[2] = (const vostok::variant<32> *const *)&v35;
  v8 = 22;
  v9 = &v38;
  do
  {
    *(v9 - 1) = 0;
    *v9 = 0;
    v9 += 12;
    --v8;
  }
  while ( v8 >= 0 );
  for ( i = unknown_data_class; (unsigned int)i < texture_class; i += 4 )
  {
    v10 = v52;
    profile = v52->profile;
    v53 = *(const survarium::profile_slot_enum *)((char *)weapon_slots_2 + i);
    if ( profile->slots[v53].id )
    {
      v51.path = survarium::items_dictionary::item_by_id(
                   v52->dictionary,
                   (survarium::items_dictionary_vtbl *)profile->slots[v53].dict_id)->item_cfg_name.m_begin;
      v51.id = weapon_class;
      vostok::buffer_vector<vostok::resources::request>::push_back(&v49, &v51);
      game_scene = v52->game_scene;
      LOBYTE(v47.id) = v52->preview_mode;
      v13 = &v37[12 * v53 + 2];
      vostok::variant<32>::destroy_previous_variable_if_needed(v14, (int)v13);
      v13[11] = vostok::detail::type_to_int<survarium::weapon_cook_data>::get();
      if ( v13 != (_DWORD *)-8 )
      {
        id = (vostok::buffer_vector<vostok::variant<32> const *> *)v47.id;
        v13[2] = game_scene;
        v13[3] = id;
      }
      *v13 = &vostok::detail::concrete_type_helper<survarium::weapon_cook_data>::`vftable';
      v13[10] = v13;
      v53 = (survarium::profile_slot_enum)v13;
      vostok::buffer_vector<vostok::variant<32> const *>::push_back(id, (int)v48, (const vostok::variant<32> **)&v53);
      v10 = v52;
    }
  }
  for ( i = unknown_data_class; (unsigned int)i < binary_config_class_impl; i += 4 )
  {
    if ( v10->profile->slots[*(const survarium::profile_slot_enum *)((char *)ammunition_slots_0 + i)].id
      && v10->profile->slots[*(const survarium::profile_slot_enum *)((char *)ammunition_slots_0 + i)].condition_or_stack )
    {
      v51.path = survarium::items_dictionary::item_by_id(
                   v10->dictionary,
                   (survarium::items_dictionary_vtbl *)v10->profile->slots[*(const survarium::profile_slot_enum *)((char *)ammunition_slots_0 + i)].dict_id)->item_cfg_name.m_begin;
      v51.id = weapon_ammunition_class;
      vostok::buffer_vector<vostok::resources::request>::push_back(&v49, &v51);
      v53 = helmet_slot;
      vostok::buffer_vector<vostok::variant<32> const *>::push_back(v16, (int)v48, (const vostok::variant<32> **)&v53);
      v10 = v52;
    }
  }
  for ( j = 0; j < 0x34; j += 4 )
  {
    v17 = v10->profile;
    v53 = item_slots_0[j / 4];
    v18 = (int)&v17->slots[v53];
    v19 = v17->slots[v53].id == 0;
    i = v18;
    if ( v19 )
      continue;
    v20 = survarium::items_dictionary::item_by_id(
            v10->dictionary,
            (survarium::items_dictionary_vtbl *)v17->slots[v53].dict_id);
    if ( !v20 )
    {
      *(_DWORD *)(v18 + 8) = 0;
      continue;
    }
    v21 = vostok::configs::binary_config_value::operator[](v20->item_cfg.m_object->m_root, "data");
    v22 = vostok::configs::binary_config_value::operator[](v21, "type");
    v23 = (_BYTE *)i;
    dictionary = v10->dictionary;
    pointer = (vostok::variant<32> *)v22->data.pointer;
    v51.id = (vostok::resources::class_id_enum)survarium::items_dictionary::item_by_id(
                                                 dictionary,
                                                 (survarium::items_dictionary_vtbl *)*(unsigned __int16 *)(i + 12))->item_cfg_name.m_begin;
    if ( pointer == (vostok::variant<32> *)2 )
    {
      LOBYTE(v41.id) = v10->profile->is_local;
      BYTE1(v41.id) = *v23;
      physics_world = v10->physics_world;
      v43 = v10->game_scene;
      v28 = (vostok::variant<32> *)&v37[12 * v53 + 2];
      i = booby_trap_set_class;
      pointer = v28;
      vostok::variant<32>::destroy_previous_variable_if_needed(v25, (int)v28);
      v28->m_type_id = vostok::detail::type_to_int<survarium::booby_trap_set_cook_data>::get();
      if ( v28 != (vostok::variant<32> *)-8 )
      {
        *(_DWORD *)v28->m_storage = v41.id;
        *(_DWORD *)&v28->m_storage[4] = physics_world;
        *(_DWORD *)&v28->m_storage[8] = v43;
        v28 = pointer;
      }
      *(_DWORD *)v28->m_helper_storage = &vostok::detail::concrete_type_helper<survarium::booby_trap_set_cook_data>::`vftable';
      goto LABEL_32;
    }
    if ( pointer == (vostok::variant<32> *)4 )
    {
      i = unknown_data_class;
      goto LABEL_23;
    }
    if ( pointer == (vostok::variant<32> *)5 )
    {
      i = rifle_scope_class;
      goto LABEL_23;
    }
    if ( pointer == (vostok::variant<32> *)9 )
    {
      LOBYTE(v39) = v10->profile->is_local;
      v26 = *v23;
      v27 = v10->game_scene;
      BYTE1(v39) = v26;
      v28 = (vostok::variant<32> *)&v37[12 * v53 + 2];
      i = grenade_set_class;
      vostok::variant<32>::destroy_previous_variable_if_needed(v25, (int)v28);
      v28->m_type_id = vostok::detail::type_to_int<survarium::grenade_set_cook_data>::get();
      if ( v28 != (vostok::variant<32> *)-8 )
      {
        v25 = v39;
        *(_DWORD *)v28->m_storage = v39;
        *(_DWORD *)&v28->m_storage[4] = v27;
      }
      *(_DWORD *)v28->m_helper_storage = &vostok::detail::concrete_type_helper<survarium::grenade_set_cook_data>::`vftable';
LABEL_32:
      pointer = v28;
      v28->m_helper = (vostok::detail::abstract_type_helper *)v28;
      goto LABEL_33;
    }
    i = item_class;
LABEL_23:
    pointer = 0;
LABEL_33:
    vostok::buffer_vector<vostok::variant<32> const *>::push_back(
      (vostok::buffer_vector<vostok::variant<32> const *> *)v25,
      (int)v48,
      (const vostok::variant<32> **)&pointer);
    v47.path = (const char *)v51.id;
    v47.id = i;
    vostok::buffer_vector<vostok::resources::request>::push_back(&v49, &v47);
    v10 = v52;
  }
  if ( v49.m_begin == v49.m_end )
  {
    v47.path = uri;
    v47.id = unknown_data_class;
    vostok::buffer_vector<vostok::resources::request>::push_back(&v49, &v47);
    v51.id = unknown_data_class;
    vostok::buffer_vector<vostok::variant<32> const *>::push_back(v29, (int)v48, (const vostok::variant<32> **)&v51.id);
    v10 = v52;
  }
  v41.path = (const char *)survarium::inventory_cook::on_subresources_loaded;
  v43 = v10;
  physics_world = v44;
  v41.id = unknown_data_class;
  v45 = survarium::inventory_cook::on_subresources_loaded;
  v46 = 0;
  v47.path = (const char *)v44;
  v47.id = (vostok::resources::class_id_enum)v10;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    v40[0] = 0;
  }
  else
  {
    v40[2] = (int)v45;
    v40[3] = v46;
    v41 = v47;
    v40[0] = (int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::inventory_cook,vostok::resources::queries_result &,survarium::inventory_cooker_data *>,boost::_bi::list3<boost::_bi::value<survarium::inventory_cook *>,boost::arg<1>,boost::_bi::value<survarium::inventory_cooker_data *>>>>'::`2'::stored_vtable
           + 1;
  }
  vostok::resources::query_resources(
    v49.m_begin,
    v49.m_end - v49.m_begin,
    survarium::g_allocator,
    v48[0],
    parent,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v30, v40);
  v32 = &v39;
  for ( k = 22; k >= 0; --k )
  {
    v32 -= 12;
    vostok::variant<32>::destroy_previous_variable_if_needed(v31, (int)v32);
  }
}
