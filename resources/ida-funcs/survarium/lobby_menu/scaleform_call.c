void __thiscall survarium::lobby_menu::scaleform_call(
        survarium::lobby_menu *this,
        survarium::flash_function_handler_params *params)
{
  survarium::lobby_menu *v4; // ecx
  survarium::lobby_client *v5; // eax
  int v6; // edi
  survarium::player_params_modifiers_container *p_modifiers; // ecx
  survarium::player_params_modifiers_container *v8; // ecx
  survarium::player_params_modifiers_container *v9; // ecx
  survarium::flash_value *v10; // ecx
  survarium::flash_value *v11; // ecx
  unsigned __int16 v12; // si
  survarium::flash_value *v13; // ecx
  survarium::flash_value *v14; // ecx
  survarium::flash_value *v15; // ecx
  survarium::dictionary_item *v16; // eax
  survarium::dictionary_item *v17; // ecx
  int v18; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v19; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v20; // eax
  bool has_passed_filters; // al
  survarium::dictionary_item *v22; // eax
  survarium::items_dictionary *v23; // ecx
  survarium::relocate_item_descr *v24; // eax
  __int16 v25; // cx
  unsigned int v26; // eax
  stlp_std::vector<survarium::relocate_item_descr,survarium::std_allocator<survarium::relocate_item_descr> > *v27; // ecx
  survarium::relocate_item_descr *v28; // eax
  __int16 v29; // cx
  float v30; // xmm0_4
  unsigned __int16 v31; // ax
  survarium::dictionary_item *v32; // eax
  int v33; // esi
  unsigned int v34; // esi
  unsigned __int64 v35; // rax
  unsigned int v36; // ecx
  vostok::memory::doug_lea_allocator *m_max_end_low; // ecx
  unsigned __int8 *v38; // esi
  survarium::relocate_item_descr *v39; // eax
  __int16 v40; // cx
  char v41; // al
  const vostok::configs::binary_config_value *v42; // eax
  vostok::configs::binary_config_value *v43; // ecx
  vostok::configs::binary_config_value *v44; // eax
  unsigned __int8 pointer; // al
  __int16 v46; // cx
  unsigned __int64 v47; // rax
  const survarium::profile_slot_enum *v48; // esi
  survarium::relocate_item_descr *v49; // ecx
  __int16 v50; // dx
  char v51; // al
  vostok::vectora<survarium::inventory_item_descr> *p_m_inventory_item_instances; // eax
  survarium::inventory_item_descr *M_start; // esi
  unsigned __int16 v54; // di
  survarium::items_dictionary *v55; // ecx
  char v56; // al
  survarium::relocate_item_descr *id; // eax
  unsigned int condition_or_stack; // eax
  survarium::dictionary_item *v59; // eax
  vostok::configs::binary_config_value *v60; // eax
  const vostok::configs::binary_config_value *v61; // eax
  int v62; // eax
  int v63; // ecx
  survarium::relocate_item_descr *v64; // esi
  bool v65; // al
  unsigned __int64 v66; // rax
  unsigned __int16 *p_item_dict_id; // esi
  bool v68; // zf
  survarium::dictionary_item *v69; // eax
  vostok::configs::binary_config_value *v70; // eax
  survarium::dictionary_item *v71; // eax
  vostok::configs::binary_config_value *v72; // eax
  int max_storage_low; // edi
  unsigned int v74; // eax
  unsigned __int8 v75; // cl
  unsigned int v76; // ecx
  int v77; // ecx
  unsigned __int8 v78; // cl
  unsigned int v79; // ecx
  survarium::lobby_client *v80; // eax
  survarium::relocate_item_descr v81; // [esp-Ah] [ebp-25Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v82; // [esp-2h] [ebp-254h]
  const void *M_finish_high; // [esp-2h] [ebp-254h]
  unsigned int v84; // [esp-2h] [ebp-254h]
  const char *v85; // [esp+6h] [ebp-24Ch]
  unsigned int v86; // [esp+Ah] [ebp-248h]
  unsigned __int8 v87; // [esp+11h] [ebp-241h]
  char v88; // [esp+11h] [ebp-241h]
  char v89; // [esp+11h] [ebp-241h]
  unsigned __int8 v90; // [esp+11h] [ebp-241h]
  unsigned __int8 v91; // [esp+12h] [ebp-240h]
  char v92; // [esp+12h] [ebp-240h]
  unsigned __int8 v93; // [esp+12h] [ebp-240h]
  unsigned __int8 v94; // [esp+13h] [ebp-23Fh]
  __int16 i; // [esp+14h] [ebp-23Eh]
  int v96; // [esp+16h] [ebp-23Ch]
  unsigned int first_item_dict_id; // [esp+1Ah] [ebp-238h]
  survarium::items_dictionary *v98; // [esp+1Eh] [ebp-234h]
  float v99; // [esp+22h] [ebp-230h]
  unsigned int second_item_dict_id; // [esp+26h] [ebp-22Ch]
  unsigned int dict_id; // [esp+2Ah] [ebp-228h]
  stlp_std::vector<survarium::relocate_item_descr,survarium::std_allocator<survarium::relocate_item_descr> > v102; // [esp+2Eh] [ebp-224h] BYREF
  unsigned int v103; // [esp+3Ah] [ebp-218h]
  float v104; // [esp+3Eh] [ebp-214h]
  float v105; // [esp+42h] [ebp-210h]
  unsigned int m_end_low; // [esp+46h] [ebp-20Ch]
  unsigned int item_category_id; // [esp+4Ah] [ebp-208h]
  stlp_std::vector<survarium::relocate_item_descr,survarium::std_allocator<survarium::relocate_item_descr> > v108; // [esp+4Eh] [ebp-204h] BYREF
  int v109; // [esp+5Ah] [ebp-1F8h]
  stlp_std::vector<survarium::relocate_item_descr,survarium::std_allocator<survarium::relocate_item_descr> > v110; // [esp+5Eh] [ebp-1F4h] BYREF
  stlp_std::vector<survarium::relocate_item_descr,survarium::std_allocator<survarium::relocate_item_descr> > v111; // [esp+6Ah] [ebp-1E8h] BYREF
  int v112; // [esp+76h] [ebp-1DCh]
  int v113; // [esp+7Ah] [ebp-1D8h]
  vostok::fixed_vector<survarium::sound_game_effect_presenter::effect_data,16>::allign_helper *v114; // [esp+7Eh] [ebp-1D4h]
  survarium::flash_value value; // [esp+82h] [ebp-1D0h] BYREF
  Scaleform::GFx::Value v116; // [esp+9Ah] [ebp-1B8h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v117; // [esp+B2h] [ebp-1A0h] BYREF
  survarium::dictionary_item __that; // [esp+D2h] [ebp-180h] BYREF

  v96 = 0;
  memset(&v110, 0, sizeof(v110));
  v91 = (*(int (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)params->pArgs + 40))(
          *(_DWORD *)params->pArgs,
          *(_DWORD *)&params->pArgs->body[8]);
  v87 = this->m_effect_presenter.m_sound_presenter.m_old_effects.m_buffer[13].m_store[8];
  v114 = &this[-1].m_effect_presenter.m_sound_presenter.m_new_effects.m_buffer[7];
  v5 = survarium::lobby_menu::lobby_client(
         v4,
         (int)this[-1].m_effect_presenter.m_sound_presenter.m_new_effects.m_buffer[7].m_store);
  v6 = (int)&v5->m_profiles[v87];
  second_item_dict_id = v5->m_profiles[v87].slots[7].dict_id;
  dict_id = v5->m_profiles[v87].slots[10].dict_id;
  p_modifiers = &v5->m_profiles[v87].modifiers;
  v113 = v6;
  v88 = 0;
  v99 = (float)(unsigned __int8)(int)survarium::player_params_modifiers_container::get_modifier_value(
                                       p_modifiers,
                                       ammo_bags_modifier).m128_f32[0];
  v105 = (float)(unsigned __int8)(int)survarium::player_params_modifiers_container::get_modifier_value(
                                        v8,
                                        quick_slot_size_modifier).m128_f32[0];
  v104 = (float)(unsigned __int8)(int)survarium::player_params_modifiers_container::get_modifier_value(
                                        v9,
                                        device_slots_modifier).m128_f32[0];
  if ( v91 )
  {
    v98 = 0;
    v103 = 1;
    first_item_dict_id = v91;
    while ( 1 )
    {
      v116.pObjectInterface = 0;
      v116.Type = VT_Undefined;
      *(_DWORD *)value.body = 0;
      *(_DWORD *)&value.body[4] = 0;
      (*(void (__thiscall **)(_DWORD, _DWORD, survarium::items_dictionary *, Scaleform::GFx::Value *))(**(_DWORD **)params->pArgs + 48))(
        *(_DWORD *)params->pArgs,
        *(_DWORD *)&params->pArgs->body[8],
        v98,
        &v116);
      survarium::flash_value::GetMember(v10, &v116, "id", &value);
      v102._M_impl._M_start = *(survarium::relocate_item_descr **)&value.body[8];
      survarium::flash_value::GetMember(v11, &v116, "dict_id", &value);
      v12 = *(_WORD *)&value.body[8];
      LOWORD(v102._M_impl._M_finish) = *(_WORD *)&value.body[8];
      survarium::flash_value::GetMember(v13, &v116, "sourceSlot", &value);
      BYTE2(v102._M_impl._M_finish) = value.body[8];
      survarium::flash_value::GetMember(v14, &v116, "targetSlot", &value);
      HIBYTE(v102._M_impl._M_finish) = value.body[8];
      survarium::flash_value::GetMember(v15, &v116, "count", &value);
      v102._M_impl._M_end_of_storage._M_data = (survarium::relocate_item_descr *)*(unsigned __int16 *)&value.body[8];
      v16 = survarium::items_dictionary::item_by_id(
              *(survarium::items_dictionary **)(*(_DWORD *)&this[-1].m_player_ammo_bags_count + 13908),
              (survarium::items_dictionary_vtbl *)v12);
      survarium::dictionary_item::dictionary_item(v17, &__that, (int)v16);
      v18 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)&this[-1].m_player_ammo_bags_count + 13912) + 60))(*(_DWORD *)(*(_DWORD *)&this[-1].m_player_ammo_bags_count + 13912))
          + 12712;
      v19 = *(boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> **)v18;
      v20 = *(boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> **)(v18 + 4);
      while ( 1 )
      {
        if ( v19 == v20 )
        {
          if ( !vostok::core::g_log_filter_tree
            || (has_passed_filters = vostok::logging::has_passed_filters(
                                       (vostok::logging::filter_tree *)"game",
                                       (const char *)2),
                v19 = v82,
                has_passed_filters) )
          {
            boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
              v19,
              &v117);
            v96 |= 1u;
            vostok::logging::append(
              &v117,
              (void *const)vostok::core::g_log_flags,
              &vostok::core::g_log_format,
              ".\\lobby_menu_ui.cpp",
              0xB5u,
              "void __thiscall survarium::lobby_menu::scaleform_call(struct survarium::flash_function_handler_params &)",
              "game",
              error,
              "Item with id[%d] doesn't exist in inventory!!!",
              v102._M_impl._M_start);
          }
          if ( (v96 & 1) != 0 )
          {
            v96 &= ~1u;
            boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
              (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v19,
              (int *)&v117);
          }
          goto LABEL_38;
        }
        if ( v19->functor.obj_ptr == v102._M_impl._M_start )
          break;
        v19 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)((char *)v19 + 16);
      }
      M_finish_high = (const void *)HIBYTE(v102._M_impl._M_finish);
      item_category_id = *(_DWORD *)(*(_DWORD *)&this[-1].m_player_ammo_bags_count + 13908);
      m_end_low = HIBYTE(v102._M_impl._M_finish);
      v22 = survarium::items_dictionary::item_by_id(
              (survarium::items_dictionary *)item_category_id,
              (survarium::items_dictionary_vtbl *)v12);
      if ( !survarium::items_dictionary::can_move_item_to_slot(
              v23,
              item_category_id,
              (const void *)v22->item_category,
              M_finish_high) )
        goto LABEL_38;
      stlp_std::vector<survarium::relocate_item_descr,survarium::std_allocator<survarium::relocate_item_descr>>::push_back(
        &v102,
        (int)&v110);
      if ( HIBYTE(v102._M_impl._M_finish) == 7 || HIBYTE(v102._M_impl._M_finish) == 10 )
        goto LABEL_17;
      if ( BYTE2(v102._M_impl._M_finish) != 7 )
        break;
