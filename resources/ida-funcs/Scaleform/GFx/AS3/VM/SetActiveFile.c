void __thiscall Scaleform::GFx::AS3::VM::SetActiveFile(Scaleform::GFx::AS3::VM *this, unsigned __int64 fileId)
{
  Scaleform::GFx::AMP::ViewStats *v3; // eax
  Scaleform::GFx::AMP::ViewStats *v4; // edi
  __int64 v5; // rax
  unsigned __int64 v6; // rax
  unsigned __int64 v7; // kr00_8

  v3 = this->GetAdvanceStats(this);
  v4 = v3;
  if ( v3 )
  {
    LODWORD(v5) = Scaleform::GFx::AMP::ViewStats::GetActiveFile(v3);
    if ( fileId != v5 )
    {
      LODWORD(v6) = Scaleform::Timer::GetRawTicks();
      v7 = v6;
      Scaleform::GFx::AMP::ViewStats::RecordSourceLineTime(v4, v6 - this->ActiveLineTimestamp);
      this->ActiveLineTimestamp = v7;
      Scaleform::GFx::AMP::ViewStats::SetActiveFile(v4, fileId);
    }
  }
}
