void __thiscall Scaleform::GFx::LoadProcess::AddImportData(
        Scaleform::GFx::LoadProcess *this,
        Scaleform::GFx::ImportData *pnode)
{
  Scaleform::GFx::MovieDataDef::DefBindingData *p_BindData; // edi

  pnode->ImportIndex = this->ImportIndex++;
  if ( !this->pImportData )
    this->pImportData = pnode;
  p_BindData = &this->pLoadData.pObject->BindData;
  if ( this->pLoadData.pObject->BindData.pImports.Value )
    InterlockedExchange((volatile LONG *)&this->pLoadData.pObject->BindData.pImportsLast->pNext, (LONG)pnode);
  else
    InterlockedExchange((volatile LONG *)&this->pLoadData.pObject->BindData.pImports, (LONG)pnode);
  p_BindData->pImportsLast = pnode;
  ++this->ImportDataCount;
}
