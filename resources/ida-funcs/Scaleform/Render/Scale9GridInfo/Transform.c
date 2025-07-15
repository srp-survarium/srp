int __thiscall Scaleform::Render::Scale9GridInfo::Transform(
        Scaleform::Render::Scale9GridInfo *this,
        float *x,
        float *y)
{
  double v4; // st6
  double v5; // st7
  int result; // eax
  float *v7; // edx
  double v8; // st7
  double v9; // st7
  float v10; // [esp+18h] [ebp+4h]
  float v11; // [esp+18h] [ebp+4h]

  v4 = *y;
  v5 = *x;
  *x = this->ShapeMatrix.M[0][0] * v5 + this->ShapeMatrix.M[0][1] * v4 + this->ShapeMatrix.M[0][3];
  v10 = v5 * this->ShapeMatrix.M[1][0] + v4 * this->ShapeMatrix.M[1][1] + this->ShapeMatrix.M[1][3];
  *y = v10;
  result = (this->ResultingGrid.x2 < (double)*x)
         | (2
          * ((this->ResultingGrid.y2 < (double)v10)
           | (2 * ((this->ResultingGrid.x1 > (double)*x) | (2 * (this->ResultingGrid.y1 > (double)v10))))));
  v7 = (float *)&this->ResultingMatrices[codeToMtx[result]];
  v8 = *x;
  *x = *v7 * v8 + v7[1] * v10 + v7[3];
  v11 = v8 * v7[4] + v10 * v7[5] + v7[7];
  *y = v11;
  v9 = *x;
  *x = this->InverseMatrix.M[0][0] * v9 + this->InverseMatrix.M[0][1] * v11 + this->InverseMatrix.M[0][3];
  *y = v9 * this->InverseMatrix.M[1][0] + v11 * this->InverseMatrix.M[1][1] + this->InverseMatrix.M[1][3];
  return result;
}
