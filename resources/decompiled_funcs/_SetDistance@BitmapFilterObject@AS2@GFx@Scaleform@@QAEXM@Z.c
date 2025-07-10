void __thiscall Scaleform::GFx::AS2::BitmapFilterObject::SetDistance(
        Scaleform::GFx::AS2::BitmapFilterObject *this,
        float d)
{
  Scaleform::Render::Filter *pObject; // edi
  Scaleform::MemoryHeap *v4; // eax
  int v5; // eax
  Scaleform::RefCountVImpl *v6; // ecx
  Scaleform::Render::Filter *v7; // edi
  Scaleform::Render::Filter *v8; // ecx

  pObject = this->pFilter.pObject;
  if ( pObject && pObject->Frozen )
  {
    v4 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
    v5 = (int)pObject->Clone(pObject, v4);
    v6 = (Scaleform::RefCountVImpl *)this->pFilter.pObject;
    v7 = (Scaleform::Render::Filter *)v5;
    if ( v6 )
      Scaleform::RefCountImpl::Release(v6);
    this->pFilter.pObject = v7;
  }
  v8 = this->pFilter.pObject;
  if ( v8 )
  {
    if ( v8->Type <= (unsigned int)Filter_GradientBevel )
      Scaleform::Render::BlurFilterImpl::SetAngleDistance(
        (Scaleform::Render::BlurFilterImpl *)v8,
        *(float *)&v8[3].Type,
        d);
  }
}
