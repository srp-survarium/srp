BOOL __fastcall vostok::render::sort_indices_predicate::operator()(
        const vostok::render::grass_patch::sort_info *right,
        const vostok::render::grass_patch::sort_info *left,
        vostok::render::sort_indices_predicate *this)
{
  float v3; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm4_4
  float v6; // xmm5_4

  v3 = left->position.z - this->m_view_pos.z;
  v4 = left->position.y - this->m_view_pos.y;
  v5 = right->position.y - this->m_view_pos.y;
  v6 = right->position.z - this->m_view_pos.z;
  return (float)((float)((float)(v6 * v6) + (float)(v5 * v5))
               + (float)((float)(right->position.x - this->m_view_pos.x)
                       * (float)(right->position.x - this->m_view_pos.x))) > (float)((float)((float)(v3 * v3)
                                                                                           + (float)(v4 * v4))
                                                                                   + (float)((float)(left->position.x - this->m_view_pos.x)
                                                                                           * (float)(left->position.x - this->m_view_pos.x)));
}
