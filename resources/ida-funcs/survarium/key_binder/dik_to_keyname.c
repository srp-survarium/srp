const char *__thiscall survarium::key_binder::dik_to_keyname(survarium::key_binder *this, int _dik)
{
  int v2; // ecx
  int v3; // eax
  survarium::keyboard_key_descr *v4; // ecx

  v2 = 0;
  if ( survarium::keyboards[0].key_name )
  {
    v3 = 0;
    while ( dword_88370C[v3] != _dik )
    {
      ++v2;
      v3 = 34 * v2;
      if ( !survarium::keyboards[v2].key_name )
        goto LABEL_5;
    }
    v4 = &survarium::keyboards[v2];
  }
  else
  {
LABEL_5:
    v4 = 0;
  }
  if ( v4 )
    return v4->key_name;
  else
    return 0;
}
