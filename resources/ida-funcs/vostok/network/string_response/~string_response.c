void __thiscall vostok::network::string_response::~string_response(vostok::network::string_response *this)
{
  char *m_string0; // eax
  vostok::memory::base_allocator *allocator; // ecx
  char *m_string1; // eax
  char *m_string2; // eax
  vostok::memory::base_allocator *v6; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v7; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // ecx

  m_string0 = this->m_string0;
  allocator = this->allocator;
  this->__vftable = (vostok::network::string_response_vtbl *)&vostok::network::string_response::`vftable';
  if ( m_string0 )
    allocator->call_free(
      allocator,
      m_string0,
      "vostok::network::string_response::~string_response",
      "c:\\survarium.deploy\\sources\\vostok\\network\\sources\\string_response.h",
      52u);
  m_string1 = this->m_string1;
  if ( m_string1 )
    this->allocator->call_free(
      this->allocator,
      m_string1,
      "vostok::network::string_response::~string_response",
      "c:\\survarium.deploy\\sources\\vostok\\network\\sources\\string_response.h",
      55u);
  m_string2 = this->m_string2;
  v6 = this->allocator;
  if ( m_string2 )
    v6->call_free(
      v6,
      m_string2,
      "vostok::network::string_response::~string_response",
      "c:\\survarium.deploy\\sources\\vostok\\network\\sources\\string_response.h",
      58u);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v6,
    (int *)&this->m_functor2);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v7,
    (int *)&this->m_functor1);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v8,
    (int *)&this->m_functor0);
  this->__vftable = (vostok::network::string_response_vtbl *)&vostok::network::response::`vftable';
}
