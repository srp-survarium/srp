void __thiscall vostok::network::match_client::set_connection_ports(
        vostok::network::match_client *this,
        int ping_message_type,
        char session_id,
        int first_port,
        const unsigned __int16 last_port,
        __int16 a6)
{
  int v6; // edi
  int v7; // esi
  char *v8; // eax
  _DWORD *v9; // ebx
  int v10; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v11; // ecx
  bool v12; // zf
  _BYTE v13[28]; // [esp-1Ch] [ebp-78h] BYREF
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> f; // [esp+Ch] [ebp-50h] BYREF
  _DWORD v15[6]; // [esp+2Ch] [ebp-30h] BYREF
  _DWORD v16[5]; // [esp+44h] [ebp-18h] BYREF
  int v17; // [esp+58h] [ebp-4h]

  v17 = 0;
  v6 = ping_message_type;
  v7 = *(_DWORD *)(*(_DWORD *)(ping_message_type + 236) + 284);
  v8 = type_info::raw_name(&vostok::network::functor_order `RTTI Type Descriptor');
  v9 = (_DWORD *)(*(int (__thiscall **)(int, int, char *, const char *, const char *, int))(*(_DWORD *)v7 + 16))(
                   v7,
                   48,
                   v8,
                   "vostok::network::match_client::set_connection_ports",
                   ".\\match_client.cpp",
                   206);
  if ( v9 )
  {
    v16[0] = *(_DWORD *)(ping_message_type + 240);
    LOBYTE(v16[1]) = session_id;
    v16[2] = first_port;
    LOWORD(v16[3]) = last_port;
    LOWORD(v16[4]) = a6;
    v15[0] = vostok::network::match_client_impl::set_connection_ports;
    qmemcpy(&v15[1], v16, 0x14u);
    *(_DWORD *)v13 = &f;
    qmemcpy(&v13[4], v15, 0x18u);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      0,
      *(boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::network::match_client_impl,unsigned char,unsigned int,unsigned short,unsigned short>,boost::_bi::list5<boost::reference_wrapper<vostok::network::match_client_impl *>,boost::_bi::value<unsigned char>,boost::_bi::value<unsigned int>,boost::_bi::value<unsigned short>,boost::_bi::value<unsigned short> > > *)v13,
      *(int *)&v13[24]);
    v9[1] = *(_DWORD *)(*(_DWORD *)(ping_message_type + 236) + 284);
    *(_DWORD *)&v13[24] = v9 + 4;
    v17 = 1;
    *v9 = &vostok::network::functor_order::`vftable';
    boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
      &f,
      *(const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> **)&v13[24]);
    v6 = ping_message_type;
  }
  else
  {
    v9 = 0;
  }
  v10 = *(_DWORD *)(v6 + 236);
  v9[2] = 0;
  v10 += 148;
  v11 = (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)_InterlockedExchange(
                                                                                          (volatile __int32 *)(*(_DWORD *)v10 + 8),
                                                                                          (__int32)v9);
  v12 = (v17 & 1) == 0;
  *(_DWORD *)v10 = v9;
  if ( !v12 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v11,
      (int *)&f);
}
