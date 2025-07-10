void __usercall btSoftBody::RayFromToCaster::Process(
        btSoftBody::RayFromToCaster *this@<ecx>,
        const btDbvtNode *leaf@<eax>)
{
  btSoftBody::Face *v2; // ebx
  float v4; // xmm0_4
  float rayNormalizedDirection; // [esp+14h] [ebp-4h]

  v2 = (btSoftBody::Face *)leaf->childs[0];
  rayNormalizedDirection = this->m_mint;
  v4 = btSoftBody::RayFromToCaster::rayFromToTriangle(
         &this->m_rayFrom,
         &v2->m_n[0]->m_x,
         &v2->m_n[1]->m_x,
         &v2->m_n[2]->m_x,
         &this->m_rayNormalizedDirection,
         (const btVector3 *)LODWORD(rayNormalizedDirection));
  ++this->m_tests;
  if ( v4 > 0.0 && rayNormalizedDirection > v4 )
  {
    this->m_mint = v4;
    this->m_face = v2;
  }
}
