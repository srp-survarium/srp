void __thiscall Scaleform::GFx::AMP::MessageSwdRequest::MessageSwdRequest(
        Scaleform::GFx::AMP::MessageSwdRequest *this,
        unsigned int swfHandle,
        bool requestContents)
{
  this->__vftable = (Scaleform::GFx::AMP::MessageSwdRequest_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->Version = 33;
  this->GFxVersion = 4;
  this->__vftable = (Scaleform::GFx::AMP::MessageSwdRequest_vtbl *)&Scaleform::GFx::AMP::MessageSwdRequest::`vftable';
  this->Handle = swfHandle;
  this->RequestContents = requestContents;
}
