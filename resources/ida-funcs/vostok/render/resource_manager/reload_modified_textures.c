void __thiscall vostok::render::resource_manager::reload_modified_textures(
        vostok::render::resource_manager *this,
        vostok::render::resource_manager *a1)
{
  const vostok::fixed_string<260> *v2; // edi
  int v3; // eax
  vostok::fixed_string<260> *v4; // esi
  const vostok::fixed_string<260> *v5; // eax
  vostok::buffer_string *v6; // ecx
  int v7; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // ecx
  _BYTE v9[28]; // [esp-1Ch] [ebp-2524h] BYREF
  const vostok::fixed_string<260> *v10; // [esp+Ch] [ebp-24FCh]
  int f[8]; // [esp+10h] [ebp-24F8h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf5<void,vostok::render::resource_manager,vostok::resources::queries_result &,unsigned int,bool,unsigned int,long volatile *>,boost::_bi::list6<boost::_bi::value<vostok::render::resource_manager *>,boost::arg<1>,boost::_bi::value<int>,boost::_bi::value<bool>,boost::_bi::value<unsigned int>,boost::_bi::value<long volatile *> > > v12; // [esp+30h] [ebp-24D8h] BYREF
  unsigned __int8 *str1[3]; // [esp+48h] [ebp-24C0h] BYREF
  _BYTE v14[260]; // [esp+54h] [ebp-24B4h] BYREF
  char v15; // [esp+158h] [ebp-23B0h] BYREF
  vostok::fixed_string<260> v16; // [esp+160h] [ebp-23A8h] BYREF
  char v17; // [esp+270h] [ebp-2298h]
  const vostok::fixed_string<260> *v18; // [esp+278h] [ebp-2290h]
  const vostok::fixed_string<260> *i; // [esp+27Ch] [ebp-228Ch]
  char *v20; // [esp+280h] [ebp-2288h]
  _DWORD v21[2208]; // [esp+284h] [ebp-2284h] BYREF
  char v22; // [esp+2504h] [ebp-4h] BYREF

  v18 = (const vostok::fixed_string<260> *)v21;
  v20 = &v22;
  v2 = *(const vostok::fixed_string<260> **)((char *)&a1->sh_created + (_DWORD)&loc_948EB + 1);
  v3 = (signed int)(*(unsigned int *)((char *)&a1->sh_returned + (_DWORD)&loc_948EB + 1) - (int)v2) / 276;
  v10 = *(const vostok::fixed_string<260> **)((char *)&a1->sh_returned + (_DWORD)&loc_948EB + 1);
  v4 = (vostok::fixed_string<260> *)v21;
  for ( i = (const vostok::fixed_string<260> *)&v21[69 * v3];
        v2 != v10;
        v4 = (vostok::fixed_string<260> *)((char *)v4 + 276) )
  {
    if ( v4 )
    {
      vostok::fixed_string<260>::fixed_string<260>(v4, v2);
      LOBYTE(v4[1].m_begin) = 47;
    }
    v2 = (const vostok::fixed_string<260> *)((char *)v2 + 276);
  }
  v5 = v18;
  v10 = v18;
  while ( v5 != i )
  {
    str1[0] = v14;
    str1[1] = v14;
    str1[2] = (unsigned __int8 *)&v15;
    v14[0] = 0;
    v15 = 47;
    vostok::fixed_string<260>::fixed_string<260>(&v16, v10);
    v17 = 47;
    vostok::fs_new::path_string_impl::assignf(
      str1,
      v6,
      (vostok::buffer_string *)"%s/%s.dds",
      "resources/textures",
      v16.m_begin);
    strstr(str1[0], "$user$");
    if ( !v7 )
    {
      *(_DWORD *)&v9[24] = (unsigned __int8)1_230;
      *(_DWORD *)v9 = f;
      qmemcpy(
        &v9[4],
        boost::bind<void,vostok::render::resource_manager,vostok::resources::queries_result &,unsigned int,bool,unsigned int,long volatile *,vostok::render::resource_manager *,boost::arg<1>,int,bool,unsigned int,long volatile *>(
          a1,
          &v12),
        0x18u);
      boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
        0,
        *(boost::_bi::bind_t<void,boost::_mfi::mf5<void,vostok::render::resource_manager,vostok::resources::queries_result &,unsigned int,bool,unsigned int,long volatile *>,boost::_bi::list6<boost::_bi::value<vostok::render::resource_manager *>,boost::arg<1>,boost::_bi::value<int>,boost::_bi::value<bool>,boost::_bi::value<unsigned int>,boost::_bi::value<long volatile *> > > *)v9,
        *(int *)&v9[24]);
      vostok::resources::query_resource(
        (const char *)str1[0],
        (vostok::variant<32> *)7,
        vostok::render::g_allocator,
        0,
        0,
        assert_on_fail_true);
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v8, f);
    }
    v10 = (const vostok::fixed_string<260> *)((char *)v10 + 276);
    v5 = v10;
  }
}
