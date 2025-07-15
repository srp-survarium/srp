int __thiscall Scaleform::GFx::ZLibFileImpl::SetPosition(Scaleform::GFx::ZLibFileImpl *this, int offset)
{
  int LogicalStreamPos; // eax
  int v5; // eax
  unsigned __int8 dst[4096]; // [esp+8h] [ebp-1000h] BYREF

  LogicalStreamPos = this->LogicalStreamPos;
  if ( offset >= LogicalStreamPos )
  {
    if ( offset > LogicalStreamPos )
      this->UserPos = LogicalStreamPos;
  }
  else
  {
    if ( offset >= LogicalStreamPos - this->BacktrackSize )
    {
      this->UserPos = offset;
      return offset;
    }
    Scaleform::GFx::ZLibFileImpl::Reset(this);
  }
  if ( this->UserPos < offset )
  {
    do
    {
      v5 = offset - this->UserPos;
      if ( v5 >= 4096 )
        v5 = 4096;
    }
    while ( Scaleform::GFx::ZLibFileImpl::Inflate(this, dst, v5) && this->UserPos < offset );
  }
  return this->UserPos;
}
