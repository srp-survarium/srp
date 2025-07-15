void __thiscall Scaleform::Render::TreeCacheShape::UpdateTransform(
        Scaleform::Render::TreeCacheShape *this,
        const Scaleform::Render::TreeShape::NodeData *shapeData,
        const Scaleform::Render::TransformArgs *t,
        Scaleform::Render::TransformFlags flags)
{
  Scaleform::Render::TreeCacheShapeLayer *pNext; // ebx
  Scaleform::List<Scaleform::Render::TreeCacheNode,Scaleform::Render::TreeCacheNode> *p_Children; // esi
  int v7; // eax
  float x2; // [esp+F4h] [ebp-ECh]
  float y2; // [esp+F8h] [ebp-E8h]
  float y1; // [esp+FCh] [ebp-E4h]
  Scaleform::Render::TransformArgs v11; // [esp+100h] [ebp-E0h] BYREF
  Scaleform::Render::TransformFlags flagsa; // [esp+1F0h] [ebp+10h]

  Scaleform::Render::TransformArgs::TransformArgs(&v11, t, &t->Mat);
  if ( (flags & 0x80u) != 0 )
    memcpy((unsigned __int8 *)&v11.Mat3D, (unsigned __int8 *)&t->Mat3D, sizeof(v11.Mat3D));
  Scaleform::Render::TreeCacheNode::updateCulling(
    this,
    shapeData,
    t,
    &v11.CullRect,
    (Scaleform::Render::TransformFlags)(flags | 0x20));
  y1 = shapeData->AproxParentBounds.y1;
  x2 = shapeData->AproxParentBounds.x2;
  flagsa = flags & 0xFFFFFFEF;
  y2 = shapeData->AproxParentBounds.y2;
  this->SortParentBounds.x1 = shapeData->AproxParentBounds.x1;
  this->SortParentBounds.y1 = y1;
  this->SortParentBounds.x2 = x2;
  this->SortParentBounds.y2 = y2;
  this->Flags &= ~0x400u;
  pNext = (Scaleform::Render::TreeCacheShapeLayer *)this->Children.Root.pNext;
  p_Children = &this->Children;
  while ( 1 )
  {
    v7 = p_Children ? (int)&p_Children[-2] : 0;
    if ( pNext == (Scaleform::Render::TreeCacheShapeLayer *)v7 )
      break;
    Scaleform::Render::TreeCacheShapeLayer::UpdateTransform(pNext, shapeData, &v11, flagsa);
    pNext = (Scaleform::Render::TreeCacheShapeLayer *)pNext->pNext;
  }
}
