int __thiscall btBU_Simplex1to4::getNumPlanes(btBU_Simplex1to4 *this)
{
  int result; // eax

  switch ( this->m_numVertices )
  {
    case 3:
      result = 2;
      break;
    case 4:
      result = 4;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}
