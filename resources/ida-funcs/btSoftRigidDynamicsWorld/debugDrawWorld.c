void __thiscall btSoftRigidDynamicsWorld::debugDrawWorld(btSoftRigidDynamicsWorld *this)
{
  int i; // ebp
  btSoftBody *v3; // edi
  btIDebugDraw *v4; // eax

  btDiscreteDynamicsWorld::debugDrawWorld(this);
  if ( this->getDebugDrawer(this) )
  {
    for ( i = 0; i < this->m_softBodies.m_size; ++i )
    {
      v3 = this->m_softBodies.m_data[i];
      if ( this->getDebugDrawer(this) )
      {
        v4 = this->getDebugDrawer(this);
        if ( (v4->getDebugMode(v4) & 1) != 0 )
        {
          btSoftBodyHelpers::DrawFrame(v3, this->m_debugDrawer);
          btSoftBodyHelpers::Draw(0.0, (int)v3, (int)this, v3, this->m_debugDrawer, this->m_drawFlags);
        }
      }
      if ( this->m_debugDrawer && (this->m_debugDrawer->getDebugMode(this->m_debugDrawer) & 2) != 0 )
      {
        if ( this->m_drawNodeTree )
          btSoftBodyHelpers::DrawNodeTree(v3, this->m_debugDrawer);
        if ( this->m_drawFaceTree )
          btSoftBodyHelpers::DrawFaceTree(v3, this->m_debugDrawer);
        if ( this->m_drawClusterTree )
          btSoftBodyHelpers::DrawClusterTree(v3, this->m_debugDrawer);
      }
    }
  }
}
