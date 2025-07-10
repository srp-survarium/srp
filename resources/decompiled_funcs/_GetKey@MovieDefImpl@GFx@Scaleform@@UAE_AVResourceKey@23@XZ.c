Scaleform::GFx::ResourceKey *__thiscall Scaleform::GFx::MovieDefImpl::GetKey(
        Scaleform::GFx::MovieDefImpl *this,
        Scaleform::GFx::ResourceKey *result)
{
  Scaleform::GFx::MovieDefImpl::CreateMovieKey(
    result,
    this->pBindData.pObject->pDataDef.pObject,
    (Scaleform::GFx::Resource *)this->pBindStates.pObject);
  return result;
}
