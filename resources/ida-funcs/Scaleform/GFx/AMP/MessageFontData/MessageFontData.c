void __thiscall Scaleform::GFx::AMP::MessageFontData::MessageFontData(
        Scaleform::GFx::AMP::MessageFontData *this,
        unsigned int fontId)
{
  Scaleform::GFx::AMP::AmpStream *v3; // eax
  Scaleform::GFx::AMP::AmpStream *v4; // eax
  int v5; // [esp+4h] [ebp-4h] BYREF

  this->__vftable = (Scaleform::GFx::AMP::MessageFontData_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->FontId = fontId;
  this->RefCount = 1;
  this->Version = 33;
  this->GFxVersion = 4;
  this->__vftable = (Scaleform::GFx::AMP::MessageFontData_vtbl *)&Scaleform::GFx::AMP::MessageFontData::`vftable';
  v5 = 2;
  v3 = (Scaleform::GFx::AMP::AmpStream *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                           Scaleform::Memory::pGlobalHeap,
                                           this,
                                           24,
                                           &v5);
  if ( v3 )
  {
    Scaleform::GFx::AMP::AmpStream::AmpStream(v3);
    this->FontDataStream = v4;
  }
  else
  {
    this->FontDataStream = 0;
  }
}
