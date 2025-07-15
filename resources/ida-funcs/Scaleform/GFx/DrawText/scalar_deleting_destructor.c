Scaleform::GFx::DrawText *__thiscall Scaleform::GFx::DrawText::`scalar deleting destructor'(
        Scaleform::GFx::DrawText *this,
        char a2)
{
  this->__vftable = (Scaleform::GFx::DrawText_vtbl *)&Scaleform::GFx::DrawText::`vftable';
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
