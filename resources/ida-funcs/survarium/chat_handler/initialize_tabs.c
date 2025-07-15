void __thiscall survarium::chat_handler::initialize_tabs(
        survarium::chat_handler *this,
        const vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *ui,
        vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *is_game_mode,
        char a4)
{
  survarium::chat_tab *v4; // eax
  survarium::chat_handler *v5; // ecx
  survarium::chat_tab *v6; // edi
  int v7; // esi
  char v8[516]; // [esp+8h] [ebp-224h] BYREF
  _DWORD v9[2]; // [esp+20Ch] [ebp-20h] BYREF
  char v10; // [esp+214h] [ebp-18h]
  unsigned int *v11; // [esp+218h] [ebp-14h]
  int v12; // [esp+21Ch] [ebp-10h]
  int v13; // [esp+220h] [ebp-Ch]
  char v14; // [esp+224h] [ebp-8h]

  survarium::text_translator::translate_text(
    (survarium::text_translator *)this,
    (int)&ui[4].m_object[51].m_parent_resources.gapC,
    "st_chat_channel_general",
    v8);
  v9[0] = v8;
  v4 = 0;
  LOBYTE(v5) = 0;
  v9[1] = 0;
  v10 = 0;
  v11 = survarium::lobby_tab_chanels;
  v12 = 3;
  v13 = 1;
  v14 = 1;
  if ( !a4 )
  {
    v4 = (survarium::chat_tab *)v9;
    LOBYTE(v5) = 1;
  }
  if ( (_BYTE)v5 )
  {
    v6 = v4;
    v7 = (unsigned __int8)v5;
    do
    {
      survarium::chat_handler::add_new_tab(v5, is_game_mode, v6++);
      --v7;
    }
    while ( v7 );
  }
}
