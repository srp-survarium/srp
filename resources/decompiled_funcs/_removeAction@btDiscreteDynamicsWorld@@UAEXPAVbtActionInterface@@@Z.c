void __thiscall btDiscreteDynamicsWorld::removeAction(btDiscreteDynamicsWorld *this, btActionInterface *action)
{
  btAlignedObjectArray<btSoftBody::Joint *>::remove(
    (btAlignedObjectArray<btSoftBody *> *)this,
    (int)&this->m_actions,
    (btSoftBody *const *)&action);
}
