Scaleform::Log *__thiscall Scaleform::GFx::MovieImpl::GetCachedLog(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::Resource **Log; // edi
  Scaleform::Log *pObject; // ecx
  Scaleform::GFx::Resource *v4; // edx
  Scaleform::Log *v5; // ecx
  Scaleform::Ptr<Scaleform::Log> result; // [esp+4h] [ebp-4h] BYREF

  if ( (this->Flags & 2) != 0 )
    return this->pCachedLog.pObject;
  Log = (Scaleform::GFx::Resource **)Scaleform::GFx::StateBag::GetLog(&this->Scaleform::GFx::StateBag, &result);
  if ( *Log )
    Scaleform::RefCountImpl::AddRef(*Log);
  pObject = this->pCachedLog.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pObject);
  v4 = *Log;
  v5 = result.pObject;
  this->pCachedLog.pObject = (Scaleform::Log *)*Log;
  if ( v5 )
  {
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v5);
    return this->pCachedLog.pObject;
  }
  return (Scaleform::Log *)v4;
}
