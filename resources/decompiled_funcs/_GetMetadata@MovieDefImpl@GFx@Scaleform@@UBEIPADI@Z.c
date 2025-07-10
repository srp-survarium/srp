unsigned int __thiscall Scaleform::GFx::MovieDefImpl::GetMetadata(
        Scaleform::GFx::MovieDefImpl *this,
        char *pbuff,
        unsigned int buffSize)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // eax
  unsigned int MetadataSize; // esi
  unsigned __int8 *pMetadata; // eax

  pObject = this->pBindData.pObject->pDataDef.pObject->pData.pObject;
  MetadataSize = buffSize;
  if ( !pbuff )
    return pObject->MetadataSize;
  if ( buffSize >= pObject->MetadataSize )
    MetadataSize = pObject->MetadataSize;
  pMetadata = pObject->pMetadata;
  if ( pMetadata )
    memcpy((unsigned __int8 *)pbuff, pMetadata, MetadataSize);
  return MetadataSize;
}
