void __thiscall btCollisionWorld::debugDrawWorld(btCollisionWorld *this)
{
  btIDebugDraw *v2; // eax
  btPersistentManifold *v3; // eax
  float *p_m_distance1; // esi
  int m_cachedPoints; // edi
  btIDebugDraw *v6; // eax
  btIDebugDraw *v7; // eax
  btCollisionObject *v8; // esi
  btIDebugDraw *v9; // eax
  int v10; // esi
  int v11; // esi
  int v12; // esi
  int v13; // esi
  int *v14; // esi
  btCollisionWorld_vtbl *v15; // edx
  int *v16; // esi
  btCollisionShape *v17; // ecx
  bool v18; // zf
  float v19; // xmm0_4
  bool v20; // cc
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  float v24; // xmm4_4
  float v25; // xmm5_4
  const btCollisionShape *m_collisionShape; // [esp+28h] [ebp-F8h]
  int v27; // [esp+48h] [ebp-D8h]
  int i; // [esp+48h] [ebp-D8h]
  int v29; // [esp+4Ch] [ebp-D4h]
  btCollisionObject *v30; // [esp+4Ch] [ebp-D4h]
  float v31; // [esp+50h] [ebp-D0h] BYREF
  float v32; // [esp+54h] [ebp-CCh]
  float v33; // [esp+58h] [ebp-C8h]
  float v34; // [esp+5Ch] [ebp-C4h]
  float v35; // [esp+60h] [ebp-C0h] BYREF
  float v36; // [esp+64h] [ebp-BCh]
  float v37; // [esp+68h] [ebp-B8h]
  float v38; // [esp+6Ch] [ebp-B4h]
  float v39; // [esp+70h] [ebp-B0h]
  float v40; // [esp+74h] [ebp-ACh]
  float v41; // [esp+78h] [ebp-A8h]
  int v42; // [esp+80h] [ebp-A0h] BYREF
  int v43; // [esp+84h] [ebp-9Ch]
  int v44; // [esp+88h] [ebp-98h]
  int v45; // [esp+8Ch] [ebp-94h]
  float v46; // [esp+90h] [ebp-90h] BYREF
  float v47; // [esp+94h] [ebp-8Ch]
  float v48; // [esp+98h] [ebp-88h]
  float v49; // [esp+9Ch] [ebp-84h]
  float v50; // [esp+A0h] [ebp-80h] BYREF
  float v51; // [esp+A4h] [ebp-7Ch]
  float v52; // [esp+A8h] [ebp-78h]
  float v53; // [esp+ACh] [ebp-74h]
  _DWORD v54[4]; // [esp+B0h] [ebp-70h] BYREF
  _DWORD v55[4]; // [esp+C0h] [ebp-60h] BYREF
  _DWORD v56[4]; // [esp+D0h] [ebp-50h] BYREF
  _DWORD v57[4]; // [esp+E0h] [ebp-40h] BYREF
  _DWORD v58[4]; // [esp+F0h] [ebp-30h] BYREF
  _DWORD v59[4]; // [esp+100h] [ebp-20h] BYREF
  _DWORD v60[4]; // [esp+110h] [ebp-10h] BYREF

  if ( this->getDebugDrawer(this) )
  {
    v2 = this->getDebugDrawer(this);
    if ( (v2->getDebugMode(v2) & 8) != 0 )
    {
      v27 = 0;
      v29 = this->m_dispatcher1->getNumManifolds(this->m_dispatcher1);
      v42 = 0;
      v43 = 0;
      v44 = 0;
      v45 = 0;
      if ( v29 > 0 )
      {
        do
        {
          v3 = this->m_dispatcher1->getManifoldByIndexInternal(this->m_dispatcher1, v27);
          if ( v3->m_cachedPoints > 0 )
          {
            p_m_distance1 = &v3->m_pointCache[0].m_distance1;
            m_cachedPoints = v3->m_cachedPoints;
            do
            {
              v6 = this->getDebugDrawer(this);
              ((void (__thiscall *)(btIDebugDraw *, int, int, _DWORD, _DWORD, _DWORD *))v6->drawContactPoint)(
                v6,
                (const btVector3 *)(p_m_distance1 - 12),
                (const btVector3 *)(p_m_distance1 - 4),
                *p_m_distance1,
                *((_DWORD *)p_m_distance1 + 16),
                (const btVector3 *)&v42);
              p_m_distance1 += 72;
              --m_cachedPoints;
            }
            while ( m_cachedPoints );
          }
          ++v27;
        }
        while ( v27 < v29 );
      }
    }
  }
  if ( this->getDebugDrawer(this) )
  {
    v7 = this->getDebugDrawer(this);
    if ( (v7->getDebugMode(v7) & 3) != 0 )
    {
      for ( i = 0; i < this->m_collisionObjects.m_size; ++i )
      {
        v8 = this->m_collisionObjects.m_data[i];
        v30 = v8;
        if ( (v8->m_collisionFlags & 0x20) == 0 )
        {
          if ( this->getDebugDrawer(this) )
          {
            v9 = this->getDebugDrawer(this);
            if ( (v9->getDebugMode(v9) & 1) != 0 )
            {
              v10 = v8->m_activationState1 - 1;
              if ( v10 )
              {
                v11 = v10 - 1;
                if ( v11 )
                {
                  v12 = v11 - 1;
                  if ( v12 )
                  {
                    v13 = v12 - 1;
                    if ( v13 )
                    {
                      if ( v13 == 1 )
                      {
                        *(float *)v59 = s_aim_transition_time;
                        *(float *)&v59[1] = s_aim_transition_time;
                        v59[2] = 0;
                        v59[3] = 0;
                        v14 = v59;
                      }
                      else
                      {
                        *(float *)v57 = s_bm_current_air_resistance;
                        memset(&v57[1], 0, 12);
                        v14 = v57;
                      }
                    }
                    else
                    {
                      *(float *)v54 = s_aim_transition_time;
                      memset(&v54[1], 0, 12);
                      v14 = v54;
                    }
                  }
                  else
                  {
                    v55[0] = 0;
                    *(float *)&v55[1] = s_aim_transition_time;
                    *(float *)&v55[2] = s_aim_transition_time;
                    v55[3] = 0;
                    v14 = v55;
                  }
                }
                else
                {
                  v56[0] = 0;
                  *(float *)&v56[1] = s_aim_transition_time;
                  v56[2] = 0;
                  v56[3] = 0;
                  v14 = v56;
                }
              }
              else
              {
                *(float *)v58 = s_aim_transition_time;
                *(float *)&v58[1] = s_aim_transition_time;
                *(float *)&v58[2] = s_aim_transition_time;
                v58[3] = 0;
                v14 = v58;
              }
              v15 = this->__vftable;
              v42 = *v14;
              v16 = v14 + 1;
              v43 = *v16++;
              m_collisionShape = v30->m_collisionShape;
              v44 = *v16;
              v45 = v16[1];
              v15->debugDrawObject(this, &v30->m_worldTransform, m_collisionShape, (const btVector3 *)&v42);
              v8 = v30;
            }
          }
          if ( this->m_debugDrawer && (this->m_debugDrawer->getDebugMode(this->m_debugDrawer) & 2) != 0 )
          {
            v17 = v8->m_collisionShape;
            *(float *)v60 = s_bm_current_air_resistance;
            memset(&v60[1], 0, 12);
            v17->getAabb(v17, &v8->m_worldTransform, (btVector3 *)&v35, (btVector3 *)&v31);
            v18 = v8->m_internalType == 2;
            v35 = v35 - gContactBreakingThreshold;
            v36 = v36 - gContactBreakingThreshold;
            v37 = v37 - gContactBreakingThreshold;
            v31 = gContactBreakingThreshold + v31;
            v32 = v32 + gContactBreakingThreshold;
            v39 = gContactBreakingThreshold;
            v40 = gContactBreakingThreshold;
            v41 = gContactBreakingThreshold;
            v33 = v33 + gContactBreakingThreshold;
            if ( v18 )
            {
              v8->m_collisionShape->getAabb(
                v8->m_collisionShape,
                &v8->m_interpolationWorldTransform,
                (btVector3 *)&v50,
                (btVector3 *)&v46);
              v19 = v50 - v39;
              v20 = v35 <= (float)(v50 - v39);
              v21 = v51 - v40;
              v22 = v52 - v41;
              v23 = v46 + v39;
              v24 = v47 + v40;
              v25 = v48 + v41;
              v50 = v50 - v39;
              v51 = v51 - v40;
              v52 = v52 - v41;
              v46 = v46 + v39;
              v47 = v47 + v40;
              v48 = v48 + v41;
              if ( !v20 )
                v35 = v19;
              if ( v36 > v21 )
                v36 = v21;
              if ( v37 > v22 )
                v37 = v22;
              if ( v38 > v53 )
                v38 = v53;
              if ( v23 > v31 )
                v31 = v23;
              if ( v24 > v32 )
                v32 = v24;
              if ( v25 > v33 )
                v33 = v25;
              if ( v49 > v34 )
                v34 = v49;
            }
            this->m_debugDrawer->drawAabb(
              this->m_debugDrawer,
              (const btVector3 *)&v35,
              (const btVector3 *)&v31,
              (const btVector3 *)v60);
          }
        }
      }
    }
  }
}
