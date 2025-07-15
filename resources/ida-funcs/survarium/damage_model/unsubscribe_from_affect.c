void __userpurge survarium::damage_model::unsubscribe_from_affect(
        survarium::damage_model *this@<ecx>,
        survarium::hit_affects_type_enum affect_type@<eax>,
        survarium::affect_subscriber *const subscriber)
{
  survarium::hit_affects_type_enum v3; // eax
  char *v4; // esi
  survarium::affect_subscriber *v5; // eax
  survarium::affect_subscriber *v6; // ecx
  survarium::affect_subscriber *next; // edx
  survarium::affect_subscriber *v8; // eax

  v3 = affect_type;
  v4 = (char *)&this->m_affect_subscriptions + v3 * 48;
  if ( this->m_affect_subscriptions.elems[v3].m_first )
  {
    vostok::threading::mutex::lock(
      (vostok::threading::mutex *)this,
      (_RTL_CRITICAL_SECTION *)&this->m_affect_subscriptions.elems[v3].vostok::threading::mutex);
    v5 = (survarium::affect_subscriber *)*((_DWORD *)v4 + 9);
    v6 = 0;
    while ( v5 )
    {
      if ( v5 == subscriber )
        goto LABEL_7;
      v6 = v5;
      v5 = v5->next;
    }
    if ( subscriber )
      goto LABEL_14;
LABEL_7:
    --*(_DWORD *)v4;
    next = v5->next;
    if ( v6 )
      v6->next = next;
    else
      *((_DWORD *)v4 + 9) = next;
    if ( !v5->next )
    {
      v8 = v6;
      if ( !v6 )
        v8 = (survarium::affect_subscriber *)*((_DWORD *)v4 + 9);
      *((_DWORD *)v4 + 10) = v8;
    }
LABEL_14:
    LeaveCriticalSection((LPCRITICAL_SECTION)(v4 + 8));
  }
}
