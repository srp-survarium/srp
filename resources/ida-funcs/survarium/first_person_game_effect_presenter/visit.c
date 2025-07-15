void __thiscall survarium::first_person_game_effect_presenter::visit(
        survarium::first_person_game_effect_presenter *this,
        const survarium::hud_game_effect *effect,
        const survarium::game_effect_state *state)
{
  this->m_hud_presenter.visit(&this->m_hud_presenter, effect, state);
}


void __thiscall survarium::first_person_game_effect_presenter::visit(
        survarium::first_person_game_effect_presenter *this,
        const survarium::post_process_game_effect *effect,
        const survarium::game_effect_state *state)
{
  this->m_post_process_presenter.visit(&this->m_post_process_presenter, effect, state);
}


void __thiscall survarium::first_person_game_effect_presenter::visit(
        survarium::first_person_game_effect_presenter *this,
        const survarium::sound_game_effect *effect,
        const survarium::game_effect_state *state)
{
  this->m_sound_presenter.visit(&this->m_sound_presenter, effect, state);
}
