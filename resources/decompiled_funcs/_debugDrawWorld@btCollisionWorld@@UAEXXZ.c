void __thiscall btCollisionWorld::debugDrawWorld(btCollisionWorld *this)
{
  btIDebugDraw *v2; // eax
  int v3; // esi
  btPersistentManifold *v4; // eax
  int m_cachedPoints; // ebx
  float *p_m_distance1; // esi
  btIDebugDraw *v7; // eax
  btIDebugDraw *v8; // eax
  int i; // ebx
  btCollisionObject *v10; // esi
  btIDebugDraw *v11; // eax
  __m128i v12; // xmm0
  void (__thiscall *debugDrawObject)(btCollisionWorld *, const btTransform *, const btCollisionShape *, const btVector3 *); // edx
  btCollisionShape *v14; // ecx
  bool v15; // zf
  float v16; // xmm0_4
  float v17; // xmm3_4
  float v18; // xmm1_4
  float v19; // xmm4_4
  float v20; // xmm2_4
  float v21; // xmm5_4
  bool v22; // cc
  btCollisionShape *m_collisionShape; // [esp+670h] [ebp-108h]
  float v24; // [esp+688h] [ebp-F0h] BYREF
  float v25; // [esp+68Ch] [ebp-ECh]
  float v26; // [esp+690h] [ebp-E8h]
  float v27; // [esp+694h] [ebp-E4h]
  float v28; // [esp+698h] [ebp-E0h] BYREF
  float v29; // [esp+69Ch] [ebp-DCh]
  float v30; // [esp+6A0h] [ebp-D8h]
  float v31; // [esp+6A4h] [ebp-D4h]
  int v32; // [esp+6B4h] [ebp-C4h]
  float v33; // [esp+6B8h] [ebp-C0h] BYREF
  float v34; // [esp+6BCh] [ebp-BCh]
  float v35; // [esp+6C0h] [ebp-B8h]
  int v36; // [esp+6C4h] [ebp-B4h]
  float v37; // [esp+6C8h] [ebp-B0h] BYREF
  float v38; // [esp+6CCh] [ebp-ACh]
  float v39; // [esp+6D0h] [ebp-A8h]
  float v40; // [esp+6D4h] [ebp-A4h]
  int v41; // [esp+6E4h] [ebp-94h]
  float v42; // [esp+6E8h] [ebp-90h] BYREF
  float v43; // [esp+6ECh] [ebp-8Ch]
  float v44; // [esp+6F0h] [ebp-88h]
  float v45; // [esp+6F4h] [ebp-84h]
  __m128i v46; // [esp+6F8h] [ebp-80h] BYREF
  __m128i v47; // [esp+708h] [ebp-70h] BYREF
  __m128i v48; // [esp+718h] [ebp-60h] BYREF
  __m128i v49; // [esp+728h] [ebp-50h] BYREF
  __m128i v50; // [esp+738h] [ebp-40h] BYREF
  __m128i v51; // [esp+748h] [ebp-30h] BYREF
  __m128i v52; // [esp+758h] [ebp-20h] BYREF
  _DWORD v53[4]; // [esp+768h] [ebp-10h] BYREF

  if ( this->getDebugDrawer(this) )
  {
    v2 = this->getDebugDrawer(this);
    if ( (v2->getDebugMode(v2) & 8) != 0 )
    {
      v3 = 0;
      v41 = this->m_dispatcher1->getNumManifolds(this->m_dispatcher1);
      v33 = 0.0;
      v34 = 0.0;
      v35 = 0.0;
      v36 = 0;
      v32 = 0;
      if ( v41 > 0 )
      {
        do
        {
          v4 = this->m_dispatcher1->getManifoldByIndexInternal(this->m_dispatcher1, v3);
          m_cachedPoints = v4->m_cachedPoints;
          if ( m_cachedPoints > 0 )
          {
            p_m_distance1 = &v4->m_pointCache[0].m_distance1;
            do
            {
              v7 = this->getDebugDrawer(this);
              ((void (__thiscall *)(btIDebugDraw *, int, int, _DWORD, _DWORD, float *))v7->drawContactPoint)(
                v7,
                (const btVector3 *)(p_m_distance1 - 12),
                (const btVector3 *)(p_m_distance1 - 4),
                *p_m_distance1,
                *((_DWORD *)p_m_distance1 + 16),
                (const btVector3 *)&v33);
              p_m_distance1 += 72;
              --m_cachedPoints;
            }
            while ( m_cachedPoints );
            v3 = v32;
          }
          v32 = ++v3;
        }
        while ( v3 < v41 );
      }
    }
  }
  if ( this->getDebugDrawer(this) )
  {
    v8 = this->getDebugDrawer(this);
    if ( (v8->getDebugMode(v8) & 3) != 0 )
    {
      for ( i = 0; i < this->m_collisionObjects.m_size; ++i )
      {
        v10 = this->m_collisionObjects.m_data[i];
        if ( (v10->m_collisionFlags & 0x20) == 0 )
        {
          if ( this->getDebugDrawer(this) )
          {
            v11 = this->getDebugDrawer(this);
            if ( (v11->getDebugMode(v11) & 1) != 0 )
            {
              switch ( v10->m_activationState1 )
              {
                case 1:
                  *(float *)v52.m128i_i32 = s_aim_transition_time;
                  *(float *)&v52.m128i_i32[1] = s_aim_transition_time;
                  v52.m128i_i64[1] = LODWORD(s_aim_transition_time);
                  v12 = _mm_load_si128(&v52);
                  break;
                case 2:
                  v47.m128i_i32[0] = 0;
                  *(float *)&v47.m128i_i32[1] = s_aim_transition_time;
                  v47.m128i_i64[1] = 0;
                  v12 = _mm_load_si128(&v47);
                  break;
                case 3:
                  v50.m128i_i32[0] = 0;
                  *(float *)&v50.m128i_i32[1] = s_aim_transition_time;
                  v50.m128i_i64[1] = LODWORD(s_aim_transition_time);
                  v12 = _mm_load_si128(&v50);
                  break;
                case 4:
                  v48.m128i_i64[0] = LODWORD(s_aim_transition_time);
                  v48.m128i_i64[1] = 0;
                  v12 = _mm_load_si128(&v48);
                  break;
                case 5:
                  *(float *)v49.m128i_i32 = s_aim_transition_time;
                  *(float *)&v49.m128i_i32[1] = s_aim_transition_time;
                  v49.m128i_i64[1] = 0;
                  v12 = _mm_load_si128(&v49);
                  break;
                default:
                  v51.m128i_i64[0] = (unsigned int)clear_value;
                  v51.m128i_i64[1] = 0;
                  v12 = _mm_load_si128(&v51);
                  break;
              }
              debugDrawObject = this->debugDrawObject;
              m_collisionShape = v10->m_collisionShape;
              v46 = v12;
              debugDrawObject(this, &v10->m_worldTransform, m_collisionShape, (const btVector3 *)&v46);
            }
          }
          if ( this->m_debugDrawer && (this->m_debugDrawer->getDebugMode(this->m_debugDrawer) & 2) != 0 )
          {
            v14 = v10->m_collisionShape;
            v53[0] = clear_value;
            memset(&v53[1], 0, 12);
            v14->getAabb(v14, &v10->m_worldTransform, (btVector3 *)&v28, (btVector3 *)&v24);
            v15 = v10->m_internalType == 2;
            v33 = gContactBreakingThreshold;
            v28 = v28 - gContactBreakingThreshold;
            v24 = gContactBreakingThreshold + v24;
            v29 = v29 - gContactBreakingThreshold;
            v25 = v25 + gContactBreakingThreshold;
            v34 = gContactBreakingThreshold;
            v35 = gContactBreakingThreshold;
            v30 = v30 - gContactBreakingThreshold;
            v26 = v26 + gContactBreakingThreshold;
            if ( v15 )
            {
              v10->m_collisionShape->getAabb(
                v10->m_collisionShape,
                &v10->m_interpolationWorldTransform,
                (btVector3 *)&v42,
                (btVector3 *)&v37);
              v16 = v42 - v33;
              v17 = v37 + v33;
              v18 = v43 - v34;
              v19 = v38 + v34;
              v20 = v44 - v35;
              v21 = v39 + v35;
              v22 = v28 <= (float)(v42 - v33);
              v42 = v42 - v33;
              v43 = v43 - v34;
              v44 = v44 - v35;
              v37 = v37 + v33;
              v38 = v38 + v34;
              v39 = v39 + v35;
              if ( !v22 )
                v28 = v16;
              if ( v29 > v18 )
                v29 = v18;
              if ( v30 > v20 )
                v30 = v20;
              if ( v31 > v45 )
                v31 = v45;
              if ( v17 > v24 )
                v24 = v17;
              if ( v19 > v25 )
                v25 = v19;
              if ( v21 > v26 )
                v26 = v21;
              if ( v40 > v27 )
                v27 = v40;
            }
            this->m_debugDrawer->drawAabb(
              this->m_debugDrawer,
              (const btVector3 *)&v28,
              (const btVector3 *)&v24,
              (const btVector3 *)v53);
          }
        }
      }
    }
  }
}
