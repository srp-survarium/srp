void __thiscall btBoxShape::getEdge(btBoxShape *this, int i, btVector3 *pa, btVector3 *pb)
{
  int v5; // eax
  int v6; // esi
  int v7; // [esp-4h] [ebp-Ch]
  int v8; // [esp-4h] [ebp-Ch]
  int v9; // [esp-4h] [ebp-Ch]

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
      v7 = 2;
      goto LABEL_18;
    case 2:
      v5 = 1;
      goto LABEL_5;
    case 3:
      v5 = 2;
LABEL_5:
      v7 = 3;
      goto LABEL_18;
    case 4:
      v5 = 0;
      v7 = 4;
      goto LABEL_18;
    case 5:
      v5 = 1;
      goto LABEL_9;
    case 6:
      v8 = 2;
      goto LABEL_11;
    case 7:
      v9 = 3;
      goto LABEL_17;
    case 8:
      v5 = 4;
LABEL_9:
      v7 = 5;
      goto LABEL_18;
    case 9:
      v8 = 4;
LABEL_11:
      v5 = v8;
      v7 = 6;
      goto LABEL_18;
    case 10:
      v9 = 5;
      goto LABEL_17;
    case 11:
      v9 = 6;
LABEL_17:
      v5 = v9;
      v7 = 7;
LABEL_18:
      v6 = v7;
      break;
    default:
      break;
  }
  this->getVertex(this, v5, pa);
  this->getVertex(this, v6, pb);
}
