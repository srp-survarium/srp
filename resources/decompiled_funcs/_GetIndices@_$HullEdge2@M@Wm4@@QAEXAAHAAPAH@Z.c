void __userpurge Wm4::HullEdge2<float>::GetIndices(
        Wm4::HullEdge2<float> *this@<edi>,
        int *riHQuantity@<esi>,
        int **raiHIndex)
{
  Wm4::HullEdge2<float> *v3; // ecx
  Wm4::HullEdge2<float> *v4; // eax

  *riHQuantity = 0;
  v3 = this;
  do
  {
    ++*riHQuantity;
    v3 = v3->A[1];
  }
  while ( v3 != this );
  *raiHIndex = (int *)operator new[](4 * *riHQuantity);
  *riHQuantity = 0;
  v4 = this;
  do
  {
    (*raiHIndex)[(*riHQuantity)++] = v4->V[0];
    v4 = v4->A[1];
  }
  while ( v4 != this );
}
