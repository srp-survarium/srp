Scaleform::GFx::Resource *__thiscall Scaleform::GFx::Video::VideoCharacterDef::`scalar deleting destructor'(
        Scaleform::GFx::Resource *this,
        char a2)
{
  this->__vftable = (Scaleform::GFx::Resource_vtbl *)&Scaleform::GFx::Resource::`vftable';
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
