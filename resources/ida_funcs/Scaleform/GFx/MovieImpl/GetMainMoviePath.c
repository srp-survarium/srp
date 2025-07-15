char __thiscall Scaleform::GFx::MovieImpl::GetMainMoviePath(Scaleform::GFx::MovieImpl *this, Scaleform::String *ppath)
{
  char *v3; // eax

  if ( this->pMainMovie )
  {
    v3 = (char *)this->pMainMovieDef.pObject->GetFileURL(this->pMainMovieDef.pObject);
    Scaleform::String::operator=(ppath, v3);
    if ( Scaleform::GFx::URLBuilder::ExtractFilePath(ppath) )
      return 1;
  }
  Scaleform::String::Clear(ppath);
  return 0;
}
