const char *__thiscall survarium::booby_trap_core::use_info(
        survarium::booby_trap_core *this,
        const survarium::usable_object_user_data *user)
{
  bool v2; // zf
  const char *result; // eax

  v2 = ((unsigned __int8 (__thiscall *)(survarium::booby_trap_core *, const survarium::usable_object_user_data *))this->hit)(
         this,
         user) == 0;
  result = "st_defuse_trap";
  if ( v2 )
    return uri;
  return result;
}
