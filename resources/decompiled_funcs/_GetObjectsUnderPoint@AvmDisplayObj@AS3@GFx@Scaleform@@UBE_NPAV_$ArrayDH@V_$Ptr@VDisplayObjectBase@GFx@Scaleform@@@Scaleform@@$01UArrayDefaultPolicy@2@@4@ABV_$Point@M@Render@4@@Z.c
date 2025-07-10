char __thiscall Scaleform::GFx::AS3::AvmDisplayObj::GetObjectsUnderPoint(
        Scaleform::GFx::AS3::AvmDisplayObj *this,
        Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::DisplayObjectBase>,2,Scaleform::ArrayDefaultPolicy> *destArray,
        const Scaleform::Render::Point<float> *pt)
{
  Scaleform::GFx::DisplayObject *pDispObj; // esi

  if ( !this->pDispObj->PointTestLocal(this->pDispObj, pt, 1u) )
    return 0;
  pDispObj = this->pDispObj;
  if ( pDispObj )
    ++pDispObj->RefCount;
  pt = (const Scaleform::Render::Point<float> *)pDispObj;
  Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::Ptr<Scaleform::GFx::DisplayObjectBase>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::DisplayObjectBase>,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    destArray,
    0,
    (const Scaleform::Ptr<Scaleform::GFx::DisplayObjectBase> *)&pt);
  if ( pDispObj )
    Scaleform::RefCountNTSImpl::Release(pDispObj);
  return 1;
}
