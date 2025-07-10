int __usercall survarium::key_binder::action_name_to_id@<eax>(
        const char *_name@<eax>,
        survarium::key_binder *a2@<ecx>,
        survarium::key_binder *this)
{
  survarium::game_action_descr *v3; // eax

  v3 = survarium::key_binder::action_name_to_ptr(a2, _name);
  if ( v3 )
    return v3->id;
  else
    return 65;
}
