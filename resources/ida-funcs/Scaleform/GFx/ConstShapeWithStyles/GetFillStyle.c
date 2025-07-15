void __thiscall Scaleform::GFx::ConstShapeWithStyles::GetFillStyle(
        Scaleform::GFx::ConstShapeWithStyles *this,
        unsigned int idx,
        Scaleform::Render::FillStyleType *p)
{
  unsigned __int8 *v3; // esi
  Scaleform::GFx::Resource *v4; // ecx
  Scaleform::RefCountVImpl *pObject; // ecx

  v3 = &this->Styles[8 * idx - 8];
  p->Color = *(_DWORD *)v3;
  v4 = (Scaleform::GFx::Resource *)*((_DWORD *)v3 + 1);
  if ( v4 )
    Scaleform::RefCountImpl::AddRef(v4);
  pObject = (Scaleform::RefCountVImpl *)p->pFill.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  p->pFill.pObject = (Scaleform::Render::ComplexFill *)*((_DWORD *)v3 + 1);
}
