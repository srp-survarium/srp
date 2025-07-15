void __userpurge vostok::collision::colliders::ray_object::query<vostok::collision::colliders::object::vertical_predicate<1>>(
        vostok::collision::colliders::ray_object *this@<ecx>,
        bool a2@<bl>,
        const stlp_std::__true_type *a3@<edi>,
        unsigned int a4@<esi>,
        const vostok::collision::oct_node *const node,
        const vostok::math::float3 *aabb_center,
        float aabb_extents,
        const vostok::collision::colliders::object::vertical_predicate<1> *predicate)
{
  const vostok::collision::oct_node *v9; // edx
  float v10; // xmm6_4
  float v11; // xmm1_4
  const vostok::collision::oct_node *v12; // esi
  float v13; // xmm0_4
  const vostok::collision::oct_node *v14; // ecx
  int v15; // eax
  float v16; // xmm3_4
  float v17; // xmm2_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  const vostok::collision::object *i; // edi
  float v23; // xmm3_4
  float v24; // xmm0_4
  float v25; // xmm2_4
  float x; // xmm7_4
  float v27; // xmm4_4
  float v28; // xmm5_4
  float v29; // xmm3_4
  float v30; // xmm0_4
  float v31; // xmm2_4
  float v32; // xmm4_4
  float v33; // xmm5_4
  float z; // xmm1_4
  float y; // xmm0_4
  float v36; // xmm1_4
  bool (__thiscall *ray_query)(vostok::collision::object *, const vostok::math::float3 *, const vostok::math::float3 *, float, float *, vostok::vectora<vostok::collision::ray_triangle_result> *, const fastdelegate::FastDelegate<bool __cdecl(vostok::collision::ray_triangle_result const &)> *); // eax
  bool (__thiscall *ray_test)(vostok::collision::object *, const vostok::math::float3 *, const vostok::math::float3 *, float, float *); // edx
  stlp_std::priv::_Impl_vector<vostok::collision::ray_object_result,vostok::vectora_allocator<vostok::collision::ray_object_result> > *v39; // ecx
  vostok::vectora<vostok::collision::ray_object_result> *m_objects; // esi
  float *M_finish; // eax
  float distance; // ecx
  float v43; // [esp+A8h] [ebp-60h]
  vostok::vectora<vostok::collision::ray_triangle_result> *m_triangles; // [esp+B0h] [ebp-58h]
  const stlp_std::__true_type *v45; // [esp+B8h] [ebp-50h]
  unsigned int v46; // [esp+BCh] [ebp-4Ch]
  bool v47; // [esp+C0h] [ebp-48h]
  float v48; // [esp+C4h] [ebp-44h] BYREF
  float v49[6]; // [esp+C8h] [ebp-40h] BYREF
  float v50; // [esp+E0h] [ebp-28h]
  float m_max_distance; // [esp+E4h] [ebp-24h]
  vostok::collision::ray_object_result __x; // [esp+E8h] [ebp-20h] BYREF
  vostok::math::float3 extents; // [esp+F0h] [ebp-18h] BYREF
  float v54; // [esp+100h] [ebp-8h]
  float v55; // [esp+104h] [ebp-4h]

  v47 = a2;
  v46 = a4;
  v45 = a3;
  extents.x = aabb_extents;
  extents.y = aabb_extents;
  extents.z = aabb_extents;
  if ( vostok::collision::colliders::ray_aabb_collider::intersects_aabb_vertical(
         &this->m_ray_aabb_collider,
         aabb_center,
         &extents,
         v49)
    && v49[0] <= this->m_max_distance )
  {
    v9 = node;
    v10 = FLOAT_0_5;
    v11 = aabb_extents * 0.5;
    v49[0] = aabb_extents * 0.5;
    v12 = node;
    v13 = *(float *)&clear_value;
    v48 = 0.0;
    do
    {
      v14 = v12->octants[0];
      if ( v12->octants[0] )
      {
        v15 = SLODWORD(v48) >> 2;
        if ( ((SLODWORD(v48) >> 2) & 4) != 0 )
          v16 = v13;
        else
          v16 = -1.0;
        if ( (v15 & 2) != 0 )
          v17 = v13;
        else
          v17 = -1.0;
        if ( (v15 & 1) == 0 )
          v13 = -1.0;
        v18 = v17 * v11;
        v19 = v16 * v11;
        v20 = aabb_center->x + (float)(v13 * v11);
        extents.y = aabb_center->y + v18;
        v21 = aabb_center->z + v19;
        extents.x = v20;
        extents.z = v21;
        vostok::collision::colliders::ray_object::query<vostok::collision::colliders::object::vertical_predicate<1>>(
          this,
          v14,
          &extents,
          v49[0],
          predicate);
        v11 = v49[0];
        v13 = *(float *)&clear_value;
        v10 = FLOAT_0_5;
        v9 = node;
      }
      LODWORD(v48) += 4;
      v12 = (const vostok::collision::oct_node *)((char *)v12 + 4);
    }
    while ( v12 != (const vostok::collision::oct_node *)&v9->parent );
    for ( i = v9->objects; i; i = i->m_next )
    {
      if ( (i->m_type & this->m_query_type) != 0 )
      {
        v23 = i->m_aabb.max.x + i->m_aabb.min.x;
        v24 = i->m_aabb.max.x - i->m_aabb.min.x;
        v25 = i->m_aabb.max.z - i->m_aabb.min.z;
        x = this->m_ray_aabb_collider.m_origin.x;
        v27 = i->m_aabb.max.y + i->m_aabb.min.y;
        v28 = i->m_aabb.max.z + i->m_aabb.min.z;
        v54 = (float)(i->m_aabb.max.y - i->m_aabb.min.y) * v10;
        v29 = v23 * v10;
        v30 = v24 * v10;
        v31 = v25 * v10;
        v55 = v31;
        v32 = v27 * v10;
        v33 = v28 * v10;
        if ( x <= (float)(v29 + v30) )
        {
          v49[0] = v33 + v31;
          z = this->m_ray_aabb_collider.m_origin.z;
          if ( z <= (float)(v33 + v31) && (float)(v29 - v30) <= x && (float)(v33 - v55) <= z )
          {
            y = this->m_ray_aabb_collider.m_origin.y;
            v36 = v32 + v54;
            if ( y < (float)(v32 + v54) )
            {
              if ( (float)(v32 - v54) < y )
              {
                v48 = 0.0;
                goto LABEL_28;
              }
              if ( this->m_ray_aabb_collider.m_direction.y > 0.0 )
              {
                v50 = v32 - (float)(y + v54);
                v48 = fabs(v50);
                goto LABEL_28;
              }
            }
            else if ( this->m_ray_aabb_collider.m_direction.y < 0.0 )
            {
              v49[5] = y - v36;
              v48 = fabs(y - v36);
LABEL_28:
              if ( this->m_objects )
              {
                ray_test = i->ray_test;
                m_max_distance = this->m_max_distance;
                v48 = m_max_distance;
                if ( ((unsigned __int8 (__thiscall *)(const vostok::collision::object *, vostok::collision::colliders::ray_object *, vostok::math::float3 *, _DWORD, float *))ray_test)(
                       i,
                       this,
                       &this->m_ray_aabb_collider.m_direction,
                       LODWORD(m_max_distance),
                       &v48) )
                {
                  m_objects = this->m_objects;
                  M_finish = (float *)m_objects->_M_impl._M_finish;
                  __x.object = i;
                  __x.distance = v48;
                  if ( M_finish == (float *)m_objects->_M_impl._M_end_of_storage._M_data )
                  {
                    stlp_std::priv::_Impl_vector<vostok::resources::request,vostok::vectora_allocator<vostok::resources::request>>::_M_insert_overflow(
                      v39,
                      (unsigned __int8 **)m_objects,
                      (int)M_finish,
                      &__x,
                      v45,
                      v46,
                      v47);
                  }
                  else
                  {
                    if ( M_finish )
                    {
                      distance = __x.distance;
                      *(_DWORD *)M_finish = i;
                      M_finish[1] = distance;
                    }
                    ++m_objects->_M_impl._M_finish;
                  }
                }
              }
              else
              {
                ray_query = i->ray_query;
                m_triangles = this->m_triangles;
                v43 = this->m_max_distance;
                *(_QWORD *)&extents.x = __PAIR64__(
                                          vostok::collision::colliders::ray_object::false_triangle_predicate,
                                          (unsigned int)this);
                ((void (__thiscall *)(const vostok::collision::object *, vostok::collision::colliders::ray_object *, vostok::math::float3 *, _DWORD, float *, vostok::vectora<vostok::collision::ray_triangle_result> *, vostok::math::float3 *))ray_query)(
                  i,
                  this,
                  &this->m_ray_aabb_collider.m_direction,
                  LODWORD(v43),
                  &v48,
                  m_triangles,
                  &extents);
              }
              v10 = FLOAT_0_5;
            }
          }
        }
      }
    }
  }
}


