void __thiscall Scaleform::Render::Scale9GridTess::transformVertex(
        Scaleform::Render::Scale9GridTess *this,
        const Scaleform::Render::Scale9GridInfo *s9g,
        Scaleform::Render::Image9GridVertex *v)
{
  float *v3; // eax
  double y; // st6
  double x; // st7
  double v6; // st6
  double v7; // st7

  v3 = (float *)&s9g->ResultingMatrices[codeToMtx[(s9g->ResultingGrid.x2 < (double)v->x)
                                                | (2
                                                 * ((s9g->ResultingGrid.y2 < (double)v->y)
                                                  | (2
                                                   * ((s9g->ResultingGrid.x1 > (double)v->x)
                                                    | (2 * (s9g->ResultingGrid.y1 > (double)v->y))))))]];
  y = v->y;
  x = v->x;
  v->x = *v3 * x + v3[1] * y + v3[3];
  v->y = x * v3[4] + y * v3[5] + v3[7];
  v6 = v->y;
  v7 = v->x;
  v->x = s9g->InverseMatrix.M[0][0] * v7 + s9g->InverseMatrix.M[0][1] * v6 + s9g->InverseMatrix.M[0][3];
  v->y = v7 * s9g->InverseMatrix.M[1][0] + v6 * s9g->InverseMatrix.M[1][1] + s9g->InverseMatrix.M[1][3];
}
