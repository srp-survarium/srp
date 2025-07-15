void __thiscall survarium::options_resolution_selector::fill_resolutions(
        survarium::options_resolution_selector *this,
        int monitor_number,
        unsigned __int8 a3)
{
  int v3; // eax
  char *v4; // eax
  int v5; // eax
  vostok::math::int2 *v6; // esi
  survarium::options_resolution_selector *x; // eax
  _DWORD *v8; // eax
  vostok::math::int2 *v9; // esi
  vostok::buffer_string *v10; // ecx
  _DWORD *v11; // eax
  const char **v12; // eax
  unsigned int v13; // edi
  const char **v14; // esi
  int v15; // edi
  survarium::flash_value *v16; // ecx
  survarium::flash_value *v17; // ecx
  int v18; // edx
  survarium::flash_value *v19; // ecx
  survarium::flash_value *v20; // ecx
  survarium::flash_value *v21; // ecx
  Scaleform::GFx::Value *v22; // esi
  survarium::options_resolution_selector *v23; // [esp-8h] [ebp-D0h]
  int y; // [esp-4h] [ebp-CCh]
  const char *v25; // [esp+0h] [ebp-C8h]
  const char *v26; // [esp+4h] [ebp-C4h]
  unsigned int v27; // [esp+8h] [ebp-C0h]
  _DWORD *v28; // [esp+Ch] [ebp-BCh]
  _DWORD *v29; // [esp+Ch] [ebp-BCh]
  const char **v30; // [esp+Ch] [ebp-BCh]
  unsigned int count; // [esp+10h] [ebp-B8h]
  int v32; // [esp+14h] [ebp-B4h]
  int v33; // [esp+18h] [ebp-B0h]
  int v34; // [esp+1Ch] [ebp-ACh]
  int v35; // [esp+1Ch] [ebp-ACh]
  __int64 v36; // [esp+20h] [ebp-A8h]
  __int64 v37; // [esp+20h] [ebp-A8h]
  __int64 v38; // [esp+28h] [ebp-A0h]
  __int64 v39; // [esp+28h] [ebp-A0h]
  int v40; // [esp+34h] [ebp-94h]
  vostok::buffer_string left; // [esp+3Ch] [ebp-8Ch] BYREF
  _BYTE v42[32]; // [esp+48h] [ebp-80h] BYREF
  survarium::flash_value v43; // [esp+68h] [ebp-60h] BYREF
  char v44[24]; // [esp+80h] [ebp-48h] BYREF
  char v45[24]; // [esp+98h] [ebp-30h] BYREF
  char v46[24]; // [esp+B0h] [ebp-18h] BYREF
  char vars0; // [esp+C8h] [ebp+0h] BYREF

  v40 = -1;
  left.m_begin = v42;
  left.m_end = v42;
  left.m_max_end = (char *)&v43;
  v3 = *(_DWORD *)(monitor_number + 24);
  v42[0] = 0;
  if ( v3 )
  {
    v4 = *(char **)(v3 + 4 * *(unsigned __int8 *)(monitor_number + 29));
    this = (survarium::options_resolution_selector *)v42;
    if ( v42 != v4 )
    {
      left.m_end = v42;
      v42[0] = 0;
      vostok::buffer_string::operator+=(&left, v4);
    }
    v5 = *(_DWORD *)(monitor_number + 24);
    if ( v5 )
      vostok::memory::doug_lea_allocator::free_impl(
        (vostok::memory::doug_lea_allocator *)this,
        (int)survarium::g_allocator,
        (char *)(v5 - 8),
        v25,
        v26,
        v27);
  }
  count = 0;
  v6 = vostok::render::g_monitor_resolutions[a3];
  v28 = (_DWORD *)(monitor_number + 32);
  v34 = 512;
  do
  {
    if ( v6->x
      && v6->y
      && (vostok::command_line::key::is_set((vostok::command_line::key *)this, (int)&s_all_resolutions)
       || v6->y >= 720 && v6->x >= 1280) )
    {
      if ( vostok::command_line::key::is_set((vostok::command_line::key *)this, (int)&s_all_resolutions)
        || !count
        || !vostok::platform::is_address_space_or_ram_under_2_gb() )
      {
        y = v6->y;
        x = (survarium::options_resolution_selector *)v6->x;
        v23 = (survarium::options_resolution_selector *)v6->x;
        goto LABEL_20;
      }
      this = (survarium::options_resolution_selector *)v6->x;
      v36 = v32 * (__int64)v33;
      v38 = v6->x * (__int64)v6->y;
      if ( v36 > v38 || v36 == v38 && v32 < (int)this )
      {
        y = v6->y;
        x = (survarium::options_resolution_selector *)v6->x;
        v23 = (survarium::options_resolution_selector *)v6->x;
LABEL_20:
        v32 = (int)x;
        v33 = v6->y;
        v8 = v28;
        v28 += 11;
        ++count;
        vostok::fs_new::path_string_impl::assignf(
          v8,
          (vostok::buffer_string *)this,
          (vostok::buffer_string *)"%dx%d",
          (const char *)v23,
          y);
      }
    }
    ++v6;
    --v34;
  }
  while ( v34 );
  if ( !count )
  {
    v9 = vostok::render::g_monitor_resolutions[a3];
    v29 = (_DWORD *)(monitor_number + 32);
    v35 = 512;
    do
    {
      if ( vostok::command_line::key::is_set((vostok::command_line::key *)this, (int)&s_all_resolutions) || !count )
      {
        ++count;
        v32 = v9->x;
        v33 = v9->y;
        v11 = v29;
        v29 += 11;
        vostok::fs_new::path_string_impl::assignf(v11, v10, (vostok::buffer_string *)"%dx%d", (const char *)v9->x, v33);
      }
      else
      {
        this = (survarium::options_resolution_selector *)v9->x;
        v37 = v32 * (__int64)v33;
        v39 = v9->y * (__int64)v9->x;
        if ( v37 < v39 || v37 == v39 && v32 < (int)this )
        {
          v32 = v9->x;
          v33 = v9->y;
          vostok::fs_new::path_string_impl::assignf(
            v29,
            (vostok::buffer_string *)this,
            (vostok::buffer_string *)"%dx%d",
            (const char *)this,
            v33);
        }
      }
      ++v9;
      --v35;
    }
    while ( v35 );
  }
  v12 = vostok::memory::new_array_helper<char const *>::call<vostok::memory::doug_lea_allocator>(
          survarium::g_allocator,
          count,
          v25,
          v26,
          v27);
  v13 = 0;
  *(_DWORD *)(monitor_number + 24) = v12;
  *(_BYTE *)(monitor_number + 28) = count;
  if ( count )
  {
    v14 = v12;
    v30 = (const char **)(monitor_number + 32);
    do
    {
      v14[v13] = *v30;
      v14 = *(const char ***)(monitor_number + 24);
      if ( !vostok::strings::compare(left.m_begin, v14[v13]) )
        v40 = v13;
      v30 += 11;
      ++v13;
    }
    while ( v13 < count );
  }
  if ( vostok::strings::compare(left.m_begin, uri) )
  {
    if ( v40 == -1 )
    {
      v15 = 3;
      *(_BYTE *)(monitor_number + 29) = *(_BYTE *)(monitor_number + 28) - 1;
      v16 = &v43;
      do
      {
        survarium::flash_value::flash_value(v16);
        v16 = v17 + 1;
      }
      while ( v18 - 1 >= 0 );
      survarium::flash_value::SetUInt(v16, (int)&v43, 2u);
      survarium::flash_value::SetUInt(v19, (int)v44, 1u);
      survarium::flash_value::SetUInt(v20, (int)v45, *(unsigned __int8 *)(monitor_number + 29));
      survarium::flash_value::SetUInt(v21, (int)v46, 0);
      Scaleform::GFx::Movie::Invoke(
        *(Scaleform::GFx::Movie **)(*(_DWORD *)(**(_DWORD **)(*(_DWORD *)(monitor_number + 16) + 16) + 264) + 4),
        "root.set_value",
        0,
        (const Scaleform::GFx::Value *)&v43,
        4u);
      v22 = (Scaleform::GFx::Value *)&vars0;
      do
      {
        Scaleform::GFx::Value::~Value(--v22);
        --v15;
      }
      while ( v15 >= 0 );
    }
    else
    {
      *(_BYTE *)(monitor_number + 29) = v40;
    }
  }
}
