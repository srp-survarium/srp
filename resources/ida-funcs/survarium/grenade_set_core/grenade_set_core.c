void __usercall survarium::grenade_set_core::grenade_set_core(
        survarium::grenade_set_core *this@<ecx>,
        _DWORD *a2@<eax>)
{
  survarium::inventory_item::inventory_item(&this->survarium::inventory_item, (int)a2, use_silent, 1);
  *a2 = &survarium::grenade_set_core::`vftable';
  a2[72] = 0;
  a2[73] = 0;
  a2[74] = 0;
  a2[75] = 0;
}
