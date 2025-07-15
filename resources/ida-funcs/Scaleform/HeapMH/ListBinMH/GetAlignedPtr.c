unsigned __int8 *__cdecl Scaleform::HeapMH::ListBinMH::GetAlignedPtr(unsigned __int8 *start, unsigned int alignMask)
{
  return (unsigned __int8 *)(~alignMask & (unsigned int)&start[alignMask]);
}
