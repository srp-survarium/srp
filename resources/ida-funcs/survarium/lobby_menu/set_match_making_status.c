void __userpurge survarium::lobby_menu::set_match_making_status(
        unsigned int current_time_sec@<eax>,
        survarium::text_translator *a2@<ecx>,
        survarium::lobby_menu *this,
        unsigned int order_place,
        unsigned int orders_total,
        unsigned int avg_wait_time)
{
  Scaleform::GFx::Value *v7; // ecx
  survarium::lobby_client *v8; // eax
  survarium::lobby_client *v9; // eax
  int v10; // esi
  survarium::lobby_client *v11; // eax
  survarium::flash_value *v12; // ecx
  survarium::flash_value *v13; // ecx
  int v14; // edx
  int v15; // edi
  survarium::flash_value *v16; // ecx
  Scaleform::GFx::Value *v17; // esi
  survarium::flash_value *v18; // ecx
  survarium::flash_value *v19; // ecx
  int v20; // edx
  survarium::flash_value *v21; // ecx
  int v22; // edi
  Scaleform::GFx::Value *v23; // esi
  char value[512]; // [esp+10h] [ebp-478h] BYREF
  char v25[512]; // [esp+210h] [ebp-278h] BYREF
  survarium::flash_value v26; // [esp+410h] [ebp-78h] BYREF
  _BYTE v27[24]; // [esp+428h] [ebp-60h] BYREF
  survarium::flash_value v28; // [esp+440h] [ebp-48h] BYREF
  survarium::flash_value v29; // [esp+458h] [ebp-30h] BYREF
  survarium::flash_value v30; // [esp+470h] [ebp-18h] BYREF

  if ( !this->m_match_making_match_found )
  {
    if ( !order_place )
    {
      *(_DWORD *)v29.body = 0;
      *(_DWORD *)&v29.body[4] = 0;
      survarium::text_translator::translate_text(a2, (int)&this->m_game->m_text_translator, "st_mm_match_found", value);
      survarium::flash_value::SetString(&v29, value);
      Scaleform::GFx::Movie::Invoke(
        this->m_lobby_menu_ui.m_object->movie->m_movie,
        "root.set_mm_sync_state",
        0,
        (const Scaleform::GFx::Value *)&v29,
        1u);
      this->m_match_making_match_found = 1;
      v7 = (Scaleform::GFx::Value *)&v29;
LABEL_24:
      Scaleform::GFx::Value::~Value(v7);
      return;
    }
    v8 = survarium::lobby_menu::lobby_client((survarium::lobby_menu *)a2, (int)this);
    if ( !(v8->m_squad_members.m_end - v8->m_squad_members.m_begin)
      || (v9 = survarium::lobby_menu::lobby_client((survarium::lobby_menu *)0x50, (int)this),
          v10 = v9->m_squad_members.m_end - v9->m_squad_members.m_begin,
          v11 = survarium::lobby_menu::lobby_client((survarium::lobby_menu *)0x50, (int)this),
          v10 == survarium::lobby_client::squad_ready_count(v11)) )
    {
      *(_DWORD *)v30.body = 0;
      *(_DWORD *)&v30.body[4] = 0;
      if ( current_time_sec >= 0xE10 )
      {
        if ( current_time_sec < (unsigned int) __thiscall vostok::sound::world::`vcall'{12,{flat}} )
          vostok::sprintf<512>(
            (char (*)[512])v25,
            "%02d:%02d:%02d",
            current_time_sec / 0xE10,
            current_time_sec % 0xE10 / 0x3C,
            current_time_sec % 0x3C);
      }
      else
      {
        vostok::sprintf<512>((char (*)[512])v25, "%02d:%02d", current_time_sec / 0x3C, current_time_sec % 0x3C);
      }
      survarium::flash_value::SetString(&v30, v25);
      Scaleform::GFx::Movie::Invoke(
        this->m_lobby_menu_ui.m_object->movie->m_movie,
        "root.set_mm_current_time",
        0,
        (const Scaleform::GFx::Value *)&v30,
        1u);
      v18 = &v26;
      do
      {
        survarium::flash_value::flash_value(v18);
        v18 = v19 + 1;
      }
      while ( v20 - 1 >= 0 );
      survarium::flash_value::SetUInt(v18, (int)&v26, order_place);
      survarium::flash_value::SetUInt(v21, (int)v27, orders_total);
      Scaleform::GFx::Movie::Invoke(
        this->m_lobby_menu_ui.m_object->movie->m_movie,
        "root.set_mm_place",
        0,
        (const Scaleform::GFx::Value *)&v26,
        2u);
      if ( avg_wait_time >= 0xE10 )
      {
        if ( avg_wait_time < (unsigned int) __thiscall vostok::sound::world::`vcall'{12,{flat}} )
          vostok::sprintf<512>(
            (char (*)[512])v25,
            "%02d:%02d:%02d",
            avg_wait_time / 0xE10,
            avg_wait_time % 0xE10 / 0x3C,
            avg_wait_time % 0x3C);
      }
      else
      {
        vostok::sprintf<512>((char (*)[512])v25, "%02d:%02d", avg_wait_time / 0x3C, avg_wait_time % 0x3C);
      }
      survarium::flash_value::SetString(&v30, v25);
      v22 = 1;
      Scaleform::GFx::Movie::Invoke(
        this->m_lobby_menu_ui.m_object->movie->m_movie,
        "root.set_mm_average_time",
        0,
        (const Scaleform::GFx::Value *)&v30,
        1u);
      v23 = (Scaleform::GFx::Value *)&v28;
      do
      {
        Scaleform::GFx::Value::~Value(--v23);
        --v22;
      }
      while ( v22 >= 0 );
      v7 = (Scaleform::GFx::Value *)&v30;
      goto LABEL_24;
    }
    v12 = &v28;
    do
    {
      survarium::flash_value::flash_value(v12);
      v12 = v13 + 1;
    }
    while ( v14 - 1 >= 0 );
    survarium::text_translator::translate_text(
      (survarium::text_translator *)v12,
      (int)&this->m_game->m_text_translator,
      "st_squad_not_ready",
      value);
    survarium::flash_value::SetString(&v28, value);
    v15 = 1;
    survarium::flash_value::SetUInt(v16, (int)&v29, 1u);
    Scaleform::GFx::Movie::Invoke(
      this->m_lobby_menu_ui.m_object->movie->m_movie,
      "root.set_mm_sync_state",
      0,
      (const Scaleform::GFx::Value *)&v28,
      2u);
    v17 = (Scaleform::GFx::Value *)&v30;
    do
    {
      Scaleform::GFx::Value::~Value(--v17);
      --v15;
    }
    while ( v15 >= 0 );
  }
}
