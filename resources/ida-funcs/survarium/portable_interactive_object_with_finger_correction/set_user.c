void __thiscall survarium::portable_interactive_object_with_finger_correction::set_user(
        survarium::portable_interactive_object_with_finger_correction *this,
        survarium::base_player *user)
{
  vostok::animation::fingers_to_weapon_corrector *v3; // ecx

  survarium::portable_interactive_object::set_user(this, user);
  vostok::animation::fingers_to_weapon_corrector::initialize_bones_indices(
    v3,
    (int)&this->m_fingers_corrector,
    *(const vostok::animation::skeleton **)((char *)&dword_10E28 + (unsigned int)this->m_user));
}
