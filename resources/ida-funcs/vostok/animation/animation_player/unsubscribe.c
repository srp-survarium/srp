void __thiscall vostok::animation::animation_player::unsubscribe(
        vostok::animation::animation_player *this,
        const char *channel_id,
        char *callback_uid,
        int a4)
{
  int i; // esi
  vostok::animation::animation_player *v5; // ecx
  int j; // edi
  boost::function1<void,vostok::physics::contact_point const &> *v7; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // ecx
  boost::function1<void,vostok::physics::contact_point const &> *v9; // esi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v10; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v11; // ecx
  boost::function1<void,vostok::physics::contact_point const &> v12; // [esp+10h] [ebp-60h] BYREF
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v13; // [esp+30h] [ebp-40h] BYREF
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> f; // [esp+50h] [ebp-20h] BYREF

  for ( i = *((_DWORD *)channel_id + 16434); i; i = *(_DWORD *)(i + 4) )
  {
    if ( !vostok::strings::compare(*(const char **)i, callback_uid) )
    {
      for ( j = *(_DWORD *)(i + 8); j; j = *(_DWORD *)(j + 40) )
      {
        if ( *(_DWORD *)(j + 44) == a4 )
        {
          v13.vtable = 0;
          boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(&v13, &f);
          v9 = v7;
          if ( (boost::function1<void,vostok::physics::contact_point const &> *)j != v7 )
          {
            v12.vtable = 0;
            boost::function1<fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>,unsigned char>::move_assign(
              &v12,
              v7);
            boost::function1<fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>,unsigned char>::move_assign(
              v9,
              (boost::function1<void,vostok::physics::contact_point const &> *)j);
            boost::function1<fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>,unsigned char>::move_assign(
              (boost::function1<void,vostok::physics::contact_point const &> *)j,
              &v12);
            boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
              v10,
              (int *)&v12);
          }
          boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
            v8,
            (int *)&f);
          boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
            v11,
            (int *)&v13);
          *(_DWORD *)(j + 44) = 0;
          *(_BYTE *)(j + 49) = 0;
          *((_BYTE *)channel_id + 65750) = 0;
          break;
        }
      }
      if ( !*((_WORD *)channel_id + 32874) )
        vostok::animation::animation_player::compact_callbacks(v5, (int)channel_id);
      return;
    }
  }
}
