Scaleform::GFx::AMP::MessageFontData *__thiscall Scaleform::GFx::AMP::MessageFontData::`scalar deleting destructor'(
        Scaleform::GFx::AMP::MessageFontData *this,
        char a2)
{
  Scaleform::RefCountVImpl *FontDataStream; // ecx

  FontDataStream = (Scaleform::RefCountVImpl *)this->FontDataStream;
  this->__vftable = (Scaleform::GFx::AMP::MessageFontData_vtbl *)&Scaleform::GFx::AMP::MessageFontData::`vftable';
  Scaleform::RefCountImpl::Release(FontDataStream);
  this->__vftable = (Scaleform::GFx::AMP::MessageFontData_vtbl *)&Scaleform::GFx::AMP::Message::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
