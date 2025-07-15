void __thiscall Scaleform::GFx::AMP::MessageSourceRequest::MessageSourceRequest(
        Scaleform::GFx::AMP::MessageSourceRequest *this,
        unsigned __int64 handle,
        bool requestContents)
{
  LODWORD(this->FileHandle) = handle;
  this->__vftable = (Scaleform::GFx::AMP::MessageSourceRequest_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->Version = 33;
  this->GFxVersion = 4;
  this->__vftable = (Scaleform::GFx::AMP::MessageSourceRequest_vtbl *)&Scaleform::GFx::AMP::MessageSourceRequest::`vftable';
  HIDWORD(this->FileHandle) = HIDWORD(handle);
  this->RequestContents = requestContents;
}
