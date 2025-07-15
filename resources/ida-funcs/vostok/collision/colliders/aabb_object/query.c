void __userpurge vostok::collision::colliders::aabb_object::query(
        vostok::collision::colliders::aabb_object *this@<ecx>,
        __int64 a2@<esi:edi>,
        vostok::collision::oct_node *node,
        float aabb_center,
        float aabb_extents)
{
  const vostok::math::aabb *m_aabb; // eax
  float v6; // xmm2_4
  float v7; // xmm6_4
  bool v8; // cc
  float v9; // xmm5_4
  float v10; // xmm4_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float z; // xmm7_4
  float v14; // xmm0_4
  vostok::collision::oct_node *v15; // ebx
  vostok::math::float3 *v16; // eax
  float v17; // xmm2_4
  float v18; // xmm3_4
  float v19; // xmm0_4
  vostok::collision::colliders::aabb_object *v20; // ecx
  vostok::buffer_vector<vostok::collision::object const *> *v21; // ecx
  vostok::buffer_vector<vostok::collision::object const *> aabb_extentsa; // [esp+0h] [ebp-30h]
  vostok::math::float3 aabb_centera; // [esp+14h] [ebp-1Ch] BYREF
  vostok::math::float3_pod left; // [esp+20h] [ebp-10h] BYREF
  vostok::collision::colliders::aabb_object *v25; // [esp+2Ch] [ebp-4h]

  m_aabb = this->m_aabb;
  *(_QWORD *)&aabb_extentsa.m_end = a2;
  *(float *)&a2 = aabb_center;
  v6 = *(float *)LODWORD(aabb_center);
  v7 = *(float *)LODWORD(aabb_center) - aabb_extents;
  v8 = v7 <= this->m_aabb->max.x;
  v25 = this;
  if ( v8 )
  {
    v9 = *(float *)(LODWORD(aabb_center) + 4) - aabb_extents;
    if ( v9 <= m_aabb->max.y )
    {
      v10 = *(float *)(LODWORD(aabb_center) + 8) - aabb_extents;
      if ( v10 <= m_aabb->max.z )
      {
        v11 = v6 + aabb_extents;
        if ( m_aabb->min.x <= v11 )
        {
          v12 = *(float *)(LODWORD(aabb_center) + 4) + aabb_extents;
          if ( m_aabb->min.y <= v12 )
          {
            z = m_aabb->min.z;
            v14 = *(float *)(LODWORD(aabb_center) + 8) + aabb_extents;
            if ( z <= v14 )
            {
              if ( v7 < m_aabb->min.x
                || v9 < m_aabb->min.y
                || v10 < z
                || m_aabb->max.x < v11
                || m_aabb->max.y < v12
                || m_aabb->max.z < v14 )
              {
                HIDWORD(a2) = node;
                aabb_center = aabb_extents * 0.5;
                aabb_extents = 0.0;
                do
                {
                  v15 = node->octants[0];
                  if ( node->octants[0] )
                  {
                    v16 = vostok::collision::octant_vector(
                            (vostok::math::float3 *)&left,
                            (vostok::math::float3 *)(SLODWORD(aabb_extents) >> 2));
                    v17 = v16->z * aabb_center;
                    v18 = *(float *)a2 + (float)(v16->x * aabb_center);
                    aabb_centera.y = *(float *)(a2 + 4) + (float)(v16->y * aabb_center);
                    v19 = *(float *)(a2 + 8) + v17;
                    aabb_centera.x = v18;
                    aabb_centera.z = v19;
                    vostok::collision::colliders::aabb_object::query(
                      v25,
                      a2,
                      v15,
                      COERCE_FLOAT(&aabb_centera),
                      SLODWORD(aabb_center));
                  }
                  node = (vostok::collision::oct_node *)((char *)node + 4);
                  LODWORD(aabb_extents) += 4;
                }
                while ( node != (vostok::collision::oct_node *)(HIDWORD(a2) + 32) );
                v20 = v25;
                LODWORD(a2) = *(_DWORD *)(HIDWORD(a2) + 36);
                if ( (_DWORD)a2 )
                {
                  while ( 1 )
                  {
                    if ( (*(_DWORD *)(a2 + 40) & v20->m_query_type) != 0 )
                    {
                      HIDWORD(a2) = v20->m_aabb;
                      LODWORD(left.x) = *(float *)(a2 + 4) <= v20->m_aabb->max.x
                                      ? *(_DWORD *)(a2 + 4)
                                      : LODWORD(v20->m_aabb->max.x);
                      LODWORD(left.y) = *(float *)(a2 + 8) <= *(float *)(HIDWORD(a2) + 16)
                                      ? *(_DWORD *)(a2 + 8)
                                      : *(_DWORD *)(HIDWORD(a2) + 16);
                      LODWORD(left.z) = *(float *)(a2 + 12) <= *(float *)(HIDWORD(a2) + 20)
                                      ? *(_DWORD *)(a2 + 12)
                                      : *(_DWORD *)(HIDWORD(a2) + 20);
                      if ( vostok::math::operator==((const vostok::math::float3_pod *)(a2 + 4), &left) )
                      {
                        LODWORD(aabb_centera.x) = *(float *)HIDWORD(a2) <= *(float *)(a2 + 16)
                                                ? *(_DWORD *)(a2 + 16)
                                                : *(_DWORD *)HIDWORD(a2);
                        LODWORD(aabb_centera.y) = *(float *)(HIDWORD(a2) + 4) <= *(float *)(a2 + 20)
                                                ? *(_DWORD *)(a2 + 20)
                                                : *(_DWORD *)(HIDWORD(a2) + 4);
                        LODWORD(aabb_centera.z) = *(float *)(HIDWORD(a2) + 8) <= *(float *)(a2 + 24)
                                                ? *(_DWORD *)(a2 + 24)
                                                : *(_DWORD *)(HIDWORD(a2) + 8);
                        if ( vostok::math::operator==((const vostok::math::float3_pod *)(a2 + 16), &aabb_centera) )
                        {
                          if ( v25->m_triangles )
                          {
                            (*(void (__thiscall **)(_DWORD, _DWORD, vostok::buffer_vector<vostok::collision::triangle_result> *const))(*(_DWORD *)a2 + 4))(
                              a2,
                              HIDWORD(a2),
                              v25->m_triangles);
                          }
                          else if ( (*(unsigned __int8 (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)a2 + 16))(
                                      a2,
                                      HIDWORD(a2)) )
                          {
                            HIDWORD(a2) = v25->m_objects;
                            node = (vostok::collision::oct_node *)a2;
                            vostok::buffer_vector<vostok::collision::object const *>::push_back(
                              v21,
                              SHIDWORD(a2),
                              (const vostok::collision::object **)&node);
                          }
                        }
                      }
                    }
                    LODWORD(a2) = *(_DWORD *)(a2 + 28);
                    if ( !(_DWORD)a2 )
                      break;
                    v20 = v25;
                  }
                }
              }
              else
              {
                aabb_extentsa.m_begin = (const vostok::collision::object **)node;
                if ( this->m_objects )
                  vostok::collision::colliders::aabb_object::add_objects(this, aabb_extentsa);
                else
                  vostok::collision::colliders::aabb_object::add_triangles(this, node);
              }
            }
          }
        }
      }
    }
  }
}
