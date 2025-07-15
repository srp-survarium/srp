BOOL __userpurge survarium::damage_model::hit_body_part@<eax>(
        survarium::damage_model *this@<esi>,
        survarium::bullet *const bullet@<edi>,
        survarium::damage_model *a3@<ecx>,
        char *part_name,
        survarium::hit_type_enum damage_type,
        float damage,
        float armor_piercing,
        float *current_time_in_ms,
        const char *orientation)
{
  double invulnerability; // st7
  boost::function4<void,char const *,enum survarium::hit_type_enum,float &,float &> *v11; // ecx
  survarium::body_part_parameters *m_last_hitted_body_part; // ecx
  survarium::body_part_parameters *m_first; // eax
  survarium::base_player *m_owner; // ecx
  float v15; // xmm1_4
  survarium::body_part_parameters *v16; // eax
  unsigned __int8 i; // cl
  unsigned __int8 v18; // al
  float m_max_damage_dealt; // xmm0_4
  _DWORD v21[4]; // [esp+4h] [ebp-14h] BYREF
  float v22; // [esp+14h] [ebp-4h] BYREF
  survarium::body_part_parameters *a1; // [esp+24h] [ebp+Ch]

  a1 = survarium::damage_model::get_body_part(a3, (int)this, part_name);
  invulnerability = survarium::damage_model::get_invulnerability(this);
  damage = (1.0 - invulnerability) * damage;
  boost::function4<void,char const *,enum survarium::hit_type_enum,float &,float &>::operator()(
    v11,
    &this->m_damage_protector.reduce_incoming_damage_functor.vtable,
    part_name,
    damage_type,
    &damage,
    &armor_piercing);
  v22 = damage;
  if ( bullet
    && (LOBYTE(m_last_hitted_body_part) = bullet->m_last_hitted_player,
        (_BYTE)m_last_hitted_body_part == this->m_owner->id) )
  {
    m_first = this->m_body_parts.m_first;
    m_last_hitted_body_part = (survarium::body_part_parameters *)bullet->m_last_hitted_body_part;
    if ( bullet->m_last_hitted_body_part )
    {
      do
      {
        m_last_hitted_body_part = (survarium::body_part_parameters *)((char *)m_last_hitted_body_part - 1);
        m_first = m_first->next;
      }
      while ( m_last_hitted_body_part );
    }
  }
  else
  {
    m_first = 0;
  }
  survarium::body_part_parameters::hit_by_type(
    m_last_hitted_body_part,
    (survarium::affects_threshold *)a1,
    (survarium::hit_type_parameters *)damage_type,
    current_time_in_ms,
    &damage,
    &armor_piercing,
    (const survarium::body_part_parameters *const)&v22,
    m_first,
    orientation);
  v15 = damage;
  if ( bullet )
  {
    v16 = this->m_body_parts.m_first;
    for ( i = 0; ; ++i )
    {
      if ( !v16 )
      {
        v18 = -1;
        goto LABEL_13;
      }
      if ( v16 == a1 )
        break;
      v16 = v16->next;
    }
    v18 = i;
LABEL_13:
    m_owner = this->m_owner;
    LOBYTE(m_owner) = m_owner->id;
    m_max_damage_dealt = bullet->m_max_damage_dealt;
    bullet->m_last_hitted_player = (unsigned __int8)m_owner;
    bullet->m_last_hitted_body_part = v18;
    if ( m_max_damage_dealt <= v15 )
      m_max_damage_dealt = v15;
    bullet->m_max_damage_dealt = m_max_damage_dealt;
    bullet->m_damage = v22;
  }
  v21[0] = part_name;
  v21[2] = current_time_in_ms;
  *(float *)&v21[1] = v15;
  v21[3] = bullet;
  ___for_each_Udamage_subscribers_functor__1__notify_subscribers_on_damage_damage_model_survarium__AAEXQBDW4hit_type_enum_4_MIPBVbullet_4__Z____intrusive_list_Udamage_subscriber_survarium__PAU12__0CA_Vmutex_threading_vostok__Vsize_policy_5_Vno_debug_policy_5__vostok__QBEXABUdamage_subscribers_functor__1__notify_subscribers_on_damage_damage_model_survarium__AAEXQBDW4hit_type_enum_5_MIPBVbullet_5__Z__Z(
    (vostok::intrusive_list<survarium::damage_subscriber,survarium::damage_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)m_owner,
    (int)&this->m_damage_subscriptions.elems[damage_type],
    (const survarium::damage_model::notify_subscribers_on_damage::__l2::damage_subscribers_functor *)v21);
  return damage > 0.0;
}
