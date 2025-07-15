const Scaleform::StatDesc *__cdecl Scaleform::StatDesc::GetDesc(unsigned int id)
{
  if ( !Stats_InitDone )
    Scaleform::StatDesc::InitChildTree();
  if ( Scaleform::StatDescRegistryInstance.IdPageTable[id >> 3] )
    return (const Scaleform::StatDesc *)*((_DWORD *)&Scaleform::StatDescRegistryInstance.DescMem[Scaleform::StatDescRegistryInstance.IdPageTable[id >> 3]
                                                                                               - 1]
                                        + (id & 7));
  else
    return 0;
}
