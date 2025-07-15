Scaleform::Render::PNG::LibPNGInput *__thiscall Scaleform::Render::PNG::LibPNGInput::`vector deleting destructor'(
        Scaleform::Render::PNG::LibPNGInput *this,
        char a2)
{
  bool v3; // zf
  Scaleform::RefCountVImpl *pObject; // ecx

  v3 = !this->IsInitialized;
  this->__vftable = (Scaleform::Render::PNG::LibPNGInput_vtbl *)&Scaleform::Render::PNG::LibPNGInput::`vftable';
  if ( !v3 )
    png_destroy_read_struct(&this->Context, &this->Context.info_ptr, 0);
  pObject = (Scaleform::RefCountVImpl *)this->pFile.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->__vftable = (Scaleform::Render::PNG::LibPNGInput_vtbl *)&Scaleform::Render::PNG::Input::`vftable';
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
