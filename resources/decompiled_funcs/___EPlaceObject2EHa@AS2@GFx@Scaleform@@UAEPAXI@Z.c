Scaleform::GFx::AS2::PlaceObject2EHa *__thiscall Scaleform::GFx::AS2::PlaceObject2EHa::`vector deleting destructor'(
        Scaleform::GFx::AS2::PlaceObject2EHa *this,
        char a2)
{
  Scaleform::GFx::AS2::PlaceObject2EH::~PlaceObject2EH(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
