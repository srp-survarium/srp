void __thiscall Scaleform::GFx::AS3::VM::exec_debugfile(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::CallFrame *cf,
        Scaleform::GFx::ASStringNode *v)
{
  Scaleform::GFx::AS3::VMAbcFile *pFile; // edi
  Scaleform::GFx::AMP::ViewStats *v5; // ebx
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpServer *v7; // eax
  unsigned int v8; // esi
  Scaleform::GFx::ASString *InternedString; // eax
  Scaleform::GFx::ASStringNode *v10; // eax

  pFile = cf->pFile;
  v5 = this->GetAdvanceStats(this);
  if ( v5 )
  {
    Instance = Scaleform::AmpServer::GetInstance();
    if ( Instance->IsProfiling(Instance) )
    {
      v7 = Scaleform::AmpServer::GetInstance();
      if ( v7->GetProfileLevel(v7) < Amp_Profile_Level_Medium )
      {
        cf->CurrFileInd = (unsigned int)v;
      }
      else
      {
        v8 = (unsigned int)v;
        InternedString = Scaleform::GFx::AS3::VMFile::GetInternedString(pFile, (Scaleform::GFx::ASString *)&v, v);
        Scaleform::GFx::AMP::ViewStats::RegisterSourceFile(
          v5,
          (Scaleform::String)pFile->File.pObject->FileHandle,
          v8,
          InternedString->pNode->pData);
        v10 = v;
        --v->RefCount;
        if ( !v10->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v10);
        Scaleform::GFx::AS3::VM::SetActiveFile(this, v8 + ((unsigned __int64)pFile->File.pObject->FileHandle << 32));
        cf->CurrFileInd = v8;
      }
    }
    else
    {
      cf->CurrFileInd = (unsigned int)v;
    }
  }
  else
  {
    cf->CurrFileInd = (unsigned int)v;
  }
}
