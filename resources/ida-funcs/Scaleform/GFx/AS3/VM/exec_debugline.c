void __thiscall Scaleform::GFx::AS3::VM::exec_debugline(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::CallFrame *cf,
        unsigned int v)
{
  Scaleform::GFx::AMP::ViewStats *v4; // edi
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpServer *v6; // eax
  Scaleform::AmpServer *v7; // eax

  v4 = this->GetAdvanceStats(this);
  if ( v4 )
  {
    Instance = Scaleform::AmpServer::GetInstance();
    if ( Instance->IsProfiling(Instance) )
    {
      v6 = Scaleform::AmpServer::GetInstance();
      if ( v6->GetProfileLevel(v6) < Amp_Profile_Level_Medium )
      {
        cf->CurrLineNumber = v;
      }
      else
      {
        Scaleform::GFx::AS3::VM::SetActiveLine(this, v);
        Scaleform::GFx::AMP::ViewStats::RegisterScriptFunction(
          v4,
          (Scaleform::RefCountVImpl *)(cf->pFile->File.pObject->FileHandle
                                     + (cf->pFile->File.pObject->MethodBodies.Info.Data.Data[cf->MBIIndex.Ind]->method_info_ind << 16)),
          cf->pFile->File.pObject->SwfFileOffset,
          (const __m128i *)cf->Name.pObject->pData,
          0,
          3u,
          1);
        if ( Scaleform::GFx::AMP::ViewStats::IsDebugPaused(v4) )
        {
          v7 = Scaleform::AmpServer::GetInstance();
          v7->SendCurrentState(v7);
        }
        Scaleform::GFx::AMP::ViewStats::DebugWait(v4);
        cf->CurrLineNumber = v;
      }
    }
    else
    {
      cf->CurrLineNumber = v;
    }
  }
  else
  {
    cf->CurrLineNumber = v;
  }
}
