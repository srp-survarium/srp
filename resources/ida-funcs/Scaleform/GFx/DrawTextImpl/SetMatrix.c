void __thiscall Scaleform::GFx::DrawTextImpl::SetMatrix(
        Scaleform::GFx::DrawTextImpl *this,
        const Scaleform::Render::Matrix2x4<float> *matrix)
{
  Scaleform::Render::TreeText *pObject; // ecx
  Scaleform::Render::Matrix2x4<float> m; // [esp+0h] [ebp-20h] BYREF

  pObject = this->pTextNode.pObject;
  m.M[0][0] = matrix->M[0][0];
  m.M[0][1] = matrix->M[0][1];
  m.M[0][2] = matrix->M[0][2];
  m.M[0][3] = matrix->M[0][3];
  m.M[1][0] = matrix->M[1][0];
  m.M[1][1] = matrix->M[1][1];
  m.M[1][2] = matrix->M[1][2];
  m.M[1][3] = matrix->M[1][3];
  m.M[0][3] = m.M[0][3] * 20.0;
  m.M[1][3] = 20.0 * m.M[1][3];
  Scaleform::Render::TreeNode::SetMatrix(pObject, &m);
}
