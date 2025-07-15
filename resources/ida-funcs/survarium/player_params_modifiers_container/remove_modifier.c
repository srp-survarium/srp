void __userpurge survarium::player_params_modifiers_container::remove_modifier(
        survarium::player_params_modifiers_container *this@<ecx>,
        survarium::player_params_modifiers_enum modifier_id@<eax>,
        survarium::player_params_modifier *modifier)
{
  survarium::player_params_modifiers_enum v3; // eax
  char *v4; // esi
  survarium::player_params_modifier *v5; // eax
  survarium::player_params_modifier *v6; // ecx
  survarium::player_params_modifier *next; // edx
  survarium::player_params_modifier *v8; // eax

  v3 = modifier_id;
  v4 = (char *)&this->m_modifiers + v3 * 48;
  if ( this->m_modifiers.elems[v3].m_first )
  {
    vostok::threading::mutex::lock(
      (vostok::threading::mutex *)this,
      (_RTL_CRITICAL_SECTION *)&this->m_modifiers.elems[v3].vostok::threading::mutex);
    v5 = (survarium::player_params_modifier *)*((_DWORD *)v4 + 9);
    v6 = 0;
    while ( v5 )
    {
      if ( v5 == modifier )
        goto LABEL_7;
      v6 = v5;
      v5 = v5->next;
    }
    if ( modifier )
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
        v8 = (survarium::player_params_modifier *)*((_DWORD *)v4 + 9);
      *((_DWORD *)v4 + 10) = v8;
    }
LABEL_14:
    LeaveCriticalSection((LPCRITICAL_SECTION)(v4 + 8));
  }
}
