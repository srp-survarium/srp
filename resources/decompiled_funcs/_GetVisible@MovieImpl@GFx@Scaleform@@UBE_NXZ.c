BOOL __thiscall Scaleform::GFx::MovieImpl::GetVisible(Scaleform::GFx::MovieImpl *this)
{
  return this->pMainMovie && this->pMainMovie->GetVisible(this->pMainMovie);
}
