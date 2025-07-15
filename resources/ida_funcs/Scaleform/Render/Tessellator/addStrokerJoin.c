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
  float dx2; // [esp+3Ch] [ebp-44h]
  float yi; // [esp+40h] [ebp-40h] BYREF
  float xi; // [esp+44h] [ebp-3Ch] BYREF
  float len1; // [esp+48h] [ebp-38h]
  float len2; // [esp+4Ch] [ebp-34h]
  float dx1; // [esp+50h] [ebp-30h]
  double x; // [esp+54h] [ebp-2Ch]
  float turn; // [esp+5Ch] [ebp-24h]
  double d1; // [esp+60h] [ebp-20h]
  float width; // [esp+68h] [ebp-18h]
  float epsilon; // [esp+6Ch] [ebp-14h]
  unsigned int refVertex; // [esp+70h] [ebp-10h]
  Scaleform::Render::Tessellator::TriangleType tri; // [esp+74h] [ebp-Ch] BYREF
  float dy1b; // [esp+84h] [ebp+4h]
  float dy1c; // [esp+84h] [ebp+4h]
  float dy1d; // [esp+84h] [ebp+4h]
  float dy1e; // [esp+84h] [ebp+4h]
  float dy1f; // [esp+84h] [ebp+4h]
  float dy1g; // [esp+84h] [ebp+4h]
  float dy1; // [esp+84h] [ebp+4h]
  float dy1h; // [esp+84h] [ebp+4h]
  float dy1a; // [esp+84h] [ebp+4h]
  float dy1i; // [esp+84h] [ebp+4h]
  float dy1j; // [esp+84h] [ebp+4h]
  float dy1k; // [esp+84h] [ebp+4h]
  float dy1l; // [esp+84h] [ebp+4h]
  float dy1m; // [esp+84h] [ebp+4h]
  float dy1n; // [esp+84h] [ebp+4h]
  float dy1o; // [esp+84h] [ebp+4h]
  float dy1p; // [esp+84h] [ebp+4h]
  float dy2a; // [esp+88h] [ebp+8h]
  float dy2b; // [esp+88h] [ebp+8h]
  float dy2; // [esp+88h] [ebp+8h]

  node2 = e1->node2;
  Pages = this->MeshVertices.Pages;
  v6 = e1->node1 & 0xFFFFFFF;
  width = this->EdgeAAWidth * -2.0;
  v7 = &Pages[v6 >> 4][v6 & 0xF];
  refVertex = node2 & 0xFFFFFFF;
  v8 = &Pages[(node2 & 0xFFFFFFF) >> 4][node2 & 0xF];
  v9 = e2->node2 & 0xFFFFFFF;
  d1 = v8->x - v7->x;
  dy2a = d1;
  v10 = &Pages[v9 >> 4][v9 & 0xF];
  dy1b = v8->y - v7->y;
  dy1c = dy1b * dy1b + dy2a * dy2a;
  dy1d = sqrt(dy1c);
  len1 = dy1d;
  x = v10->x - v8->x;
  dy2b = x;
  dy1e = v10->y - v8->y;
  dy1f = dy1e * dy1e + dy2b * dy2b;
  dy1g = sqrt(dy1f);
  len2 = dy1g;
  turn = Scaleform::Render::Math2D::TurnRatio<Scaleform::Render::TessVertex,Scaleform::Render::TessVertex,Scaleform::Render::TessVertex>(
           v7,
           v8,
           v10,
           len1,
           dy1g);
  v11 = dy1g;
  epsilon = (dy1g + len1) * this->IntersectionEpsilon;
  dx1 = (v7->y - v8->y) * width / len1;
  dy1 = d1 * width / len1;
  dx2 = (v8->y - v10->y) * width / len2;
  dy2 = width * x / len2;
  xi = v8->x;
  yi = v8->y;
  *(float *)&d1 = fabs(turn);
  if ( *(float *)&d1 >= 0.125 )
  {
    *(double *)&tri.d.m.v1 = v8->x + dx1;
    *(float *)&x = *(double *)&tri.d.m.v1;
    ya = epsilon;
    epsilon = v10->y + dy2;
    dy = epsilon;
    epsilon = v10->x + dx2;
    v22 = epsilon;
    epsilon = dy2 + v8->y;
    cy = epsilon;
    epsilon = dx2 + v8->x;
    v20 = epsilon;
    epsilon = dy1 + v8->y;
    by = epsilon;
    epsilon = dy1 + v7->y;
    ay = epsilon;
    epsilon = dx1 + v7->x;
    if ( Scaleform::Render::Math2D::Intersection(epsilon, ay, *(float *)&x, by, v20, cy, v22, dy, &xi, &yi, ya) )
    {
      *(float *)&d1 = xi - v8->x;
      epsilon = yi - v8->y;
      epsilon = epsilon * epsilon + *(float *)&d1 * *(float *)&d1;
      epsilon = sqrt(epsilon);
      *(float *)&d1 = epsilon;
      v13 = turn;
      if ( turn <= 0.0 )
      {
        v15 = this;
        epsilon = -width * 4.0;
        if ( epsilon < (double)*(float *)&d1 )
        {
          v16 = dy1;
          dy1j = dx1 * 2.0 + dy1 + v8->y;
          yb = dy1j;
          dy1k = *(double *)&tri.d.m.v1 - v16 * 2.0;
          Scaleform::Render::Tessellator::emitStrokerVertex(this, dy1k, yb);
          dy1l = dy2 + v8->y - dx2 * 2.0;
          yc = dy1l;
          dy1m = dx2 + v8->x + 2.0 * dy2;
          Scaleform::Render::Tessellator::emitStrokerVertex(this, dy1m, yc);
          Size = this->MeshVertices.Size;
          tri.d.t.v3 = Size - 1;
          tri.d.t.v1 = refVertex;
          tri.d.t.v2 = Size - 2;
          Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::PushBack(
            &this->MeshTriangles,
            0,
            &tri);
          return 2;
        }
      }
      else
      {
        v14 = len1;
        if ( len2 <= (double)len1 )
          v14 = len2;
        turn = v14;
        v15 = this;
        epsilon = turn / v13;
        if ( epsilon < (double)*(float *)&d1 )
          goto LABEL_15;
      }
      Scaleform::Render::Tessellator::emitStrokerVertex(v15, xi, yi);
      return 1;
    }
LABEL_15:
    dy1n = dy1 + v8->y;
    Scaleform::Render::Tessellator::emitStrokerVertex(this, *(float *)&x, dy1n);
    dy1o = dy2 + v8->y;
    yd = dy1o;
    dy1p = v8->x + dx2;
    Scaleform::Render::Tessellator::emitStrokerVertex(this, dy1p, yd);
    return 2;
  }
  if ( len1 <= v11 )
  {
    dy1i = dy2 + v8->y;
    y = dy1i;
    dy1a = v8->x + dx2;
  }
  else
  {
    dy1h = dy1 + v8->y;
    y = dy1h;
    dy1a = v8->x + dx1;
  }
  Scaleform::Render::Tessellator::emitStrokerVertex(this, dy1a, y);
  return 1;
}
