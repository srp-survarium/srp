void __thiscall btDiscreteDynamicsWorld::updateActivationState(btDiscreteDynamicsWorld *this, float timeStep, float a3)
{
  btCollisionObject *v3; // ecx
  int v4; // esi
  int v5; // eax
  int v6; // edx
  int v7; // eax
  int i; // [esp+Ch] [ebp-24h]
  btVector3 v9; // [esp+10h] [ebp-20h] BYREF
  int v10; // [esp+20h] [ebp-10h]
  int v11; // [esp+24h] [ebp-Ch]
  int v12; // [esp+28h] [ebp-8h]
  int v13; // [esp+2Ch] [ebp-4h]

  for ( i = 0; i < *(_DWORD *)(LODWORD(timeStep) + 208); ++i )
  {
    v3 = (btCollisionObject *)i;
    v4 = *(_DWORD *)(*(_DWORD *)(LODWORD(timeStep) + 216) + 4 * i);
    if ( v4 )
    {
      v5 = *(_DWORD *)(v4 + 228);
      v6 = 2;
      if ( v5 != 2 && v5 != 4 )
      {
        if ( (float)(*(float *)(v4 + 492) * *(float *)(v4 + 492)) <= (float)((float)((float)(*(float *)(v4 + 328)
                                                                                           * *(float *)(v4 + 328))
                                                                                   + (float)(*(float *)(v4 + 320)
                                                                                           * *(float *)(v4 + 320)))
                                                                           + (float)(*(float *)(v4 + 324)
                                                                                   * *(float *)(v4 + 324)))
          || (float)(*(float *)(v4 + 496) * *(float *)(v4 + 496)) <= (float)((float)((float)(*(float *)(v4 + 336)
                                                                                           * *(float *)(v4 + 336))
                                                                                   + (float)(*(float *)(v4 + 340)
                                                                                           * *(float *)(v4 + 340)))
                                                                           + (float)(*(float *)(v4 + 344)
                                                                                   * *(float *)(v4 + 344))) )
        {
          *(_DWORD *)(v4 + 232) = 0;
          btCollisionObject::setActivationState((btCollisionObject *)i, v4, 0);
        }
        else
        {
          *(float *)(v4 + 232) = *(float *)(v4 + 232) + a3;
        }
      }
      v7 = *(_DWORD *)(v4 + 228);
      if ( v7 != 4 )
      {
        if ( !gDisableDeactivation && (v7 == v6 || v7 == 3 || *(float *)(v4 + 232) > 2.0) )
        {
          if ( (*(_BYTE *)(v4 + 216) & 3) != 0 )
          {
            btCollisionObject::setActivationState(v3, v4, v6);
          }
          else
          {
            if ( v7 == 1 )
              btCollisionObject::setActivationState(v3, v4, 3);
            if ( *(_DWORD *)(v4 + 228) == v6 )
            {
              memset(&v9, 0, sizeof(v9));
              btRigidBody::setAngularVelocity((btRigidBody *)v4, &v9);
              v10 = 0;
              v11 = 0;
              v12 = 0;
              v13 = 0;
              *(_DWORD *)(v4 + 320) = 0;
              *(_DWORD *)(v4 + 324) = v11;
              *(_DWORD *)(v4 + 328) = v12;
              *(_DWORD *)(v4 + 332) = v13;
            }
          }
        }
        else
        {
          btCollisionObject::setActivationState(v3, v4, 1);
        }
      }
    }
  }
}
