void __thiscall vostok::physics::bullet_character_controller::insert(
        vostok::physics::bullet_character_controller *this,
        btDynamicsWorld *world,
        btStackAlloc *a3)
{
  int m_worldUserInfo_low; // [esp-8h] [ebp-14h]
  int m_worldUserInfo_high; // [esp-4h] [ebp-10h]

  m_worldUserInfo_high = HIWORD(world[6].m_worldUserInfo);
  m_worldUserInfo_low = LOWORD(world[6].m_worldUserInfo);
  *(_DWORD *)&world->m_collisionObjects.m_ownsMemory = a3;
  (*((void (__thiscall **)(btStackAlloc *, void **, int, int))a3->data + 7))(
    a3,
    &world->m_worldUserInfo,
    m_worldUserInfo_low,
    m_worldUserInfo_high);
  btCollisionWorld::updateSingleAabb(
    *(btCollisionWorld **)&world->m_collisionObjects.m_ownsMemory,
    (btCollisionObject *)&world->m_worldUserInfo);
  (*(void (__thiscall **)(_DWORD, btDynamicsWorld *))(**(_DWORD **)&world->m_collisionObjects.m_ownsMemory + 56))(
    *(_DWORD *)&world->m_collisionObjects.m_ownsMemory,
    world);
  LODWORD(world[3].m_dispatchInfo.m_timeOfImpact) = a3;
  world[4].m_stackAlloc = a3;
  LODWORD(world[4].m_solverInfo.m_erp2) = a3;
  world[5].m_dispatcher1 = (btDispatcher *)a3;
  world[5].m_internalTickCallback = (void (__cdecl *)(btDynamicsWorld *, float))a3;
  LODWORD(world[5].m_solverInfo.m_sor) = a3;
  world[6].m_dispatcher1 = (btDispatcher *)a3;
  world[6].m_internalTickCallback = (void (__cdecl *)(btDynamicsWorld *, float))a3;
}
