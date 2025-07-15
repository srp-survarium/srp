void __thiscall survarium::inventory_cook::on_subresources_loaded(
        survarium::inventory_cook *this,
        vostok::resources::queries_result *data,
        survarium::inventory *cooker_data)
{
  vostok::memory::doug_lea_allocator *v3; // esi
  char *v4; // eax
  vostok::memory::doug_lea_allocator *v5; // ecx
  char *v6; // eax
  survarium::inventory *v7; // eax
  survarium::inventory_vtbl *v8; // ecx
  void (__thiscall **v9)(struct survarium::inventory *, unsigned int); // ebx
  survarium::empty_hands *p_m_prev_in_global_delay_delete_list; // edi
  survarium::empty_hands *v11; // esi
  survarium::inventory_item *v12; // ecx
  __int16 v13; // ax
  vostok::particle::particle_system_instance_impl *v14; // esi
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *p_m_unmanaged_resource; // edi
  survarium::inventory_vtbl *v16; // ecx
  int v17; // ebx
  vostok::particle::particle_system_instance_impl *m_object; // esi
  __int16 v19; // ax
  survarium::inventory *v20; // esi
  int v21; // eax
  survarium::profile_slot_enum *M_finish; // ebx
  const vostok::resources::memory_type *m_last_high; // eax
  const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v24; // edi
  signed int v25; // ebx
  unsigned __int8 *v26; // edi
  unsigned __int8 *v27; // esi
  char *v28; // eax
  vostok::particle::particle_system_instance_impl_vtbl *v29; // eax
  stlp_std::priv::_Vector_base<enum survarium::profile_slot_enum,vostok::vectora_allocator<enum survarium::profile_slot_enum> > *v30; // ecx
  int v31; // ebx
  int v32; // eax
  vostok::memory::doug_lea_allocator *v33; // esi
  int v34; // edi
  char *v35; // eax
  vostok::memory::doug_lea_allocator *v36; // ecx
  char *v37; // eax
  unsigned __int8 *v38; // eax
  unsigned __int8 *v39; // edi
  unsigned __int8 *j; // ecx
  stlp_std::priv::_Vector_base<enum survarium::profile_slot_enum,vostok::vectora_allocator<enum survarium::profile_slot_enum> > *v41; // ecx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v42; // edi
  survarium::inventory *v43; // esi
  survarium::inventory_vtbl *v44; // ecx
  int v45; // ebx
  vostok::particle::particle_system_instance_impl *v46; // esi
  __int16 v47; // ax
  survarium::inventory *v48; // esi
  unsigned int k; // edi
  float *p_m_clothes_weight; // ecx
  unsigned __int16 v51; // ax
  survarium::dictionary_item *v52; // eax
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *m_parent_query; // ebx
  survarium::pure_game_effect_emitter_base *v54; // ecx
  vostok::resources::query_result_for_cook *v55; // ecx
  unsigned __int8 *v56; // [esp-8h] [ebp-58h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v57; // [esp-4h] [ebp-54h] BYREF
  const stlp_std::__false_type *v58; // [esp+0h] [ebp-50h]
  const char *v59; // [esp+4h] [ebp-4Ch]
  unsigned int v60; // [esp+8h] [ebp-48h]
  survarium::inventory *v61; // [esp+Ch] [ebp-44h]
  int v62; // [esp+10h] [ebp-40h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v63; // [esp+14h] [ebp-3Ch] BYREF
  unsigned int i; // [esp+18h] [ebp-38h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *other; // [esp+1Ch] [ebp-34h]
  vostok::intrusive_ptr<survarium::empty_hands,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v66; // [esp+20h] [ebp-30h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v67; // [esp+24h] [ebp-2Ch] BYREF
  vostok::resources::memory_usage_type slot; // [esp+28h] [ebp-28h] BYREF
  stlp_std::priv::_Impl_vector<enum survarium::profile_slot_enum,vostok::vectora_allocator<enum survarium::profile_slot_enum> > v69; // [esp+30h] [ebp-20h] BYREF
  unsigned __int8 *src; // [esp+40h] [ebp-10h] BYREF
  unsigned __int8 *v71; // [esp+44h] [ebp-Ch]
  stlp_std::priv::_STLP_alloc_proxy<enum survarium::profile_slot_enum *,enum survarium::profile_slot_enum,vostok::vectora_allocator<enum survarium::profile_slot_enum> > v72; // [esp+48h] [ebp-8h] BYREF

  v3 = survarium::g_allocator;
  v4 = type_info::raw_name(&survarium::inventory `RTTI Type Descriptor');
  v6 = vostok::memory::doug_lea_allocator::malloc_impl(v5, (int)v3, 0x190u, v4, (const char *const)v58, v59, v60);
  if ( v6 )
  {
    survarium::inventory::inventory(cooker_data, (int)v6, (const survarium::items_dictionary *)cooker_data->type);
    v61 = v7;
  }
  else
  {
    v61 = 0;
  }
  v62 = 0;
  other = (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource;
  for ( i = 0; i < 8; i += 4 )
  {
    v8 = cooker_data->__vftable;
    slot.type = (const vostok::resources::memory_type *)weapon_slots_2[i / 4];
    v9 = &v8[2].decrease_quality + 4 * (int)slot.type;
    if ( *((_DWORD *)&v8[2].is_increasing_quality + 4 * (int)slot.type) )
    {
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        &v67,
        other);
      if ( v67.m_object )
        p_m_prev_in_global_delay_delete_list = (survarium::empty_hands *)&v67.m_object[-1].m_prev_in_global_delay_delete_list;
      else
        p_m_prev_in_global_delay_delete_list = 0;
      v11 = 0;
      v66.m_object = 0;
      if ( p_m_prev_in_global_delay_delete_list )
      {
        vostok::intrusive_ptr<survarium::empty_hands,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v66);
        v11 = p_m_prev_in_global_delay_delete_list;
        v66.m_object = p_m_prev_in_global_delay_delete_list;
        _InterlockedExchangeAdd(&p_m_prev_in_global_delay_delete_list->m_reference_count, 1u);
      }
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v67);
      v13 = *((_WORD *)v9 + 6);
      ++v62;
      other += 184;
      v63.m_object = 0;
      HIWORD(v11->m_transform.lines[1].elements[0]) = v13;
      v14 = (vostok::particle::particle_system_instance_impl *)&v11->vostok::resources::unmanaged_resource;
      if ( v14 )
      {
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v63);
        v63.m_object = v14;
        v12 = (survarium::inventory_item *)_InterlockedExchangeAdd(&v14->m_reference_count, 1u);
      }
      LOWORD(v12) = *(_WORD *)v9;
      survarium::inventory_item::set_amount(v12, (int)v63.m_object);
      survarium::inventory::set_item(
        v61,
        (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v63,
        (survarium::profile_slot_enum)slot.type);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v63);
      vostok::intrusive_ptr<survarium::empty_hands,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v66);
    }
  }
  i = 0;
  p_m_unmanaged_resource = &data->m_queries[v62].m_unmanaged_resource;
  do
  {
    v16 = cooker_data->__vftable;
    slot.type = (const vostok::resources::memory_type *)ammunition_slots_0[i / 4];
    v17 = (int)(&v16[2].decrease_quality + 4 * (int)slot.type);
    if ( *((_DWORD *)&v16[2].is_increasing_quality + 4 * (int)slot.type) && *(_DWORD *)v17 )
    {
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        &v67,
        (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)p_m_unmanaged_resource);
      m_object = (vostok::particle::particle_system_instance_impl *)v67.m_object;
      v63.m_object = 0;
      if ( v67.m_object )
      {
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v63);
        v63.m_object = m_object;
        _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
      }
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v67);
      v19 = *(_WORD *)(v17 + 12);
      v57.m_object = (survarium::pure_game_effect_emitter_base *)slot.type;
      v20 = v61;
      ++v62;
      HIWORD(v63.m_object->m_lods[0].m_emitter_instance_list.m_last) = v19;
      p_m_unmanaged_resource += 184;
      survarium::inventory::set_item(
        v20,
        (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v63,
        (survarium::profile_slot_enum)v57.m_object);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v63);
    }
    i += 4;
  }
  while ( i < 0x20 );
  for ( other = 0; (unsigned int)other < 8; ++other )
  {
    v69._M_end_of_storage.m_allocator = survarium::g_allocator;
    v21 = *(const survarium::profile_slot_enum *)((char *)weapon_slots_2 + (_DWORD)other);
    M_finish = 0;
    v69._M_end_of_storage._M_data = 0;
    v69._M_start = 0;
    v69._M_finish = 0;
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v63,
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v61->m_slots.elems[v21]);
    if ( v63.m_object )
    {
      m_last_high = (const vostok::resources::memory_type *)HIWORD(v63.m_object->m_lods[0].m_emitter_instance_list.m_last);
      i = 0;
      slot.type = m_last_high;
      do
      {
        v24 = (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v61->m_slots.elems[ammunition_slots_0[i / 4]];
        v67.m_object = (survarium::pure_game_effect_emitter_base *)ammunition_slots_0[i / 4];
        vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
          (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v66,
          v24);
        if ( v66.m_object
          && survarium::items_dictionary::check_items_compatibility(
               (survarium::items_dictionary *)cooker_data->type,
               (unsigned int)slot.type,
               HIWORD(v66.m_object->m_transform.right.elements[0])) )
        {
          if ( M_finish == v69._M_end_of_storage._M_data )
          {
            stlp_std::priv::_Impl_vector<enum survarium::profile_slot_enum,vostok::vectora_allocator<enum survarium::profile_slot_enum>>::_M_insert_overflow_aux(
              &v69,
              M_finish,
              (survarium::profile_slot_enum *)&v67,
              v58,
              (unsigned int)v59,
              v60);
            M_finish = v69._M_finish;
          }
          else
          {
            if ( M_finish )
              *(vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)M_finish = v67;
            v69._M_finish = ++M_finish;
          }
        }
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v66);
        i += 4;
      }
      while ( i < 0x20 );
      src = 0;
      v71 = 0;
      v72._M_data = 0;
      v25 = M_finish - v69._M_start;
      v72.m_allocator = v69._M_end_of_storage.m_allocator;
      v67.m_object = (survarium::pure_game_effect_emitter_base *)v25;
      v26 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<enum survarium::profile_slot_enum *,enum survarium::profile_slot_enum,vostok::vectora_allocator<enum survarium::profile_slot_enum>>::allocate(
                                 v25,
                                 (unsigned int *)&v67,
                                 &v72);
      src = v26;
      v72._M_data = (survarium::profile_slot_enum *)&v26[4 * (int)v67.m_object];
      v27 = v26;
      if ( v25 > 0 )
      {
        v28 = (char *)((char *)v69._M_start - (char *)v26);
        do
        {
          if ( v27 )
            *(_DWORD *)v27 = *(_DWORD *)&v28[(_DWORD)v27];
          v27 += 4;
          --v25;
        }
        while ( v25 > 0 );
      }
      v29 = v63.m_object->__vftable;
      v71 = v27;
      v31 = ((int (__thiscall *)(vostok::particle::particle_system_instance_impl *))v29[1].is_finished)(v63.m_object);
      v32 = (v27 - v26) >> 2;
      *(_BYTE *)(v31 + 1048) = v32;
      if ( (_BYTE)v32 )
      {
        v33 = survarium::g_allocator;
        *(_BYTE *)(v31 + 1049) = 0;
        v34 = (unsigned __int8)v32;
        v35 = type_info::raw_name(&enum survarium::profile_slot_enum `RTTI Type Descriptor');
        v37 = vostok::memory::doug_lea_allocator::malloc_impl(
                v36,
                (int)v33,
                4 * v34 + 8,
                v35,
                (const char *const)v58,
                v59,
                v60);
        *(_DWORD *)v37 = v34;
        v37 += 4;
        *(_DWORD *)v37 = 4;
        v38 = (unsigned __int8 *)(v37 + 4);
        v39 = &v38[4 * v34];
        for ( j = v38; j != v39; j += 4 )
        {
          if ( j )
            *(_DWORD *)j = 0;
        }
        v57.m_object = (survarium::pure_game_effect_emitter_base *)(4 * *(unsigned __int8 *)(v31 + 1048));
        v56 = src;
        *(_DWORD *)(v31 + 1044) = v38;
        memcpy(v38, v56, (unsigned int)v57.m_object);
      }
      stlp_std::priv::_Vector_base<enum survarium::profile_slot_enum,vostok::vectora_allocator<enum survarium::profile_slot_enum>>::~_Vector_base<enum survarium::profile_slot_enum,vostok::vectora_allocator<enum survarium::profile_slot_enum>>(
        v30,
        (int)&src);
    }
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v63);
    stlp_std::priv::_Vector_base<enum survarium::profile_slot_enum,vostok::vectora_allocator<enum survarium::profile_slot_enum>>::~_Vector_base<enum survarium::profile_slot_enum,vostok::vectora_allocator<enum survarium::profile_slot_enum>>(
      v41,
      (int)&v69);
  }
  other = 0;
  v42 = &data->m_queries[v62].m_unmanaged_resource;
  do
  {
    v43 = cooker_data;
    v44 = cooker_data->__vftable;
    slot.type = *(const vostok::resources::memory_type **)((char *)item_slots_0 + (_DWORD)other);
    v45 = (int)(&v44[2].decrease_quality + 4 * (int)slot.type);
    if ( *((_DWORD *)&v44[2].is_increasing_quality + 4 * (int)slot.type) )
    {
      if ( v42[-22].m_object )
      {
        vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
          &v67,
          (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)v42);
        v46 = (vostok::particle::particle_system_instance_impl *)v67.m_object;
        v63.m_object = 0;
        if ( v67.m_object )
        {
          vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v63);
          v63.m_object = v46;
          _InterlockedExchangeAdd(&v46->m_reference_count, 1u);
        }
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v67);
        v47 = *(_WORD *)(v45 + 12);
        v57.m_object = (survarium::pure_game_effect_emitter_base *)slot.type;
        v48 = v61;
        HIWORD(v63.m_object->m_lods[0].m_emitter_instance_list.m_last) = v47;
        survarium::inventory::set_item(
          v48,
          (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v63,
          (survarium::profile_slot_enum)v57.m_object);
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v63);
        v43 = cooker_data;
      }
      v42 += 184;
    }
    ++other;
  }
  while ( (unsigned int)other < 0x34 );
  for ( k = 0; k < 7; ++k )
  {
    p_m_clothes_weight = (float *)v43->__vftable;
    v51 = *((_WORD *)&v43->__vftable[3].~survarium::inventory + 8 * clothes_slots_0[k]);
    if ( v51 )
    {
      v52 = survarium::items_dictionary::item_by_id(
              (survarium::items_dictionary *)v43->type,
              (survarium::items_dictionary_vtbl *)v51);
      p_m_clothes_weight = &v61->m_clothes_weight;
      v61->m_clothes_weight = v52->weight + v61->m_clothes_weight;
    }
  }
  m_parent_query = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)data->m_parent_query;
  v57.m_object = (survarium::pure_game_effect_emitter_base *)p_m_clothes_weight;
  slot.type = &vostok::resources::nocache_memory;
  slot.size = 400;
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    &v57,
    (survarium::pure_game_effect_emitter_base *)v61);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(&slot, v54, m_parent_query, v57);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v55,
    (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)m_parent_query,
    result_out_of_memory,
    assert_on_fail_true,
    result_fail);
}
