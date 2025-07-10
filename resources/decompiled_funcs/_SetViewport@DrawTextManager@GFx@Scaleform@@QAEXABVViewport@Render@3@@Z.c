void __thiscall Scaleform::GFx::DrawTextManager::SetViewport(
        Scaleform::GFx::DrawTextManager *this,
        const Scaleform::Render::Viewport *vp)
{
  Scaleform::Render::Matrix2x4<float> v3; // [esp+50h] [ebp-40h] BYREF
  Scaleform::Render::Matrix2x4<float> v4; // [esp+70h] [ebp-20h] BYREF

  Scaleform::Render::TreeRoot::SetViewport(this->pImpl->pRootNode.pObject, vp);
  v3.M[0][0] = 1.0;
  v3.M[0][1] = 0.0;
  v3.M[0][2] = 0.0;
  v3.M[0][3] = 0.0;
  v3.M[1][0] = 0.0;
  v3.M[1][2] = 0.0;
  v3.M[1][3] = 0.0;
  v3.M[1][1] = 1.0;
  v4.M[0][0] = 0.050000001;
  v4.M[1][1] = 0.050000001;
  v4.M[0][1] = 0.0;
  v4.M[0][2] = 0.0;
  v4.M[0][3] = 0.0;
  v4.M[1][0] = 0.0;
  v4.M[1][2] = 0.0;
  v4.M[1][3] = 0.0;
  Scaleform::Render::Matrix2x4<float>::Prepend(&v3, &v4);
  Scaleform::Render::TreeNode::SetMatrix(this->pImpl->pRootNode.pObject, &v3);
}
