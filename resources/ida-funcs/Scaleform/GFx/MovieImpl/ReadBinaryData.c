bool __cdecl Scaleform::GFx::MovieImpl::ReadBinaryData(
        Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *pdata,
        Scaleform::File *pfile,
        int *pfileLen)
{
  unsigned int v3; // eax
  unsigned int v4; // esi

  v3 = pfile->GetLength(pfile);
  v4 = v3;
  *pfileLen = v3;
  if ( !v3 )
    return 0;
  if ( v3 >= pdata->Data.Size )
  {
    if ( v3 >= pdata->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *)pdata,
        pdata,
        v3 + (v3 >> 2));
  }
  else if ( v3 < pdata->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *)pdata,
      pdata,
      v3);
  }
  pdata->Data.Size = v4;
  return pfile->Read(pfile, pdata->Data.Data, *pfileLen) == *pfileLen;
}
