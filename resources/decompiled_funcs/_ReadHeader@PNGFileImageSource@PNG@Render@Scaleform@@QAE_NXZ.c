bool __thiscall Scaleform::Render::PNG::PNGFileImageSource::ReadHeader(
        Scaleform::Render::PNG::PNGFileImageSource *this)
{
  Scaleform::Render::PNG::Input *v2; // eax
  bool result; // al
  unsigned int *v4; // eax
  unsigned int v5; // ecx
  Scaleform::Render::Size<unsigned long> v6; // [esp+4h] [ebp-8h] BYREF

  Scaleform::Render::PNG::FileReader::CreateInput(
    &Scaleform::Render::PNG::FileReader::Instance,
    (Scaleform::GFx::Resource *)this->pFile.pObject);
  this->pOriginalInput = v2;
  if ( !v2 )
    return 0;
  v4 = (unsigned int *)v2->GetSize(v2, &v6);
  v5 = v4[1];
  this->Size.Width = *v4;
  this->Size.Height = v5;
  result = 1;
  if ( this->Format == Image_None )
    this->Format = Image_R8G8B8A8;
  return result;
}
