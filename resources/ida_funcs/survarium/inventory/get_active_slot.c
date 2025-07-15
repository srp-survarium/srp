survarium::profile_slot_enum __usercall survarium::inventory::get_active_slot@<eax>(
        survarium::inventory *this@<ecx>,
        int a2@<eax>)
{
  return *(_DWORD *)(a2 + 340);
}
