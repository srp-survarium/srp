void __usercall boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        boost::function1<void,vostok::sound::create_sound_propagator_params const &> *this@<ecx>,
        int *a2@<esi>)
{
  int v2; // eax
  void (__cdecl *v3)(int *, int *, int); // eax

  v2 = *a2;
  if ( *a2 )
  {
    if ( (v2 & 1) == 0 )
    {
      v3 = *(void (__cdecl **)(int *, int *, int))(v2 & 0xFFFFFFFE);
      if ( v3 )
        v3(a2 + 2, a2 + 2, 2);
    }
    *a2 = 0;
  }
}
