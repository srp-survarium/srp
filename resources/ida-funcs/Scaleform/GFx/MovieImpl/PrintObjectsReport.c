void __thiscall Scaleform::GFx::MovieImpl::PrintObjectsReport(
        Scaleform::GFx::MovieImpl *this,
        unsigned int flags,
        Scaleform::Log *log,
        const char *swfName)
{
  this->pASMovieRoot.pObject->PrintObjectsReport(this->pASMovieRoot.pObject, flags, log, swfName);
}
