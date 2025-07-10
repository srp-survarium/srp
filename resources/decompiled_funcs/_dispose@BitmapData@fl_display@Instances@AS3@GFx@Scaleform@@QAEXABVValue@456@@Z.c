void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::dispose(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        const Scaleform::GFx::AS3::Value *result)
{
  Scaleform::Render::ImageBase *pObject; // ecx

  pObject = this->pImage.pObject;
  if ( pObject )
    pObject->Release(pObject);
  this->pImage.pObject = 0;
  this->Width = 0;
  this->Height = 0;
}