LABEL_18:
      if ( HIBYTE(v102._M_impl._M_finish) == 10 )
      {
        v24 = *(survarium::relocate_item_descr **)(v6 + 240);
        if ( v24 )
        {
          v25 = *(_WORD *)(v6 + 244);
          v112 = 0;
          v111._M_impl._M_start = v24;
          second_item_dict_id += dict_id;
          LOWORD(v111._M_impl._M_finish) = v25;
          v26 = second_item_dict_id - dict_id;
          v111._M_impl._M_end_of_storage._M_data = (survarium::relocate_item_descr *)1;
          HIWORD(v111._M_impl._M_finish) = 1892;
          v27 = &v111;
          goto LABEL_25;
        }
      }
LABEL_21:
      if ( BYTE2(v102._M_impl._M_finish) != 10 )
      {
        if ( HIBYTE(v102._M_impl._M_finish) == 7 )
LABEL_27:
          second_item_dict_id = v12;
LABEL_28:
        if ( HIBYTE(v102._M_impl._M_finish) == 10 )
          dict_id = v12;
        second_item_dict_id &= -((unsigned __int8)(BYTE2(v102._M_impl._M_finish) - 7) != 0);
        dict_id &= -((unsigned __int8)(BYTE2(v102._M_impl._M_finish) - 10) != 0);
        goto LABEL_31;
      }
      if ( HIBYTE(v102._M_impl._M_finish) != 7 )
        goto LABEL_28;
      v28 = *(survarium::relocate_item_descr **)(v6 + 192);
      if ( !v28 )
        goto LABEL_27;
      v29 = *(_WORD *)(v6 + 196);
      v109 = 0;
      v108._M_impl._M_start = v28;
      second_item_dict_id += dict_id;
      LOWORD(v108._M_impl._M_finish) = v29;
      v26 = second_item_dict_id - dict_id;
      v108._M_impl._M_end_of_storage._M_data = (survarium::relocate_item_descr *)1;
      HIWORD(v108._M_impl._M_finish) = 2660;
      v27 = &v108;
