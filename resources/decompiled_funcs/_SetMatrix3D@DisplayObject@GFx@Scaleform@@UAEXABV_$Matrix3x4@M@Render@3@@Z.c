void __thiscall Scaleform::GFx::DisplayObject::SetMatrix3D(
        Scaleform::GFx::DisplayObject *this,
        Scaleform::Render::Matrix3x4<float> *mt)
{
  Scaleform::GFx::DisplayObject::ScrollRectInfo *pScrollRect; // eax
  Scaleform::GFx::DisplayObject::ScrollRectInfo *v4; // eax
  Scaleform::Render::TreeNode *RenderNode; // eax
  Scaleform::GFx::DisplayObject::ScrollRectInfo *v6; // eax
  float v7; // [esp+2A8h] [ebp-F8h]
  float y1; // [esp+2A8h] [ebp-F8h]
  float v9; // [esp+2ACh] [ebp-F4h]
  float x1; // [esp+2ACh] [ebp-F4h]
  Scaleform::Render::Matrix3x4<float> v11; // [esp+2B0h] [ebp-F0h] BYREF
  Scaleform::Render::Matrix3x4<float> m2; // [esp+2E0h] [ebp-C0h] BYREF
  Scaleform::Render::Matrix3x4<float> src; // [esp+310h] [ebp-90h] BYREF
  Scaleform::Render::Matrix3x4<float> dst; // [esp+340h] [ebp-60h] BYREF
  Scaleform::Render::Matrix3x4<float> m1; // [esp+370h] [ebp-30h] BYREF

  pScrollRect = this->pScrollRect;
  if ( pScrollRect )
  {
    memcpy(
      (unsigned __int8 *)&pScrollRect->OrigTransformMatrix,
      (unsigned __int8 *)mt,
      sizeof(pScrollRect->OrigTransformMatrix));
    this->pScrollRect->IsOrig3D = 1;
    memcpy((unsigned __int8 *)&dst, (unsigned __int8 *)&this->pScrollRect->OrigTransformMatrix, sizeof(dst));
    v4 = this->pScrollRect;
    v7 = -v4->Rectangle.x1;
    v9 = -v4->Rectangle.y1;
    memset((int)&m2, 0, sizeof(m2));
    m2.M[0][0] = 1.0;
    m2.M[1][1] = 1.0;
    m2.M[2][2] = 1.0;
    m2.M[0][3] = v7;
    m2.M[1][3] = v9;
    m2.M[2][3] = 0.0;
    memcpy((unsigned __int8 *)&m1, (unsigned __int8 *)&dst, sizeof(m1));
    Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&dst, &m1, &m2);
    RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    Scaleform::Render::TreeNode::SetMatrix3D(RenderNode, &dst);
    memset((int)&src, 0, sizeof(src));
    v6 = this->pScrollRect;
    src.M[0][0] = 1.0;
    src.M[1][1] = 1.0;
    src.M[2][2] = 1.0;
    x1 = v6->Rectangle.x1;
    y1 = v6->Rectangle.y1;
    memset((int)&v11, 0, sizeof(v11));
    v11.M[0][0] = 1.0;
    v11.M[1][1] = 1.0;
    v11.M[2][2] = 1.0;
    v11.M[0][3] = x1;
    v11.M[1][3] = y1;
    v11.M[2][3] = 0.0;
    memcpy((unsigned __int8 *)&m1, (unsigned __int8 *)&src, sizeof(m1));
    Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&src, &m1, &v11);
    Scaleform::Render::TreeNode::SetMatrix3D(this->pScrollRect->Mask.pObject->pTreeContainer.pObject, &src);
  }
  else
  {
    Scaleform::GFx::DisplayObjectBase::SetMatrix3D(this, mt);
  }
}
