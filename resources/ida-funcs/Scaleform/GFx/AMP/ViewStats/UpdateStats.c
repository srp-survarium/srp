void __thiscall Scaleform::GFx::AMP::ViewStats::UpdateStats(
        Scaleform::GFx::AMP::ViewStats *this,
        unsigned __int64 functionId,
        unsigned int functionTime,
        unsigned int functionCalls,
        Scaleform::GFx::AMP::ProfileFrame *frameProfile)
{
  if ( HIDWORD(functionId) == 1 )
  {
    switch ( (int)functionId )
    {
      case 0:
        frameProfile->AdvanceTime += functionTime;
        break;
      case 1:
        frameProfile->TimelineTime += functionTime;
        break;
      case 2:
        frameProfile->ActionTime += functionTime;
        break;
      case 3:
        frameProfile->InputTime += functionTime;
        break;
      case 4:
        frameProfile->MouseTime += functionTime;
        break;
      case 5:
        frameProfile->GcCollectTime += functionTime;
        break;
      case 6:
        frameProfile->GcMarkInCycleTime += functionTime;
        break;
      case 7:
        frameProfile->GcScanInUseTime += functionTime;
        break;
      case 8:
        frameProfile->GcFreeGarbageTime += functionTime;
        break;
      case 9:
        frameProfile->GcFinalizeTime += functionTime;
        break;
      case 10:
        frameProfile->GcDelayedCleanupTime += functionTime;
        break;
      case 11:
      case 12:
      case 13:
        frameProfile->DisplayTime += functionTime;
        break;
      case 14:
        frameProfile->PresentTime += functionTime;
        break;
      case 15:
        frameProfile->TesselationTime += functionTime;
        break;
      case 16:
        frameProfile->NumFontCacheTextureUpdates += functionCalls;
        break;
      case 17:
        frameProfile->GradientGenTime += functionTime;
        break;
      case 18:
      case 19:
        frameProfile->FontMisses += functionCalls;
        break;
      case 21:
      case 22:
      case 23:
      case 32:
      case 37:
      case 39:
      case 53:
        frameProfile->UserTime += functionTime;
        frameProfile->GetVariableTime += functionTime;
        break;
      case 24:
      case 25:
      case 26:
      case 33:
      case 38:
      case 40:
      case 52:
        frameProfile->UserTime += functionTime;
        frameProfile->SetVariableTime += functionTime;
        break;
      case 27:
      case 28:
      case 29:
      case 30:
      case 34:
      case 61:
        frameProfile->UserTime += functionTime;
        frameProfile->InvokeTime += functionTime;
        break;
      default:
        return;
    }
  }
}
