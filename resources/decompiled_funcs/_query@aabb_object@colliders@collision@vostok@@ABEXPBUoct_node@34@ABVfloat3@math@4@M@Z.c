void __userpurge vostok::collision::colliders::aabb_object::query(
        vostok::collision::colliders::aabb_object *this@<ecx>,
        bool a2@<bpl>,
        const stlp_std::__true_type *a3@<edi>,
        unsigned int a4@<esi>,
        const vostok::collision::oct_node *node,
        float aabb_center,
        float aabb_extents)
{
  const vostok::math::float3 *v7; // ebx
  vostok::collision::colliders::aabb_object *v8; // edx
  const vostok::math::aabb *m_aabb; // eax
  float v10; // xmm6_4
  float v11; // xmm5_4
  float v12; // xmm4_4
  float v13; // xmm3_4
  float v14; // xmm1_4
  float z; // xmm7_4
  float v16; // xmm0_4
  const vostok::collision::oct_node *v17; // eax
  float v18; // xmm2_4
  vostok::collision::oct_node **p_parent; // ebp
  const vostok::collision::oct_node *v20; // esi
  float v21; // xmm0_4
  int v22; // edi
  const vostok::collision::oct_node *v23; // ecx
  int v24; // eax
  float v25; // xmm3_4
  float v26; // xmm1_4
  float v27; // xmm1_4
  float v28; // xmm3_4
  float v29; // xmm2_4
  float v30; // xmm0_4
  vostok::collision::object *objects; // edi
  float *p_x; // ecx
  float x; // xmm3_4
  float v34; // xmm4_4
  float y; // xmm2_4
  float v36; // xmm0_4
  float v37; // xmm3_4
  float v38; // xmm2_4
  float v39; // xmm0_4
  vostok::vectora<vostok::collision::triangle_result> *m_triangles; // eax
  vostok::collision::object_vtbl *v41; // edx
  vostok::vectora<vostok::collision::object const *> *m_objects; // esi
  const void **M_finish; // eax
  const stlp_std::__true_type *v44; // [esp+4h] [ebp-20h]
  unsigned int v45; // [esp+8h] [ebp-1Ch]
  bool v46; // [esp+Ch] [ebp-18h]
  vostok::math::float3 aabb_centera; // [esp+18h] [ebp-Ch] BYREF

  v7 = (const vostok::math::float3 *)LODWORD(aabb_center);
  v8 = this;
  m_aabb = this->m_aabb;
  v10 = *(float *)LODWORD(aabb_center) - aabb_extents;
  if ( v10 <= this->m_aabb->max.x )
  {
    v11 = *(float *)(LODWORD(aabb_center) + 4) - aabb_extents;
    if ( v11 <= m_aabb->max.y )
    {
      v12 = *(float *)(LODWORD(aabb_center) + 8) - aabb_extents;
      if ( v12 <= m_aabb->max.z )
      {
        v13 = *(float *)LODWORD(aabb_center) + aabb_extents;
        if ( m_aabb->min.x <= v13 )
        {
          v14 = *(float *)(LODWORD(aabb_center) + 4) + aabb_extents;
          if ( m_aabb->min.y <= v14 )
          {
            z = m_aabb->min.z;
            v16 = *(float *)(LODWORD(aabb_center) + 8) + aabb_extents;
            if ( z <= v16 )
            {
              if ( v10 >= m_aabb->min.x
                && v11 >= m_aabb->min.y
                && v12 >= z
                && m_aabb->max.x >= v13
                && m_aabb->max.y >= v14
                && m_aabb->max.z >= v16 )
              {
                if ( this->m_objects )
                  vostok::collision::colliders::aabb_object::add_objects(this, node);
                else
                  vostok::collision::colliders::aabb_object::add_triangles(this, node);
                return;
              }
              v17 = node;
              v18 = aabb_extents * 0.5;
              v46 = a2;
              v45 = a4;
              p_parent = &node->parent;
              v44 = a3;
              aabb_center = aabb_extents * 0.5;
              v20 = node;
              v21 = *(float *)&clear_value;
              v22 = 0;
              do
              {
                v23 = v20->octants[0];
                if ( v20->octants[0] )
                {
                  v24 = v22 >> 2;
                  if ( ((v22 >> 2) & 4) != 0 )
                    v25 = v21;
                  else
                    v25 = -1.0;
                  if ( (v24 & 2) != 0 )
                    v26 = v21;
                  else
                    v26 = -1.0;
                  if ( (v24 & 1) == 0 )
                    v21 = -1.0;
                  v27 = v26 * v18;
                  v28 = v25 * v18;
                  v29 = v7->x + (float)(v21 * v18);
                  aabb_centera.y = v7->y + v27;
                  v30 = v7->z + v28;
                  aabb_centera.x = v29;
                  aabb_centera.z = v30;
                  vostok::collision::colliders::aabb_object::query(v8, v23, &aabb_centera, aabb_center);
                  v18 = aabb_center;
                  v21 = *(float *)&clear_value;
                  v8 = this;
                  v17 = node;
                }
                v20 = (const vostok::collision::oct_node *)((char *)v20 + 4);
                v22 += 4;
              }
              while ( v20 != (const vostok::collision::oct_node *)p_parent );
              objects = v17->objects;
              if ( objects )
              {
                while ( 1 )
                {
                  if ( (objects->m_type & v8->m_query_type) == 0 )
                    goto LABEL_59;
                  p_x = &v8->m_aabb->min.x;
                  x = objects->m_aabb.min.x;
                  if ( x <= v8->m_aabb->max.x )
                    v34 = objects->m_aabb.min.x;
                  else
                    v34 = v8->m_aabb->max.x;
                  if ( objects->m_aabb.min.y <= p_x[4] )
                    y = objects->m_aabb.min.y;
                  else
                    y = p_x[4];
                  v36 = p_x[5];
                  if ( objects->m_aabb.min.z <= v36 )
                    v36 = objects->m_aabb.min.z;
                  if ( v34 != x || y != objects->m_aabb.min.y || v36 != objects->m_aabb.min.z )
                    goto LABEL_59;
                  v37 = *p_x <= objects->m_aabb.max.x ? objects->m_aabb.max.x : *p_x;
                  v38 = p_x[1] <= objects->m_aabb.max.y ? objects->m_aabb.max.y : p_x[1];
                  v39 = p_x[2];
                  if ( v39 <= objects->m_aabb.max.z )
                    v39 = objects->m_aabb.max.z;
                  if ( v37 != objects->m_aabb.max.x || v38 != objects->m_aabb.max.y || v39 != objects->m_aabb.max.z )
                    goto LABEL_59;
                  m_triangles = v8->m_triangles;
                  v41 = objects->__vftable;
                  if ( m_triangles )
                    break;
                  if ( !v41->aabb_test(objects, (const vostok::math::aabb *)p_x) )
                    goto LABEL_58;
                  m_objects = this->m_objects;
                  M_finish = m_objects->_M_impl._M_finish;
                  node = (const vostok::collision::oct_node *)objects;
                  if ( M_finish == m_objects->_M_impl._M_end_of_storage._M_data )
                  {
                    stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
                      (stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *)this,
                      (unsigned __int8 **)m_objects,
                      (int)M_finish,
                      (const unsigned int *)&node,
                      v44,
                      v45,
                      v46);
                    goto LABEL_58;
                  }
                  *M_finish = objects;
                  ++m_objects->_M_impl._M_finish;
                  v8 = this;
LABEL_59:
                  objects = objects->m_next;
                  if ( !objects )
                    return;
                }
                v41->aabb_query(objects, (const vostok::math::aabb *)p_x, m_triangles);
LABEL_58:
                v8 = this;
                goto LABEL_59;
              }
            }
          }
        }
      }
    }
  }
}
