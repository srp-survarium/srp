void __thiscall survarium::portable_interactive_object_with_finger_correction::process_finger_correction(
        survarium::portable_interactive_object_with_finger_correction *this,
        vostok::math::float4x4 *current_time_in_ms,
        vostok::math::float4x4 *const user_matrices)
{
  bool is_first_view; // al
  vostok::animation::fingers_to_weapon_corrector *p_m_fingers_corrector; // esi
  vostok::animation::fingers_to_weapon_corrector *p_m_first_person_view; // ecx

  is_first_view = survarium::player::is_first_view((survarium::player *)this, (int)this->m_user);
  p_m_fingers_corrector = &this->m_fingers_corrector;
  p_m_first_person_view = (vostok::animation::fingers_to_weapon_corrector *)&p_m_fingers_corrector->m_first_person_view;
  if ( p_m_fingers_corrector->m_first_person_view != is_first_view )
  {
    LOBYTE(p_m_first_person_view->m_hands[0].phalanges_matrices[0][0].i.x) = is_first_view;
    vostok::animation::fingers_to_weapon_corrector::initialize_locators(
      p_m_first_person_view,
      (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)p_m_fingers_corrector,
      (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&p_m_fingers_corrector->m_item_model,
      is_first_view);
  }
  vostok::animation::fingers_to_weapon_corrector::process(
    p_m_first_person_view,
    (const unsigned int)p_m_fingers_corrector,
    current_time_in_ms,
    *(float *)&user_matrices);
}
