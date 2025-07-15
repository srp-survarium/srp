void __thiscall survarium::lobby_menu::scaleform_callback(
        survarium::lobby_menu *this,
        survarium::flash_movie *pmovieView,
        char *methodName,
        Scaleform::GFx::Value *args,
        unsigned int argCount)
{
  survarium::lobby_client *v6; // eax
  survarium::lobby_client *v7; // ecx
  survarium::lobby_menu *v8; // ecx
  survarium::lobby_client *v9; // eax
  survarium::lobby_client *v10; // ecx
  survarium::lobby_menu *v11; // ecx
  survarium::game *v12; // ecx
  survarium::lobby_menu *v13; // ecx
  survarium::lobby_menu *v14; // ecx
  char *v15; // esi
  int v16; // edi
  survarium::lobby_client *v17; // eax
  survarium::lobby_client *v18; // ecx
  survarium::flash_value *v19; // ecx
  survarium::lobby_menu *v20; // ecx
  int v21; // eax
  survarium::lobby_client *v22; // eax
  survarium::lobby_client *v23; // ecx
  unsigned int v24; // esi
  survarium::flash_value *v25; // ecx
  survarium::flash_value *v26; // ecx
  survarium::player_skill *v27; // eax
  vostok::memory::doug_lea_allocator *v28; // esi
  Scaleform::GFx::Value::ObjectInterface_vtbl *v29; // eax
  survarium::lobby_menu *v30; // ecx
  unsigned int v31; // esi
  int v32; // ecx
  survarium::lobby_client *v33; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v34; // ecx
  survarium::lobby_menu *v35; // ecx
  survarium::lobby_client *v36; // eax
  survarium::lobby_client *v37; // ecx
  survarium::flash_value *v38; // ecx
  const char *v39; // eax
  survarium::lobby_menu *v40; // ecx
  survarium::messaging_client *v41; // eax
  survarium::messaging_client *v42; // ecx
  survarium::lobby_menu *v43; // ecx
  survarium::messaging_client *v44; // eax
  survarium::messaging_client *v45; // ecx
  survarium::lobby_menu *v46; // ecx
  survarium::messaging_client *v47; // eax
  survarium::messaging_client *v48; // ecx
  survarium::lobby_menu *v49; // ecx
  survarium::messaging_client *v50; // eax
  survarium::messaging_client *v51; // ecx
  survarium::lobby_menu *v52; // ecx
  survarium::messaging_client *v53; // eax
  survarium::messaging_client *v54; // ecx
  survarium::flash_value *v55; // ecx
  const char *String; // eax
  survarium::chat_handler *v57; // ecx
  survarium::chat_handler *v58; // ecx
  survarium::game_options *v59; // ecx
  survarium::game *v60; // ecx
  const vostok::network_core::tcp_packet *v61; // eax
  survarium::lobby_client *v62; // ecx
  unsigned int UIValue; // esi
  Scaleform::GFx::Movie *v64; // ecx
  survarium::lobby_menu *v65; // ecx
  survarium::messaging_client *v66; // eax
  const vostok::messaging::send_message_params *M_finish; // esi
  const vostok::messaging::send_message_params *v68; // eax
  survarium::lobby_menu *v69; // ecx
  survarium::messaging_client *v70; // eax
  survarium::messaging_client *v71; // ecx
  survarium::messaging_client *v72; // eax
  survarium::messaging_client *v73; // ecx
  Scaleform::GFx::Value::ObjectInterface *pObjectInterface; // ecx
  Scaleform::GFx::Value::ObjectInterface_vtbl *v75; // eax
  survarium::lobby_menu *v76; // ecx
  const survarium::profile_slot_enum *v77; // esi
  survarium::player_skill *v78; // ecx
  __int16 v79; // dx
  char v80; // al
  Scaleform::GFx::Value::ObjectInterface *v81; // ecx
  survarium::flash_value *v82; // ecx
  survarium::flash_value *v83; // ecx
  survarium::flash_value *v84; // ecx
  survarium::flash_value *v85; // ecx
  survarium::flash_value *v86; // ecx
  char v87; // al
  int v88; // esi
  survarium::flash_value *v89; // ecx
  survarium::lobby_client *v90; // eax
  char *v91; // esi
  const char *v92; // edi
  int v93; // ecx
  bool v94; // zf
  char *v95; // esi
  const char *v96; // edi
  int v97; // ecx
  bool v98; // zf
  survarium::flash_value *v99; // ecx
  const char *v100; // eax
  int v101; // eax
  survarium::flash_value *v102; // ecx
  const char *v103; // eax
  int v104; // eax
  survarium::messaging_client *v105; // ecx
  survarium::lobby_menu *v106; // ecx
  unsigned __int8 v107; // bl
  int v108; // esi
  survarium::lobby_client *v109; // eax
  survarium::lobby_menu *v110; // ecx
  survarium::lobby_client *v111; // eax
  survarium::lobby_client *v112; // ecx
  survarium::lobby_menu *v113; // ecx
  int v114; // eax
  survarium::lobby_client *v115; // eax
  survarium::lobby_client *v116; // ecx
  survarium::player_params_modifiers_container *v117; // ecx
  unsigned __int8 v118; // al
  survarium::lobby_menu *v119; // ecx
  Scaleform::GFx::Value::ObjectInterface *v120; // ecx
  survarium::flash_value *v121; // ecx
  survarium::flash_value *v122; // ecx
  vostok::configs::binary_config_value *v123; // esi
  vostok::configs::binary_config_value *v124; // eax
  vostok::configs::binary_config_value *v125; // esi
  const vostok::configs::binary_config_value *v126; // eax
  int v127; // esi
  const vostok::configs::binary_config_value *v128; // eax
  float pointer; // xmm0_4
  survarium::lobby_menu *v130; // esi
  survarium::flash_value *v131; // ecx
  const char *v132; // eax
  survarium::lobby_menu *v133; // ecx
  survarium::messaging_client *v134; // eax
  survarium::messaging_client *v135; // ecx
  survarium::lobby_menu *v136; // ecx
  survarium::lobby_client *v137; // eax
  survarium::lobby_client *v138; // ecx
  survarium::lobby_menu *v139; // ecx
  survarium::lobby_client *v140; // eax
  survarium::lobby_client *v141; // ecx
  survarium::lobby_menu *v142; // ecx
  survarium::lobby_client *v143; // eax
  survarium::lobby_client *v144; // ecx
  survarium::lobby_menu *v145; // ecx
  survarium::lobby_client *v146; // eax
  survarium::lobby_client *v147; // ecx
  survarium::lobby_menu *v148; // ecx
  survarium::lobby_client *v149; // eax
  survarium::lobby_client *v150; // ecx
  int v151; // [esp+Ch] [ebp-594h]
  int v152; // [esp+Ch] [ebp-594h]
  survarium::lobby_menu *v153; // [esp+10h] [ebp-590h]
  unsigned int v154; // [esp+10h] [ebp-590h]
  unsigned int v155; // [esp+10h] [ebp-590h]
  int v156; // [esp+10h] [ebp-590h]
  unsigned __int8 v157; // [esp+10h] [ebp-590h]
  unsigned int v158; // [esp+10h] [ebp-590h]
  int IValue; // [esp+14h] [ebp-58Ch]
  const char *v160; // [esp+14h] [ebp-58Ch]
  unsigned int v161; // [esp+14h] [ebp-58Ch]
  unsigned int v162; // [esp+14h] [ebp-58Ch]
  unsigned int v163; // [esp+14h] [ebp-58Ch]
  unsigned int v164; // [esp+14h] [ebp-58Ch]
  int v165; // [esp+14h] [ebp-58Ch]
  int v166; // [esp+14h] [ebp-58Ch]
  unsigned int v167; // [esp+14h] [ebp-58Ch]
  int v168; // [esp+14h] [ebp-58Ch]
  unsigned __int8 v169; // [esp+14h] [ebp-58Ch]
  int v170; // [esp+14h] [ebp-58Ch]
  int v171; // [esp+14h] [ebp-58Ch]
  int v172; // [esp+14h] [ebp-58Ch]
  const char *v173; // [esp+18h] [ebp-588h]
  const char *v174; // [esp+1Ch] [ebp-584h]
  unsigned int v175; // [esp+20h] [ebp-580h]
  unsigned __int8 v176[4]; // [esp+24h] [ebp-57Ch] BYREF
  survarium::lobby_menu *v177; // [esp+28h] [ebp-578h]
  bool use_premium_money[4]; // [esp+2Ch] [ebp-574h]
  survarium::player_skill __x[2]; // [esp+30h] [ebp-570h] BYREF
  unsigned __int8 faction_id[4]; // [esp+34h] [ebp-56Ch] BYREF
  unsigned int count; // [esp+38h] [ebp-568h]
  vostok::vectora<survarium::player_skill> skills; // [esp+3Ch] [ebp-564h] BYREF
  survarium::flash_value value; // [esp+4Ch] [ebp-554h] BYREF
  unsigned int message_id; // [esp+64h] [ebp-53Ch]
  Scaleform::GFx::Value v185; // [esp+68h] [ebp-538h] BYREF
  Scaleform::GFx::Value v186; // [esp+80h] [ebp-520h] BYREF
  Scaleform::GFx::Value v187; // [esp+98h] [ebp-508h] BYREF
  vostok::configs::binary_config_value *v188; // [esp+B0h] [ebp-4F0h]
  int v189; // [esp+B4h] [ebp-4ECh]
  survarium::messaging_client _Dst[2]; // [esp+B8h] [ebp-4E8h] BYREF

  v177 = this;
  if ( !vostok::strings::compare(methodName, "accept_change_quest") )
  {
    IValue = args->mValue.IValue;
    v153 = (survarium::lobby_menu *)args[1].mValue.IValue;
    v6 = survarium::lobby_menu::lobby_client(
           v153,
           (int)&this[-1].m_effect_presenter.m_sound_presenter.m_new_effects.m_buffer[7].m_store[8]);
    survarium::lobby_client::switch_quest(v7, (const vostok::network_core::tcp_packet *)v6, (unsigned int)v153, IValue);
  }
  if ( vostok::strings::compare(methodName, "leave_queue") )
  {
    if ( vostok::strings::compare(methodName, "buy_new_profile_clicked") )
    {
      if ( vostok::strings::compare(methodName, "play_button_clicked") )
      {
        if ( vostok::strings::compare(methodName, "close_victory_screen") )
        {
          if ( vostok::strings::compare(methodName, "sound_play") )
          {
            if ( vostok::strings::compare(methodName, "profile_changed") )
            {
              if ( vostok::strings::compare(methodName, "shop_ready") )
              {
                if ( vostok::strings::compare(methodName, "set_mouse_cursor") )
                {
                  if ( vostok::strings::compare(methodName, "buy_ok_clicked") )
                  {
                    if ( vostok::strings::compare(methodName, "unlock_perks") )
                    {
                      if ( vostok::strings::compare(methodName, "reroll_ok_clicked") )
                      {
                        if ( vostok::strings::compare(methodName, "find_players") )
                        {
                          if ( vostok::strings::compare(methodName, "add_friend") )
                          {
                            if ( vostok::strings::compare(methodName, "remove_friend") )
                            {
                              if ( vostok::strings::compare(methodName, "add_ignore") )
                              {
                                if ( vostok::strings::compare(methodName, "remove_ignored") )
                                {
                                  if ( vostok::strings::compare(methodName, "start_friend_message") )
                                  {
                                    if ( vostok::strings::compare(methodName, "show_settings") )
                                    {
                                      if ( vostok::strings::compare(methodName, "sell_ok_clicked") )
                                      {
                                        if ( vostok::strings::compare(methodName, "important_message_read") )
                                        {
                                          if ( !vostok::strings::compare(methodName, "apply_profile_items") )
                                          {
                                            pObjectInterface = args->pObjectInterface;
                                            v166 = args->mValue.IValue;
                                            v75 = args->pObjectInterface->__vftable;
                                            memset(&value, 0, 12);
                                            v176[3] = v75->GetArraySize(pObjectInterface, (void *)v166);
                                            v176[2] = this->m_effect_presenter.m_sound_presenter.m_old_effects.m_buffer[14].m_store[4];
                                            *(_DWORD *)faction_id = (char *)this - 244;
                                            count = (unsigned int)&survarium::lobby_menu::lobby_client(
                                                                     v76,
                                                                     (int)&this[-1].m_effect_presenter.m_sound_presenter.m_new_effects.m_buffer[7].m_store[8])->m_profiles[v176[2]];
                                            v77 = equipment_slots;
                                            *(_DWORD *)use_premium_money = 14;
                                            do
                                            {
                                              v78 = *(survarium::player_skill **)(16 * *v77 + count + 80);
                                              if ( v78 )
                                              {
                                                v79 = *(_WORD *)(16 * *v77 + count + 84);
                                                skills._M_impl._M_end_of_storage.m_allocator = (vostok::memory::base_allocator *)*(unsigned __int16 *)(16 * *v77 + count + 72);
                                                v80 = *(_BYTE *)v77;
                                                skills._M_impl._M_start = v78;
                                                BYTE2(skills._M_impl._M_finish) = v80;
                                                LOWORD(skills._M_impl._M_finish) = v79;
                                                HIBYTE(skills._M_impl._M_finish) = 100;
                                                skills._M_impl._M_end_of_storage._M_data = 0;
                                                stlp_std::vector<survarium::relocate_item_descr,survarium::std_allocator<survarium::relocate_item_descr>>::push_back(
                                                  (stlp_std::vector<survarium::relocate_item_descr,survarium::std_allocator<survarium::relocate_item_descr> > *)&skills,
                                                  (int)&value);
                                              }
                                              ++v77;
                                              --*(_DWORD *)use_premium_money;
                                            }
                                            while ( *(_DWORD *)use_premium_money );
                                            v176[2] = 0;
                                            if ( v176[3] )
                                            {
                                              *(_DWORD *)&__x[0].skill_id = 0;
                                              *(_DWORD *)use_premium_money = v176[3];
                                              do
                                              {
                                                v81 = args->pObjectInterface;
                                                v186.pObjectInterface = 0;
                                                v151 = args->mValue.IValue;
                                                v186.Type = VT_Undefined;
                                                v185.pObjectInterface = 0;
                                                v185.Type = VT_Undefined;
                                                v81->GetElement(v81, (void *)v151, *(_DWORD *)&__x[0].skill_id, &v186);
                                                survarium::flash_value::GetMember(
                                                  v82,
                                                  &v186,
                                                  "id",
                                                  (survarium::flash_value *)&v185);
                                                skills._M_impl._M_start = (survarium::player_skill *)v185.mValue.IValue;
                                                survarium::flash_value::GetMember(
                                                  v83,
                                                  &v186,
                                                  "dict_id",
                                                  (survarium::flash_value *)&v185);
                                                LOWORD(skills._M_impl._M_finish) = LOWORD(v185.mValue.NValue);
                                                survarium::flash_value::GetMember(
                                                  v84,
                                                  &v186,
                                                  "sourceSlot",
                                                  (survarium::flash_value *)&v185);
                                                BYTE2(skills._M_impl._M_finish) = v185.mValue.BValue;
                                                survarium::flash_value::GetMember(
                                                  v85,
                                                  &v186,
                                                  "targetSlot",
                                                  (survarium::flash_value *)&v185);
                                                HIBYTE(skills._M_impl._M_finish) = v185.mValue.BValue;
                                                LOBYTE(v86) = 0;
                                                while ( ammunition_slots_1[(unsigned __int8)v86] != v185.mValue.BValue )
                                                {
                                                  LOBYTE(v86) = (_BYTE)v86 + 1;
                                                  if ( (unsigned __int8)v86 >= 8u )
                                                    goto LABEL_86;
                                                }
                                                v87 = ammunition_slots_1[v176[2]++];
                                                HIBYTE(skills._M_impl._M_finish) = v87;
LABEL_86:
                                                survarium::flash_value::GetMember(
                                                  v86,
                                                  &v186,
                                                  "count",
                                                  (survarium::flash_value *)&v185);
                                                v88 = v185.mValue.IValue;
                                                skills._M_impl._M_end_of_storage.m_allocator = (vostok::memory::base_allocator *)v185.mValue.IValue;
                                                survarium::flash_value::GetMember(
                                                  v89,
                                                  &v186,
                                                  "count_in_inventory",
                                                  (survarium::flash_value *)&v185);
                                                skills._M_impl._M_end_of_storage._M_data = (survarium::player_skill *)v185.mValue.IValue;
                                                if ( v88 || v185.mValue.IValue )
                                                  stlp_std::vector<survarium::relocate_item_descr,survarium::std_allocator<survarium::relocate_item_descr>>::push_back(
                                                    (stlp_std::vector<survarium::relocate_item_descr,survarium::std_allocator<survarium::relocate_item_descr> > *)&skills,
                                                    (int)&value);
                                                Scaleform::GFx::Value::~Value(&v185);
                                                Scaleform::GFx::Value::~Value(&v186);
                                                ++*(_DWORD *)&__x[0].skill_id;
                                                --*(_DWORD *)use_premium_money;
                                              }
                                              while ( *(_DWORD *)use_premium_money );
                                            }
                                            if ( (*(_DWORD *)&value.body[4] - *(_DWORD *)value.body) >> 4 )
                                            {
                                              v167 = *(_DWORD *)(count + 4);
                                              v90 = survarium::lobby_menu::lobby_client(
                                                      (survarium::lobby_menu *)v78,
                                                      *(int *)faction_id);
                                              survarium::lobby_client::move_item(
                                                (survarium::vector<survarium::relocate_item_descr> *)&value,
                                                v90,
                                                v167);
                                            }
                                            if ( *(_DWORD *)value.body )
                                              vostok::memory::doug_lea_allocator::free_impl(
                                                (vostok::memory::doug_lea_allocator *)v78,
                                                (int)survarium::g_allocator,
                                                *(char **)value.body,
                                                v173,
                                                v174,
                                                v175);
                                          }
                                        }
                                        else
                                        {
                                          UIValue = args->mValue.UIValue;
                                          *(_DWORD *)use_premium_money = args[1].mValue.IValue;
                                          v64 = *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)v177->m_effect_presenter.m_sound_presenter.m_old_effects.m_buffer[14].m_store
                                                                                      + 264)
                                                                          + 4);
                                          message_id = UIValue;
                                          Scaleform::GFx::Movie::Invoke(
                                            v64,
                                            "root.remove_important_message",
                                            0,
                                            args,
                                            1u);
                                          *(_DWORD *)faction_id = UIValue;
                                          v66 = survarium::lobby_menu::messaging_client(
                                                  v65,
                                                  (int)&v177[-1].m_effect_presenter.m_sound_presenter.m_new_effects.m_buffer[7].m_store[8]);
                                          M_finish = v66->m_important_messages._M_impl._M_finish;
                                          v68 = stlp_std::priv::__find<vostok::messaging::send_message_params const *,unsigned int>(
                                                  v66->m_important_messages._M_impl._M_start,
                                                  (const unsigned int *)faction_id,
                                                  M_finish);
                                          if ( v68 != M_finish )
                                          {
                                            qmemcpy(&_Dst[0].m_connection_info.host[50], v68, 0x98u);
                                            v69 = 0;
                                            if ( !*(_DWORD *)use_premium_money
                                              && _Dst[0].m_network_client.m_on_connected.functor.vostok_pointer_size_alignment[5] == (void *)2 )
                                            {
                                              v70 = survarium::lobby_menu::messaging_client(
                                                      0,
                                                      (int)&v177[-1].m_effect_presenter.m_sound_presenter.m_new_effects.m_buffer[7].m_store[8]);
                                              survarium::messaging_client::send_important_message(
                                                v71,
                                                (const char (*)[64])v70,
                                                (int)&_Dst[0].m_connection_state,
                                                (const char *)3,
                                                "membership accepted");
                                            }
                                            v155 = message_id;
                                            v72 = survarium::lobby_menu::messaging_client(
                                                    v69,
                                                    (int)&v177[-1].m_effect_presenter.m_sound_presenter.m_new_effects.m_buffer[7].m_store[8]);
                                            survarium::messaging_client::read_important_message(
                                              v73,
                                              (int)v72,
                                              v155,
                                              *(vostok::messaging::important_message_answer *)use_premium_money);
                                          }
                                        }
                                      }
                                      else
                                      {
                                        v165 = args[1].mValue.IValue;
                                        v154 = args->mValue.UIValue;
                                        v61 = (const vostok::network_core::tcp_packet *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(LODWORD(this[-1].m_player_total_items_weight) + 13912) + 60))(*(_DWORD *)(LODWORD(this[-1].m_player_total_items_weight) + 13912));
                                        survarium::lobby_client::sell_item(v62, v61, v154, v165);
                                      }
                                    }
                                    else
                                    {
                                      survarium::game_options::show_options(
                                        v59,
                                        LODWORD(this[-1].m_player_total_items_weight) + 15072,
                                        1);
                                      survarium::game::activate_main_menu(
                                        v60,
                                        LODWORD(this[-1].m_player_total_items_weight));
                                    }
                                  }
                                  else
                                  {
                                    String = survarium::flash_value::GetString(v55, (int)args);
                                    strcpy_s((char *)_Dst, 0x40u, String);
                                    survarium::chat_handler::start_conversation(
                                      v57,
                                      *(const char (**)[64])(LODWORD(this[-1].m_player_total_items_weight) + 13848),
                                      (char *)_Dst);
                                    survarium::chat_handler::focus(
                                      v58,
                                      *(_DWORD *)(LODWORD(this[-1].m_player_total_items_weight) + 13848),
                                      1);
                                  }
                                }
                                else
                                {
                                  v164 = args->mValue.UIValue;
                                  v53 = survarium::lobby_menu::messaging_client(
                                          v52,
                                          (int)&this[-1].m_effect_presenter.m_sound_presenter.m_new_effects.m_buffer[7].m_store[8]);
                                  survarium::messaging_client::remove_from_ignore_list(v54, (int)v53, v164);
                                }
                              }
                              else
                              {
                                v163 = args->mValue.UIValue;
                                v50 = survarium::lobby_menu::messaging_client(
                                        v49,
                                        (int)&this[-1].m_effect_presenter.m_sound_presenter.m_new_effects.m_buffer[7].m_store[8]);
                                survarium::messaging_client::add_to_ignore_list(v51, (int)v50, v163);
                              }
                            }
                            else
                            {
                              v162 = args->mValue.UIValue;
                              v47 = survarium::lobby_menu::messaging_client(
                                      v46,
                                      (int)&this[-1].m_effect_presenter.m_sound_presenter.m_new_effects.m_buffer[7].m_store[8]);
                              survarium::messaging_client::remove_from_friend_list(v48, (int)v47, v162);
                            }
                          }
                          else
                          {
                            v161 = args->mValue.UIValue;
                            v44 = survarium::lobby_menu::messaging_client(
                                    v43,
                                    (int)&this[-1].m_effect_presenter.m_sound_presenter.m_new_effects.m_buffer[7].m_store[8]);
                            survarium::messaging_client::add_to_friend_list(v45, (int)v44, v161);
                          }
                        }
                        else
                        {
                          v39 = survarium::flash_value::GetString(v38, (int)args);
                          v40 = (survarium::lobby_menu *)strlen(v39);
                          if ( (unsigned int)v40 >= 3 )
                          {
                            v160 = v39;
                            v41 = survarium::lobby_menu::messaging_client(
                                    v40,
                                    (int)&this[-1].m_effect_presenter.m_sound_presenter.m_new_effects.m_buffer[7].m_store[8]);
                            survarium::messaging_client::find_players_by_name(v42, (int)v41, v160);
                          }
                        }
                      }
                      else
                      {
                        v36 = survarium::lobby_menu::lobby_client(
                                v35,
                                (int)&this[-1].m_effect_presenter.m_sound_presenter.m_new_effects.m_buffer[7].m_store[8]);
                        survarium::lobby_client::reroll_player_skills(
                          v37,
                          (const vostok::network_core::tcp_packet *)v36);
                      }
                    }
                    else
                    {
                      qmemcpy(&v185, args, sizeof(v185));
                      qmemcpy(&v186, &args[1], sizeof(v186));
                      skills._M_impl._M_end_of_storage.m_allocator = survarium::g_allocator;
                      skills._M_impl._M_start = 0;
                      skills._M_impl._M_finish = 0;
                      skills._M_impl._M_end_of_storage._M_data = 0;
                      v176[2] = 0;
                      if ( v185.pObjectInterface->GetArraySize(v185.pObjectInterface, (void *)v185.mValue.IValue) )
                      {
                        v24 = 0;
                        do
                        {
                          v187.pObjectInterface = 0;
                          v187.Type = VT_Undefined;
                          *(_DWORD *)value.body = 0;
                          *(_DWORD *)&value.body[4] = 0;
                          v185.pObjectInterface->GetElement(
                            v185.pObjectInterface,
                            (void *)v185.mValue.IValue,
                            v24,
                            &v187);
                          survarium::flash_value::GetMember(v25, &v187, "id", &value);
                          v176[3] = value.body[8];
                          survarium::flash_value::GetMember(v26, &v187, "points", &value);
                          __x[0].skill_id = v176[3];
                          __x[0].skill_points = value.body[8];
                          v27 = skills._M_impl._M_finish;
                          if ( skills._M_impl._M_finish == skills._M_impl._M_end_of_storage._M_data )
                          {
                            stlp_std::priv::_Impl_vector<survarium::player_skill,vostok::vectora_allocator<survarium::player_skill>>::_M_insert_overflow(
                              (stlp_std::priv::_Impl_vector<survarium::player_skill,vostok::vectora_allocator<survarium::player_skill> > *)__x,
                              (unsigned __int8 **)&skills,
                              skills._M_impl._M_finish,
                              __x,
                              (const stlp_std::__true_type *)v173,
                              (unsigned int)v174,
                              v175);
                          }
                          else
                          {
                            *skills._M_impl._M_finish = __x[0];
                            skills._M_impl._M_finish = v27 + 1;
                          }
                          Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&value);
                          Scaleform::GFx::Value::~Value(&v187);
                          v24 = ++v176[2];
                        }
                        while ( v176[2] < v185.pObjectInterface->GetArraySize(
                                            v185.pObjectInterface,
                                            (void *)v185.mValue.IValue) );
                      }
                      v28 = survarium::g_allocator;
                      v29 = v186.pObjectInterface->__vftable;
                      *(_DWORD *)value.body = 0;
                      *(_DWORD *)&value.body[4] = 0;
                      *(_DWORD *)&value.body[8] = survarium::g_allocator;
                      *(_DWORD *)&value.body[12] = 0;
                      v176[2] = 0;
                      if ( v29->GetArraySize(v186.pObjectInterface, v186.mValue.pStringManaged) )
                      {
                        v31 = 0;
                        do
                        {
                          v187.pObjectInterface = 0;
                          v187.Type = VT_Undefined;
                          v186.pObjectInterface->GetElement(
                            v186.pObjectInterface,
                            (void *)v186.mValue.IValue,
                            v31,
                            &v187);
                          v32 = *(_DWORD *)&value.body[4];
                          v176[3] = v187.mValue.BValue;
                          if ( *(_DWORD *)&value.body[4] == *(_DWORD *)&value.body[12] )
                          {
                            stlp_std::priv::_Impl_vector<unsigned char,vostok::vectora_allocator<unsigned char>>::_M_insert_overflow(
                              *(stlp_std::priv::_Impl_vector<unsigned char,vostok::vectora_allocator<unsigned char> > **)&value.body[4],
                              (unsigned __int8 **)&value,
                              *(unsigned __int8 **)&value.body[4],
                              &v176[3],
                              (const stlp_std::__true_type *)v173,
                              (unsigned int)v174,
                              v175);
                          }
                          else
                          {
                            **(_BYTE **)&value.body[4] = v187.mValue.BValue;
                            *(_DWORD *)&value.body[4] = v32 + 1;
                          }
                          Scaleform::GFx::Value::~Value(&v187);
                          v31 = ++v176[2];
                        }
                        while ( v176[2] < v186.pObjectInterface->GetArraySize(
                                            v186.pObjectInterface,
                                            (void *)v186.mValue.IValue) );
                        v28 = *(vostok::memory::doug_lea_allocator **)&value.body[8];
                      }
                      v33 = survarium::lobby_menu::lobby_client(
                              v30,
                              (int)&v177[-1].m_effect_presenter.m_sound_presenter.m_new_effects.m_buffer[7].m_store[8]);
                      survarium::lobby_client::set_player_skills(
                        &skills,
                        v34,
                        v33,
                        (vostok::vectora<unsigned char> *)&value);
                      if ( *(_DWORD *)value.body )
                        v28->call_free(
                          v28,
                          *(void **)value.body,
                          "vostok::detail::std_allocator<unsigned char>::deallocate",
                          "c:\\survarium.deploy\\sources\\vostok/std_allocator_inline.h",
                          102u);
                      if ( skills._M_impl._M_start )
                        skills._M_impl._M_end_of_storage.m_allocator->call_free(
                          skills._M_impl._M_end_of_storage.m_allocator,
                          skills._M_impl._M_start,
                          "vostok::detail::std_allocator<struct survarium::player_skill>::deallocate",
                          "c:\\survarium.deploy\\sources\\vostok/std_allocator_inline.h",
                          102u);
                      Scaleform::GFx::Value::~Value(&v186);
                      Scaleform::GFx::Value::~Value(&v185);
                    }
                  }
                  else
                  {
                    count = LOWORD(args->mValue.UIValue);
                    *(_DWORD *)faction_id = LOWORD(args[1].mValue.UIValue);
                    use_premium_money[0] = args[2].mValue.BValue;
                    if ( !use_premium_money[0] )
                    {
                      v176[3] = 1;
                      do
                      {
                        v21 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(LODWORD(this[-1].m_player_total_items_weight)
                                                                          + 13912)
                                                            + 60))(*(_DWORD *)(LODWORD(this[-1].m_player_total_items_weight)
                                                                             + 13912))
                            + 8 * v176[3]
                            + 12744;
                        v20 = (survarium::lobby_menu *)*(unsigned __int16 *)(v21 + 4);
                        v176[2] = 0;
                        if ( (_WORD)v20 )
                        {
                          while ( *(_WORD *)(12 * v176[2] + *(_DWORD *)v21) != (_WORD)count )
                          {
                            if ( ++v176[2] >= (unsigned __int16)v20 )
                              goto LABEL_28;
                          }
                          use_premium_money[0] = v176[3];
                          if ( v176[3] )
                            break;
                        }
LABEL_28:
                        ++v176[3];
                      }
                      while ( v176[3] <= 4u );
                    }
                    v22 = survarium::lobby_menu::lobby_client(
                            v20,
                            (int)&this[-1].m_effect_presenter.m_sound_presenter.m_new_effects.m_buffer[7].m_store[8]);
                    survarium::lobby_client::buy_item(
                      v23,
                      (const vostok::network_core::tcp_packet *)v22,
                      count,
                      faction_id[0],
                      use_premium_money[0]);
                  }
                }
                else
                {
                  survarium::lobby_menu::set_cursor(
                    args->mValue.BValue,
                    v19,
                    (survarium::lobby_menu *)((char *)this - 244));
                }
              }
              else
              {
                v15 = &this[-1].m_effect_presenter.m_sound_presenter.m_new_effects.m_buffer[7].m_store[8];
                v16 = 1;
                *(_DWORD *)use_premium_money = 4;
                do
                {
                  v17 = survarium::lobby_menu::lobby_client(v14, (int)v15);
                  survarium::lobby_client::query_prices(v18, (const vostok::network_core::tcp_packet *)v17, v16++);
                  --*(_DWORD *)use_premium_money;
                }
                while ( *(_DWORD *)use_premium_money );
              }
            }
            else
            {
              survarium::lobby_menu::on_profile_changed(
                v13,
                (int)&this[-1].m_effect_presenter.m_sound_presenter.m_new_effects.m_buffer[7].m_store[8],
                (survarium::factions_enum)args->mValue.BValue);
            }
          }
          else
          {
            survarium::game::play_ui_sound(v12, LODWORD(this[-1].m_player_total_items_weight), args->mValue.BValue);
          }
        }
        else
        {
          this->m_effect_presenter.m_sound_presenter.m_new_effects.m_buffer[1].m_store[9] = 0;
          this->m_effect_presenter.m_sound_presenter.m_new_effects.m_buffer[1].m_store[11] = 0;
        }
      }
      else
      {
        survarium::lobby_menu::play_button_clicked(
          v11,
          (int)&this[-1].m_effect_presenter.m_sound_presenter.m_new_effects.m_buffer[7].m_store[8]);
      }
    }
  }
  else
  {
    v9 = survarium::lobby_menu::lobby_client(
           v8,
           (int)&this[-1].m_effect_presenter.m_sound_presenter.m_new_effects.m_buffer[7].m_store[8]);
    survarium::lobby_client::discard_playing_order(v10, (int)v9);
  }
  v91 = methodName;
  v92 = "chat_enter_start";
  v93 = 17;
  v94 = 1;
  do
  {
    if ( !v93 )
      break;
    v94 = *v91++ == *v92++;
    --v93;
  }
  while ( v94 );
  if ( v94 )
  {
    survarium::chat_handler::focus(
      (survarium::chat_handler *)v93,
      *(_DWORD *)(LODWORD(v177[-1].m_player_total_items_weight) + 13848),
      1);
  }
  else
  {
    v95 = methodName;
    v96 = "chat_enter_cancel";
    v97 = 18;
    v98 = 1;
    do
    {
      if ( !v97 )
        break;
      v98 = *v95++ == *v96++;
      --v97;
    }
    while ( v98 );
    if ( v98 )
    {
      survarium::chat_handler::focus(
        (survarium::chat_handler *)v97,
        *(_DWORD *)(LODWORD(v177[-1].m_player_total_items_weight) + 13848),
        0);
    }
    else if ( vostok::strings::compare(methodName, "chat_tab_close") )
    {
      if ( vostok::strings::compare(methodName, "power_off_button_click") )
      {
        if ( vostok::strings::compare(methodName, "add_friend_name") )
        {
          if ( vostok::strings::compare(methodName, "add_ignore_name") )
          {
            if ( vostok::strings::compare(methodName, "ammo_autobuy_changed") )
            {
              if ( vostok::strings::compare(methodName, "request_players_range") )
              {
                if ( vostok::strings::compare(methodName, "on_skills_tree_selection_changed") )
                {
                  if ( vostok::strings::compare(methodName, "invite_to_squad") )
                  {
                    if ( vostok::strings::compare(methodName, "leave_squad") )
                    {
                      if ( vostok::strings::compare(methodName, "disband_squad") )
                      {
                        if ( vostok::strings::compare(methodName, "remove_from_squad") )
                        {
                          if ( vostok::strings::compare(methodName, "victory_screen_request_player_data") )
                          {
                            if ( !vostok::strings::compare(methodName, "accept_premium") )
                            {
                              v172 = args->mValue.IValue;
                              v149 = survarium::lobby_menu::lobby_client(
                                       v148,
                                       (int)&v177[-1].m_effect_presenter.m_sound_presenter.m_new_effects.m_buffer[7].m_store[8]);
                              survarium::lobby_client::buy_shop_item(
                                v150,
                                (const vostok::network_core::tcp_packet *)v149,
                                v172);
                            }
                          }
                          else
                          {
                            v171 = args[1].mValue.IValue;
                            v158 = args->mValue.UIValue;
                            v146 = survarium::lobby_menu::lobby_client(
                                     v145,
                                     (int)&v177[-1].m_effect_presenter.m_sound_presenter.m_new_effects.m_buffer[7].m_store[8]);
                            survarium::lobby_client::query_player_match_stats(
                              v147,
                              (const vostok::network_core::tcp_packet *)v146,
                              v158,
                              v171);
                          }
                        }
                        else
                        {
                          v170 = args->mValue.IValue;
                          v143 = survarium::lobby_menu::lobby_client(
                                   v142,
                                   (int)&v177[-1].m_effect_presenter.m_sound_presenter.m_new_effects.m_buffer[7].m_store[8]);
                          survarium::lobby_client::drop_squad_member(
                            v144,
                            (const vostok::network_core::tcp_packet *)v143,
                            v170);
                        }
                      }
                      else
                      {
                        v140 = survarium::lobby_menu::lobby_client(
                                 v139,
                                 (int)&v177[-1].m_effect_presenter.m_sound_presenter.m_new_effects.m_buffer[7].m_store[8]);
                        survarium::lobby_client::destroy_squad(v141, (const vostok::network_core::tcp_packet *)v140);
                      }
                    }
                    else
                    {
                      v137 = survarium::lobby_menu::lobby_client(
                               v136,
                               (int)&v177[-1].m_effect_presenter.m_sound_presenter.m_new_effects.m_buffer[7].m_store[8]);
                      survarium::lobby_client::leave_squad(v138, (const vostok::network_core::tcp_packet *)v137);
                    }
                  }
                  else
                  {
                    v132 = survarium::flash_value::GetString(v131, (int)args);
                    strcpy_s((char *)_Dst, 0x40u, v132);
                    v134 = survarium::lobby_menu::messaging_client(
                             v133,
                             (int)&v177[-1].m_effect_presenter.m_sound_presenter.m_new_effects.m_buffer[7].m_store[8]);
                    survarium::messaging_client::send_important_message(
                      v135,
                      (const char (*)[64])v134,
                      (int)_Dst,
                      (const char *)2,
                      "invite");
                  }
                }
                else
                {
                  survarium::player_params_modifiers_container::player_params_modifiers_container(
                    v117,
                    (char *)&_Dst[0].m_network_client.m_on_disconnected.functor);
                  v118 = args->pObjectInterface->GetArraySize(args->pObjectInterface, (void *)args->mValue.IValue);
                  if ( v118 )
                  {
                    *(_DWORD *)use_premium_money = 0;
                    *(_DWORD *)faction_id = v118;
                    do
                    {
                      v120 = args->pObjectInterface;
                      v187.pObjectInterface = 0;
                      v152 = args->mValue.IValue;
                      v187.Type = VT_Undefined;
                      v186.pObjectInterface = 0;
                      v186.Type = VT_Undefined;
                      v120->GetElement(v120, (void *)v152, *(_DWORD *)use_premium_money, &v187);
                      survarium::flash_value::GetMember(v121, &v187, "id", (survarium::flash_value *)&v186);
                      v176[3] = v186.mValue.BValue;
                      survarium::flash_value::GetMember(v122, &v187, "value", (survarium::flash_value *)&v186);
                      v176[2] = v186.mValue.BValue;
                      v123 = *(vostok::configs::binary_config_value **)(*(_DWORD *)v177->m_effect_presenter.m_sound_presenter.m_new_effects.m_buffer[7].m_store
                                                                      + 264);
                      sprintf_s<16>((char (*)[16])&skills, "skill_%d", v176[3]);
                      v188 = vostok::configs::binary_config_value::operator[](v123, (char *)&skills);
                      if ( v176[2] )
                      {
                        count = 1;
                        message_id = v176[2];
                        do
                        {
                          sprintf_s<16>((char (*)[16])&value, "skill_level_%d", count);
                          v124 = vostok::configs::binary_config_value::operator[](v188, "levels");
                          v125 = vostok::configs::binary_config_value::operator[](v124, value.body);
                          *(_DWORD *)&__x[0].skill_id = vostok::configs::binary_config_value::operator[](
                                                          v125,
                                                          "boosters")->data.pointer;
                          v126 = vostok::configs::binary_config_value::operator[](v125, "boosters");
                          v127 = (int)v126->data.pointer + 24 * v126->count;
                          while ( *(_DWORD *)&__x[0].skill_id != v127 )
                          {
                            v189 = LOBYTE(vostok::configs::binary_config_value::operator[](
                                            *(vostok::configs::binary_config_value **)&__x[0].skill_id,
                                            "id")->data.max_storage)
                                 - 1;
                            v128 = vostok::configs::binary_config_value::operator[](
                                     *(vostok::configs::binary_config_value **)&__x[0].skill_id,
                                     "value");
                            if ( v128->type == 2 )
                              pointer = *(float *)&v128->data.pointer;
                            else
                              pointer = (float)(int)v128->data.pointer;
                            *(_DWORD *)&__x[0].skill_id += 24;
                            *((float *)&_Dst[0].m_network_client.m_on_disconnected.functor.obj_ptr + v189) = pointer + *((float *)&_Dst[0].m_network_client.m_on_disconnected.functor.obj_ptr + v189);
                          }
                          ++count;
                          --message_id;
                        }
                        while ( message_id );
                      }
                      Scaleform::GFx::Value::~Value(&v186);
                      Scaleform::GFx::Value::~Value(&v187);
                      ++*(_DWORD *)use_premium_money;
                      --*(_DWORD *)faction_id;
                    }
                    while ( *(_DWORD *)faction_id );
                  }
                  v130 = v177;
                  v185.pObjectInterface = 0;
                  v185.Type = VT_Undefined;
                  survarium::lobby_menu::create_player_params(
                    v119,
                    (survarium::flash_value *)&v177[-1].m_effect_presenter.m_sound_presenter.m_new_effects.m_buffer[7].m_store[8],
                    &v185,
                    (int)&_Dst[0].m_network_client.m_on_disconnected.functor);
                  Scaleform::GFx::Movie::Invoke(
                    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)v130->m_effect_presenter.m_sound_presenter.m_old_effects.m_buffer[14].m_store
                                                          + 264)
                                              + 4),
                    "root.apply_char_stats",
                    0,
                    &v185,
                    1u);
                  Scaleform::GFx::Value::~Value(&v185);
                  `vector destructor iterator'(
                    &_Dst[0].m_local_name[16],
                    0x30u,
                    20,
                    (void (__thiscall *)(void *))vostok::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::~intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>);
                }
              }
              else
              {
                v114 = args->mValue.IValue;
                faction_id[0] = args[1].mValue.BValue;
                LOBYTE(v113) = faction_id[0];
                v169 = faction_id[0];
                v157 = v114;
                v115 = survarium::lobby_menu::lobby_client(
                         v113,
                         (int)&v177[-1].m_effect_presenter.m_sound_presenter.m_new_effects.m_buffer[7].m_store[8]);
                survarium::lobby_client::query_elo_players(
                  v116,
                  (const vostok::network_core::tcp_packet *)v115,
                  v157,
                  v169);
              }
            }
            else
            {
              faction_id[0] = args->mValue.BValue;
              v107 = v177->m_effect_presenter.m_sound_presenter.m_old_effects.m_buffer[14].m_store[4];
              v108 = (int)&v177[-1].m_effect_presenter.m_sound_presenter.m_new_effects.m_buffer[7].m_store[8];
              v109 = survarium::lobby_menu::lobby_client(
                       v106,
                       (int)&v177[-1].m_effect_presenter.m_sound_presenter.m_new_effects.m_buffer[7].m_store[8]);
              v168 = *(_DWORD *)faction_id;
              v110 = (survarium::lobby_menu *)(1512 * v107);
              v156 = *(unsigned int *)((char *)&v109->m_profiles[0].profile_id + (_DWORD)v110);
              v111 = survarium::lobby_menu::lobby_client(v110, v108);
              survarium::lobby_client::set_autobuy_for_profile(
                v112,
                (const vostok::network_core::tcp_packet *)v111,
                v156,
                v168);
            }
          }
          else
          {
            v103 = survarium::flash_value::GetString(v102, (int)args);
            strcpy_s((char *)_Dst, 0x40u, v103);
            v104 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(LODWORD(v177[-1].m_player_total_items_weight) + 13912)
                                                 + 68))(*(_DWORD *)(LODWORD(v177[-1].m_player_total_items_weight) + 13912));
            survarium::messaging_client::add_to_ignore_list_by_name(v105, v104, (const char (*)[64])_Dst);
          }
        }
        else
        {
          v100 = survarium::flash_value::GetString(v99, (int)args);
          strcpy_s((char *)_Dst, 0x40u, v100);
          v101 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(LODWORD(v177[-1].m_player_total_items_weight) + 13912)
                                               + 68))(*(_DWORD *)(LODWORD(v177[-1].m_player_total_items_weight) + 13912));
          if ( *(_DWORD *)(v101 + 136) == 3 )
            survarium::messaging_client::send_important_message(
              _Dst,
              (const char (*)[64])v101,
              (int)_Dst,
              0,
              (char *)uri);
        }
      }
      else
      {
        survarium::game::exit((survarium::game *)LODWORD(v177[-1].m_player_total_items_weight), "quit");
      }
    }
    else
    {
      survarium::chat_handler::close_conversation(
        *(survarium::chat_handler **)(LODWORD(v177[-1].m_player_total_items_weight) + 13848),
        args->mValue.UIValue);
    }
  }
}
