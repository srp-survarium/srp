void __thiscall survarium::damage_model::dump_stats(
        survarium::damage_model *this,
        boost::function<void __cdecl(unsigned int,float,float,char const *)> callback)
{
  survarium::body_part_parameters *m_first; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> v3; // [esp-24h] [ebp-3Ch]
  survarium::body_part_parameters *body_part; // [esp+10h] [ebp-8h]
  unsigned int body_part_index; // [esp+14h] [ebp-4h]

  m_first = this->m_body_parts.m_first;
  body_part = m_first;
  body_part_index = 0;
  while ( body_part )
  {
    boost::function<void __cdecl (unsigned int,float,float,char const *)>::function<void __cdecl (unsigned int,float,float,char const *)>(&callback);
    survarium::body_part_parameters::dump_state(body_part, v3, body_part_index);
    m_first = (survarium::body_part_parameters *)++body_part_index;
    body_part = body_part->next;
  }
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)m_first,
    (int *)&callback);
}
