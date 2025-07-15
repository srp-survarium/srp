void __thiscall Scaleform::GFx::AMP::MovieInstructionStats::Write(
        Scaleform::GFx::AMP::MovieInstructionStats *this,
        Scaleform::File *str,
        unsigned int version)
{
  int (__thiscall *Write)(Scaleform::File *, const unsigned __int8 *, int); // edx
  unsigned int i; // esi
  unsigned int Size; // [esp+Ch] [ebp-4h] BYREF

  Write = str->Write;
  Size = this->BufferStatsArray.Data.Size;
  Write(str, (const unsigned __int8 *)&Size, 4);
  for ( i = 0; i < this->BufferStatsArray.Data.Size; ++i )
    Scaleform::GFx::AMP::MovieInstructionStats::ScriptBufferStats::Write(
      this->BufferStatsArray.Data.Data[i].pObject,
      str,
      version);
}
