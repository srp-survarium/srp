bool __userpurge vostok::render::sort_grass_patch_predicate::operator()@<al>(
        const vostok::render::grass_patch *left@<eax>,
        const vostok::render::grass_patch *right@<edx>,
        vostok::render::sort_grass_patch_predicate *this)
{
  vostok::render::grass_template *m_template; // esi
  vostok::render::grass_template *v4; // edi
  float y; // xmm5_4
  float z; // xmm6_4

  m_template = left->m_template;
  v4 = right->m_template;
  if ( m_template < v4 )
    return 1;
  if ( m_template > v4 )
    return 0;
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
