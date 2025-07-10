Scaleform::GFx::AS2::PlaceObject3EH *__thiscall Scaleform::GFx::AS2::PlaceObject3EH::`scalar deleting destructor'(
        Scaleform::GFx::AS2::PlaceObject3EH *this,
        char a2)
{
  Scaleform::GFx::AS2::PlaceObject3EH::~PlaceObject3EH(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
