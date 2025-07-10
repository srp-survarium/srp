survarium::base_player *__usercall survarium::weapon_core::get_user@<eax>(
        survarium::weapon_core *this@<ecx>,
        int a2@<eax>)
{
  return *(survarium::base_player **)(a2 + 1100);
}
