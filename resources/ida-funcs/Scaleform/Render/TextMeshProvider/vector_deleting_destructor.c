Scaleform::Render::TextMeshProvider *__thiscall Scaleform::Render::TextMeshProvider::`vector deleting destructor'(
        Scaleform::Render::TextMeshProvider *this,
        char a2)
{
  Scaleform::Render::TextMeshProvider::~TextMeshProvider(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
