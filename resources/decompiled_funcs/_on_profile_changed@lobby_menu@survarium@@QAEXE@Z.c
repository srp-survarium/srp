void __thiscall survarium::lobby_menu::on_profile_changed(
        survarium::lobby_menu *this,
        survarium::lobby_menu *profile_id,
        unsigned __int8 profile_ida)
{
  survarium::game *m_game; // eax
  int v4; // eax
  __int64 v5; // rdi
  survarium::profile_player_character *v6; // ecx
  survarium::flash_movie_resource *m_object; // eax
  survarium::profile_slot *slots; // eax
  void *id; // edi
  survarium::flash_movie_resource *v10; // edx
  bool v11; // zf
  int v12; // ecx
  survarium::player_profile *v13; // edi
  survarium::player_profile *v14; // eax
  __m128i v15; // xmm0
  void (__cdecl *v16)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  const char *v17; // [esp+1326h] [ebp-234h]
  unsigned __int8 v18; // [esp+133Dh] [ebp-21Dh]
  int v19; // [esp+133Eh] [ebp-21Ch] BYREF
  int v20; // [esp+1342h] [ebp-218h]
  void *pObjectInterface; // [esp+1346h] [ebp-214h]
  vostok::variant<32> *condition_or_stack; // [esp+1356h] [ebp-204h] BYREF
  survarium::player_profile *v23; // [esp+135Ah] [ebp-200h]
  Scaleform::GFx::Value pargs; // [esp+135Eh] [ebp-1FCh] BYREF
  Scaleform::GFx::Value v25; // [esp+137Ah] [ebp-1E0h] BYREF
  int v26; // [esp+139Eh] [ebp-1BCh] BYREF
  int v27; // [esp+13A2h] [ebp-1B8h]
  int profile_name; // [esp+13A6h] [ebp-1B4h]
  survarium::profile_slot *v29; // [esp+13B6h] [ebp-1A4h]
  __m128i requests; // [esp+13BAh] [ebp-1A0h] BYREF
  int v31; // [esp+13CAh] [ebp-190h] BYREF
  int v32; // [esp+13CEh] [ebp-18Ch]
  unsigned int v33; // [esp+13D2h] [ebp-188h]
  Scaleform::GFx::Value pvalue; // [esp+13E2h] [ebp-178h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+13FAh] [ebp-160h] BYREF
  _DWORD v36[2]; // [esp+141Ah] [ebp-140h] BYREF
  _DWORD v37[8]; // [esp+1422h] [ebp-138h] BYREF
  _DWORD *v38; // [esp+1442h] [ebp-118h]
  int v39; // [esp+1446h] [ebp-114h]
  vostok::buffer_string v40; // [esp+144Ah] [ebp-110h] BYREF
  _BYTE v41[260]; // [esp+1456h] [ebp-104h] BYREF
  char vars0; // [esp+155Ah] [ebp+0h] BYREF

  HIDWORD(v5) = profile_id;
  m_game = profile_id->m_game;
  profile_id->m_selected_profile = profile_ida;
  v4 = (int)m_game->m_network_client->lobby_client(m_game->m_network_client);
  LODWORD(v5) = profile_id->m_character;
  v6 = (survarium::profile_player_character *)(440 * profile_ida);
  v23 = (survarium::player_profile *)((char *)&v6[76] + v4);
  survarium::profile_player_character::query_profile_contents(v6, v5, v23);
  m_object = profile_id->m_lobby_menu_ui.m_object;
  pvalue.pObjectInterface = 0;
  pvalue.Type = VT_Undefined;
  Scaleform::GFx::Movie::CreateArray(m_object->movie->m_movie, &pvalue);
  v40.m_end = v41;
  slots = v23->slots;
  v18 = 0;
  v40.m_begin = v41;
  v40.m_max_end = &vars0;
  v41[0] = 0;
  v19 = 0;
  v20 = 0;
  pargs.pObjectInterface = 0;
  v29 = v23->slots;
  requests.m128i_i32[0] = 19;
  do
  {
    id = (void *)slots->item.id;
    if ( id )
    {
      v17 = (const char *)slots->item.id;
      condition_or_stack = (vostok::variant<32> *)slots->item.condition_or_stack;
      vostok::buffer_string::appendf(&v40, (vostok::buffer_string *)&stru_96B880, v17);
      v10 = profile_id->m_lobby_menu_ui.m_object;
      v25.pObjectInterface = 0;
      v25.Type = VT_Undefined;
      Scaleform::GFx::Movie::CreateObject(v10->movie->m_movie, &v25, 0, 0, 0);
      if ( (v20 & 0x40) != 0 )
      {
        (*(void (__thiscall **)(int, int *, void *))(*(_DWORD *)v19 + 8))(v19, &v19, pObjectInterface);
        v19 = 0;
      }
      v20 = 3;
      pObjectInterface = id;
      v25.pObjectInterface->SetMember(
        v25.pObjectInterface,
        (void *)v25.mValue.IValue,
        "itemId",
        (const Scaleform::GFx::Value *)&v19,
        (v25.Type & 0x8F) == 10);
      if ( (v20 & 0x40) != 0 )
      {
        (*(void (__thiscall **)(int, int *, void *))(*(_DWORD *)v19 + 8))(v19, &v19, pObjectInterface);
        v19 = 0;
      }
      pObjectInterface = pargs.pObjectInterface;
      v20 = 3;
      v25.pObjectInterface->SetMember(
        v25.pObjectInterface,
        (void *)v25.mValue.IValue,
        "slotId",
        (const Scaleform::GFx::Value *)&v19,
        (v25.Type & 0x8F) == 10);
      if ( (v20 & 0x40) != 0 )
      {
        (*(void (__thiscall **)(int, int *, void *))(*(_DWORD *)v19 + 8))(v19, &v19, pObjectInterface);
        v19 = 0;
      }
      pObjectInterface = condition_or_stack;
      v20 = 3;
      v25.pObjectInterface->SetMember(
        v25.pObjectInterface,
        (void *)v25.mValue.IValue,
        "condition_or_stack",
        (const Scaleform::GFx::Value *)&v19,
        (v25.Type & 0x8F) == 10);
      pvalue.pObjectInterface->SetElement(pvalue.pObjectInterface, (void *)pvalue.mValue.IValue, v18++, &v25);
      if ( (v25.Type & 0x40) != 0 )
        v25.pObjectInterface->ObjectRelease(v25.pObjectInterface, &v25, (void *)v25.mValue.IValue);
      HIDWORD(v5) = profile_id;
    }
    ++pargs.pObjectInterface;
    slots = v29 + 1;
    v11 = requests.m128i_i32[0]-- == 1;
    ++v29;
  }
  while ( !v11 );
  v12 = *(_DWORD *)(HIDWORD(v5) + 212);
  pargs.Type = VT_Undefined;
  pargs.mValue.IValue = 0;
  Scaleform::GFx::Movie::CreateObject(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(v12 + 264) + 4),
    (Scaleform::GFx::Value *)&pargs.Type,
    0,
    0,
    0);
  (*(void (__thiscall **)(Scaleform::GFx::Value::ValueType, _DWORD, const char *, Scaleform::GFx::Value *, bool))(*(_DWORD *)pargs.Type + 20))(
    pargs.Type,
    *((_DWORD *)&pargs.mValue.BValue + 1),
    "items",
    &pvalue,
    (pargs.mValue.BValue & 0x8F) == 10);
  v13 = v23;
  profile_name = (int)v23->profile_name;
  v26 = 0;
  v27 = 6;
  (*(void (__thiscall **)(Scaleform::GFx::Value::ValueType, _DWORD, const char *, int *, bool))(*(_DWORD *)pargs.Type
                                                                                              + 20))(
    pargs.Type,
    *((_DWORD *)&pargs.mValue.BValue + 1),
    "name",
    &v26,
    (pargs.mValue.BValue & 0x8F) == 10);
  v32 = 0;
  v31 = 0;
  v33 = v13->profile_id;
  v32 = 4;
  (*(void (__thiscall **)(Scaleform::GFx::Value::ValueType, _DWORD, const char *, int *, bool))(*(_DWORD *)pargs.Type
                                                                                              + 20))(
    pargs.Type,
    *((_DWORD *)&pargs.mValue.BValue + 1),
    "profileId",
    &v31,
    (pargs.mValue.BValue & 0x8F) == 10);
  if ( (v27 & 0x40) != 0 )
  {
    (*(void (__thiscall **)(int, int *, int))(*(_DWORD *)v26 + 8))(v26, &v26, profile_name);
    v26 = 0;
  }
  v27 = 4;
  profile_name = 1;
  (*(void (__thiscall **)(Scaleform::GFx::Value::ValueType, _DWORD, const char *, int *, bool))(*(_DWORD *)pargs.Type
                                                                                              + 20))(
    pargs.Type,
    *((_DWORD *)&pargs.mValue.BValue + 1),
    "icon",
    &v26,
    (pargs.mValue.BValue & 0x8F) == 10);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(HIDWORD(v5) + 212) + 264) + 4),
    "root.player_profile.fillProfileItems",
    0,
    (const Scaleform::GFx::Value *)&pargs.Type,
    1u);
  LODWORD(v5) = vostok::memory::doug_lea_allocator::malloc_impl(
                  (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
                  8u);
  v14 = v23;
  *(_DWORD *)(v5 + 4) = *(_DWORD *)(*(_DWORD *)(HIDWORD(v5) + 168) + 948);
  *(_DWORD *)v5 = v14;
  v38 = 0;
  v39 = 0;
  v39 = vostok::detail::type_to_int<survarium::player_parameters_cooker_data *>::get();
  requests.m128i_i32[0] = (int)survarium::lobby_menu::player_parameters_ready;
  requests.m128i_i32[1] = 0;
  requests.m128i_i64[1] = __PAIR64__(v5, HIDWORD(v5));
  v15 = _mm_load_si128(&requests);
  v37[0] = v5;
  v36[0] = &vostok::detail::concrete_type_helper<survarium::player_parameters_cooker_data *>::`vftable';
  v38 = v36;
  *(__m128i *)&v25.pObjectInterface = v15;
  if ( survarium::generate_shaders_world::is_loading() )
  {
    callback.vtable = 0;
  }
  else
  {
    *(_QWORD *)&callback.functor.obj_ptr = *(_QWORD *)&v25.pObjectInterface;
    *((_QWORD *)&callback.functor.data + 1) = *(_QWORD *)&v25.mValue.NValue;
    callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::lobby_menu,vostok::resources::queries_result &,survarium::player_parameters_cooker_data *>,boost::_bi::list3<boost::_bi::value<survarium::lobby_menu *>,boost::arg<1>,boost::_bi::value<survarium::player_parameters_cooker_data *>>>>'::`2'::stored_vtable
                                                             + 1);
  }
  requests.m128i_i64[0] = (unsigned int)v40.m_begin | 0x6300000000LL;
  condition_or_stack = (vostok::variant<32> *)v36;
  vostok::resources::query_resources(
    (const vostok::resources::request *)&requests,
    1u,
    (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
    (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_,
    (const vostok::variant<32> **)&condition_or_stack,
    0,
    assert_on_fail_true);
  if ( callback.vtable )
  {
    if ( ((int)callback.vtable & 1) == 0 )
    {
      v16 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
      if ( v16 )
        v16(&callback.functor, &callback.functor, 2);
    }
  }
  if ( v38 )
  {
    (*(void (__thiscall **)(_DWORD *, _DWORD *))(*v38 + 4))(v38, v37);
    v38 = 0;
  }
  if ( (v32 & 0x40) != 0 )
  {
    (*(void (__thiscall **)(int, int *, unsigned int))(*(_DWORD *)v31 + 8))(v31, &v31, v33);
    v31 = 0;
  }
  v32 = 0;
  if ( (v27 & 0x40) != 0 )
  {
    (*(void (__thiscall **)(int, int *, int))(*(_DWORD *)v26 + 8))(v26, &v26, profile_name);
    v26 = 0;
  }
  v27 = 0;
  if ( (pargs.mValue.BValue & 0x40) != 0 )
  {
    (*(void (__thiscall **)(Scaleform::GFx::Value::ValueType, Scaleform::GFx::Value::ValueType *, _DWORD))(*(_DWORD *)pargs.Type + 8))(
      pargs.Type,
      &pargs.Type,
      *((_DWORD *)&pargs.mValue.BValue + 1));
    pargs.Type = VT_Undefined;
  }
  pargs.mValue.IValue = 0;
  if ( (v20 & 0x40) != 0 )
  {
    (*(void (__thiscall **)(int, int *, void *))(*(_DWORD *)v19 + 8))(v19, &v19, pObjectInterface);
    v19 = 0;
  }
  v20 = 0;
  if ( (pvalue.Type & 0x40) != 0 )
    pvalue.pObjectInterface->ObjectRelease(pvalue.pObjectInterface, &pvalue, (void *)pvalue.mValue.IValue);
}
