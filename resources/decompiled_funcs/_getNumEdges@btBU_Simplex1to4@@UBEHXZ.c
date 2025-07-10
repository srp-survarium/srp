int __thiscall btBU_Simplex1to4::getNumEdges(btBU_Simplex1to4 *this)
{
  int result; // eax

  switch ( this->m_numVertices )
  {
    case 2:
      result = 1;
      break;
    case 3:
      result = 3;
      break;
    case 4:
      result = 6;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}
