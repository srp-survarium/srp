void __thiscall survarium::chat_handler::add_message(
        survarium::chat_handler *this,
        survarium::chat_handler *channel,
        survarium::flash_value *w_text,
        const wchar_t *w_sender_name,
        wchar_t *w_sender_namea)
{
  survarium::flash_movie_resource *m_object; // ecx
  Scaleform::GFx::Movie *m_movie; // ecx
  const char *v7; // edi
  survarium::flash_value *p_obj; // esi
  survarium::network_client *p_net_client; // esi
  survarium::network_client *v10; // ecx
  vostok::memory::detail::call_destructor_predicate *local_player; // eax
  int v12; // eax
  char v13; // [esp+4Fh] [ebp-861h]
  survarium::flash_value obj; // [esp+50h] [ebp-860h] BYREF
  survarium::game_team_id sender_team; // [esp+68h] [ebp-848h] BYREF
  survarium::network_client *net_client; // [esp+6Ch] [ebp-844h] BYREF
  survarium::flash_value ret_args; // [esp+70h] [ebp-840h] BYREF
  int v18; // [esp+88h] [ebp-828h]
  char sender_name[32]; // [esp+8Ch] [ebp-824h] BYREF
  wchar_t text_to_send[512]; // [esp+ACh] [ebp-804h] BYREF
  wchar_t to_all_localized[514]; // [esp+4ACh] [ebp-404h] BYREF

  m_object = channel->m_chat_ui.m_object;
  *(_DWORD *)ret_args.body = 0;
  *(_DWORD *)&ret_args.body[4] = 0;
  m_movie = m_object->movie->m_movie;
  v18 = 0;
  Scaleform::GFx::Movie::CreateObject(m_movie, (Scaleform::GFx::Value *)&ret_args, 0, 0, 0);
  *(_DWORD *)obj.body = 0;
  *(_DWORD *)&obj.body[4] = 0;
  survarium::flash_value::SetStringW(&obj, w_sender_namea);
  (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)ret_args.body + 20))(
    *(_DWORD *)ret_args.body,
    *(_DWORD *)&ret_args.body[8],
    "name",
    &obj,
    (ret_args.body[4] & 0x8F) == 10);
  v7 = "(12:12:12)";
  survarium::flash_value::SetString(&obj, "(12:12:12)");
  (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)ret_args.body + 20))(
    *(_DWORD *)ret_args.body,
    *(_DWORD *)&ret_args.body[8],
    "time",
    &obj,
    (ret_args.body[4] & 0x8F) == 10);
  if ( (obj.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)obj.body + 8))(
      *(_DWORD *)obj.body,
      &obj,
      *(_DWORD *)&obj.body[8]);
    *(_DWORD *)obj.body = 0;
  }
  p_obj = w_text;
  *(_DWORD *)&obj.body[4] = 4;
  *(_DWORD *)&obj.body[8] = w_text;
  (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)ret_args.body + 20))(
    *(_DWORD *)ret_args.body,
    *(_DWORD *)&ret_args.body[8],
    "type",
    &obj,
    (ret_args.body[4] & 0x8F) == 10);
  if ( !channel->m_game_ui_mode || w_text != (survarium::flash_value *)5 )
    goto LABEL_12;
  net_client = (survarium::network_client *)channel->m_game->m_network_client;
  p_net_client = net_client;
  sender_team = team_1;
  wcstombs_s((unsigned int *)&sender_team, sender_name, 0x20u, w_sender_namea, 0xFFFFFFFF);
  sender_team = survarium::network_client::get_player_team(p_net_client, sender_name);
  if ( sender_team == team_undefined
    || (p_net_client = (survarium::network_client *)&net_client,
        v18 = 1,
        local_player = survarium::network_client::get_local_player(
                         v10,
                         (int)net_client,
                         (vostok::memory::detail::call_destructor_predicate *)&net_client),
        v12 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)local_player + 72))(*(_DWORD *)local_player),
        v13 = 1,
        v12 == sender_team) )
  {
    v13 = 0;
  }
  if ( (v18 & 1) != 0 )
    vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> *)&net_client);
  if ( v13 )
  {
    v7 = "Red";
    p_obj = &obj;
    survarium::flash_value::SetString(&obj, "Red");
    survarium::flash_value::SetMember(&obj, &ret_args, (const char *)&stru_9555EC, &obj);
LABEL_12:
    swprintf_0(0x200u, (unsigned int)v7, (unsigned int)p_obj, text_to_send, L"%s", w_sender_name);
    goto LABEL_13;
  }
  survarium::text_translator::translate_text(&channel->m_game->m_text_translator, "st_to_all", to_all_localized);
  swprintf_0(
    0x200u,
    (unsigned int)"st_to_all",
    (unsigned int)p_net_client,
    text_to_send,
    L"[%s] %s",
    to_all_localized,
    w_sender_name);
LABEL_13:
  survarium::flash_value::SetStringW(&obj, text_to_send);
  (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)ret_args.body + 20))(
    *(_DWORD *)ret_args.body,
    *(_DWORD *)&ret_args.body[8],
    "text",
    &obj,
    (ret_args.body[4] & 0x8F) == 10);
  Scaleform::GFx::Movie::Invoke(
    channel->m_chat_ui.m_object->movie->m_movie,
    "root.add_chat_message",
    0,
    (const Scaleform::GFx::Value *)&ret_args,
    1u);
  if ( (obj.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)obj.body + 8))(
      *(_DWORD *)obj.body,
      &obj,
      *(_DWORD *)&obj.body[8]);
    *(_DWORD *)obj.body = 0;
  }
  *(_DWORD *)&obj.body[4] = 0;
  if ( (ret_args.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)ret_args.body + 8))(
      *(_DWORD *)ret_args.body,
      &ret_args,
      *(_DWORD *)&ret_args.body[8]);
}