void __userpurge vostok::collision::colliders::ray_object::query<vostok::collision::colliders::object::vertical_predicate<0>>(
        vostok::collision::colliders::ray_object *this@<ecx>,
        bool a2@<bl>,
        const stlp_std::__true_type *a3@<edi>,
        unsigned int a4@<esi>,
        const vostok::collision::oct_node *const node,
        const vostok::math::float3 *aabb_center,
        float aabb_extents,
        const vostok::collision::colliders::object::vertical_predicate<0> *predicate)
{
  const vostok::collision::oct_node *v9; // edx
  float v10; // xmm0_4
  float v11; // xmm1_4
  const vostok::collision::oct_node *v12; // esi
  const vostok::math::float4x4 *v13; // xmm4_4
  const vostok::collision::oct_node *v14; // ecx
  int v15; // eax
  float v16; // xmm3_4
  float v17; // xmm2_4
  float v18; // xmm0_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  const vostok::collision::object *i; // edi
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm3_4
  float v27; // xmm4_4
  float v28; // xmm5_4
  float v29; // xmm6_4
  bool (__thiscall *ray_query)(vostok::collision::object *, const vostok::math::float3 *, const vostok::math::float3 *, float, float *, vostok::vectora<vostok::collision::ray_triangle_result> *, const fastdelegate::FastDelegate<bool __cdecl(vostok::collision::ray_triangle_result const &)> *); // edx
  bool (__thiscall *ray_test)(vostok::collision::object *, const vostok::math::float3 *, const vostok::math::float3 *, float, float *); // eax
  stlp_std::priv::_Impl_vector<vostok::collision::ray_object_result,vostok::vectora_allocator<vostok::collision::ray_object_result> > *v32; // ecx
  vostok::vectora<vostok::collision::ray_object_result> *m_objects; // esi
  float *M_finish; // eax
  float distance; // ecx
  float m_max_distance; // [esp+108h] [ebp-80h]
  vostok::vectora<vostok::collision::ray_triangle_result> *m_triangles; // [esp+110h] [ebp-78h]
  const stlp_std::__true_type *v38; // [esp+118h] [ebp-70h]
  unsigned int v39; // [esp+11Ch] [ebp-6Ch]
  bool v40; // [esp+120h] [ebp-68h]
  float v41; // [esp+124h] [ebp-64h] BYREF
  float v42[6]; // [esp+128h] [ebp-60h] BYREF
  vostok::collision::ray_object_result __x; // [esp+140h] [ebp-48h] BYREF
  _DWORD v44[2]; // [esp+148h] [ebp-40h] BYREF
  __int64 v45; // [esp+150h] [ebp-38h]
  float v46; // [esp+158h] [ebp-30h]
  vostok::math::float3 extents; // [esp+15Ch] [ebp-2Ch] BYREF
  vostok::collision::colliders::sse::aabb_a16 aabb; // [esp+168h] [ebp-20h] BYREF

  v40 = a2;
  v39 = a4;
  v38 = a3;
  extents.x = aabb_extents;
  extents.y = aabb_extents;
  extents.z = aabb_extents;
  if ( vostok::collision::colliders::ray_object::intersects_aabb(this, aabb_center, &extents, v42)
    && v42[0] <= this->m_max_distance )
  {
    v9 = node;
    v10 = FLOAT_0_5;
    v11 = aabb_extents * 0.5;
    v42[0] = aabb_extents * 0.5;
    v12 = node;
    v13 = clear_value;
    v41 = 0.0;
    do
    {
      v14 = v12->octants[0];
      if ( v12->octants[0] )
      {
        v15 = SLODWORD(v41) >> 2;
        if ( ((SLODWORD(v41) >> 2) & 4) != 0 )
          v16 = *(float *)&v13;
        else
          v16 = -1.0;
        if ( (v15 & 2) != 0 )
          v17 = *(float *)&v13;
        else
          v17 = -1.0;
        if ( (v15 & 1) != 0 )
          v18 = *(float *)&v13;
        else
          v18 = -1.0;
        v19 = v17 * v11;
        v20 = v16 * v11;
        v21 = aabb_center->x + (float)(v18 * v11);
        extents.y = aabb_center->y + v19;
        v22 = aabb_center->z + v20;
        extents.x = v21;
        extents.z = v22;
        vostok::collision::colliders::ray_object::query<vostok::collision::colliders::object::vertical_predicate<0>>(
          this,
          v14,
          &extents,
          v42[0],
          predicate);
        v11 = v42[0];
        v13 = clear_value;
        v10 = FLOAT_0_5;
        v9 = node;
      }
      LODWORD(v41) += 4;
      v12 = (const vostok::collision::oct_node *)((char *)v12 + 4);
    }
    while ( v12 != (const vostok::collision::oct_node *)&v9->parent );
    for ( i = v9->objects; i; i = i->m_next )
    {
      if ( (i->m_type & this->m_query_type) != 0 )
      {
        v24 = (float)(i->m_aabb.max.x - i->m_aabb.min.x) * v10;
        v25 = (float)(i->m_aabb.max.y - i->m_aabb.min.y) * v10;
        v26 = (float)(i->m_aabb.max.z - i->m_aabb.min.z) * v10;
        v27 = (float)(i->m_aabb.max.x + i->m_aabb.min.x) * v10;
        v28 = (float)(i->m_aabb.max.y + i->m_aabb.min.y) * v10;
        v29 = (float)(i->m_aabb.max.z + i->m_aabb.min.z) * v10;
        *(float *)&v45 = v27 - v24;
        *((float *)&v45 + 1) = v28 - v25;
        v46 = v29 - v26;
        extents.z = v29 + v26;
        *(_QWORD *)&aabb.min.x = v45;
        extents.x = v27 + v24;
        extents.y = v28 + v25;
        aabb.max.z = v29 + v26;
        aabb.min.z = v29 - v26;
        aabb.min.padding = 0.0;
        *(_QWORD *)&aabb.max.x = *(_QWORD *)&extents.x;
        aabb.max.padding = 0.0;
        if ( vostok::collision::colliders::ray_aabb_collider::intersects_aabb_sse(
               &this->m_ray_aabb_collider,
               &aabb,
               &v41) )
        {
          if ( this->m_objects )
          {
            ray_test = i->ray_test;
            v42[0] = this->m_max_distance;
            v41 = v42[0];
            if ( ((unsigned __int8 (__thiscall *)(const vostok::collision::object *, vostok::collision::colliders::ray_object *, vostok::math::float3 *, _DWORD, float *))ray_test)(
                   i,
                   this,
                   &this->m_ray_aabb_collider.m_direction,
                   LODWORD(v42[0]),
                   &v41) )
            {
              m_objects = this->m_objects;
              M_finish = (float *)m_objects->_M_impl._M_finish;
              __x.object = i;
              __x.distance = v41;
              if ( M_finish == (float *)m_objects->_M_impl._M_end_of_storage._M_data )
              {
                stlp_std::priv::_Impl_vector<vostok::resources::request,vostok::vectora_allocator<vostok::resources::request>>::_M_insert_overflow(
                  v32,
                  (unsigned __int8 **)m_objects,
                  (int)M_finish,
                  &__x,
                  v38,
                  v39,
                  v40);
              }
              else
              {
                if ( M_finish )
                {
                  distance = __x.distance;
                  *(_DWORD *)M_finish = i;
                  M_finish[1] = distance;
                }
                ++m_objects->_M_impl._M_finish;
              }
            }
          }
          else
          {
            ray_query = i->ray_query;
            m_triangles = this->m_triangles;
            m_max_distance = this->m_max_distance;
            v44[1] = vostok::collision::colliders::ray_object::false_triangle_predicate;
            v44[0] = this;
            ((void (__thiscall *)(const vostok::collision::object *, vostok::collision::colliders::ray_object *, vostok::math::float3 *, _DWORD, float *, vostok::vectora<vostok::collision::ray_triangle_result> *, _DWORD *))ray_query)(
              i,
              this,
              &this->m_ray_aabb_collider.m_direction,
              LODWORD(m_max_distance),
              &v41,
              m_triangles,
              v44);
          }
        }
        v10 = FLOAT_0_5;
      }
    }
  }
}
