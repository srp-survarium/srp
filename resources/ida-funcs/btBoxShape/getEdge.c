void __thiscall btBoxShape::getEdge(btBoxShape *this, int i, btVector3 *pa, btVector3 *pb)
{
  int v5; // eax
  int v6; // esi

  v5 = 0;
  v6 = 0;
  switch ( i )
  {
    case 0:
      v5 = 0;
      v6 = 1;
      break;
    case 1:
      v5 = 0;
      v6 = 2;
      break;
    case 2:
      v5 = 1;
      v6 = 3;
      break;
    case 3:
      v5 = 2;
      v6 = 3;
      break;
    case 4:
      v5 = 0;
      v6 = 4;
      break;
    case 5:
      v5 = 1;
      v6 = 5;
      break;
    case 6:
      v5 = 2;
      v6 = 6;
      break;
    case 7:
      v5 = 3;
      goto LABEL_14;
    case 8:
      v5 = 4;
      v6 = 5;
      break;
    case 9:
      v5 = 4;
      v6 = 6;
      break;
    case 10:
      v5 = 5;
      goto LABEL_14;
    case 11:
      v5 = 6;
LABEL_14:
      v6 = 7;
      break;
    default:
      break;
  }
  this->getVertex(this, v5, pa);
  this->getVertex(this, v6, pb);
}
