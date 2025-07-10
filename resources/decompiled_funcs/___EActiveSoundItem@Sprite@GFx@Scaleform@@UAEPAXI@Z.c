Scaleform::GFx::Sprite::ActiveSoundItem *__thiscall Scaleform::GFx::Sprite::ActiveSoundItem::`vector deleting destructor'(
        Scaleform::GFx::Sprite::ActiveSoundItem *this,
        char a2)
{
  Scaleform::GFx::Sprite::ActiveSoundItem::~ActiveSoundItem(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
