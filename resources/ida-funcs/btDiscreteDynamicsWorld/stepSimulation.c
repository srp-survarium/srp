int __thiscall btDiscreteDynamicsWorld::stepSimulation(
        btDiscreteDynamicsWorld *this,
        float timeStep,
        int maxSubSteps,
        float fixedTimeStep)
{
  int v4; // ebx
  int v5; // edi
  float v7; // xmm0_4
  btIDebugDraw *v8; // eax
  btDiscreteDynamicsWorld_vtbl *v9; // eax

  v4 = maxSubSteps;
  v5 = 0;
  if ( maxSubSteps )
  {
    v7 = this->m_localTime + timeStep;
    this->m_localTime = v7;
    if ( v7 >= fixedTimeStep )
    {
      v5 = (int)(float)(v7 / fixedTimeStep);
      this->m_localTime = v7 - (float)((float)v5 * fixedTimeStep);
    }
  }
  else
  {
    this->m_localTime = timeStep;
    fixedTimeStep = timeStep;
    if ( COERCE_FLOAT(LODWORD(timeStep) & _mask__AbsFloat_) >= 0.00000011920929 )
    {
      v4 = 1;
      v5 = 1;
    }
    else
    {
      v5 = 0;
      v4 = 0;
    }
  }
  if ( this->getDebugDrawer(this) )
  {
    v8 = this->getDebugDrawer(this);
    gDisableDeactivation = (v8->getDebugMode(v8) & 0x10) != 0;
  }
  v9 = this->__vftable;
  if ( v5 )
  {
    if ( v5 <= v4 )
      v4 = v5;
    ((void (__fastcall *)(btDiscreteDynamicsWorld *))v9->applyGravity)(this);
    if ( v4 > 0 )
    {
      do
      {
        ((void (__thiscall *)(btDiscreteDynamicsWorld *, _DWORD))this->internalSingleStepSimulation)(
          this,
          LODWORD(fixedTimeStep));
        this->synchronizeMotionStates(this);
        --v4;
      }
      while ( v4 );
    }
  }
  else
  {
    v9->synchronizeMotionStates(this);
  }
  this->clearForces(this);
  return v5;
}
