vostok::ai::percept_memory_object *__thiscall vostok::ai::working_memory::get_oldest_object(
        vostok::ai::working_memory *this)
{
  vostok::ai::percept_memory_object *m_first; // [esp+0h] [ebp-24h]
  vostok::ai::percept_memory_object *v3; // [esp+4h] [ebp-20h]
  vostok::ai::working_memory *iter; // [esp+1Ch] [ebp-8h]
  vostok::ai::percept_memory_object *result; // [esp+20h] [ebp-4h]

  result = 0;
  for ( iter = this;
        iter != (vostok::ai::working_memory *)&this->m_subscription;
        iter = (vostok::ai::working_memory *)((char *)iter + 48) )
  {
    if ( iter->m_percept_objects.elems[0].m_first )
    {
      if ( result )
      {
        if ( result->update_time >= iter->m_percept_objects.elems[0].m_first->update_time )
          m_first = iter->m_percept_objects.elems[0].m_first;
        else
          m_first = result;
        v3 = m_first;
      }
      else
      {
        v3 = iter->m_percept_objects.elems[0].m_first;
      }
      result = v3;
    }
  }
  return result;
}
