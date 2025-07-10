void __thiscall Scaleform::GFx::LoadProcess::SetBindProcess(
        Scaleform::GFx::LoadProcess *this,
        Scaleform::GFx::Resource *pbindProcess)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  if ( pbindProcess )
    Scaleform::RefCountImpl::AddRef(pbindProcess);
  pObject = (Scaleform::RefCountVImpl *)this->pBindProcess.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pBindProcess.pObject = (Scaleform::GFx::MovieBindProcess *)pbindProcess;
}
