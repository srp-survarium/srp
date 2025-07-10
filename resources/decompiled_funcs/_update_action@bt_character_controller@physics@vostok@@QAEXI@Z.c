void __usercall vostok::physics::bt_character_controller::update_action(
        vostok::physics::bt_character_controller *this@<eax>,
        const unsigned int time_delta_in_ms@<esi>)
{
  float v2; // [esp+0h] [ebp-8h]

  v2 = (double)time_delta_in_ms * 0.001;
  ((void (__stdcall *)(btSoftRigidDynamicsWorld *, _DWORD))this->m_bt_controller->updateAction)(
    this->m_bt_physics_world->m_dynamicsWorld,
    LODWORD(v2));
}
