void __thiscall Scaleform::GFx::AMP::Server::ViewProfile::CollectStats(
        Scaleform::GFx::AMP::Server::ViewProfile *this,
        Scaleform::GFx::AMP::ProfileFrame *frameProfile,
        unsigned int index)
{
  Scaleform::GFx::AMP::MovieProfile *v4; // eax
  Scaleform::GFx::AMP::MovieProfile *v5; // eax
  Scaleform::GFx::AMP::MovieProfile *v6; // edi
  unsigned int CurrentFrame; // eax
  Scaleform::StringLH *Name; // eax
  Scaleform::RefCountVImpl **v9; // esi
  int v10; // [esp+8h] [ebp-4h] BYREF

  v10 = 578;
  v4 = (Scaleform::GFx::AMP::MovieProfile *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                              Scaleform::Memory::pGlobalHeap,
                                              this,
                                              72,
                                              &v10);
  if ( v4 )
  {
    Scaleform::GFx::AMP::MovieProfile::MovieProfile(v4);
    v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  Scaleform::GFx::AMP::ViewStats::CollectTimingStats(this->AdvanceTimings.pObject, frameProfile);
  Scaleform::GFx::AMP::ViewStats::CollectAmpInstructionStats(this->AdvanceTimings.pObject, v6);
  Scaleform::GFx::AMP::ViewStats::CollectAmpFunctionStats(this->AdvanceTimings.pObject, v6);
  Scaleform::GFx::AMP::ViewStats::CollectAmpSourceLineStats(this->AdvanceTimings.pObject, v6);
  Scaleform::GFx::AMP::ViewStats::CollectMarkers(this->AdvanceTimings.pObject, v6);
  Scaleform::GFx::AMP::ViewStats::CollectGcStats(this->AdvanceTimings.pObject, frameProfile);
  v6->ViewHandle = Scaleform::GFx::AMP::ViewStats::GetViewHandle(this->AdvanceTimings.pObject);
  CurrentFrame = Scaleform::GFx::AMP::ViewStats::GetCurrentFrame(this->AdvanceTimings.pObject);
  v6->MaxFrame = CurrentFrame;
  v6->MinFrame = CurrentFrame;
  Name = Scaleform::GFx::AMP::ViewStats::GetName(this->AdvanceTimings.pObject);
  Scaleform::String::operator=(&v6->ViewName, Name);
  v6->Version = Scaleform::GFx::AMP::ViewStats::GetVersion(this->AdvanceTimings.pObject);
  v6->Width = Scaleform::GFx::AMP::ViewStats::GetWidth(this->AdvanceTimings.pObject);
  v6->Height = Scaleform::GFx::AMP::ViewStats::GetHeight(this->AdvanceTimings.pObject);
  v6->FrameRate = Scaleform::GFx::AMP::ViewStats::GetFrameRate(this->AdvanceTimings.pObject);
  v6->FrameCount = Scaleform::GFx::AMP::ViewStats::GetFrameCount(this->AdvanceTimings.pObject);
  v9 = (Scaleform::RefCountVImpl **)&frameProfile->MovieStats.Data.Data[index];
  if ( *v9 )
    Scaleform::RefCountImpl::Release(*v9);
  *v9 = (Scaleform::RefCountVImpl *)v6;
}
