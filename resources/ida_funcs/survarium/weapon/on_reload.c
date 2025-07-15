void __thiscall survarium::weapon::on_reload(survarium::weapon *this)
{
  survarium::weapon::set_ui_ammo(this, (int)this, 1);
}
