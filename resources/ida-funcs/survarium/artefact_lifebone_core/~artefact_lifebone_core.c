void __thiscall survarium::artefact_lifebone_core::~artefact_lifebone_core(survarium::artefact_lifebone_core *this)
{
  __int64 v2; // rax
  int v3; // ecx
  int v4; // eax
  int v5; // ebx
  int v6; // ebp
  survarium::artefact_base *v7; // ecx
  const char *v8; // [esp+0h] [ebp-14h]
  const char *v9; // [esp+4h] [ebp-10h]
  unsigned int v10; // [esp+8h] [ebp-Ch]

  this->__vftable = (survarium::artefact_lifebone_core_vtbl *)&survarium::artefact_lifebone_core::`vftable';
  v2 = (char *)this->m_config.passive.regeneration_modifiers._M_impl._M_finish
     - (char *)this->m_config.passive.regeneration_modifiers._M_impl._M_start;
  v3 = 52;
  v4 = v2 / 52;
  if ( v4 )
  {
    v5 = 0;
    v6 = v4;
    do
    {
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v3,
        (int *)&this->m_regeneration_modifier_subscribers[v5++]);
      --v6;
    }
    while ( v6 );
  }
  if ( this->m_regeneration_modifier_subscribers )
  {
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)v3,
      (int)survarium::g_allocator,
      (char *)this->m_regeneration_modifier_subscribers,
      v8,
      v9,
      v10);
    this->m_regeneration_modifier_subscribers = 0;
  }
  survarium::artefact_lifebone_core::config::~config((survarium::artefact_lifebone_core::config *)v3);
  survarium::artefact_base::~artefact_base(v7, (int)this);
}
