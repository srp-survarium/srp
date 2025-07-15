void __thiscall Scaleform::GFx::AS2::InvokeContext::~InvokeContext(Scaleform::GFx::AS2::InvokeContext *this)
{
  Scaleform::GFx::AS2::LocalFrame *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Object *v4; // ecx
  unsigned int v5; // eax
  Scaleform::GFx::InteractiveObject *v6; // ecx
  Scaleform::GFx::InteractiveObject *v7; // ecx
  Scaleform::GFx::InteractiveObject *v8; // ecx

  pObject = this->CurLocalFrame.pObject;
  if ( pObject )
  {
    RefCount = pObject->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
  v4 = this->PassedThisObj.pObject;
  if ( v4 )
  {
    v5 = v4->RefCount;
    if ( (v5 & 0x3FFFFFF) != 0 )
    {
      v4->RefCount = v5 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v4);
    }
  }
  v6 = this->PassedThisCh.pObject;
  if ( v6 )
    Scaleform::RefCountNTSImpl::Release(v6);
  v7 = this->FnEnvCh.pObject;
  if ( v7 )
    Scaleform::RefCountNTSImpl::Release(v7);
  v8 = this->TargetCh.pObject;
  if ( v8 )
    Scaleform::RefCountNTSImpl::Release(v8);
}
