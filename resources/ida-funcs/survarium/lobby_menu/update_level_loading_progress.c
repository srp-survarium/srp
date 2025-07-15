void __thiscall survarium::lobby_menu::update_level_loading_progress(
        survarium::lobby_menu *this,
        survarium::lobby_menu *thisa)
{
  volatile int m_initialized; // eax
  volatile unsigned int m_pending_queries_count; // eax
  volatile int v4; // ecx
  double m_level_loading_progress; // st7
  unsigned int v6; // edx
  volatile int v7; // eax
  float v8; // xmm0_4
  survarium::flash_movie_resource *m_object; // ecx
  char *m_begin; // [esp-8h] [ebp-C98h]
  unsigned int pConvertedChars; // [esp+14h] [ebp-C7Ch] BYREF
  unsigned int v12[2]; // [esp+18h] [ebp-C78h] BYREF
  survarium::flash_value progress; // [esp+20h] [ebp-C70h] BYREF
  survarium::flash_value text; // [esp+38h] [ebp-C58h] BYREF
  char buff[64]; // [esp+50h] [ebp-C40h] BYREF
  wchar_t w_text[512]; // [esp+90h] [ebp-C00h] BYREF
  wchar_t level_name[512]; // [esp+490h] [ebp-800h] BYREF
  wchar_t queries_count[512]; // [esp+890h] [ebp-400h] BYREF

  m_initialized = vostok::resources::g_resources_manager.m_initialized;
  if ( vostok::resources::g_resources_manager.m_initialized )
    m_initialized = vostok::resources::g_resources_manager.m_variable->m_pending_queries_count;
  vostok::sprintf<64>((char (*)[64])buff, "(%d)", m_initialized);
  if ( vostok::resources::g_resources_manager.m_initialized )
    m_pending_queries_count = vostok::resources::g_resources_manager.m_variable->m_pending_queries_count;
  else
    m_pending_queries_count = 0;
  if ( thisa->m_last_queries_count > m_pending_queries_count )
  {
    v4 = vostok::resources::g_resources_manager.m_initialized;
    if ( vostok::resources::g_resources_manager.m_initialized )
      v4 = vostok::resources::g_resources_manager.m_variable->m_pending_queries_count;
    m_level_loading_progress = thisa->m_level_loading_progress;
    v6 = thisa->m_last_queries_count - v4;
    v12[0] = thisa->m_last_queries_count;
    thisa->m_level_loading_progress = m_level_loading_progress
                                    + (double)v6 / (double)v12[0] * (1.0 - m_level_loading_progress);
  }
  v7 = vostok::resources::g_resources_manager.m_initialized;
  if ( vostok::resources::g_resources_manager.m_initialized )
    v7 = vostok::resources::g_resources_manager.m_variable->m_pending_queries_count;
  thisa->m_last_queries_count = v7;
  wcscpy(w_text, L"Загрузка уровня[");
  memset((int)&w_text[17], 0, 0x3DEu);
  m_begin = thisa->m_game->m_project_resource_name.m_begin;
  pConvertedChars = 0;
  mbstowcs_s(&pConvertedChars, level_name, 0x200u, m_begin, 0xFFFFFFFF);
  v12[0] = 0;
  mbstowcs_s(v12, queries_count, 0x200u, buff, 0xFFFFFFFF);
  wcscat_s((unsigned int)thisa, w_text, 0x400u, level_name);
  wcscat_s((unsigned int)thisa, w_text, 0x400u, L"]");
  wcscat_s((unsigned int)thisa, w_text, 0x400u, queries_count);
  *(_DWORD *)text.body = 0;
  *(_DWORD *)&text.body[4] = 0;
  survarium::flash_value::SetStringW(&text, w_text);
  Scaleform::GFx::Movie::Invoke(
    thisa->m_match_making_ui.m_object->movie->m_movie,
    "root.set_status",
    0,
    (const Scaleform::GFx::Value *)&text,
    1u);
  v8 = thisa->m_level_loading_progress;
  *(_DWORD *)progress.body = 0;
  if ( (float)(*(float *)&clear_value - v8) < 0.001 )
    v8 = *(float *)&clear_value;
  m_object = thisa->m_match_making_ui.m_object;
  pConvertedChars = LODWORD(v8);
  thisa->m_level_loading_progress = v8;
  *(_DWORD *)&progress.body[4] = 4;
  *(_QWORD *)v12 = (__int64)(v8 * 100.0);
  *(_DWORD *)&progress.body[8] = v12[0];
  Scaleform::GFx::Movie::Invoke(
    m_object->movie->m_movie,
    "root.set_percent",
    0,
    (const Scaleform::GFx::Value *)&progress,
    1u);
  if ( (progress.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)progress.body + 8))(
      *(_DWORD *)progress.body,
      &progress,
      *(_DWORD *)&progress.body[8]);
    *(_DWORD *)progress.body = 0;
  }
  *(_DWORD *)&progress.body[4] = 0;
  if ( (text.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)text.body + 8))(
      *(_DWORD *)text.body,
      &text,
      *(_DWORD *)&text.body[8]);
}
