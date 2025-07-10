char __usercall Scaleform::GFx::ReadAndUniteScanline@<al>(
        Scaleform::GFx::Params *params@<edi>,
        unsigned __int8 *fullData)
{
  unsigned __int8 *pReadScanline; // ebx
  unsigned __int8 *v3; // ebp
  unsigned int v5; // esi
  unsigned __int8 *v6; // eax
  unsigned __int8 *v7; // ecx

  pReadScanline = params->SourceScanline.pReadScanline;
  v3 = params->AlphaScanline.pReadScanline;
  if ( params->Jin->ReadScanline(params->Jin, pReadScanline)
    && params->ZlibFile.pObject->Read(params->ZlibFile.pObject, v3, params->AlphaScanline.ReadScanlineSize) > 0 )
  {
    v5 = 0;
    if ( params->Width )
    {
      v6 = fullData + 1;
      v7 = pReadScanline + 1;
      do
      {
        *(v6 - 1) = *(v7 - 1);
        *v6 = *v7;
        v6[1] = v7[1];
        v6[2] = v3[v5++];
        v7 += 3;
        v6 += 4;
      }
      while ( v5 < params->Width );
    }
    return 1;
  }
  else
  {
    params->Success = 0;
    return 0;
  }
}
