void __usercall survarium::damage_model::subscribe_on_damage(
        survarium::damage_model *this@<ecx>,
        survarium::hit_type_enum damage_type@<eax>,
        survarium::damage_subscriber *const subscriber@<edi>)
{
  unsigned __int32 v3; // eax
  vostok::threading::mutex *v4; // ebx
  boost::array<vostok::intrusive_list<survarium::damage_subscriber,survarium::damage_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>,8> *v5; // esi

  v3 = 48 * damage_type;
  v4 = 0;
  v5 = (boost::array<vostok::intrusive_list<survarium::damage_subscriber,survarium::damage_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>,8> *)((char *)&this->m_damage_subscriptions + v3);
  subscriber->next = 0;
  if ( (survarium::damage_model *)((char *)this + v3) != (survarium::damage_model *)-1144 )
    v4 = &this->m_damage_subscriptions.elems[v3 / 0x30].vostok::threading::mutex;
  vostok::threading::mutex::lock((vostok::threading::mutex *)this, (_RTL_CRITICAL_SECTION *)v4);
  ++v5->elems[0].m_size;
  if ( v5->elems[0].m_first )
    v5->elems[0].m_last->next = subscriber;
  else
    v5->elems[0].m_first = subscriber;
  v5->elems[0].m_last = subscriber;
  LeaveCriticalSection((LPCRITICAL_SECTION)v4);
}
