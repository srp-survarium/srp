survarium::scheduler::record *__userpurge survarium::scheduler::register_object@<eax>(
        survarium::scheduler *this@<ecx>,
        int a2@<edx>,
        survarium::scheduler::identifier *identifier,
        boost::function<void __cdecl(unsigned int,unsigned int)> *callback,
        const bool active)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  stlp_std::reverse_iterator<survarium::scheduler::record *> *v6; // edi
  int v7; // eax
  survarium::scheduler::record *current; // eax
  int v9; // esi
  const stlp_std::__false_type *v11; // [esp+0h] [ebp-48h]
  unsigned int v12; // [esp+4h] [ebp-44h]
  bool v13; // [esp+8h] [ebp-40h]
  survarium::scheduler::record __that; // [esp+10h] [ebp-38h] BYREF

  *(_DWORD *)identifier |= 0x80000000;
  v5 = (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)*identifier;
  v6 = *(stlp_std::reverse_iterator<survarium::scheduler::record *> **)(a2 + 4 * (*(unsigned int *)identifier >> 31) + 32);
  v7 = v6[1].current - v6->current;
  __that.m_callback.vtable = 0;
  *identifier = (survarium::scheduler::identifier)((unsigned int)v5 ^ ((unsigned int)v5 ^ v7) & 0x7FFFFFFF);
  current = v6[1].current;
  if ( current == v6[3].current )
  {
    stlp_std::priv::_Impl_vector<survarium::scheduler::record,vostok::vectora_allocator<survarium::scheduler::record>>::_M_insert_overflow_aux(
      (stlp_std::priv::_Impl_vector<survarium::scheduler::record,vostok::vectora_allocator<survarium::scheduler::record> > *)&__that,
      v6,
      current,
      &__that,
      v11,
      v12,
      v13);
  }
  else
  {
    if ( current )
      survarium::scheduler::record::record(&__that, v6[1].current);
    ++v6[1].current;
  }
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v5,
    (int *)&__that.m_callback);
  v9 = (int)&v6[1].current[-1];
  *(_DWORD *)v9 = identifier;
  boost::function<void __cdecl (unsigned int,unsigned int)>::operator=(
    callback,
    (boost::function1<void,vostok::physics::contact_point const &> *)(v9 + 8));
  return (survarium::scheduler::record *)v9;
}
