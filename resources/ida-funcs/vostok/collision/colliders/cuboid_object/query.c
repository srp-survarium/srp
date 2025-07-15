void __userpurge vostok::collision::colliders::cuboid_object::query(
        vostok::collision::colliders::cuboid_object *this@<ecx>,
        __int64 a2@<esi:edi>,
        vostok::collision::oct_node *node,
        const vostok::math::float3 *aabb_center,
        float aabb_extents)
{
  int v6; // eax
  vostok::collision::oct_node *v7; // eax
  vostok::math::float3 *v8; // eax
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm0_4
  float v12; // xmm3_4
  float *objects; // edi
  const vostok::math::cuboid *m_cuboid; // esi
  unsigned int v15; // xmm1_4
  unsigned int v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  vostok::math::aabb_plane *v20; // eax
  int v21; // eax
  boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *v22; // ecx
  boost::function<void __cdecl(vostok::collision::object const &)> *m_callback; // eax
  vostok::buffer_vector<vostok::collision::object const *> *m_objects; // esi
  vostok::buffer_vector<vostok::collision::object const *> aabb_extentsa; // [esp+0h] [ebp-4Ch]
  vostok::math::cuboid *aabb_extentsb; // [esp+0h] [ebp-4Ch]
  float v27; // [esp+10h] [ebp-3Ch]
  vostok::collision::oct_node *v28; // [esp+14h] [ebp-38h]
  int v29; // [esp+18h] [ebp-34h] BYREF
  vostok::math::float3 aabb_centera; // [esp+1Ch] [ebp-30h] BYREF
  vostok::math::float3 v31; // [esp+28h] [ebp-24h] BYREF
  vostok::math::aabb v32; // [esp+34h] [ebp-18h] BYREF

  *(_QWORD *)&aabb_extentsa.m_end = a2;
  HIDWORD(a2) = aabb_center;
  aabb_centera.x = aabb_extents;
  aabb_centera.y = aabb_extents;
  aabb_centera.z = aabb_extents;
  v6 = vostok::collision::colliders::cuboid_object::intersects_aabb(&aabb_centera, aabb_center, this) - 1;
  if ( v6 )
  {
    if ( v6 != 1 )
    {
      v7 = node;
      v27 = aabb_extents * 0.5;
      v28 = node;
      v29 = 0;
      do
      {
        LODWORD(a2) = v28->octants[0];
        if ( v28->octants[0] )
        {
          v8 = vostok::collision::octant_vector(&v31, (vostok::math::float3 *)(v29 >> 2));
          v9 = v8->z * v27;
          v10 = aabb_center->x + (float)(v8->x * v27);
          aabb_centera.y = aabb_center->y + (float)(v8->y * v27);
          v11 = aabb_center->z + v9;
          aabb_centera.x = v10;
          aabb_centera.z = v11;
          vostok::collision::colliders::cuboid_object::query(
            this,
            a2,
            (vostok::collision::oct_node *)a2,
            &aabb_centera,
            v27);
          v7 = node;
        }
        v28 = (vostok::collision::oct_node *)((char *)v28 + 4);
        v29 += 4;
      }
      while ( v28 != (vostok::collision::oct_node *)&v7->parent );
      v12 = c_anim_center;
      objects = (float *)v7->objects;
      if ( objects )
      {
        while ( 1 )
        {
          if ( ((_DWORD)objects[10] & this->m_query_type) != 0 )
          {
            m_cuboid = this->m_cuboid;
            *(float *)&v15 = (float)(objects[5] - objects[2]) * v12;
            *(float *)&v16 = (float)(objects[6] - objects[3]) * v12;
            aabb_centera.x = (float)(objects[4] - objects[1]) * v12;
            v17 = objects[1] + objects[4];
            *(_QWORD *)&aabb_centera.elements[1] = __PAIR64__(v16, v15);
            v18 = objects[5] + objects[2];
            v19 = (float)(objects[6] + objects[3]) * v12;
            v31.x = v17 * v12;
            v31.y = v18 * v12;
            v31.z = v19;
            v20 = (vostok::math::aabb_plane *)vostok::math::create_aabb_center_radius(&aabb_centera, &v31, &v32);
            v21 = vostok::math::cuboid::test_inexact(aabb_extentsb, (int)m_cuboid, v20);
            if ( v21 )
            {
              if ( v21 != 2 )
              {
                if ( this->m_triangles )
                {
                  (*(void (__thiscall **)(float *, const vostok::math::cuboid *, vostok::buffer_vector<vostok::collision::triangle_result> *))(*(_DWORD *)objects + 8))(
                    objects,
                    m_cuboid,
                    this->m_triangles);
                }
                else if ( (*(unsigned __int8 (__thiscall **)(float *, const vostok::math::cuboid *))(*(_DWORD *)objects + 20))(
                            objects,
                            m_cuboid) )
                {
                  m_callback = this->m_callback;
                  if ( m_callback )
                  {
                    boost::function1<void,vostok::collision::object const &>::operator()(
                      v22,
                      m_callback,
                      (const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)objects);
                  }
                  else
                  {
                    m_objects = this->m_objects;
                    v29 = (int)objects;
                    vostok::buffer_vector<vostok::collision::object const *>::push_back(
                      (vostok::buffer_vector<vostok::collision::object const *> *)v22,
                      (int)m_objects,
                      (const vostok::collision::object **)&v29);
                  }
                }
              }
            }
          }
          objects = (float *)*((_DWORD *)objects + 7);
          if ( !objects )
            break;
          v12 = c_anim_center;
        }
      }
    }
  }
  else
  {
    aabb_extentsa.m_begin = (const vostok::collision::object **)node;
    if ( this->m_callback )
    {
      vostok::collision::colliders::cuboid_object::add_objects_by_callback(this, node);
    }
    else if ( this->m_objects )
    {
      vostok::collision::colliders::cuboid_object::add_objects(this, aabb_extentsa);
    }
    else
    {
      vostok::collision::colliders::cuboid_object::add_triangles(this, node);
    }
  }
}
