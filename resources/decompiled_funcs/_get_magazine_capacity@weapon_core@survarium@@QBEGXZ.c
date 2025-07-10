unsigned __int16 __usercall survarium::weapon_core::get_magazine_capacity@<ax>(
        survarium::weapon_core *this@<ecx>,
        int a2@<eax>)
{
  return *(_WORD *)(a2 + 1144);
}
