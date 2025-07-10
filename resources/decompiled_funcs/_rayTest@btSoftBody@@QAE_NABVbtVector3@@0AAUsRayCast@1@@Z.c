BOOL __userpurge btSoftBody::rayTest@<eax>(
        btSoftBody *this@<edi>,
        btSoftBody::sRayCast *results@<esi>,
        btSoftBody *a3@<ecx>,
        const btVector3 *rayFrom,
        const btVector3 *rayTo)
{
  bool v6; // [esp-4h] [ebp-4h]

  v6 = (char)a3;
  if ( this->m_faces.m_size && !this->m_fdbvt.m_root )
    btSoftBody::initializeFaceTree(a3, this);
  LODWORD(results->fraction) = clear_value;
  results->feature = Linear;
  results->body = this;
  results->index = -1;
  return btSoftBody::rayTest(rayFrom, rayTo, this, &results->fraction, &results->feature, &results->index, v6) != 0;
}
