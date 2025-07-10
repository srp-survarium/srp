Scaleform::Ptr<Scaleform::Log> *__thiscall Scaleform::GFx::StateBag::GetLog(
        Scaleform::GFx::StateBag *this,
        Scaleform::Ptr<Scaleform::Log> *result)
{
  Scaleform::RefCountVImpl *v2; // edi
  Scaleform::GFx::Resource *GlobalLog; // eax
  Scaleform::Log *v4; // esi

  v2 = (Scaleform::RefCountVImpl *)this->GetStateAddRef(this, 2);
  GlobalLog = (Scaleform::GFx::Resource *)v2[2].__vftable;
  if ( !GlobalLog )
    GlobalLog = (Scaleform::GFx::Resource *)Scaleform::Log::GetGlobalLog();
  v4 = (Scaleform::Log *)GlobalLog;
  if ( GlobalLog )
    Scaleform::RefCountImpl::AddRef(GlobalLog);
  result->pObject = v4;
  Scaleform::RefCountImpl::Release(v2);
  return result;
}
