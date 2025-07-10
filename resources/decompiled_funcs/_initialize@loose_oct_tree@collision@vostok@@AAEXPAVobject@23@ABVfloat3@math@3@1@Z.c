void __userpurge vostok::collision::loose_oct_tree::initialize(
        vostok::collision::loose_oct_tree *this@<esi>,
        vostok::collision::object *object@<eax>,
        const vostok::math::float3 *aabb_center,
        const vostok::math::float3 *aabb_extents)
{
  vostok::collision::vertex_allocator *m_allocator; // ecx
  vostok::collision::oct_node *v6; // eax
  vostok::collision::oct_node *m_root; // eax
  vostok::collision::oct_node *p_parent; // ecx
  float m_min_aabb_extents; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  signed int v14; // edi
  signed int v15; // edi
  long double v16; // [esp+8h] [ebp-20h]
  long double v17; // [esp+8h] [ebp-20h]
  float v18; // [esp+14h] [ebp-14h]
  float v19; // [esp+18h] [ebp-10h]

  m_allocator = this->m_allocator;
  this->m_initialized = 1;
  v6 = vostok::collision::vertex_allocator::allocate(m_allocator);
  this->m_root = v6;
  v6->objects = object;
  object->m_moved = 1;
  object->m_node = this->m_root;
  object->m_next = 0;
  m_root = this->m_root;
  p_parent = (vostok::collision::oct_node *)&m_root->parent;
  do
  {
    m_root->octants[0] = 0;
    m_root = (vostok::collision::oct_node *)((char *)m_root + 4);
  }
  while ( m_root != p_parent );
  this->m_object_count = 1;
  *(_QWORD *)&this->m_aabb_center.x = *(_QWORD *)&aabb_center->x;
  m_min_aabb_extents = this->m_min_aabb_extents;
  this->m_aabb_center.z = aabb_center->z;
  v18 = m_min_aabb_extents;
  if ( m_min_aabb_extents <= aabb_extents->x
    || m_min_aabb_extents <= aabb_extents->y
    || m_min_aabb_extents <= aabb_extents->z )
  {
    v10 = *(float *)&clear_value / this->m_min_aabb_extents;
    v11 = v10 * aabb_extents->x;
    v12 = v10 * aabb_extents->y;
    v13 = v10 * aabb_extents->z;
    if ( v12 > v13 )
      v13 = v12;
    if ( v11 > v13 )
      v13 = v11;
    __libm_sse2_log(v16);
    __libm_sse2_log(v17);
    v14 = ~(~(COERCE_INT(v13 / (float)2.0) - 1) & 0x80000000) & COERCE_UNSIGNED_INT(v13 / (float)2.0);
    v15 = (v14 >> 31)
        ^ ((158 - (unsigned __int8)(v14 >> 23) - 96 + 64) >> 31)
        & (((v14 | 0xFF800000) << 8 >> (-98 - (v14 >> 23)))
         - ((v14 >> 31) & ((v14 & (((1 << (-98 - (v14 >> 23) - 96)) - 1) >> 8)) == 0)));
    v19 = powf(2.0, (float)v15) * v18;
    this->m_aabb_extents = v19;
    if ( v19 < aabb_extents->x || v19 < aabb_extents->y || v19 < aabb_extents->z )
      this->m_aabb_extents = powf(2.0, (float)(v15 + 1)) * v18;
  }
  else
  {
    this->m_aabb_extents = m_min_aabb_extents;
  }
}
