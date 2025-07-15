void __thiscall survarium::portable_interactive_object::serialize(
        survarium::portable_interactive_object *this,
        vostok::network_core::buffer_writer *writer,
        vostok::network_core::buffer_writer *client_writer,
        vostok::network_core::buffer_writer *time_offset)
{
  vostok::animation::hand_to_weapon_ik_solver *v5; // ecx

  survarium::portable_interactive_object_core::serialize(this, writer, client_writer, (unsigned int)time_offset);
  vostok::animation::hand_to_weapon_ik_solver::serialize(
    v5,
    (const vostok::network_core::buffer_writer *)&this->m_hand_ik_solver,
    client_writer,
    time_offset);
}
