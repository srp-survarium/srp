Scaleform::GFx::DisplayObjContainer *__thiscall Scaleform::GFx::DisplayObjContainer::`vector deleting destructor'(
        Scaleform::GFx::DisplayObjContainer *this,
        char a2)
{
  Scaleform::GFx::DisplayObjContainer::~DisplayObjContainer(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}


void *__thiscall Scaleform::GFx::DisplayObjContainer::`vector deleting destructor'(char *this, unsigned int a2)
{
  return Scaleform::GFx::DisplayObjContainer::`vector deleting destructor'(
           (Scaleform::GFx::DisplayObjContainer *)(this - 12),
           a2);
}
