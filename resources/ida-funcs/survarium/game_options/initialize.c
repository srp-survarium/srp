void __usercall survarium::game_options::initialize(survarium::game_options *this@<ecx>, int a2@<eax>)
{
  _DWORD *v3; // ebx
  vostok::memory::doug_lea_allocator *v4; // esi
  char *v5; // eax
  vostok::memory::doug_lea_allocator *v6; // ecx
  char *v7; // eax
  int v8; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v9; // ecx
  const char *v10; // [esp+0h] [ebp-58h]
  const char *v11; // [esp+4h] [ebp-54h]
  unsigned int v12; // [esp+8h] [ebp-50h]
  int v13[4]; // [esp+20h] [ebp-38h] BYREF
  void (__thiscall *v14)(survarium::game_options *, vostok::resources::queries_result *); // [esp+30h] [ebp-28h]
  int v15; // [esp+34h] [ebp-24h]
  int v16; // [esp+38h] [ebp-20h]
  int v17; // [esp+3Ch] [ebp-1Ch]
  vostok::resources::request v18; // [esp+40h] [ebp-18h] BYREF
  const char *v19; // [esp+48h] [ebp-10h]
  int v20; // [esp+4Ch] [ebp-Ch]
  int v21; // [esp+50h] [ebp-8h]
  survarium::options_enum type; // [esp+54h] [ebp-4h]

  type = gameplay_options_type;
  v3 = (_DWORD *)(a2 + 20);
  v21 = 4;
  do
  {
    v4 = survarium::g_allocator;
    v5 = type_info::raw_name(&survarium::options_tab `RTTI Type Descriptor');
    v7 = vostok::memory::doug_lea_allocator::malloc_impl(v6, (int)v4, 0x14u, v5, v10, v11, v12);
    if ( v7 )
      survarium::options_tab::options_tab(
        *(survarium::game **)(a2 + 52),
        type,
        (survarium::options_tab *)v7,
        (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)(a2 + 12));
    else
      v8 = 0;
    ++type;
    *v3++ = v8;
    --v21;
  }
  while ( v21 );
  v16 = a2;
  v18.id = flash_movie_class;
  v20 = 515;
  v14 = survarium::game_options::on_resources_ready;
  v15 = 0;
  v18.path = "resources/flash_movies/main_menu.swf";
  v19 = "resources/flash_movies/cursor.swf";
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    v13[0] = 0;
  }
  else
  {
    v13[2] = (int)survarium::game_options::on_resources_ready;
    v13[3] = 0;
    v14 = (void (__thiscall *)(survarium::game_options *, vostok::resources::queries_result *))a2;
    v15 = v17;
    v13[0] = (int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::game_options,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::game_options *>,boost::arg<1>>>>'::`2'::stored_vtable
           + 1;
  }
  vostok::resources::query_resources(&v18, 2u, survarium::g_allocator, 0, 0, assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v9, v13);
}
