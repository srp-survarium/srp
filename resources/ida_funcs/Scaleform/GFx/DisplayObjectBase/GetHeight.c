double __thiscall Scaleform::GFx::DisplayObjectBase::GetHeight(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::DisplayObjectBase_vtbl *v2; // edi
  const Scaleform::Render::Matrix2x4<float> *v3; // eax
  float v5; // [esp+1Ch] [ebp-14h]
  char v6; // [esp+20h] [ebp-10h] BYREF
  float v7; // [esp+24h] [ebp-Ch]
  float v8; // [esp+2Ch] [ebp-4h]

  v2 = this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
  v3 = this->GetMatrix(this);
  v2->GetBounds(this, (Scaleform::Render::Rect<float> *)&v6, v3);
  v5 = v8 - v7;
  return floor(v5) * 0.05;
}
