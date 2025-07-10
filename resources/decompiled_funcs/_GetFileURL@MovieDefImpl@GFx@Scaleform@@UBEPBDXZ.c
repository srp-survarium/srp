const char *__thiscall Scaleform::GFx::MovieDefImpl::GetFileURL(Scaleform::GFx::MovieDefImpl *this)
{
  return (const char *)((this->pBindData.pObject->pDataDef.pObject->pData.pObject->FileURL.HeapTypeBits & 0xFFFFFFFC) + 8);
}
