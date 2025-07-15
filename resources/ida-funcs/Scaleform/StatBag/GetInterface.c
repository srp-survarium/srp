Scaleform::StatInfo::StatInterface *__cdecl Scaleform::StatBag::GetInterface(unsigned int id)
{
  if ( !Stats_InitDone )
    Scaleform::StatDesc::InitChildTree();
  if ( Scaleform::StatDescRegistryInstance.IdPageTable[id >> 3] )
    return Scaleform::Stats_InterfaceTable[**((unsigned __int8 **)&Scaleform::StatDescRegistryInstance.DescMem[Scaleform::StatDescRegistryInstance.IdPageTable[id >> 3] - 1]
                                            + (id & 7))];
  else
    return Scaleform::Stats_InterfaceTable[MEMORY[0]];
}
