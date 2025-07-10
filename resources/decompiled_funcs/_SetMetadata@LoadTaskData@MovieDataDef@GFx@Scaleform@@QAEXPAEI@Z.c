void __thiscall Scaleform::GFx::MovieDataDef::LoadTaskData::SetMetadata(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this,
        unsigned __int8 *pdata,
        unsigned int size)
{
  unsigned __int8 *v4; // eax

  v4 = (unsigned __int8 *)this->pHeap->Alloc(this->pHeap, size, 0);
  this->pMetadata = v4;
  if ( v4 )
  {
    this->MetadataSize = size;
    memcpy(v4, pdata, size);
  }
}
