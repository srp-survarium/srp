void __thiscall Scaleform::Render::Scale9GridInfo::Scale9GridInfo(
        Scaleform::Render::Scale9GridInfo *this,
        const Scaleform::Render::Rect<float> *s9Rect,
        const Scaleform::Render::Matrix2x4<float> *s9gMtx,
        const Scaleform::Render::Matrix2x4<float> *shapeMtx,
        const Scaleform::Render::Rect<float> *bounds)
{
  Scaleform::Render::Matrix2x4<float> *p_ShapeMatrix; // edi
  Scaleform::Render::Matrix2x4<float> *p_InverseMatrix; // ebx
  float y1; // [esp+14h] [ebp-4Ch]
  float v9; // [esp+14h] [ebp-4Ch]
  float x2; // [esp+18h] [ebp-48h]
  float v11; // [esp+18h] [ebp-48h]
  float y2; // [esp+1Ch] [ebp-44h]
  float v13; // [esp+1Ch] [ebp-44h]
  Scaleform::Render::Matrix2x4<float> v14; // [esp+20h] [ebp-40h] BYREF
  Scaleform::Render::Matrix2x4<float> m; // [esp+40h] [ebp-20h] BYREF

  this->__vftable = (Scaleform::Render::Scale9GridInfo_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::Scale9GridInfo_vtbl *)&Scaleform::Render::Matrix4x4Ref<float>::`vftable';
  this->Scale9.x1 = 0.0;
  this->Scale9.y1 = 0.0;
  this->Scale9.x2 = 0.0;
  this->Scale9.y2 = 0.0;
  p_ShapeMatrix = &this->ShapeMatrix;
  p_InverseMatrix = &this->InverseMatrix;
  this->S9gMatrix.M[0][0] = 1.0;
  this->S9gMatrix.M[1][1] = 1.0;
  this->S9gMatrix.M[0][1] = 0.0;
  this->S9gMatrix.M[0][2] = 0.0;
  this->S9gMatrix.M[0][3] = 0.0;
  this->S9gMatrix.M[1][0] = 0.0;
  this->S9gMatrix.M[1][2] = 0.0;
  this->S9gMatrix.M[1][3] = 0.0;
  this->ShapeMatrix.M[0][0] = 1.0;
  this->ShapeMatrix.M[1][1] = 1.0;
  this->ShapeMatrix.M[0][1] = 0.0;
  this->ShapeMatrix.M[0][2] = 0.0;
  this->ShapeMatrix.M[0][3] = 0.0;
  this->ShapeMatrix.M[1][0] = 0.0;
  this->ShapeMatrix.M[1][2] = 0.0;
  this->ShapeMatrix.M[1][3] = 0.0;
  this->Bounds.x1 = 0.0;
  this->Bounds.y1 = 0.0;
  this->Bounds.x2 = 0.0;
  this->Bounds.y2 = 0.0;
  this->ResultingGrid.x1 = 0.0;
  this->ResultingGrid.y1 = 0.0;
  this->ResultingGrid.x2 = 0.0;
  this->ResultingGrid.y2 = 0.0;
  this->InverseMatrix.M[0][0] = 1.0;
  this->InverseMatrix.M[1][1] = 1.0;
  this->InverseMatrix.M[0][1] = 0.0;
  this->InverseMatrix.M[0][2] = 0.0;
  this->InverseMatrix.M[0][3] = 0.0;
  this->InverseMatrix.M[1][0] = 0.0;
  this->InverseMatrix.M[1][2] = 0.0;
  this->InverseMatrix.M[1][3] = 0.0;
  this->ResultingMatrices[0].M[0][0] = 1.0;
  this->ResultingMatrices[0].M[1][1] = 1.0;
  this->ResultingMatrices[1].M[0][0] = 1.0;
  this->ResultingMatrices[1].M[1][1] = 1.0;
  this->ResultingMatrices[2].M[0][0] = 1.0;
  this->ResultingMatrices[2].M[1][1] = 1.0;
  this->ResultingMatrices[3].M[0][0] = 1.0;
  this->ResultingMatrices[3].M[1][1] = 1.0;
  this->ResultingMatrices[4].M[0][0] = 1.0;
  this->ResultingMatrices[4].M[1][1] = 1.0;
  this->ResultingMatrices[5].M[0][0] = 1.0;
  this->ResultingMatrices[5].M[1][1] = 1.0;
  this->ResultingMatrices[6].M[0][0] = 1.0;
  this->ResultingMatrices[6].M[1][1] = 1.0;
  this->ResultingMatrices[7].M[0][0] = 1.0;
  this->ResultingMatrices[7].M[1][1] = 1.0;
  this->ResultingMatrices[8].M[0][0] = 1.0;
  this->ResultingMatrices[8].M[1][1] = 1.0;
  this->ResultingMatrices[0].M[0][1] = 0.0;
  this->ResultingMatrices[0].M[0][2] = 0.0;
  this->ResultingMatrices[0].M[0][3] = 0.0;
  this->ResultingMatrices[0].M[1][0] = 0.0;
  this->ResultingMatrices[0].M[1][2] = 0.0;
  this->ResultingMatrices[0].M[1][3] = 0.0;
  this->ResultingMatrices[1].M[0][1] = 0.0;
  this->ResultingMatrices[1].M[0][2] = 0.0;
  this->ResultingMatrices[1].M[0][3] = 0.0;
  this->ResultingMatrices[1].M[1][0] = 0.0;
  this->ResultingMatrices[1].M[1][2] = 0.0;
  this->ResultingMatrices[1].M[1][3] = 0.0;
  this->ResultingMatrices[2].M[0][1] = 0.0;
  this->ResultingMatrices[2].M[0][2] = 0.0;
  this->ResultingMatrices[2].M[0][3] = 0.0;
  this->ResultingMatrices[2].M[1][0] = 0.0;
  this->ResultingMatrices[2].M[1][2] = 0.0;
  this->ResultingMatrices[2].M[1][3] = 0.0;
  this->ResultingMatrices[3].M[0][1] = 0.0;
  this->ResultingMatrices[3].M[0][2] = 0.0;
  this->ResultingMatrices[3].M[0][3] = 0.0;
  this->ResultingMatrices[3].M[1][0] = 0.0;
  this->ResultingMatrices[3].M[1][2] = 0.0;
  this->ResultingMatrices[3].M[1][3] = 0.0;
  this->ResultingMatrices[4].M[0][1] = 0.0;
  this->ResultingMatrices[4].M[0][2] = 0.0;
  this->ResultingMatrices[4].M[0][3] = 0.0;
  this->ResultingMatrices[4].M[1][0] = 0.0;
  this->ResultingMatrices[4].M[1][2] = 0.0;
  this->ResultingMatrices[4].M[1][3] = 0.0;
  this->ResultingMatrices[5].M[0][1] = 0.0;
  this->ResultingMatrices[5].M[0][2] = 0.0;
  this->ResultingMatrices[5].M[0][3] = 0.0;
  this->ResultingMatrices[5].M[1][0] = 0.0;
  this->ResultingMatrices[5].M[1][2] = 0.0;
  this->ResultingMatrices[5].M[1][3] = 0.0;
  this->ResultingMatrices[6].M[0][1] = 0.0;
  this->ResultingMatrices[6].M[0][2] = 0.0;
  this->ResultingMatrices[6].M[0][3] = 0.0;
  this->ResultingMatrices[6].M[1][0] = 0.0;
  this->ResultingMatrices[6].M[1][2] = 0.0;
  this->ResultingMatrices[6].M[1][3] = 0.0;
  this->ResultingMatrices[7].M[0][1] = 0.0;
  this->ResultingMatrices[7].M[0][2] = 0.0;
  this->ResultingMatrices[7].M[0][3] = 0.0;
  this->ResultingMatrices[7].M[1][0] = 0.0;
  this->ResultingMatrices[7].M[1][2] = 0.0;
  this->ResultingMatrices[7].M[1][3] = 0.0;
  this->ResultingMatrices[8].M[0][1] = 0.0;
  this->ResultingMatrices[8].M[0][2] = 0.0;
  this->ResultingMatrices[8].M[0][3] = 0.0;
  this->ResultingMatrices[8].M[1][0] = 0.0;
  this->ResultingMatrices[8].M[1][2] = 0.0;
  this->ResultingMatrices[8].M[1][3] = 0.0;
  y1 = s9Rect->y1;
  x2 = s9Rect->x2;
  y2 = s9Rect->y2;
  this->Scale9.x1 = s9Rect->x1;
  this->Scale9.y1 = y1;
  this->Scale9.x2 = x2;
  this->Scale9.y2 = y2;
  this->S9gMatrix = *s9gMtx;
  this->ShapeMatrix = *shapeMtx;
  v13 = bounds->y1;
  v11 = bounds->x2;
  v9 = bounds->y2;
  this->Bounds.x1 = bounds->x1;
  this->Bounds.y1 = v13;
  this->Bounds.x2 = v11;
  this->Bounds.y2 = v9;
  v14.M[0][0] = 1.0;
  v14.M[1][1] = 1.0;
  v14.M[0][1] = 0.0;
  v14.M[0][2] = 0.0;
  v14.M[0][3] = 0.0;
  v14.M[1][0] = 0.0;
  v14.M[1][2] = 0.0;
  v14.M[1][3] = 0.0;
  Scaleform::Render::Matrix2x4<float>::SetInverse(&v14, &this->S9gMatrix);
  *p_InverseMatrix = v14;
  m.M[0][0] = 1.0;
  m.M[0][1] = 0.0;
  m.M[0][2] = 0.0;
  m.M[0][3] = 0.0;
  m.M[1][0] = 0.0;
  m.M[1][2] = 0.0;
  m.M[1][3] = 0.0;
  m.M[1][1] = 1.0;
  Scaleform::Render::Matrix2x4<float>::SetInverse(&m, p_ShapeMatrix);
  Scaleform::Render::Matrix2x4<float>::Append(p_InverseMatrix, &m);
  Scaleform::Render::Scale9GridInfo::Compute(this);
}