LABEL_25:
      second_item_dict_id -= v26;
      dict_id = v26;
      stlp_std::vector<survarium::relocate_item_descr,survarium::std_allocator<survarium::relocate_item_descr>>::push_back(
        v27,
        (int)&v110);
LABEL_31:
      v88 = 1;
LABEL_32:
      if ( HIBYTE(v102._M_impl._M_finish) == 100 )
      {
        v99 = v99 - __that.modifiers[16];
        v105 = v105 - __that.modifiers[17];
        v30 = v104 - __that.modifiers[15];
      }
      else
      {
        v31 = *(_WORD *)(16 * m_end_low + v6 + 84);
        if ( v31 )
        {
          v32 = survarium::items_dictionary::item_by_id(
                  *(survarium::items_dictionary **)(*(_DWORD *)&this[-1].m_player_ammo_bags_count + 13908),
                  (survarium::items_dictionary_vtbl *)v31);
          v99 = v99 - v32->modifiers[16];
          v105 = v105 - v32->modifiers[17];
          v104 = v104 - v32->modifiers[15];
        }
        v99 = __that.modifiers[16] + v99;
        v105 = __that.modifiers[17] + v105;
        v30 = __that.modifiers[15] + v104;
      }
      v104 = v30;
LABEL_38:
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&__that.item_cfg);
      Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&value);
      Scaleform::GFx::Value::~Value(&v116);
      v98 = (survarium::items_dictionary *)((char *)v98 + 1);
      if ( !--first_item_dict_id )
        goto LABEL_39;
    }
    if ( BYTE2(v102._M_impl._M_finish) != 10 )
      goto LABEL_32;
