void __thiscall Scaleform::Render::Tessellator::addTriangleAA(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::Tessellator::MonoVertexType *v1,
        Scaleform::Render::Tessellator::MonoVertexType *v2,
        unsigned int v3,
        float cp)
{
  Scaleform::Render::TessVertex **Pages; // ecx
  const Scaleform::Render::TessVertex *v7; // edi
  const Scaleform::Render::TessVertex *v8; // esi
  Scaleform::Render::TessVertex *v9; // edx
  double x; // st7
  Scaleform::Render::TessVertex *v11; // edx
  Scaleform::Render::TessVertex *v12; // ecx
  Scaleform::Render::TessVertex *v13; // edx
  unsigned int v14; // eax
  unsigned int FactorOneFlag; // edx
  unsigned int v16; // eax
  unsigned int v17; // ecx
  unsigned int MonoStyle; // edx
  const Scaleform::Render::TessVertex *refV1; // [esp+4h] [ebp-1Ch]
  Scaleform::Render::TessVertex *aaV3; // [esp+8h] [ebp-18h]
  float v21; // [esp+Ch] [ebp-14h]
  Scaleform::Render::TessVertex *aaV2; // [esp+10h] [ebp-10h]
  float aaV2a; // [esp+10h] [ebp-10h]
  float aaV2b; // [esp+10h] [ebp-10h]
  Scaleform::Render::Tessellator::TriangleType tri; // [esp+14h] [ebp-Ch] BYREF

  if ( this->EdgeAAFlag )
  {
    Pages = this->MeshVertices.Pages;
    refV1 = &Pages[(v1->srcVer & 0xFFFFFFF) >> 4][v1->srcVer & 0xF];
    v7 = &Pages[(v2->srcVer & 0xFFFFFFF) >> 4][v2->srcVer & 0xF];
    v8 = &Pages[(*(_DWORD *)v3 & 0xFFFFFFFu) >> 4][*(_DWORD *)v3 & 0xF];
    v9 = Pages[(v1->aaVer & 0xFFFFFFF) >> 4];
    x = v9[v1->aaVer & 0xF].x;
    v11 = &v9[v1->aaVer & 0xF];
    aaV2 = &Pages[(v2->aaVer & 0xFFFFFFF) >> 4][v2->aaVer & 0xF];
    v21 = (x - v8->x) * (v8->y - v7->y) - (v11->y - v8->y) * (v8->x - v7->x);
    v12 = &Pages[(*(_DWORD *)(v3 + 4) & 0xFFFFFFFu) >> 4][*(_DWORD *)(v3 + 4) & 0xF];
    aaV3 = v12;
    if ( v21 >= 0.0 )
    {
      Scaleform::Render::Tessellator::moveVertexAA(this, refV1, v11, v7, v8);
      v12 = aaV3;
    }
    v13 = aaV2;
    aaV2a = (aaV2->x - refV1->x) * (refV1->y - v8->y) - (aaV2->y - refV1->y) * (refV1->x - v8->x);
    if ( aaV2a >= 0.0 )
    {
      Scaleform::Render::Tessellator::moveVertexAA(this, v7, v13, v8, refV1);
      v12 = aaV3;
    }
    aaV2b = (v12->x - v7->x) * (v7->y - refV1->y) - (v12->y - v7->y) * (v7->x - refV1->x);
    if ( aaV2b >= 0.0 )
      Scaleform::Render::Tessellator::moveVertexAA(this, v8, v12, refV1, v7);
    *(_QWORD *)&tri.d.m.v1 = __PAIR64__((unsigned int)v2, (unsigned int)v1);
    tri.d.t.v3 = v3;
  }
  else
  {
    v14 = Scaleform::Render::Tessellator::emitVertex(
            this,
            this->MeshIdx,
            v1->srcVer & 0xFFFFFFF,
            this->MonoStyle,
            this->FactorOneFlag);
    FactorOneFlag = this->FactorOneFlag;
    tri.d.t.v1 = v14;
    v16 = Scaleform::Render::Tessellator::emitVertex(
            this,
            this->MeshIdx,
            v2->srcVer & 0xFFFFFFF,
            this->MonoStyle,
            FactorOneFlag);
    v17 = this->FactorOneFlag;
    MonoStyle = this->MonoStyle;
    tri.d.t.v2 = v16;
    tri.d.t.v3 = Scaleform::Render::Tessellator::emitVertex(
                   this,
                   this->MeshIdx,
                   *(_DWORD *)v3 & 0xFFFFFFF,
                   MonoStyle,
                   v17);
  }
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::PushBack(
    &this->MeshTriangles,
    this->MeshIdx,
    &tri);
}
