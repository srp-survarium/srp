void __thiscall vostok::physics::old_bullet_character_controller::insert(
        vostok::physics::old_bullet_character_controller *this,
        btDynamicsWorld *world)
{
  int m_stepCount_high; // [esp-8h] [ebp-14h]
  int m_dispatchFunc_low; // [esp-4h] [ebp-10h]

  m_dispatchFunc_low = LOWORD(world[3].m_dispatchInfo.m_dispatchFunc);
  m_stepCount_high = HIWORD(world[3].m_dispatchInfo.m_stepCount);
  *(_DWORD *)&world->m_collisionObjects.m_ownsMemory = this;
  ((void (__thiscall *)(vostok::physics::old_bullet_character_controller *, int *, int, int))this->btActionInterface::__vftable[2].updateAction)(
    this,
    &world->m_solverInfo.m_solverMode,
    m_stepCount_high,
    m_dispatchFunc_low);
  btCollisionWorld::updateSingleAabb(
    *(btCollisionWorld **)&world->m_collisionObjects.m_ownsMemory,
    (btCollisionObject *)&world->m_solverInfo.m_solverMode);
  (*(void (__thiscall **)(_DWORD, btDynamicsWorld *))(**(_DWORD **)&world->m_collisionObjects.m_ownsMemory + 56))(
    *(_DWORD *)&world->m_collisionObjects.m_ownsMemory,
    world);
  world[28].m_dispatcher1 = *(btDispatcher **)&world->m_collisionObjects.m_ownsMemory;
}
