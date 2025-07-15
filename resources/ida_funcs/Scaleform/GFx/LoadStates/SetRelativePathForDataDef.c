void __thiscall Scaleform::GFx::LoadStates::SetRelativePathForDataDef(
        Scaleform::GFx::LoadStates *this,
        Scaleform::GFx::MovieDataDef *pdef)
{
  Scaleform::String *p_RelativePath; // esi

  p_RelativePath = &this->RelativePath;
  Scaleform::String::operator=(
    &this->RelativePath,
    (char *)((pdef->pData.pObject->FileURL.HeapTypeBits & 0xFFFFFFFC) + 8));
  if ( !Scaleform::GFx::URLBuilder::ExtractFilePath(p_RelativePath) )
    Scaleform::String::Clear(p_RelativePath);
}
