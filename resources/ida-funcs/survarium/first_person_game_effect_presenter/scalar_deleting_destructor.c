survarium::first_person_game_effect_presenter *__thiscall survarium::first_person_game_effect_presenter::`scalar deleting destructor'(
        survarium::first_person_game_effect_presenter *this,
        char a2)
{
  survarium::first_person_game_effect_presenter::~first_person_game_effect_presenter(
    this,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
