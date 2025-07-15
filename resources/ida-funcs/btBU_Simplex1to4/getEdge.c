void __thiscall btBU_Simplex1to4::getEdge(btBU_Simplex1to4 *this, int i, btVector3 *pa, btVector3 *pb)
{
  btVector3 *m_vertices; // esi
  int *v5; // esi
  btVector3 *v6; // esi
  int *v7; // esi

  if ( this->m_numVertices == 2 )
    goto LABEL_19;
  if ( this->m_numVertices != 3 )
  {
    if ( this->m_numVertices != 4 )
      return;
    if ( i )
    {
      if ( i != 1 )
      {
        if ( i != 2 )
        {
          switch ( i )
          {
            case 3:
              m_vertices = this->m_vertices;
              break;
            case 4:
              m_vertices = &this->m_vertices[1];
              break;
            case 5:
              m_vertices = &this->m_vertices[2];
              break;
            default:
              return;
          }
          pa->mVec128.m128_i32[0] = m_vertices->mVec128.m128_i32[0];
          v5 = &m_vertices->mVec128.m128_i32[1];
          pa->mVec128.m128_i32[1] = *v5;
          pa->mVec128.m128_u64[1] = *(_QWORD *)(v5 + 1);
          v6 = &this->m_vertices[3];
          goto LABEL_20;
        }
        goto LABEL_18;
      }
      goto LABEL_14;
    }
LABEL_19:
    *pa = this->m_vertices[0];
    v6 = &this->m_vertices[1];
    goto LABEL_20;
  }
  if ( !i )
    goto LABEL_19;
  if ( i != 1 )
  {
    if ( i != 2 )
      return;
LABEL_18:
    *pa = this->m_vertices[2];
    v6 = this->m_vertices;
    goto LABEL_20;
  }
LABEL_14:
  *pa = this->m_vertices[1];
  v6 = &this->m_vertices[2];
LABEL_20:
  pb->mVec128.m128_i32[0] = v6->mVec128.m128_i32[0];
  v7 = &v6->mVec128.m128_i32[1];
  pb->mVec128.m128_i32[1] = *v7;
  pb->mVec128.m128_u64[1] = *(_QWORD *)(v7 + 1);
}
