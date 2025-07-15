void __thiscall survarium::sound_game_effect::accept(
        survarium::sound_game_effect *this,
        survarium::base_game_effect_presenter *presenter,
        const survarium::game_effect_state *state)
{
  ((void (__thiscall *)(survarium::base_game_effect_presenter *, survarium::sound_game_effect *, const survarium::game_effect_state *))presenter->__vftable[1].~survarium::base_game_effect_presenter)(
    presenter,
    this,
    state);
}
