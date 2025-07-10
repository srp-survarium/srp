const btTypedConstraint *__thiscall btDiscreteDynamicsWorld::getConstraint(btDiscreteDynamicsWorld *this, int index)
{
  return this->m_constraints.m_data[index];
}
