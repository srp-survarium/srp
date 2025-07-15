survarium::particle_game_effect_presenter::effect_data *__userpurge survarium::particle_game_effect_presenter::effect_data::operator=@<eax>(
        survarium::particle_game_effect_presenter::effect_data *this@<ecx>,
        survarium::particle_game_effect_presenter::effect_data *a2@<esi>,
        const survarium::particle_game_effect_presenter::effect_data *__that)
{
  survarium::loose_ptr_data *m_object; // eax
  survarium::loose_ptr_data *v4; // ecx
  survarium::loose_ptr_data *v5; // eax
  survarium::particle_game_effect_presenter::effect_data *result; // eax

  m_object = 0;
  if ( __that->effect.m_object )
  {
    m_object = __that->effect.m_object;
    ++__that->effect.m_object->m_reference_count;
  }
  v4 = m_object;
  v5 = a2->effect.m_object;
  a2->effect.m_object = v4;
  if ( v5 )
  {
    if ( v5->m_reference_count-- == 1 )
      survarium::loose_ptr_data::destroy<survarium::loose_ptr_data>(
        (survarium::loose_ptr_data *)v5->m_reference_count,
        v5);
  }
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&__that->particle_system,
    &a2->particle_system);
  a2->time_to_finish = __that->time_to_finish;
  result = a2;
  a2->time = __that->time;
  return result;
}
