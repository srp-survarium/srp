double __thiscall Scaleform::GFx::DisplayObjectBase::GetWidth(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::DisplayObjectBase_vtbl *v2; // edi
  const Scaleform::Render::Matrix2x4<float> *v3; // eax
  float v5; // [esp+1Ch] [ebp-14h]
  float v6[4]; // [esp+20h] [ebp-10h] BYREF

  v2 = this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
  v3 = this->GetMatrix(this);
  v2->GetBounds(this, (Scaleform::Render::Rect<float> *)v6, v3);
  v5 = v6[2] - v6[0];
  return floor(v5) * 0.05;
}
