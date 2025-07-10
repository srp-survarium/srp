unsigned int __thiscall Scaleform::SysAllocMapper::findSegment(Scaleform::SysAllocMapper *this, unsigned __int8 *ptr)
{
  unsigned int result; // eax
  int v3; // ecx
  unsigned int v4; // edx
  unsigned int v5; // edx

  result = Scaleform::SysAllocMapper::binarySearch(this, ptr);
  if ( result
    && (v4 = *(_DWORD *)(v3 + 12 * result + 16), (unsigned int)ptr >= v4)
    && (unsigned int)ptr < v4 + *(_DWORD *)(v3 + 16) )
  {
    --result;
  }
  else
  {
    if ( result >= *(_DWORD *)(v3 + 412) )
      return *(_DWORD *)(v3 + 412);
    v5 = *(_DWORD *)(v3 + 12 * result + 28);
    if ( (unsigned int)ptr < v5 || (unsigned int)ptr >= v5 + *(_DWORD *)(v3 + 16) )
      return *(_DWORD *)(v3 + 412);
  }
  return result;
}
