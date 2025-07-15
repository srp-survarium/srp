void __thiscall Scaleform::Render::Tessellator::addTriangleAA(
        Scaleform::Render::Tessellator *this,
        __int64 v1,
        _DWORD *v3,
        float cp)
{
  Scaleform::Render::TessVertex **Pages; // ecx
  const Scaleform::Render::TessVertex *v6; // edi
  const Scaleform::Render::TessVertex *v7; // esi
  Scaleform::Render::TessVertex *v8; // edx
  double x; // st7
  Scaleform::Render::TessVertex *v10; // edx
  Scaleform::Render::TessVertex *v11; // ecx
  Scaleform::Render::TessVertex *v12; // edx
  unsigned int v13; // eax
  unsigned int FactorOneFlag; // edx
  unsigned int v15; // eax
  unsigned int v16; // ecx
  unsigned int MonoStyle; // edx
  Scaleform::Render::TessVertex *refVer; // [esp+4h] [ebp-1Ch]
  Scaleform::Render::TessVertex *v19; // [esp+8h] [ebp-18h]
  float v20; // [esp+Ch] [ebp-14h]
  Scaleform::Render::TessVertex *aaVer; // [esp+10h] [ebp-10h]
  float aaVera; // [esp+10h] [ebp-10h]
  float aaVerb; // [esp+10h] [ebp-10h]
  Scaleform::Render::Tessellator::TriangleType val; // [esp+14h] [ebp-Ch] BYREF

  if ( this->EdgeAAFlag )
  {
    Pages = this->MeshVertices.Pages;
    refVer = &Pages[(*(_DWORD *)v1 & 0xFFFFFFFu) >> 4][*(_DWORD *)v1 & 0xF];
    v6 = &Pages[(*(_DWORD *)HIDWORD(v1) & 0xFFFFFFFu) >> 4][*(_DWORD *)HIDWORD(v1) & 0xF];
    v7 = &Pages[(*v3 & 0xFFFFFFFu) >> 4][*v3 & 0xF];
    v8 = Pages[(*(_DWORD *)(v1 + 4) & 0xFFFFFFFu) >> 4];
    x = v8[*(_DWORD *)(v1 + 4) & 0xF].x;
    v10 = &v8[*(_DWORD *)(v1 + 4) & 0xF];
    aaVer = &Pages[(*(_DWORD *)(HIDWORD(v1) + 4) & 0xFFFFFFFu) >> 4][*(_DWORD *)(HIDWORD(v1) + 4) & 0xF];
    v20 = (x - v7->x) * (v7->y - v6->y) - (v10->y - v7->y) * (v7->x - v6->x);
    v11 = &Pages[(v3[1] & 0xFFFFFFFu) >> 4][v3[1] & 0xF];
    v19 = v11;
    if ( v20 >= 0.0 )
    {
      Scaleform::Render::Tessellator::moveVertexAA(this, refVer, v10, v6, v7);
      v11 = v19;
    }
    v12 = aaVer;
    aaVera = (aaVer->x - refVer->x) * (refVer->y - v7->y) - (aaVer->y - refVer->y) * (refVer->x - v7->x);
    if ( aaVera >= 0.0 )
    {
      Scaleform::Render::Tessellator::moveVertexAA(this, v6, v12, v7, refVer);
      v11 = v19;
    }
    aaVerb = (v11->x - v6->x) * (v6->y - refVer->y) - (v11->y - v6->y) * (v6->x - refVer->x);
    if ( aaVerb >= 0.0 )
      Scaleform::Render::Tessellator::moveVertexAA(this, v7, v11, refVer, v6);
    *(_QWORD *)&val.d.m.v1 = v1;
    val.d.t.v3 = (unsigned int)v3;
  }
  else
  {
    v13 = Scaleform::Render::Tessellator::emitVertex(
            this,
            this->MeshIdx,
            *(_DWORD *)v1 & 0xFFFFFFF,
            this->MonoStyle,
            this->FactorOneFlag);
    FactorOneFlag = this->FactorOneFlag;
    val.d.t.v1 = v13;
    v15 = Scaleform::Render::Tessellator::emitVertex(
            this,
            this->MeshIdx,
            *(_DWORD *)HIDWORD(v1) & 0xFFFFFFF,
            this->MonoStyle,
            FactorOneFlag);
    v16 = this->FactorOneFlag;
    MonoStyle = this->MonoStyle;
    val.d.t.v2 = v15;
    val.d.t.v3 = Scaleform::Render::Tessellator::emitVertex(this, this->MeshIdx, *v3 & 0xFFFFFFF, MonoStyle, v16);
  }
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::PushBack(
    &this->MeshTriangles,
    this->MeshIdx,
    &val);
}
