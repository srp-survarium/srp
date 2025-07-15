const char *__fastcall survarium::key_binder::dik_to_keyname(
        survarium::key_binder *a1,
        int _dik,
        survarium::key_binder *this)
{
  survarium::keyboard_key_descr *v3; // eax

  v3 = survarium::key_binder::dik_to_ptr(_dik, a1);
  if ( v3 )
    return v3->key_name;
  else
    return 0;
}
