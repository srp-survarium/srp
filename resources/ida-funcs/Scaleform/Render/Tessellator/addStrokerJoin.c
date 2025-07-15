unsigned int __thiscall Scaleform::Render::Tessellator::addStrokerJoin(
        Scaleform::Render::Tessellator *this,
        const Scaleform::Render::Tessellator::StrokerEdgeType *e1,
        const Scaleform::Render::Tessellator::StrokerEdgeType *e2)
{
  unsigned int node2; // ecx
  Scaleform::Render::TessVertex **Pages; // edx
  unsigned int v6; // esi
  const Scaleform::Render::TessVertex *v7; // ebx
  const Scaleform::Render::TessVertex *v8; // esi
  unsigned int v9; // eax
  const Scaleform::Render::TessVertex *v10; // ebp
  double v11; // st7
  double v13; // st7
  double v14; // st6
  Scaleform::Render::Tessellator *v15; // ecx
  double v16; // st7
  unsigned int Size; // eax
  float ay; // [esp+4h] [ebp-7Ch]
  float by; // [esp+Ch] [ebp-74h]
  float v20; // [esp+10h] [ebp-70h]
  float cy; // [esp+14h] [ebp-6Ch]
  float v22; // [esp+18h] [ebp-68h]
  float dy; // [esp+1Ch] [ebp-64h]
  float y; // [esp+28h] [ebp-58h]
  float ya; // [esp+28h] [ebp-58h]
  float yb; // [esp+28h] [ebp-58h]
  float yc; // [esp+28h] [ebp-58h]
  float yd; // [esp+28h] [ebp-58h]
  float v29; // [esp+3Ch] [ebp-44h]
  float v30; // [esp+40h] [ebp-40h] BYREF
  float v31; // [esp+44h] [ebp-3Ch] BYREF
  float v32; // [esp+48h] [ebp-38h]
  float v33; // [esp+4Ch] [ebp-34h]
  float v34; // [esp+50h] [ebp-30h]
  double v35; // [esp+54h] [ebp-2Ch]
  float v36; // [esp+5Ch] [ebp-24h]
  double v37; // [esp+60h] [ebp-20h]
  float v38; // [esp+68h] [ebp-18h]
  float v39; // [esp+6Ch] [ebp-14h]
  unsigned int v40; // [esp+70h] [ebp-10h]
  Scaleform::Render::Tessellator::TriangleType val; // [esp+74h] [ebp-Ch] BYREF
  float v42; // [esp+84h] [ebp+4h]
  float v43; // [esp+84h] [ebp+4h]
  float v44; // [esp+84h] [ebp+4h]
  float v45; // [esp+84h] [ebp+4h]
  float v46; // [esp+84h] [ebp+4h]
  float v47; // [esp+84h] [ebp+4h]
  float v48; // [esp+84h] [ebp+4h]
  float v49; // [esp+84h] [ebp+4h]
  float x; // [esp+84h] [ebp+4h]
  float v51; // [esp+84h] [ebp+4h]
  float v52; // [esp+84h] [ebp+4h]
  float v53; // [esp+84h] [ebp+4h]
  float v54; // [esp+84h] [ebp+4h]
  float v55; // [esp+84h] [ebp+4h]
  float v56; // [esp+84h] [ebp+4h]
  float v57; // [esp+84h] [ebp+4h]
  float v58; // [esp+84h] [ebp+4h]
  float v59; // [esp+88h] [ebp+8h]
  float v60; // [esp+88h] [ebp+8h]
  float v61; // [esp+88h] [ebp+8h]

  node2 = e1->node2;
  Pages = this->MeshVertices.Pages;
  v6 = e1->node1 & 0xFFFFFFF;
  v38 = this->EdgeAAWidth * -2.0;
  v7 = &Pages[v6 >> 4][v6 & 0xF];
  v40 = node2 & 0xFFFFFFF;
  v8 = &Pages[(node2 & 0xFFFFFFF) >> 4][node2 & 0xF];
  v9 = e2->node2 & 0xFFFFFFF;
  v37 = v8->x - v7->x;
  v59 = v37;
  v10 = &Pages[v9 >> 4][v9 & 0xF];
  v42 = v8->y - v7->y;
  v43 = v42 * v42 + v59 * v59;
  v44 = sqrt(v43);
  v32 = v44;
  v35 = v10->x - v8->x;
  v60 = v35;
  v45 = v10->y - v8->y;
  v46 = v45 * v45 + v60 * v60;
  v47 = sqrt(v46);
  v33 = v47;
  v36 = Scaleform::Render::Math2D::TurnRatio<Scaleform::Render::TessVertex,Scaleform::Render::TessVertex,Scaleform::Render::TessVertex>(
          v7,
          v8,
          v10,
          v32,
          v47);
  v11 = v47;
  v39 = (v47 + v32) * this->IntersectionEpsilon;
  v34 = (v7->y - v8->y) * v38 / v32;
  v48 = v37 * v38 / v32;
  v29 = (v8->y - v10->y) * v38 / v33;
  v61 = v38 * v35 / v33;
  v31 = v8->x;
  v30 = v8->y;
  *(float *)&v37 = fabs(v36);
  if ( *(float *)&v37 >= 0.125 )
  {
    *(double *)&val.d.m.v1 = v8->x + v34;
    *(float *)&v35 = *(double *)&val.d.m.v1;
    ya = v39;
    v39 = v10->y + v61;
    dy = v39;
    v39 = v10->x + v29;
    v22 = v39;
    v39 = v61 + v8->y;
    cy = v39;
    v39 = v29 + v8->x;
    v20 = v39;
    v39 = v48 + v8->y;
    by = v39;
    v39 = v48 + v7->y;
    ay = v39;
    v39 = v34 + v7->x;
    if ( Scaleform::Render::Math2D::Intersection(v39, ay, *(float *)&v35, by, v20, cy, v22, dy, &v31, &v30, ya) )
    {
      *(float *)&v37 = v31 - v8->x;
      v39 = v30 - v8->y;
      v39 = v39 * v39 + *(float *)&v37 * *(float *)&v37;
      v39 = sqrt(v39);
      *(float *)&v37 = v39;
      v13 = v36;
      if ( v36 <= 0.0 )
      {
        v15 = this;
        v39 = -v38 * 4.0;
        if ( v39 < (double)*(float *)&v37 )
        {
          v16 = v48;
          v52 = v34 * 2.0 + v48 + v8->y;
          yb = v52;
          v53 = *(double *)&val.d.m.v1 - v16 * 2.0;
          Scaleform::Render::Tessellator::emitStrokerVertex(this, v53, yb);
          v54 = v61 + v8->y - v29 * 2.0;
          yc = v54;
          v55 = v29 + v8->x + 2.0 * v61;
          Scaleform::Render::Tessellator::emitStrokerVertex(this, v55, yc);
          Size = this->MeshVertices.Size;
          val.d.t.v3 = Size - 1;
          val.d.t.v1 = v40;
          val.d.t.v2 = Size - 2;
          Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::PushBack(
            &this->MeshTriangles,
            0,
            &val);
          return 2;
        }
      }
      else
      {
        v14 = v32;
        if ( v33 <= (double)v32 )
          v14 = v33;
        v36 = v14;
        v15 = this;
        v39 = v36 / v13;
        if ( v39 < (double)*(float *)&v37 )
          goto LABEL_15;
      }
      Scaleform::Render::Tessellator::emitStrokerVertex(v15, v31, v30);
      return 1;
    }
LABEL_15:
    v56 = v48 + v8->y;
    Scaleform::Render::Tessellator::emitStrokerVertex(this, *(float *)&v35, v56);
    v57 = v61 + v8->y;
    yd = v57;
    v58 = v8->x + v29;
    Scaleform::Render::Tessellator::emitStrokerVertex(this, v58, yd);
    return 2;
  }
  if ( v32 <= v11 )
  {
    v51 = v61 + v8->y;
    y = v51;
    x = v8->x + v29;
  }
  else
  {
    v49 = v48 + v8->y;
    y = v49;
    x = v8->x + v34;
  }
  Scaleform::Render::Tessellator::emitStrokerVertex(this, x, y);
  return 1;
}
