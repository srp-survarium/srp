void __thiscall Scaleform::Render::TreeCacheNode::updateMaskTransform(
        Scaleform::Render::TreeCacheNode *this,
        Scaleform::Render::TransformArgs *t,
        Scaleform::Render::TransformFlags flags)
{
  Scaleform::Render::TreeCacheNode *pMask; // eax
  const Scaleform::Render::TreeNode::NodeData *v4; // esi
  Scaleform::Render::Matrix3x4<float> dst; // [esp+10h] [ebp-30h] BYREF

  pMask = this->pMask;
  if ( pMask )
  {
    v4 = (const Scaleform::Render::TreeNode::NodeData *)(*(_DWORD *)(*(_DWORD *)(((int)pMask->pNode & 0xFFFFF000) + 0x14)
                                                                   + 4
                                                                   * ((int)((int)&pMask->pNode[-1]
                                                                          - ((int)pMask->pNode & 0xFFFFF000))
                                                                    / 28)
                                                                   + 20)
                                                       & 0xFFFFFFFE);
    if ( (flags & 0x80u) != 0 )
    {
      memcpy((int)&dst, (const __m128i *)&t->Mat3D, sizeof(dst));
      Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&t->Mat3D, &dst, &v4->M34);
    }
    else
    {
      Scaleform::Render::Matrix2x4<float>::Prepend(&t->Mat, (const Scaleform::Render::Matrix2x4<float> *)&v4->M34);
    }
    this->pMask->UpdateTransform(this->pMask, v4, t, flags);
  }
}
