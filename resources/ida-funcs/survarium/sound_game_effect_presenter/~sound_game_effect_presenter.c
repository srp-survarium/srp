void __usercall survarium::sound_game_effect_presenter::~sound_game_effect_presenter(
        survarium::sound_game_effect_presenter *this@<ecx>,
        int a2@<esi>)
{
  vostok::buffer_vector<survarium::sound_game_effect_presenter::effect_data>::destroy(
    *(survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> **)(a2 + 224),
    (survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> **)(a2 + 228));
  *(_DWORD *)(a2 + 228) = *(_DWORD *)(a2 + 224);
  vostok::buffer_vector<survarium::sound_game_effect_presenter::effect_data>::destroy(
    *(survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> **)(a2 + 20),
    (survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> **)(a2 + 24));
  *(_DWORD *)(a2 + 24) = *(_DWORD *)(a2 + 20);
  *(_DWORD *)a2 = &survarium::base_game_effect_presenter::`vftable';
}
