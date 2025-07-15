unsigned int __thiscall Scaleform::GFx::AS3::Tracer::GetNewTopOpCode(
        Scaleform::GFx::AS3::Tracer *this,
        unsigned int num)
{
  unsigned int Size; // eax

  Size = this->NewOpcodePos.Data.Size;
  if ( Size <= num )
    return 2;
  else
    return this->WCode->Data.Data[this->NewOpcodePos.Data.Data[Size - num - 1]];
}
