void __thiscall vostok::render::skeleton_combined_model_cook::query_resources_by_data(
        vostok::render::skeleton_combined_model_cook *this,
        __int64 parent,
        int *a3)
{
  vostok::memory::doug_lea_allocator *v4; // esi
  char *v5; // eax
  vostok::memory::doug_lea_allocator *v6; // ecx
  char *v7; // edi
  int v8; // eax
  int v9; // ecx
  bool v10; // zf
  const char **v11; // eax
  const char ***v12; // edi
  vostok::strings::detail::tuples *v13; // ecx
  void *v14; // esp
  vostok::strings::detail::tuples *v15; // ecx
  const char ***v16; // edi
  vostok::strings::detail::tuples *v17; // ecx
  vostok::strings::detail::tuples *v18; // ecx
  void *v19; // esp
  vostok::strings::detail::tuples *v20; // ecx
  vostok::strings::detail::tuples *v21; // ecx
  vostok::strings::detail::tuples *v22; // ecx
  void *v23; // esp
  vostok::strings::detail::tuples *v24; // ecx
  unsigned int v25; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v26; // ecx
  vostok::memory::doug_lea_allocator *v27; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::skeleton_combined_model_cook,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *,vostok::render::skeleton_combined_cook_data *>,boost::_bi::list4<boost::_bi::value<vostok::render::skeleton_combined_model_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *>,boost::_bi::value<vostok::render::skeleton_combined_cook_data *> > > v28; // [esp-14h] [ebp-98h]
  const char *v29; // [esp+0h] [ebp-84h] BYREF
  const char *v30; // [esp+4h] [ebp-80h]
  unsigned int v31; // [esp+8h] [ebp-7Ch]
  vostok::strings::detail::tuples v32; // [esp+10h] [ebp-74h] BYREF
  __int64 v33; // [esp+44h] [ebp-40h]
  int v34; // [esp+4Ch] [ebp-38h]
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::skeleton_combined_model_cook,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *,vostok::render::skeleton_combined_cook_data *>,boost::_bi::list4<boost::_bi::value<vostok::render::skeleton_combined_model_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *>,boost::_bi::value<vostok::render::skeleton_combined_cook_data *> > > f; // [esp+50h] [ebp-34h] BYREF
  void (__thiscall *v36)(vostok::render::skeleton_combined_model_cook *, vostok::resources::queries_result *, vostok::render::skeleton_combined_cook_data *, vostok::render::skeleton_combined_cook_data *); // [esp+60h] [ebp-24h]
  __int64 v37; // [esp+64h] [ebp-20h]
  int v38; // [esp+6Ch] [ebp-18h]
  unsigned int v39; // [esp+70h] [ebp-14h]
  vostok::resources::request *v40; // [esp+74h] [ebp-10h]
  const char **v41; // [esp+78h] [ebp-Ch]
  int v42; // [esp+7Ch] [ebp-8h]
  const char **i; // [esp+94h] [ebp+10h]

  v4 = vostok::render::g_allocator;
  v39 = 3 * *((unsigned __int8 *)a3 + 7316) + 2;
  v5 = type_info::raw_name(&vostok::resources::request `RTTI Type Descriptor');
  v42 = 0;
  v7 = vostok::memory::doug_lea_allocator::malloc_impl(v6, (int)v4, 8 * v39, v5, v29, v30, v31);
  v8 = *a3;
  *((_DWORD *)v7 + 1) = 45;
  *(_DWORD *)v7 = v8;
  v9 = 3;
  *((_DWORD *)v7 + 2) = a3[70];
  *((_DWORD *)v7 + 3) = 3;
  v10 = *((_BYTE *)a3 + 7316) == 0;
  v40 = (vostok::resources::request *)v7;
  if ( !v10 )
  {
    v11 = (const char **)(a3 + 141);
    v38 = 3;
    v34 = 32;
    v12 = (const char ***)(v7 + 16);
    for ( i = (const char **)(a3 + 141); ; v11 = i )
    {
      vostok::strings::detail::tuples::tuples(
        (vostok::strings::detail::tuples *)v9,
        &v32,
        "resources/models/",
        *v11,
        ".skinned_model/render/",
        v11[69],
        "/converted_model");
      v14 = alloca(vostok::strings::detail::tuples::size(v13, (unsigned int *)&v32));
      v41 = &v29;
      vostok::strings::detail::tuples::concat(v15, (int)&v32, (char *)&v29);
      *v12 = v41;
      v12[1] = (const char **)v38;
      v16 = v12 + 2;
      vostok::strings::detail::tuples::tuples(v17, &v32, "resources/models/", *i, ".skinned_model/settings");
      v19 = alloca(vostok::strings::detail::tuples::size(v18, (unsigned int *)&v32));
      v41 = &v29;
      vostok::strings::detail::tuples::concat(v20, (int)&v32, (char *)&v29);
      *v16 = v41;
      v16[1] = (const char **)32;
      v16 += 2;
      vostok::strings::detail::tuples::tuples(
        v21,
        &v32,
        "resources/models/",
        *i,
        ".skinned_model/render/",
        i[69],
        "/export_properties");
      v23 = alloca(vostok::strings::detail::tuples::size(v22, (unsigned int *)&v32));
      v41 = &v29;
      vostok::strings::detail::tuples::concat(v24, (int)&v32, (char *)&v29);
      i += 211;
      *v16 = v41;
      v16[1] = (const char **)v34;
      v25 = *((unsigned __int8 *)a3 + 7316);
      v12 = v16 + 2;
      if ( ++v42 >= v25 )
        break;
    }
  }
  v33 = parent;
  v36 = vostok::render::skeleton_combined_model_cook::on_resources_loaded;
  v34 = (int)a3;
  v37 = parent;
  v38 = (int)a3;
  v28.l_.a1_.t_ = (vostok::render::skeleton_combined_model_cook *)vostok::render::skeleton_combined_model_cook::on_resources_loaded;
  *(_QWORD *)&v28.l_.a3_.t_ = parent;
  v28.f_.f_ = (void (__thiscall *)(vostok::render::skeleton_combined_model_cook *, vostok::resources::queries_result *, vostok::resources::query_result_for_cook *, vostok::render::skeleton_combined_cook_data *))&f;
  boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
    (boost::function<void __cdecl(vostok::resources::queries_result &)> *)v9,
    v28,
    (int)a3);
  vostok::resources::query_resources(
    v40,
    v39,
    vostok::render::g_allocator,
    0,
    (const vostok::variant<32> **)HIDWORD(parent),
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v26,
    (int *)&f);
  vostok::memory::doug_lea_allocator::free_impl(v27, (int)vostok::render::g_allocator, (char *)v40, v29, v30, v31);
}
