Scaleform::Render::CacheEffect *__cdecl Scaleform::Render::MaskEffect::Create(
        Scaleform::Render::TreeCacheNode *node,
        const Scaleform::Render::State *__formal,
        Scaleform::Render::CacheEffect *next)
{
  char v3; // al
  Scaleform::Render::MaskEffectState v4; // edi
  Scaleform::Render::MatrixPoolImpl::MatrixPool *MatrixPool; // eax
  Scaleform::Render::MaskEffect *v6; // eax
  int v7; // eax
  int v8; // esi
  Scaleform::Render::MatrixPoolImpl::HMatrix areaMatrix; // [esp+Ch] [ebp-A8h] BYREF
  int v11; // [esp+10h] [ebp-A4h] BYREF
  Scaleform::Render::Rect<float> v12; // [esp+14h] [ebp-A0h] BYREF
  Scaleform::Render::Matrix2x4<float> v13; // [esp+24h] [ebp-90h] BYREF
  Scaleform::Render::Matrix3x4<float> pviewMatrix; // [esp+44h] [ebp-70h] BYREF
  Scaleform::Render::Matrix4x4<float> pviewProj; // [esp+74h] [ebp-40h] BYREF

  v12.x1 = 0.0;
  v12.y1 = 0.0;
  v12.x2 = 0.0;
  v12.y2 = 0.0;
  v13.M[0][0] = 1.0;
  v13.M[1][1] = 1.0;
  v13.M[0][1] = 0.0;
  v13.M[0][2] = 0.0;
  v13.M[0][3] = 0.0;
  v13.M[1][0] = 0.0;
  v13.M[1][2] = 0.0;
  v13.M[1][3] = 0.0;
  memset((int)&pviewMatrix, 0, sizeof(pviewMatrix));
  pviewMatrix.M[0][0] = 1.0;
  pviewMatrix.M[1][1] = 1.0;
  pviewMatrix.M[2][2] = 1.0;
  memset((int)&pviewProj, 0, sizeof(pviewProj));
  pviewProj.M[0][0] = 1.0;
  pviewProj.M[1][1] = 1.0;
  pviewProj.M[2][2] = 1.0;
  pviewProj.M[3][3] = 1.0;
  Scaleform::Render::TreeCacheNode::CalcViewMatrix(node, (__m128i *)&pviewMatrix, &pviewProj);
  v3 = Scaleform::Render::TreeCacheNode::CalcFilterFlag(node);
  v4 = Scaleform::Render::TreeCacheNode::calcMaskBounds(
         node,
         &v12,
         &v13,
         &pviewMatrix,
         &pviewProj,
         MES_NoMask,
         v3 != 0 ? 0x100 : 0);
  MatrixPool = Scaleform::Render::TreeCacheNode::GetMatrixPool(node);
  Scaleform::Render::MatrixPoolImpl::MatrixPool::CreateMatrix(MatrixPool, &areaMatrix, &v13, 0);
  v11 = 74;
  v6 = (Scaleform::Render::MaskEffect *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                          Scaleform::Memory::pGlobalHeap,
                                          node,
                                          116,
                                          &v11);
  if ( v6 )
  {
    Scaleform::Render::MaskEffect::MaskEffect(v6, node, v4, &areaMatrix, next);
    v8 = v7;
  }
  else
  {
    v8 = 0;
  }
  if ( areaMatrix.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    Scaleform::Render::MatrixPoolImpl::DataHeader::Release(areaMatrix.pHandle->pHeader);
  return (Scaleform::Render::CacheEffect *)v8;
}
