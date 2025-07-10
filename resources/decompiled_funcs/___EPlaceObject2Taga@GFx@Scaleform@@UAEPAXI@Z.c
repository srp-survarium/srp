Scaleform::GFx::PlaceObject3Tag *__thiscall Scaleform::GFx::PlaceObject2Taga::`vector deleting destructor'(
        Scaleform::GFx::PlaceObject3Tag *this,
        char a2)
{
  Scaleform::GFx::PlaceObject2Tag::~PlaceObject2Tag(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
