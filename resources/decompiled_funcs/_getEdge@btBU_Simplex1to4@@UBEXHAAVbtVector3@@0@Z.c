void __thiscall btBU_Simplex1to4::getEdge(btBU_Simplex1to4 *this, int i, btVector3 *pa, btVector3 *pb)
{
  if ( this->m_numVertices == 2 )
    goto $LN16_80;
  if ( this->m_numVertices != 3 )
  {
    if ( this->m_numVertices == 4 )
    {
      switch ( i )
      {
        case 0:
          goto $LN16_80;
        case 1:
          goto $LN5_188;
        case 2:
          goto $LN4_164;
        case 3:
          *pa = this->m_vertices[0];
          *pb = this->m_vertices[3];
          break;
        case 4:
          *pa = this->m_vertices[1];
          *pb = this->m_vertices[3];
          break;
        case 5:
          *pa = this->m_vertices[2];
          *pb = this->m_vertices[3];
          break;
        default:
          return;
      }
    }
    return;
  }
  switch ( i )
  {
    case 0:
$LN16_80:
      *pa = this->m_vertices[0];
      *pb = this->m_vertices[1];
      return;
    case 1:
$LN5_188:
      *pa = this->m_vertices[1];
      *pb = this->m_vertices[2];
      break;
    case 2:
$LN4_164:
      *pa = this->m_vertices[2];
      *pb = this->m_vertices[0];
      break;
  }
}
