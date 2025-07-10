void __userpurge vostok::render::renderer_context_targets::create_targets(
        vostok::render::renderer_context_targets *this@<ecx>,
        int a2@<eax>,
        vostok::math::uint2 size,
        vostok::render::renderer_context_targets *force_resize)
{
  const vostok::render::res_texture **v5; // ebx
  int v6; // ebp
  const char *v7; // eax
  bool v8; // zf
  const vostok::render::res_texture *v9; // esi
  unsigned int v10; // ecx
  unsigned int v11; // ebx
  unsigned int v12; // esi
  unsigned int v13; // ebp
  void (__cdecl *v14)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // ebx
  char v15; // bl
  void (__cdecl *v16)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  int v17; // eax
  vostok::render::backend *v18; // ecx
  const char *m_conflicted_key_name; // eax
  int v20; // eax
  vostok::render::backend *v21; // ecx
  const char *v22; // eax
  int v23; // eax
  vostok::render::backend *v24; // ecx
  const char *v25; // eax
  vostok::render::backend *v26; // ecx
  int v27; // edi
  int v28; // edi
  const char *v29; // eax
  vostok::math::uint2 _FFFFFFFC; // [esp-4h] [ebp-A0h]
  vostok::math::uint2 _FFFFFFFCa; // [esp-4h] [ebp-A0h]
  vostok::math::uint2 _FFFFFFFCb; // [esp-4h] [ebp-A0h]
  vostok::math::uint2 _FFFFFFFCc; // [esp-4h] [ebp-A0h]
  vostok::math::uint2 b_4; // [esp+8h] [ebp-94h]
  vostok::math::uint2 b_4a; // [esp+8h] [ebp-94h]
  float v36; // [esp+Ch] [ebp-90h]
  float v37; // [esp+Ch] [ebp-90h]
  float v38; // [esp+Ch] [ebp-90h]
  float v39; // [esp+Ch] [ebp-90h]
  unsigned int v40; // [esp+1Ch] [ebp-80h]
  unsigned int v41; // [esp+20h] [ebp-7Ch]
  unsigned int v42; // [esp+24h] [ebp-78h]
  unsigned int v43; // [esp+28h] [ebp-74h]
  unsigned int v44; // [esp+2Ch] [ebp-70h]
  unsigned int v45; // [esp+30h] [ebp-6Ch]
  unsigned int v46; // [esp+34h] [ebp-68h]
  unsigned int size_d16; // [esp+3Ch] [ebp-60h]
  unsigned int size_d4; // [esp+44h] [ebp-58h]
  unsigned int size_blur_1x; // [esp+4Ch] [ebp-50h]
  unsigned int size_blur_2x; // [esp+54h] [ebp-48h]
  unsigned int size_blur_4x; // [esp+5Ch] [ebp-40h]
  unsigned int size_blur_8x; // [esp+64h] [ebp-38h]
  unsigned int size_blur_16x; // [esp+6Ch] [ebp-30h]
  unsigned int size_blur_32x; // [esp+74h] [ebp-28h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+7Ch] [ebp-20h] BYREF

  if ( LOBYTE(size.x)
    || *(_DWORD *)(a2 + 11200) != size.y
    || (this = *(vostok::render::renderer_context_targets **)(a2 + 11204), this != force_resize) )
  {
    v5 = (const vostok::render::res_texture **)(a2 + 156);
    v6 = 70;
    do
    {
      v7 = (const char *)*(v5 - 1);
      *(v5 - 1) = 0;
      if ( v7 )
      {
        v8 = (*(_DWORD *)v7)-- == 1;
        if ( v8 )
          vostok::render::resource_manager::release(
            (vostok::render::resource_manager *)this,
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            v7);
      }
      v9 = *v5;
      *v5 = 0;
      if ( v9 )
      {
        v8 = v9->m_reference_count-- == 1;
        if ( v8 )
          vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)this, v9);
      }
      v5 += 40;
      --v6;
    }
    while ( v6 );
    v10 = vostok::render::renderer_context_targets::s_new_id;
    *(_QWORD *)(a2 + 11200) = __PAIR64__((unsigned int)force_resize, size.y);
    *(_DWORD *)(a2 + 11208) = v10;
    vostok::render::renderer_context_targets::s_new_id = v10 + 1;
    v11 = vostok::math::max(1u, (unsigned int)force_resize >> 2);
    size_blur_1x = vostok::math::max(1u, size.y >> 2);
    v42 = vostok::math::max(1u, (unsigned int)force_resize >> 3);
    size_blur_2x = vostok::math::max(1u, size.y >> 3);
    v43 = vostok::math::max(1u, (unsigned int)force_resize >> 4);
    size_blur_4x = vostok::math::max(1u, size.y >> 4);
    v44 = vostok::math::max(1u, (unsigned int)force_resize >> 5);
    size_blur_8x = vostok::math::max(1u, size.y >> 5);
    v45 = vostok::math::max(1u, (unsigned int)force_resize >> 6);
    size_blur_16x = vostok::math::max(1u, size.y >> 6);
    v46 = vostok::math::max(1u, (unsigned int)force_resize >> 7);
    size_blur_32x = vostok::math::max(1u, size.y >> 7);
    v12 = vostok::math::max(1u, (unsigned int)force_resize >> 1);
    v13 = vostok::math::max(1u, size.y >> 1);
    v40 = vostok::math::max(1u, (unsigned int)force_resize >> 2);
    size_d4 = vostok::math::max(1u, size.y >> 2);
    vostok::math::max(1u, (unsigned int)force_resize >> 3);
    vostok::math::max(1u, size.y >> 3);
    v41 = vostok::math::max(1u, (unsigned int)force_resize >> 4);
    size_d16 = vostok::math::max(1u, size.y >> 4);
    *(_DWORD *)(a2 + 11212) = 0;
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x2F,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0x1A,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__((unsigned int)force_resize, size.y));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x30,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0x1A,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__((unsigned int)force_resize, size.y));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x2D,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0x1C,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__((unsigned int)force_resize, size.y));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x2E,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0x1C,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__((unsigned int)force_resize, size.y));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x1A,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0x18,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__((unsigned int)force_resize, size.y));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x1C,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0x18,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__((unsigned int)force_resize, size.y));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0xC,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0x1C,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__((unsigned int)force_resize, size.y));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x37,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0x2C,
      (const vostok::math::uint2)0x100000000LL,
      (vostok::math::uint2)__PAIR64__((unsigned int)force_resize, size.y));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)8,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0x22,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__((unsigned int)force_resize, size.y));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0xA,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0x18,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__((unsigned int)force_resize, size.y));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x1B,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0x18,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__((unsigned int)force_resize, size.y));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0xB,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0x18,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__((unsigned int)force_resize, size.y));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0xE,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0x22,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__((unsigned int)force_resize, size.y));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0xF,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0x3D,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__((unsigned int)force_resize, size.y));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x10,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0x22,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__((unsigned int)force_resize, size.y));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)9,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0x36,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__((unsigned int)force_resize, size.y));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x12,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0x31,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__((unsigned int)force_resize, size.y));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0xD,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0x3D,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__((unsigned int)force_resize, size.y));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x17,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0x1C,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__((unsigned int)force_resize, size.y));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x18,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0x1C,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__((unsigned int)force_resize, size.y));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x19,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0x31,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__((unsigned int)force_resize, size.y));
    _FFFFFFFC.y = *((unsigned __int8 *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                  + 292);
    _FFFFFFFC.x = 1;
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x14,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0x31,
      _FFFFFFFC,
      (vostok::math::uint2)__PAIR64__((unsigned int)force_resize, size.y));
    _FFFFFFFCa.y = *((unsigned __int8 *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                   + 292);
    _FFFFFFFCa.x = 1;
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x15,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0x36,
      _FFFFFFFCa,
      (vostok::math::uint2)__PAIR64__((unsigned int)force_resize, size.y));
    _FFFFFFFCb.y = *((unsigned __int8 *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                   + 292);
    _FFFFFFFCb.x = 1;
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x16,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0x36,
      _FFFFFFFCb,
      (vostok::math::uint2)__PAIR64__((unsigned int)force_resize, size.y));
    _FFFFFFFCc.y = *((unsigned __int8 *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                   + 292);
    _FFFFFFFCc.x = 1;
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x13,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0x31,
      _FFFFFFFCc,
      (vostok::math::uint2)__PAIR64__(v12, v13));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x1D,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0x1A,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__(v12, v13));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)3,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0x1A,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__(v12, v13));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x11,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0x22,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__(v12, v13));
    vostok::render::renderer_context_targets::new_rt(
      0,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0x36,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__(v12, v13));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)4,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0x3D,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__(v12, v13));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)5,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0x18,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__(v12, v13));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x33,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0x1C,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__(v12, v13));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x31,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0xA,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__(v40, size_d4));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x32,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0xA,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__(v40, size_d4));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x43,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0xA,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__(v40, size_d4));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)6,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0x1C,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__(v40, size_d4));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)7,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0xA,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__(v40, size_d4));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)2,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0xA,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__(v41, size_d16));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)1,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0xA,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__(v41, size_d16));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x2C,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0xA,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__(v11, size_blur_1x));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x1E,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0xA,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__(v11, size_blur_1x));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x1F,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0xA,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__(v11, size_blur_1x));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x20,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0xA,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__(v11, size_blur_1x));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x21,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0xA,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__(v11, size_blur_1x));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x22,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0xA,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__(v42, size_blur_2x));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x23,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0xA,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__(v42, size_blur_2x));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x24,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0xA,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__(v43, size_blur_4x));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x25,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0xA,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__(v43, size_blur_4x));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x26,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0xA,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__(v44, size_blur_8x));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x27,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0xA,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__(v44, size_blur_8x));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x28,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0xA,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__(v45, size_blur_16x));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x29,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0xA,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__(v45, size_blur_16x));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x2A,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0xA,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__(v46, size_blur_32x));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x2B,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0xA,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)__PAIR64__(v46, size_blur_32x));
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x38,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)2,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)0x100000001LL);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x39,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)2,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)0x200000002LL);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x3A,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)2,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)0x400000004LL);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x3B,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)2,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)0x800000008LL);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x3C,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)2,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)0x1000000010LL);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x3D,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)2,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)0x2000000020LL);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x3E,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)2,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)0x4000000040LL);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x3F,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)2,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)0x8000000080LL);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x40,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)2,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)0x10000000100LL);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x35,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)2,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)0x100000001LL);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x34,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)2,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)0x100000001LL);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x36,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)2,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)0x100000010LL);
    b_4.x = 1;
    vostok::render::renderer_context_targets::new_lt(
      (vostok::render::renderer_context_targets *)0x44,
      (vostok::render::renderer_context_targets *)a2,
      DXGI_FORMAT_R32G32_FLOAT,
      b_4);
    b_4a.x = 1;
    vostok::render::renderer_context_targets::new_lt(
      (vostok::render::renderer_context_targets *)0x45,
      (vostok::render::renderer_context_targets *)a2,
      DXGI_FORMAT_R32G32_FLOAT,
      b_4a);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x41,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0xA,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)0x8000000100LL);
    vostok::render::renderer_context_targets::new_rt(
      (vostok::render::renderer_context_targets *)0x42,
      (vostok::render::renderer_context_targets *)a2,
      (const char *)0xA,
      (const vostok::math::uint2)0x100000001LL,
      (vostok::math::uint2)0x8000000100LL);
    if ( vostok::core::g_log_filter_tree
      && !vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render_pc_dx11:", info) )
    {
      v15 = 0;
    }
    else
    {
      v14 = vostok::core::g_log_callback;
      log_callback.vtable = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          &log_callback.functor,
          &log_callback.functor,
          destroy_functor_tag);
      if ( v14 )
      {
        log_callback.functor.obj_ptr = v14;
        log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                     + 1);
      }
      else
      {
        log_callback.vtable = 0;
      }
      v15 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\renderer_context_targets.cpp",
        0x130u,
        "void __thiscall vostok::render::renderer_context_targets::create_targets(class vostok::math::uint2,bool)",
        "render_pc_dx11:",
        info,
        "render targets memory usage: %d",
        *(_DWORD *)(a2 + 11212) >> 20);
    }
    if ( (v15 & 1) != 0 && log_callback.vtable )
    {
      if ( ((int)log_callback.vtable & 1) == 0 )
      {
        v16 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
        if ( v16 )
          v16(&log_callback.functor, &log_callback.functor, 2);
      }
      log_callback.vtable = 0;
    }
    v17 = *(_DWORD *)(a2 + 8472);
    if ( v17 )
      v18 = *(vostok::render::backend **)(v17 + 16);
    else
      v18 = 0;
    m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    if ( *((vostok::render::backend **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
         + 535) != v18 )
    {
      *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) = v18;
      *((_BYTE *)m_conflicted_key_name + 163) = 1;
    }
    if ( *((_DWORD *)m_conflicted_key_name + 536) )
    {
      *((_DWORD *)m_conflicted_key_name + 536) = 0;
      *((_BYTE *)m_conflicted_key_name + 164) = 1;
    }
    if ( *((_DWORD *)m_conflicted_key_name + 537) )
    {
      *((_DWORD *)m_conflicted_key_name + 537) = 0;
      *((_BYTE *)m_conflicted_key_name + 165) = 1;
    }
    if ( *((_DWORD *)m_conflicted_key_name + 538) )
    {
      *((_DWORD *)m_conflicted_key_name + 538) = 0;
      *((_BYTE *)m_conflicted_key_name + 166) = 1;
    }
    vostok::render::backend::clear_render_targets(v18, (int)m_conflicted_key_name, 0.25, 0.25, 0.25, 0.25, v36);
    v20 = *(_DWORD *)(a2 + 8632);
    if ( v20 )
      v21 = *(vostok::render::backend **)(v20 + 16);
    else
      v21 = 0;
    v22 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    if ( *((vostok::render::backend **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
         + 535) != v21 )
    {
      *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) = v21;
      *((_BYTE *)v22 + 163) = 1;
    }
    if ( *((_DWORD *)v22 + 536) )
    {
      *((_DWORD *)v22 + 536) = 0;
      *((_BYTE *)v22 + 164) = 1;
    }
    if ( *((_DWORD *)v22 + 537) )
    {
      *((_DWORD *)v22 + 537) = 0;
      *((_BYTE *)v22 + 165) = 1;
    }
    if ( *((_DWORD *)v22 + 538) )
    {
      *((_DWORD *)v22 + 538) = 0;
      *((_BYTE *)v22 + 166) = 1;
    }
    vostok::render::backend::clear_render_targets(v21, (int)v22, 0.25, 0.25, 0.25, 0.25, v37);
    v23 = *(_DWORD *)(a2 + 3352);
    if ( v23 )
    {
      v24 = *(vostok::render::backend **)(v23 + 16);
      v25 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      if ( *((vostok::render::backend **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
           + 535) != v24 )
      {
        *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) = v24;
        *((_BYTE *)v25 + 163) = 1;
      }
      if ( *((_DWORD *)v25 + 536) )
      {
        *((_DWORD *)v25 + 536) = 0;
        *((_BYTE *)v25 + 164) = 1;
      }
      if ( *((_DWORD *)v25 + 537) )
      {
        *((_DWORD *)v25 + 537) = 0;
        *((_BYTE *)v25 + 165) = 1;
      }
      if ( *((_DWORD *)v25 + 538) )
      {
        *((_DWORD *)v25 + 538) = 0;
        *((_BYTE *)v25 + 166) = 1;
      }
      vostok::render::backend::clear_render_targets(v24, (int)v25, *(float *)&clear_value, 0.0, 0.0, 0.0, v38);
      v27 = *(_DWORD *)(a2 + 3672);
      if ( v27 )
        v28 = *(_DWORD *)(v27 + 16);
      else
        v28 = 0;
      v29 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      if ( *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) != v28 )
      {
        *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) = v28;
        *((_BYTE *)v29 + 163) = 1;
      }
      if ( *((_DWORD *)v29 + 536) )
      {
        *((_DWORD *)v29 + 536) = 0;
        *((_BYTE *)v29 + 164) = 1;
      }
      if ( *((_DWORD *)v29 + 537) )
      {
        *((_DWORD *)v29 + 537) = 0;
        *((_BYTE *)v29 + 165) = 1;
      }
      if ( *((_DWORD *)v29 + 538) )
      {
        *((_DWORD *)v29 + 538) = 0;
        *((_BYTE *)v29 + 166) = 1;
      }
      vostok::render::backend::clear_render_targets(v26, (int)v29, 0.0, 0.0, 0.0, 0.0, v39);
    }
  }
}
