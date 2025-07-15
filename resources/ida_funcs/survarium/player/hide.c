void __usercall survarium::player::hide(survarium::player *this@<ecx>, int a2@<eax>)
{
  byte_10F34[a2] = 0;
  survarium::player::remove_models_from_scene(this, a2);
}
