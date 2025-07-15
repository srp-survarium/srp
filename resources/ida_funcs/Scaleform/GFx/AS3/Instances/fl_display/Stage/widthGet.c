void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Stage::widthGet(
        Scaleform::GFx::AS3::Instances::fl_display::Stage *this,
        long double *result)
{
  Scaleform::GFx::DisplayObject *pObject; // esi
  Scaleform::GFx::DisplayObject_vtbl *v3; // edi
  int v4; // eax
  float v5; // [esp+1Ch] [ebp-14h]
  float v6[4]; // [esp+20h] [ebp-10h] BYREF

  pObject = this->pDispObj.pObject;
  v3 = pObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
  v4 = (int)pObject->GetMatrix(pObject);
  v3->GetBounds(pObject, (Scaleform::Render::Rect<float> *)v6, (const Scaleform::Render::Matrix2x4<float> *)v4);
  v5 = v6[2] - v6[0];
  *result = v5 * 0.05;
}
