void __thiscall Scaleform::Render::RawImage::RawImage(Scaleform::Render::RawImage *this)
{
  this->__vftable = (Scaleform::Render::RawImage_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::RawImage_vtbl *)&Scaleform::Render::Image::`vftable';
  InterlockedExchange((volatile LONG *)&this->pTexture, 0);
  this->pUpdateSync = 0;
  this->pInverseMatrix = 0;
  this->__vftable = (Scaleform::Render::RawImage_vtbl *)&Scaleform::Render::RawImage::`vftable';
  this->Data.Format = Image_None;
  this->Data.Use = 0;
  this->Data.Flags = 0;
  this->Data.LevelCount = 0;
  this->Data.pPlanes = &this->Data.Plane0;
  this->Data.RawPlaneCount = 1;
  this->Data.pPalette.pObject = 0;
  this->Data.Plane0.Width = 0;
  this->Data.Plane0.Height = 0;
  this->Data.Plane0.Pitch = 0;
  this->Data.Plane0.DataSize = 0;
  this->Data.Plane0.pData = 0;
  this->ImageId = Scaleform::Render::ImageBase::GetNextImageId();
}
