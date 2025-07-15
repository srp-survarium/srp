void __thiscall Scaleform::GFx::DisplayObjectBase::SetMatrix(
        Scaleform::GFx::DisplayObjectBase *this,
        const Scaleform::Render::Matrix2x4<float> *m)
{
  Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *pIndXFormData; // ecx
  Scaleform::Render::TreeNode *v4; // eax
  Scaleform::Render::TreeNode *RenderNode; // eax
  unsigned __int8 src[48]; // [esp+10h] [ebp-30h] BYREF

  pIndXFormData = this->pIndXFormData;
  if ( pIndXFormData )
  {
    *(float *)src = m->M[0][0];
    *(float *)&src[4] = m->M[0][1];
    *(float *)&src[8] = m->M[0][2];
    *(float *)&src[12] = m->M[0][3];
    *(float *)&src[16] = m->M[1][0];
    *(float *)&src[20] = m->M[1][1];
    *(float *)&src[24] = m->M[1][2];
    *(float *)&src[28] = m->M[1][3];
    *(float *)&src[32] = 0.0;
    *(float *)&src[36] = 0.0;
    *(float *)&src[40] = 1.0;
    *(float *)&src[44] = 0.0;
    memcpy((int)pIndXFormData, (const __m128i *)src, 0x30u);
    RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    Scaleform::Render::ContextImpl::Entry::getWritableData(RenderNode, 1u);
    Scaleform::GFx::DisplayObjectBase::UpdateViewAndPerspective(this);
  }
  else
  {
    v4 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    Scaleform::Render::TreeNode::SetMatrix(v4, m);
    Scaleform::GFx::DisplayObjectBase::UpdateViewAndPerspective(this);
  }
}
