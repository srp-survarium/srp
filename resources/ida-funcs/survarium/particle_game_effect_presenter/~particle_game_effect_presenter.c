void __usercall survarium::particle_game_effect_presenter::~particle_game_effect_presenter(
        survarium::particle_game_effect_presenter *this@<ecx>,
        int a2@<esi>)
{
  vostok::buffer_vector<survarium::particle_game_effect_presenter::effect_data>::destroy(
    *(survarium::particle_game_effect_presenter::effect_data **)(a2 + 68),
    (survarium::particle_game_effect_presenter::effect_data *const *)(a2 + 72));
  *(_DWORD *)(a2 + 72) = *(_DWORD *)(a2 + 68);
  vostok::buffer_vector<survarium::particle_game_effect_presenter::effect_data>::destroy(
    *(survarium::particle_game_effect_presenter::effect_data **)(a2 + 8),
    (survarium::particle_game_effect_presenter::effect_data *const *)(a2 + 12));
  *(_DWORD *)(a2 + 12) = *(_DWORD *)(a2 + 8);
  *(_DWORD *)a2 = &survarium::base_game_effect_presenter::`vftable';
}
