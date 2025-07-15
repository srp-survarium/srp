char __thiscall Scaleform::Render::MaskEffect::Update(
        Scaleform::Render::MaskEffect *this,
        const Scaleform::Render::State *stateArg)
{
  Scaleform::Render::TreeCacheNode *pSourceNode; // edi
  char v4; // bl
  char v5; // al
  Scaleform::Render::MaskEffectState v6; // eax
  int v7; // ecx
  Scaleform::Render::SortKeyMaskType v8; // edi
  Scaleform::Render::SortKeyInterface **v9; // eax
  Scaleform::Render::SortKeyInterface **v10; // edi
  void *Data; // eax
  Scaleform::Render::MaskEffectState v13; // [esp+298h] [ebp-ACh]
  Scaleform::Render::SortKey v14; // [esp+29Ch] [ebp-A8h] BYREF
  Scaleform::Render::Rect<float> v15; // [esp+2A4h] [ebp-A0h] BYREF
  Scaleform::Render::Matrix2x4<float> boundAreaMatrix; // [esp+2B4h] [ebp-90h] BYREF
  Scaleform::Render::Matrix3x4<float> dst; // [esp+2D4h] [ebp-70h] BYREF
  Scaleform::Render::Matrix4x4<float> pviewProj; // [esp+304h] [ebp-40h] BYREF

  v15.x1 = 0.0;
  v15.y1 = 0.0;
  v15.x2 = 0.0;
  v15.y2 = 0.0;
  pSourceNode = this->StartEntry.pSourceNode;
  boundAreaMatrix.M[0][0] = 1.0;
  boundAreaMatrix.M[1][1] = 1.0;
  v4 = 0;
  boundAreaMatrix.M[0][1] = 0.0;
  boundAreaMatrix.M[0][2] = 0.0;
  boundAreaMatrix.M[0][3] = 0.0;
  boundAreaMatrix.M[1][0] = 0.0;
  boundAreaMatrix.M[1][2] = 0.0;
  boundAreaMatrix.M[1][3] = 0.0;
  memset((int)&dst, 0, sizeof(dst));
  dst.M[0][0] = 1.0;
  dst.M[1][1] = 1.0;
  dst.M[2][2] = 1.0;
  memset((int)&pviewProj, 0, sizeof(pviewProj));
  pviewProj.M[0][0] = 1.0;
  pviewProj.M[1][1] = 1.0;
  pviewProj.M[2][2] = 1.0;
  pviewProj.M[3][3] = 1.0;
  Scaleform::Render::TreeCacheNode::CalcViewMatrix(pSourceNode, &dst, &pviewProj);
  v5 = Scaleform::Render::TreeCacheNode::CalcFilterFlag(pSourceNode);
  v6 = Scaleform::Render::TreeCacheNode::calcMaskBounds(
         pSourceNode,
         &v15,
         &boundAreaMatrix,
         &dst,
         &pviewProj,
         this->MES,
         v5 != 0 ? 0x100 : 0);
  v13 = v6;
  if ( v6 == MES_Clipped )
  {
    v7 = 5;
    v8 = SortKeyMask_PushClipped;
  }
  else
  {
    v7 = 4;
    v8 = SortKeyMask_Push;
  }
  if ( v7 != this->StartEntry.Key.pImpl->Type )
  {
    Scaleform::Render::BundleEntry::ClearBundle(&this->StartEntry);
    Scaleform::Render::SortKey::SortKey(&v14, v8);
    v10 = v9;
    (*v9)->AddRef(*v9, v9[1]);
    this->StartEntry.Key.pImpl->Release(this->StartEntry.Key.pImpl, this->StartEntry.Key.Data);
    this->StartEntry.Key.pImpl = *v10;
    Data = v14.Data;
    this->StartEntry.Key.Data = v10[1];
    v14.pImpl->Release(v14.pImpl, Data);
    v6 = v13;
    v4 = 1;
  }
  this->MES = v6;
  Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix2D(&this->BoundsMatrix, &boundAreaMatrix);
  return v4;
}
