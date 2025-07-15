Scaleform::Render::CacheEffect *__cdecl Scaleform::Render::FilterEffect::Create(
        Scaleform::Render::TreeCacheNode *node,
        Scaleform::Render::FilterState *stateArg,
        Scaleform::Render::CacheEffect *next)
{
  Scaleform::Render::MatrixPoolImpl::MatrixPool *MatrixPool; // eax
  Scaleform::Render::FilterEffect *v4; // eax
  int v5; // eax
  int v6; // esi
  Scaleform::Render::MatrixPoolImpl::HMatrix m; // [esp+Ch] [ebp-D4h] BYREF
  Scaleform::Render::Matrix2x4<float> v9; // [esp+10h] [ebp-D0h] BYREF
  __m128 v10; // [esp+30h] [ebp-B0h] BYREF
  int v11; // [esp+4Ch] [ebp-94h] BYREF
  Scaleform::Render::Matrix3x4<float> pviewMatrix; // [esp+50h] [ebp-90h] BYREF
  Scaleform::Render::Matrix4x4<float> pviewProj; // [esp+80h] [ebp-60h] BYREF
  Scaleform::Render::Cxform dest; // [esp+C0h] [ebp-20h] BYREF

  v10.m128_f32[0] = 0.0;
  v10.m128_f32[1] = 0.0;
  v10.m128_f32[2] = 0.0;
  v10.m128_f32[3] = 0.0;
  v9.M[0][0] = 1.0;
  v9.M[1][1] = 1.0;
  v9.M[0][1] = 0.0;
  v9.M[0][2] = 0.0;
  v9.M[0][3] = 0.0;
  v9.M[1][0] = 0.0;
  v9.M[1][2] = 0.0;
  v9.M[1][3] = 0.0;
  Scaleform::Render::Cxform::Cxform(&dest);
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
  Scaleform::Render::TreeCacheNode::CalcCxform(node, &dest);
  if ( !Scaleform::Render::TreeCacheNode::calcFilterBounds(node, &v10, &v9, &pviewMatrix, &pviewProj, 0) )
  {
    v10.m128_f32[0] = 0.0;
    v10.m128_f32[1] = 0.0;
    v10.m128_f32[2] = 0.0;
    v10.m128_f32[3] = 0.0;
    v9.M[0][0] = 1.0;
    v9.M[1][1] = 1.0;
    v9.M[0][1] = 0.0;
    v9.M[0][2] = 0.0;
    v9.M[0][3] = 0.0;
    v9.M[1][0] = 0.0;
    v9.M[1][2] = 0.0;
    v9.M[1][3] = 0.0;
  }
  MatrixPool = Scaleform::Render::TreeCacheNode::GetMatrixPool(node);
  Scaleform::Render::MatrixPoolImpl::MatrixPool::CreateMatrix(MatrixPool, &m, &v9, 0);
  Scaleform::Render::MatrixPoolImpl::HMatrix::SetCxform(&m, &dest);
  v11 = 74;
  v4 = (Scaleform::Render::FilterEffect *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                            Scaleform::Memory::pGlobalHeap,
                                            node,
                                            84,
                                            &v11);
  if ( v4 )
  {
    Scaleform::Render::FilterEffect::FilterEffect(v4, node, &m, stateArg, next);
    v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  if ( m.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    Scaleform::Render::MatrixPoolImpl::DataHeader::Release(m.pHandle->pHeader);
  return (Scaleform::Render::CacheEffect *)v6;
}
