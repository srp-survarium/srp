Scaleform::Render::DDS::DDSFileImageSource *__thiscall Scaleform::Render::DDS::DDSFileImageSource::`scalar deleting destructor'(
        Scaleform::Render::DDS::DDSFileImageSource *this,
        char a2)
{
  this->__vftable = (Scaleform::Render::DDS::DDSFileImageSource_vtbl *)&Scaleform::Render::DDS::DDSFileImageSource::`vftable';
  Scaleform::Render::FileImageSource::~FileImageSource(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
