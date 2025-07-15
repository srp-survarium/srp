void __userpurge vostok::collision::loose_oct_tree::initialize(
        vostok::collision::object *object@<eax>,
        vostok::collision::loose_oct_tree *a2@<ecx>,
        vostok::collision::loose_oct_tree *this,
        const vostok::math::float3 *aabb_center,
        const vostok::math::float3 *aabb_extents)
{
  vostok::collision::oct_node *v7; // eax
  vostok::collision::oct_node *m_root; // eax
  vostok::collision::oct_node *v9; // eax
  vostok::collision::oct_node *p_parent; // ecx
  float m_min_aabb_extents; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  long double v16; // [esp+4h] [ebp-Ch]
  long double v17; // [esp+4h] [ebp-Ch]
  long double v18; // [esp+4h] [ebp-Ch]
  long double v19; // [esp+4h] [ebp-Ch]
  long double _C; // [esp+Ch] [ebp-4h]
  long double _Ca; // [esp+Ch] [ebp-4h]
  float v22; // [esp+18h] [ebp+8h]

  this->m_initialized = 1;
  v7 = vostok::collision::loose_oct_tree::new_node(a2, (int)this);
  this->m_root = v7;
  v7->objects = object;
  object->m_moved = 1;
  m_root = this->m_root;
  object->m_next = 0;
  object->m_node = m_root;
  v9 = this->m_root;
  p_parent = (vostok::collision::oct_node *)&v9->parent;
  while ( v9 != p_parent )
  {
    v9->octants[0] = 0;
    v9 = (vostok::collision::oct_node *)((char *)v9 + 4);
  }
  m_min_aabb_extents = this->m_min_aabb_extents;
  this->m_objects_count = 1;
  this->m_aabb_center = *aabb_center;
  v22 = m_min_aabb_extents;
  if ( m_min_aabb_extents > aabb_extents->x
    && m_min_aabb_extents > aabb_extents->y
    && m_min_aabb_extents > aabb_extents->z )
  {
    goto LABEL_15;
  }
  v12 = s_bm_current_air_resistance / this->m_min_aabb_extents;
  v13 = v12 * aabb_extents->x;
  v14 = aabb_extents->y * v12;
  if ( v14 <= (float)(aabb_extents->z * v12) )
    v14 = aabb_extents->z * v12;
  if ( v13 <= v14 )
    v13 = v14;
  __libm_sse2_log(v16);
  __libm_sse2_log(v17);
  vostok::math::floor(v13 / (float)2.0);
  __libm_sse2_pow(v18, _C);
  v15 = (float)2.0 * v22;
  this->m_aabb_extents = v15;
  if ( v15 < aabb_extents->x || v15 < aabb_extents->y || v15 < aabb_extents->z )
  {
    __libm_sse2_pow(v19, _Ca);
    m_min_aabb_extents = (float)2.0 * v22;
LABEL_15:
    this->m_aabb_extents = m_min_aabb_extents;
  }
}
