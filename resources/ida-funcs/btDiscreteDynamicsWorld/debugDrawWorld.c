void __thiscall btDiscreteDynamicsWorld::debugDrawWorld(btDiscreteDynamicsWorld *this)
{
  btIDebugDraw *v2; // eax
  int v3; // edi
  btTypedConstraint *v4; // eax
  btDiscreteDynamicsWorld *v5; // ecx
  btIDebugDraw *v6; // eax
  btIDebugDraw *v7; // eax
  int i; // edi
  btActionInterface *v9; // ecx

  btCollisionWorld::debugDrawWorld(this);
  if ( this->getDebugDrawer(this) )
  {
    v2 = this->getDebugDrawer(this);
    if ( (v2->getDebugMode(v2) & 0x1800) != 0 )
    {
      v3 = this->getNumConstraints(this);
      while ( --v3 >= 0 )
      {
        v4 = this->getConstraint(this, v3);
        btDiscreteDynamicsWorld::debugDrawConstraint(v5, (btTypedConstraint *)this, (int)v4);
      }
    }
  }
  if ( this->getDebugDrawer(this) )
  {
    v6 = this->getDebugDrawer(this);
    if ( (v6->getDebugMode(v6) & 3) != 0 )
    {
      if ( this->getDebugDrawer(this) )
      {
        v7 = this->getDebugDrawer(this);
        if ( v7->getDebugMode(v7) )
        {
          for ( i = 0; i < this->m_actions.m_size; ++i )
          {
            v9 = this->m_actions.m_data[i];
            v9->debugDraw(v9, this->m_debugDrawer);
          }
        }
      }
    }
  }
}
