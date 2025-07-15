void __usercall survarium::player_creation_params::player_creation_params(
        survarium::player_creation_params *this@<ecx>,
        const float *a2@<esi>)
{
  survarium::base_player_creation_params::base_player_creation_params(this, (int)a2, a2);
  a2[111] = 0.0;
  a2[112] = 0.0;
  a2[115] = 0.0;
  memset((void *)(a2 + 116), 0, 0x18u);
  a2[122] = 0.0;
  a2[123] = 0.0;
  a2[124] = 0.0;
  memset((void *)(a2 + 125), 0, 0x24u);
  memset((void *)(a2 + 134), 0, 0x24u);
  a2[143] = 0.0;
}
