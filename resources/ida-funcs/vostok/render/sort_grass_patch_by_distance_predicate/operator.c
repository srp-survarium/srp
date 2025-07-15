BOOL __userpurge vostok::render::sort_grass_patch_by_distance_predicate::operator()@<eax>(
        vostok::render::sort_grass_patch_by_distance_predicate *this@<ecx>,
        const vostok::render::grass_patch *left@<eax>,
        const vostok::render::grass_patch *right)
{
  float y; // xmm5_4
  float z; // xmm6_4

  y = this->m_view_pos.y;
  z = this->m_view_pos.z;
  return (float)((float)((float)((float)(right->m_origin.z - z) * (float)(right->m_origin.z - z))
                       + (float)((float)(right->m_origin.y - y) * (float)(right->m_origin.y - y)))
               + (float)((float)(right->m_origin.x - this->m_view_pos.x)
                       * (float)(right->m_origin.x - this->m_view_pos.x))) > (float)((float)((float)((float)(left->m_origin.z - z) * (float)(left->m_origin.z - z))
                                                                                           + (float)((float)(left->m_origin.x - this->m_view_pos.x) * (float)(left->m_origin.x - this->m_view_pos.x)))
                                                                                   + (float)((float)(left->m_origin.y - y)
                                                                                           * (float)(left->m_origin.y - y)));
}
