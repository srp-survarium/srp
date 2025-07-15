unsigned int __thiscall Scaleform::GFx::MovieDefImpl::GetMetadata(
        Scaleform::GFx::MovieDefImpl *this,
        char *pbuff,
        unsigned int buffSize)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // eax
  unsigned int MetadataSize; // esi
  const __m128i *pMetadata; // eax

  pObject = this->pBindData.pObject->pDataDef.pObject->pData.pObject;
  MetadataSize = buffSize;
  if ( !pbuff )
    return pObject->MetadataSize;
  if ( buffSize >= pObject->MetadataSize )
    MetadataSize = pObject->MetadataSize;
  pMetadata = (const __m128i *)pObject->pMetadata;
  if ( pMetadata )
    memcpy((int)pbuff, pMetadata, MetadataSize);
  return MetadataSize;
}
