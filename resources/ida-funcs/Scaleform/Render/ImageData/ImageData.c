void __thiscall Scaleform::Render::ImageData::ImageData(Scaleform::Render::ImageData *this)
{
  Scaleform::Render::ImagePlane *p_Plane0; // ecx

  this->RawPlaneCount = 1;
  p_Plane0 = &this->Plane0;
  this->Format = Image_None;
  this->Use = 0;
  this->Flags = 0;
  this->LevelCount = 0;
  this->pPlanes = p_Plane0;
  this->pPalette.pObject = 0;
  p_Plane0->Width = 0;
  p_Plane0->Height = 0;
  p_Plane0->Pitch = 0;
  p_Plane0->DataSize = 0;
  p_Plane0->pData = 0;
}
