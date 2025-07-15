Scaleform::GFx::AMP::DefaultSocketFactory<Scaleform::GFx::AMP::GFxSocketImpl> *__thiscall Scaleform::GFx::AMP::DefaultSocketFactory<Scaleform::GFx::AMP::GFxSocketImpl>::`vector deleting destructor'(
        Scaleform::GFx::AMP::DefaultSocketFactory<Scaleform::GFx::AMP::GFxSocketImpl> *this,
        char a2)
{
  this->__vftable = (Scaleform::GFx::AMP::DefaultSocketFactory<Scaleform::GFx::AMP::GFxSocketImpl>_vtbl *)&Scaleform::GFx::AMP::SocketImplFactory::`vftable';
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
