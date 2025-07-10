void __thiscall Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetFillStyle(
        Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int idx,
        Scaleform::Render::FillStyleType *p)
{
  Scaleform::Render::FillStyleType *v3; // esi
  Scaleform::GFx::Resource *pObject; // ecx
  Scaleform::RefCountVImpl *v5; // ecx

  v3 = &this->Fills.Data.Data[idx - 1];
  p->Color = v3->Color;
  pObject = (Scaleform::GFx::Resource *)v3->pFill.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::AddRef(pObject);
  v5 = (Scaleform::RefCountVImpl *)p->pFill.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::Release(v5);
  p->pFill.pObject = v3->pFill.pObject;
}
