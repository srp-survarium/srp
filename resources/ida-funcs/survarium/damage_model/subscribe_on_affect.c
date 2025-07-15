void __usercall survarium::damage_model::subscribe_on_affect(
        survarium::damage_model *this@<ecx>,
        const survarium::hit_affects_type_enum affect_type@<eax>,
        survarium::affect_subscriber *const subscriber@<edi>)
{
  unsigned __int32 v3; // eax
  vostok::threading::mutex *v4; // ebx
  boost::array<vostok::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>,9> *v5; // esi

  v3 = 48 * affect_type;
  v4 = 0;
  v5 = (boost::array<vostok::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>,9> *)((char *)&this->m_affect_subscriptions + v3);
  subscriber->next = 0;
  if ( (survarium::damage_model *)((char *)this + v3) != (survarium::damage_model *)-280 )
    v4 = &this->m_affect_subscriptions.elems[v3 / 0x30].vostok::threading::mutex;
  vostok::threading::mutex::lock((vostok::threading::mutex *)this, (_RTL_CRITICAL_SECTION *)v4);
  ++v5->elems[0].m_size;
  if ( v5->elems[0].m_first )
    v5->elems[0].m_last->next = subscriber;
  else
    v5->elems[0].m_first = subscriber;
  v5->elems[0].m_last = subscriber;
  LeaveCriticalSection((LPCRITICAL_SECTION)v4);
}
