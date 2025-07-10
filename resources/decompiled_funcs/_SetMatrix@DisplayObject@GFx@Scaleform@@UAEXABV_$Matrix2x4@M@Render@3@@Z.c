void __thiscall Scaleform::GFx::DisplayObject::SetMatrix(
        Scaleform::GFx::DisplayObject *this,
        const Scaleform::Render::Matrix2x4<float> *mt)
{
  Scaleform::GFx::DisplayObject::ScrollRectInfo *pScrollRect; // ecx
  Scaleform::GFx::DisplayObject::ScrollRectInfo *v4; // eax
  Scaleform::Render::TreeNode *RenderNode; // eax
  Scaleform::GFx::DisplayObject::ScrollRectInfo *v6; // eax
  float v7; // [esp+C8h] [ebp-78h]
  float x1; // [esp+C8h] [ebp-78h]
  float v9; // [esp+CCh] [ebp-74h]
  float y1; // [esp+CCh] [ebp-74h]
  Scaleform::Render::Matrix2x4<float> v11; // [esp+D0h] [ebp-70h] BYREF
  Scaleform::Render::Matrix2x4<float> v12; // [esp+F0h] [ebp-50h] BYREF
  unsigned __int8 src[48]; // [esp+110h] [ebp-30h] BYREF

  pScrollRect = this->pScrollRect;
  if ( pScrollRect )
  {
    *(float *)src = mt->M[0][0];
    *(float *)&src[4] = mt->M[0][1];
    *(float *)&src[8] = mt->M[0][2];
    *(float *)&src[12] = mt->M[0][3];
    *(float *)&src[16] = mt->M[1][0];
    *(float *)&src[20] = mt->M[1][1];
    *(float *)&src[24] = mt->M[1][2];
    *(float *)&src[28] = mt->M[1][3];
    *(float *)&src[32] = 0.0;
    *(float *)&src[36] = 0.0;
    *(float *)&src[40] = 1.0;
    *(float *)&src[44] = 0.0;
    memcpy((unsigned __int8 *)&pScrollRect->OrigTransformMatrix, src, sizeof(pScrollRect->OrigTransformMatrix));
    v4 = this->pScrollRect;
    v11.M[0][0] = v4->OrigTransformMatrix.M[0][0];
    v11.M[0][1] = v4->OrigTransformMatrix.M[0][1];
    v11.M[0][2] = v4->OrigTransformMatrix.M[0][2];
    v11.M[0][3] = v4->OrigTransformMatrix.M[0][3];
    v11.M[1][0] = v4->OrigTransformMatrix.M[1][0];
    v11.M[1][1] = v4->OrigTransformMatrix.M[1][1];
    v11.M[1][2] = v4->OrigTransformMatrix.M[1][2];
    v11.M[1][3] = v4->OrigTransformMatrix.M[1][3];
    v9 = -v4->Rectangle.x1;
    v7 = -v4->Rectangle.y1;
    v11.M[0][3] = v11.M[0][0] * v9 + v11.M[0][1] * v7 + v11.M[0][3];
    v11.M[1][3] = v9 * v11.M[1][0] + v7 * v11.M[1][1] + v11.M[1][3];
    RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    Scaleform::Render::TreeNode::SetMatrix(RenderNode, &v11);
    v12.M[0][0] = 1.0;
    v12.M[0][1] = 0.0;
    v12.M[0][2] = 0.0;
    v6 = this->pScrollRect;
    v12.M[0][3] = 0.0;
    v12.M[1][0] = 0.0;
    v12.M[1][2] = 0.0;
    v12.M[1][3] = 0.0;
    v12.M[1][1] = 1.0;
    x1 = v6->Rectangle.x1;
    y1 = v6->Rectangle.y1;
    v12.M[0][3] = y1 * 0.0 + x1 + 0.0;
    v12.M[1][3] = y1 + x1 * 0.0 + 0.0;
    Scaleform::Render::TreeNode::SetMatrix(v6->Mask.pObject->pTreeContainer.pObject, &v12);
  }
  else
  {
    Scaleform::GFx::DisplayObjectBase::SetMatrix(this, mt);
  }
}
