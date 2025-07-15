void __thiscall Scaleform::GFx::AMP::Server::RenderProfile::CollectStats(
        Scaleform::GFx::AMP::Server::RenderProfile *this,
        Scaleform::GFx::AMP::ProfileFrame *frameProfile)
{
  Scaleform::GFx::AMP::MovieProfile *v3; // eax
  Scaleform::GFx::AMP::MovieProfile *v4; // eax
  Scaleform::GFx::AMP::MovieProfile *v5; // esi
  int v6; // [esp+Ch] [ebp-4h] BYREF

  v6 = 578;
  v3 = (Scaleform::GFx::AMP::MovieProfile *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                              Scaleform::Memory::pGlobalHeap,
                                              this,
                                              72,
                                              &v6);
  if ( v3 )
  {
    Scaleform::GFx::AMP::MovieProfile::MovieProfile(v3);
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  Scaleform::GFx::AMP::ViewStats::CollectTimingStats(this->DisplayTimings.pObject, frameProfile);
  Scaleform::GFx::AMP::ViewStats::CollectAmpFunctionStats(this->DisplayTimings.pObject, v5);
  Scaleform::GFx::AMP::MovieFunctionTreeStats::Merge(
    frameProfile->DisplayFunctionStats.pObject,
    v5->FunctionTreeStats.pObject);
  Scaleform::GFx::AMP::MovieFunctionStats::Merge(frameProfile->DisplayStats.pObject, v5->FunctionStats.pObject);
  Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v5);
}
