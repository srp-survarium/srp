void __thiscall Scaleform::GFx::AMP::MessageProfileFrame::Read(
        Scaleform::GFx::AMP::MessageProfileFrame *this,
        Scaleform::String str)
{
  Scaleform::File *pData; // ebx
  Scaleform::GFx::AMP::ProfileFrame *v4; // eax
  Scaleform::GFx::AMP::ProfileFrame *v5; // eax
  Scaleform::GFx::AMP::ProfileFrame *v6; // edi
  Scaleform::RefCountVImpl *pObject; // ecx

  pData = (Scaleform::File *)str.pData;
  Scaleform::GFx::AMP::Message::Read(this, str);
  str.pData = (Scaleform::String::DataDesc *)578;
  v4 = (Scaleform::GFx::AMP::ProfileFrame *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                              Scaleform::Memory::pGlobalHeap,
                                              this,
                                              304,
                                              &str);
  if ( v4 )
  {
    Scaleform::GFx::AMP::ProfileFrame::ProfileFrame(v4);
    v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  pObject = (Scaleform::RefCountVImpl *)this->FrameInfo.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->FrameInfo.pObject = v6;
  Scaleform::GFx::AMP::ProfileFrame::Read(v6, pData, this->Version);
}
