survarium::keyboard_key_descr *__usercall survarium::key_binder::dik_to_ptr@<eax>(
        int _dik@<edx>,
        survarium::key_binder *this)
{
  int v2; // eax
  int v3; // ecx

  v2 = 0;
  if ( !survarium::keyboards[0].key_name )
    return 0;
  v3 = 0;
  while ( dword_9C4224[v3] != _dik )
  {
    ++v2;
    v3 = 34 * v2;
    if ( !survarium::keyboards[v2].key_name )
      return 0;
  }
  return &survarium::keyboards[v2];
}
