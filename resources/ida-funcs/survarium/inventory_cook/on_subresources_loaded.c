void __thiscall survarium::inventory_cook::on_subresources_loaded(
        survarium::inventory_cook *this,
        vostok::resources::queries_result *data,
        survarium::inventory_cooker_data *cooker_data)
{
  survarium::game_camera *v3; // ecx
  vostok::memory::doug_lea_allocator *v4; // eax
  vostok::resources::queries_result *v5; // ecx
  survarium::inventory *v6; // eax
  vostok::resources::query_result *v7; // eax
  vostok::resources::query_result_for_user *v8; // ecx
  survarium::game_camera *v9; // ecx
  survarium::game_camera *v10; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v11; // ecx
  const vostok::variant<32> **v12; // eax
  survarium::inventory_item *v13; // ecx
  survarium::profile_slot *v14; // ecx
  vostok::resources::query_result *v15; // eax
  vostok::resources::query_result_for_user *v16; // ecx
  vostok::resources::query_result *v17; // eax
  vostok::resources::resource_quality *v18; // ecx
  vostok::resources::query_result *v19; // eax
  vostok::resources::query_result_for_user *v20; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v21; // ecx
  vostok::resources::memory_usage_type *v22; // eax
  vostok::resources::unmanaged_resource *v23; // ecx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v24[2]; // [esp-4h] [ebp-CCh] BYREF
  vostok::resources::memory_usage_type *memory_usage; // [esp+4h] [ebp-C4h]
  survarium::inventory *v26; // [esp+8h] [ebp-C0h]
  survarium::inventory_cook *thisa; // [esp+Ch] [ebp-BCh]
  unsigned __int16 v28; // [esp+16h] [ebp-B2h]
  const vostok::variant<32> **v29; // [esp+18h] [ebp-B0h]
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v30; // [esp+20h] [ebp-A8h]
  survarium::inventory_item *v31; // [esp+24h] [ebp-A4h]
  survarium::inventory_item *v32; // [esp+28h] [ebp-A0h]
  unsigned __int16 v33; // [esp+2Eh] [ebp-9Ah]
  const vostok::variant<32> **v34; // [esp+30h] [ebp-98h]
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v35; // [esp+38h] [ebp-90h]
  survarium::inventory_item *v36; // [esp+3Ch] [ebp-8Ch]
  survarium::inventory_item *v37; // [esp+40h] [ebp-88h]
  survarium::inventory_item *v38; // [esp+48h] [ebp-80h]
  unsigned __int16 dict_id; // [esp+4Eh] [ebp-7Ah]
  survarium::weapon_core *m_object; // [esp+50h] [ebp-78h]
  char v41; // [esp+57h] [ebp-71h]
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *unmanaged_resource; // [esp+58h] [ebp-70h]
  vostok::ai::sound_player *object; // [esp+5Ch] [ebp-6Ch]
  void *_Where; // [esp+60h] [ebp-68h]
  vostok::memory::doug_lea_allocator *v45; // [esp+64h] [ebp-64h]
  boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> *v46; // [esp+6Ch] [ebp-5Ch] BYREF
  vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> v47; // [esp+74h] [ebp-54h] BYREF
  vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> v48; // [esp+78h] [ebp-50h] BYREF
  char v49; // [esp+7Eh] [ebp-4Ah]
  char v50; // [esp+7Fh] [ebp-49h]
  vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> v51; // [esp+80h] [ebp-48h] BYREF
  char v52; // [esp+87h] [ebp-41h]
  survarium::inventory *v53; // [esp+88h] [ebp-40h]
  char v54; // [esp+8Fh] [ebp-39h]
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v55; // [esp+90h] [ebp-38h] BYREF
  survarium::profile_slot_enum v56; // [esp+94h] [ebp-34h]
  unsigned int k; // [esp+98h] [ebp-30h]
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v58; // [esp+9Ch] [ebp-2Ch] BYREF
  survarium::profile_slot_enum v59; // [esp+A0h] [ebp-28h]
  unsigned int j; // [esp+A4h] [ebp-24h]
  vostok::resources::resource_ptr<survarium::weapon_core,vostok::resources::unmanaged_intrusive_base> wpn; // [esp+A8h] [ebp-20h] BYREF
  vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base> iitem; // [esp+ACh] [ebp-1Ch] BYREF
  survarium::profile_slot_enum current; // [esp+B0h] [ebp-18h]
  unsigned int i; // [esp+B4h] [ebp-14h]
  survarium::inventory *result; // [esp+B8h] [ebp-10h]
  survarium::profile_slot *slot; // [esp+BCh] [ebp-Ch]
  vostok::resources::query_result_for_cook *parent; // [esp+C0h] [ebp-8h]
  unsigned int result_index; // [esp+C4h] [ebp-4h]

  thisa = this;
  v54 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v3);
  v45 = v4;
  _Where = vostok::memory::doug_lea_allocator::malloc_impl(v4, 0x160u);
  v53 = (survarium::inventory *)operator new(0x160u, _Where);
  if ( v53 )
  {
    survarium::inventory::inventory(v53);
    v26 = v6;
  }
  else
  {
    v26 = 0;
  }
  result = v26;
  result_index = 0;
  for ( i = 0; i < 2; ++i )
  {
    current = weapon_slots_1[i];
    slot = &cooker_data->profile->slots[current];
    v5 = (vostok::resources::queries_result *)slot;
    if ( slot->item.id )
    {
      v52 = 0;
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)slot);
      v7 = vostok::resources::queries_result::operator[](data, result_index);
      unmanaged_resource = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::resources::query_result_for_user::get_unmanaged_resource(v8, (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v7, (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v51);
      object = (vostok::ai::sound_player *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(unmanaged_resource);
      vostok::resources::resource_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base>(
        (vostok::resources::resource_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base> *)&wpn,
        object);
      vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v51);
      ++result_index;
      v50 = 0;
      survarium::weapon_user_dead_state::finalize(v9);
      v41 = 0;
      survarium::weapon_user_dead_state::finalize(v10);
      dict_id = slot->item.dict_id;
      m_object = wpn.m_object;
      wpn.m_object->m_dict_id = dict_id;
      v38 = (survarium::inventory_item *)wpn.m_object;
      iitem.m_object = 0;
      vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
        &iitem.vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>,
        &wpn.m_object->survarium::inventory_item);
      v12 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v11, (int)&iitem);
      HIWORD(v13) = HIWORD(slot);
      LOWORD(v13) = slot->item.condition_or_stack;
      survarium::inventory_item::set_amount(v13, (int)v12);
      survarium::inventory::set_item(
        result,
        current,
        (vostok::intrusive_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&iitem);
      vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&iitem);
      vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&wpn);
    }
  }
  for ( j = 0; j < 4; ++j )
  {
    v59 = ammunition_slots_0[j];
    v14 = &cooker_data->profile->slots[v59];
    slot = v14;
    if ( v14->item.id )
    {
      v49 = 0;
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v14);
      v15 = vostok::resources::queries_result::operator[](data, result_index);
      v35 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::resources::query_result_for_user::get_unmanaged_resource(v16, (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v15, (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v48);
      v37 = (survarium::inventory_item *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(v35);
      v36 = v37;
      v58.m_object = 0;
      vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
        &v58,
        v37);
      vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v48);
      ++result_index;
      v33 = slot->item.dict_id;
      v34 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
              (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)result_index,
              (int)&v58);
      *((_WORD *)v34 + 139) = v33;
      survarium::inventory::set_item(
        result,
        v59,
        (vostok::intrusive_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v58);
      vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&v58);
    }
    v5 = (vostok::resources::queries_result *)(j + 1);
  }
  for ( k = 0; k < 0xD; ++k )
  {
    v56 = item_slots_0[k];
    v5 = (vostok::resources::queries_result *)(16 * v56);
    slot = &cooker_data->profile->slots[v56];
    if ( slot->item.id )
    {
      v17 = vostok::resources::queries_result::operator[](data, result_index);
      if ( vostok::resources::resource_quality::get_class_id(v18, (int)v17) )
      {
        v19 = vostok::resources::queries_result::operator[](data, result_index);
        v30 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::resources::query_result_for_user::get_unmanaged_resource(v20, (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v19, (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v47);
        v32 = (survarium::inventory_item *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(v30);
        v31 = v32;
        v55.m_object = 0;
        vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
          &v55,
          v32);
        vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v47);
        v28 = slot->item.dict_id;
        v29 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v21, (int)&v55);
        *((_WORD *)v29 + 139) = v28;
        survarium::inventory::set_item(
          result,
          v56,
          (vostok::intrusive_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v55);
        vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&v55);
      }
      ++result_index;
    }
  }
  parent = vostok::resources::queries_result::get_parent_query(v5, (int)data);
  vostok::resources::memory_usage_type::memory_usage_type(
    (boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> *)&vostok::resources::nocache_memory,
    &v46,
    (vostok::network_core::packet_reader *)0x160,
    (vostok::network_core::packet_reader *)v24[1].m_object);
  memory_usage = v22;
  v24[0].m_object = v23;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    v24,
    (vostok::configs::binary_config *)result);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(memory_usage, parent, v24[0]);
  vostok::resources::query_result_for_cook::finish_query(parent, result_success, assert_on_fail_true);
}
