const Scaleform::ArrayLH_POD<unsigned int,338,Scaleform::ArrayDefaultPolicy> *__thiscall Scaleform::GFx::AS3::VMAbcFile::GetOpCode(
        Scaleform::GFx::AS3::VMAbcFile *this,
        Scaleform::GFx::AS3::Abc::MbiInd ind,
        const Scaleform::GFx::AS3::CallFrame *cf)
{
  int v3; // edx
  Scaleform::ArrayLH_POD<unsigned int,338,Scaleform::ArrayDefaultPolicy> *v5; // ecx
  Scaleform::GFx::AS3::VM *VMRef; // edi
  Scaleform::GFx::AS3::Tracer tracer; // [esp+4h] [ebp-A4h] BYREF

  v3 = ind.Ind;
  v5 = &this->OpCodeArray.Data.Data[ind.Ind];
  if ( !v5->Data.Size )
  {
    VMRef = this->VMRef;
    Scaleform::GFx::AS3::Tracer::Tracer(
      &tracer,
      VMRef->MHeap,
      cf,
      (int)v5,
      (const Scaleform::GFx::AS3::Abc::MethodInfo *)&this->Exceptions.Data.Data[ind.Ind]);
    if ( !VMRef->HandleException )
      Scaleform::GFx::AS3::Tracer::EmitCode(&tracer);
    Scaleform::GFx::AS3::Tracer::~Tracer(&tracer);
    v3 = ind.Ind;
  }
  return &this->OpCodeArray.Data.Data[v3];
}