LABEL_17:
    if ( BYTE2(v102._M_impl._M_finish) != 7 )
      goto LABEL_21;
    goto LABEL_18;
  }
LABEL_39:
  m_end_low = LOBYTE(this->m_effect_presenter.m_sound_presenter.m_new_effects.m_end);
  v33 = BYTE1(this->m_effect_presenter.m_sound_presenter.m_new_effects.m_end);
  LODWORD(v99) = (unsigned __int64)v99 + m_end_low;
  v34 = (unsigned __int64)v105 + v33;
  v105 = *(float *)&v34;
  v35 = (unsigned __int64)v104;
  v36 = BYTE2(this->m_effect_presenter.m_sound_presenter.m_new_effects.m_end);
  m_end_low = v35;
  if ( LODWORD(v99) < v36 )
    v88 = 1;
  m_max_end_low = (vostok::memory::doug_lea_allocator *)LOBYTE(this->m_effect_presenter.m_sound_presenter.m_new_effects.m_max_end);
  if ( (unsigned int)v35 < (unsigned int)m_max_end_low
    || v34 < HIBYTE(this->m_effect_presenter.m_sound_presenter.m_new_effects.m_end) )
  {
    v98 = 0;
    v96 = (int)quick_slots_1;
    first_item_dict_id = 6;
    do
    {
      v38 = (unsigned __int8 *)(16 * *(_DWORD *)v96 + v6 + 72);
      v39 = *(survarium::relocate_item_descr **)(16 * *(_DWORD *)v96 + v6 + 80);
      if ( v39 )
      {
        if ( (unsigned int)v98 < m_end_low )
        {
          item_category_id = (unsigned int)survarium::items_dictionary::item_by_id(
                                             *(survarium::items_dictionary **)(*(_DWORD *)&this[-1].m_player_ammo_bags_count
                                                                             + 13908),
                                             (survarium::items_dictionary_vtbl *)*(unsigned __int16 *)(16 * *(_DWORD *)v96 + v6 + 84));
          v42 = vostok::configs::binary_config_value::operator[](
                  *(vostok::configs::binary_config_value **)(*(_DWORD *)(item_category_id + 4) + 264),
                  "parameters");
          if ( vostok::configs::binary_config_value::value_exists(v43, (int)v42, (unsigned int)"quick_slot_item_size") )
          {
            v44 = vostok::configs::binary_config_value::operator[](
                    *(vostok::configs::binary_config_value **)(*(_DWORD *)(item_category_id + 4) + 264),
                    "parameters");
            pointer = (unsigned __int8)vostok::configs::binary_config_value::operator[](v44, "quick_slot_item_size")->data.pointer;
          }
          else
          {
            pointer = 1;
          }
          v46 = *((_WORD *)v38 + 6);
          v112 = 0;
          LOWORD(v111._M_impl._M_finish) = v46;
          v111._M_impl._M_start = (survarium::relocate_item_descr *)*((_DWORD *)v38 + 2);
          item_category_id = pointer;
          v47 = (unsigned __int64)((double)LODWORD(v105) / (double)pointer);
          if ( *v38 >= (unsigned __int8)v47 )
            LOWORD(v47) = (unsigned __int8)v47;
          else
            LOWORD(v47) = *v38;
          v111._M_impl._M_end_of_storage._M_data = (survarium::relocate_item_descr *)(unsigned __int16)v47;
          BYTE2(v111._M_impl._M_finish) = *(_BYTE *)v96;
          HIBYTE(v111._M_impl._M_finish) = BYTE2(v111._M_impl._M_finish);
          stlp_std::vector<survarium::relocate_item_descr,survarium::std_allocator<survarium::relocate_item_descr>>::push_back(
            &v111,
            (int)&v110);
          v6 = v113;
        }
        else
        {
          v40 = *(_WORD *)(16 * *(_DWORD *)v96 + v6 + 84);
          v103 = 0;
          v102._M_impl._M_start = v39;
          v102._M_impl._M_end_of_storage._M_data = (survarium::relocate_item_descr *)*(unsigned __int16 *)v38;
          v41 = *(_BYTE *)v96;
          LOWORD(v102._M_impl._M_finish) = v40;
          BYTE2(v102._M_impl._M_finish) = v41;
          HIBYTE(v102._M_impl._M_finish) = 100;
          stlp_std::vector<survarium::relocate_item_descr,survarium::std_allocator<survarium::relocate_item_descr>>::push_back(
            &v102,
            (int)&v110);
        }
      }
      v98 = (survarium::items_dictionary *)((char *)v98 + 1);
      v96 += 4;
      --first_item_dict_id;
    }
    while ( first_item_dict_id );
  }
  if ( v88 )
  {
    memset(&v111, 0, sizeof(v111));
    v48 = ammunition_slots_1;
    first_item_dict_id = 8;
    do
    {
      v49 = *(survarium::relocate_item_descr **)(16 * *v48 + v113 + 80);
      if ( v49 )
      {
        v50 = *(_WORD *)(16 * *v48 + v113 + 84);
        v102._M_impl._M_end_of_storage._M_data = (survarium::relocate_item_descr *)*(unsigned __int16 *)(16 * *v48 + v113 + 72);
        v51 = *(_BYTE *)v48;
        v102._M_impl._M_start = v49;
        BYTE2(v102._M_impl._M_finish) = v51;
        v103 = 0;
        LOWORD(v102._M_impl._M_finish) = v50;
        HIBYTE(v102._M_impl._M_finish) = 100;
        stlp_std::vector<survarium::relocate_item_descr,survarium::std_allocator<survarium::relocate_item_descr>>::push_back(
          &v102,
          (int)&v111);
      }
      ++v48;
      --first_item_dict_id;
    }
    while ( first_item_dict_id );
    memset(&v108, 0, sizeof(v108));
    p_m_inventory_item_instances = &survarium::lobby_menu::lobby_client((survarium::lobby_menu *)v49, (int)v114)->m_inventory_item_instances;
    M_start = p_m_inventory_item_instances->_M_impl._M_start;
    m_end_low = (unsigned int)p_m_inventory_item_instances->_M_impl._M_finish;
    for ( i = 0; M_start != (survarium::inventory_item_descr *)m_end_low; ++M_start )
    {
      v54 = M_start->dict_id;
      v55 = *(survarium::items_dictionary **)(*(_DWORD *)&this[-1].m_player_ammo_bags_count + 13908);
      first_item_dict_id = v54;
      v98 = v55;
      v92 = survarium::items_dictionary::check_items_compatibility(v55, v54, second_item_dict_id);
      v56 = survarium::items_dictionary::check_items_compatibility(v98, v54, dict_id);
      v89 = v56;
      if ( v92 || v56 )
      {
        id = (survarium::relocate_item_descr *)M_start->id;
        v102._M_impl._M_end_of_storage._M_data = 0;
        v102._M_impl._M_start = id;
        condition_or_stack = M_start->condition_or_stack;
        LOWORD(v102._M_impl._M_finish) = v54;
        v103 = condition_or_stack;
        HIWORD(v102._M_impl._M_finish) = 100;
        v59 = survarium::items_dictionary::item_by_id(v98, (survarium::items_dictionary_vtbl *)first_item_dict_id);
        v60 = vostok::configs::binary_config_value::operator[](v59->item_cfg.m_object->m_root, "parameters");
        v61 = vostok::configs::binary_config_value::operator[](v60, "clip_size");
        if ( LOBYTE(v61->data.max_storage) <= v103 )
        {
          stlp_std::vector<survarium::relocate_item_descr,survarium::std_allocator<survarium::relocate_item_descr>>::push_back(
            &v102,
            (int)&v108);
          if ( v92 )
            ++HIBYTE(i);
          if ( v89 )
            LOBYTE(i) = i + 1;
        }
      }
    }
    v102._M_impl._M_start = *(survarium::relocate_item_descr **)(*(_DWORD *)&this[-1].m_player_ammo_bags_count + 13908);
    v102._M_impl._M_finish = (survarium::relocate_item_descr *)second_item_dict_id;
    v102._M_impl._M_end_of_storage._M_data = (survarium::relocate_item_descr *)dict_id;
    if ( v108._M_impl._M_start != v108._M_impl._M_finish )
    {
      v62 = v108._M_impl._M_finish - v108._M_impl._M_start;
      v63 = 0;
      while ( v62 != 1 )
      {
        ++v63;
        v62 >>= 1;
      }
      stlp_std::priv::__introsort_loop<survarium::relocate_item_descr *,survarium::relocate_item_descr,int,survarium::ammo_slots_sort>(
        v108._M_impl._M_start,
        v108._M_impl._M_finish,
        0,
        2 * v63,
        (survarium::ammo_slots_sort)v102);
      *(stlp_std::vector<survarium::relocate_item_descr,survarium::std_allocator<survarium::relocate_item_descr> > *)&v81.item_id = v102;
      stlp_std::priv::__final_insertion_sort<survarium::relocate_item_descr *,survarium::ammo_slots_sort>(
        v108._M_impl._M_start,
        v108._M_impl._M_finish,
        v81);
    }
    v64 = v108._M_impl._M_start;
    v90 = 0;
    first_item_dict_id = HIBYTE(i);
    v65 = HIBYTE(i) == v108._M_impl._M_finish - v108._M_impl._M_start && HIBYTE(i) == (_BYTE)i
       || !HIBYTE(i)
       || !(_BYTE)i;
    if ( HIBYTE(i) )
    {
      if ( v65 )
        LOBYTE(v66) = LOBYTE(v99);
      else
        v66 = (unsigned __int64)((double)LODWORD(v99) * 0.69999999 + 0.5);
      v94 = v66;
    }
    else
    {
      v94 = 0;
    }
    v96 = 169088050;
    v93 = LOBYTE(v99) - v94;
    if ( v108._M_impl._M_start != v108._M_impl._M_finish )
    {
      p_item_dict_id = &v108._M_impl._M_start->item_dict_id;
      do
      {
        v68 = LODWORD(v99) == 0;
        LODWORD(v104) = v90;
        *((_BYTE *)p_item_dict_id + 3) = ammunition_slots_1[v90];
        if ( !v68 )
        {
          v69 = survarium::items_dictionary::item_by_id(
                  *(survarium::items_dictionary **)(*(_DWORD *)&this[-1].m_player_ammo_bags_count + 13908),
                  (survarium::items_dictionary_vtbl *)*p_item_dict_id);
          v70 = vostok::configs::binary_config_value::operator[](v69->item_cfg.m_object->m_root, "parameters");
          v98 = (survarium::items_dictionary *)vostok::configs::binary_config_value::operator[](v70, "clips_in_bag")->data.pointer;
          v71 = survarium::items_dictionary::item_by_id(
                  *(survarium::items_dictionary **)(*(_DWORD *)&this[-1].m_player_ammo_bags_count + 13908),
                  (survarium::items_dictionary_vtbl *)*p_item_dict_id);
          v72 = vostok::configs::binary_config_value::operator[](v71->item_cfg.m_object->m_root, "parameters");
          max_storage_low = LOBYTE(vostok::configs::binary_config_value::operator[](v72, "clip_size")->data.max_storage);
          v74 = *((_DWORD *)p_item_dict_id + 2) / (unsigned int)(max_storage_low * (_DWORD)v98);
          if ( v90 >= HIBYTE(i) )
          {
            if ( LODWORD(v104) == (unsigned __int8)i + first_item_dict_id - 1 )
              v78 = 100;
            else
              v78 = *((_BYTE *)&v96 + LODWORD(v104));
            v79 = (unsigned __int8)(int)(float)((float)((float)(v93 * v78) * 0.0099999998) + 0.5);
            if ( v74 >= v79 )
              LOBYTE(v74) = v79;
            v77 = max_storage_low * (_DWORD)v98 * (unsigned __int8)v74;
            v93 -= v74;
          }
          else
          {
            if ( LODWORD(v104) == first_item_dict_id - 1 )
              v75 = 100;
            else
              v75 = *((_BYTE *)&v96 + LODWORD(v104));
            v76 = (unsigned __int8)(int)(float)((float)((float)(v94 * v75) * 0.0099999998) + 0.5);
            if ( v74 >= v76 )
              LOBYTE(v74) = v76;
            v77 = max_storage_low * (_DWORD)v98 * (unsigned __int8)v74;
            v94 -= v74;
          }
          ++v90;
          *((_DWORD *)p_item_dict_id + 1) = v77;
        }
        p_item_dict_id += 8;
      }
      while ( p_item_dict_id - 2 != (unsigned __int16 *)v108._M_impl._M_finish );
      v64 = v108._M_impl._M_start;
    }
    stlp_std::vector<survarium::relocate_item_descr,survarium::std_allocator<survarium::relocate_item_descr>>::insert<survarium::relocate_item_descr *>(
      (stlp_std::priv::_Impl_vector<survarium::relocate_item_descr,survarium::std_allocator<survarium::relocate_item_descr> > *)v111._M_impl._M_finish,
      v111._M_impl._M_start,
      &v110,
      v110._M_impl._M_finish);
    stlp_std::vector<survarium::relocate_item_descr,survarium::std_allocator<survarium::relocate_item_descr>>::insert<survarium::relocate_item_descr *>(
      (stlp_std::priv::_Impl_vector<survarium::relocate_item_descr,survarium::std_allocator<survarium::relocate_item_descr> > *)v108._M_impl._M_finish,
      v64,
      &v110,
      v110._M_impl._M_finish);
    if ( v64 )
      vostok::memory::doug_lea_allocator::free_impl(
        m_max_end_low,
        (int)survarium::g_allocator,
        (char *)v108._M_impl._M_start,
        (const char *const)v81.amount_in_inventory,
        v85,
        v86);
    if ( v111._M_impl._M_start )
      vostok::memory::doug_lea_allocator::free_impl(
        m_max_end_low,
        (int)survarium::g_allocator,
        (char *)v111._M_impl._M_start,
        (const char *const)v81.amount_in_inventory,
        v85,
        v86);
  }
  if ( v110._M_impl._M_finish - v110._M_impl._M_start )
  {
    v84 = *(_DWORD *)(v113 + 4);
    v80 = survarium::lobby_menu::lobby_client((survarium::lobby_menu *)m_max_end_low, (int)v114);
    survarium::lobby_client::move_item((survarium::vector<survarium::relocate_item_descr> *)&v110, v80, v84);
  }
  if ( v110._M_impl._M_start )
    vostok::memory::doug_lea_allocator::free_impl(
      m_max_end_low,
      (int)survarium::g_allocator,
      (char *)v110._M_impl._M_start,
      (const char *const)v81.amount_in_inventory,
      v85,
      v86);
}
