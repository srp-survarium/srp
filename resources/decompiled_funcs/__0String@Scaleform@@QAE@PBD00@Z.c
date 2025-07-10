void __thiscall Scaleform::String::String(Scaleform::String *this, char *pdata1, char *pdata2, char *pdata3)
{
  unsigned int v4; // ebp
  unsigned int v5; // edi
  unsigned int v6; // ebx
  Scaleform::String::DataDesc *v7; // esi

  if ( pdata1 )
    v4 = strlen(pdata1);
  else
    v4 = 0;
  if ( pdata2 )
    v5 = strlen(pdata2);
  else
    v5 = 0;
  if ( pdata3 )
    v6 = strlen(pdata3);
  else
    v6 = 0;
  v7 = Scaleform::String::AllocDataCopy2(this, Scaleform::Memory::pGlobalHeap, v4 + v6 + v5, 0, pdata1, v4, pdata2, v5);
  memcpy((unsigned __int8 *)&v7->Data[v5 + v4], (unsigned __int8 *)pdata3, v6);
  this->HeapTypeBits = (unsigned int)v7;
}
