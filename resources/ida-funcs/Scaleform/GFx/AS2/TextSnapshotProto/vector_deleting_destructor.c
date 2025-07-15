Scaleform::GFx::AS2::TextSnapshotProto *__thiscall Scaleform::GFx::AS2::TextSnapshotProto::`vector deleting destructor'(
        Scaleform::GFx::AS2::TextSnapshotProto *this,
        char a2)
{
  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TextSnapshotObject,Scaleform::GFx::AS2::Environment>::~Prototype<Scaleform::GFx::AS2::TextSnapshotObject,Scaleform::GFx::AS2::Environment>(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}


void *__thiscall Scaleform::GFx::AS2::TextSnapshotProto::`vector deleting destructor'(char *this, unsigned int a2)
{
  return Scaleform::GFx::AS2::TextSnapshotProto::`vector deleting destructor'(
           (Scaleform::GFx::AS2::TextSnapshotProto *)(this - 72),
           a2);
}
