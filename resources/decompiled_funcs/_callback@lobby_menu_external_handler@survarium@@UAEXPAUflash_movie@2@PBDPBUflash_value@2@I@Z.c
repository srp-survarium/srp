void __thiscall survarium::lobby_menu_external_handler::callback(
        survarium::lobby_menu_external_handler *this,
        survarium::flash_movie *pmovieView,
        const char *methodName,
        const survarium::flash_value *args,
        unsigned int argCount)
{
  survarium::lobby_client *v6; // ecx
  survarium::game *m_game; // eax
  unsigned __int8 m_selected_profile; // bl
  survarium::lobby_client *v9; // eax
  unsigned int v10; // edi
  char v11; // al
  unsigned __int8 i; // bl
  int v13; // eax
  unsigned __int16 v14; // dx
  _DWORD *v15; // ecx
  unsigned __int8 v16; // al
  unsigned __int16 v17; // ax
  survarium::lobby_client *v18; // ecx
  int (__thiscall *v19)(_DWORD, _DWORD); // edx
  survarium::player_skill *M_finish; // edi
  survarium::flash_value *v21; // ecx
  unsigned int v22; // esi
  char v23; // bl
  survarium::flash_value *v24; // ecx
  stlp_std::priv::_Impl_vector<survarium::player_skill,vostok::vectora_allocator<survarium::player_skill> > *v25; // ecx
  int f; // ebx
  int (__thiscall *v27)(_DWORD, _DWORD); // edx
  unsigned __int8 *v28; // edi
  int v29; // esi
  survarium::lobby_client *v30; // eax
  survarium::lobby_client *v31; // ecx
  survarium::flash_value *v32; // ecx
  const char *String; // esi
  survarium::messaging_client *v34; // eax
  survarium::messaging_client *v35; // ecx
  survarium::messaging_client *v36; // ecx
  survarium::messaging_client *v37; // ecx
  survarium::messaging_client *v38; // ecx
  survarium::flash_value *v39; // ecx
  const char *v40; // eax
  survarium::game *v41; // ecx
  unsigned int v42; // [esp+Ah] [ebp-ACh]
  unsigned int v43; // [esp+Ah] [ebp-ACh]
  unsigned int v44; // [esp+Ah] [ebp-ACh]
  unsigned int v45; // [esp+Ah] [ebp-ACh]
  const stlp_std::__true_type *v46; // [esp+Eh] [ebp-A8h]
  unsigned int v47; // [esp+12h] [ebp-A4h]
  bool v48; // [esp+16h] [ebp-A0h]
  unsigned __int8 v49; // [esp+21h] [ebp-95h]
  unsigned __int8 v50; // [esp+21h] [ebp-95h]
  int perk; // [esp+22h] [ebp-94h] BYREF
  survarium::lobby_menu_external_handler *v52; // [esp+26h] [ebp-90h]
  survarium::flash_value branch_value; // [esp+2Ah] [ebp-8Ch] BYREF
  vostok::vectora<survarium::player_skill> skills; // [esp+42h] [ebp-74h] BYREF
  survarium::flash_value perks_array; // [esp+52h] [ebp-64h] BYREF
  survarium::flash_value skills_array; // [esp+6Ah] [ebp-4Ch] BYREF
  unsigned int items_count; // [esp+82h] [ebp-34h]
  survarium::flash_value ret_args[2]; // [esp+86h] [ebp-30h] BYREF

  v52 = this;
  if ( !strcmp(methodName, "leave_queue") )
  {
    this->m_game->m_network_client->lobby_client(this->m_game->m_network_client);
    survarium::lobby_client::discard_playing_order(v6);
  }
  else if ( !strcmp(methodName, "play_button_clicked") )
  {
    if ( this->m_game->m_network_client->lobby_client(this->m_game->m_network_client)->m_profiles_count )
    {
      m_game = this->m_game;
      m_selected_profile = m_game->m_lobby_menu->m_selected_profile;
      m_game->m_network_client->lobby_client(m_game->m_network_client);
      v9 = this->m_game->m_network_client->lobby_client(this->m_game->m_network_client);
      survarium::lobby_client::set_status_ready_for_match(
        (survarium::lobby_client *)(440 * m_selected_profile),
        (const unsigned int)v9);
    }
  }
  else if ( !strcmp(methodName, "profile_changed") )
  {
    survarium::lobby_menu::on_profile_changed(
      (survarium::lobby_menu *)(unsigned __int8)args->body[8],
      (unsigned __int8)this->m_game->m_lobby_menu);
  }
  else if ( vostok::strings::equal(methodName, "shop_ready") )
  {
    survarium::lobby_menu::on_shop_ui_ready((survarium::lobby_menu *)this->m_game);
  }
  else if ( vostok::strings::equal(methodName, "set_mouse_cursor") )
  {
    survarium::lobby_menu::set_cursor(this->m_game->m_lobby_menu, args->body[8]);
  }
  else if ( vostok::strings::equal(methodName, "buy_ok_clicked") )
  {
    v10 = *(unsigned __int16 *)&args->body[8];
    v11 = args[2].body[8];
    items_count = *(unsigned __int16 *)&args[1].body[8];
    LOBYTE(perk) = v11;
    if ( !v11 )
    {
      for ( i = 1; i <= 4u; ++i )
      {
        v13 = (int)v52->m_game->m_network_client->lobby_client(v52->m_game->m_network_client);
        v14 = *(_WORD *)(v13 + 8 * i + 1964);
        v15 = (_DWORD *)(v13 + 8 * i + 1960);
        v16 = 0;
        if ( v14 )
        {
          while ( *(_WORD *)(*v15 + 6 * v16) != (_WORD)v10 )
          {
            if ( ++v16 >= v14 )
              goto LABEL_20;
          }
          LOBYTE(perk) = i;
          if ( i )
            break;
        }
LABEL_20:
        ;
      }
    }
    v17 = (unsigned __int16)v52->m_game->m_network_client->lobby_client(v52->m_game->m_network_client);
    survarium::lobby_client::buy_item(v18, v17, v10, items_count, perk);
  }
  else if ( vostok::strings::equal(methodName, "unlock_perks") )
  {
    skills_array = *args;
    *(_QWORD *)perks_array.body = *(_QWORD *)args[1].body;
    *(_QWORD *)&perks_array.body[8] = *(_QWORD *)&args[1].body[8];
    skills._M_impl._M_end_of_storage.m_allocator = (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_;
    *(_QWORD *)&perks_array.body[16] = *(_QWORD *)&args[1].body[16];
    v19 = *(int (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)skills_array.body + 40);
    M_finish = 0;
    skills._M_impl._M_start = 0;
    skills._M_impl._M_finish = 0;
    skills._M_impl._M_end_of_storage._M_data = 0;
    v49 = 0;
    if ( v19(*(_DWORD *)skills_array.body, *(_DWORD *)&skills_array.body[8]) )
    {
      v22 = 0;
      do
      {
        *(_DWORD *)branch_value.body = 0;
        *(_DWORD *)&branch_value.body[4] = 0;
        *(_DWORD *)ret_args[0].body = 0;
        *(_DWORD *)&ret_args[0].body[4] = 0;
        survarium::flash_value::GetElement(v21, v22, &branch_value);
        survarium::flash_value::GetMember(ret_args, "id", ret_args);
        v23 = ret_args[0].body[8];
        survarium::flash_value::GetMember(v24, "points", ret_args);
        LOBYTE(perk) = v23;
        BYTE1(perk) = ret_args[0].body[8];
        if ( M_finish == skills._M_impl._M_end_of_storage._M_data )
        {
          stlp_std::priv::_Impl_vector<survarium::player_skill,vostok::vectora_allocator<survarium::player_skill>>::_M_insert_overflow(
            v25,
            M_finish,
            (const survarium::player_skill *)&perk,
            v46,
            v47,
            v48);
          M_finish = skills._M_impl._M_finish;
        }
        else
        {
          *M_finish++ = (survarium::player_skill)perk;
          skills._M_impl._M_finish = M_finish;
        }
        survarium::flash_value::~flash_value(ret_args);
        survarium::flash_value::~flash_value(&branch_value);
        v22 = ++v49;
      }
      while ( v49 < (unsigned int)(*(int (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)skills_array.body + 40))(
                                    *(_DWORD *)skills_array.body,
                                    *(_DWORD *)&skills_array.body[8]) );
    }
    f = (int)survarium::g_allocator.f_.f_;
    v27 = *(int (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)perks_array.body + 40);
    v28 = 0;
    v29 = 0;
    *(_DWORD *)branch_value.body = 0;
    *(_DWORD *)&branch_value.body[4] = 0;
    *(_DWORD *)&branch_value.body[8] = survarium::g_allocator.f_.f_;
    *(_DWORD *)&branch_value.body[12] = 0;
    v50 = 0;
    if ( v27(*(_DWORD *)perks_array.body, *(_DWORD *)&perks_array.body[8]) )
    {
      do
      {
        *(_DWORD *)ret_args[0].body = 0;
        *(_DWORD *)&ret_args[0].body[4] = 0;
        (*(void (__thiscall **)(_DWORD, _DWORD, int, survarium::flash_value *))(**(_DWORD **)perks_array.body + 48))(
          *(_DWORD *)perks_array.body,
          *(_DWORD *)&perks_array.body[8],
          v29,
          ret_args);
        LOBYTE(perk) = ret_args[0].body[8];
        if ( v28 == *(unsigned __int8 **)&branch_value.body[12] )
        {
          stlp_std::priv::_Impl_vector<unsigned char,vostok::vectora_allocator<unsigned char>>::_M_insert_overflow(
            (stlp_std::priv::_Impl_vector<unsigned char,vostok::vectora_allocator<unsigned char> > *)&branch_value,
            v28,
            (const unsigned __int8 *)&perk,
            v46,
            v47,
            v48);
          v28 = *(unsigned __int8 **)&branch_value.body[4];
        }
        else
        {
          *v28++ = ret_args[0].body[8];
          *(_DWORD *)&branch_value.body[4] = v28;
        }
        if ( (ret_args[0].body[4] & 0x40) != 0 )
          (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)ret_args[0].body + 8))(
            *(_DWORD *)ret_args[0].body,
            ret_args,
            *(_DWORD *)&ret_args[0].body[8]);
        v29 = ++v50;
      }
      while ( v50 < (unsigned int)(*(int (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)perks_array.body + 40))(
                                    *(_DWORD *)perks_array.body,
                                    *(_DWORD *)&perks_array.body[8]) );
      f = *(_DWORD *)&branch_value.body[8];
      v29 = *(_DWORD *)branch_value.body;
    }
    v30 = v52->m_game->m_network_client->lobby_client(v52->m_game->m_network_client);
    survarium::lobby_client::set_player_skills(v30, &skills, (vostok::vectora<unsigned char> *)&branch_value);
    if ( v29 )
      (*(void (__thiscall **)(int, int))(*(_DWORD *)f + 24))(f, v29);
    if ( skills._M_impl._M_start )
      skills._M_impl._M_end_of_storage.m_allocator->call_free(
        skills._M_impl._M_end_of_storage.m_allocator,
        skills._M_impl._M_start);
    if ( (perks_array.body[4] & 0x40) != 0 )
    {
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)perks_array.body + 8))(
        *(_DWORD *)perks_array.body,
        &perks_array,
        *(_DWORD *)&perks_array.body[8]);
      *(_DWORD *)perks_array.body = 0;
    }
    *(_DWORD *)&perks_array.body[4] = 0;
    if ( (skills_array.body[4] & 0x40) != 0 )
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)skills_array.body + 8))(
        *(_DWORD *)skills_array.body,
        &skills_array,
        *(_DWORD *)&skills_array.body[8]);
  }
  else if ( vostok::strings::equal(methodName, "reroll_ok_clicked") )
  {
    this->m_game->m_network_client->lobby_client(this->m_game->m_network_client);
    survarium::lobby_client::reroll_player_skills(v31);
  }
  else if ( vostok::strings::equal(methodName, "find_players") )
  {
    String = survarium::flash_value::GetString(v32);
    if ( strlen(String) >= 3 )
    {
      v34 = this->m_game->m_network_client->messaging_client(this->m_game->m_network_client);
      survarium::messaging_client::find_players_by_name(v34, String);
    }
  }
  else if ( vostok::strings::equal(methodName, "add_friend") )
  {
    v42 = *(_DWORD *)&args->body[8];
    this->m_game->m_network_client->messaging_client(this->m_game->m_network_client);
    survarium::messaging_client::add_to_friend_list(v35, v42);
  }
  else if ( vostok::strings::equal(methodName, "remove_friend") )
  {
    v43 = *(_DWORD *)&args->body[8];
    this->m_game->m_network_client->messaging_client(this->m_game->m_network_client);
    survarium::messaging_client::remove_from_friend_list(v36, v43);
  }
  else if ( vostok::strings::equal(methodName, "add_ignore") )
  {
    v44 = *(_DWORD *)&args->body[8];
    this->m_game->m_network_client->messaging_client(this->m_game->m_network_client);
    survarium::messaging_client::add_to_ignore_list(v37, v44);
  }
  else if ( vostok::strings::equal(methodName, "remove_ignored") )
  {
    v45 = *(_DWORD *)&args->body[8];
    this->m_game->m_network_client->messaging_client(this->m_game->m_network_client);
    survarium::messaging_client::remove_from_ignore_list(v38, v45);
  }
  else if ( vostok::strings::equal(methodName, "start_friend_message") )
  {
    `vector constructor iterator'(
      ret_args[0].body,
      0x18u,
      2,
      (void *(__thiscall *)(void *))survarium::flash_value::flash_value);
    v40 = survarium::flash_value::GetString(v39);
    survarium::flash_value::SetString(ret_args, v40);
    survarium::flash_value::SetUInt(&ret_args[1], 0x64u);
    Scaleform::GFx::Movie::Invoke(
      v52->m_game->m_chat_handler->m_chat_ui.m_object->movie->m_movie,
      "root.start_message",
      0,
      (const Scaleform::GFx::Value *)ret_args,
      2u);
    survarium::chat_handler::focus((survarium::chat_handler *)v52->m_game, 1);
    `vector destructor iterator'(
      ret_args[0].body,
      0x18u,
      2,
      (void (__thiscall *)(void *))survarium::flash_value::~flash_value);
  }
  else if ( vostok::strings::equal(methodName, "show_settings") )
  {
    survarium::game::activate_main_menu(v41);
  }
}
