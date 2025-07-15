int __userpurge vostok::render::options::end_render_options_changing@<eax>(
        vostok::render::options *this@<ecx>,
        int a2@<eax>,
        vostok::render::vector<vostok::fs_new::virtual_path_string> *out_changed_defines)
{
  unsigned int y; // edx
  int v5; // ecx
  bool v6; // zf
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  _DWORD *v11; // esi
  int v12; // ebp
  stlp_std::priv::_Impl_vector<vostok::fs_new::virtual_path_string,vostok::render::std_allocator<vostok::fs_new::virtual_path_string> > *v13; // ecx
  const char *v14; // eax
  vostok::console_commands::command_type v16; // [esp+0h] [ebp-130h]
  vostok::memory::base_allocator *v17; // [esp+4h] [ebp-12Ch]
  vostok::math::uint2 res_str; // [esp+14h] [ebp-11Ch] BYREF
  vostok::fs_new::virtual_path_string __x; // [esp+1Ch] [ebp-114h] BYREF

  vostok::render::parse_resolution(s_r_resolution_value.m_begin, (int *)&res_str);
  y = res_str.y;
  v6 = *(_DWORD *)(a2 + 196) == 0;
  *(_DWORD *)(a2 + 232) = res_str.x;
  v5 = *(_DWORD *)(a2 + 128);
  *(_DWORD *)(a2 + 236) = y;
  *(_BYTE *)(a2 + 267) = !v6;
  v6 = v5 == 0;
  if ( v5 )
  {
    v7 = *(_DWORD *)(a2 + 220);
    if ( v7 )
    {
      v8 = v7 - 1;
      if ( v8 )
      {
        if ( v8 == 1 )
          *(_BYTE *)(a2 + 293) = 1;
      }
      else
      {
        *(_BYTE *)(a2 + 269) = 1;
        *(_BYTE *)(a2 + 272) = 1;
        *(_BYTE *)(a2 + 293) = 0;
      }
    }
    v6 = v5 == 0;
  }
  if ( v6 )
  {
    *(_BYTE *)(a2 + 301) = 0;
    *(_DWORD *)(a2 + 172) = 512;
  }
  else if ( (unsigned int)(v5 - 1) <= 2 )
  {
    *(_BYTE *)(a2 + 301) = 1;
    *(_DWORD *)(a2 + 172) = 1024;
  }
  v9 = *(_DWORD *)(a2 + 216);
  if ( v9 )
  {
    if ( (unsigned int)(v9 - 1) <= 2 )
      *(_BYTE *)(a2 + 250) = 1;
  }
  else
  {
    *(_BYTE *)(a2 + 250) = 0;
  }
  v10 = *(_DWORD *)(a2 + 208);
  if ( v10 )
  {
    if ( (unsigned int)(v10 - 1) <= 2 )
      *(_BYTE *)(a2 + 294) = 1;
  }
  else
  {
    *(_BYTE *)(a2 + 294) = 0;
  }
  if ( !*(_DWORD *)(a2 + 200) )
    *(_BYTE *)(a2 + 292) = 0;
  v11 = *(_DWORD **)a2;
  v12 = 1;
  if ( *(_DWORD *)a2 )
  {
    do
    {
      if ( (*(unsigned __int8 (__thiscall **)(_DWORD *))(*v11 + 4))(v11) )
      {
        v12 |= v11[3];
        res_str.x = v11[2];
        vostok::fs_new::virtual_path_string::virtual_path_string(&__x, (const char **)&res_str);
        stlp_std::priv::_Impl_vector<vostok::fs_new::virtual_path_string,vostok::render::std_allocator<vostok::fs_new::virtual_path_string>>::push_back(
          (const stlp_std::__false_type *)&__x,
          v13,
          &out_changed_defines->_M_impl);
      }
      v11 = (_DWORD *)v11[1];
    }
    while ( v11 );
  }
  qmemcpy((void *)(a2 + 308), (const void *)(a2 + 12), 0x128u);
  v14 = s_engine_0->get_user_data_directory(s_engine_0);
  vostok::console_commands::save("user.cfg", v14, v16, v17);
  return v12;
}
