Scaleform::Render::SIF::FileReader *__thiscall Scaleform::Render::PNG::FileReader::`scalar deleting destructor'(
        Scaleform::Render::SIF::FileReader *this,
        char a2)
{
  this->__vftable = (Scaleform::Render::SIF::FileReader_vtbl *)&Scaleform::Render::ImageFileHandler::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
