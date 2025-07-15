void __usercall survarium::player::show(survarium::player *this@<ecx>, int a2@<eax>)
{
  byte_10F34[a2] = 1;
  survarium::player::add_models_to_scene(this, a2);
}
