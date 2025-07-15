char __thiscall Scaleform::GFx::AMP::Server::HandleAppControl(
        Scaleform::GFx::AMP::Server *this,
        const Scaleform::GFx::AMP::MessageAppControl *msg)
{
  Scaleform::GFx::AMP::MessageAppControl *v3; // edi
  Scaleform::RefCountVImpl *pObject; // ebx
  Scaleform::GFx::AMP::ViewStats *v5; // ebx
  unsigned int i; // edi
  Scaleform::Ptr<Scaleform::GFx::AMP::Server::ViewProfile> *Data; // eax
  unsigned int v8; // ecx
  Scaleform::GFx::AMP::AppControlInterface *AppControlCallback; // ecx
  Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats> result; // [esp+10h] [ebp-8h] BYREF
  LPCRITICAL_SECTION lpCriticalSection; // [esp+14h] [ebp-4h]

  lpCriticalSection = &this->ToggleStateLock.cs;
  EnterCriticalSection(&this->ToggleStateLock.cs);
  v3 = msg;
  this->ToggleState = 0;
  if ( (unsigned __int8)Scaleform::GFx::AMP::MessageAppControl::IsToggleAmpRecording(msg) )
    this->ToggleState |= 1u;
  if ( (unsigned __int8)Scaleform::GFx::AMP::MessageAppControl::IsToggleInstructionProfile(msg) )
    this->PendingProfileLevel = this->IsInstructionProfiling(&this->Scaleform::AmpServer) ? 0 : 2;
  if ( (unsigned __int8)Scaleform::GFx::AMP::MessageAppControl::IsToggleMemReport(msg) )
    this->ToggleState |= 0x20u;
  if ( Scaleform::GFx::Text::EditorKit::GetCursorPos((Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *)msg) != (Scaleform::GFx::AS3::VMAppDomain *)-1 )
    this->PendingProfileLevel = (int)Scaleform::GFx::Text::EditorKit::GetCursorPos((Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *)msg);
  if ( (unsigned __int8)Scaleform::GFx::AMP::MessageAppControl::IsDebugPause(msg) )
  {
    EnterCriticalSection(&this->MovieLock.cs);
    Scaleform::GFx::AMP::Server::GetDebugPausedMovie(this, &result);
    pObject = (Scaleform::RefCountVImpl *)result.pObject;
    if ( result.pObject )
    {
      Scaleform::GFx::AMP::ViewStats::DebugGo(result.pObject);
      Scaleform::RefCountImpl::Release(pObject);
    }
    else if ( this->MovieStats.Data.Size )
    {
      Scaleform::GFx::AMP::ViewStats::DebugPause(this->MovieStats.Data.Data->pObject->AdvanceTimings.pObject);
    }
    LeaveCriticalSection(&this->MovieLock.cs);
    v3 = msg;
  }
  EnterCriticalSection(&this->MovieLock.cs);
  Scaleform::GFx::AMP::Server::GetDebugPausedMovie(this, &result);
  v5 = result.pObject;
  if ( result.pObject )
  {
    if ( (unsigned __int8)Scaleform::GFx::AMP::MessageAppControl::IsDebugNextMovie(v3) )
    {
      for ( i = 0; i < this->MovieStats.Data.Size; ++i )
      {
        Data = this->MovieStats.Data.Data;
        if ( Data[i].pObject->AdvanceTimings.pObject == v5 )
        {
          if ( i == this->MovieStats.Data.Size - 1 )
            v8 = 0;
          else
            v8 = i + 1;
          Scaleform::GFx::AMP::ViewStats::DebugPause(Data[v8].pObject->AdvanceTimings.pObject);
          Scaleform::GFx::AMP::ViewStats::DebugGo(v5);
        }
      }
      v3 = msg;
    }
    else if ( (unsigned __int8)Scaleform::GFx::AMP::MessageAppControl::IsDebugStep(v3) )
    {
      Scaleform::GFx::AMP::ViewStats::DebugStep(v5, 0);
    }
    else if ( (unsigned __int8)Scaleform::GFx::AMP::MessageAppControl::IsDebugStepIn(v3) )
    {
      Scaleform::GFx::AMP::ViewStats::DebugStep(v5, 1);
    }
    else if ( (unsigned __int8)Scaleform::GFx::AMP::MessageAppControl::IsDebugStepOut(v3) )
    {
      Scaleform::GFx::AMP::ViewStats::DebugStep(v5, -1);
    }
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v5);
  }
  LeaveCriticalSection(&this->MovieLock.cs);
  AppControlCallback = this->AppControlCallback;
  if ( AppControlCallback )
    AppControlCallback->HandleAmpRequest(AppControlCallback, v3);
  LeaveCriticalSection(lpCriticalSection);
  return 1;
}
