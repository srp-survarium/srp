void __userpurge vostok::collision::colliders::cuboid_object::query(
        vostok::collision::colliders::cuboid_object *this@<ecx>,
        bool a2@<bl>,
        const stlp_std::__true_type *a3@<edi>,
        unsigned int a4@<esi>,
        const vostok::collision::oct_node *node,
        const vostok::math::float3 *aabb_center,
        float aabb_extents)
{
  __int32 v8; // eax
  const vostok::collision::oct_node *v9; // edx
  float v10; // xmm1_4
  const vostok::collision::oct_node *v11; // esi
  float v12; // xmm0_4
  int v13; // edi
  const vostok::collision::oct_node *v14; // ecx
  int v15; // eax
  float v16; // xmm3_4
  float v17; // xmm2_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm6_4
  const vostok::collision::object *objects; // edi
  const vostok::math::cuboid *m_cuboid; // esi
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // xmm3_4
  float v29; // xmm4_4
  float v30; // xmm5_4
  vostok::math::intersection v31; // eax
  vostok::collision::object_vtbl *v32; // edx
  boost::function1<void,vostok::collision::object const &> *v33; // ecx
  boost::function<void __cdecl(vostok::collision::object const &)> *m_callback; // eax
  vostok::vectora<vostok::collision::object const *> *m_objects; // esi
  const void **M_finish; // eax
  const stlp_std::__true_type *v37; // [esp+4h] [ebp-40h]
  unsigned int v38; // [esp+8h] [ebp-3Ch]
  bool v39; // [esp+Ch] [ebp-38h]
  float octant_radius; // [esp+10h] [ebp-34h] BYREF
  __int64 v41; // [esp+14h] [ebp-30h]
  float v42; // [esp+1Ch] [ebp-28h]
  vostok::math::float3 v43; // [esp+20h] [ebp-24h] BYREF
  vostok::math::aabb aabb; // [esp+2Ch] [ebp-18h] BYREF

  v39 = a2;
  v38 = a4;
  v37 = a3;
  v43.x = aabb_extents;
  v43.y = aabb_extents;
  v43.z = aabb_extents;
  v8 = vostok::collision::colliders::cuboid_object::intersects_aabb(aabb_center, &v43, this) - 1;
  if ( v8 )
  {
    if ( v8 != 1 )
    {
      v9 = node;
      v10 = aabb_extents * 0.5;
      octant_radius = aabb_extents * 0.5;
      v11 = node;
      v12 = *(float *)&clear_value;
      v13 = 0;
      do
      {
        v14 = v11->octants[0];
        if ( v11->octants[0] )
        {
          v15 = v13 >> 2;
          if ( ((v13 >> 2) & 4) != 0 )
            v16 = v12;
          else
            v16 = -1.0;
          if ( (v15 & 2) != 0 )
            v17 = v12;
          else
            v17 = -1.0;
          if ( (v15 & 1) == 0 )
            v12 = -1.0;
          v18 = v17 * v10;
          v19 = v16 * v10;
          v20 = aabb_center->x + (float)(v12 * v10);
          v43.y = aabb_center->y + v18;
          v21 = aabb_center->z + v19;
          v43.x = v20;
          v43.z = v21;
          vostok::collision::colliders::cuboid_object::query(this, v14, &v43, octant_radius);
          v10 = octant_radius;
          v12 = *(float *)&clear_value;
          v9 = node;
        }
        v11 = (const vostok::collision::oct_node *)((char *)v11 + 4);
        v13 += 4;
      }
      while ( v11 != (const vostok::collision::oct_node *)&v9->parent );
      v22 = FLOAT_0_5;
      objects = v9->objects;
      if ( objects )
      {
        while ( 1 )
        {
          if ( (objects->m_type & this->m_query_type) != 0 )
          {
            m_cuboid = this->m_cuboid;
            v25 = (float)(objects->m_aabb.max.x - objects->m_aabb.min.x) * v22;
            v26 = (float)(objects->m_aabb.max.y - objects->m_aabb.min.y) * v22;
            v27 = (float)(objects->m_aabb.max.z - objects->m_aabb.min.z) * v22;
            v28 = (float)(objects->m_aabb.min.x + objects->m_aabb.max.x) * v22;
            v29 = (float)(objects->m_aabb.max.y + objects->m_aabb.min.y) * v22;
            v30 = (float)(objects->m_aabb.max.z + objects->m_aabb.min.z) * v22;
            *(float *)&v41 = v28 - v25;
            *((float *)&v41 + 1) = v29 - v26;
            v43.z = v30 + v27;
            v42 = v30 - v27;
            v43.x = v28 + v25;
            v43.y = v29 + v26;
            aabb.max.z = v30 + v27;
            *(_QWORD *)&aabb.min.x = v41;
            aabb.min.z = v30 - v27;
            *(_QWORD *)&aabb.max.x = *(_QWORD *)&v43.x;
            v31 = vostok::math::cuboid::test_inexact((vostok::math::cuboid *)&aabb, &aabb);
            if ( v31 )
            {
              if ( v31 != intersection_outside )
              {
                v32 = objects->__vftable;
                if ( this->m_triangles )
                {
                  v32->cuboid_query((vostok::collision::object *)objects, m_cuboid, this->m_triangles);
                }
                else if ( v32->cuboid_test((vostok::collision::object *)objects, m_cuboid) )
                {
                  m_callback = this->m_callback;
                  if ( m_callback )
                  {
                    boost::function1<void,vostok::collision::object const &>::operator()(v33, m_callback, objects);
                  }
                  else
                  {
                    m_objects = this->m_objects;
                    M_finish = m_objects->_M_impl._M_finish;
                    octant_radius = *(float *)&objects;
                    if ( M_finish == m_objects->_M_impl._M_end_of_storage._M_data )
                    {
                      stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
                        (stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *)&octant_radius,
                        (unsigned __int8 **)m_objects,
                        (int)M_finish,
                        (const unsigned int *)&octant_radius,
                        v37,
                        v38,
                        v39);
                    }
                    else
                    {
                      *M_finish = objects;
                      ++m_objects->_M_impl._M_finish;
                    }
                  }
                }
              }
            }
          }
          objects = objects->m_next;
          if ( !objects )
            break;
          v22 = FLOAT_0_5;
        }
      }
    }
  }
  else if ( this->m_callback )
  {
    vostok::collision::colliders::cuboid_object::add_objects_by_callback(this, node);
  }
  else if ( this->m_objects )
  {
    vostok::collision::colliders::cuboid_object::add_objects(this, (const vostok::collision::object *)node);
  }
  else
  {
    vostok::collision::colliders::cuboid_object::add_triangles(this, node);
  }
}
