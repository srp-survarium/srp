btGhostObject *__usercall btGhostObject::btGhostObject@<eax>(btGhostObject *this@<ecx>, btCollisionObject *a2@<eax>)
{
  btGhostObject *result; // eax

  result = (btGhostObject *)btCollisionObject::btCollisionObject(this, a2);
  result->__vftable = (btGhostObject_vtbl *)&btGhostObject::`vftable';
  result->m_overlappingObjects.m_ownsMemory = 1;
  result->m_overlappingObjects.m_data = 0;
  result->m_overlappingObjects.m_size = 0;
  result->m_overlappingObjects.m_capacity = 0;
  result->m_internalType = 4;
  return result;
}
