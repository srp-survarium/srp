void __thiscall Scaleform::Render::Tessellator::GetTrianglesI16(
        Scaleform::Render::Tessellator *this,
        unsigned int meshIdx,
        unsigned __int16 *idx,
        unsigned int start,
        unsigned int num)
{
  unsigned int v5; // edx
  Scaleform::Render::Tessellator::TriangleType *v8; // esi
  unsigned __int16 *v9; // eax
  unsigned int meshIdxa; // [esp+4h] [ebp+4h]

  if ( num )
  {
    v5 = 16 * meshIdx;
    for ( meshIdxa = 16 * meshIdx; ; v5 = meshIdxa )
    {
      v8 = &(*(Scaleform::Render::Tessellator::TriangleType ***)((char *)&this->MeshTriangles.Arrays->Pages + v5))[start >> 4][start & 0xF];
      *idx = this->MeshVertices.Pages[v8->d.t.v1 >> 4][v8->d.t.v1 & 0xF].Idx;
      idx[1] = this->MeshVertices.Pages[v8->d.t.v2 >> 4][v8->d.t.v2 & 0xF].Idx;
      v9 = idx + 2;
      *v9 = this->MeshVertices.Pages[v8->d.t.v3 >> 4][v8->d.t.v3 & 0xF].Idx;
      idx = v9 + 1;
      ++start;
      if ( !--num )
        break;
    }
  }
}
