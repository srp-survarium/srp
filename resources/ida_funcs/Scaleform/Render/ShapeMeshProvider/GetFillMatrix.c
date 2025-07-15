void __thiscall Scaleform::Render::ShapeMeshProvider::GetFillMatrix(
        Scaleform::Render::ShapeMeshProvider *this,
        Scaleform::Render::MeshBase *mesh,
        Scaleform::Render::Matrix2x4<float> *matrix,
        unsigned int drawLayer,
        unsigned int fillIndex,
        unsigned int meshGenFlags)
{
  Scaleform::Render::ComplexFill *ComplexFill; // eax
  Scaleform::Render::ComplexFill *v8; // ecx
  Scaleform::Render::Matrix2x4<float> *p_ImageMatrix; // edi
  double v10; // st7
  Scaleform::Render::Matrix2x4<float> *MorphMatrix; // eax
  const Scaleform::Render::Matrix2x4<float> *v12; // eax
  Scaleform::Render::Scale9GridData *pObject; // eax
  Scaleform::Render::TextureManager *v14; // eax
  const Scaleform::Render::Matrix2x4<float> *Inverse; // [esp+174h] [ebp-88h]
  float t; // [esp+178h] [ebp-84h]
  Scaleform::Render::ComplexFill *v17; // [esp+18Ch] [ebp-70h]
  unsigned int v18; // [esp+190h] [ebp-6Ch] BYREF
  Scaleform::Render::ShapeMeshProvider *v19; // [esp+194h] [ebp-68h]
  float MorphRatio; // [esp+198h] [ebp-64h]
  Scaleform::Render::Matrix2x4<float> result; // [esp+19Ch] [ebp-60h] BYREF
  Scaleform::Render::Matrix2x4<float> m; // [esp+1BCh] [ebp-40h] BYREF
  Scaleform::Render::Matrix2x4<float> v23; // [esp+1DCh] [ebp-20h] BYREF

  v18 = 0;
  v19 = (Scaleform::Render::ShapeMeshProvider *)((char *)this - 8);
  ComplexFill = Scaleform::Render::ShapeMeshProvider::getComplexFill(
                  (Scaleform::Render::ShapeMeshProvider *)((char *)this - 8),
                  drawLayer,
                  fillIndex,
                  &v18);
  v8 = ComplexFill;
  v17 = ComplexFill;
  if ( ComplexFill )
  {
    *matrix = ComplexFill->ImageMatrix;
    p_ImageMatrix = &ComplexFill->ImageMatrix;
    v10 = 0.0;
    if ( this->FillToStyleTable.Data.Policy.Capacity && 0.0 != mesh->MorphRatio )
    {
      MorphRatio = mesh->MorphRatio;
      t = MorphRatio;
      MorphMatrix = Scaleform::Render::ShapeMeshProvider::getMorphMatrix(v19, &result, drawLayer, fillIndex);
      Inverse = Scaleform::Render::Matrix2x4<float>::GetInverse(MorphMatrix, &m);
      v12 = Scaleform::Render::Matrix2x4<float>::GetInverse(p_ImageMatrix, &v23);
      Scaleform::Render::Matrix2x4<float>::SetLerp(matrix, v12, Inverse, t);
      Scaleform::Render::Matrix2x4<float>::Invert(matrix);
      v10 = 0.0;
      v8 = v17;
    }
    if ( mesh )
    {
      pObject = mesh->pScale9Grid.pObject;
      if ( pObject )
      {
        result.M[0][0] = 1.0;
        result.M[1][1] = 1.0;
        result.M[0][1] = v10;
        result.M[0][2] = v10;
        result.M[0][3] = v10;
        result.M[1][0] = v10;
        result.M[1][2] = v10;
        result.M[1][3] = v10;
        Scaleform::Render::ShapeMeshProvider::computeImgAdjustMatrix(v19, pObject, drawLayer, v18, &result);
        m.M[0][0] = 1.0;
        m.M[0][1] = 0.0;
        m.M[0][2] = 0.0;
        m.M[0][3] = 0.0;
        m.M[1][0] = 0.0;
        m.M[1][2] = 0.0;
        m.M[1][3] = 0.0;
        m.M[1][1] = 1.0;
        Scaleform::Render::Matrix2x4<float>::SetInverse(&m, &result);
        Scaleform::Render::Matrix2x4<float>::Prepend(matrix, &m);
        v8 = v17;
      }
    }
    if ( v8->pImage.pObject )
    {
      v14 = mesh->pRenderer2D->pHal.pObject->GetTextureManager(mesh->pRenderer2D->pHal.pObject);
      v17->pImage.pObject->GetUVGenMatrix(v17->pImage.pObject, &m, v14);
      Scaleform::Render::Matrix2x4<float>::Append(matrix, &m);
    }
  }
  else
  {
    matrix->M[0][0] = 1.0;
    matrix->M[0][1] = 0.0;
    matrix->M[0][2] = 0.0;
    matrix->M[0][3] = 0.0;
    matrix->M[1][0] = 0.0;
    matrix->M[1][2] = 0.0;
    matrix->M[1][3] = 0.0;
    matrix->M[1][1] = 1.0;
  }
}
