char __userpurge Scaleform::GFx::AS3::AvmSprite::GetObjectsUnderPoint@<al>(
        Scaleform::GFx::AS3::AvmSprite *this@<ecx>,
        int a2@<ebx>,
        Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::DisplayObjectBase>,2,Scaleform::ArrayDefaultPolicy> *destArray,
        const Scaleform::Render::Point<float> *pt)
{
  const Scaleform::Render::Point<float> *v4; // edi
  char result; // al
  Scaleform::GFx::DisplayObject *pDispObj; // ecx
  Scaleform::GFx::DrawingContext *v8; // eax
  char v9; // bl
  Scaleform::GFx::DisplayObject *v10; // esi

  v4 = pt;
  result = Scaleform::GFx::AS3::AvmDisplayObjContainer::GetObjectsUnderPoint(this, destArray, pt);
  if ( !result )
  {
    pDispObj = this->pDispObj;
    if ( pDispObj[2].Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable )
    {
      v8 = pDispObj->GetDrawingContext(pDispObj);
      v9 = Scaleform::GFx::DrawingContext::DefPointTestLocal(v8, a2, v4, 1, this->pDispObj);
      if ( v9 )
      {
        v10 = this->pDispObj;
        if ( v10 )
          ++v10->RefCount;
        pt = (const Scaleform::Render::Point<float> *)v10;
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::Ptr<Scaleform::GFx::DisplayObjectBase>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::DisplayObjectBase>,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
          destArray,
          0,
          (const Scaleform::Ptr<Scaleform::GFx::DisplayObjectBase> *)&pt);
        if ( v10 )
          Scaleform::RefCountNTSImpl::Release(v10);
      }
      return v9;
    }
  }
  return result;
}
