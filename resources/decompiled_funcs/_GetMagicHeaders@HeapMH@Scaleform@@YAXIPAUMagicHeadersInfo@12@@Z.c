void __cdecl Scaleform::HeapMH::GetMagicHeaders(unsigned int pageStart, Scaleform::HeapMH::MagicHeadersInfo *headers)
{
  Scaleform::HeapMH::MagicHeader *v2; // eax
  unsigned __int8 *v3; // edx
  unsigned __int8 *v4; // esi
  unsigned int *p_Magic; // edi

  v2 = (Scaleform::HeapMH::MagicHeader *)((pageStart + 4095) & 0xFFFFF000);
  v3 = (unsigned __int8 *)((pageStart + 15) & 0xFFFFFFF0);
  v4 = (unsigned __int8 *)((pageStart + 4096) & 0xFFFFFFF0);
  headers->Header1 = 0;
  headers->Header2 = 0;
  if ( (unsigned int)((char *)v2 - (char *)v3) > 0x10 )
    headers->Header1 = v2 - 1;
  if ( (unsigned int)(v4 - (unsigned __int8 *)v2) > 0x10 )
    headers->Header2 = v2;
  p_Magic = (unsigned int *)&v2[-5].Magic;
  if ( (char *)v2 - (char *)v3 <= (unsigned int)(v4 - (unsigned __int8 *)v2) )
    p_Magic = (unsigned int *)&v2[1].Magic;
  headers->BitSet = p_Magic;
  headers->AlignedEnd = v4;
  headers->AlignedStart = v3;
  headers->Bound = (unsigned __int8 *)v2;
  headers->Page = 0;
}
