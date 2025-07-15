void __thiscall Scaleform::Render::Hairliner::generateTriangles(Scaleform::Render::Hairliner *this, float width)
{
  unsigned int Size; // esi
  unsigned int **Pages; // edx
  unsigned int v5; // ebp
  Scaleform::Render::Hairliner::OutVertexType **v6; // ecx
  unsigned int v7; // edx
  float *p_x; // ebx
  unsigned int v9; // eax
  unsigned int v10; // esi
  unsigned int v11; // eax
  unsigned int v12; // ecx
  Scaleform::Render::Hairliner::TriangleType *v13; // eax
  unsigned int v14; // ecx
  Scaleform::Render::Hairliner::TriangleType *v15; // eax
  unsigned int v16; // esi
  Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *p_Triangles; // edi
  unsigned int v18; // esi
  Scaleform::Render::Tessellator::MonoVertexType *v19; // eax
  unsigned int v20; // esi
  Scaleform::Render::Tessellator::MonoVertexType *v21; // eax
  unsigned int prevRef; // [esp+1Ch] [ebp-3Ch]
  unsigned int i; // [esp+20h] [ebp-38h]
  unsigned int prevAA; // [esp+24h] [ebp-34h]
  const Scaleform::Render::TessVertex *v1; // [esp+28h] [ebp-30h]
  const Scaleform::Render::Hairliner::OutVertexType *v3; // [esp+2Ch] [ebp-2Ch]
  float len2a; // [esp+30h] [ebp-28h]
  float len2; // [esp+30h] [ebp-28h]
  float nv; // [esp+34h] [ebp-24h]
  unsigned int nva; // [esp+34h] [ebp-24h]
  float startAAa; // [esp+38h] [ebp-20h]
  unsigned int startAA; // [esp+38h] [ebp-20h]
  float startRefa; // [esp+3Ch] [ebp-1Ch]
  float startRefb; // [esp+3Ch] [ebp-1Ch]
  float startRefc; // [esp+3Ch] [ebp-1Ch]
  unsigned int startRef; // [esp+3Ch] [ebp-1Ch]
  float v37; // [esp+40h] [ebp-18h]
  float v38; // [esp+40h] [ebp-18h]
  float v39; // [esp+40h] [ebp-18h]
  unsigned int v40; // [esp+40h] [ebp-18h]
  unsigned int v41; // [esp+40h] [ebp-18h]
  int v42; // [esp+48h] [ebp-10h]
  unsigned int tri_4; // [esp+50h] [ebp-8h]
  unsigned int tri_8; // [esp+54h] [ebp-4h]

  Size = this->ContourNodes.Size;
  if ( Size >= 2 )
  {
    Pages = this->ContourNodes.Pages;
    v5 = Pages[(Size - 1) >> 4][(Size - 1) & 0xF];
    v6 = this->OutVertices.Pages;
    v7 = Pages[(Size - 2) >> 4][(Size - 2) & 0xF];
    p_x = &v6[v5 >> 4][v5 & 0xF].x;
    v1 = (const Scaleform::Render::TessVertex *)&v6[v7 >> 4][v7 & 0xF];
    startAAa = *p_x - v1->x;
    startRefa = p_x[1] - v1->y;
    startRefb = startRefa * startRefa + startAAa * startAAa;
    startRefc = sqrt(startRefb);
    prevRef = -1;
    nv = startRefc;
    prevAA = -1;
    startRef = -1;
    startAA = -1;
    v9 = 0;
    for ( i = 0; ; v9 = i )
    {
      v10 = v9 >> 4;
      v42 = v9 & 0xF;
      v3 = &this->OutVertices.Pages[this->ContourNodes.Pages[v10][v42] >> 4][this->ContourNodes.Pages[v10][v42] & 0xF];
      v37 = v3->x - *p_x;
      len2a = v3->y - p_x[1];
      v38 = len2a * len2a + v37 * v37;
      v39 = sqrt(v38);
      len2 = v39;
      v11 = Scaleform::Render::Hairliner::addJoin(this, v5, v1, *(float *)&p_x, *(float *)&v3, nv, v39, width);
      nva = v11;
      if ( prevRef == -1 )
      {
        startRef = v5;
        startAA = this->OutVertices.Size - v11;
      }
      else
      {
        tri_8 = this->OutVertices.Size - v11;
        v12 = this->Triangles.Size >> 4;
        v40 = v12;
        if ( v12 >= this->Triangles.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->Triangles,
            v12);
          v12 = v40;
        }
        v13 = &this->Triangles.Pages[v12][this->Triangles.Size & 0xF];
        v13->v1 = prevRef;
        v13->v2 = prevAA;
        v13->v3 = tri_8;
        v14 = ++this->Triangles.Size >> 4;
        tri_4 = this->OutVertices.Size - nva;
        v41 = v14;
        if ( v14 >= this->Triangles.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->Triangles,
            v14);
          v14 = v41;
        }
        v15 = &this->Triangles.Pages[v14][this->Triangles.Size & 0xF];
        v15->v1 = prevRef;
        v15->v2 = tri_4;
        v15->v3 = v5;
        ++this->Triangles.Size;
      }
      nv = len2;
      prevRef = v5;
      v5 = this->ContourNodes.Pages[v10][v42];
      prevAA = this->OutVertices.Size - 1;
      v1 = (const Scaleform::Render::TessVertex *)p_x;
      p_x = &v3->x;
      if ( ++i >= this->ContourNodes.Size )
        break;
    }
    if ( prevRef != -1 )
    {
      v16 = this->Triangles.Size;
      p_Triangles = (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->Triangles;
      v18 = v16 >> 4;
      if ( v18 >= p_Triangles->NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(p_Triangles, v18);
      v19 = &p_Triangles->Pages[v18][p_Triangles->Size & 0xF];
      v19->srcVer = prevRef;
      v19->aaVer = prevAA;
      v19->next = (Scaleform::Render::Tessellator::MonoVertexType *)startAA;
      v20 = ++p_Triangles->Size >> 4;
      if ( v20 >= p_Triangles->NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
          p_Triangles,
          p_Triangles->Size >> 4);
      v21 = &p_Triangles->Pages[v20][p_Triangles->Size & 0xF];
      v21->srcVer = prevRef;
      v21->aaVer = startAA;
      v21->next = (Scaleform::Render::Tessellator::MonoVertexType *)startRef;
      ++p_Triangles->Size;
    }
  }
}
