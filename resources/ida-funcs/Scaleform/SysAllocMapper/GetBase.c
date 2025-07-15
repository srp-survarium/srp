unsigned __int8 *__thiscall Scaleform::SysAllocMapper::GetBase(Scaleform::SysAllocMapper *this)
{
  if ( this->NumSegments )
    return this->Segments[0].Memory;
  else
    return 0;
}
