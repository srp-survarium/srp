void __thiscall Scaleform::GFx::AMP::MessageImageData::MessageImageData(
        Scaleform::GFx::AMP::MessageImageData *this,
        unsigned int imageId)
{
  Scaleform::GFx::AMP::AmpStream *v3; // eax
  Scaleform::GFx::AMP::AmpStream *v4; // eax
  int v5; // [esp+4h] [ebp-4h] BYREF

  this->__vftable = (Scaleform::GFx::AMP::MessageImageData_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->PngFormat = 1;
  this->Version = 33;
  this->GFxVersion = 4;
  this->__vftable = (Scaleform::GFx::AMP::MessageImageData_vtbl *)&Scaleform::GFx::AMP::MessageImageData::`vftable';
  this->ImageId = imageId;
  v5 = 2;
  v3 = (Scaleform::GFx::AMP::AmpStream *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                           Scaleform::Memory::pGlobalHeap,
                                           this,
                                           24,
                                           &v5);
  if ( v3 )
  {
    Scaleform::GFx::AMP::AmpStream::AmpStream(v3);
    this->ImageDataStream = v4;
  }
  else
  {
    this->ImageDataStream = 0;
  }
}
