void __usercall survarium::hud_game_effect_presenter::~hud_game_effect_presenter(
        survarium::hud_game_effect_presenter *this@<ecx>,
        survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> **a2@<esi>)
{
  vostok::buffer_vector<survarium::hud_game_effect_presenter::effect_data> *v2; // ecx

  vostok::buffer_vector<survarium::hud_game_effect_presenter::effect_data>::clear(
    (vostok::buffer_vector<survarium::hud_game_effect_presenter::effect_data> *)this,
    a2 + 20);
  vostok::buffer_vector<survarium::hud_game_effect_presenter::effect_data>::clear(v2, a2 + 2);
  *a2 = (survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *)&survarium::base_game_effect_presenter::`vftable';
}
