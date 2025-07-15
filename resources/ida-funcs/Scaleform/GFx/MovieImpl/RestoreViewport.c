void __thiscall Scaleform::GFx::MovieImpl::RestoreViewport(Scaleform::GFx::MovieImpl *this)
{
  int v1; // ecx

  Scaleform::GFx::MovieImpl::ResetViewportMatrix(this);
  Scaleform::Render::TreeNode::SetMatrix(
    *(Scaleform::Render::TreeNode **)(v1 + 68),
    (const Scaleform::Render::Matrix2x4<float> *)(v1 + 192));
}
