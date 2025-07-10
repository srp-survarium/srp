void __thiscall Scaleform::Render::GradientImage::GradientImage(
        Scaleform::Render::GradientImage *this,
        Scaleform::Render::PrimitiveFillManager *mng,
        Scaleform::GFx::Resource *data,
        float morphRatio)
{
  unsigned int v5; // eax

  this->__vftable = (Scaleform::Render::GradientImage_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::GradientImage_vtbl *)&Scaleform::Render::Image::`vftable';
  InterlockedExchange((volatile LONG *)&this->pTexture, 0);
  this->pUpdateSync = 0;
  this->pInverseMatrix = 0;
  this->__vftable = (Scaleform::Render::GradientImage_vtbl *)&Scaleform::Render::GradientImage::`vftable';
  this->pManager = mng;
  if ( data )
    Scaleform::RefCountImpl::AddRef(data);
  this->pData.pObject = (Scaleform::Render::GradientData *)data;
  this->Size.Width = 1;
  this->Size.Height = 1;
  this->MorphRatio = morphRatio;
  if ( data )
  {
    if ( BYTE1(data->pLib) )
    {
      v5 = Scaleform::Render::GradientData::CalcImageSize((Scaleform::Render::GradientData *)data);
      this->Size.Height = v5;
      this->Size.Width = v5;
    }
    else
    {
      this->Size.Height = 1;
      this->Size.Width = 256;
    }
  }
}
