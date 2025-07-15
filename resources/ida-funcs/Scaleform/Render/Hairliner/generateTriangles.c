void __thiscall Scaleform::Render::Hairliner::generateTriangles(Scaleform::Render::Hairliner *this, float width)
{
  unsigned int Size; // esi
  unsigned int **Pages; // edx
  unsigned int v5; // ebp
  Scaleform::Render::Hairliner::OutVertexType **v6; // ecx
  unsigned int v7; // edx
  Scaleform::Render::TessVertex *v8; // ebx
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
  int v22; // [esp+1Ch] [ebp-3Ch]
  unsigned int i; // [esp+20h] [ebp-38h]
  unsigned int v24; // [esp+24h] [ebp-34h]
  Scaleform::Render::TessVertex *v25; // [esp+28h] [ebp-30h]
  Scaleform::Render::TessVertex *v26; // [esp+2Ch] [ebp-2Ch]
  float v27; // [esp+30h] [ebp-28h]
  float v28; // [esp+30h] [ebp-28h]
  float v29; // [esp+34h] [ebp-24h]
  unsigned int v30; // [esp+34h] [ebp-24h]
  float v31; // [esp+38h] [ebp-20h]
  int v32; // [esp+38h] [ebp-20h]
  float v33; // [esp+3Ch] [ebp-1Ch]
  float v34; // [esp+3Ch] [ebp-1Ch]
  float v35; // [esp+3Ch] [ebp-1Ch]
  int v36; // [esp+3Ch] [ebp-1Ch]
  float v37; // [esp+40h] [ebp-18h]
  float v38; // [esp+40h] [ebp-18h]
  float v39; // [esp+40h] [ebp-18h]
  unsigned int v40; // [esp+40h] [ebp-18h]
  unsigned int v41; // [esp+40h] [ebp-18h]
  int v42; // [esp+48h] [ebp-10h]
  unsigned int v43; // [esp+50h] [ebp-8h]
  unsigned int v44; // [esp+54h] [ebp-4h]

  Size = this->ContourNodes.Size;
  if ( Size >= 2 )
  {
    Pages = this->ContourNodes.Pages;
    v5 = Pages[(Size - 1) >> 4][(Size - 1) & 0xF];
    v6 = this->OutVertices.Pages;
    v7 = Pages[(Size - 2) >> 4][(Size - 2) & 0xF];
    v8 = (Scaleform::Render::TessVertex *)&v6[v5 >> 4][v5 & 0xF];
    v25 = (Scaleform::Render::TessVertex *)&v6[v7 >> 4][v7 & 0xF];
    v31 = v8->x - v25->x;
    v33 = v8->y - v25->y;
    v34 = v33 * v33 + v31 * v31;
    v35 = sqrt(v34);
    v22 = -1;
    v29 = v35;
    v24 = -1;
    v36 = -1;
    v32 = -1;
    v9 = 0;
    for ( i = 0; ; v9 = i )
    {
      v10 = v9 >> 4;
      v42 = v9 & 0xF;
      v26 = (Scaleform::Render::TessVertex *)&this->OutVertices.Pages[this->ContourNodes.Pages[v10][v42] >> 4][this->ContourNodes.Pages[v10][v42] & 0xF];
      v37 = v26->x - v8->x;
      v27 = v26->y - v8->y;
      v38 = v27 * v27 + v37 * v37;
      v39 = sqrt(v38);
      v28 = v39;
      v11 = Scaleform::Render::Hairliner::addJoin(this, v5, v25, v8, v26, v29, v39, width);
      v30 = v11;
      if ( v22 == -1 )
      {
        v36 = v5;
        v32 = this->OutVertices.Size - v11;
      }
      else
      {
        v44 = this->OutVertices.Size - v11;
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
        v13->v1 = v22;
        v13->v2 = v24;
        v13->v3 = v44;
        v14 = ++this->Triangles.Size >> 4;
        v43 = this->OutVertices.Size - v30;
        v41 = v14;
        if ( v14 >= this->Triangles.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->Triangles,
            v14);
          v14 = v41;
        }
        v15 = &this->Triangles.Pages[v14][this->Triangles.Size & 0xF];
        v15->v1 = v22;
        v15->v2 = v43;
        v15->v3 = v5;
        ++this->Triangles.Size;
      }
      v29 = v28;
      v22 = v5;
      v5 = this->ContourNodes.Pages[v10][v42];
      v24 = this->OutVertices.Size - 1;
      v25 = v8;
      v8 = v26;
      if ( ++i >= this->ContourNodes.Size )
        break;
    }
    if ( v22 != -1 )
    {
      v16 = this->Triangles.Size;
      p_Triangles = (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->Triangles;
      v18 = v16 >> 4;
      if ( v18 >= p_Triangles->NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(p_Triangles, v18);
      v19 = &p_Triangles->Pages[v18][p_Triangles->Size & 0xF];
      v19->srcVer = v22;
      v19->aaVer = v24;
      v19->next = (Scaleform::Render::Tessellator::MonoVertexType *)v32;
      v20 = ++p_Triangles->Size >> 4;
      if ( v20 >= p_Triangles->NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
          p_Triangles,
          p_Triangles->Size >> 4);
      v21 = &p_Triangles->Pages[v20][p_Triangles->Size & 0xF];
      v21->srcVer = v22;
      v21->aaVer = v32;
      v21->next = (Scaleform::Render::Tessellator::MonoVertexType *)v36;
      ++p_Triangles->Size;
    }
  }
}
