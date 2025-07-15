vostok::fixed_string<260> *__usercall vostok::render::make_shader_name@<eax>(
        vostok::buffer_string *config@<ecx>,
        int a2@<esi>,
        const char *shd_name,
        vostok::render::enum_shader_type type)
{
  vostok::buffer_string *v4; // ecx
  char *v6; // [esp-10h] [ebp-120h]
  char *m_end; // [esp-Ch] [ebp-11Ch]
  char *m_max_end; // [esp-8h] [ebp-118h]
  char *m_begin; // [esp-4h] [ebp-114h]
  _DWORD v10[3]; // [esp+0h] [ebp-110h] BYREF
  _BYTE v11[260]; // [esp+Ch] [ebp-104h] BYREF
  char vars0; // [esp+110h] [ebp+0h] BYREF

  *(_DWORD *)(a2 + 8) = a2 + 272;
  *(_DWORD *)a2 = a2 + 12;
  *(_DWORD *)(a2 + 4) = a2 + 12;
  *(_BYTE *)(a2 + 12) = 0;
  m_begin = config[1].m_begin;
  m_max_end = config->m_max_end;
  v10[0] = v11;
  m_end = config->m_end;
  v10[1] = v11;
  v6 = config->m_begin;
  v10[2] = &vars0;
  v11[0] = 0;
  vostok::fs_new::path_string_impl::assignf(
    v10,
    config,
    (vostok::buffer_string *)"%llu%llu",
    v6,
    m_end,
    m_max_end,
    m_begin);
  vostok::fs_new::path_string_impl::assignf(
    (_DWORD *)a2,
    v4,
    (vostok::buffer_string *)"%s_%s_%d",
    shd_name,
    v10[0],
    type);
  return (vostok::fixed_string<260> *)a2;
}
