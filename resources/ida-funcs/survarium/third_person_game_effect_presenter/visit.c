void __thiscall survarium::third_person_game_effect_presenter::visit(
        survarium::third_person_game_effect_presenter *this,
        const survarium::particle_game_effect *effect,
        const survarium::game_effect_state *state)
{
  this->m_particle_presenter.visit(&this->m_particle_presenter, effect, state);
}


void __thiscall survarium::third_person_game_effect_presenter::visit(
        survarium::third_person_game_effect_presenter *this,
        const survarium::sound_game_effect *effect,
        const survarium::game_effect_state *state)
{
  this->m_sound_presenter.visit(&this->m_sound_presenter, effect, state);
}
