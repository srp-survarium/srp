Scaleform::Render::CacheEffect *__cdecl Scaleform::Render::FilterEffect::Create(
        Scaleform::Render::TreeCacheNode *node,
        const Scaleform::Render::FilterState *stateArg,
        Scaleform::Render::CacheEffect *next)
{
  Scaleform::Render::MatrixPoolImpl::MatrixPool *MatrixPool; // eax
  Scaleform::Render::FilterEffect *v4; // eax
  int v5; // eax
  int v6; // esi
  Scaleform::Render::MatrixPoolImpl::HMatrix result; // [esp+370h] [ebp-D4h] BYREF
  Scaleform::Render::Matrix2x4<float> v9; // [esp+374h] [ebp-D0h] BYREF
  Scaleform::Render::Rect<float> v10; // [esp+394h] [ebp-B0h] BYREF
  int v11; // [esp+3B0h] [ebp-94h] BYREF
  Scaleform::Render::Matrix3x4<float> dst; // [esp+3B4h] [ebp-90h] BYREF
  Scaleform::Render::Matrix4x4<float> pviewProj; // [esp+3E4h] [ebp-60h] BYREF
  Scaleform::Render::Cxform dest; // [esp+424h] [ebp-20h] BYREF

  v10.x1 = 0.0;
  v10.y1 = 0.0;
  v10.x2 = 0.0;
  v10.y2 = 0.0;
  v9.M[0][0] = 1.0;
  v9.M[1][1] = 1.0;
  v9.M[0][1] = 0.0;
  v9.M[0][2] = 0.0;
  v9.M[0][3] = 0.0;
  v9.M[1][0] = 0.0;
  v9.M[1][2] = 0.0;
  v9.M[1][3] = 0.0;
  Scaleform::Render::Cxform::Cxform(&dest);
  memset((int)&dst, 0, sizeof(dst));
  dst.M[0][0] = 1.0;
  dst.M[1][1] = 1.0;
  dst.M[2][2] = 1.0;
  memset((int)&pviewProj, 0, sizeof(pviewProj));
  pviewProj.M[0][0] = 1.0;
  pviewProj.M[1][1] = 1.0;
  pviewProj.M[2][2] = 1.0;
  pviewProj.M[3][3] = 1.0;
  Scaleform::Render::TreeCacheNode::CalcViewMatrix(node, &dst, &pviewProj);
  Scaleform::Render::TreeCacheNode::CalcCxform(node, &dest);
  if ( !Scaleform::Render::TreeCacheNode::calcFilterBounds(node, (__m128 *)&v10, &v9, &dst, &pviewProj, 0) )
  {
    v10.x1 = 0.0;
    v10.y1 = 0.0;
    v10.x2 = 0.0;
    v10.y2 = 0.0;
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
  Scaleform::Render::MatrixPoolImpl::MatrixPool::CreateMatrix(MatrixPool, &result, &v9, 0);
  Scaleform::Render::MatrixPoolImpl::HMatrix::SetCxform(&result, &dest);
  v11 = 74;
  v4 = (Scaleform::Render::FilterEffect *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                            Scaleform::Memory::pGlobalHeap,
                                            node,
                                            84,
                                            &v11);
  if ( v4 )
  {
    Scaleform::Render::FilterEffect::FilterEffect(v4, node, &result, stateArg, next);
    v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  if ( result.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    Scaleform::Render::MatrixPoolImpl::DataHeader::Release(result.pHandle->pHeader);
  return (Scaleform::Render::CacheEffect *)v6;
}
