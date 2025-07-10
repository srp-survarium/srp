void __thiscall Scaleform::Render::Scale9GridData::MakeMeshKey(
        Scaleform::Render::Scale9GridData *this,
        Scaleform::Render::Rect<float> *keyData)
{
  *keyData = this->S9Rect;
  keyData[1] = this->Bounds;
  Scaleform::Render::MeshKey::CalcMatrixKey(&this->ViewMtx, &keyData[2].x1, 0);
  keyData[2].y2 = this->ShapeMtx.M[0][3];
  keyData[3].x1 = this->ShapeMtx.M[1][3];
}
