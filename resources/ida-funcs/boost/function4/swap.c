void __userpurge boost::function4<void,char const *,enum survarium::hit_type_enum,float &,float &>::swap(
        boost::function1<void,vostok::physics::contact_point const &> *other@<eax>,
        boost::function1<void,vostok::physics::contact_point const &> *this)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  boost::function1<void,vostok::physics::contact_point const &> v4; // [esp+8h] [ebp-24h] BYREF

  if ( other != this )
  {
    v4.vtable = 0;
    boost::function1<fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>,unsigned char>::move_assign(
      &v4,
      this);
    boost::function1<fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>,unsigned char>::move_assign(
      this,
      other);
    boost::function1<fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>,unsigned char>::move_assign(
      other,
      &v4);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v3,
      (int *)&v4);
  }
}
