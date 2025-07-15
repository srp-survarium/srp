void __thiscall Scaleform::GFx::AS3::VM::SetActiveLine(Scaleform::GFx::AS3::VM *this, unsigned int lineNumber)
{
  Scaleform::GFx::AMP::ViewStats *v3; // eax
  Scaleform::GFx::AMP::ViewStats *v4; // edi
  unsigned __int64 v5; // rax
  unsigned __int64 v6; // kr00_8

  v3 = this->GetAdvanceStats(this);
  v4 = v3;
  if ( v3 )
  {
    if ( lineNumber != Scaleform::GFx::AMP::ViewStats::GetActiveLine(v3) )
    {
      LODWORD(v5) = Scaleform::Timer::GetRawTicks();
      v6 = v5;
      Scaleform::GFx::AMP::ViewStats::RecordSourceLineTime(v4, v5 - this->ActiveLineTimestamp);
      this->ActiveLineTimestamp = v6;
      Scaleform::GFx::AMP::ViewStats::SetActiveLine(v4, lineNumber);
    }
  }
}
