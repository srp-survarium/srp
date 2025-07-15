void __thiscall Scaleform::GFx::AMP::MessageProfileFrame::MessageProfileFrame(
        Scaleform::GFx::AMP::MessageProfileFrame *this,
        Scaleform::GFx::Resource *frameInfo)
{
  Scaleform::GFx::AMP::ProfileFrame *v3; // ecx

  v3 = (Scaleform::GFx::AMP::ProfileFrame *)frameInfo;
  this->__vftable = (Scaleform::GFx::AMP::MessageProfileFrame_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->Version = 33;
  this->GFxVersion = 4;
  this->__vftable = (Scaleform::GFx::AMP::MessageProfileFrame_vtbl *)&Scaleform::GFx::AMP::MessageProfileFrame::`vftable';
  if ( frameInfo )
  {
    Scaleform::RefCountImpl::AddRef(frameInfo);
    v3 = (Scaleform::GFx::AMP::ProfileFrame *)frameInfo;
  }
  this->FrameInfo.pObject = v3;
  if ( v3 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v3);
}
