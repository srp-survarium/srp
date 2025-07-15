void __thiscall Scaleform::GFx::AMP::ProfileFrame::Print(Scaleform::GFx::AMP::ProfileFrame *this, Scaleform::Log *log)
{
  unsigned int i; // ebx
  Scaleform::GFx::AMP::MovieProfile *pObject; // esi

  for ( i = 0; i < this->MovieStats.Data.Size; ++i )
  {
    pObject = this->MovieStats.Data.Data[i].pObject;
    Scaleform::Log::LogMessage(
      log,
      "========== MOVIE VIEW FUNCTIONS FOR %s ======\n",
      (const char *)((pObject->ViewName.HeapTypeBits & 0xFFFFFFFC) + 8));
    Scaleform::GFx::AMP::MovieFunctionStats::Print(pObject->FunctionStats.pObject, log);
    Scaleform::GFx::AMP::MovieFunctionTreeStats::Print(pObject->FunctionTreeStats.pObject, log);
  }
  Scaleform::Log::LogMessage(log, "========== RENDERER FUNCTIONS ===============\n");
  Scaleform::GFx::AMP::MovieFunctionStats::Print(this->DisplayStats.pObject, log);
  Scaleform::GFx::AMP::MovieFunctionTreeStats::Print(this->DisplayFunctionStats.pObject, log);
}
