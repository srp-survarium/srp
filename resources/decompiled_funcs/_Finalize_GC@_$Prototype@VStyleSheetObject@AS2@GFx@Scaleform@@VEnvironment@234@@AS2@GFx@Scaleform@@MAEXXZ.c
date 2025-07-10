void __thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StyleSheetObject,Scaleform::GFx::AS2::Environment>::Finalize_GC(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StyleSheetObject,Scaleform::GFx::AS2::Environment> *this)
{
  Scaleform::GFx::AS2::GASPrototypeBase::InterfacesArray *pInterfaces; // eax

  pInterfaces = this->pInterfaces;
  if ( pInterfaces )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pInterfaces->Data.Data);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->pInterfaces);
  }
  ((void (__thiscall *)(Scaleform::GFx::Text::StyleManager *, _DWORD))this->CSS.~Scaleform::GFx::Text::StyleManager)(
    &this->CSS,
    0);
  Scaleform::GFx::AS2::Object::Finalize_GC(this);
}
