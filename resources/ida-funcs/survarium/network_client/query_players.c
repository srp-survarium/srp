// bad sp value at call has been detected, the output may be wrong!
void __userpurge survarium::network_client::query_players(
        survarium::network_client *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        _DWORD *a5)
{
  int v5; // eax
  int v6; // edi
  int v7; // esi
  void *v8; // esp
  vostok::resources::request *v9; // eax
  void *v10; // esp
  void *v11; // esp
  int v12; // eax
  vostok::buffer_vector<vostok::variant<32> const *> *v13; // ecx
  int v14; // eax
  int v15; // esi
  survarium::game_world *v16; // ecx
  char *v17; // edx
  char *v18; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v19; // ecx
  vostok::variant<32> *v20; // ecx
  vostok::buffer_vector<vostok::variant<32> > *v21; // ecx
  vostok::variant<32> v22; // [esp-90h] [ebp-9Ch] BYREF
  int v23; // [esp-60h] [ebp-6Ch]
  _QWORD v24[3]; // [esp-5Ch] [ebp-68h] BYREF
  const vostok::variant<32> **v25; // [esp-44h] [ebp-50h] BYREF
  _DWORD *v26; // [esp-40h] [ebp-4Ch]
  _DWORD *v27; // [esp-3Ch] [ebp-48h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v28; // [esp-38h] [ebp-44h] BYREF
  vostok::buffer_vector<vostok::resources::request> v29; // [esp-18h] [ebp-24h] BYREF
  _DWORD *v30; // [esp-Ch] [ebp-18h] BYREF
  _QWORD *v31; // [esp-8h] [ebp-14h]
  _DWORD v32[4]; // [esp-4h] [ebp-10h] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v32[1] = a2;
  v32[2] = retaddr;
  v5 = (*(int (__thiscall **)(_DWORD *, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, vostok::detail::abstract_type_helper *, unsigned int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, const vostok::variant<32> **, _DWORD *, _DWORD *, boost::detail::function::vtable_base *, boost::detail::function::vtable_base *, void *, void *, void *, void *, void *, void *, vostok::resources::request *, vostok::resources::request *, vostok::resources::request *, _DWORD *, _QWORD *))(*a5 + 64))(
         a5,
         a3,
         a4,
         *(_DWORD *)v22.m_helper_storage,
         *(_DWORD *)&v22.m_helper_storage[4],
         *(_DWORD *)v22.m_storage,
         *(_DWORD *)&v22.m_storage[4],
         *(_DWORD *)&v22.m_storage[8],
         *(_DWORD *)&v22.m_storage[12],
         *(_DWORD *)&v22.m_storage[16],
         *(_DWORD *)&v22.m_storage[20],
         *(_DWORD *)&v22.m_storage[24],
         *(_DWORD *)&v22.m_storage[28],
         v22.m_helper,
         v22.m_type_id,
         v23,
         v24[0],
         HIDWORD(v24[0]),
         v24[1],
         HIDWORD(v24[1]),
         v24[2],
         HIDWORD(v24[2]),
         v25,
         v26,
         v27,
         v28.vtable,
         (&v28.vtable)[1],
         v28.functor.obj_ptr,
         v28.functor.vostok_pointer_size_alignment[1],
         v28.functor.vostok_pointer_size_alignment[2],
         v28.functor.vostok_pointer_size_alignment[3],
         v28.functor.bound_memfunc_ptr.obj_ptr,
         v28.functor.vostok_pointer_size_alignment[5],
         v29.m_begin,
         v29.m_end,
         v29.m_max_end,
         v30,
         v31);
  v6 = *(unsigned __int8 *)(v5 + 29788);
  v7 = v5 + 16;
  v28.functor.vostok_pointer_size_alignment[5] = (void *)v6;
  v8 = alloca(8 * v6);
  v29.m_begin = (vostok::resources::request *)v32;
  v29.m_end = (vostok::resources::request *)v32;
  v9 = (vostok::resources::request *)&v32[2 * v6];
  v6 *= 48;
  v29.m_max_end = v9;
  v10 = alloca(v6);
  v32[0] = (char *)v32 + v6;
  v30 = v32;
  v31 = v32;
  v11 = alloca(4 * (int)v28.functor.vostok_pointer_size_alignment[5]);
  v25 = (const vostok::variant<32> **)v32;
  v26 = v32;
  v12 = a5[6] + 192;
  v27 = &v32[(int)v28.functor.vostok_pointer_size_alignment[5]];
  BYTE4(v24[2]) = 0;
  HIDWORD(v24[0]) = v7;
  if ( v12 )
    LODWORD(v24[1]) = v12 + 240;
  else
    LODWORD(v24[1]) = 0;
  LODWORD(v24[0]) = v12;
  vostok::variant<32>::destroy_previous_variable_if_needed(0, (int)&v22);
  v22.m_type_id = vostok::detail::type_to_int<survarium::pvp_match_core_query_user_data>::get();
  qmemcpy(v22.m_storage, v24, 0x18u);
  *(_DWORD *)v22.m_helper_storage = &vostok::detail::concrete_type_helper<survarium::pvp_match_core_query_user_data>::`vftable';
  v22.m_helper = (vostok::detail::abstract_type_helper *)&v22;
  vostok::buffer_vector<vostok::variant<32>>::push_back(0, (int)&v30, &v22);
  vostok::buffer_vector<vostok::variant<32> const *>::push_back(
    v13,
    (int)&v25,
    (const vostok::variant<32> **)&v28.functor.vostok_pointer_size_alignment[5]);
  v28.functor.vostok_pointer_size_alignment[5] = (void *)93;
  vostok::buffer_vector<vostok::resources::request>::push_back(
    &v29,
    (const vostok::resources::request *)&v28.functor.data + 2);
  v28.functor.vostok_pointer_size_alignment[2] = survarium::network_client::on_match_ready;
  v28.functor.bound_memfunc_ptr.obj_ptr = a5;
  v28.functor.vostok_pointer_size_alignment[3] = 0;
  LODWORD(v24[1]) = survarium::network_client::on_match_ready;
  HIDWORD(v24[1]) = 0;
  v24[2] = __PAIR64__((unsigned int)v28.functor.vostok_pointer_size_alignment[5], (unsigned int)a5);
  v31 = &v24[1];
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    v28.vtable = 0;
  }
  else
  {
    *(_QWORD *)&v28.functor.obj_ptr = v24[1];
    *((_QWORD *)&v28.functor.data + 1) = v24[2];
    v28.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::network_client,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::network_client *>,boost::arg<1>>>>'::`2'::stored_vtable
                                                        + 1);
  }
  v14 = (*(int (__thiscall **)(_DWORD *))(*a5 + 64))(a5);
  v15 = a5[6];
  v16 = (survarium::game_world *)(v15 + 14524);
  v17 = *(char **)(v15 + 14524);
  v18 = (char *)(v14 + 29804);
  if ( v17 != v18 )
  {
    *(_DWORD *)(v15 + 14528) = v17;
    *v17 = 0;
    vostok::buffer_string::operator+=((vostok::buffer_string *)(v15 + 14524), v18);
  }
  survarium::game_world::load(
    v16,
    (boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::game_world,vostok::resources::queries_result &,unsigned int,boost::function<void __cdecl(vostok::resources::queries_result &)> const &>,boost::_bi::list4<boost::_bi::value<survarium::game_world *>,boost::arg<1>,boost::_bi::value<unsigned int>,boost::_bi::value<boost::function<void __cdecl(vostok::resources::queries_result &)> > > > *)(v15 + 192),
    v29.m_begin,
    v29.m_end,
    v25,
    &v28);
  *(_BYTE *)(v15 + 13993) = 0;
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v19,
    (int *)&v28);
  vostok::variant<32>::destroy_previous_variable_if_needed(v20, (int)&v22);
  vostok::buffer_vector<vostok::variant<32>>::~buffer_vector<vostok::variant<32>>(v21, (int *)&v30);
}
