char __thiscall Scaleform::GFx::AMP::Server::HandleObjectsReportRequest(
        Scaleform::GFx::AMP::Server *this,
        Scaleform::Render::RawImage *msg)
{
  Scaleform::Lock *p_ObjectsReportLock; // ebx

  p_ObjectsReportLock = &this->ObjectsReportLock;
  EnterCriticalSection(&this->ObjectsReportLock.cs);
  this->ObjectsReportRequested = Scaleform::GFx::AMP::MessageAppControl::GetFlags(msg);
  this->ObjectsReportFlags = 0;
  if ( Scaleform::GFx::AMP::MessageObjectsReportRequest::IsShortFilenames((Scaleform::GFx::AMP::MessageObjectsReportRequest *)msg) )
    this->ObjectsReportFlags |= 1u;
  if ( Scaleform::GFx::AMP::MessageObjectsReportRequest::IsNoCircularReferences((Scaleform::GFx::AMP::MessageObjectsReportRequest *)msg) )
    this->ObjectsReportFlags |= 2u;
  if ( Scaleform::GFx::AMP::MessageObjectsReportRequest::IsSuppressOverallStats((Scaleform::GFx::AMP::MessageObjectsReportRequest *)msg) )
    this->ObjectsReportFlags |= 4u;
  if ( Scaleform::GFx::AMP::MessageObjectsReportRequest::IsAddressesForAnonymObjsOnly((Scaleform::GFx::AMP::MessageObjectsReportRequest *)msg) )
    this->ObjectsReportFlags |= 8u;
  if ( Scaleform::GFx::AMP::MessageObjectsReportRequest::IsSuppressMovieDefsStats((Scaleform::GFx::AMP::MessageObjectsReportRequest *)msg) )
    this->ObjectsReportFlags |= 0x10u;
  if ( Scaleform::GFx::AMP::MessageObjectsReportRequest::IsNoEllipsis((Scaleform::GFx::AMP::MessageObjectsReportRequest *)msg) )
    this->ObjectsReportFlags |= 0x20u;
  LeaveCriticalSection(&p_ObjectsReportLock->cs);
  return 1;
}
