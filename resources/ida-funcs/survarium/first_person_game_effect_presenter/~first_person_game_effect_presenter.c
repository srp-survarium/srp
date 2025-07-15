void __usercall survarium::first_person_game_effect_presenter::~first_person_game_effect_presenter(
        survarium::first_person_game_effect_presenter *this@<ecx>,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *a2@<edi>)
{
  survarium::hud_game_effect_presenter *v2; // ecx
  vostok::render::environment_properties *v3; // ecx

  survarium::sound_game_effect_presenter::~sound_game_effect_presenter(
    (survarium::sound_game_effect_presenter *)this,
    (int)&a2[205]);
  survarium::hud_game_effect_presenter::~hud_game_effect_presenter(v2, &a2[167].m_object);
  vostok::render::environment_properties::~environment_properties(v3, a2 + 3);
  a2[1].m_object = (vostok::particle::particle_system_instance_impl *)&survarium::base_game_effect_presenter::`vftable';
  a2->m_object = (vostok::particle::particle_system_instance_impl *)&survarium::base_game_effect_presenter::`vftable';
}
