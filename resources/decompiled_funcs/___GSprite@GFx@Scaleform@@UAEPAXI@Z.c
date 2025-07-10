Scaleform::GFx::Sprite *__thiscall Scaleform::GFx::Sprite::`scalar deleting destructor'(
        Scaleform::GFx::Sprite *this,
        char a2)
{
  Scaleform::GFx::Sprite::~Sprite(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
